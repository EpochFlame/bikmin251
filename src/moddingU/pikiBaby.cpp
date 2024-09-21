#include "Game/Entities/PikiBaby.h"
#include "Game/EnemyFunc.h"
#include "Game/EnemyAnimKeyEvent.h"
#include "Dolphin/rand.h"

namespace Game {
namespace PikiBabyRed {

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

void Obj::getShadowParam(ShadowParam&)
{
    
}

void Obj::bounceCallback(Sys::Triangle* tri)
{
	setVelocity(Vector3f::zero);
	m_simVelocity = Vector3f::zero;
}

void FSM::init(EnemyBase* enemy)
{
	StateDead* stateDead = new StateDead;

    create(Baby::BABY_Count), 
	registerState(stateDead);
	registerState(stateDead);
	registerState(new Baby::StateBorn);
	registerState(new Baby::StateMove);
	registerState(new Baby::StateAttack);
}

void StateDead::init(EnemyBase* enemy, StateArg* arg)
{
    Baby::StateDead::init(enemy, arg);

    Obj* piki = OBJ(enemy);
    piki->mDoPlayMatAnim = true;
}

} // namespace PikiBabyRed

namespace PikiBabyYellow {

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
