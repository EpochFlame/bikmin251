#include "Game/Entities/Houdai.h"
#include "PS.h"
#include "efx/TDama.h"
#include "efx/TOoota.h"
#include "efx/TEnemyDownWat.h"
#include "efx/TEnemyDownSmoke.h"
#include "JSystem/JAI/JAISound.h"

namespace Game{
namespace Houdai {

Sys::MatLoopAnimator Obj::sMatAnimator;

// startMatAnimator__Q34Game6Houdai3ObjFv
void Obj::startMatAnimator()
{
    sMatAnimator.start(C_MGR->mTevRegAnimation);
}

// changeMaterial__Q34Game6Houdai3ObjFv
void Obj::changeMaterial()
{
    J3DModel* model = m_model->getJ3DModel();
    J3DModelData* modelData = model->m_modelData;
    model->calcMaterial();

    if (sMatAnimator._08 < sMatAnimator.m_animation->getFrameMax() - 1 && mFsm->getCurrID(this) == HOUDAI_Land) {
        sMatAnimator.animate(30.0f);
    }

    // diff material
    for (u16 i = 0; i < modelData->m_materialTable.m_count1; i++) {
		j3dSys.m_matPacket = &model->m_matPackets[i];
		J3DMaterial* mat  = modelData->m_materialTable.m_materials1[i];
		mat->diff(j3dSys.m_matPacket->_2C->_34);
	}
}

void Obj::doUpdate()
{
	updateShotGunTimer();
	mFsm->exec(this);
	updatePinchLife();
	updateIKSystem();
	doUpdateShotGun();
}

// void Obj::createEffect()
// {
// 	for (int i = 0; i < 4; i++) {
// 		mAppearHahenFootFX[i] = new efx::THdamaOnHahen2;
// 	}

// 	for (int i = 0; i < 3; i++) {
// 		mDeadElecAFX[i] = new efx::TDamaDeadElecA;
// 		mHahenFX[i]     = new efx::THdamaHahen;
// 	}

// 	mAppearHahenFX = new efx::THdamaOnHahen1;
// 	mDeadBombFX    = new efx::THdamaDeadbomb;
// }

void Obj::setupEffect()
{
	for (int i = 0; i < 4; i++) {
		mAppearHahenFootFX[i]->setPosPosptrs(&mJointPositions[i][1], &mJointPositions[i][2]);
	}

	for (int i = 0; i < 3; i++) {
		mDeadElecAFX[i]->setPosPosptrs(&mJointPositions[0][i], &mJointPositions[0][i + 1]);
	}

	mHahenFX[0]->setPosPosptrs(&mJointPositions[2][1], &mJointPositions[2][2]);
	mHahenFX[1]->setPosPosptrs(&mJointPositions[1][1], &mJointPositions[1][2]);
	mHahenFX[2]->setPosPosptrs(&mJointPositions[3][1], &mJointPositions[3][2]);

    mSmokeFX[0]->m_position = &mJointPositions[0][1];
	mSmokeFX[1]->m_position = &mJointPositions[0][2];

	SysShape::Joint* joint = m_model->getJoint("kosi");
	mAppearHahenFX->m_mtx   = joint->getWorldMatrix();
	mDeadBombFX->setMtxptr(joint->getWorldMatrix()->m_matrix.mtxView);
}

void Obj::createOnGroundEffect(int footIdx, WaterBox* wbox)
{
	Vector3f effectPos = mJointPositions[footIdx][3];

    if (wbox) {
        effectPos.y = *wbox->getSeaHeightPtr();

        efx::ArgScale fxArg(effectPos, 0.3f);
        efx::TEnemyDownWat waterWalk;

        waterWalk.create(&fxArg);

        PSM::SeSound* sound = PSStartSoundVec(PSSE_EV_ITEM_LAND_WATER1_M, (Vec*)&mJointPositions[footIdx][3]);
        if (sound) {
            sound->setPitch(1.2f, 0, SOUNDPARAM_Unk0);
        }
    } else {
        efx::Arg fxArg(effectPos);
        efx::TEnemyDownSmoke walk;
        walk._0C = 0.3f;

        walk.create(&fxArg);
    }

    if (mIsSmoking) {
        int jointIdx = 0;
        if (footIdx == 2) {
            jointIdx = 0;
        } else if (footIdx == 1) {
            jointIdx = 1;
        } else if (footIdx == 3) {
            jointIdx = 2;
        }

        mHahenFX[jointIdx]->create(nullptr);
    }

    PSStartSoundVec(PSSE_EN_HOUDAI_BAREFOOT, (Vec*)&mJointPositions[footIdx][3]);
}

void Obj::createOffGroundEffect(int footIdx, WaterBox* wbox)
{
	f32 healthRatio = m_health / C_PARMS->m_general.m_health.m_value;

    if (healthRatio < 0.175f) {
        getJAIObject()->startSound(PSSE_EN_HOUDAI_RAISE_B3, 0);
    } else if (healthRatio < 0.35f) {
        getJAIObject()->startSound(PSSE_EN_HOUDAI_RAISE_B2, 0);
    } else {
        getJAIObject()->startSound(PSSE_EN_HOUDAI_RAISE_B1, 0);
    }
}

void Obj::updatePinchLife()
{
	if (!isAlive()) {
		return;
	}

	f32 healthRatio = m_health / C_PARMS->m_general.m_health.m_value;
	if (mIsSmoking) {
		if (healthRatio > 0.35f) {
			mIsSmoking = false;
		}

	} else if (healthRatio < 0.35f) {
		mIsSmoking = true;
		getJAIObject()->startSound(PSSE_EN_DAMAGUMO_SMOKE, 0);
	}
}

void Obj::startPinchJointEffect() { }

void Obj::finishPinchJointEffect() { }

void Obj::createHoudaiDeadEffect()
{
	for (int i = 0; i < 4; i++) {
		for (int j = 1; j < 3; j++) {
			efx::Arg fxArg(mJointPositions[i][j]);
			efx::TDamaDeadBomb deadBombFX;
			deadBombFX.create(&fxArg);
		}
	}

	for (int i = 0; i < 3; i++) {
		mDeadElecAFX[i]->create(nullptr);
	}
}

void Obj::createAppearEffect() { }

void Obj::startSteamEffect(bool doBodySteam) { }

void Obj::finishSteamEffect() { }

void Obj::startChimneyEffect() { }

void Obj::finishChimneyEffect() { }

void Obj::effectDrawOn()
{
	for (int i = 0; i < 3; i++) {
		mHahenFX[i]->endDemoDrawOn();
		mDeadElecAFX[i]->endDemoDrawOn();
	}

	mAppearHahenFX->endDemoDrawOn();

	for (int i = 0; i < 4; i++) {
		mAppearHahenFootFX[i]->endDemoDrawOn();
	}

	mDeadBombFX->endDemoDrawOn();

	mShotGunMgr->effectDrawOn();
}

void Obj::effectDrawOff()
{
	for (int i = 0; i < 3; i++) {
		mHahenFX[i]->startDemoDrawOff();
		mDeadElecAFX[i]->startDemoDrawOff();
	}

	mAppearHahenFX->startDemoDrawOff();

	for (int i = 0; i < 4; i++) {
		mAppearHahenFootFX[i]->startDemoDrawOff();
	}

	mDeadBombFX->startDemoDrawOff();

	mShotGunMgr->effectDrawOff();
}

} // namespace Houdai    
} // namespace Game