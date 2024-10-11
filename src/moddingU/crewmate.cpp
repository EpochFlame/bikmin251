#include "Game/Entities/Ujia.h"
#include "Game/Entities/ItemHoney.h"
#include "Dolphin/rand.h"

namespace Game {
namespace Ujia {

void Obj::createNectar()
{
    // crewmates shouldn't drop nectar on day 1
    if (gameSystem->m_timeMgr != nullptr && gameSystem->m_timeMgr->m_dayCount == 0) {
        return;
    }

    // 30% chance to do nothing
    if (randWeightFloat(1.0f) <= 0.3f) {
        return;
    }

    // 70% chance to spawn nectar
    ItemHoney::Item* nectar = static_cast<ItemHoney::Item*>(ItemHoney::mgr->birth());
    if (nectar == nullptr) {
        return;
    }

    nectar->init(nullptr);
    nectar->m_honeyType = HONEY_Y;
    nectar->setPosition(m_position, false);
    Vector3f vel(0.0f, 250.0f, 0.0f);
    nectar->setVelocity(vel);
}

void StateDead::init(EnemyBase* enemy, StateArg* stateArg)
{
	enemy->deathProcedure();
	enemy->resetEvent(0, EB_Cullable);
	enemy->m_simVelocity = Vector3f(0.0f);
	enemy->startMotion(UJIAANIM_Dead, nullptr);

    OBJ(enemy)->createNectar();
}
    
} // namespace Ujia
} // namespace Game
