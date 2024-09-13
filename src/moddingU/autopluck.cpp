#include "Game/NaviParms.h"
#include "Game/NaviState.h"
#include "Game/MoviePlayer.h"
#include "Game/PikiMgr.h"
#include "Game/PikiState.h"
#include "Game/Entities/ItemPikihead.h"
#include "PSM/Navi.h"

namespace Game {
    
void NaviState::swapNavi(Navi* navi)
{
	Navi* currNavi = naviMgr->getAt(1 - navi->m_naviIndex);
	int currID     = currNavi->getStateID();

	if (currNavi->isAlive() && currID != NSID_Punch) {
		gameSystem->m_section->pmTogglePlayer();

		playChangeVoice(currNavi);

		if (currNavi->getStateID() == NSID_Follow) {
			InteractFue whistle(currNavi, 0, 0);
			navi->stimulate(whistle);
		}

		if (currNavi->m_currentState->needYChangeMotion()) {
			currNavi->m_fsm->transit(currNavi, NSID_Change, nullptr);
		}
	}
}

void NaviWalkState::execAI(Navi* navi)
{
	switch (mAIState) {
	case WALKAI_Wait:
		navi->procActionButton();
		execAI_wait(navi);
		checkAI(navi);
		break;

	case WALKAI_Animation:
		execAI_animation(navi);
		checkAI(navi);
		break;

	case WALKAI_Escape:
		execAI_escape(navi);
		break;

	case WALKAI_Attack:
		execAI_attack(navi);
		break;
	}
}

void NaviNukuState::init(Navi* navi, StateArg* stateArg)
{
	if (stateArg != nullptr) {
		mIsFollower = static_cast<NaviNukuArg*>(stateArg)->mIsFollowing;
	} else {
		mIsFollower = false;
	}
	if (navi->_26A != 0) {
		mAnimID = IPikiAnims::NUKU3;
	} else {
		mAnimID = IPikiAnims::NUKU;
	}
	navi->startMotion(mAnimID, mAnimID, navi, nullptr);
	mCounter = static_cast<NaviParms*>(navi->m_parms)->m_naviParms.m_p042.m_value;
	navi->m_soundObj->startSound(PSSE_PL_PULLING_PIKI, 0);
	mDidPluckSE = 0;
	mIsActive   = 0;
	mDidPressA  = 0;
	_15         = 0;
	navi->m_mass = 0.0f;
}

void NaviNukuState::exec(Navi* navi)
{
	if (!mDidPressA) {
		mDidPressA = true;
	}

    if (moviePlayer && moviePlayer->m_demoState != 0) {
		if (mIsFollower) {
			NaviFollowArg followArg(false);
			transit(navi, NSID_Follow, &followArg);
			return;
		}
		transit(navi, NSID_Walk, nullptr);
		return;
	}

	navi->m_velocity = 0.0f;
	navi->m_position2       = 0.0f;
	if (!navi->assertMotion(mAnimID)) {
		if (mIsFollower) {
			NaviFollowArg followArg(false);
			transit(navi, NSID_Follow, &followArg);
		} else {
			transit(navi, NSID_Walk, nullptr);
		}
		navi->_26A = 0;
	} else {
		mDidPressA = true;
		mIsActive = true;
		navi->_26A++;
	}

	if (navi->m_padinput && navi->m_padinput->getButton() & PAD_BUTTON_B) {
		navi->_26A = 0;
		transit(navi, NSID_Walk, nullptr);
		return;
	}

	if (navi->m_padinput && !gameSystem->paused_soft() && moviePlayer->m_demoState == 0 
		&& !gameSystem->isMultiplayerMode() && navi->m_padinput->isButtonDown(JUTGamePad::PRESS_Y) 
		&& playData->isDemoFlag(DEMO_Unlock_Captain_Switch)) 
	{
		swapNavi(navi);
	}
}

void NaviNukuState::onKeyEvent(Navi* navi, SysShape::KeyEvent const& key)
{
	switch (key.m_type) {
	case KEYEVENT_2:
		_15 = true;
		mCounter--;
		if (mCounter == 0) {
			navi->m_soundObj->startSound(PSSE_PL_PULLOUT_PIKI, 0);
			mDidPluckSE = true;
		}
		break;
	case KEYEVENT_END:
		if (mIsActive) {
			if (!navi->procActionButton()) {
				mIsActive = false;
				if (mIsFollower) {
					NaviFollowArg arg(false); // not new to party
					transit(navi, NSID_Follow, &arg);
				} else {
					transit(navi, NSID_Walk, nullptr);
				}
				navi->_26A = 0;
			}
		} else {
			if (mIsFollower) {
				NaviFollowArg arg(false); // not new to party
				transit(navi, NSID_Follow, &arg);
			} else {
				transit(navi, NSID_Walk, nullptr);
			}
			navi->_26A = 0;
		}
		break;
	}
}

void NaviNukuAdjustState::exec(Navi* navi)
{
	if (moviePlayer && moviePlayer->m_demoState  != 0) {
		if (mIsFollowing) {
			transit(navi, NSID_Follow, nullptr);
		} else {
			transit(navi, NSID_Walk, nullptr);
		}
		return;
	}

	if (!mPikiHead->isAlive() && !navi->procActionButton()) {
		if (mIsFollowing) {
			transit(navi, NSID_Follow, nullptr);
		} else {
			transit(navi, NSID_Walk, nullptr);
		}
		return;
	}

	if (!mIsFollowing) {
		navi->makeCStick(false);
	}

	if (navi->m_padinput && navi->m_padinput->getButton() & Controller::PRESS_B) {
		navi->_26A = 0;
		transit(navi, NSID_Walk, nullptr);
		return;
	}

	mNaviPosition = navi->getPosition();

	Vector3f sproutToNavi = mPikiHead->getPosition() - navi->getPosition();
	sproutToNavi.length(); // unused

	Vector3f targetToNavi    = mTargetPosition - navi->getPosition(); // f26, f27, f28
	f32 targetToNaviDistance = targetToNavi.length2D();                 // f31
	f32 absoluteDeltaY       = absF(targetToNavi.y);

	f32 normalisedDistance = targetToNavi.normalise(); // f30, why tho

	f32 newFaceDir = mAngleToPiki;
	f32 angle      = angDist(newFaceDir, navi->m_faceDir);

	if (absF(angle) < (PI / 10) && targetToNaviDistance < 2.0f && absoluteDeltaY < 10.0f) {
		navi->m_faceDir      = newFaceDir;
		PikiMgr::mBirthMode = PikiMgr::PSM_Force;
		Piki* piki          = pikiMgr->birth();
		PikiMgr::mBirthMode = PikiMgr::PSM_Normal;

		if (!piki) {
			if (mIsFollowing) {
				transit(navi, NSID_Follow, nullptr);
			} else {
				transit(navi, NSID_Walk, nullptr);
			}
			return;
		}

		piki->init(nullptr);
		piki->changeShape(mPikiHead->m_color);
		piki->changeHappa(mPikiHead->m_headType);
        if (Game::playData->m_olimarData[0].hasItem(Game::OlimarData::ODII_RepugnantAppendage)) {
            piki->changeHappa(Game::Bud);
        }

		Vector3f sproutPos = mPikiHead->getPosition();
		piki->setPosition(sproutPos, false);
		mPikiHead->kill(nullptr);
		mPikiHead = nullptr;

		NukareStateArg nukareArg;
		nukareArg.mIsPlucking = navi->_26A != 0;
		nukareArg.mNavi       = navi;
		piki->m_fsm->transit(piki, PIKISTATE_Nukare, &nukareArg);

		NaviNukuArg nukuArg;
		nukuArg.mIsFollowing = mIsFollowing;

		transit(navi, NSID_Nuku, &nukuArg);

	} else {
		f32 angleOffset = 0.2f * angle;
		navi->m_faceDir  = roundAng(navi->m_faceDir + angleOffset);

		f32 speed = 100.0f;
		if (speed * sys->m_deltaTime > normalisedDistance) {
			speed = 0.5f / sys->m_deltaTime;
		}

		Vector3f vel          = targetToNavi * speed;
		navi->m_position2       = vel;
		navi->m_velocity = Vector3f(0.0f);
		navi->m_velocity = vel;
	}

	if (mWallHitCounter > 10) {
		if (mIsFollowing) {
			transit(navi, NSID_Follow, nullptr);
		} else {
			transit(navi, NSID_Walk, nullptr);
		}

		return;
	}

	if (!mIsMoving) {
		return;
	}

	Vector3f currentVel = navi->m_position2; // f31, f30, f29
	mIsMoving--;
	Vector3f naviPos = navi->getPosition();

	Vector3f pikiToNavi    = mCollidedPikiPosition - naviPos;
	f32 distancePikiToNavi = pikiToNavi.normalise();

	// If the distance is 0, return
	if (!(distancePikiToNavi > 0.0f)) {
		return;
	}

	f32 velocityDifference = pikiToNavi.z * currentVel.z - targetToNavi.x * currentVel.x;
	Vector3f newVel(pikiToNavi.x, 0.0f, -pikiToNavi.z);

	f32 simSpeed = currentVel.length();

	newVel *= simSpeed;
	if (!(velocityDifference < 0.0f)) {
		newVel *= -1.0f;
	}

	// Interpolate 35% current velocity and 65% new velocity
	Vector3f blendedVel = currentVel * 0.35f + newVel * 0.65f;

	f32 speed = blendedVel.normalise();
	if (speed != 0.0f) {
		Vector3f finalVel     = blendedVel * simSpeed;
		navi->m_position2       = finalVel;
		navi->m_velocity = finalVel;
    }
}

bool NaviNukuAdjustState::callable() { return true; }

} // namespace Game

