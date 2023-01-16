#include "types.h"
#include "Dolphin/os.h"
#include "Game/AIConstants.h"
#include "Game/gamePlayData.h"
#include "Game/GameSystem.h"
#include "Game/CameraMgr.h"
#include "Game/CollEvent.h"
#include "Game/rumble.h"
#include "Game/EnemyBase.h"
#include "Game/TimeMgr.h"
#include "Game/MoviePlayer.h"
#include "Game/Interaction.h"
#include "Game/enemyInfo.h"
#include "JSystem/JUT/JUTGamePad.h"
#include "SoundID.h"
#include "PSSystem/PSSystemIF.h"
#include "efx/TSimple.h"
#include "ObjectTypes.h"

bool isTreasureCutscene;

namespace Game {

struct Navi {
	void procActionButton();
};

struct NaviWalkState {
	void execAI(Navi*);
};

void autopluck(NaviWalkState* walkstate, Navi* captain)
// performs Pikmin 3-style autopluck of pikmin seeds
{
	captain->procActionButton();
	walkstate->execAI(captain);
}

void allowSkipTreasureCutscene(MoviePlayer* movieplayer)
// allows 251-style treasure cutscene skips
{
	if (isTreasureCutscene && movieplayer != nullptr) {
		if (movieplayer->m_demoState == 6) {
			isTreasureCutscene = false;
			// OSReport("Treasure cutscene finished normally!");
		} else if (((JUTGamePad::mPadStatus[0].button & 0x1000) != 0) && (movieplayer->m_demoState == 5)) {
			isTreasureCutscene = false;
			movieplayer->skip();
			// OSReport("Treasure cutscene skipped successfully!);
		}
	}
}

void frogDeathSphere(Game::EnemyBase* frog, Game::CollEvent& event)
{
	if (frog->getEnemyTypeID() == EnemyTypeID::EnemyID_MaroFrog)
		return;

	Vector3f fxPos;
	frog->setEmotionCaution();
	frog->getCommonEffectPos(fxPos);
	fxPos.y -= 85.0f; // effect offset to ground the explosion

	efx::TSimple1 simpleFx(12, nullptr);
	efx::Arg arg(fxPos);
	simpleFx.create(&arg);

	PSSystem::spSysIF->playSystemSe(PSSE_PK_SE_BOMB, 0);

	cameraMgr->startVibration(12, fxPos, 2);
	rumbleMgr->startRumble(15, fxPos, 2);

	Creature* collCreature = event.m_collidingCreature;

	Vector3f curPos   = frog->getPosition();
	Vector3f otherPos = collCreature->getPosition();
	Vector3f direction(otherPos.x - curPos.x, 0, otherPos.z - curPos.z);

	direction.normalise();

	direction = Vector3f(direction.x * 50, 0, direction.z * 50);

	InteractBomb bomb(frog, 10000.0f, &direction);
	collCreature->stimulate(bomb);

	// Water can't save the Pikmin
	if (collCreature->isPiki() && collCreature->inWater()) {
		collCreature->kill(nullptr);
	}
}

void doFrogBombParticle(Game::EnemyBase* frog)
{
	if (frog->getEnemyTypeID() == EnemyTypeID::EnemyID_MaroFrog)
		return;

	Vector3f fxPos;
	frog->getCommonEffectPos(fxPos);

	efx::TSimple1 simpleFx(12, nullptr);
	efx::Arg arg(fxPos);
	simpleFx.create(&arg);

	PSSystem::spSysIF->playSystemSe(PSSE_PK_SE_BOMB, 0);
}

bool isLowGravity()
{
	if (playData->getCurrentCourseIndex() == 3) {
		if (gameSystem->m_inCave) {
			return false;
		} else {
			return true;
		}
	} else {
		return false;
	}
}

void setLowGravity(void)
{
	static float backupGravity = _aiConstants->m_gravity.m_data;
	if (isLowGravity()) {
		_aiConstants->m_gravity.m_data = (backupGravity * 0.4f);
	} else {
		_aiConstants->m_gravity.m_data = backupGravity;
	}
}

}; // namespace Game

#include "Game/Entities/ItemTreasure.h"
#include "Game/pelletMgr.h"
#include "Radar.h"

Radar::Point* getPointFromObj(Game::TPositionObject* obj)
{
	Radar::Point* node = (Radar::Point*)Radar::mgr->m_pointNode1.m_child;
	while (node->m_object != obj) {
		node = (Radar::Point*)node->m_next;
	}
	return node;
}

// no longer used for anything, though I don't feel like unlinking them if needed later
void removeBuriedTreasureRadar(Game::ItemTreasure::Item* treasure) { }
void addPelletUnearthRadar(Game::ItemTreasure::Item* treasure) { }

bool hasTreasure(Game::Pellet* pellet)
{
	Iterator<Game::BaseItem> iTreasure = Game::ItemTreasure::mgr;
	CI_LOOP(iTreasure)
	{
		Game::ItemTreasure::Item* treasure = static_cast<Game::ItemTreasure::Item*>(*iTreasure);
		if (pellet == treasure->m_pellet)
			return true;
	}
	return false;
}

bool shouldDrawTreasure(Radar::Point* point)
{
	if (!Game::playData->m_olimarData[0].hasItem(8)) return false;

	if (!point || !point->m_object)
		return false;
	if (point->m_objType == Radar::MAP_TREASURE || point->m_objType == Radar::MAP_UPGRADE) {
		Game::Creature* obj = (Game::Creature*)point->m_object;
		if (obj->isPellet()) {
			Game::Pellet* pellet = (Game::Pellet*)obj;
			if (hasTreasure(pellet)) {
				return false;
			}
			return true;
		}
	}
	return false;
}

namespace mod {
int keyLockCount;
bool isExitLocked;
bool isBobuMovieQueued = FALSE;

// adjust treasure culling radius to 50.0f if radius was zero
float adjustBoundingRadius(float radius)
{
	if (radius == 0.0f)
		return 50.0f;
	else
		return radius;
}

}; // namespace mod
