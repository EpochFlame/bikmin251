#include "Dolphin/rand.h"
#include "Game/Entities/SnakeWhole.h"
#include "Game/EnemyAnimKeyEvent.h"
#include "Game/EnemyFunc.h"
#include "Game/CameraMgr.h"
#include "Game/rumble.h"
#include "Game/PikiMgr.h"
#include "Game/Navi.h"
#include "Game/Interaction.h"
#include "efx/THebi.h"
#include "Iterator.h"
#include "nans.h"

namespace Game {
namespace SnakeWhole {

void Obj::flickOnLand()
{
	f32 knockback = C_GENERALPARMS.m_shakeKnockback.m_value;
	f32 damage    = C_GENERALPARMS.m_shakeDamage.m_value;
	f32 range     = C_GENERALPARMS.m_shakeRange.m_value;
	EnemyFunc::flickNearbyPikmin(this, range, knockback, damage, m_faceDir, nullptr);
}

/*
 * --INFO--
 * Address:	802CB94C
 * Size:	0003D0
 */
void FSM::init(EnemyBase* enemy)
{
	create(SNAKEWHOLE_Count);
	registerState(new StateDead);
	registerState(new StateStay);
	registerState(new StateAppear1);
	registerState(new StateAppear2);
	registerState(new StateDisappear);
	registerState(new StateWait);
	registerState(new StateWalk);
	registerState(new StateHome);
	registerState(new StateAttack);
	registerState(new StateEat);
	registerState(new StateStruggle);
}

/*
 * --INFO--
 * Address:	802CBD1C
 * Size:	0000C4
 */
void StateDead::init(EnemyBase* enemy, StateArg* stateArg)
{
	Obj* snagret = static_cast<Obj*>(enemy);
	snagret->deathProcedure();
	snagret->resetEvent(0, EB_Cullable);
	snagret->m_simVelocity = Vector3f(0.0f);
	snagret->setEmotionCaution();
	snagret->startMotion(0, nullptr);
	snagret->createDeadStartEffect();

	Vector3f position = snagret->getPosition();
	cameraMgr->startVibration(0, position, 2);
	rumbleMgr->startRumble(13, position, 2);
}

/*
 * --INFO--
 * Address:	802CBDE0
 * Size:	0001C0
 */
void StateDead::exec(EnemyBase* enemy)
{
	Obj* snagret = static_cast<Obj*>(enemy);
	if (snagret->m_curAnim->m_isRunning) {
		if ((u32)snagret->m_curAnim->m_type == KEYEVENT_2) {
			snagret->deleteJointShadow();
			snagret->createDeadFinishEffect();
			snagret->throwupItem();

		} else if ((u32)snagret->m_curAnim->m_type == KEYEVENT_3) {
			snagret->createWalkSmokeEffect(0.9f);
			Vector3f position = snagret->getPosition();
			cameraMgr->startVibration(3, position, 2);
			rumbleMgr->startRumble(11, position, 2);

		} else if ((u32)snagret->m_curAnim->m_type == KEYEVENT_4) {
			snagret->createWalkSmokeEffect(0.75f);
			Vector3f position = snagret->getPosition();
			cameraMgr->startVibration(3, position, 2);
			rumbleMgr->startRumble(11, position, 2);

		} else if ((u32)snagret->m_curAnim->m_type == KEYEVENT_5) {
			Vector3f position = snagret->getPosition();
			cameraMgr->startVibration(8, position, 2);
			rumbleMgr->startRumble(13, position, 2);

		} else if ((u32)snagret->m_curAnim->m_type == KEYEVENT_END) {
			snagret->kill(nullptr);
		}
	}
}

/*
 * --INFO--
 * Address:	802CBFA0
 * Size:	000004
 */
void StateDead::cleanup(EnemyBase* enemy) { }

/*
 * --INFO--
 * Address:	802CBFA4
 * Size:	00012C
 */
void StateStay::init(EnemyBase* enemy, StateArg* stateArg)
{
	Obj* snagret          = static_cast<Obj*>(enemy);
	snagret->m_stateTimer = 0.0f;
	snagret->finishJointShadow();

	Vector3f position = snagret->getPosition();
	snagret->onSetPosition(position);
	snagret->setAtari(false);
	snagret->setEvent(0, EB_Vulnerable);
	snagret->m_isUnderground = true;
	snagret->setEvent(0, EB_BitterImmune);
	snagret->hardConstraintOn();
	snagret->resetEvent(0, EB_16);
	snagret->setEvent(0, EB_31);
	snagret->resetEvent(0, EB_LifegaugeVisible);

	snagret->m_simVelocity = Vector3f(0.0f);
	snagret->startMotion(1, nullptr);
	snagret->stopMotion();

	if (snagret->m_waterBox) {
		snagret->fadeEfxHamon();
	}
}

/**
 * @note Address: 0x802CC0D0
 * @note Size: 0x618
 */
void StateStay::exec(EnemyBase* enemy)
{
	Obj* snagret     = OBJ(enemy);
	Creature* target = nullptr;
	if (snagret->m_stateTimer > CG_PROPERPARMS(snagret).m_fp12.m_value) {
		f32 territory    = CG_GENERALPARMS(snagret).m_territoryRadius.m_value;
		Vector3f homePos = Vector3f(snagret->m_homePosition);
		f32 tSqr         = territory * territory;

		Iterator<Piki> pikiIterator(pikiMgr);
		bool targetNotFound = true;
		pikiIterator.first();

		while (!pikiIterator.isDone()) {
			Piki* piki = (*pikiIterator);
			if (piki->isAlive() && piki->isPikmin() && !piki->isStickToMouth()) {
				Vector3f pikiPos = piki->getPosition();
				f32 sqrDist      = homePos.sqrDistance(pikiPos);
				if (sqrDist < tSqr) {
					target         = piki;
					targetNotFound = false;
				} else if (sqrDist < 160000.0f) {
					targetNotFound = false;
				}
			}

			if (target) {
				break;
			}
			pikiIterator.next();
		}

		if (target == nullptr) {
			Iterator<Navi> naviIterator(naviMgr);
			naviIterator.first();

			while (!naviIterator.isDone()) {
				Navi* navi = (*naviIterator);
				if (navi->isAlive()) {
					Vector3f naviPos = navi->getPosition();
					f32 sqrDist      = homePos.sqrDistance(naviPos);
					if (sqrDist < tSqr) {
						target         = navi;
						targetNotFound = false;
					} else if (sqrDist < 160000.0f) {
						targetNotFound = false;
					}
				}

				if (target) {
					break;
				}
				naviIterator.next();
			}
		}

		if (targetNotFound) {
			snagret->resetBossAppearBGM();
		}
	}

	snagret->m_stateTimer += sys->m_deltaTime;
	if (target) {
		snagret->m_targetCreature = target;
		snagret->appearNearByTarget(target);
		snagret->setBossAppearBGM();
		if (randWeightFloat(1.0f) < CG_PROPERPARMS(snagret).m_fp01.m_value) {
			transit(snagret, SNAKEWHOLE_Appear1, nullptr);
		} else {
			transit(snagret, SNAKEWHOLE_Appear2, nullptr);
		}
	}
}

/*
 * --INFO--
 * Address:	802CC6E8
 * Size:	000098
 */
void StateStay::cleanup(EnemyBase* enemy)
{
	Obj* snagret = static_cast<Obj*>(enemy);
	snagret->setAtari(true);
	snagret->resetEvent(0, EB_Vulnerable);
	snagret->m_isUnderground = false;
	snagret->resetEvent(0, EB_BitterImmune);
	snagret->hardConstraintOff();
	snagret->setEvent(0, EB_16);
	snagret->resetEvent(0, EB_31);
	snagret->setEvent(0, EB_LifegaugeVisible);
	snagret->lifeIncrement();
}

/*
 * --INFO--
 * Address:	802CC780
 * Size:	0000D4
 */
void StateAppear1::init(EnemyBase* enemy, StateArg* stateArg)
{
	Obj* snagret = static_cast<Obj*>(enemy);
	snagret->setEvent(0, EB_22);
	snagret->resetEvent(0, EB_Cullable);
	snagret->hardConstraintOn();
	snagret->m_simVelocity = Vector3f(0.0f);
	snagret->setEmotionExcitement();
	snagret->startMotion(1, nullptr);
	snagret->createAppearEffect(0);

	Vector3f position = snagret->getPosition();
	cameraMgr->startVibration(6, position, 2);
	rumbleMgr->startRumble(15, position, 2);
}

/*
 * --INFO--
 * Address:	802CC854
 * Size:	0002F8
 */
void StateAppear1::exec(EnemyBase* enemy)
{
	Obj* snagret = static_cast<Obj*>(enemy);
	if (snagret->m_curAnim->m_isRunning) {
		if ((u32)snagret->m_curAnim->m_type == KEYEVENT_2) {
			snagret->resetEvent(0, EB_22);
			snagret->startJointShadow();

		} else if ((u32)snagret->m_curAnim->m_type == KEYEVENT_3) {
			snagret->setEvent(0, EB_22);
			snagret->startBossAttackBGM();

			Vector3f position = snagret->getPosition();
			cameraMgr->startVibration(6, position, 2);
			rumbleMgr->startRumble(14, position, 2);

		} else if ((u32)snagret->m_curAnim->m_type == KEYEVENT_4) {
			snagret->resetEvent(0, EB_22);

			Vector3f position = snagret->getPosition();
			cameraMgr->startVibration(6, position, 2);
			rumbleMgr->startRumble(14, position, 2);

		} else if ((u32)snagret->m_curAnim->m_type == KEYEVENT_END) {
			snagret->setAttackPosition();
			if (snagret->m_health <= 0.0f) {
				transit(snagret, SNAKEWHOLE_Dead, nullptr);

			} else if (EnemyFunc::isStartFlick(snagret, false)) {
				transit(snagret, SNAKEWHOLE_Disappear, nullptr);

			} else if (snagret->getAttackPiki(5) != nullptr || snagret->getAttackNavi(5)) {
				if (snagret->getStickHeadPikmin() != 0) {
					transit(snagret, SNAKEWHOLE_Struggle, nullptr);
				} else {
					transit(snagret, SNAKEWHOLE_Attack, nullptr);
				}

			} else if (snagret->getSearchedTarget()) {
				transit(snagret, SNAKEWHOLE_Walk, nullptr);

			} else {
				transit(snagret, SNAKEWHOLE_Wait, nullptr);
			}
		}

		Vector3f position = snagret->getPosition();
		cameraMgr->startVibration(3, position, 2);
		rumbleMgr->startRumble(8, position, 2);
	}
}

/*
 * --INFO--
 * Address:	802CCB4C
 * Size:	000068
 */
void StateAppear1::cleanup(EnemyBase* enemy)
{
	Obj* snagret = static_cast<Obj*>(enemy);
	snagret->resetEvent(0, EB_22);
	snagret->setEvent(0, EB_Cullable);
	snagret->hardConstraintOff();

	if (snagret->m_waterBox) {
		snagret->createEfxHamon();
	}
}

/*
 * --INFO--
 * Address:	802CCBB4
 * Size:	0000D4
 */
void StateAppear2::init(EnemyBase* enemy, StateArg* stateArg)
{
	Obj* snagret = static_cast<Obj*>(enemy);
	snagret->setEvent(0, EB_22);
	snagret->resetEvent(0, EB_Cullable);
	snagret->hardConstraintOn();
	snagret->m_simVelocity = Vector3f(0.0f);
	snagret->setEmotionExcitement();
	snagret->startMotion(2, nullptr);
	snagret->createAppearEffect(1);

	Vector3f position = snagret->getPosition();
	cameraMgr->startVibration(8, position, 2);
	rumbleMgr->startRumble(12, position, 2);
}

/*
 * --INFO--
 * Address:	802CCC88
 * Size:	000318
 */
void StateAppear2::exec(EnemyBase* enemy)
{
	Obj* snagret = static_cast<Obj*>(enemy);
	if (snagret->m_curAnim->m_isRunning) {
		if ((u32)snagret->m_curAnim->m_type == KEYEVENT_2) {
			snagret->resetEvent(0, EB_22);
			snagret->startJointShadow();

		} else if ((u32)snagret->m_curAnim->m_type == KEYEVENT_3) {
			snagret->startBossAttackBGM();

		} else if ((u32)snagret->m_curAnim->m_type == KEYEVENT_4) {
			snagret->createAppearEffect(2);

			Vector3f position = snagret->getPosition();
			cameraMgr->startVibration(3, position, 2);
			rumbleMgr->startRumble(11, position, 2);

		} else if ((u32)snagret->m_curAnim->m_type == KEYEVENT_5) {
			snagret->setEvent(0, EB_22);

			Vector3f position = snagret->getPosition();
			cameraMgr->startVibration(3, position, 2);
			rumbleMgr->startRumble(11, position, 2);

		} else if ((u32)snagret->m_curAnim->m_type == KEYEVENT_6) {
			snagret->resetEvent(0, EB_22);

			Vector3f position = snagret->getPosition();
			cameraMgr->startVibration(6, position, 2);
			rumbleMgr->startRumble(14, position, 2);

		} else if ((u32)snagret->m_curAnim->m_type == KEYEVENT_END) {
			snagret->setAttackPosition();
			if (snagret->m_health <= 0.0f) {
				transit(snagret, SNAKEWHOLE_Dead, nullptr);

			} else if (EnemyFunc::isStartFlick(snagret, false)) {
				transit(snagret, SNAKEWHOLE_Disappear, nullptr);

			} else if (snagret->getAttackPiki(5) != nullptr || snagret->getAttackNavi(5)) {
				if (snagret->getStickHeadPikmin() != 0) {
					transit(snagret, SNAKEWHOLE_Struggle, nullptr);
				} else {
					transit(snagret, SNAKEWHOLE_Attack, nullptr);
				}

			} else if (snagret->getSearchedTarget()) {
				transit(snagret, SNAKEWHOLE_Walk, nullptr);

			} else {
				transit(snagret, SNAKEWHOLE_Wait, nullptr);
			}
		}
	}
}

/*
 * --INFO--
 * Address:	802CCFA0
 * Size:	000068
 */
void StateAppear2::cleanup(EnemyBase* enemy)
{
	Obj* snagret = static_cast<Obj*>(enemy);
	snagret->resetEvent(0, EB_22);
	snagret->setEvent(0, EB_Cullable);
	snagret->hardConstraintOff();

	if (snagret->m_waterBox) {
		snagret->createEfxHamon();
	}
}

/*
 * --INFO--
 * Address:	802CD008
 * Size:	000064
 */
void StateDisappear::init(EnemyBase* enemy, StateArg* stateArg)
{
	enemy->hardConstraintOn();
	enemy->resetEvent(0, EB_Cullable);
	enemy->m_simVelocity = Vector3f(0.0f);
	enemy->setEmotionCaution();
	enemy->startMotion(3, nullptr);
}

/*
 * --INFO--
 * Address:	802CD06C
 * Size:	000214
 */
void StateDisappear::exec(EnemyBase* enemy)
{
	Obj* snagret = static_cast<Obj*>(enemy);

	if (snagret->m_curAnim->m_isRunning) {
		if ((u32)snagret->m_curAnim->m_type == KEYEVENT_2) {
			Parms* parms1 = static_cast<Parms*>(snagret->m_parms);
			EnemyFunc::flickNearbyNavi(snagret, parms1->m_general.m_shakeRange.m_value, parms1->m_general.m_shakeKnockback.m_value,
			                           parms1->m_general.m_shakeDamage.m_value, -1000.0f, nullptr);
			Parms* parms2 = static_cast<Parms*>(snagret->m_parms);
			EnemyFunc::flickNearbyPikmin(snagret, parms2->m_general.m_shakeRange.m_value, parms2->m_general.m_shakeKnockback.m_value,
			                             parms2->m_general.m_shakeDamage.m_value, -1000.0f, nullptr);

			Parms* parms3 = static_cast<Parms*>(snagret->m_parms);
			EnemyFunc::flickStickPikmin(snagret, parms3->m_general.m_shakeRateMaybe.m_value, parms3->m_general.m_shakeKnockback.m_value,
			                            parms3->m_general.m_shakeDamage.m_value, -1000.0f, nullptr);
			snagret->setEvent(0, EB_22);
			snagret->startBossFlickBGM();

		} else if ((u32)snagret->m_curAnim->m_type == KEYEVENT_3) {
			snagret->resetEvent(0, EB_22);

		} else if ((u32)snagret->m_curAnim->m_type == KEYEVENT_4) {
			Vector3f position = snagret->getPosition();
			efx::Arg fxArg(position);
			efx::THebiAphd_dive diveFx;
			diveFx.create(&fxArg);

			cameraMgr->startVibration(6, position, 2);
			rumbleMgr->startRumble(15, position, 2);

		} else if ((u32)snagret->m_curAnim->m_type == KEYEVENT_5) {
			snagret->m_isUnderground = true;
			snagret->setEvent(0, EB_BitterImmune);
			snagret->m_toFlick = 0.0f;
			snagret->finishJointShadow();

		} else if ((u32)snagret->m_curAnim->m_type == KEYEVENT_END) {
			transit(snagret, SNAKEWHOLE_Stay, nullptr);
		}
	}
}

/*
 * --INFO--
 * Address:	802CD280
 * Size:	000078
 */
void StateDisappear::cleanup(EnemyBase* enemy)
{
	Obj* snagret = static_cast<Obj*>(enemy);
	EnemyFunc::flickStickPikmin(snagret, 1.0f, 10.0f, 0.0f, -1000.0f, nullptr);
	snagret->m_isUnderground = false;
	snagret->resetEvent(0, EB_BitterImmune);
	snagret->resetEvent(0, EB_22);
	snagret->setEvent(0, EB_Cullable);
	snagret->hardConstraintOff();
}

/*
 * --INFO--
 * Address:	802CD2F8
 * Size:	000068
 */
void StateWait::init(EnemyBase* enemy, StateArg* stateArg)
{
	Obj* snagret          = static_cast<Obj*>(enemy);
	snagret->m_stateTimer = 0.0f;
	snagret->m_nextState  = SNAKEWHOLE_NULL;
	snagret->setAttackPosition();
	snagret->m_targetCreature = nullptr;
	snagret->m_simVelocity    = Vector3f(0.0f);
	snagret->startMotion(9, nullptr);
}

/*
 * --INFO--
 * Address:	802CD360
 * Size:	000198
 */
void StateWait::exec(EnemyBase* enemy)
{
	Obj* snagret = static_cast<Obj*>(enemy);
	if (snagret->m_health <= 0.0f) {
		snagret->m_nextState = SNAKEWHOLE_Dead;
		snagret->finishMotion();
	} else if (EnemyFunc::isStartFlick(snagret, false)
	           || snagret->m_stateTimer > static_cast<Parms*>(snagret->m_parms)->m_properParms.m_fp11.m_value) {
		snagret->m_nextState = SNAKEWHOLE_Disappear;
		snagret->finishMotion();
	} else if (snagret->isOutTerritory()) {
		snagret->m_nextState = SNAKEWHOLE_Home;
		snagret->finishMotion();
	} else if (snagret->getAttackPiki(5) != nullptr || snagret->getAttackNavi(5)) {
		snagret->m_nextState = SNAKEWHOLE_Attack;
		snagret->finishMotion();
	} else if (snagret->getSearchedTarget()) {
		snagret->m_nextState = SNAKEWHOLE_Walk;
		snagret->finishMotion();
	} else {
		snagret->m_nextState = SNAKEWHOLE_Wait;
	}

	snagret->m_stateTimer += sys->m_deltaTime;

	if (snagret->m_curAnim->m_isRunning && (u32)snagret->m_curAnim->m_type == KEYEVENT_END) {
		if (snagret->m_nextState == SNAKEWHOLE_Attack && snagret->getStickHeadPikmin() != 0) {
			snagret->m_nextState = SNAKEWHOLE_Struggle;
		}

		transit(snagret, snagret->m_nextState, nullptr);
	}
}

/*
 * --INFO--
 * Address:	802CD4F8
 * Size:	000004
 */
void StateWait::cleanup(EnemyBase* enemy) { }

/*
 * --INFO--
 * Address:	802CD4FC
 * Size:	000048
 */
void StateWalk::init(EnemyBase* enemy, StateArg* stateArg)
{
	Obj* snagret           = static_cast<Obj*>(enemy);
	snagret->_2C1          = false;
	snagret->_2C8          = 0.0f;
	snagret->m_simVelocity = Vector3f(0.0f);
	snagret->startMotion(12, nullptr);
}

/*
 * --INFO--
 * Address:	802CD544
 * Size:	000288
 */
void StateWalk::exec(EnemyBase* enemy)
{
	Obj* snagret = static_cast<Obj*>(enemy);
	snagret->setAttackPosition();
	if (snagret->m_health <= 0.0f) {
		snagret->m_nextState = SNAKEWHOLE_Dead;
		snagret->finishMotion();
	} else if (EnemyFunc::isStartFlick(snagret, false)) {
		snagret->m_nextState = SNAKEWHOLE_Disappear;
		snagret->finishMotion();
	} else if (snagret->isOutTerritory()) {
		snagret->m_nextState = SNAKEWHOLE_Home;
		snagret->finishMotion();
	} else if (snagret->getAttackPiki(5) != nullptr || snagret->getAttackNavi(5)) {
		snagret->m_nextState = SNAKEWHOLE_Attack;
		snagret->finishMotion();
	}

	if (snagret->_2C1) {
		snagret->updateFace();
	} else {
		snagret->m_simVelocity = Vector3f(0.0f);
	}

	if (snagret->m_curAnim->m_isRunning) {
		if ((u32)snagret->m_curAnim->m_type == KEYEVENT_2) {
			snagret->setEvent(0, EB_22);
			snagret->_2C1 = true;
			snagret->_2C8 = 0.0f;

			Creature* target = snagret->getSearchedTarget();
			if (target) {
				Vector3f targetPos = target->getPosition();
				snagret->setJumpMove(targetPos);
			} else {
				snagret->m_nextState = SNAKEWHOLE_Wait;
				snagret->finishMotion();
			}

			snagret->createWalkSmokeEffect(0.75f);

		} else if ((u32)snagret->m_curAnim->m_type == KEYEVENT_3) {
			snagret->resetEvent(0, EB_22);
			snagret->_2C1 = false;
			snagret->createWalkSmokeEffect(0.75f);
			snagret->flickOnLand();

			Vector3f position = snagret->getPosition();
			cameraMgr->startVibration(6, position, 2);
			rumbleMgr->startRumble(14, position, 2);

		} else if ((u32)snagret->m_curAnim->m_type == KEYEVENT_END) {
			if (snagret->m_nextState == SNAKEWHOLE_Attack && snagret->getStickHeadPikmin() != 0) {
				snagret->m_nextState = SNAKEWHOLE_Struggle;
			}

			transit(snagret, snagret->m_nextState, nullptr);
		}
	}
}

/*
 * --INFO--
 * Address:	802CD7CC
 * Size:	000010
 */
void StateWalk::cleanup(EnemyBase* enemy) { enemy->resetEvent(0, EB_22); }

/*
 * --INFO--
 * Address:	802CD7DC
 * Size:	000048
 */
void StateHome::init(EnemyBase* enemy, StateArg* stateArg)
{
	Obj* snagret           = static_cast<Obj*>(enemy);
	snagret->_2C1          = false;
	snagret->_2C8          = 0.0f;
	snagret->m_simVelocity = Vector3f(0.0f);
	snagret->startMotion(12, nullptr);
}

/*
 * --INFO--
 * Address:	802CD824
 * Size:	0001A4
 */
void StateHome::exec(EnemyBase* enemy)
{
	Obj* snagret = static_cast<Obj*>(enemy);
	snagret->setAttackPosition();
	if (snagret->m_health <= 0.0f) {
		snagret->m_nextState = SNAKEWHOLE_Dead;
		snagret->finishMotion();
	} else if (EnemyFunc::isStartFlick(snagret, false)) {
		snagret->m_nextState = SNAKEWHOLE_Disappear;
		snagret->finishMotion();
	} else if (snagret->isInHomeRange()) {
		snagret->m_simVelocity = Vector3f(0.0f);
		snagret->m_nextState   = SNAKEWHOLE_Wait;
		snagret->finishMotion();
	}

	if (snagret->_2C1) {
		snagret->updateFace();
	} else {
		snagret->m_simVelocity = Vector3f(0.0f);
	}

	if (snagret->m_curAnim->m_isRunning) {
		if ((u32)snagret->m_curAnim->m_type == KEYEVENT_2) {
			snagret->setEvent(0, EB_22);
			snagret->_2C1 = true;
			snagret->_2C8 = 0.0f;

			Vector3f targetPos = Vector3f(snagret->m_homePosition);
			snagret->setJumpMove(targetPos);
			snagret->createWalkSmokeEffect(0.75f);

		} else if ((u32)snagret->m_curAnim->m_type == KEYEVENT_3) {
			snagret->resetEvent(0, EB_22);
			snagret->_2C1 = false;
			snagret->createWalkSmokeEffect(0.75f);
			snagret->flickOnLand();

		} else if ((u32)snagret->m_curAnim->m_type == KEYEVENT_END) {
			transit(snagret, snagret->m_nextState, nullptr);
		}
	}
}

/*
 * --INFO--
 * Address:	802CD9C8
 * Size:	000010
 */
void StateHome::cleanup(EnemyBase* enemy) { enemy->resetEvent(0, EB_22); }

/*
 * --INFO--
 * Address:	802CD9D8
 * Size:	00004C
 */
void StateAttack::init(EnemyBase* enemy, StateArg* stateArg)
{
	Obj* snagret = static_cast<Obj*>(enemy);
	snagret->resetEvent(0, EB_Cullable);
	snagret->m_simVelocity = Vector3f(0.0f);
	snagret->startMotion(snagret->_2E4 + 4, nullptr);
}

/*
 * --INFO--
 * Address:	802CDA24
 * Size:	0003D0
 */
void StateAttack::exec(EnemyBase* enemy)
{
	Obj* snagret = static_cast<Obj*>(enemy);
	if (!snagret->isFinishMotion()) {
		snagret->setAttackPosition();
	}

	if (snagret->m_health <= 0.0f) {
		snagret->finishMotion();
	}

	if (snagret->m_curAnim->m_isRunning) {
		if ((u32)snagret->m_curAnim->m_type == KEYEVENT_2) {
			snagret->startJointCallBack();

		} else if ((u32)snagret->m_curAnim->m_type == KEYEVENT_3) {
			int idx    = snagret->_2E4;
			Piki* piki = snagret->getAttackPiki(idx);

			if (piki) {
				CollPart* slot = snagret->getSwallowSlot();
				InteractSwallow swallow(snagret, 1.0f, slot, 0);
				piki->stimulate(swallow);

			} else {
				Navi* navi = snagret->getAttackNavi(idx);

				if (navi) {
					Parms* parms = static_cast<Parms*>(snagret->m_parms);
					InteractAttack attack(snagret, parms->m_general.m_attackDamage.m_value, nullptr);
					navi->stimulate(attack);
				}

				snagret->finishMotion();
			}

			snagret->returnJointCallBack();

		} else if ((u32)snagret->m_curAnim->m_type == KEYEVENT_4) {

			if (!snagret->isFinishMotion() && snagret->getSwallowSlot()) {

				if (snagret->getAttackPiki(5) != nullptr || snagret->getAttackNavi(5)) {
					snagret->startMotion(snagret->_2E4 + 4, nullptr);
					snagret->setMotionFrame(snagret->getFirstKeyFrame());
					snagret->startJointCallBack();

				} else {
					snagret->finishJointCallBack();
				}

			} else {
				snagret->finishJointCallBack();
			}

		} else if ((u32)snagret->m_curAnim->m_type == KEYEVENT_END) {
			if (snagret->m_health <= 0.0f) {
				transit(snagret, SNAKEWHOLE_Dead, nullptr);
				return;
			}

			if (snagret->isSwallowPikmin()) {
				transit(snagret, SNAKEWHOLE_Eat, nullptr);
				return;
			}

			if (EnemyFunc::isStartFlick(snagret, false)) {
				transit(snagret, SNAKEWHOLE_Disappear, nullptr);
				return;
			}

			if (snagret->getAttackPiki(5) != nullptr || snagret->getAttackNavi(5)) {
				if (snagret->getStickHeadPikmin() != 0) {
					transit(snagret, SNAKEWHOLE_Struggle, nullptr);
					return;

				} else {
					transit(snagret, SNAKEWHOLE_Attack, nullptr);
					return;
				}
			}

			if (snagret->isOutTerritory()) {
				transit(snagret, SNAKEWHOLE_Home, nullptr);
				return;
			}

			if (snagret->getSearchedTarget()) {
				transit(snagret, SNAKEWHOLE_Walk, nullptr);
				return;
			}

			transit(snagret, SNAKEWHOLE_Wait, nullptr);
		}
	}
}

/*
 * --INFO--
 * Address:	802CDDF4
 * Size:	000010
 */
void StateAttack::cleanup(EnemyBase* enemy) { enemy->setEvent(0, EB_Cullable); }

/*
 * --INFO--
 * Address:	802CDE04
 * Size:	00003C
 */
void StateEat::init(EnemyBase* enemy, StateArg* stateArg)
{
	enemy->m_simVelocity = Vector3f(0.0f);
	enemy->startMotion(10, nullptr);
}

/*
 * --INFO--
 * Address:	802CDE40
 * Size:	0001F0
 */
void StateEat::exec(EnemyBase* enemy)
{
	Obj* snagret = static_cast<Obj*>(enemy);
	if (snagret->m_curAnim->m_isRunning) {
		if ((u32)snagret->m_curAnim->m_type == KEYEVENT_2) {
			Parms* parms = static_cast<Parms*>(snagret->m_parms);
			EnemyFunc::swallowPikmin(snagret, parms->m_properParms.m_poisonDamage.m_value, nullptr);

		} else if ((u32)snagret->m_curAnim->m_type == KEYEVENT_END) {
			snagret->setAttackPosition();

			if (snagret->m_health <= 0.0f) {
				transit(snagret, SNAKEWHOLE_Dead, nullptr);
				return;
			}

			if (EnemyFunc::isStartFlick(snagret, false)) {
				transit(snagret, SNAKEWHOLE_Disappear, nullptr);
				return;
			}

			if (snagret->getAttackPiki(5) != nullptr || snagret->getAttackNavi(5)) {
				if (snagret->getStickHeadPikmin() != 0) {
					transit(snagret, SNAKEWHOLE_Struggle, nullptr);
					return;

				} else {
					transit(snagret, SNAKEWHOLE_Attack, nullptr);
					return;
				}
			}

			if (snagret->isOutTerritory()) {
				transit(snagret, SNAKEWHOLE_Home, nullptr);
				return;
			}

			if (snagret->getSearchedTarget()) {
				transit(snagret, SNAKEWHOLE_Walk, nullptr);
				return;
			}

			transit(snagret, SNAKEWHOLE_Wait, nullptr);
		}
	}
}

/*
 * --INFO--
 * Address:	802CE030
 * Size:	000004
 */
void StateEat::cleanup(EnemyBase* enemy) { }

/*
 * --INFO--
 * Address:	802CE034
 * Size:	000040
 */
void StateStruggle::init(EnemyBase* enemy, StateArg* stateArg)
{
	Obj* snagret           = static_cast<Obj*>(enemy);
	snagret->m_stateTimer  = 0.0f;
	snagret->m_simVelocity = Vector3f(0.0f);
	snagret->startMotion(11, nullptr);
}

/*
 * --INFO--
 * Address:	802CE074
 * Size:	0001C8
 */
void StateStruggle::exec(EnemyBase* enemy)
{
	Obj* snagret = static_cast<Obj*>(enemy);
	if (snagret->m_stateTimer > 1.5f) {
		snagret->finishMotion();
	}

	snagret->m_stateTimer += sys->m_deltaTime;
	if (snagret->m_curAnim->m_isRunning && (u32)snagret->m_curAnim->m_type == KEYEVENT_END) {
		snagret->setAttackPosition();

		if (snagret->m_health <= 0.0f) {
			transit(snagret, SNAKEWHOLE_Dead, nullptr);
			return;
		}

		if (EnemyFunc::isStartFlick(snagret, false)) {
			transit(snagret, SNAKEWHOLE_Disappear, nullptr);
			return;
		}

		if (snagret->getAttackPiki(5) != nullptr || snagret->getAttackNavi(5)) {
			transit(snagret, SNAKEWHOLE_Attack, nullptr);
			return;
		}

		if (snagret->isOutTerritory()) {
			transit(snagret, SNAKEWHOLE_Home, nullptr);
			return;
		}

		if (snagret->getSearchedTarget()) {
			transit(snagret, SNAKEWHOLE_Walk, nullptr);
			return;
		}

		transit(snagret, SNAKEWHOLE_Wait, nullptr);
	}
}

/*
 * --INFO--
 * Address:	802CE23C
 * Size:	000004
 */
void StateStruggle::cleanup(EnemyBase* enemy) { }

} // namespace SnakeWhole
} // namespace Game
