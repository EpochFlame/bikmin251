#include "BitFlag.h"
#include "CollInfo.h"
#include "Dolphin/math.h"
#include "Dolphin/rand.h"
#include "Game/generalEnemyMgr.h"
#include "efx/Arg.h"
#include "efx/TEnemyApsmoke.h"
#include "efx/TEnemyBomb.h"
#include "efx/TEnemyDead.h"
#include "efx/TEnemyDownSmoke.h"
#include "efx/TEnemyDownWat.h"
#include "efx/TEnemyPoison.h"
#include "Game/WaterBox.h"
#include "Game/AIConstants.h"
#include "Game/BaseItem.h"
#include "Game/BaseHIO.h"
#include "Game/Cave/RandMapMgr.h"
#include "Game/cellPyramid.h"
#include "Game/EnemyAnimatorBase.h"
#include "Game/EnemyAnimKeyEvent.h"
#include "Game/EnemyBase.h"
#include "Game/enemyInfo.h"
#include "Game/EnemyParmsBase.h"
#include "Game/EnemyStateMachine.h"
#include "Game/EnemyStone.h"
#include "Game/gamePlayData.h"
#include "Game/GameSystem.h"
#include "Game/Interaction.h"
#include "Game/Entities/ItemHoney.h"
#include "Game/Entities/PelletNumber.h"
#include "Game/MapMgr.h"
#include "Game/MoviePlayer.h"
#include "Game/pelletMgr.h"
#include "Game/Piki.h"
#include "Game/PlatInstance.h"
#include "Game/shadowMgr.h"
#include "Game/TekiStat.h"
#include "Game/WalkSmokeEffect.h"
#include "JSystem/JMath.h"
#include "JSystem/J3D/J3DJoint.h"
#include "JSystem/J3D/J3DModel.h"
#include "LifeGaugeMgr.h"
#include "Matrix3f.h"
#include "ObjectTypes.h"
#include "PS.h"
#include "PSM/CreatureAnime.h"
#include "PSM/EnemyBase.h"
#include "PSM/EnemyBoss.h"
#include "PSM/BossBgmFader.h"
#include "PSM/ObjCalc.h"
#include "PSM/ObjMgr.h"
#include "PSM/BgmTrackMap.h"
#include "PSM/CreaturePrm.h"
#include "PSGame/Global.h"
#include "PSSystem/PSSystemIF.h"
#include "PSSystem/SingletonBase.h"
#include "PSSystem/PSStream.h"
#include "Sys/Sphere.h"
#include "SysShape/AnimInfo.h"
#include "SysShape/AnimMgr.h"
#include "SysShape/Model.h"
#include "SysShape/Joint.h"
#include "System.h"
#include "Radar.h"
#include "types.h"
#include "Vector3.h"
#include "nans.h"

JKRArchive* Game::gParmArc;
PSGame::BASARC* PSSystem::ArcMgr<PSGame::BASARC>::sInstance;
PSM::BossBgmFader::Mgr* PSSystem::SingletonBase<PSM::BossBgmFader::Mgr>::sInstance;
PSM::ObjCalcBase* PSSystem::SingletonBase<PSM::ObjCalcBase>::sInstance;
PSM::CreaturePrm* PSSystem::SingletonBase<PSM::CreaturePrm>::sInstance;
PSM::ObjMgr* PSSystem::SingletonBase<PSM::ObjMgr>::sInstance;
PSM::BgmTrackMapFile* PSSystem::SingletonBase<PSM::BgmTrackMapFile>::sInstance;
PSGame::SoundTable::CategoryMgr* PSSystem::SingletonBase<PSGame::SoundTable::CategoryMgr>::sInstance;
PSGame::SeMgr* PSSystem::SingletonBase<PSGame::SeMgr>::sInstance;
PSSystem::SeqDataList* PSSystem::SingletonBase<PSSystem::SeqDataList>::sInstance;
PSSystem::StreamDataList* PSSystem::SingletonBase<PSSystem::StreamDataList>::sInstance;

namespace Game {

static const int someEBArray[3] = { 0, 0, 0 };
/*
 * Unused. Just here to make the rodata line up.
 * --INFO--
 * Address: ........
 * Size:  0000e4
 */
static void _Print(char* format, ...) { OSReport(format, "enemyBase"); }

namespace EnemyBaseFSM {
/*
 * --INFO--
 * Address:	800FF26C
 * Size:	0000F8
 */
void State::animation(EnemyBase* enemy)
{
	if (enemy->isEvent(0, EB_Alive)) {
		GeneralEnemyMgr::mTotalCount++;

		bool fxExists = enemy->isCullingOff();

		enemy->updateCell();
		enemy->updateLOD(enemy->m_lodParm);

		if (enemy->isCullingOff()) {
			if (enemy->isEvent(0, EB_16)) {
				enemy->doAnimationCullingOff();
			} else {
				enemy->doAnimationCullingOn();
			}

			if (!fxExists) {
				enemy->createEffects();
			}

			return;
		}

		GeneralEnemyMgr::mCullCount++;
		enemy->doAnimationCullingOn();
		if (fxExists == true) {
			enemy->fadeEffects();
		}
	}
}

/*
 * --INFO--
 * Address:	800FF364
 * Size:	0001E0
 */
bool BirthTypeDropState::isFinishableWaitingBirthTypeDrop(EnemyBase* enemy)
{
	Sys::Sphere sphere(enemy->m_position, static_cast<EnemyParmsBase*>(enemy->m_parms)->m_general.m_privateRadius.m_value);
	bool result = false;

	CellIteratorArg cellIteratorArg(sphere);
	CellIterator cellIterator(cellIteratorArg);
	cellIterator.first();
	while (cellIterator.isDone() == false) {
		Creature* cell = (Creature*)*cellIterator;
		if (cell->isAlive()) {
			if (cell->isNavi() || (cell->isPiki() && static_cast<Piki*>(cell)->isPikmin())) {
				f32 privateRadius = static_cast<EnemyParmsBase*>(enemy->m_parms)->m_general.m_privateRadius.m_value;
				Vector2f delta;
				enemy->getDistanceTo(cell, delta);

				if ((SQUARE(delta.x) + SQUARE(delta.y)) < SQUARE(privateRadius)) {
					result = true;
				}
			}
		}
		cellIterator.next();
	}
	return result;
}

/*
 * --INFO--
 * Address:	800FF550
 * Size:	0001A8
 */
void BirthTypeDropState::init(EnemyBase* enemy, StateArg* arg)
{
	if (mapMgr) {
		enemy->m_position.y              = mapMgr->getMinY(enemy->m_position) + 300.0f;
		EnemyTypeID::EEnemyTypeID typeID = enemy->getEnemyTypeID();
		if (typeID != EnemyTypeID::EnemyID_BluePom && typeID != EnemyTypeID::EnemyID_RedPom && typeID != EnemyTypeID::EnemyID_YellowPom
		    && typeID != EnemyTypeID::EnemyID_BlackPom && typeID != EnemyTypeID::EnemyID_WhitePom
		    && typeID != EnemyTypeID::EnemyID_RandPom) {
			f32 theta = randFloat() * TAU;
			enemy->m_position.x += pikmin2_sinf(theta) * 50.0f;
			enemy->m_position.z += pikmin2_cosf(theta) * 50.0f;
		}
	}
	enemy->setPosition(enemy->m_position, false);
	enemy->updateCell();
	enemy->startWaitingBirthTypeDrop();
}

/*
 * --INFO--
 * Address:	800FF6F8
 * Size:	00006C
 */
void BirthTypeDropState::update(EnemyBase* enemy)
{
	if (isFinishableWaitingBirthTypeDrop(enemy)) {
		transit(enemy, EBS_Appear, nullptr);
	}
}

/*
 * --INFO--
 * Address:	800FF764
 * Size:	000030
 */
void BirthTypeDropState::cleanup(EnemyBase* enemy) { enemy->finishWaitingBirthTypeDrop(); }

/*
 * --INFO--
 * Address:	800FF794
 * Size:	0001C4
 */
bool BirthTypeDropPikminState::isFinishableWaitingBirthTypeDrop(EnemyBase* enemy)
{
	Sys::Sphere sphere(enemy->m_position, static_cast<EnemyParmsBase*>(enemy->m_parms)->m_general.m_privateRadius.m_value);
	bool result = false;

	CellIteratorArg cellIteratorArg(sphere);
	CellIterator cellIterator(cellIteratorArg);
	cellIterator.first();
	while (cellIterator.isDone() == false) {
		Creature* cell = (Creature*)(*cellIterator);
		if (cell->isAlive() && cell->isPiki() && static_cast<Piki*>(cell)->isPikmin()) {
			f32 privateRadius = static_cast<EnemyParmsBase*>(enemy->m_parms)->m_general.m_privateRadius.m_value;
			Vector2f delta;
			enemy->getDistanceTo(cell, delta);

			if ((SQUARE(delta.x) + SQUARE(delta.y)) < SQUARE(privateRadius)) {
				result = true;
			}
		}
		cellIterator.next();
	}
	return result;
}

/*
 * --INFO--
 * Address:	800FF958
 * Size:	0001A8
 */
bool BirthTypeDropOlimarState::isFinishableWaitingBirthTypeDrop(EnemyBase* enemy)
{

	Sys::Sphere sphere(enemy->m_position, static_cast<EnemyParmsBase*>(enemy->m_parms)->m_general.m_privateRadius.m_value);
	bool result = false;

	CellIteratorArg cellIteratorArg(sphere);
	CellIterator cellIterator(cellIteratorArg);
	cellIterator.first();
	while (cellIterator.isDone() == 0) {
		Creature* cell = (Creature*)(*cellIterator);
		if (cell->isAlive() && cell->isNavi()) {
			f32 privateRadius = static_cast<EnemyParmsBase*>(enemy->m_parms)->m_general.m_privateRadius.m_value;
			Vector2f delta;
			enemy->getDistanceTo(cell, delta);

			if ((SQUARE(delta.x) + SQUARE(delta.y)) < SQUARE(privateRadius)) {
				result = true;
			}
		}
		cellIterator.next();
	}
	return result;
}

/*
 * --INFO--
 * Address:	800FFB00
 * Size:	00018C
 */
bool BirthTypeDropTreasureState::isFinishableWaitingBirthTypeDrop(EnemyBase* enemy)
{
	bool result = false;
	PelletIterator pelletIterator;

	pelletIterator.first();
	while (!pelletIterator.isDone()) {
		Pellet* cell = (Pellet*)(*pelletIterator);
		if (cell->isAlive() && cell->isCarried()) {
			Vector3f pos      = cell->getPosition(); // why this
			f32 privateRadius = static_cast<EnemyParmsBase*>(enemy->m_parms)->m_general.m_privateRadius.m_value;
			Vector2f delta;

			enemy->getDistanceTo(cell, delta);

			if ((SQUARE(delta.x) + SQUARE(delta.y)) < SQUARE(privateRadius)) {
				result = true;
			}
		}
		pelletIterator.next();
	}
	return result;
}

/*
 * --INFO--
 * Address:	800FFCA8
 * Size:	000008
 */
bool BirthTypeDropEarthquakeState::isFinishableWaitingBirthTypeDrop(EnemyBase*) { return false; }

/*
 * --INFO--
 * Address:	800FFCB0
 * Size:	000024
 */
void AppearState::entry(EnemyBase* enemy) { enemy->doEntryLiving(); }

/*
 * --INFO--
 * Address:	800FFCD4
 * Size:	0000FC
 */
void AppearState::init(EnemyBase* enemy, StateArg* arg)
{
	efx::TEnemyApsmoke effect; // this is "Appear Smoke"
	// for context, the term "effects" refer to particle effects
	f32 mod                      = enemy->m_scaleModifier;
	EnemyTypeID::EEnemyTypeID id = enemy->getEnemyTypeID();

	efx::ArgEnemyType effectArg(enemy->getPosition(), id, mod);
	effect.create(&effectArg);

	enemy->m_scale         = 0.0f;
	enemy->m_stunAnimTimer = 0.0f;
}

/*
 * --INFO--
 * Address:	800FFDEC
 * Size:	000130
 */
void AppearState::update(EnemyBase* enemy)
{
	enemy->m_stunAnimTimer += 2.0f * sys->m_deltaTime;
	if (enemy->m_stunAnimTimer > 1.0f) {
		transit(enemy, EBS_Living, 0);
		return;
	}

	enemy->m_scale.x = 2.0f * enemy->m_stunAnimTimer;
	if (enemy->m_scale.x > 1.0f) {
		enemy->m_scale.x = 1.0f;
	}

	enemy->m_scale.x += 0.2f * pikmin2_sinf(TAU * enemy->m_stunAnimTimer);
	f32 newScale     = enemy->m_scale.x;
	enemy->m_scale.z = newScale;
	enemy->m_scale.y = newScale;

	enemy->doUpdate();
	enemy->doUpdateCommon();
}

/*
 * --INFO--
 * Address:	800FFF1C
 * Size:	00001C
 */
void AppearState::cleanup(EnemyBase* enemy)
{
	enemy->m_scale         = 1.0f;
	enemy->m_stunAnimTimer = 0.0f;
}

/*
 * --INFO--
 * Address:	800FFF38
 * Size:	00010C
 */
void EnemyBaseFSM::LivingState::simulation(EnemyBase* enemy, f32 constraint)
{
	if ((enemy->isEvent(0, EB_HardConstraint)) || isLiving(enemy) && !(enemy->isEvent(1, EB2_1)) && !(enemy->isEvent(1, EB2_5))) {

		if (enemy->isCullingOff()) {
			enemy->doSimulationConstraint(constraint);
		}

	} else if (enemy->isCullingOff()) {
		enemy->collisionMapAndPlat(constraint);
		enemy->updateWaterBox();
	}

	Creature::CheckHellArg hellArg;
	hellArg.m_isKillPiki = false;
	if (enemy->checkHell(hellArg) == 2) {
		enemy->getCreatureName();
		enemy->getCreatureID();
		enemy->gotoHell();
	}
}

/*
 * --INFO--
 * Address:	80100084
 * Size:	000040
 */
void LivingState::entry(EnemyBase* enemy)
{
	if (enemy->m_pellet) {
		enemy->doEntryCarcass();
		return;
	}
	enemy->doEntryLiving();
}

/*
 * --INFO--
 * Address:	801000C4
 * Size:	000030
 */
void LivingState::updateCullingOff(EnemyBase* enemy) { enemy->doUpdate(); }

/*
 * --INFO--
 * Address:	801000F4
 * Size:	000030
 */
void LivingState::updateAlways(EnemyBase* enemy)
{
	if (enemy->isEvent(0, EB_21)) {
		enemy->startStoneState();
	}
}

/*
 * --INFO--
 * Address:	80100124
 * Size:	0001BC
 */
void LivingState::update(EnemyBase* enemy)
{
	sys->m_timers->_start("e-upd-do", 1);

	enemy->resetEvent(0, EB_17);
	enemy->resetEvent(0, EB_18);

	enemy->m_soundObj->exec();

	if (enemy->m_pellet) {
		enemy->doUpdateCarcass();
	} else {
		if (enemy->isCullingOff()) {
			updateCullingOff(enemy);
			enemy->doUpdateCommon();
		}

		updateAlways(enemy);

		if (!(enemy->m_health <= 0.0f) && (enemy->isAlive())) {
			enemy->lifeRecover();
			enemy->injure();
		}

		if (enemy->m_maxExistTime > 0.0f) {
			enemy->m_existTimer += sys->m_deltaTime;

			if (enemy->m_existTimer > enemy->m_maxExistTime) {
				enemy->addDamage(enemy->m_maxHealth, 1.0f);
				enemy->resetEvent(0, EB_Cullable);
				enemy->resetEvent(0, EB_Flying);
			}
		}
	}

	sys->m_timers->_stop("e-upd-do");
}

/*
 * --INFO--
 * Address:	801002E0
 * Size:	000048
 */
void EnemyBaseFSM::FitState::updateCullingOff(EnemyBase* enemy)
{
	if (enemy->m_health <= 0.0f) {
		transit(enemy, EBS_Living, 0);
	}
}

/*
 * --INFO--
 * Address:	80100328
 * Size:	000150
 */
void EnemyBaseFSM::FitState::init(EnemyBase* enemy, StateArg* arg)
{
	enemy->doUpdate();
	enemy->m_eventBuffer.m_flags[0].typeView = enemy->m_events.m_flags[0].typeView;
	enemy->m_eventBuffer.m_flags[1].typeView = enemy->m_events.m_flags[1].typeView;
	enemy->setEvent(1, EB2_2);
	enemy->stopMotion();
	enemy->setEvent(0, EB_Constraint);

	enemy->m_simVelocity = 0.0f;
	enemy->m_impVelocity = 0.0f;
	enemy->doStartEarthquakeFitState();

	m_enemyPiyo.m_position       = enemy->getFitEffectPos();
	f32 scale                    = enemy->m_scaleModifier;
	EnemyTypeID::EEnemyTypeID id = enemy->getEnemyTypeID();

	efx::ArgEnemyType effectArg(enemy->m_position, id, scale);
	m_enemyPiyo.create(&effectArg);
}

/*
 * --INFO--
 * Address:	80100478
 * Size:	000080
 */
void FitState::cleanup(EnemyBase* enemy)
{
	enemy->m_events.m_flags[0] = enemy->m_eventBuffer.m_flags[0];
	enemy->m_events.m_flags[1] = enemy->m_eventBuffer.m_flags[1];
	enemy->resetEvent(1, EB2_2);
	enemy->startMotion();
	enemy->doFinishEarthquakeFitState();
	m_enemyPiyo.fade();
}

/*
 * --INFO--
 * Address:	801004F8
 * Size:	000204
 */
void FitState::updateAlways(EnemyBase* enemy)
{
	enemy->m_stunAnimTimer += sys->m_deltaTime;
	if ((enemy->m_stunAnimTimer > ((EnemyParmsBase*)enemy->m_parms)->m_general.m_purplePikminStunTime.m_value) || (enemy->isEvent(0, EB_21))
	    || (((enemy->m_health <= 0.0f)))) {
		enemy->m_stunAnimTimer = 0.0f;
		transit(enemy, EBS_Living, 0);
	} else {
		f32 sinStun
		    = 4.0f
		    * pikmin2_sinf((PI * enemy->m_stunAnimTimer) / ((EnemyParmsBase*)enemy->m_parms)->m_general.m_purplePikminStunTime.m_value);
		if (sinStun > 1.0f) {
			sinStun = 1.0f;
		}
		f32 theta = (TAU * enemy->m_stunAnimTimer) / 0.25f;

		enemy->m_stunAnimRotation.x = sinStun * ((PI * DEG2RAD) * pikmin2_sinf(theta));
		enemy->m_stunAnimRotation.y = 0.0f;
		enemy->m_stunAnimRotation.z = sinStun * ((PI * DEG2RAD) * pikmin2_cosf(theta));
	}
	m_enemyPiyo.m_position = enemy->getFitEffectPos();
}

/*
 * --INFO--
 * Address:	801006FC
 * Size:	000088
 */
void EarthquakeState::init(EnemyBase* enemy, StateArg* arg)
{
	enemy->doUpdate();
	enemy->setEvent(1, EB2_1);
	enemy->stopMotion();
	EarthquakeStateArg* eqArg = static_cast<EarthquakeStateArg*>(arg);
	enemy->doStartEarthquakeState(eqArg->m_bounceFactor);
	this->_10 = 0;
}

/*
 * --INFO--
 * Address:	80100784
 * Size:	000050
 */
void EarthquakeState::cleanup(EnemyBase* enemy)
{
	enemy->resetEvent(1, EB2_1);
	enemy->startMotion();
	enemy->doFinishEarthquakeState();
}

/*
 * --INFO--
 * Address:	801007D4
 * Size:	000158
 */
void EarthquakeState::updateCullingOff(EnemyBase* enemy)
{
	if ((enemy->m_health <= 0.0f) && (enemy->m_curTriangle)) {
		transit(enemy, EBS_Living, 0);
		return;
	}

	if ((++_10 > 3) && (enemy->m_curTriangle)) {
		f32 randChance = randFloat();
		if ((enemy->m_stunAnimTimer > 0.0f)
		    || ((randChance < ((EnemyParmsBase*)enemy->m_parms)->m_general.m_purplePikminStunChance.m_value) && !(enemy->isEvent(0, EB_21))
		        && !(enemy->isEvent(0, EB_22)))) {
			transit(enemy, EBS_Fit, 0);
		} else {
			transit(enemy, EBS_Living, 0);
		}
	}

	if (enemy->isFlying()) {
		enemy->resetEvent(0, EB_3);
	}
}

/*
 * --INFO--
 * Address:	80100938
 * Size:	000064
 */
void StoneState::bounceProcedure(EnemyBase* enemy, Sys::Triangle* triangle)
{
	enemy->setEvent(0, EB_Constraint);
	enemy->createBounceEffect(enemy->m_position, enemy->getDownSmokeScale());
	enemy->addDamage(0.0f, 1.0f);
}

/*
 * --INFO--
 * Address:	8010099C
 * Size:	000100
 */
void StoneState::init(EnemyBase* enemy, StateArg* arg)
{
	if (enemy->isEvent(0, EB_21)) {
		enemy->resetEvent(0, EB_21);
	} else {
		enemy->doUpdate();
	}

	enemy->m_eventBuffer.m_flags[0] = enemy->m_events.m_flags[0];
	enemy->m_eventBuffer.m_flags[1] = enemy->m_events.m_flags[1];
	enemy->setEvent(0, EB_Bittered);
	enemy->hide();
	enemy->m_stoneTimer = 0.0f;
	enemy->stopMotion();
	enemy->m_impVelocity = 0.0f;

	if (enemy->m_curTriangle) {
		enemy->setEvent(0, EB_Constraint);
	} else {
		enemy->setEvent(0, EB_Constraint);
	}

	if (enemy->m_sfxEmotion == EMOTE_Excitement && PSGetDirectedMainBgm()) {
		enemy->m_soundObj->battleOff();
	}

	enemy->doStartStoneState();
}

/*
 * --INFO--
 * Address:	80100A9C
 * Size:	0000CC
 */
void StoneState::cleanup(EnemyBase* enemy)
{
	P2ASSERTLINE(1024, enemy->isEvent(0, EB_Bittered));

	enemy->m_events.m_flags[0] = enemy->m_eventBuffer.m_flags[0];
	enemy->m_events.m_flags[1] = enemy->m_eventBuffer.m_flags[1];
	enemy->resetEvent(0, EB_21);
	enemy->resetEvent(0, EB_Bittered);

	enemy->show();
	enemy->startMotion();
	enemy->doFinishStoneState();

	if ((enemy->m_sfxEmotion == EMOTE_Excitement) && PSGetDirectedMainBgm()) {
		enemy->m_soundObj->battleOn();
	}
}

/*
 * --INFO--
 * Address:	80100B68
 * Size:	000118
 */
void StoneState::updateAlways(EnemyBase* enemy)
{
	enemy->m_enemyStoneObj->update();
	enemy->m_stoneTimer += sys->m_deltaTime;

	if (enemy->m_enemyStoneObj->isFlag(EnemyStone::STONE_HasViewedDemo)) {
		if (!enemy->m_curTriangle) {
			enemy->constraintOff();
			enemy->resetEvent(0, EB_3);
		}
		// why.
		f32 comp = (enemy->m_stoneTimer > ((EnemyParmsBase*)enemy->m_parms)->m_general.m_stoneDuration.m_value);
		if (comp) {
			if (enemy->m_enemyStoneObj->isFlag(EnemyStone::STONE_Shake)) {
				if ((enemy->m_enemyStoneObj->isFlag(EnemyStone::STONE_Break)) && enemy->isAlive()) {
					transit(enemy, EBS_Living, nullptr);
				}
			} else {
				enemy->m_enemyStoneObj->shake();
			}
		}
	}
}

/*
 * --INFO--
 * Address:	80100C80
 * Size:	000074
 */
void StoneState::updateCullingOff(EnemyBase* enemy)
{
	if (enemy->isAlive() && enemy->isStopMotion() && (enemy->m_health <= 0.0f)) {
		enemy->kill((CreatureKillArg*)nullptr);
	}
}

/*
 * --INFO--
 * Address:	80100CF4
 * Size:	000484
 */
void StateMachine::init(EnemyBase* enemy)
{
	create(10);

	registerState(new BirthTypeDropState(EBS_Drop));
	registerState(new BirthTypeDropPikminState);
	registerState(new BirthTypeDropOlimarState);
	registerState(new BirthTypeDropTreasureState);
	registerState(new BirthTypeDropEarthquakeState);

	registerState(new AppearState);
	registerState(new LivingState);
	registerState(new StoneState);
	registerState(new EarthquakeState);
	registerState(new FitState);
}

/*
 * --INFO--
 * Address:	80101304
 * Size:	000030
 */
void StateMachine::update(EnemyBase* enemy) { m_state->update(enemy); }

/*
 * --INFO--
 * Address:	80101338
 * Size:	000030
 */
void StateMachine::entry(EnemyBase* enemy) { m_state->entry(enemy); }

/*
 * --INFO--
 * Address:	8010136C
 * Size:	000030
 */
void StateMachine::simulation(EnemyBase* enemy, f32 constraint) { m_state->simulation(enemy, constraint); }
} // namespace EnemyBaseFSM

/*
 * --INFO--
 * Address:	801013A0
 * Size:	000370
 */
EnemyBase::EnemyBase()
    : Creature()
    , SysShape::MotionListener()
    , PelletView()
    , m_position(Vector3f(0.0f))
    , m_rotation(Vector3f(0.0f))
    , m_damageAnimRotation(Vector3f(0.0f))
    , m_stunAnimRotation(Vector3f(0.0f))
    , m_events()
    , m_eventBuffer()
    , m_sfxEmotion(EMOTE_Caution)
    , m_creatureID(0xFF)
    , _1F2(0xFF)
    , m_stuckPikminCount(0)
    , m_stunAnimTimer(0.0f)
    , m_friction(0.0f)
    , m_stoneTimer(0.0f)
    , m_collEvent()
    , m_commonEffectOffset(0.0f, 0.0f, 0.0f)
    , m_enemyStoneObj(nullptr)
    , m_pelletDropCode(0)
    , m_heldPellet(nullptr)
    , m_pelletInfo()
    , m_lodParm()
    , m_waterBox(nullptr)
    , m_curWallTri(0)
    , m_soundObj(nullptr)
    , m_effectNodeHamonRoot()
    , m_existTimer(0.0f)
    , m_maxExistTime(0.0f)
    , m_dropGroup(0)
    , m_currentLifecycleState(nullptr)
    , m_lifecycleFSM(nullptr)
{
	for (int i = 0; i < 4; i++) {
		m_flags.byteView[i] = 0;
	}

	m_objectTypeID  = OBJTYPE_Teki;
	m_scaleModifier = 1.0f;
	m_collisionBuffer.alloc(this, 8);
	m_animator        = nullptr;
	m_curAnim         = new EnemyAnimKeyEvent;
	m_damageAnimTimer = 0.0f;
	m_targetCreature  = nullptr;
	m_curTriangle     = nullptr;
	m_lifecycleFSM    = new EnemyBaseFSM::StateMachine();
	m_lifecycleFSM->init(this);
	clearStick();
	m_curAnim->m_isRunning = 0;
	m_instantDamage        = 0.0f;
	resetEvent(0, EB_Damage);
	m_toFlick    = 0.0f;
	m_stoneTimer = 0.0f;

	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 4; j++) {
			m_events.m_flags[i].byteView[j] = 0;
		}
	}
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 4; j++) {
			m_eventBuffer.m_flags[i].byteView[j] = 0;
		}
	}

	if (shadowMgr) {
		shadowMgr->createShadow(this);
	}

	if (lifeGaugeMgr) {
		lifeGaugeMgr->createLifeGauge(this);
	}

	m_effectNodeHamonRoot.m_child  = nullptr;
	m_effectNodeHamonRoot.m_parent = nullptr;
	m_effectNodeHamonRoot.m_prev   = nullptr;
	m_effectNodeHamonRoot.m_next   = nullptr;
}

/*
 * --INFO--
 * Address:	80101788
 * Size:	000044
 */
void EnemyBase::constructor()
{
	m_soundObj = createPSEnemyBase();
	createInstanceEfxHamon();
}

/*
 * --INFO--
 * Address:	801017CC
 * Size:	00005C
 */
inline void EnemyBase::createEffects()
{
	EnemyEffectNodeHamon* next;
	EnemyEffectNodeHamon* hamon = (EnemyEffectNodeHamon*)m_effectNodeHamonRoot.m_child;
	while (hamon) {
		next = (EnemyEffectNodeHamon*)hamon->m_next;
		hamon->create(this);
		hamon = next;
	}
}

/*
 * --INFO--
 * Address:	80101828
 * Size:	00005C
 */
inline void EnemyBase::fadeEffects()
{
	EnemyEffectNodeHamon* next;
	EnemyEffectNodeHamon* hamon = (EnemyEffectNodeHamon*)m_effectNodeHamonRoot.m_child;
	while (hamon) {
		next = (EnemyEffectNodeHamon*)hamon->m_next;
		hamon->fade(this);
		hamon = next;
	}
}

/*
 * --INFO--
 * Address:	80101884
 * Size:	000050
 */
void EnemyBase::createInstanceEfxHamon()
{
	m_effectNodeHamon = new EnemyEffectNodeHamon;
	m_effectNodeHamonRoot.add(m_effectNodeHamon);
}

/*
 * --INFO--
 * Address:	801018D4
 * Size:	000030
 */
void EnemyBase::updateEfxHamon()
{
	if (m_effectNodeHamon) {
		m_effectNodeHamon->update(this);
	}
}

/*
 * --INFO--
 * Address:	80101904
 * Size:	00003C
 */
void EnemyBase::createEfxHamon()
{
	if (m_effectNodeHamon) {
		m_effectNodeHamon->create(this);
	}
}

/*
 * --INFO--
 * Address:	80101940
 * Size:	00003C
 */
void EnemyBase::fadeEfxHamon()
{
	if (m_effectNodeHamon) {
		m_effectNodeHamon->fade(this);
	}
}

/*
 * --INFO--
 * Address:	8010197C
 * Size:	000050
 */
void EnemyBase::setEmotionCaution()
{
	m_sfxEmotion = EMOTE_Caution;
	if (PSGetDirectedMainBgm()) {
		m_soundObj->battleOff();
	}
}

/*
 * --INFO--
 * Address:	801019CC
 * Size:	00003C
 */
void EnemyBase::setEmotionExcitement()
{
	m_sfxEmotion = EMOTE_Excitement;
	m_soundObj->battleOn();
}

/*
 * --INFO--
 * Address:	80101A08
 * Size:	000050
 */
void EnemyBase::setEmotionNone()
{
	m_sfxEmotion = EMOTE_None;
	if (PSGetDirectedMainBgm()) {
		m_soundObj->battleOff();
	}
}

/*
 * --INFO--
 * Address:	80101A58
 * Size:	000104
 */
void EnemyBase::onInit(CreatureInitArg* arg)
{
	clearStick();
	m_curAnim->m_isRunning = false;
	m_instantDamage        = 0.0f;
	resetEvent(0, EB_Damage);
	m_toFlick    = 0.0f;
	m_stoneTimer = 0.0f;

	m_events.m_flags[0].clear();
	m_events.m_flags[1].clear();
	m_eventBuffer.m_flags[0].clear();
	m_eventBuffer.m_flags[1].clear();

	setEvent(0, EB_Alive);
	setEvent(0, EB_Flying);
	setEvent(0, EB_DropMassSet);
	setEvent(0, EB_Cullable);
	setEvent(0, EB_LeaveCarcass);
	setEvent(0, EB_9);
	setEvent(0, EB_LifegaugeVisible);
	m_waterBox = nullptr;
	setEvent(0, EB_13);
	setEvent(0, EB_16);
}

/*
 * --INFO--
 * Address:	80101B5C
 * Size:	000218
 */
void EnemyBase::onInitPost(CreatureInitArg* arg)
{
	switch (m_dropGroup) {
	case 0:
		m_lifecycleFSM->start(this, EnemyBaseFSM::EBS_Living, nullptr);
		break;
	case 1:
	case 2:
	case 3:
	case 4:
	case 5:
		if (isEvent(0, EB_HardConstraint)) {
			m_lifecycleFSM->start(this, EnemyBaseFSM::EBS_Living, nullptr);
		} else {
			switch (m_dropGroup) {
			case 1:
				m_lifecycleFSM->start(this, EnemyBaseFSM::EBS_Drop, nullptr);
				break;
			case 2:
				m_lifecycleFSM->start(this, EnemyBaseFSM::EBS_DropPikmin, nullptr);
				break;
			case 3:
				m_lifecycleFSM->start(this, EnemyBaseFSM::EBS_DropOlimar, nullptr);
				break;
			case 4:
				m_lifecycleFSM->start(this, EnemyBaseFSM::EBS_DropTreasure, nullptr);
				break;
			case 5:
				m_lifecycleFSM->start(this, EnemyBaseFSM::EBS_DropEarthquake, nullptr);
				break;
			default:
				JUT_PANICLINE(1483, "Unknown birth type:%d", m_dropGroup);
				break;
			}
		}
		break;
	default:
		JUT_PANICLINE(1490, "Unknown birth type:%d", m_dropGroup);
		break;
	}

	if (gameSystem->m_mode == GSM_PIKLOPEDIA) {
		doAnimationCullingOff();

		Sys::Sphere waterSphere;
		getWaterSphere(&waterSphere);

		WaterBox* waterBox = nullptr;
		if (mapMgr) {
			waterBox = mapMgr->findWater(waterSphere);
		}
		if (waterBox) {
			m_waterBox = waterBox;
		} else {
			m_waterBox = nullptr;
		}
	}
}

/*
 * --INFO--
 * Address:	80101D74
 * Size:	0000A0
 */
void EnemyBase::setOtakaraCode(PelletMgr::OtakaraItemCode& itemCode)
{
	m_pelletDropCode.m_value = itemCode.m_value;
	if (!m_pelletDropCode.isNull()) {
		short dropCode = m_pelletDropCode.m_value;
		int dropShift  = dropCode >> 8;
		if ((u8)dropShift == 4) {
			Radar::Mgr::entry(this, Radar::MAP_UPGRADE, 0);
			return;
		}
		if (playData->isPelletEverGot(dropShift, dropCode)) {
			Radar::Mgr::entry(this, Radar::MAP_TREASURE, 0);
			return;
		}
		Radar::Mgr::entry(this, Radar::MAP_SWALLOWED_TREASURE, 0);
	}
}

void EnemyBase::forceKillEffects()
{
	if (m_heldPellet != nullptr) {
		InteractMattuan interactMatt(this, 2.5f);

		m_heldPellet->stimulate(interactMatt);
		m_heldPellet = nullptr;
	}
	m_soundObj->setKilled();
}

/*
 * --INFO--
 * Address:	80101E18
 * Size:	0000C4
 */
void EnemyBase::setCarcassArg(PelletViewArg& carcassArg)
{
	Vector3f pos           = getPosition();
	carcassArg.m_enemyName = EnemyInfoFunc::getEnemyName(getEnemyTypeID(), 0xFFFF);
	carcassArg.m_position  = pos;
	carcassArg.m_matrix    = &m_mainMatrix;
	carcassArg.m_enemy     = this;
}

void EnemyBase::becomeCarcass()
{
	if (lifeGaugeMgr != nullptr) {
		lifeGaugeMgr->inactiveLifeGauge(this);
	}

	if (shadowMgr != nullptr) {
		shadowMgr->delShadow(this);
	}

	fadeEffects();

	m_sfxEmotion = 0;

	if (PSGetDirectedMainBgm()) {
		m_soundObj->battleOff();
	}

	m_soundObj->setAnime((JAIAnimeSoundData*)NULL, 1, 0.0f, 0.0f);
	m_mgr->kill(this);
}

/*
 * --INFO--
 * Address:	80101EDC
 * Size:	000008
 */
bool EnemyBase::doBecomeCarcass() { return true; }

/*
 * --INFO--
 * Address:	80101EE4
 * Size:	000004
 */
void EnemyBase::doUpdateCarcass() { }

void EnemyBase::deathMethod()
{
	forceKillEffects();
	becomeCarcass();
}

/*
 * --INFO--
 * Address:	80101EE8
 * Size:	0009EC
 */
void EnemyBase::onKill(CreatureKillArg* inputArg)
{
	getCreatureName();
	getCreatureID();

	CreatureKillArg* killArg = nullptr; // killArg
	if (inputArg) {
		// inputArg->getName();
		if (strcmp(inputArg->getName(), "EnemyKillArg") == 0) {
			killArg = inputArg;
		}
	}

	endStick();

	if (((!killArg) || !(killArg->_04 & 0x10000000)) && (isEvent(0, EB_9))) {
		Vector3f effectPos;
		getCommonEffectPos(effectPos); // sp80, 4C
		f32 scaleMod                      = m_scaleModifier;
		EnemyTypeID::EEnemyTypeID enemyID = getEnemyTypeID();

		efx::ArgEnemyType efxArg(effectPos, enemyID, scaleMod);
		efx::TEnemyDead efxDead;

		efxDead.create((efx::Arg*)&efxArg);
		PSStartEnemyGhostSE(this, 0.0f);
	}

	if ((!killArg) || !(killArg->_04 & 0x40000000)) {
		if (isEvent(0, EB_Bittered)) {
			m_enemyStoneObj->dead();
			deathProcedure();
			resetEvent(0, EB_Bittered); // 0xFFFFFDFF
			constraintOff();
			if (ItemHoney::mgr) {
				s8 bitterDrop = (s8)EnemyInfoFunc::getEnemyInfo(getEnemyTypeID(), 0xFFFF)->m_bitterDrops;
				f32 scaledChance, dropChance;
				int dropRolls;

				switch (bitterDrop) {
				case BDT_Weak:
					dropChance = 0.99f;
					dropRolls  = 1;
					break;
				case BDT_Normal:
				case BDT_Strong:
					dropChance = 0.9f;
					dropRolls  = 1;
					break;
				case BDT_Triple:
					dropChance = 0.9f;
					dropRolls  = 3;
					break;
				case BDT_MiniBoss:
				case BDT_Boss:
					dropChance = 0.85f;
					dropRolls  = 5;
					break;
				case BDT_FinalBoss:
					dropChance = 0.0f;
					dropRolls  = 10;
					break;
				default:
					dropChance = 1.0f;
					dropRolls  = 0;
					break;
				}

				scaledChance = (0.5f * (1.0f - dropChance)) + dropChance;

				for (int i = 0; i < dropRolls; i++) {
					f32 randRoll = randFloat();
					u8 honeyKind;
					if (randRoll < dropChance) {
						honeyKind = HONEY_Y;
					} else if (randRoll < scaledChance) {
						honeyKind = HONEY_R;
					} else {
						honeyKind = HONEY_B;
					}
					Sys::Sphere ball; // sp64
					getBoundingSphere(ball);

					ItemHoney::InitArg honeyArg(honeyKind, 0);
					ItemHoney::Item* drop = static_cast<ItemHoney::Item*>(ItemHoney::mgr->birth());

					if (drop != nullptr) {
						drop->init((CreatureInitArg*)&honeyArg);
						drop->setPosition(ball.m_position, false);
						f32 theta    = TAU * randFloat(); // temp_f6
						f32 scale    = 1.0f + ((f32)dropRolls / 10.0f);
						f32 cosTheta = scale * (50.0f * pikmin2_cosf(theta));
						f32 sinTheta = scale * (50.0f * pikmin2_sinf(theta));

						Vector3f dropVelocity; // sp58
						dropVelocity.x = sinTheta;
						dropVelocity.y = 250.0f * scale;
						dropVelocity.z = cosTheta;

						drop->setVelocity(dropVelocity);
					}
				}
			}
			forceKillEffects();
			becomeCarcass();

		} else if ((0.0f == m_maxExistTime) && (isEvent(0, EB_LeaveCarcass)) && (!killArg || !(killArg->_04 & 0x20000000))) {
			if (!m_pellet) {
				PelletViewArg pvArg;
				setCarcassArg(pvArg);
				if (!becomePellet(&pvArg)) {
					deathMethod();

				} else {
					lifeGaugeMgr->inactiveLifeGauge(this);
					m_sfxEmotion = 0;
					if (PSGetDirectedMainBgm()) {
						m_soundObj->battleOff();
					}
					doBecomeCarcass();
				}
			}
			forceKillEffects();

		} else {
			forceKillEffects();
			becomeCarcass();
		}
		setZukanVisible(true);
		return;
	}
	if (isEvent(0, EB_Bittered)) {
		m_enemyStoneObj->dead();
	}
	forceKillEffects();
	becomeCarcass();
}

/*
 * --INFO--
 * Address:	80102920
 * Size:	0000E0
 */
void EnemyBase::setZukanVisible(bool arg)
{
	if (m_inPiklopedia) {
		if (!(gameSystem->m_flags & 0x10)) {
			EnemyInfo* enemyInfo = EnemyInfoFunc::getEnemyInfo(getEnemyTypeID(), 0xFFFF);
			if (!(enemyInfo->m_flags & 0x200)) {
				TekiStat::Info* tekiInfo = playData->m_tekiStatMgr.getTekiInfo(getEnemyTypeID());
				P2ASSERTLINE(1859, tekiInfo);
				if (arg) {
					tekiInfo->incKilled();
				} else {
					tekiInfo->m_state |= TEKISTAT_STATE_UPDATED;
				}
			}
		}
	}
}

/*
 * --INFO--
 * Address:	80102A00
 * Size:	000160
 */
void EnemyBase::birth(Vector3f& pos, f32 faceDir)
{
	setEvent(0, EB_Alive);
	m_inPiklopedia = true;
	setPosition(pos, false);
	m_homePosition.x   = pos.x;
	m_homePosition.y   = pos.y;
	m_homePosition.z   = pos.z;
	m_rotation         = Vector3f(0.0f);
	m_impVelocity      = Vector3f(0.0f);
	m_simVelocity      = Vector3f(0.0f);
	m_targetCreature   = nullptr;
	m_faceDir          = faceDir;
	m_rotation.y       = m_faceDir;
	m_curTriangle      = nullptr;
	m_stuckPikminCount = 0;
	m_heldPellet       = nullptr;
	m_model->m_j3dModel->calc();
	m_collTree->update();
	updateSpheres();
	resetCollEvent();
	_1F2 = 0xFF;
	setParameters();
	shadowMgr->addShadow(this);
	if (lifeGaugeMgr) {
		lifeGaugeMgr->activeLifeGauge(this, 1.0f);
	}
	m_model->hide();
	m_sfxEmotion    = EMOTE_Caution;
	m_maxExistTime  = 0.0f;
	m_existTimer    = 0.0f;
	m_stunAnimTimer = 0.0f;
}

/*
 * --INFO--
 * Address:	80102B60
 * Size:	000078
 */
void EnemyBase::updateTrMatrix()
{
	Vector3f rot = m_rotation + m_damageAnimRotation + m_stunAnimRotation;
	m_mainMatrix.makeTR(m_position, rot);
}

/*
 * --INFO--
 * Address:	80102BD8
 * Size:	000078
 */
void EnemyBase::setParameters()
{
	m_health    = static_cast<EnemyParmsBase*>(m_parms)->m_general.m_health.m_value;
	m_maxHealth = static_cast<EnemyParmsBase*>(m_parms)->m_general.m_health.m_value;
	m_mass      = static_cast<EnemyParmsBase*>(m_parms)->m_general.m_fp05.m_value;
	m_friction  = m_mass;
	Sys::Sphere sphere;
	m_collTree->m_part->getSphere(sphere);
	m_boundingSphere.m_radius = sphere.m_radius;
	m_curLodSphere.m_radius   = static_cast<EnemyParmsBase*>(m_parms)->m_general.m_offCameraRadius.m_value;
}

/*
 * --INFO--
 * Address:	80102C50
 * Size:	000034
 */
void EnemyBase::update() { static_cast<EnemyBaseFSM::StateMachine*>(m_lifecycleFSM)->update(this); }

/*
 * --INFO--
 * Address:	80102C84
 * Size:	0001E0
 */
bool EnemyBase::isFinishableWaitingBirthTypeDrop()
{
	Sys::Sphere sphere(m_position, static_cast<EnemyParmsBase*>(m_parms)->m_general.m_privateRadius.m_value);
	bool result = false;

	CellIteratorArg cellIteratorArg(sphere);
	CellIterator cellIterator(cellIteratorArg);
	cellIterator.first();
	while (cellIterator.isDone() == false) {
		Creature* cell = (Creature*)*cellIterator;
		if (cell->isAlive()) {
			if (cell->isNavi() || (cell->isPiki() && static_cast<Piki*>(cell)->isPikmin())) {
				f32 privateRadius = static_cast<EnemyParmsBase*>(m_parms)->m_general.m_privateRadius.m_value;

				Vector2f delta;
				getDistanceTo(cell, delta);

				if ((SQUARE(delta.x) + SQUARE(delta.y)) < SQUARE(privateRadius)) {
					result = true;
				}
			}
		}
		cellIterator.next();
	}
	return result;
}

/*
 * --INFO--
 * Address:	80102E64
 * Size:	000090
 */
void EnemyBase::startStoneState()
{
	if (!(isEvent(0, EB_BitterImmune)) && !((isEvent(0, EB_Bittered)))) {
		if (isEvent(0, EB_22)) {
			setEvent(0, EB_21);
			return;
		}
		if (m_enemyStoneObj->start()) {
			m_lifecycleFSM->transit(this, EnemyBaseFSM::EBS_Stone, 0);
		} else {
			setEvent(0, EB_21);
		}
	}
}

/*
 * --INFO--
 * Address:	80102EF4
 * Size:	000014
 */
void EnemyBase::doStartStoneState()
{
	m_simVelocity.x = 0.0f;
	m_simVelocity.y = 0.0f;
	m_simVelocity.z = 0.0f;
}

/*
 * --INFO--
 * Address:	80102F08
 * Size:	000004
 */
void EnemyBase::doFinishStoneState() { }

void EnemyBase::updateEffects()
{
	WalkSmokeEffect::Mgr* smokeMgr = getWalkSmokeEffectMgr();
	if (smokeMgr) {
		smokeMgr->update(this);
	}
}

/*
 * --INFO--
 * Address:	80102F14
 * Size:	000080
 */
void EnemyBase::doUpdateCommon()
{
	scaleDamageAnim();
	resetCollEvent();

	if ((m_lod.m_flags & AILOD_FLAG_NEED_SHADOW) && isAlive()) {
		updateEffects();
	}
}

/*
 * --INFO--
 * Address:	80102F94
 * Size:	000034
 */
void EnemyBase::doAnimation() { static_cast<EnemyBaseFSM::StateMachine*>(m_lifecycleFSM)->animation(this); }

/*
 * --INFO--
 * Address:	80102FF8
 * Size:	000088
 */
void EnemyBase::doAnimationUpdateAnimator()
{
	m_animator->animate(m_animator->m_animSpeed * sys->m_deltaTime);

	SysShape::Animator* animator = &m_animator->getAnimator();
	SysShape::Model* model       = m_model;
	J3DMtxCalc* calc             = static_cast<SysShape::BaseAnimator*>(animator)->getCalc();

	model->m_j3dModel->m_modelData->m_jointTree.m_joints[0]->m_mtxCalc = static_cast<J3DMtxCalcAnmBase*>(calc);
}

/*
 * --INFO--
 * Address:	80103080
 * Size:	0001E0
 */
void EnemyBase::doAnimationCullingOff()
{
	m_curAnim->m_isRunning = false;
	doAnimationUpdateAnimator();

	if (m_pellet) {
		viewMakeMatrix(m_mainMatrix);
		Matrixf mtx;
		PSMTXScale(mtx.m_matrix.mtxView, m_scale.x, m_scale.y, m_scale.z);
		PSMTXConcat(m_mainMatrix.m_matrix.mtxView, mtx.m_matrix.mtxView, m_mainMatrix.m_matrix.mtxView);

		Vector3f pos;
		pos.x = m_mainMatrix.m_matrix.structView.tx;
		pos.y = m_mainMatrix.m_matrix.structView.ty;
		pos.z = m_mainMatrix.m_matrix.structView.tz;
		onSetPosition(pos);
		onSetPositionPost(pos);
	} else {
		if (isStickTo()) {
			doAnimationStick();
		} else {
			Vector3f rot = m_rotation + m_damageAnimRotation + m_stunAnimRotation;
			m_mainMatrix.makeSRT(m_scale, rot, m_position);
		}
	}

	sys->m_timers->_start("e-calc", true);
	PSMTXCopy(m_mainMatrix.m_matrix.mtxView, m_model->m_j3dModel->m_posMtx);
	m_model->m_j3dModel->calc();
	sys->m_timers->_stop("e-calc");
	m_collTree->update();

	if (m_animator->getAnimator().m_flags & 1) {
		static_cast<PSM::CreatureAnime*>(m_soundObj)->setAnime(nullptr, 1, 0.0f, 0.0f);
	}
}

/*
 * --INFO--
 * Address:	8010329C
 * Size:	00007C
 */
void EnemyBase::doAnimationStick()
{
	Vector3f rot = m_rotation + m_damageAnimRotation + m_stunAnimRotation;
	m_mainMatrix.makeSRT(m_scale, rot, m_position);
}

/*
 * --INFO--
 * Address:
 * Size:	000020
 */
void EnemyBase::doAnimationCullingOn() { m_model->m_j3dModel->m_modelData->m_jointTree.m_joints[0]->m_mtxCalc = 0; }

/*
 * --INFO--
 * Address:	80103338
 * Size:	00007C
 */
void EnemyBase::show()
{
	if (isEvent(0, EB_Bittered)) {
		if (m_enemyStoneObj->isFlag(EnemyStone::STONE_Fit)) {
			m_model->hide();
		} else {
			m_model->show();
		}
	} else {
		m_model->show();
	}
}

/*
 * --INFO--
 * Address:	801033B4
 * Size:	000054
 */
void EnemyBase::hide()
{
	if ((isEvent(0, EB_Bittered))) {
		m_model->hide();
	} else {
		m_model->hide();
	}
}

/*
 * --INFO--
 * Address:	80103408
 * Size:	000108
 */
void EnemyBase::doEntryCarcass()
{
	if (m_lod.m_flags & AILOD_FLAG_NEED_SHADOW) {
		show();
		changeMaterial();
	} else {
		hide();
	}

	if (!(isEvent(0, EB_31))) {
		m_model->m_j3dModel->entry();
	}
}

/*
 * --INFO--
 * Address:	80103510
 * Size:	00013C
 */
void EnemyBase::doEntryLiving()
{
	if (m_lod.m_flags & AILOD_FLAG_NEED_SHADOW) {
		show();
		changeMaterial();
	} else {
		if (BaseHIOParms::sEntryOpt != false) {
			if (!gameSystem->isMultiplayerMode())
				return;
		}

		hide();
	}

	if (!(isEvent(0, EB_31))) {
		m_model->m_j3dModel->entry();
	}
}

/*
 * --INFO--
 * Address:	8010364C
 * Size:	000034
 */
void EnemyBase::doEntry() { m_lifecycleFSM->entry(this); }

/*
 * --INFO--
 * Address:	80103680
 * Size:	000028
 */
void EnemyBase::doSetView(int viewNo) { m_model->setCurrentViewNo((u16)viewNo); }

/*
 * --INFO--
 * Address:	801036A8
 * Size:	000054
 */
bool EnemyBase::isCullingOff()
{
	if (m_pellet) {
		return true;
	}
	return ((!(isEvent(0, EB_Cullable))) || (m_lod.m_flags & AILOD_FLAG_NEED_SHADOW) || (m_lod.m_flags & AILOD_FLAG_UNKNOWN4)
	        || (isEvent(1, EB2_5)));
}

/*
 * --INFO--
 * Address:	801036FC
 * Size:	000078
 */
void EnemyBase::doViewCalc()
{
	if (isCullingOff()) {
		m_model->viewCalc();
	}
}

/*
 * --INFO--
 * Address:	80103774
 * Size:	0000AC
 */
void EnemyBase::doSimulationGround(f32 accelRate)
{
	Vector3f groundDiff;
	groundDiff.x = m_simVelocity.x;
	groundDiff.y = m_impVelocity.y;
	groundDiff.z = m_simVelocity.z;

	Vector3f diff = groundDiff - m_impVelocity;

	diff          = diff * getAccelerationScale(accelRate);
	m_impVelocity = m_impVelocity + diff;

	if (checkSecondary()) {
		m_impVelocity.y = -((3.0f * (accelRate * _aiConstants->m_gravity.m_data)) - m_impVelocity.y);
		return;
	}

	m_impVelocity.y = -((accelRate * _aiConstants->m_gravity.m_data) - m_impVelocity.y);
}

/*
 * --INFO--
 * Address:	80103820
 * Size:	000058
 */
void EnemyBase::doSimulationFlying(f32 accelRate)
{
	Vector3f diff = m_simVelocity - m_impVelocity;
	diff          = diff * getAccelerationScale(accelRate);
	m_impVelocity = m_impVelocity + diff;
}

/*
 * --INFO--
 * Address:	80103878
 * Size:	000058
 */
void EnemyBase::doSimulationStick(f32 accelRate)
{
	Vector3f diff = m_simVelocity - m_impVelocity;
	diff          = diff * getAccelerationScale(accelRate);
	m_impVelocity = m_impVelocity + diff;
}

/*
 * --INFO--
 * Address:	801038D0
 * Size:	000070
 */
inline void EnemyBase::updateSpheres()
{
	Sys::Sphere sphere;
	m_collTree->m_part->getSphere(sphere);

	m_boundingSphere          = sphere;
	m_curLodSphere.m_position = m_boundingSphere.m_position;
}

/*
 * --INFO--
 * Address:	80103940
 * Size:	0000B8
 */
void EnemyBase::createDropEffect(const Vector3f& position, f32 scale)
{
	efx::Arg enemyArg(position);
	efx::TEnemyDownSmoke downSmoke;
	downSmoke._0C = scale;
	downSmoke.create(&enemyArg);

	PSStartEnemyDownSmokeSE(this, scale);
}

/*
 * --INFO--
 * Address:	801039F8
 * Size:	000158
 */
void EnemyBase::createSplashDownEffect(const Vector3f& position, f32 scale)
{
	Vector3f effectPosition;
	if (m_waterBox) {
		effectPosition = Vector3f(position.x, *m_waterBox->getSeaHeightPtr(), position.z);
	} else {
		effectPosition = position;
	}

	efx::ArgScale scaleArg(effectPosition, scale);
	efx::TEnemyDownWat waterEffects;

	waterEffects.create(&scaleArg);
	PSStartEnemyDownWatSE(this, scale);
}

/*
 * --INFO--
 * Address:	80103B50
 * Size:	0001DC
 */
void EnemyBase::createBounceEffect(const Vector3f& position, f32 scale)
{
	if (m_waterBox) {
		createSplashDownEffect(position, scale);
	} else {
		createDropEffect(position, scale);
	}
}

/*
 * --INFO--
 * Address:	80103D2C
 * Size:	000168
 */
void EnemyBase::outWaterCallback()
{
	f32 downSmokeScale = getDownSmokeScale();
	if (downSmokeScale > 0.0f) {
		createSplashDownEffect(m_position, downSmokeScale);
	}
}

/*
 * --INFO--
 * Address:	80103E94
 * Size:	000168
 */
void EnemyBase::inWaterCallback(WaterBox* water)
{
	f32 downSmokeScale = getDownSmokeScale();
	if (downSmokeScale > 0.0f) {
		createSplashDownEffect(m_position, downSmokeScale);
	}
}

/*
 * --INFO--
 * Address:	80103FFC
 * Size:	00028C
 */
void EnemyBase::finishDropping(bool heightCheck)
{
	if (isEvent(1, EB2_5)) {
		addDamage(0.0f, 1.0f);
		setEvent(0, EB_20);
		Sys::Sphere ball;
		getBoundingSphere(ball);        // sp4C
		Vector3f pos = ball.m_position; // sp40

		if (heightCheck) {
			if (mapMgr) {
				pos.y = mapMgr->getMinY(pos);
			}
		}

		createBounceEffect(pos, getDownSmokeScale());

		resetEvent(1, EB2_5);
		m_impVelocity = 0.0f;
	}
}

/*
 * --INFO--
 * Address:	80104288
 * Size:	000080
 */
void EnemyBase::bounceProcedure(Sys::Triangle* triangle)
{
	bounceCallback(triangle);
	resetEvent(0, EB_30);

	finishDropping(true);
	resetDroppingMassZero();

	m_lifecycleFSM->bounceProcedure(this, triangle);
}

/*
 * --INFO--
 * Address:	80104340
 * Size:	0006D4
 */
void EnemyBase::collisionMapAndPlat(f32 accelRate)
{
	if (!isStickTo()) {
		if (!(isEvent(0, EB_3))) {
			doSimulationGround(accelRate);
		} else {
			doSimulationFlying(accelRate);
			resetEvent(0, EB_30);
		}

		f32 yOffsetFromMap = static_cast<EnemyParmsBase*>(m_parms)->m_general.m_fp01.m_value;

		Vector3f pos         = getPosition();
		m_commonEffectOffset = getOffsetForMapCollision();

		Sys::Sphere sphere;
		pos += m_commonEffectOffset;
		pos.y += yOffsetFromMap;
		sphere.m_position = pos;
		sphere.m_radius   = yOffsetFromMap;

		f32 z = checkSecondary() ? 0.0f : static_cast<CreatureProperty*>(m_parms)->m_props.m_wallReflection.m_value;

		m_acceleration.y = 0.0f;

		Vector3f velocityDest = m_impVelocity + m_acceleration;
		MoveInfo moveInfo(&sphere, &velocityDest, z);
		moveInfo.m_infoOrigin = (BaseItem*)this;

		mapMgr->traceMove(moveInfo, accelRate);

		m_impVelocity = velocityDest;

		f32 velocityNorm  = m_impVelocity.normalise();
		f32 collTriNormal = m_acceleration.length();

		if ((velocityNorm > collTriNormal)) {
			velocityNorm -= collTriNormal;
			m_impVelocity *= velocityNorm;
			m_acceleration = 0.0f;
		} else {
			m_impVelocity *= velocityNorm;
			m_acceleration = 0.0f;
		}

		if (!m_curTriangle && moveInfo.m_curTriangle) {
			bounceProcedure(moveInfo.m_curTriangle);
		}
		m_curTriangle = moveInfo.m_curTriangle;

		m_collisionPosition = moveInfo.m_position;

		if (!m_curWallTri && moveInfo.m_curWallTri) {
			wallCallback(moveInfo);
		}
		m_curWallTri = moveInfo.m_curWallTri;

		if (platMgr && isEvent(0, EB_13)) {
			moveInfo.m_velocity = &m_impVelocity;
			platMgr->traceMove(moveInfo, accelRate);

			if (!m_curTriangle) {
				if (moveInfo.m_curTriangle) {
					bounceProcedure(moveInfo.m_curTriangle);
				}
				m_curTriangle = moveInfo.m_curTriangle;

				m_collisionPosition = moveInfo.m_position;
			}

			if (!m_curWallTri && moveInfo.m_curWallTri) {
				wallCallback(moveInfo);
			}
			m_curWallTri = moveInfo.m_curWallTri;
		}

		if (mapMgr->hasHiddenCollision()) {
			mapMgr->constraintBoundBox(sphere);
		}

		m_position.x = sphere.m_position.x - m_commonEffectOffset.x;
		m_position.y = sphere.m_position.y - m_commonEffectOffset.y - yOffsetFromMap;
		m_position.z = sphere.m_position.z - m_commonEffectOffset.z;

		updateSpheres();
	} else {
		m_acceleration = 0.0f;

		doSimulationStick(accelRate);

		m_position += m_impVelocity;

		Vector3f stick(pikmin2_sinf(m_faceDir), 0.0f, pikmin2_cosf(m_faceDir));
		updateStick(stick);
		updateSpheres();
		updateCell();
	}
}

/*
 * --INFO--
 * Address:	80104A38
 * Size:	000020
 */
void EnemyBase::doSimulationCarcass(f32 _) { updateWaterBox(); }

/*
 * --INFO--
 * Address:	80104A58
 * Size:	000034
 */
void EnemyBase::doSimulation(f32 arg) { static_cast<EnemyBaseFSM::StateMachine*>(m_lifecycleFSM)->simulation(this, arg); }

/*
 * --INFO--
 * Address:	80104A8C
 * Size:	0000D8
 */
void EnemyBase::doSimulationConstraint(f32 arg)
{
	if (!(isEvent(0, EB_HardConstraint))) {
		if (m_acceleration.x != 0.0f || m_acceleration.z != 0.0f) {
			setEvent(0, EB_30);
		} else if (m_curTriangle) {
			resetEvent(0, EB_30);
		}
		if (isEvent(0, EB_30)) {
			collisionMapAndPlat(arg);
		}
	}

	updateSpheres();
	updateWaterBox();
}

/*
 * --INFO--
 * Address:	80104B64
 * Size:	000070
 */
void EnemyBase::gotoHell()
{
	if (isEvent(0, EB_Alive)) {
		throwupItem();
		EnemyKillArg killArg(0x70000000);
		kill(&killArg);
	}
}

/*
 * --INFO--
 * Address:	80104BD4
 * Size:	000030
 */
void EnemyBase::setAnimMgr(SysShape::AnimMgr* mgr) { m_animator->setAnimMgr(mgr); }

/*
 * --INFO--
 * Address:	80104C04
 * Size:	0001B4
 */
void EnemyBase::setPSEnemyBaseAnime()
{
	if (isEvent(0, EB_PS1)) {
		int idx = getCurrAnimIndex();
		SysShape::AnimInfo* info
		    = static_cast<SysShape::AnimInfo*>(m_animator->getAnimator(0).m_animMgr->m_animInfo.m_child)->getInfoByID(idx);
		JAIAnimeFrameSoundData* file = info->m_basFile;

		if (file) {
			SysShape::KeyEvent* event1 = info->getAnimKeyByType(0);
			SysShape::KeyEvent* event2 = info->getAnimKeyByType(1);

			if (event1 && event2) {
				f32 val1 = (f32)event1->m_frame;
				f32 val2 = (f32)event2->m_frame;
				m_soundObj->setAnime((JAIAnimeSoundData*)file, 1, val1, val2);
				return;
			}

			m_soundObj->setAnime((JAIAnimeSoundData*)file, 1, 0.0f, 0.0f);
			return;
		}

		m_soundObj->setAnime(nullptr, 1, 0.0f, 0.0f);
		return;
	}

	if (isEvent(0, EB_PS2)) {
		m_soundObj->setAnime((JAIAnimeSoundData*)-1, 1, 0.0f, 0.0f);
		return;
	}

	if (isEvent(0, EB_PS3)) {
		m_soundObj->setAnime((JAIAnimeSoundData*)-1, 1, 0.0f, 0.0f);
		return;
	}

	m_soundObj->setAnime(nullptr, 1, 0.0f, 0.0f);
}

/*
 * --INFO--
 * Address:	80104DB8
 * Size:	0001F0
 */
void EnemyBase::startBlend(int start, int end, SysShape::BlendFunction* blendFunc, f32 framerate, SysShape::MotionListener* inputListener)
{
	SysShape::MotionListener* listener = inputListener;
	if (!listener) {
		listener = static_cast<SysShape::MotionListener*>(this);
	}

	static_cast<EnemyBlendAnimatorBase*>(m_animator)->startBlend(start, end, blendFunc, framerate, listener);

	resetEvent(0, EB_PS1 + EB_PS2 + EB_PS3 + EB_PS4);
	setEvent(0, EB_PS3);

	if (isEvent(0, EB_PS1)) {
		int idx = getCurrAnimIndex();
		SysShape::AnimInfo* info
		    = static_cast<SysShape::AnimInfo*>(m_animator->getAnimator(0).m_animMgr->m_animInfo.m_child)->getInfoByID(idx);
		JAIAnimeFrameSoundData* file = info->m_basFile;

		if (file) {
			SysShape::KeyEvent* event1 = info->getAnimKeyByType(0);
			SysShape::KeyEvent* event2 = info->getAnimKeyByType(1);

			if (event1 && event2) {
				f32 val1 = (f32)event1->m_frame;
				f32 val2 = (f32)event2->m_frame;
				m_soundObj->setAnime((JAIAnimeSoundData*)file, 1, val1, val2);
				return;
			}

			m_soundObj->setAnime((JAIAnimeSoundData*)file, 1, 0.0f, 0.0f);
			return;
		}

		m_soundObj->setAnime(nullptr, 1, 0.0f, 0.0f);
		return;
	}

	if (isEvent(0, EB_PS2)) {
		m_soundObj->setAnime((JAIAnimeSoundData*)-1, 1, 0.0f, 0.0f);
		return;
	}

	if (isEvent(0, EB_PS3)) {
		m_soundObj->setAnime((JAIAnimeSoundData*)-1, 1, 0.0f, 0.0f);
		return;
	}

	m_soundObj->setAnime(nullptr, 1, 0.0f, 0.0f);
}

/*
 * --INFO--
 * Address:	80104FA8
 * Size:	000050
 */
void EnemyBase::endBlend()
{
	if (m_animator->getTypeID() == 'blnd') {
		static_cast<EnemyBlendAnimatorBase*>(m_animator)->endBlend();
	}
}

/*
 * --INFO--
 * Address:	80105004
 * Size:	000224
 */
void EnemyBase::startMotion(int p1, SysShape::MotionListener* inputListener)
{
	SysShape::MotionListener* listener;
	if (!(listener = inputListener)) {
		inputListener = static_cast<SysShape::MotionListener*>(this);
	}

	EnemyAnimatorBase* animator = m_animator;
	animator->m_flags.typeView &= ~0x3;
	animator->m_progress = 1.0f;

	(animator->getAnimator(0)).startAnim(p1, inputListener);

	resetEvent(0, EB_PS1 + EB_PS2 + EB_PS3 + EB_PS4);
	setEvent(0, EB_PS1);

	if (isEvent(0, EB_PS1)) {
		int idx = getCurrAnimIndex();
		SysShape::AnimInfo* info
		    = static_cast<SysShape::AnimInfo*>(m_animator->getAnimator(0).m_animMgr->m_animInfo.m_child)->getInfoByID(idx);
		JAIAnimeFrameSoundData* file = info->m_basFile;

		if (file) {
			SysShape::KeyEvent* event1 = info->getAnimKeyByType(0);
			SysShape::KeyEvent* event2 = info->getAnimKeyByType(1);

			if (event1 && event2) {
				f32 val1 = (f32)event1->m_frame;
				f32 val2 = (f32)event2->m_frame;
				m_soundObj->setAnime((JAIAnimeSoundData*)file, 1, val1, val2);
				return;
			}

			m_soundObj->setAnime((JAIAnimeSoundData*)file, 1, 0.0f, 0.0f);
			return;
		}

		m_soundObj->setAnime(nullptr, 1, 0.0f, 0.0f);
		return;
	}

	if (isEvent(0, EB_PS2)) {
		m_soundObj->setAnime((JAIAnimeSoundData*)-1, 1, 0.0f, 0.0f);
		return;
	}

	if (isEvent(0, EB_PS3)) {
		m_soundObj->setAnime((JAIAnimeSoundData*)-1, 1, 0.0f, 0.0f);
		return;
	}

	m_soundObj->setAnime(nullptr, 1, 0.0f, 0.0f);
}

/*
 * --INFO--
 * Address:	80105228
 * Size:	000044
 */
void EnemyBase::setMotionFrame(f32 frame) { m_animator->getAnimator().setCurrFrame(frame); }

/*
 * --INFO--
 * Address:	8010526C
 * Size:	000034
 */
f32 EnemyBase::getMotionFrame() { return m_animator->getAnimator().m_timer; }

/*
 * --INFO--
 * Address:	801052A0
 * Size:	000040
 */
void EnemyBase::finishMotion() { m_animator->getAnimator(0).m_flags |= 2; }

/*
 * --INFO--
 * Address:	801052E0
 * Size:	000020
 */
void EnemyBase::onKeyEvent(const SysShape::KeyEvent& event)
{
	EnemyAnimKeyEvent* animKeyEvent = m_curAnim;
	animKeyEvent->m_frame           = event.m_frame;
	animKeyEvent->m_type            = event.m_type;
	animKeyEvent->m_isRunning       = true;
}

/*
 * --INFO--
 * Address:	80105300
 * Size:	000080
 */
bool EnemyBase::stimulate(Interaction& interaction)
{
	bool b = false;
	if (interaction.actCommon(this)) {
		b = interaction.actEnemy(this);
	}
	return b;
}

/*
 * --INFO--
 * Address:	80105390
 * Size:	000030
 */
void EnemyBase::lifeRecover()
{
	m_health += m_maxHealth * static_cast<EnemyParmsBase*>(m_parms)->m_general.m_regenerationRate.m_value;
	if (m_health > m_maxHealth) {
		m_health = m_maxHealth;
	}
}

/*
 * --INFO--
 * Address:	801053C0
 * Size:	00033C
 */
void EnemyBase::scaleDamageAnim()
{
	if (isEvent(0, EB_Flying) || m_damageAnimTimer != 0.0f) {
		if (m_damageAnimTimer == 0.0f) {
			if (isEvent(0, EB_Damage)) {
				m_damageAnimTimer += sys->m_deltaTime;
			}

		} else {
			f32 horizontalModifier = 0.0f;
			f32 scaleDuration      = static_cast<EnemyParmsBase*>(m_parms)->m_general.m_damageScaleDuration.m_value;
			f32 factor;

			if (isEvent(0, EB_20)) {
				factor = 2.5f;
			} else {
				factor = 1.0f;
			}

			if (isEvent(0, EB_15)) {
				m_damageAnimTimer += 0.5f * sys->m_deltaTime;
			} else {
				m_damageAnimTimer += sys->m_deltaTime;
			}

			if (isEvent(0, EB_Bittered)) {

				if (m_damageAnimTimer > scaleDuration) {
					finishScaleDamageAnim();
				} else {
					horizontalModifier = 1.0f - getDamageAnimFrac(scaleDuration);
				}
				f32 sin1               = scaledSin(horizontalModifier);
				sin1                   = (FULLDEG2RAD)*factor * sin1;
				m_damageAnimRotation.x = horizontalModifier * sin1;

				m_damageAnimRotation.y = 0.0f;

				f32 t             = 2.0f * horizontalModifier * TAU;
				f32 sin2          = altSin(t);
				f32 anotherFactor = (TAU / 144.0f) * factor;
				anotherFactor *= sin2;
				m_damageAnimRotation.z = horizontalModifier * anotherFactor;

				f32 scaleVal = m_scaleModifier;
				m_scale.z    = scaleVal;
				m_scale.y    = scaleVal;
				m_scale.x    = scaleVal;
				return;
			}

			if (m_damageAnimTimer > scaleDuration) {
				finishScaleDamageAnim();
			} else {
				f32 s              = scaledSin(getDamageAnimFrac(scaleDuration));
				f32 t              = (1.0f - getDamageAnimFrac(scaleDuration));
				horizontalModifier = t * s;
			}

			if (isEvent(0, EB_15)) {
				horizontalModifier *= 2.0f;
			}

			f32 xzScale = horizontalModifier * (factor * static_cast<EnemyParmsBase*>(m_parms)->m_general.m_horizontalDamageScale.m_value);
			if (isEvent(0, EB_20)) {
				m_scale.x = m_scaleModifier + xzScale;
				m_scale.y = -((horizontalModifier * static_cast<EnemyParmsBase*>(m_parms)->m_general.m_verticalDamageScale.m_value)
				              - m_scaleModifier);
				m_scale.z = m_scaleModifier + xzScale;
				return;
			}

			m_scale.x = m_scaleModifier - xzScale;
			m_scale.y
			    = (horizontalModifier * static_cast<EnemyParmsBase*>(m_parms)->m_general.m_verticalDamageScale.m_value) + m_scaleModifier;
			m_scale.z = m_scaleModifier - xzScale;
		}
	}
}

/*
 * --INFO--
 * Address:	801056FC
 * Size:	000024
 */
void EnemyBase::finishScaleDamageAnim()
{
	m_damageAnimTimer = 0.0f;
	resetEvent(0, EB_15);
	resetEvent(0, EB_20);
}

/*
 * --INFO--
 * Address:	80105720
 * Size:	0000F8
 */
void EnemyBase::deathProcedure()
{
	resetEvent(0, EB_Flying);
	setAlive(false);

	if (isEvent(0, EB_Bittered)) {
		throwupItem();
	} else {
		throwupItemInDeathProcedure();
	}
	startMotion();

	if (isEvent(0, EB_9)) {
		createDeadBombEffect();
		PSStartEnemyFatalHitSE(this, 0.0f);
	}

	PSM::EnemyBase* soundObj = m_soundObj;
	if ((soundObj->getCastType() == PSM::CCT_EnemyMidBoss) || (soundObj->getCastType() == PSM::CCT_EnemyBigBoss)) {
		static_cast<PSM::EnemyBoss*>(soundObj)->onDeathMotionTop();
	}
}

/*
 * --INFO--
 * Address:	80105874
 * Size:	0000D8
 */
void EnemyBase::createDeadBombEffect()
{
	Vector3f effectPos;
	getCommonEffectPos(effectPos);
	f32 scale                    = m_scaleModifier;
	EnemyTypeID::EEnemyTypeID id = getEnemyTypeID();
	efx::ArgEnemyType effectArg(effectPos, id, scale);
	efx::TEnemyBomb bombEffect;
	bombEffect.create(&effectArg);
}

/*
 * --INFO--
 * Address:	8010594C
 * Size:	000054
 */
void EnemyBase::getThrowupItemPosition(Vector3f* throwupItemPosition)
{
	Sys::Sphere sphere;
	getBoundingSphere(sphere);
	*throwupItemPosition = sphere.m_position;
}

/*
 * --INFO--
 * Address:	801059A0
 * Size:	000018
 */
void EnemyBase::getThrowupItemVelocity(Vector3f* throwupItemVelocity)
{
	throwupItemVelocity->x = 0.0f;
	throwupItemVelocity->y = 200.0f;
	throwupItemVelocity->z = 0.0f;
}

/*
 * --INFO--
 * Address:	801059B8
 * Size:	0004B0
 */
void EnemyBase::throwupItem()
{
	Vector3f throwupPosition;
	getThrowupItemPosition(&throwupPosition);

	PelletInitArg pelletInitArg;

	if (pelletMgr->makePelletInitArg(pelletInitArg, m_pelletDropCode)) {
		pelletInitArg._14            = 2;
		EnemyTypeID::EEnemyTypeID id = getEnemyTypeID();

		if ((id == EnemyTypeID::EnemyID_Queen || id == EnemyTypeID::EnemyID_SnakeCrow || id == EnemyTypeID::EnemyID_KingChappy
		     || id == EnemyTypeID::EnemyID_Damagumo || id == EnemyTypeID::EnemyID_OoPanModoki || id == EnemyTypeID::EnemyID_Houdai
		     || id == EnemyTypeID::EnemyID_UmiMushiBlind || id == EnemyTypeID::EnemyID_BlackMan || id == EnemyTypeID::EnemyID_DangoMushi
		     || id == EnemyTypeID::EnemyID_BigFoot || id == EnemyTypeID::EnemyID_SnakeWhole || id == EnemyTypeID::EnemyID_UmiMushi
		     || id == EnemyTypeID::EnemyID_BigTreasure)
		    && gameSystem && gameSystem->m_mode == GSM_STORY_MODE && gameSystem->m_inCave && Cave::randMapMgr
		    && Cave::randMapMgr->isLastFloor()) {
			pelletInitArg._1D = true;
		}

		if (Pellet::sFromTekiEnable) {
			pelletInitArg._1F = true;
		}

		m_heldPellet = pelletMgr->birth(&pelletInitArg);

		if (m_heldPellet) {
			InteractMattuan mattuan = InteractMattuan(this, 8.0f);
			m_heldPellet->stimulate(mattuan);

			Vector3f throwupVelocity;
			getThrowupItemVelocity(&throwupVelocity);

			m_heldPellet->setPosition(throwupPosition, false);
			m_heldPellet->setVelocity(throwupVelocity);
			m_heldPellet->createKiraEffect(throwupPosition);

			Radar::Mgr::exit(this);
			m_soundObj->startSound(PSSE_EN_ENEMY_LOOSE_ITEM, 0);
		}
	}

	if (randFloat() < m_pelletInfo.m_spawnChance) {
		f32 range = (m_pelletInfo.m_maxPellets - m_pelletInfo.m_minPellets) * randFloat();
		f32 roundRange;
		if (range >= 0.0f) {
			roundRange = range + 0.5f;
		} else {
			roundRange = range - 0.5f;
		}
		int additionalPellets = m_pelletInfo.m_minPellets + (int)roundRange;

		f32 velocity = 0.0f;
		switch (m_pelletInfo.m_size) {
		case PELLET_NUMBER_ONE:
			velocity = 150.0f;
			break;
		case PELLET_NUMBER_FIVE:
			velocity = 200.0f;
			break;
		case PELLET_NUMBER_TEN:
			velocity = 250.0f;
			break;
		case PELLET_NUMBER_TWENTY:
			velocity = 250.0f;
			break;
		}

		for (int i = 0; i < additionalPellets; i++) {
			u8 pelletColor = m_pelletInfo.m_color;
			if (pelletColor == 3) {
				pelletColor = randFloat() * 3.0f;
			}

			PelletNumberInitArg numberInitArg(m_pelletInfo.m_size, pelletColor);
			numberInitArg._14 = 2;
			Pellet* pellet    = pelletMgr->birth(&numberInitArg);

			if (pellet) {
				Vector3f throwupVelocity = Vector3f(velocity * (randFloat() - 0.5f), velocity, velocity * (randFloat() - 0.5f));
				pellet->setPosition(throwupPosition, false);
				pellet->setVelocity(throwupVelocity);
				pellet->createKiraEffect(throwupPosition);
			}
		}
	}
}

/*
 * --INFO--
 * Address:	80105E6C
 * Size:	000004
 */
void EnemyBase::doDebugDraw(Graphics&) { }

/*
 * --INFO--
 * Address:	80105E70
 * Size:	000080
 */
void EnemyBase::getLifeGaugeParam(LifeGaugeParam& param)
{
	if ((moviePlayer) && (moviePlayer->m_flags & MoviePlayer::IS_ACTIVE)) {
		param._14 = false;
	} else {
		param._14 = ((isEvent(0, EB_LifegaugeVisible)) && (m_lod.m_flags & AILOD_FLAG_NEED_SHADOW));
	}
	if (param._14) {
		doGetLifeGaugeParam(param);
	}
}

/*
 * --INFO--
 * Address:	80105EF0
 * Size:	000040
 */
void EnemyBase::doGetLifeGaugeParam(LifeGaugeParam& param)
{
	f32 y                    = m_position.y + static_cast<EnemyParmsBase*>(m_parms)->m_general.m_lifeMeterHeight.m_value;
	f32 z                    = m_position.z;
	f32 x                    = m_position.x;
	param.m_position         = Vector3f(x, y, z);
	param.m_healthPercentage = m_health / m_maxHealth;
	param._10                = 10.0f;
}

/*
 * --INFO--
 * Address:	80105F30
 * Size:	000050
 */
void EnemyBase::onStickStart(Creature* other)
{
	if (other->isPiki()) {
		m_stuckPikminCount++;
	}
}

/*
 * --INFO--
 * Address:	80105F80
 * Size:	000050
 */
void EnemyBase::onStickEnd(Creature* other)
{
	if (other->isPiki()) {
		m_stuckPikminCount--;
	}
}

/*
 * --INFO--
 * Address:	80105FD0
 * Size:	00005C
 */
bool EnemyBase::injure()
{
	if (isEvent(0, EB_Damage)) {
		if (!(isEvent(0, EB_Vulnerable))) {
			m_health -= m_instantDamage;
			if (m_health < 0.0f) {
				m_health = 0.0f;
			}
		}
		m_instantDamage = 0.0f;
		resetEvent(0, EB_Damage);
		return true;
	}
	return false;
}

/*
 * --INFO--
 * Address:	8010602C
 * Size:	000040
 */
void EnemyBase::addDamage(f32 damageAmt, f32 flickSpeed)
{
	if (isEvent(0, EB_Vulnerable)) {
		return;
	}
	m_instantDamage += damageAmt;
	if (isEvent(0, EB_DropMassSet)) {
		m_toFlick += flickSpeed;
	}
	setEvent(0, EB_Damage);
}

/*
 * --INFO--
 * Address:	8010606C
 * Size:	000048
 */
bool EnemyBase::damageCallBack(Creature* sourceCreature, f32 damage, CollPart* p3)
{
	if (!(isEvent(0, EB_Vulnerable))) {
		m_instantDamage += damage;
		if (isEvent(0, EB_DropMassSet)) {
			m_toFlick += 1.0f;
		}
		setEvent(0, EB_Damage);
	}
	return true;
}

/*
 * --INFO--
 * Address:	801060B4
 * Size:	000008
 */
bool EnemyBase::pressCallBack(Creature*, f32, CollPart*) { return false; }

/*
 * --INFO--
 * Address:	801060BC
 * Size:	000008
 */
bool EnemyBase::flyCollisionCallBack(Creature*, f32, CollPart*) { return false; }

/*
 * --INFO--
 * Address:	801060C4
 * Size:	000248
 */
bool EnemyBase::hipdropCallBack(Creature* sourceCreature, f32 damage, CollPart* p3)
{
	f32 purpleDamage = *static_cast<EnemyParmsBase*>(m_parms)->m_general.m_purplePikminHipDropDamage();

	if (!(isEvent(0, EB_Vulnerable))) {
		m_instantDamage += purpleDamage;
		if (isEvent(0, EB_DropMassSet)) {
			m_toFlick += 1.0f;
		}
		setEvent(0, EB_Damage);
	}

	setEvent(0, EB_20);
	if (m_curTriangle != 0) {
		createBounceEffect(m_position, getDownSmokeScale());
	}
	return false;
}

/*
 * --INFO--
 * Address:	8010630C
 * Size:	000008
 */
bool EnemyBase::dropCallBack(Creature*) { return false; }

/*
 * --INFO--
 * Address:	80106314
 * Size:	000040
 */
bool EnemyBase::isBeforeAppearState() { return m_lifecycleFSM->getCurrID(this) < 5; }

/*
 * --INFO--
 * Address:	80106354
 * Size:	000070
 */
bool EnemyBase::checkBirthTypeDropEarthquake()
{
	bool b = false;
	if (m_lifecycleFSM->getCurrID(this) == 4) {
		m_lifecycleFSM->transit(this, 5, nullptr);
		b = true;
	}
	return b;
}

/*
 * --INFO--
 * Address:	801063C4
 * Size:	0000EC
 */
bool EnemyBase::earthquakeCallBack(Creature* creature, f32 bounceFactor)
{
	if (m_curTriangle && !(m_health <= 0.0f) && !isFlying() && isAlive()) {
		if (!(isEvent(0, EB_HardConstraint)) && !(isEvent(0, EB_Bittered))) {
			if (((isEvent(0, EB_22)) || (isEvent(0, EB_BitterImmune))) == false) {
				EarthquakeStateArg eqArg;
				eqArg.m_bounceFactor = bounceFactor;
				m_lifecycleFSM->transit(this, EnemyBaseFSM::EBS_Earthquake, &eqArg);
			}
		}
	}
	return false;
}

/*
 * --INFO--
 * Address:	801064B0
 * Size:	000108
 */
bool EnemyBase::dopeCallBack(Creature* creature, int sprayType)
{
	if (isAlive() && !(m_health <= 0.0f) && doDopeCallBack(creature, sprayType)) {
		switch (sprayType) {
		case 1:
			if (!(m_events.m_flags[0].typeView & 0x400000) && !(m_events.m_flags[0].typeView & 0x200)) {
				if (m_events.m_flags[0].typeView & 0x200000) {
					m_events.m_flags[0].typeView |= 0x100000;
				} else if (m_enemyStoneObj->start()) {
					m_lifecycleFSM->transit(this, 7, 0);
				} else {
					m_events.m_flags[0].typeView |= 0x100000;
				}
			}
		}
	}
	return false;
}

/*
 * --INFO--
 * Address:	801065C0
 * Size:	000008
 */
bool EnemyBase::farmCallBack(Creature*, f32 power) { return false; }

/*
 * --INFO--
 * Address:	801065C8
 * Size:	000048
 */
bool EnemyBase::bombCallBack(Creature* creature, Vector3f& vec, f32 damage)
{
	if (!(isEvent(0, EB_Vulnerable))) {
		m_instantDamage += damage;

		if (isEvent(0, EB_DropMassSet)) {
			m_toFlick += 1.0f;
		}

		setEvent(0, EB_Damage);
	}

	return true;
}

/*
 * --INFO--
 * Address:	80106610
 * Size:	000054
 */
void EnemyBase::collisionCallback(CollEvent& coll)
{
	finishDropping(false);
	setCollEvent(coll);
}

/*
 * --INFO--
 * Address:	80106664
 * Size:	000028
 */
void EnemyBase::setCollEvent(CollEvent& event)
{
	m_collEvent.m_collidingCreature = event.m_collidingCreature;
	m_collEvent._04                 = event._04;
	m_collEvent.m_hitPart           = event.m_hitPart;
	setEvent(0, EB_Collision);
}

/*
 * --INFO--
 * Address:	8010668C
 * Size:	000010
 */
void EnemyBase::resetCollEvent() { resetEvent(0, EB_Collision); }

/*
 * --INFO--
 * Address:	8010669C
 * Size:	000004
 */
void EnemyBase::changeMaterial() { }

/*
 * --INFO--
 * Address:	801066A0
 * Size:	000008
 */
SysShape::Model* EnemyBase::viewGetShape() { return m_model; }

/*
 * --INFO--
 * Address:	801066A8
 * Size:	000020
 */
void EnemyBase::viewStartCarryMotion() { startMotion(); }

/*
 * --INFO--
 * Address:	801066C8
 * Size:	000040
 */
void EnemyBase::viewStartPreCarryMotion()
{
	startCarcassMotion();
	stopMotion();
}

/*
 * --INFO--
 * Address:	8010691C
 * Size:	000130
 */
void EnemyBase::viewOnPelletKilled()
{
	if (m_heldPellet) {
		InteractMattuan mattuan = InteractMattuan(this, 2.5f);
		m_heldPellet->stimulate(mattuan);
		m_heldPellet = nullptr;
	}

	m_soundObj->setKilled();

	if (lifeGaugeMgr) {
		lifeGaugeMgr->inactiveLifeGauge(this);
	}
	if (shadowMgr) {
		shadowMgr->delShadow(this);
	}

	fadeEffects();
	m_sfxEmotion = EMOTE_None;

	if (PSGetDirectedMainBgm()) {
		m_soundObj->battleOff();
	}

	static_cast<PSM::CreatureAnime*>(m_soundObj)->setAnime(nullptr, 1, 0.0f, 0.0f);
	m_mgr->kill(this);
}

/*
 * --INFO--
 * Address:	80106A4C
 * Size:	00002C
 */
void EnemyBase::view_start_carrymotion() { startCarcassMotion(); }

/*
 * --INFO--
 * Address:	80106A78
 * Size:	000040
 */
void EnemyBase::view_finish_carrymotion() { m_animator->getAnimator(0).m_flags |= 2; }

/*
 * --INFO--
 * Address:	80106AB8
 * Size:	0000A8
 */
void EnemyBase::getCommonEffectPos(Vector3f& commonEffectPos)
{
	commonEffectPos = getPosition();
	commonEffectPos.x += m_commonEffectOffset.x;
	commonEffectPos.y += m_commonEffectOffset.y;
	commonEffectPos.z += m_commonEffectOffset.z;
	commonEffectPos.y += static_cast<EnemyParmsBase*>(m_parms)->m_general.m_fp01.m_value;
}

/*
 * --INFO--
 * Address:	80106B60
 * Size:	000040
 */
inline void EnemyBase::getWaterSphere(Sys::Sphere* sphere)
{
	sphere->m_position.x = m_position.x + m_commonEffectOffset.x;
	sphere->m_position.y = m_position.y + m_commonEffectOffset.y;
	sphere->m_position.z = m_position.z + m_commonEffectOffset.z;
	sphere->m_radius     = static_cast<EnemyParmsBase*>(m_parms)->m_general.m_fp01.m_value;
}

/*
 * --INFO--
 * Address:	80106BA0
 * Size:	000148
 */
void EnemyBase::updateWaterBox()
{
	Sys::Sphere waterSphere;
	getWaterSphere(&waterSphere);

	if (m_waterBox) {
		if (!m_waterBox->inWater(waterSphere)) {
			if (mapMgr) {
				m_waterBox = mapMgr->findWater(waterSphere);
			}
			if (!m_waterBox) {
				m_waterBox = nullptr;
				outWaterCallback();
				fadeEfxHamon();
			}
		}
		updateEfxHamon();
	} else {
		WaterBox* waterBox = nullptr;
		if (mapMgr) {
			waterBox = mapMgr->findWater(waterSphere);
		}
		if (waterBox) {
			m_waterBox = waterBox;
			inWaterCallback(waterBox);
			createEfxHamon();
		}
	}
}

/*
 * --INFO--
 * Address:	80106CF0
 * Size:	00027C
 */
PSM::EnemyBase* EnemyBase::createPSEnemyBase()
{
	PSM::EnemyBase* base = nullptr;

	if (getEnemyTypeID() == EnemyTypeID::EnemyID_KumaChappy || getEnemyTypeID() == EnemyTypeID::EnemyID_FireChappy) {
		base = new PSM::Enemy_SpecialChappy(this, 4);
		return base;
	} else {
		EnemyInfo* info = EnemyInfoFunc::getEnemyInfo(getEnemyTypeID(), 0xFFFF);

		switch (info->m_bitterDrops) {
		case BDT_Weak:
			base = new PSM::EnemyHekoi(this, 2);
			break;
		case BDT_Normal:
			base = new PSM::EnemyBase(this, 3);
			break;
		case BDT_Strong:
			base = new PSM::EnemyBig(this, 4);
			break;
		case BDT_Triple:
		case BDT_MiniBoss:
			JUT_PANICLINE(4392, "abolished type\n");
			break;
		case BDT_Boss:
			base = new PSM::EnemyMidBoss(this);
			break;
		case BDT_FinalBoss:
			base = new PSM::EnemyBigBoss(this);
			break;
		case BDT_Empty:
			base = new PSM::EnemyNotAggressive(this, 2);
			break;
		}
	}
	return base;
}

/*
 * --INFO--
 * Address:	80107204
 * Size:	00001C
 */
void EnemyBase::startMotion()
{
	EnemyAnimatorBase* animator = m_animator;
	RESET_FLAG(animator->m_flags.typeView, EANIM_FLAG_STOPPED | EANIM_FLAG_REWIND);
	animator->m_progress = 1.0f;
}

/*
 * --INFO--
 * Address:	80107220
 * Size:	000058
 */
f32 EnemyBase::getMotionFrameMax() { return m_animator->getAnimator().m_animInfo->m_anm->m_time; }

/*
 * --INFO--
 * Address:	80107278
 * Size:	000068
 */
f32 EnemyBase::getFirstKeyFrame()
{
	CNode* node = m_animator->getAnimator().m_animInfo->m_keyEvent.m_child;
	if (node) {
		return (s32) static_cast<SysShape::KeyEvent*>(node)->m_frame;
	}
	return 0.0f;
}

/*
 * --INFO--
 * Address:	801072E0
 * Size:	000020
 */
void EnemyBase::stopMotion()
{
	EnemyAnimatorBase* animator = m_animator;
	animator->m_flags.typeView &= ~0x4;
	animator->m_flags.typeView |= 1;
}

/*
 * --INFO--
 * Address:	80107300
 * Size:	000038
 */
bool EnemyBase::isFinishMotion() { return m_animator->getAnimator().m_flags >> 1 & 1; }

/*
 * --INFO--
 * Address:	80107338
 * Size:	000010
 */
bool EnemyBase::isStopMotion() { return m_animator->m_flags.typeView & 1; }

/*
 * --INFO--
 * Address:	80107348
 * Size:	000048
 */
int EnemyBase::getCurrAnimIndex()
{
	SysShape::AnimInfo* animInfo = m_animator->getAnimator().m_animInfo;
	if (animInfo) {
		return animInfo->m_id;
	}
	return -1;
}

/*
 * --INFO--
 * Address:	80107390
 * Size:	00000C
 */
void EnemyBase::setAnimSpeed(f32 speed) { m_animator->m_animSpeed = speed; }

/*
 * --INFO--
 * Address:	8010739C
 * Size:	000030
 */
void EnemyBase::resetAnimSpeed() { m_animator->resetAnimSpeed(); }

/*
 * --INFO--
 * Address:	801073D8
 * Size:	000014
 */
JAInter::Object* EnemyBase::getJAIObject() { return static_cast<JAInter::Object*>(m_soundObj); }

/*
 * --INFO--
 * Address:	801073EC
 * Size:	000008
 */
PSM::Creature* EnemyBase::getPSCreature() { return static_cast<PSM::Creature*>(m_soundObj); }

/*
 * --INFO--
 * Address:	801073F4
 * Size:	00001C
 */
int EnemyBase::getStateID()
{
	if (m_currentLifecycleState) {
		return m_currentLifecycleState->m_stateID;
	}
	return -1;
}

/*
 * --INFO--
 * Address:	80107410
 * Size:	0000AC
 */
bool EnemyBase::needShadow()
{
	if (moviePlayer && moviePlayer->m_flags & 1) {
		bool needShadow = false;
		if (isMovieActor() || m_mgr->isAlwaysMovieActor()) {
			needShadow = true;
		}
		return needShadow;
	} else {
		bool needShadow = false;
		if (m_lod.m_flags & AILOD_FLAG_NEED_SHADOW && !(isEvent(0, EB_31))) {
			needShadow = true;
		}
		return needShadow;
	}
}

/*
 * --INFO--
 * Address:	801074D0
 * Size:	000234
 */
bool EnemyBase::eatWhitePikminCallBack(Creature* creature, f32 damage)
{
	addDamage(damage, 0.0f);

	if (!(isEvent(0, EB_15))) {
		setEvent(0, EB_15);

		m_damageAnimTimer = sys->m_deltaTime;

		for (int i = 0; i < m_enemyStoneObj->m_info->m_infoCnt; i++) {
			EnemyStone::DrawInfo drawInfo(false);
			EnemyStone::ObjInfo* objInfo = &m_enemyStoneObj->m_info->m_infoArr[i];
			char* jointName              = objInfo->m_name;
			SysShape::Joint* joint       = m_model->getJoint(jointName);
			drawInfo.m_matrix            = joint->getWorldMatrix();
			drawInfo.m_objInfo           = objInfo;
			Vector3f effectPosition;
			f32 scale;
			if (drawInfo.getPosAndScale(&effectPosition, &scale)) {
				scale *= m_scaleModifier;
				efx::ArgScale arg(effectPosition, scale);
				switch (drawInfo.m_objInfo->_04) {
				case 0:
					efx::TEnemyPoisonL poisonL;
					poisonL.create(&arg);
					break;
				case 1:
					efx::TEnemyPoisonS poisonS;
					poisonS.create(&arg);
					break;
				}
			}
		}

		m_soundObj->startSound(0x5807, false);
	}
	return true;
}

/*
 * --INFO--
 * Address:	80107764
 * Size:	000008
 */
f32 EnemyBase::getDownSmokeScale() { return 0.0f; }

/*
 * --INFO--
 * Address:	8010776C
 * Size:	000010
 */
void EnemyBase::constraintOff() { resetEvent(0, EB_Constraint); }

/*
 * --INFO--
 * Address:	8010777C
 * Size:	000018
 */
void EnemyBase::hardConstraintOn()
{
	setEvent(0, EB_HardConstraint);
	m_mass = 0.0f;
}

/*
 * --INFO--
 * Address:	80107794
 * Size:	000028
 */
void EnemyBase::hardConstraintOff()
{
	resetEvent(0, EB_HardConstraint);
	m_mass           = m_friction;
	m_acceleration.x = 0.0f;
	m_acceleration.y = 0.0f;
	m_acceleration.z = 0.0f;
}

/*
 * --INFO--
 * Address:	801077BC
 * Size:	000084
 */
void EnemyBase::startMovie()
{
	if (m_lifecycleFSM->getCurrID(this) >= 5) {
		fadeEffects();
		doStartMovie();
	}
}

/*
 * --INFO--
 * Address:	80107844
 * Size:	000084
 */
void EnemyBase::endMovie()
{
	if (m_lifecycleFSM->getCurrID(this) >= 5) {
		createEffects();
		doEndMovie();
	}
}

/*
 * --INFO--
 * Address:	801078C8
 * Size:	000004
 */
// WEAK - in header
// void EnemyBase::doEndMovie() { }

/*
 * --INFO--
 * Address:	801078CC
 * Size:	000094
 */
void EnemyBase::doStartEarthquakeState(f32 yVelocityScale)
{
	m_simVelocity.x = 0.0f;
	m_simVelocity.y = 0.0f;
	m_simVelocity.z = 0.0f;

	m_impVelocity.x = 0.0f;
	m_impVelocity.y = 0.0f;
	m_impVelocity.z = 0.0f;

	m_impVelocity.y = (yVelocityScale * 200.0f + randFloat() * 100.0f);
};

/*
 * --INFO--
 * Address:	80107960
 * Size:	000004
 */
void EnemyBase::doFinishEarthquakeState() { }

/*
 * --INFO--
 * Address:	80107964
 * Size:	000004
 */
void EnemyBase::doStartEarthquakeFitState() { }

/*
 * --INFO--
 * Address:	80107968
 * Size:	000004
 */
void EnemyBase::doFinishEarthquakeFitState() { }

/*
 * --INFO--
 * Address:	8010796C
 * Size:	00002C
 */
void EnemyBase::startWaitingBirthTypeDrop() { doStartWaitingBirthTypeDrop(); }

/*
 * --INFO--
 * Address:	80107998
 * Size:	000004
 */
void EnemyBase::doStartWaitingBirthTypeDrop() { }

/*
 * --INFO--
 * Address:	8010799C
 * Size:	00002C
 */
void EnemyBase::finishWaitingBirthTypeDrop() { doFinishWaitingBirthTypeDrop(); }

/*
 * --INFO--
 * Address:	801079C8
 * Size:	000064
 */
void EnemyBase::doFinishWaitingBirthTypeDrop()
{
	if (!isFlying()) {
		setEvent(1, EB2_5);
		setDroppingMassZero();
		m_scale.x = 1.0f;
		m_scale.y = 1.0f;
		m_scale.z = 1.0f;
	}
}

/*
 * --INFO--
 * Address:	80107A2C
 * Size:	00003C
 */
bool EnemyBase::isBirthTypeDropGroup()
{
	return (m_dropGroup == 1 || m_dropGroup == 2 || m_dropGroup == 3 || m_dropGroup == 4 || m_dropGroup == 5);
}

/*
 * --INFO--
 * Address:	80107A68
 * Size:	000008
 */
Vector3f* EnemyBase::getFitEffectPos() { return &m_boundingSphere.m_position; }

/*
 * --INFO--
 * Address:	80107A70
 * Size:	000018
 */
void EnemyBase::setDroppingMassZero()
{
	setEvent(1, EB2_DroppingMassZero);
	m_mass = 0.0f;
}

/*
 * --INFO--
 * Address:	80107A88
 * Size:	000018
 */
void EnemyBase::resetDroppingMassZero()
{
	resetEvent(1, EB2_DroppingMassZero);
	m_mass = m_friction;
}
} // namespace Game
