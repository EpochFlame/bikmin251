#ifndef _GAME_ENTITIES_PIKIBABY_H
#define _GAME_ENTITIES_PIKIBABY_H

#include "Game/EnemyBase.h"
#include "Game/Entities/Baby.h"
#include "Game/WalkSmokeEffect.h"
#include "Sys/MatBaseAnimator.h"
#include "Sys/MatBaseAnimation.h"
#include "efx/TOta.h"
#include "efx/TPk.h"
#include "efx/TEnemyDive.h"

namespace efx {

struct TPikiFire : public TOtaFire {
	inline TPikiFire()
	    : TOtaFire()
	{
	}

	virtual bool create(Arg*);
};

struct TPikiDenki : public TChaseMtx2 {
	inline TPikiDenki()
	    : TChaseMtx2(nullptr, PID_DenkiPole_1, PID_DenkiPole_2)
	{
	}
};

struct TPikiBury : public TPkAp {
	inline TPikiBury()
	    : TPkAp()
	{
	}

	virtual bool create(Arg*);
};

} // namespace efx

namespace Game {
namespace PikiBaby {

struct Obj : public Baby::Obj {
	Obj();

	virtual ~Obj() { }
	virtual void bounceCallback(Sys::Triangle*);
	virtual void changeMaterial();
	virtual void doUpdate();
	virtual void doUpdateCommon();
	virtual void onInit(CreatureInitArg*);
	virtual void getShadowParam(ShadowParam&);
	virtual WalkSmokeEffect::Mgr* getWalkSmokeEffectMgr();
	virtual bool hipdropCallBack(Creature*, f32, CollPart*) { return false; }
	virtual void initMouthSlots();
	virtual void initWalkSmokeEffect();
	virtual bool pressCallBack(Creature*, f32, CollPart*);
	virtual void onDeathStateInit();
	virtual void onBirthStateEnd();
	virtual void setInWaterDamage();
	virtual Creature* getAttackableTarget();

	inline f32 getMaxAttackHeight() const 
	{ 
		return m_position.y + CS_GENERALPARMS(Baby::Parms*).m_fp20.m_value; 
	}

	inline f32 getMinAttackHeight() const 
	{ 
		return m_position.y - CS_GENERALPARMS(Baby::Parms*).m_fp21.m_value; 
	}

	void createLandEfx();

	bool mDoPlayMatAnim;
	Sys::MatLoopAnimator* mMatAnimator;
	WalkSmokeEffect::Mgr mWalkSmokeMgr;
};

struct Mgr : public EnemyMgrBase {
	Mgr(int objLimit, u8 modelType);

	virtual SysShape::Model* createModel();
	virtual void loadTexData();
	virtual J3DModelData* doLoadBmd(void* filename) 
	{ 
		return J3DModelLoaderDataBase::load(filename, 0x20240010); 
	}

	Sys::MatTevRegAnimation* mTevRegAnim;
};

struct FSM : public Baby::FSM {
	virtual void init(EnemyBase*);
};

struct StateDead : public Baby::StateDead {
	virtual void init(EnemyBase*, StateArg*);
};

struct StateBorn : public Baby::StateBorn {
	virtual void exec(EnemyBase*);
	virtual void cleanup(EnemyBase*);
};

struct StateMove : public Baby::StateMove {
	virtual void exec(EnemyBase*);
};

} // namespace PikiBaby

namespace PikiBabyRed {

struct Obj : public PikiBaby::Obj {
	inline Obj()
	    : PikiBaby::Obj()
	{
	}

	virtual ~Obj() { }
	virtual void onDeathStateInit();
	virtual EnemyTypeID::EEnemyTypeID getEnemyTypeID() 
	{ 
		return EnemyTypeID::EnemyID_PikiBabyRed; 
	}

	void createDisChargeEffect();
};

struct Mgr : public PikiBaby::Mgr {
	Mgr(int objLimit, u8 modelType);

	virtual void createObj(int);
	virtual EnemyBase* getEnemy(int idx);
	virtual void doAlloc();
	virtual EnemyTypeID::EEnemyTypeID getEnemyTypeID() 
	{ 
		return EnemyTypeID::EnemyID_PikiBabyRed; 
	}

	Obj* m_obj;
};

} // namespace PikiBabyRed

namespace PikiBabyYellow {

struct Obj : public PikiBaby::Obj {
	inline Obj()
	    : PikiBaby::Obj()
	    , mIsBorn(false)
	    , mElecEfx(new efx::TPikiDenki)
	{
	}

	virtual ~Obj() { }
	virtual void onInit(CreatureInitArg*);
	virtual void collisionCallback(CollEvent&);
	virtual void onDeathStateInit();
	virtual void onBirthStateEnd();
	virtual Creature* getAttackableTarget();
	virtual EnemyTypeID::EEnemyTypeID getEnemyTypeID() 
	{ 
		return EnemyTypeID::EnemyID_PikiBabyYellow; 
	}

	bool mIsBorn;
	efx::TPikiDenki* mElecEfx;
};

struct Mgr : public PikiBaby::Mgr {
	Mgr(int objLimit, u8 modelType);

	virtual void createObj(int);
	virtual EnemyBase* getEnemy(int idx);
	virtual void doAlloc();
	virtual EnemyTypeID::EEnemyTypeID getEnemyTypeID() 
	{ 
		return EnemyTypeID::EnemyID_PikiBabyYellow; 
	}

	Obj* m_obj;
};

} // namespace PikiBabyYellow

namespace PikiBabyBlue {

struct Obj : public PikiBaby::Obj {
	inline Obj()
	    : PikiBaby::Obj()
	{
	}

	virtual ~Obj() { }
	virtual Creature* getAttackableTarget();
	virtual void setInWaterDamage() { }
	virtual EnemyTypeID::EEnemyTypeID getEnemyTypeID() 
	{ 
		return EnemyTypeID::EnemyID_PikiBabyBlue; 
	}
};

struct Mgr : public PikiBaby::Mgr {
	Mgr(int objLimit, u8 modelType);

	virtual void createObj(int);
	virtual EnemyBase* getEnemy(int idx);
	virtual void doAlloc();
	virtual EnemyTypeID::EEnemyTypeID getEnemyTypeID() 
	{ 
		return EnemyTypeID::EnemyID_PikiBabyBlue; 
	}

	Obj* m_obj;
};

} // namespace PikiBabyBlue
} // namespace Game

#endif /* _GAME_ENTITIES_PIKIBABY_H */
