#ifndef _GAME_ENTITIES_PIKIBABY_H
#define _GAME_ENTITIES_PIKIBABY_H

#include "Game/EnemyBase.h"
#include "Game/Entities/Baby.h"
#include "Sys/MatBaseAnimator.h"
#include "Sys/MatBaseAnimation.h"
#include "efx/TOta.h"

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

} // namespace efx


namespace Game {
namespace PikiBaby {

struct Obj : public Baby::Obj {
    Obj();

    virtual ~Obj() { }
    virtual void onInit(CreatureInitArg*);
    virtual void initMouthSlots();
    virtual bool pressCallBack(Creature*, f32, CollPart*);
	virtual bool hipdropCallBack(Creature*, f32, CollPart*) { return false; }
    virtual void changeMaterial();
    virtual void getShadowParam(ShadowParam&);
    virtual void bounceCallback(Sys::Triangle*);

    virtual void attackTarget();

    inline f32 getMaxAttackHeight() const { return m_position.y + CS_GENERALPARMS(Baby::Parms*).m_fp20.m_value; }
	inline f32 getMinAttackHeight() const { return m_position.y - CS_GENERALPARMS(Baby::Parms*).m_fp21.m_value; }
    
    bool mDoPlayMatAnim;
    Sys::MatLoopAnimator* mMatAnimator;
};

struct Mgr : public EnemyMgrBase {
    Mgr(int objLimit, u8 modelType);

    virtual SysShape::Model* createModel();
    virtual J3DModelData* doLoadBmd(void* filename) 
    {
        return J3DModelLoaderDataBase::load(filename, 0x20240010);
    }
    virtual void loadTexData();

	Obj* m_obj;
    Sys::MatTevRegAnimation* mTevRegAnim;
};

struct FSM : public Baby::FSM {
	virtual void init(EnemyBase*);
};

struct StateDead : public Baby::StateDead {
    virtual void init(EnemyBase*, StateArg*);
};

struct StateBorn : public Baby::StateBorn {
    virtual void cleanup(EnemyBase*);
};

} // namespace PikiBaby

namespace PikiBabyRed
{

struct Obj : public PikiBaby::Obj {
    inline Obj()
        : PikiBaby::Obj()
    {
    }

    virtual ~Obj() { }
    virtual EnemyTypeID::EEnemyTypeID getEnemyTypeID()
    {
        return EnemyTypeID::EnemyID_PikiBabyRed;
    }
    virtual void attackTarget();
    
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

};
    
} // namespace PikiBabyRed

namespace PikiBabyYellow {

struct Obj : public PikiBaby::Obj {
    Obj();
    
    virtual ~Obj() { }
    virtual void onInit(CreatureInitArg*);
    virtual EnemyTypeID::EEnemyTypeID getEnemyTypeID()
    {
        return EnemyTypeID::EnemyID_PikiBabyYellow;
    }
    virtual void collisionCallback(CollEvent&);
    virtual void attackTarget();

    efx::TPikiDenki* m_elecEfx;
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
};
    
} // namespace PikiBabyYellow

namespace PikiBabyBlue {
    
struct Obj : public PikiBaby::Obj {
    inline Obj()
        : PikiBaby::Obj()
    {
    }
    
    virtual ~Obj() { }
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
};

} // namespace PikiBabyBlue
} // namespace Game

#endif /* _GAME_ENTITIES_PIKIBABY_H */
