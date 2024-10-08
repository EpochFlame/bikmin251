#include "Game/Entities/PikiBaby.h"
#include "Game/EnemyFunc.h"
#include "Game/EnemyAnimKeyEvent.h"
#include "Game/EnemyParmsBase.h"
#include "Dolphin/rand.h"

namespace efx {

bool TPikiFire::create(Arg* arg)
{
	if (!TSimple5::create(arg)) {
		return false;
	}

	ArgScale* args = static_cast<ArgScale*>(arg);
	f32 scale      = args->m_scale;

	for (int i = 0; i < 5; i++) {
		m_emitters[i]->setScale(scale);
	}

	return true;
}

bool TPikiBury::create(Arg* arg)
{
	if (!TSimple2::create(arg)) {
		return false;
	}

	ArgScale* args = static_cast<ArgScale*>(arg);
	f32 scale      = args->m_scale;

	for (int i = 0; i < 2; i++) {
		m_emitters[i]->setScale(scale);
	}

	return true;
}

} // namespace efx

namespace Game {
namespace PikiBaby {

Obj::Obj()
{
	m_animator   = new Baby::ProperAnimator;
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
	J3DModel* j3dModel      = m_model->m_j3dModel;
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

void Obj::onDeathStateInit() { }

void Obj::onBirthStateEnd() { }

void Obj::setInWaterDamage()
{
	if (m_waterBox) {
		addDamage(CS_GENERALPARMS(Baby::Parms*).m_health.m_value * sys->m_deltaTime, 1.0f);
	}
}

void Obj::initWalkSmokeEffect()
{
	mWalkSmokeMgr.alloc(2);
	mWalkSmokeMgr.setup(0, m_model, "foreArm.R", 1.25);
	mWalkSmokeMgr.setup(1, m_model, "foreArm.L", 1.25);
}

WalkSmokeEffect::Mgr* Obj::getWalkSmokeEffectMgr() { return &mWalkSmokeMgr; }

void Obj::doUpdate()
{
	Baby::Obj::doUpdate();

	setInWaterDamage();
}

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

void Obj::createLandEfx()
{
	efx::ArgScale fxArg(m_position, 1.5f);

	if (m_waterBox != nullptr) {
		efx::TEnemyDive diveFX;
		diveFX.create(&fxArg);
		return;
	}

	efx::TPikiBury buryFX;
	buryFX.create(&fxArg);
}

Creature* Obj::getAttackableTarget()
{
	EnemyParmsBase::Parms* parms = &CS_GENERALPARMS(Baby::Parms*);
	return EnemyFunc::getNearestPikminOrNavi(this, parms->m_fov.m_value, parms->m_sightRadius.m_value, nullptr, nullptr, nullptr);
}

void FSM::init(EnemyBase* enemy)
{
	StateDead* stateDead = new StateDead;

	create(Baby::BABY_Count), registerState(stateDead);
	registerState(stateDead);
	registerState(new StateBorn);
	registerState(new StateMove);
	registerState(new Baby::StateAttack);
}

void StateDead::init(EnemyBase* enemy, StateArg* arg)
{
	Baby::StateDead::init(enemy, arg);

	Obj* piki            = OBJ(enemy);
	piki->mDoPlayMatAnim = true;
	piki->onDeathStateInit();
}

void StateBorn::exec(EnemyBase* enemy)
{
	Baby::StateBorn::exec(enemy);

	if (enemy->m_curAnim->m_isRunning && enemy->m_curAnim->m_type == KEYEVENT_2) {
		OBJ(enemy)->createLandEfx();
	}
}

void StateBorn::cleanup(EnemyBase* enemy)
{
	Baby::StateBorn::cleanup(enemy);

	OBJ(enemy)->onBirthStateEnd();
}

void StateMove::exec(EnemyBase* enemy)
{
	Obj* baby = OBJ(enemy);
	if (baby->m_health <= 0.0f) {
		transit(baby, Baby::BABY_Dead, nullptr);
		return;
	}

	Creature* creature = baby->getAttackableTarget();

	if (creature) {
		EnemyParmsBase::Parms* parms = &CV_GENERALPARMS(Baby::Parms*, baby);
		f32 angleDist                = baby->turnToTarget(creature, parms->m_rotationalAccel.m_value, parms->m_rotationalSpeed.m_value);

		f32 limit = PI * (DEG2RAD * parms->m_fp21.m_value);

		if (FABS(angleDist) <= limit) {
			baby->setTargetVelocity();
		} else {
			baby->setTargetVelocity(0.25f);
		}

		if (baby->isTargetAttackable(creature, angleDist, parms->m_fp20.m_value, parms->m_fp21.m_value)) {
			transit(baby, Baby::BABY_Attack, nullptr);
		}
	} else {
		baby->moveNoTarget();
	}

	if (baby->m_curAnim->m_isRunning && baby->m_curAnim->m_type == KEYEVENT_END) {
		transit(baby, Baby::BABY_Move, nullptr);
	}
}

} // namespace PikiBaby

namespace PikiBabyRed {

void Obj::createDisChargeEffect()
{
	efx::ArgScale fxArg(m_position, 0.25f);
	efx::TPikiFire dischargeFX;
	dischargeFX.create(&fxArg);
}

void Obj::onDeathStateInit()
{
	createDisChargeEffect();

	f32 radius = CS_GENERALPARMS(Baby::Parms*).m_fp22.m_value;
	f32 dist   = SQUARE(radius);

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

void Obj::onInit(CreatureInitArg* arg)
{
	PikiBaby::Obj::onInit(arg);

	mIsBorn = false;

	Matrixf* jointMtx = m_model->m_joints[0].getWorldMatrix();
	mElecEfx->setMtxptr(jointMtx->m_matrix.mtxView);
}

void Obj::onDeathStateInit() { mElecEfx->fade(); }

void Obj::onBirthStateEnd()
{
	mIsBorn = true;
	mElecEfx->create(nullptr);
}

void Obj::collisionCallback(CollEvent& event)
{
	Creature* creature = event.m_collidingCreature;
	bool isFakePiki    = creature->isPiki() || creature->isNavi();
	if (!mIsBorn || !isFakePiki) {
		return;
	}

	Vector3f direction = creature->getPosition() - m_position;
	direction.y        = 0.0f;
	direction.normalise();

	EnemyParmsBase::Parms* parms = &static_cast<EnemyParmsBase*>(m_parms)->m_general;
	direction.x *= parms->m_fp14.m_value;
	direction.y *= parms->m_fp14.m_value;

	if (creature->isPiki()) {
		direction.y = parms->m_fp26.m_value;
	}

	InteractDenki denki(this, parms->m_attackDamage.m_value, &direction);
	creature->stimulate(denki);
}

Creature* Obj::getAttackableTarget()
{
	EnemyParmsBase::Parms* parms = &CS_GENERALPARMS(Baby::Parms*);
	return (Creature*)EnemyFunc::getNearestNavi(this, parms->m_fov.m_value, parms->m_sightRadius.m_value, nullptr, nullptr);
}

} // namespace PikiBabyYellow

namespace PikiBabyBlue {

Creature* Obj::getAttackableTarget()
{
	EnemyParmsBase::Parms* parms = &CS_GENERALPARMS(Baby::Parms*);
	return EnemyFunc::getNearestPikmin(this, parms->m_fov.m_value, parms->m_sightRadius.m_value, nullptr, nullptr);
}

} // namespace PikiBabyBlue

} // namespace Game
