#include "Dolphin/rand.h"
#include "Game/Entities/BigTreasure.h"
#include "Game/Entities/PikiBaby.h"
#include "Game/generalEnemyMgr.h"
#include "Game/Entities/ItemHoney.h"

namespace Game {
namespace BigTreasure {

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

bool Obj::isNormalAttack(int idx)
{
	int curIndex = idx;
	// Gas pinch life check uses Elec life instead
	if (idx == BIGATTACK_Gas) {
		curIndex = BIGATTACK_Elec;
	}
	return (mTreasureHealth[curIndex] > 2500.0f);
}

// force BIGATTACK_Gas to be one of two attacks that shock therapist can use
void Obj::setTreasureAttack()
{
	int attackIdx[BIGATTACK_Count];     // indices for available attacks, max 4
	f32 weaponWeights[BIGATTACK_Count]; // weightings for each available attack based on health, max 4

	f32 totalWeights = 0.0f; // total weightings
	int count        = 0;    // how many weapons alive, max 4

	// loop through all weapons; if alive, calc weighting + add to arrays
	// 0 = elec, 1 = fire, 2 = gas, 3 = water
	for (int i = 0; i < BIGATTACK_Count; i++) {
		// effectively rework BIGATTACK_Gas to be a part of BIGATTACK_Elec
		// basically 50/50 chance for one treasure to do either
		Game::Pellet* curTreasure = mTreasures[i];
		f32 treasureHealth        = mTreasureHealth[i];
		// BIGATTACK_Gas uses shock therapist's health and treasure reference
		if (i == BIGATTACK_Gas) {
			curTreasure    = mTreasures[BIGATTACK_Elec];
			treasureHealth = mTreasureHealth[BIGATTACK_Elec];
		}

		if (curTreasure) {
			attackIdx[count] = i;

			// each weapon weight is [5000.0f, 10000.0f)
			// 5000.0f at max health, linearly approaches 10000.0f as health decreases
			weaponWeights[count] = 10000.0f - treasureHealth;
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
		 * - Bands are always in the order (elec -> fire -> gas -> water).
		 *
		 * i.e.
		 *
		 *      |     elec     | fire |   gas   |       water       |
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
	case BIGATTACK_Elec:
		mAttackMgr->startElecAttack();
		break;
	case BIGATTACK_Fire:
		mAttackMgr->startFireAttack();
		break;
	case BIGATTACK_Gas:
		mAttackMgr->startGasAttack();
		break;
	case BIGATTACK_Water:
		mAttackMgr->startWaterAttack();
		break;
	}
}

// change gas effect joint to shock therapist's joint
void BigTreasureAttackMgr::updateGasEmitPosition()
{
	mGasEmitPosition = mObj->m_model->getJoint("otakara_elec_eff")->getWorldMatrix()->getColumn(3);
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
	case BIGATTACK_Gas:
		createPikiBaby(EnemyTypeID::EnemyID_PikiBabyYellow, 7, position);
		break;
	case BIGATTACK_Elec:
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

} // namespace BigTreasure
} // namespace Game
