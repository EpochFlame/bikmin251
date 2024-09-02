#include "Game/Navi.h"
#include "Game/NaviState.h"
#include "PSM/Navi.h"
#include "Drought/Game/NaviGoHere.h"
#include "Game/MoviePlayer.h"
#include "Game/MapMgr.h"
#include "Iterator.h"
#include "Drought/Pathfinder.h"
#include "Game/CPlate.h"
#include "PSSystem/PSSystemIF.h"

namespace Game
{

bool CheckAllPikisBlue(Navi* navi) {
	Iterator<Creature> iterator(navi->m_cPlateMgr);
	CI_LOOP(iterator)
	{
		Piki* piki = static_cast<Piki*>(*iterator);
		if (piki->m_pikiKind != Game::Blue) {
			return false;
		}
	}
	return true;
}

void NaviFSM::init(Navi* navi)
{
	_1C = -1;
	create(NSID_StateCount);

	registerState(new NaviWalkState);
	registerState(new NaviFollowState);
	registerState(new NaviPunchState);
	registerState(new NaviChangeState);
	registerState(new NaviGatherState);
	registerState(new NaviThrowState);
	registerState(new NaviThrowWaitState);
	registerState(new NaviDopeState);
	registerState(new NaviNukuState);
	registerState(new NaviNukuAdjustState);
	registerState(new NaviContainerState);
	registerState(new NaviAbsorbState);
	registerState(new NaviFlickState);
	registerState(new NaviDamagedState);
	registerState(new NaviPressedState);
	registerState(new NaviFallMeckState);
	registerState(new NaviKokeDamageState);
	registerState(new NaviSaraiState);
	registerState(new NaviSaraiExitState);
	registerState(new NaviDeadState);
	registerState(new NaviStuckState);
	registerState(new NaviDemo_UfoState);
	registerState(new NaviDemo_HoleInState);
	registerState(new NaviPelletState);
	registerState(new NaviCarryBombState);
	registerState(new NaviClimbState);
	registerState(new NaviPathMoveState);
	// added state
    registerState(new NaviGoHereState);
}

void NaviGoHereState::init(Navi* navi, StateArg* arg) {
    P2ASSERT(arg);
    NaviGoHereStateArg* goHereArg = static_cast<NaviGoHereStateArg*>(arg);

	navi->startMotion(IPikiAnims::WALK, IPikiAnims::WALK, nullptr, nullptr);

    mPosition            = goHereArg->mPosition;
	mPath                = goHereArg->mPath;
    mCurrNode            = goHereArg->mPath->mRoot;

}

// usually inlined, plays the navi's voice line when swapped
inline void NaviState::playChangeVoice(Navi* navi)
{
	if (navi->m_naviIndex == 0) { // OLIMAR
		PSSystem::spSysIF->playSystemSe(PSSE_SY_CHANGE_ORIMA, 0);

	} else if (playData->isStoryFlag(STORY_DebtPaid)) { // PRESIDENT
		PSSystem::spSysIF->playSystemSe(PSSE_SY_CHANGE_SHACHO, 0);

	} else { // LOUIE
		PSSystem::spSysIF->playSystemSe(PSSE_SY_CHANGE_LUI, 0);
	}

	if (navi->m_naviIndex == 0) { // OLIMAR
		navi->m_soundObj->startSound(PSSE_PL_PIKON_ORIMA, 0);

	} else if (playData->isStoryFlag(STORY_DebtPaid)) { // PRESIDENT
		navi->m_soundObj->startSound(PSSE_PL_PIKON_SHACHO, 0);

	} else { // LOUIE
		navi->m_soundObj->startSound(PSSE_PL_PIKON_LUI, 0);
	}
}

void NaviGoHereState::exec(Navi* navi) {
    bool done = false;

	if (gameSystem && gameSystem->m_isFrozen) {
		navi->m_velocity = 0.0f;
		return;
	}

    if (mCurrNode) {
        execMove(navi);
    }
    else {
        done = execMoveGoal(navi);
    }

    if (navi->m_padinput) {
		navi->m_cursor->update(navi->m_velocity, false);

        if (!gameSystem->paused_soft() && moviePlayer->m_demoState == 0 && navi->m_padinput->isButtonDown(JUTGamePad::PRESS_B)) {
            done = true;
        }

		// swaps captains
        if (!gameSystem->paused_soft() && moviePlayer->m_demoState == 0 && !gameSystem->isMultiplayerMode() &&
            navi->m_padinput->isButtonDown(JUTGamePad::PRESS_Y) && playData->isDemoFlag(DEMO_Unlock_Captain_Switch)) {

            Navi* currNavi = naviMgr->getAt(1 - navi->m_naviIndex);
            int currID     = currNavi->getStateID();

            if (currNavi->isAlive() && currID != NSID_Nuku && currID != NSID_NukuAdjust && currID != NSID_Punch) {
                gameSystem->m_section->pmTogglePlayer();

                playChangeVoice(currNavi);

                currNavi->getStateID(); // commented out code probably.

                if (currNavi->m_currentState->needYChangeMotion()) {
                    currNavi->m_fsm->transit(currNavi, NSID_Change, nullptr);
                }
            }
        }
    }

    if (done) {
		navi->GoHereSuccess();
        transit(navi, NSID_Walk, nullptr);
    }
}

// moves the navi to the nearest waypoint
bool NaviGoHereState::execMove(Navi* navi)
{
	WayPoint* wp     = mapMgr->m_routeMgr->getWayPoint(mCurrNode->mWpIdx);
	Vector3f wpPos   = wp->m_position;
	wpPos.y          = 0.0f;
	Vector3f naviPos = navi->getPosition();
	naviPos.y        = 0.0f;
	Vector3f diff    = wpPos - naviPos;
	f32 dist = _normaliseXZ(diff);

	if (dist < wp->m_radius) {
		mCurrNode = mCurrNode->m_next;

        if (mCurrNode) {
            WayPoint* nextWp = mapMgr->m_routeMgr->getWayPoint(mCurrNode->mWpIdx);
			bool wpClosed = nextWp->m_flags & (WPF_Closed);
			bool wpWater = nextWp->m_flags & (WPF_Water) && !CheckAllPikisBlue(navi);
            if (wpClosed || wpWater) {
                mPosition = wp->getPosition();
                mCurrNode = nullptr;
				
				navi->GoHereInterupted();
				if (wpWater) {
					navi->GoHereInteruptWater();
				}
				else {
					navi->GoHereInteruptBlocked();
				}
            }
        }

        return true;
	}
	
    navi->makeCStick(true);

    

    navi->m_faceDir += 0.2f * angDist(JMath::atanTable_.atan2_(diff.x, diff.z), navi->m_faceDir);
    navi->m_faceDir = roundAng(navi->m_faceDir);

	navi->m_velocity.x = diff.x * 150.0f;
	navi->m_velocity.z = diff.z * 150.0f;
	return false;
}

// moves the navi to its final target destination
bool NaviGoHereState::execMoveGoal(Navi* navi) {
    Vector3f goalPos = mPosition;
	goalPos.y        = 0.0f;
	Vector3f naviPos = navi->getPosition();
	naviPos.y        = 0.0f;
	Vector3f diff    = goalPos - naviPos;
	f32 dist = _normaliseXZ(diff);

	if (dist < 15.0f) {
		return true;
	}
	
    navi->makeCStick(true);

    
    navi->m_faceDir += 0.2f * angDist(JMath::atanTable_.atan2_(diff.x, diff.z), navi->m_faceDir);
    navi->m_faceDir = roundAng(navi->m_faceDir);

	navi->m_velocity.x = diff.x * 150.0f;
	navi->m_velocity.z = diff.z * 150.0f;
	return false;
}

void NaviGoHereState::cleanup(Navi* navi) {
	delete mPath;
	mPath     = nullptr;
	mCurrNode = nullptr;
}


void Navi::GoHereSuccess() {
	// your code here
}

void Navi::GoHereInterupted() {

}

void Navi::GoHereInteruptBlocked() {

}

void Navi::GoHereInteruptWater() {
	
}

} // namespace Game
