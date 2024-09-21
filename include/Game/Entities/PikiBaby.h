#ifndef _GAME_ENTITIES_PIKIBABY_H
#define _GAME_ENTITIES_PIKIBABY_H

#include "Game/EnemyBase.h"
#include "Game/Entities/Baby.h"
#include "Sys/MatBaseAnimator.h"
#include "Sys/MatBaseAnimation.h"

namespace Game {
namespace PikiBabyRed {

struct Obj : public Baby::Obj {
    Obj();

    virtual ~Obj() { }
    virtual void onInit(CreatureInitArg*);
    virtual EnemyTypeID::EEnemyTypeID getEnemyTypeID()
    {
        return EnemyTypeID::EnemyID_PikiBabyRed;
    }
    virtual void initMouthSlots();
    virtual bool pressCallBack(Creature*, f32, CollPart*);
	virtual bool hipdropCallBack(Creature*, f32, CollPart*) { return false; }
    virtual void changeMaterial();
    virtual void getShadowParam(ShadowParam&);
    virtual void bounceCallback(Sys::Triangle*);
    
    bool mDoPlayMatAnim;
    Sys::MatLoopAnimator* mMatAnimator;
};

struct Mgr : public EnemyMgrBase {
    Mgr(int objLimit, u8 modelType);

	virtual void createObj(int);
	virtual EnemyBase* getEnemy(int idx);
	virtual void doAlloc();
	virtual EnemyTypeID::EEnemyTypeID getEnemyTypeID()
	{
		return EnemyTypeID::EnemyID_PikiBabyRed;
	}
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
        
} // namespace PikiBaby

namespace PikiBabyYellow {

struct Obj : public PikiBabyRed::Obj {
    inline Obj()
        : PikiBabyRed::Obj()
    {
    }
    
    virtual ~Obj() { }
    virtual EnemyTypeID::EEnemyTypeID getEnemyTypeID()
    {
        return EnemyTypeID::EnemyID_PikiBabyYellow;
    }
    virtual void collisionCallback(CollEvent&);
};

struct Mgr : public PikiBabyRed::Mgr {
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
    
struct Obj : public PikiBabyRed::Obj {
    inline Obj()
        : PikiBabyRed::Obj()
    {
    }
    
    virtual ~Obj() { }
    virtual EnemyTypeID::EEnemyTypeID getEnemyTypeID()
    {
        return EnemyTypeID::EnemyID_PikiBabyBlue;
    }
};

struct Mgr : public PikiBabyRed::Mgr {
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
