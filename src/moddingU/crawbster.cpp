#include "Game/Entities/DangoMushi.h"
#include "Game/PikiMgr.h"
#include "Game/generalEnemyMgr.h"
#include "Game/EnemyFunc.h"
#include "Game/Stickers.h"
#include "Vector3.h"
#include "Dolphin/rand.h"
#include "Graphics.h"

namespace Game {
namespace DangoMushi {

#define DANGO_FALLING_ROCK_COUNT (10)
#define DANGO_FALLING_PIKI_COUNT (10)

int Obj::getFallEggNum()
{
    // spawn 1 PikiBabyBlue per 10 pikmin
    f32 pikiCount = (f32)pikiMgr->m_activeCount;
    return (int)(pikiCount / 15.0f);
}

enum FallEnemyTypes {
    DANGOFALL_Rock = 0,
    DANGOFALL_Egg  = 1,
};

void Obj::createCrashEnemy()
{
    int fallEnemyTypes[]  = { EnemyTypeID::EnemyID_Rock, EnemyTypeID::EnemyID_PikiBabyBlue };
    int fallEnemyCounts[] = { DANGO_FALLING_ROCK_COUNT, DANGO_FALLING_PIKI_COUNT };

    // set number of falling pikimistakes based on active piki count (between 0 and 10)
    fallEnemyCounts[DANGOFALL_Egg] = getFallEggNum();

    for (int i = 0; i < (int)ARRAY_SIZE(fallEnemyTypes); i++) {
        EnemyMgrBase* mgr = generalEnemyMgr->getEnemyMgr(fallEnemyTypes[i]);
        if (!mgr) {
            continue;
        }

        Vector3f fallPos = getFallPosition(i);

        f32 angleOffset1 = randWeightFloat(PI);
        f32 angleOffset2 = 0.5f + angleOffset1;
        f32 angleOffset3 = 0.25f + angleOffset1;
        f32 birthAngle   = 0.0f;
        f32 dist;

        for (int j = 0; j < fallEnemyCounts[i]; j++) {
            if (j == 0) {
                // first falling enemy goes at (fallPos.x, fallPos.y, dist + fallPos.z)
                dist = randWeightFloat(15.0f);

            } else if (j < 4) {
                // enemies (rocks) 2, 3, 4 go vaguely equally spaced around a circle, with some small randomness...
                birthAngle = (2 * PI / 3) * (f32)j + (angleOffset1 + randWeightFloat(1.0f));

                // ... at some distance between 70 and 85 units from fall position
                dist = 70.0f + randWeightFloat(15.0f);

            } else if (j < 10) {
                // enemies (rocks) 5, 6, 7, 8, 9, 10 go vaguely equally spaced around a circle, with some small(er) randomness...
                birthAngle = (PI / 3) * (f32)j + (angleOffset2 + randWeightFloat(0.5f));

                // ... at some distance between 140 and 155 units from fall position
                dist = 140.0f + randWeightFloat(15.0f);

            } else {
                // any additional enemies (rocks) keep going around a circle with smaller spacing (unused, max is 10 rocks)
                birthAngle = (PI / 6) * (f32)j + (angleOffset3 + randWeightFloat(0.1f));

                // they'd also go at a larger distance from fall position (220-235 units)
                dist = 220.0f + randWeightFloat(15.0f);
            }

            if (birthAngle > TAU) {
                birthAngle -= TAU;
            }

            EnemyBirthArg birthArg;
            birthArg.m_typeID     = (EnemyTypeID::EEnemyTypeID)fallEnemyTypes[i];
            birthArg.m_faceDir    = m_faceDir;
            birthArg.m_position.x = dist * sinf(birthAngle) + fallPos.x;
            birthArg.m_position.y = fallPos.y;
            birthArg.m_position.z = dist * cosf(birthAngle) + fallPos.z;

            if (fallEnemyTypes[i] == EnemyTypeID::EnemyID_PikiBabyBlue) {
                birthArg.m_tekiBirthType = 1; // eggs fall on approach by piki or navi, rocks just fall with no condition
            } else {
                birthArg._2C = 30.0f; // rocks have an "existence length" instead
            }

            EnemyBase* enemy = mgr->birth(birthArg);
            if (enemy) {
                enemy->init(nullptr);
                enemy->resetEvent(0, EB_Cullable); // rocks/eggs are always loaded to go off, even if you're not watching

                // majorly increase trigger distance (for rocks, these are 75 and 150 by default; for eggs, 30 and 700)
                CG_GENERALPARMS(enemy).m_privateRadius.m_value = 1000.0f;
                CG_GENERALPARMS(enemy).m_sightRadius.m_value   = 1000.0f;
            }
        }
    }
}

bool Obj::damageCallBack(Creature* creature, f32 damage, CollPart* part)
{
    if (creature && creature->isPiki()) {
        // if bittered, can attack anywhere
        if (isEvent(0, EB_Bittered)) {
            addDamage(damage, 1.0f);
            return true;
        }

        // if not bittered, can only attack bod0 or bod1 parts
        if (part && (part->m_currentID == 'bod0' || part->m_currentID == 'bod1')) {
            createBodyDamageEffect();
            addDamage(damage, 1.0f);
            return true;
        }

        // face can get damaged but like hardly
        if (part && (part->m_currentID == 'heaR' || part->m_currentID == 'heaL')) {
            addDamage(damage * 0.05, 1.0f);
            return true; 
        }
    }
    return false;
}

void Obj::wallCallback(const MoveInfo& mvInfo)
{
    if (mIsRolling) {
        Vector3f velocity = mRollingVelocity;
        f32 speed         = velocity.normalise();

        // if we're rolling fast enough and hit the wall at a 30 degree angle or more (90 degree = head-on), crash
        if (speed > 100.0f && velocity.dot(mvInfo._5C) < -0.5f) {

            // flick pikmin stuck to it
            f32 shakeChance    = C_GENERALPARMS.m_shakeRateMaybe.m_value;
            f32 shakeKnockback = C_GENERALPARMS.m_shakeKnockback.m_value;
            f32 shakeDamage    = C_GENERALPARMS.m_shakeDamage.m_value;
            EnemyFunc::flickStickPikmin(this, shakeChance, shakeKnockback, shakeDamage, FLICK_BACKWARD_ANGLE, nullptr);

            createBodyWallCrashEffect(mvInfo._5C);
            mFsm->transit(this, 6, nullptr);
        }
    }
}

void Obj::collisionCallback(CollEvent& evt)
{
    if (isEvent(0, EB_Bittered) || evt.m_collidingCreature == nullptr) {
        setCollEvent(evt);
        return;
    }

    Creature* target = evt.m_collidingCreature;
    // if rolling and we hit a piki, crush it.
    if (mIsRolling && target->m_curTriangle) {
        InteractPress press(this, C_GENERALPARMS.m_attackDamage.m_value, nullptr);
        target->stimulate(press);
        setCollEvent(evt);
        return;
    }
    
    // if we're swinging our arm and our arm hits something, do our arm effect (flick or wither)
    if (mIsArmSwinging) {
        CollPart* part   = evt.m_hitPart;
        if (part && part->m_currentID.match('haR*', '*')) {
            flickHandCollision(target);
        }

        if (part && part->m_currentID == 'kill') {
            Vector3f targetPos = target->getPosition();
            Vector3f::getFlatDirectionFromTo(m_position, targetPos);

            // bikmin that get hit by this part should be flung to the stratosphere
            targetPos = 1000.0f;

            InteractBomb wither(this, C_GENERALPARMS.m_attackDamage.m_value, &targetPos);
            target->stimulate(wither);
        }
    }

    setCollEvent(evt);
}
    
} // namespace DangoMushi
} // namespace Game
