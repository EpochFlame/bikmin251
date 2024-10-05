#include "Game/Entities/PikiBaby.h"
#include "Game/EnemyFunc.h"
#include "Game/EnemyAnimKeyEvent.h"
#include "Dolphin/rand.h"

namespace efx {

bool TPikiFire::create(Arg* arg)
{
	if (!TSimple5::create(arg)) {
		return false;
	}

	ArgScale* args = static_cast<ArgScale*>(arg);
	f32 scale = args->m_scale;

	for (int i = 0; i < 5; i++) {
		m_emitters[i]->setScale(scale);
	}

	return true;
}
	
} // namespace efx


namespace Game {
namespace PikiBaby {

Obj::Obj()
{
	m_animator = new Baby::ProperAnimator;
	mMatAnimator = new Sys::MatLoopAnimator;

	setFSM(new FSM);
	createEffect();
}

void Obj::onInit(CreatureInitArg* arg)
{
    Baby::Obj::onInit(arg);

    mDoPlayMatAnim = false;
	mMatAnimator->start(C_MGR->mTevRegAnim);
}

void Obj::changeMaterial()
{
	J3DModel* j3dModel = m_model->m_j3dModel;
    J3DModelData* modelData = j3dModel->m_modelData;

	// apparently this allows material animations to play independently of other objects.
	f32 animSpeed = 0.0f;

	// play mat anim flag is true and animation has not played yet (don't loop)
    if (mDoPlayMatAnim) {
		animSpeed = 30.0f;
    }

	mMatAnimator->animate(animSpeed);

    j3dModel->calcMaterial();

    // diff material
	for (u16 i = 0; i < modelData->m_materialTable.m_count1; i++) {
		J3DMatPacket& packet = j3dModel->m_matPackets[i];
		j3dSys.m_matPacket   = &j3dModel->m_matPackets[i];
		modelData->m_materialTable.m_materials1[i]->diff(packet._2C->_34);
	}
}

void Obj::initMouthSlots()
{
	m_mouthSlots.alloc(1);
	m_mouthSlots.setup(0, m_model, "happa4");
	f32 size = 20.0f;
	for (int i = 0; i < m_mouthSlots.m_max; i++) {
		m_mouthSlots.getSlot(i)->m_radius = size;
	}
}

void Obj::getShadowParam(ShadowParam& param)
{
    param.m_position = m_position;
	param.m_position.y += 0.5f;

	param.m_boundingSphere.m_position = Vector3f(0.0f, 1.0f, 0.0f);

	if (isEvent(1, 1)) {
		param.m_boundingSphere.m_radius = 25.0f;
	} else {
		param.m_boundingSphere.m_radius = 5.0f;
	}

	param.m_size = 5.0f;
}

bool Obj::pressCallBack(Creature* source, f32 damage, CollPart* part)
{
	if (source->isPiki()) {
		return false;
	}

	m_FSM->transit(this, Baby::BABY_Dead, nullptr);
	return true;
}

void Obj::bounceCallback(Sys::Triangle* tri)
{
	setVelocity(Vector3f::zero);
	m_simVelocity = Vector3f::zero;
}

void Obj::attackTarget() { }

void Obj::initWalkSmokeEffect()
{
	mWalkSmokeMgr.alloc(2);
	mWalkSmokeMgr.setup(0, m_model, "foreArm.R", 1.25);
	mWalkSmokeMgr.setup(1, m_model, "foreArm.L", 1.25);
}

WalkSmokeEffect::Mgr* Obj::getWalkSmokeEffectMgr() { return &mWalkSmokeMgr; }

void Obj::doUpdateCommon()
{
	Matrixf mtx;
	PSMTXIdentity(mtx.m_matrix.mtxView);
	mtx.m_matrix.structView.ty = 6.0f;

	WalkSmokeEffect::Mgr* mgr = getWalkSmokeEffectMgr();
	for (u8 i = 0; i < mgr->m_objCount; i++) {
		Matrixf* walksmokeMtx = mgr->m_objects[i].m_matrix;
		PSMTXConcat(walksmokeMtx->m_matrix.mtxView, mtx.m_matrix.mtxView, walksmokeMtx->m_matrix.mtxView);
	}

	Baby::Obj::doUpdateCommon();
}

void FSM::init(EnemyBase* enemy)
{
	StateDead* stateDead = new StateDead;

    create(Baby::BABY_Count), 
	registerState(stateDead);
	registerState(stateDead);
	registerState(new StateBorn);
	registerState(new Baby::StateMove);
	registerState(new Baby::StateAttack);
}

void StateDead::init(EnemyBase* enemy, StateArg* arg)
{
    Baby::StateDead::init(enemy, arg);

    Obj* piki = OBJ(enemy);
    piki->mDoPlayMatAnim = true;
	piki->attackTarget();
}

void StateBorn::cleanup(EnemyBase*enemy)
{
	Obj* baby = OBJ(enemy);
}

} // namespace PikiBaby

namespace PikiBabyRed {

void Obj::createDisChargeEffect()
{
	efx::ArgScale fxArg(m_position, 0.25f);
	efx::TPikiFire dischargeFX;
	dischargeFX.create(&fxArg);
}
	
void Obj::attackTarget()
{
	createDisChargeEffect();

	f32 radius = CS_GENERALPARMS(Baby::Parms*).m_fp22.m_value;
	f32 dist = SQUARE(radius);

	Sys::Sphere sphere;
	sphere.m_position = m_position;
	sphere.m_radius   = radius;

	CellIteratorArg iterArg(sphere);
	iterArg._1C = true;
	CellIterator iter(iterArg);

	CI_LOOP(iter)
	{
		Creature* target = static_cast<Creature*>(*iter);
		if (!target->isAlive() || (!target->isNavi() && !target->isPiki())) {
			continue;
		}

		Vector3f targetPos = target->getPosition();
		if (sqrDistanceXZ(m_position, targetPos) >= dist) {
			continue;
		}

		if (getMaxAttackHeight() > targetPos.y && getMinAttackHeight() < targetPos.y) {
			f32 damage = CS_GENERALPARMS(Baby::Parms*).m_attackDamage.m_value;
			InteractFire fire(this, damage);
			target->stimulate(fire);
		}
	}
}

} // namespace PikiBabyRed


namespace PikiBabyYellow {

Obj::Obj()
	: PikiBaby::Obj()
{
	m_elecEfx = new efx::TPikiDenki;
}

void Obj::onInit(CreatureInitArg* arg)
{
	PikiBaby::Obj::onInit(arg);

	Matrixf* jointMtx = m_model->m_joints[0].getWorldMatrix();
	m_elecEfx->setMtxptr(jointMtx->m_matrix.mtxView);
	m_elecEfx->create(nullptr);
}

void Obj::attackTarget()
{
	m_elecEfx->fade();
}

void Obj::collisionCallback(CollEvent& event)
{
	Creature* creature = event.m_collidingCreature;
	if (!creature->isPiki() && !creature->isNavi()) {
		return;
	}

	Vector3f direction = creature->getPosition() - m_position;
	direction.y = 0.0f;
	direction.normalise();

	EnemyParmsBase::Parms* parms = &static_cast<EnemyParmsBase*>(m_parms)->m_general;
	direction.x *= parms->m_fp14.m_value;
	direction.y *= parms->m_fp14.m_value;

	if (creature->isPiki()) {
		direction.y = parms->m_fp26.m_value;
	}

	InteractDenki interact(this, parms->m_attackDamage.m_value, &direction);
	creature->stimulate(interact);
}

} // namespace PikiBabyYellow

} // namespace Game
