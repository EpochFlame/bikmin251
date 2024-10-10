#include "Dolphin/rand.h"
#include "Game/Entities/BigTreasure.h"
#include "Game/Entities/PikiBaby.h"
#include "Game/generalEnemyMgr.h"
#include "Game/Entities/ItemHoney.h"

namespace Game {
namespace BigTreasure {

bool Obj::sHasDoneTrollAttack = false;

int BigTreasureAttackMgr::sPikiBabyCount = 0;

#pragma region GENERAL

// remove the hardcoded offset for comedy bomb
void Obj::setupBigTreasureCollision()
{
	bool treasureCheck = true;
	for (int i = 0; i < 4; i++) {
		if (mTreasures[i]) {
			treasureCheck = false;
		} else if (mTreasureCollParts[i]) {
			flickStickCollPartPikmin(mTreasureCollParts[i]);
			mTreasureCollParts[i]->m_specialID = '_t__';
			mTreasureCollParts[i]->m_radius    = 0.0f;
			mTreasureCollParts[i]->m_attribute = 1;
			mTreasureCollParts[i]              = nullptr;
		}
	}

	CollPart* tam1 = m_collTree->getCollPart('tam1');
	CollPart* tam2 = m_collTree->getCollPart('tam2');

	if (tam1 && tam2) {
		if (treasureCheck) {
			tam1->m_specialID = 'st__';
			tam2->m_specialID = 'st__';
		} else {
			tam1->m_specialID = '_t__';
			tam2->m_specialID = '_t__';
		}
	}
}

void Obj::setupTreasure()
{
	// swap comedy bomb and shock therapist positions
	u32 collTags[]      = { 'elec', 'fire', 'gasi', 'mizu' };
	char* pelletNames[] = { "gas", "fire", "elec", "water" };
	char* jointNames[]  = { "otakara_elec", "otakara_fire", "otakara_gas", "otakara_water" };

	for (int i = 0; i < 4; i++) {
		mIsWeaponAttacked[i]   = false;
		mTreasures[i]          = nullptr;
		mTreasureHealth[i]     = 0.0f;
		mTreasureShakeAngle[i] = 0.0f;
		mTreasureCollParts[i]  = m_collTree->getCollPart(collTags[i]);

		PelletInitArg weaponArg;
		if (pelletMgr->makePelletInitArg(weaponArg, pelletNames[i])) {
			mTreasures[i] = pelletMgr->birth(&weaponArg);

			if (mTreasures[i]) {
				Matrixf* pelletMat = m_model->getJoint(jointNames[i])->getWorldMatrix();
				mTreasures[i]->startCapture(pelletMat);
				// change treasure health from 6000.0f to 5000.0f
				mTreasureHealth[i] = 5000.0f;
			}
		}
	}

	mLouie = nullptr;
	PelletInitArg louieArg;
	if (pelletMgr->makePelletInitArg(louieArg, "loozy")) {
		mLouie = pelletMgr->birth(&louieArg);

		if (mLouie) {
			Matrixf* louieMat = m_model->getJoint("otakara_loozy")->getWorldMatrix();
			mLouie->startCapture(louieMat);
		}
	}

	setupBigTreasureCollision();

	mAttackIndex = -1;
}

#pragma endregion

#pragma region GENERAL_ATTACK

// force BIGATTACK_Gas to be one of two attacks that troll onion can use
void Obj::setTreasureAttack()
{
	int attackIdx[BIGATTACK_Count];     // indices for available attacks, max 4
	f32 weaponWeights[BIGATTACK_Count]; // weightings for each available attack based on health, max 4

	f32 totalWeights = 0.0f; // total weightings
	int count        = 0;    // how many weapons alive, max 4

	// loop through all weapons; if alive, calc weighting + add to arrays
	// 0 = troll, 1 = fire, 2 = piki, 3 = water
	for (int i = 0; i < BIGATTACK_Count; i++) {
		if (mTreasures[i]) {
			attackIdx[count] = i;

			// each weapon weight is [5000.0f, 10000.0f)
			// 5000.0f at max health, linearly approaches 10000.0f as health decreases
			weaponWeights[count] = 10000.0f - mTreasureHealth[i];
			totalWeights += weaponWeights[count];

			count++;
		}
	}

	// if we have any weapons left, determine attack
	if (count) {
		/**
		 * 'threshold' is a random float between 0 and totalWeights.
		 * - If threshold falls 'within' one of the 'bands' of weights, that weapon is selected.
		 * - A given band is bigger if that weapon is on lower health.
		 * - Bands are always in the order (troll -> fire -> piki -> water).
		 *
		 * i.e.
		 *
		 *      |     troll     | fire |   piki   |       water       |
		 *      0                 ^(threshold)                    total
		 *
		 * == fire gets chosen.
		 */
		f32 threshold = randWeightFloat(totalWeights);
		f32 inc       = 0.0f;
		for (int i = 0; i < count; i++) {
			inc += weaponWeights[i]; // jump to next weapon bracket
			if (inc > threshold) {   // if threshold falls in that bracket, choose weapon
				mAttackIndex = attackIdx[i];

				// if it has already used the troll attack, use gas instead
				if (mAttackIndex == BIGATTACK_Troll && sHasDoneTrollAttack) {
					mAttackIndex = BIGATTACK_Gas;
				}

				return;
			}
		}
	}

	// no weapons left/something weird happened, no attack
	mAttackIndex = BIGATTACK_NULL;
}

void Obj::startAttack()
{
	switch (mAttackIndex) {
	case BIGATTACK_Troll:
		mAttackMgr->startElecAttack();
		sHasDoneTrollAttack = true;
		break;
	case BIGATTACK_Gas:
		mAttackMgr->startGasAttack();
		sHasDoneTrollAttack = false;
		break;
	case BIGATTACK_Fire:
		mAttackMgr->startFireAttack();
		break;
	case BIGATTACK_Water:
		mAttackMgr->startWaterAttack();
		break;
	case BIGATTACK_Piki:
		mAttackMgr->startPikiAttack();
		break;
	}
}

void Obj::createPikiBaby(EnemyTypeID::EEnemyTypeID type, u8 count, Vector3f& position)
{
	PikiBaby::Mgr* babyMgr = static_cast<PikiBaby::Mgr*>(generalEnemyMgr->getEnemyMgr(type));
	if (babyMgr == nullptr) {
		return;
	}

	EnemyBirthArg birthArg;
	birthArg.m_position = position;

	for (u8 i = 0; i < count; i++) {
		f32 angle          = TAU * ((f32)i / count);
		birthArg.m_faceDir = angle;

		PikiBaby::Obj* baby = static_cast<PikiBaby::Obj*>(babyMgr->birth(birthArg));
		if (baby == nullptr) {
			continue;
		}

		f32 speed = C_GENERALPARMS.m_privateRadius.m_value;
		Vector3f velocity(speed * sinf(angle), 200.0f, speed * cosf(angle));

		baby->init(nullptr);
		baby->setVelocity(velocity);
		baby->m_simVelocity = velocity;
	}
}

bool Obj::dropTreasure(int idx)
{
	Vector3f position = mTreasures[idx]->getPosition();

	// all weapons should spawn something upon being dropped
	switch (idx) {
	case BIGATTACK_Fire:
		createPikiBaby(EnemyTypeID::EnemyID_PikiBabyRed, 7, position);
		break;
	case BIGATTACK_Water:
		createPikiBaby(EnemyTypeID::EnemyID_PikiBabyBlue, 7, position);
		break;
	case BIGATTACK_Piki:
		createPikiBaby(EnemyTypeID::EnemyID_PikiBabyYellow, 7, position);
		break;
	case BIGATTACK_Troll:
		// spawn an alfredo sauce
		ItemHoney::Item* spray = static_cast<ItemHoney::Item*>(ItemHoney::mgr->birth());
		if (spray != nullptr) {
			spray->init(nullptr);
			spray->m_honeyType = HONEY_R;
			spray->setPosition(position, false);
			Vector3f vel(0.0f, 250.0f, 0.0f);
			spray->setVelocity(vel);
		}
		break;
	}

	mTreasures[idx]->endCapture();
	Vector3f velocity(0.0f, 100.0f, 0.0f);
	mTreasures[idx]->setVelocity(velocity);
	mTreasures[idx]      = nullptr;
	mTreasureHealth[idx] = 0.0f;
	return true;
}

#pragma endregion

#pragma region ANIMATION

// add new BIGATTACK_Piki preattack anims
int Obj::getPreAttackAnimIndex()
{
	switch (mAttackIndex) {
	case BIGATTACK_Troll:
		return BIGTREASUREANIM_PreAttackE;
	case BIGATTACK_Fire:
		return BIGTREASUREANIM_PreAttackF;
	case BIGATTACK_Gas:
		return BIGTREASUREANIM_PreAttackG;
	case BIGATTACK_Water:
		return BIGTREASUREANIM_PreAttackW;
	case BIGATTACK_Piki:
		return BIGTREASUREANIM_PreAttackP;
	}

	return BIGTREASUREANIM_DropItem;
}

// add new BIGATTACK_Piki attack anims
int Obj::getAttackAnimIndex()
{
	switch (mAttackIndex) {
	case BIGATTACK_Troll:
		return BIGTREASUREANIM_AttackE;
	case BIGATTACK_Gas:
		return BIGTREASUREANIM_AttackG;
	case BIGATTACK_Water:
		return BIGTREASUREANIM_AttackW;
	case BIGATTACK_Piki:
		return BIGTREASUREANIM_AttackP;
	}

	if (mAttackIndex == BIGATTACK_Fire) {
		int currAnimIdx = getCurrAnimationIndex();
		switch (currAnimIdx) {
		case BIGTREASUREANIM_PreAttackF:
			return BIGTREASUREANIM_AttackF;
		case BIGTREASUREANIM_PreAttackFR:
			return BIGTREASUREANIM_AttackFR;
		case BIGTREASUREANIM_PreAttackFL:
			return BIGTREASUREANIM_AttackFR;
		case BIGTREASUREANIM_PreAttackFB:
			return BIGTREASUREANIM_AttackFB;
		}
	}

	return BIGTREASUREANIM_DropItem;
}

// add new BIGATTACK_Piki attackend anims
int Obj::getPutItemAnimIndex()
{
	switch (mAttackIndex) {
	case BIGATTACK_Troll:
		return BIGTREASUREANIM_AttackEndE;
	case BIGATTACK_Gas:
		return BIGTREASUREANIM_AttackEndG;
	case BIGATTACK_Water:
		return BIGTREASUREANIM_AttackEndW;
	case BIGATTACK_Piki:
		return BIGTREASUREANIM_AttackEndP;
	}

	if (mAttackIndex == BIGATTACK_Fire) {
		int currAnimIdx = getCurrAnimationIndex();
		switch (currAnimIdx) {
		case BIGTREASUREANIM_AttackF:
			return BIGTREASUREANIM_AttackEndF;
		case BIGTREASUREANIM_AttackFR:
			return BIGTREASUREANIM_AttackEndFR;
		case BIGTREASUREANIM_AttackFL:
			return BIGTREASUREANIM_AttackEndFL;
		case BIGTREASUREANIM_AttackFB:
			return BIGTREASUREANIM_AttackEndFB;
		}
	}
	return BIGTREASUREANIM_DropItem;
}

// add new BIGATTACK_Piki preattack time
f32 Obj::getPreAttackTimeMax()
{
	switch (mAttackIndex) {
	case BIGATTACK_Troll:
		return C_PROPERPARMS.mElectricityWaitTime.m_value;
	case BIGATTACK_Fire:
		if (isNormalAttack(mAttackIndex)) {
			return C_PROPERPARMS.mFireWaitTime1.m_value;
		}
		return C_PROPERPARMS.mFireWaitTime2.m_value;
	case BIGATTACK_Gas:
		return C_PROPERPARMS.mGasWaitTime.m_value;
	case BIGATTACK_Water:
		return C_PROPERPARMS.mWaterWaitTime.m_value;
	case BIGATTACK_Piki:
		return 0.0f;
	}

	return 5.0f;
}

// add new BIGATTACK_Piki attack time
f32 Obj::getAttackTimeMax()
{
	switch (mAttackIndex) {
	case BIGATTACK_Troll:
		return C_PROPERPARMS.mElecAttackTimeMax.m_value;
	case BIGATTACK_Fire:
		return C_PROPERPARMS.mFireAttackTimeMax.m_value;
	case BIGATTACK_Gas:
		return C_PROPERPARMS.mGasAttackTimeMax.m_value;
	case BIGATTACK_Water:
		return C_PROPERPARMS.mWaterAttackTimeMax.m_value;
	case BIGATTACK_Piki:
		if (isNormalAttack(BIGATTACK_Piki)) {
			return 0.0f;
		}
		return 1.5f;
	}

	return 5.0f;
}

#pragma endregion

#pragma region PIKIATTACK

void BigTreasureAttackMgr::startPikiAttack()
{
	if (mIsStartAttack[BIGATTACK_Piki]) {
		return;
	}

	sPikiBabyCount = 0;
	mIsStartAttack[BIGATTACK_Piki] = true;
}

void BigTreasureAttackMgr::updatePikiAttack()
{
	if (!mIsStartAttack[BIGATTACK_Piki]) {
		return;
	}

	PikiBabyYellow::Mgr* babyMgr = static_cast<PikiBabyYellow::Mgr*>(generalEnemyMgr->getEnemyMgr(EnemyTypeID::EnemyID_PikiBabyYellow));
	if (babyMgr == nullptr) {
		return;
	}

	// spawn 7 normally, and 14 at pinch life
	int max = 7;
	if (!mObj->isNormalAttack(BIGATTACK_Piki)) {
		max = 14;
	}

	EnemyBirthArg birthArg;
	birthArg.m_position = mObj->m_model->getJoint("otakara_gas")->getWorldMatrix()->getColumn(3);
	birthArg.m_position.y += 5.0f;

	Vector3f velocity(100.0f);
	f32 speed = CG_GENERALPARMS(mObj).m_privateRadius.m_value * 1.0f;

	f32 interval = (1.25f + mObj->getAttackTimeMax()) / max;
	if (mAttackTimer1 <= interval || sPikiBabyCount >= max) {
		return;
	}

	mAttackTimer1 = 0.0f;

	f32 angle          = TAU * ((f32)sPikiBabyCount / max);
	birthArg.m_faceDir = angle;

	velocity.x = speed * sinf(angle);
	velocity.y = speed * cosf(angle);

	PikiBabyYellow::Obj* baby = static_cast<PikiBabyYellow::Obj*>(babyMgr->birth(birthArg));
	if (baby == nullptr) {
		return;
	}

	baby->init(nullptr);
	baby->setVelocity(velocity);
	baby->m_simVelocity = velocity;

	sPikiBabyCount++;
}

void BigTreasureAttackMgr::update()
{
	updateFireAttack();
	updateGasAttack();
	updateWaterAttack();
	updateElecAttack();
	updateAttackShadow();

	// add pikibaby attack update func
	updatePikiAttack();

	bool isAttacking = false;
	for (int i = 0; i < BIGATTACK_Count; i++) {
		if (mIsStartAttack[i]) {
			isAttacking = true;
			if (mObj->isEvent(0, EB_Bittered) && !mObj->isCapturedTreasure(i)) {
				finishAttack();
			}
		}
	}

	if (isAttacking) {
		mAttackTimer1 += sys->m_deltaTime;
		mAttackTimer2 += sys->m_deltaTime;
	}
}

#pragma endregion

#pragma region GASATTACK

// change gas effect joint to shock therapist's joint
void BigTreasureAttackMgr::updateGasEmitPosition()
{
	mGasEmitPosition = mObj->m_model->getJoint("otakara_elec_eff")->getWorldMatrix()->getColumn(3);
}

bool Obj::isNormalAttack(int idx)
{
	int curIndex = idx;
	// Gas pinch life check uses Elec life instead
	if (idx == BIGATTACK_Gas) {
		curIndex = BIGATTACK_Troll;
	}
	return (mTreasureHealth[curIndex] > 2500.0f);
}

bool Obj::isCapturedTreasure(int idx)
{
	if (idx == BIGATTACK_Gas) {
		return mTreasures[BIGATTACK_Troll];
	}
	return mTreasures[idx];
}

// canStartGasAttack__Q34Game11BigTreasure20BigTreasureAttackMgrFv
bool BigTreasureAttackMgr::canStartGasAttack() { return mIsStartAttack[BIGATTACK_Troll] && !Obj::sHasDoneTrollAttack; }

// use BIGATTACK_Troll index instead
void BigTreasureAttackMgr::setGasAttackParameter()
{
	int attackType;
	if (mObj->isNormalAttack(BIGATTACK_Troll)) {
		attackType = 1;
	} else if (randWeightFloat(1.0f) < 0.5f) {
		attackType = 2;
	} else {
		attackType = 3;
	}

	switch (attackType) {
	case 1:
		mAttackData->mGasArmNum        = 3;
		mAttackData->mGasRotationSpeed = CG_PROPERPARMS(mObj).mRotationSpeed1.m_value;
		mAttackData->mGasReversalTime  = 30.0f;
		break;
	case 2:
		mAttackData->mGasArmNum        = 4;
		mAttackData->mGasRotationSpeed = CG_PROPERPARMS(mObj).mRotationSpeed2.m_value;
		mAttackData->mGasReversalTime  = CG_PROPERPARMS(mObj).mReversalTime2_1.m_value;
		break;
	case 3:
		mAttackData->mGasArmNum        = 4;
		mAttackData->mGasRotationSpeed = CG_PROPERPARMS(mObj).mRotationSpeed2.m_value;
		mAttackData->mGasReversalTime  = CG_PROPERPARMS(mObj).mReversalTime2_2.m_value;
		break;
	}

	// 50/50 chance to start rotating clockwise or anticlockwise
	if (randWeightFloat(1.0f) < 0.5f) {
		mAttackData->mIsGasRotClockwise = true;
	} else {
		mAttackData->mIsGasRotClockwise = false;
	}
}

// use BIGATTACK_Troll index instead
void BigTreasureAttackMgr::startGasAttack()
{
	if (!mIsStartAttack[BIGATTACK_Troll]) {
		mIsStartAttack[BIGATTACK_Troll] = true;
		mAttackTimer1                   = 0.0f;
		mAttackTimer2                   = 0.0f;

		setGasAttackParameter();

		updateGasEmitPosition();

		f32 startAngle = randWeightFloat(TAU);
		f32 armSpacing = TAU / (f32)mAttackData->mGasArmNum;

		for (int i = 0; i < mAttackData->mGasArmNum; i++) {
			mGasAttackAngles[i] = startAngle + armSpacing * (f32)i;
			mEfxGas[i]->create(nullptr);
		}

		startNewGasList();
	}
}

#pragma endregion

void Obj::setAttackMaterialColor(bool isFast)
{
	mIsFastMatAnim = isFast;

	if (mIsFastMatAnim) {
		switch (mAttackIndex) {
		case BIGATTACK_Piki:
			mTargetMatBodyColor.r = 150;
			mTargetMatBodyColor.g = 130;
			mTargetMatBodyColor.b = 20;

			mTargetClusterEyeColor[EYECOLOR_Dark].set(30.0f, 30.0f, 0.0f);
			mTargetClusterEyeColor[EYECOLOR_Light].set(255.0f, 180.0f, 70.0f);

			mTargetSideEyeColor[EYECOLOR_Dark].set(60.0f, 60.0f, 30.0f);
			mTargetSideEyeColor[EYECOLOR_Light].set(255.0f, 150.0f, 80.0f);
			break;

		case BIGATTACK_Fire:
			mTargetMatBodyColor.r = 160;
			mTargetMatBodyColor.g = 50;
			mTargetMatBodyColor.b = 20;

			mTargetClusterEyeColor[EYECOLOR_Dark].set(60.0f, 20.0f, 20.0f);
			mTargetClusterEyeColor[EYECOLOR_Light].set(255.0f, 100.0f, 100.0f);

			mTargetSideEyeColor[EYECOLOR_Dark].set(80.0f, 60.0f, 45.0f);
			mTargetSideEyeColor[EYECOLOR_Light].set(255.0f, 150.0f, 120.0f);
			break;

		case BIGATTACK_Gas:
		case BIGATTACK_Troll:
			mTargetMatBodyColor.r = 90;
			mTargetMatBodyColor.g = 5;
			mTargetMatBodyColor.b = 120;

			mTargetClusterEyeColor[EYECOLOR_Dark].set(30.0f, 0.0f, 30.0f);
			mTargetClusterEyeColor[EYECOLOR_Light].set(220.0f, 68.0f, 160.0f);

			mTargetSideEyeColor[EYECOLOR_Dark].set(68.0f, 82.0f, 40.0f);
			mTargetSideEyeColor[EYECOLOR_Light].set(182.0f, 252.0f, 3.0f);
			break;

		case BIGATTACK_Water:
			mTargetMatBodyColor.r = 40;
			mTargetMatBodyColor.g = 100;
			mTargetMatBodyColor.b = 180;

			mTargetClusterEyeColor[EYECOLOR_Dark].set(40.0f, 80.0f, 70.0f);
			mTargetClusterEyeColor[EYECOLOR_Light].set(120.0f, 255.0f, 180.0f);

			mTargetSideEyeColor[EYECOLOR_Dark].set(20.0f, 20.0f, 60.0f);
			mTargetSideEyeColor[EYECOLOR_Light].set(120.0f, 150.0f, 255.0f);
			break;
		}

	} else {
		bool hasTreasures = isCapturedTreasure();

		mTargetMatBodyColor.r = 30;
		mTargetMatBodyColor.g = 70;
		mTargetMatBodyColor.b = 60;

		if (hasTreasures) {
			mTargetMatBodyColor.a = 255;
		} else {
			mTargetMatBodyColor.a = 0;
		}

		if (hasTreasures) {
			mTargetClusterEyeColor[EYECOLOR_Dark].set(20.0f, 60.0f, 20.0f);
			mTargetClusterEyeColor[EYECOLOR_Light].set(120.0f, 255.0f, 90.0f);

			mTargetSideEyeColor[EYECOLOR_Dark].set(0.0f, 30.0f, 0.0f);
			mTargetSideEyeColor[EYECOLOR_Light].set(90.0f, 180.0f, 160.0f);

		} else {
			mTargetClusterEyeColor[EYECOLOR_Dark].set(10.0f, 100.0f, 255.0f);
			mTargetClusterEyeColor[EYECOLOR_Light].set(255.0f, 180.0f, 64.0f);

			mTargetSideEyeColor[EYECOLOR_Dark].set(60.0f, 230.0f, 30.0f);
			mTargetSideEyeColor[EYECOLOR_Light].set(100.0f, 30.0f, 200.0f);

			if (mTargetMatBodyColor.a == 0 && mCurrMatBodyColor.a == 255) {
				createChangeMaterialEffect();
				getJAIObject()->startSound(PSSE_EN_BIGTAKARA_SHELL, 0);
			}
		}
	}

	setMatEyeAnimSpeed();
}

} // namespace BigTreasure
} // namespace Game
