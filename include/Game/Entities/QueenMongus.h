#ifndef _GAME_ENTITIES_QUEENMONGUS_H
#define _GAME_ENTITIES_QUEENMONGUS_H

#include "Game/Entities/Queen.h"

namespace Game {
namespace QueenMongus {

struct Obj : public Queen::Obj {
    inline Obj()
        : Queen::Obj()
    {
    }
    
    virtual EnemyTypeID::EEnemyTypeID getEnemyTypeID()
    {
        return EnemyTypeID::EnemyID_QueenMongus;
    }
};

struct Mgr : public Queen::Mgr {
    Mgr(int objLimit, u8 modelType);
    
    virtual void createObj(int);
	virtual EnemyBase* getEnemy(int idx);
	virtual void doAlloc();
    virtual void loadTexData();
    virtual EnemyTypeID::EEnemyTypeID getEnemyTypeID()
    {
        return EnemyTypeID::EnemyID_QueenMongus;
    }
};

} // namespace QueenMongus    
} // namespace Game

#endif /* _GAME_ENTITIES_QUEENMONGUS_H */
