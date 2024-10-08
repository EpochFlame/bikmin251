#include "Game/EnemyBase.h"
#include "Game/EnemyAnimKeyEvent.h"
#include "Game/Entities/UmiMushi.h"
#include "Game/EnemyFunc.h"
#include "Game/rumble.h"
#include "Game/Navi.h"
#include "PSM/EnemyBoss.h"
#include "PSSystem/PSMainSide_ObjSound.h"

namespace Game {
namespace UmiMushi {

void Obj::onInit(CreatureInitArg* initArg)
{
	EnemyBase::onInit(initArg);
	resetEvent(0, EB_9);
	m_headJoint = m_model->getJoint("head_joint1");
	P2ASSERTLINE(124, m_headJoint);
	m_targetNavi = nullptr;
	_2BC         = m_homePosition;
	_2E0         = 0;
	_2E4         = m_homePosition;
	_2F0         = 0;
	_2F4         = 0;
	_2FC         = 0.0f;
	_2DC         = 0;
	_300         = 0;
	_2C8         = -1;

	m_normalColor2.r = 0xff40;
	m_normalColor2.g = 0xff40;
	m_normalColor2.b = 0xffff;

	m_olimarColor1.r = 0xff7f;
	m_olimarColor1.g = 0xff7f;
	m_olimarColor1.b = 0xff7f;

	m_olimarColor2.r = 0xff62;
	m_olimarColor2.g = 0xff62;
	m_olimarColor2.b = 0xff62;

	m_louieColor1.r = 0xffa5;
	m_louieColor1.g = 0x0000;
	m_louieColor1.b = 0xffff;

	m_louieColor2.r = 0xff6d;
	m_louieColor2.g = 0x0000;
	m_louieColor2.b = 0xffa8;

	m_normalColor1.r = 0xffff;
	m_normalColor1.g = 0x0000;
	m_normalColor1.b = 0x0000;

	_31C = m_normalColor1;
	_314 = m_normalColor1;

	curU = nullptr;

	m_fsm->start(this, 1, nullptr); // fix this later - Drought Ender

	P2ASSERTLINE(157, _354);
	_354->start(C_MGR->m_texAnimation);

	P2ASSERTLINE(160, m_shadowMgr);
	m_shadowMgr->init();

	J3DModelData* modelData = m_model->m_j3dModel->m_modelData;
	P2ASSERTLINE(166, modelData);

	u16 matIdx = modelData->m_materialTable.m_materialNames->getIndex("cc_mat1_v");
	_310       = modelData->m_materialTable.m_materials1[matIdx];

	P2ASSERTLINE(171, _310);

	if (m_bloysterType == EnemyTypeID::EnemyID_UmiMushi) {
		PSM::EnemyMidBoss* bossSoundObj = static_cast<PSM::EnemyMidBoss*>(m_soundObj);
		checkMidBoss(bossSoundObj);
		bossSoundObj->setAppearFlag(false);
		bossSoundObj->_118 = true;
	} else {
		setParameters();
		float health = C_PROPERPARMS.m_blindHealth.m_value;
		m_health     = health;
		m_maxHealth  = health;
		_35C         = 0.45f;
		P2ASSERTLINE(189, m_model);
		J3DModelData* modelData                                     = m_model->m_j3dModel->m_modelData;
		m_eyeJointIdx                                               = m_model->getJointIndex("eyes_joint1");
		m_weakJointIdx                                              = m_model->getJointIndex("weak_joint2");
		modelData->m_jointTree.m_joints[m_eyeJointIdx]->m_function  = UmiMushi::eyeScaleCallBack;
		modelData->m_jointTree.m_joints[m_weakJointIdx]->m_function = UmiMushi::weakScaleCallBack;
	}
	m_dropGroup = 0;
	_38C        = m_position;
	P2ASSERTLINE(212, _364);
	efx::Arg efxArg(_38C);
	_364->create(&efxArg);
	_364->setGlobalScale(m_scaleModifier);
	P2ASSERTLINE(218, _368);
	P2ASSERTLINE(219, _36C);
	Matrixf* modelMtx = m_model->getJoint("weak_joint2")->getWorldMatrix();
	_368->setMtxptr((PSQuaternion*)modelMtx);
	_36C->setMtxptr((PSQuaternion*)modelMtx);

	P2ASSERTLINE(225, _370[0]);
	P2ASSERTLINE(226, _370[1]);
	// random newline here bc why not
	P2ASSERTLINE(228, _378[0]);
	P2ASSERTLINE(229, _378[1]);

	modelMtx = m_model->getJoint("ef_eye_r")->getWorldMatrix();
	_370[0]->setMtxptr((PSQuaternion*)modelMtx);
	_378[0]->setMtxptr((PSQuaternion*)modelMtx);

	modelMtx = m_model->getJoint("ef_eye_l")->getWorldMatrix();
	_370[1]->setMtxptr((PSQuaternion*)modelMtx);
	_378[1]->setMtxptr((PSQuaternion*)modelMtx);

	P2ASSERTLINE(239, m_efxEat);
	P2ASSERTLINE(240, _384);

	_388 = m_model->getJoint("bero_joint1")->getWorldMatrix();

	m_efxEat->m_mtx = _388;
	_384->m_mtx     = _388;
}
	
void StateAttack::exec(EnemyBase* enemy)
{
	if (mIsTongueActive) {
		if (EnemyFunc::eatPikmin(enemy, nullptr) > 0) {
			mTongueHasPiki = true;
		}
	}

	if (enemy->m_curAnim->m_isRunning) {
		switch (enemy->m_curAnim->m_type) {
		case KEYEVENT_2:
			// probably commented out code - required to match though.
			break;

		case KEYEVENT_3:
			f32 rate      = CG_GENERALPARMS(enemy).m_shakeRateMaybe.m_value;
			f32 knockback = CG_GENERALPARMS(enemy).m_shakeKnockback.m_value;
			f32 damage    = CG_GENERALPARMS(enemy).m_shakeDamage.m_value;

			EnemyFunc::flickStickPikmin(enemy, rate, knockback, damage, FLICK_BACKWARD_ANGLE, nullptr);
			enemy->m_toFlick = 0.0f;
			mIsTongueActive = true;
			break;

		case KEYEVENT_4:
			OBJ(enemy)->attackEffect();
			if (enemy->getEnemyTypeID() == EnemyTypeID::EnemyID_UmiMushi) {
				Vector3f pos = enemy->getPosition();
				rumbleMgr->startRumble(RUMBLETYPE_Fixed12, pos, RUMBLEID_Both);
			}
			break;

		case KEYEVENT_5:
			if (CG_PARMS(enemy)->_A13) {
				Iterator<Navi> iter(naviMgr);
				CI_LOOP(iter)
				{
					Navi* navi = *iter;
					for (int i = 0; i < enemy->getMouthSlots()->m_max; i++) {
						MouthCollPart* slot = enemy->getMouthSlots()->getSlot(i);
						Vector3f slotPos;
						slot->getPosition(slotPos);
						Vector3f naviPos = navi->getPosition();
						Vector3f sep     = Vector3f(slotPos.y - naviPos.y, slotPos.z - naviPos.z, slotPos.x - naviPos.x); // why.
						f32 dist         = _length2(sep);
						if (dist < slot->m_radius) {
							InteractAttack attack(enemy, CG_GENERALPARMS(enemy).m_attackDamage.m_value, nullptr);
							navi->stimulate(attack);
						}
					}
				}
			}
			break;

		case KEYEVENT_6:
			mIsTongueActive = false;
			break;

		case KEYEVENT_END:
			if (mTongueHasPiki) {
				transit(enemy, UMIMUSHI_Eat, nullptr);
			} else {
				transit(enemy, UMIMUSHI_Wait, nullptr);
			}
			break;
		}
	}
}

void StateEat::exec(EnemyBase* enemy)
{
	if (enemy->m_curAnim->m_isRunning && enemy->m_curAnim->m_type == KEYEVENT_END) {
		if (enemy->m_health <= 0.0f) {
			transit(enemy, UMIMUSHI_Dead, nullptr);
			return;
		}

		EnemyFunc::swallowPikmin(enemy, 300.0f, nullptr);
		transit(enemy, UMIMUSHI_Wait, nullptr);
	}
}

void Obj::changeMaterial()
{
	J3DModel* model = m_model->m_j3dModel;
	_310->m_tevBlock->setTevColor(0, _314);
	model->calcMaterial();
	_354->animate(30.0f);


	J3DModelData* modelData = model->m_modelData;
	for (int i = 0; i < modelData->m_materialTable.m_count1; i++) {
		j3dSys.m_matPacket = &model->m_matPackets[i];
		modelData->m_materialTable.m_materials1[i]->diff(j3dSys.m_matPacket->_2C->_34);
	}
}

} // namespace UmiMushi
} // namespace Game
