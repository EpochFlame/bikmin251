#include "Game/Entities/MiniHoudai.h"
#include "Game/generalEnemyMgr.h"
#include "JSystem/JUT/JUTNameTab.h"
#include "LoadResource.h"

namespace Game {
namespace MiniHoudai {

/*
 * --INFO--
 * Address:	802EBD54
 * Size:	000050
 */
Mgr::Mgr(int objLimit, u8 modelType)
    : EnemyMgrBase(objLimit, modelType)
{
	m_name = "チビホウダイマネージャ"; // little houdai manager
}

/*
 * --INFO--
 * Address:	802EBDA4
 * Size:	0000D8
 */
void Mgr::loadModelData()
{
	int ids[2] = { EnemyTypeID::EnemyID_MiniHoudai, EnemyTypeID::EnemyID_FminiHoudai };

	for (int i = 0; i < 2; i++) {
		EnemyMgrBase* mgr = generalEnemyMgr->getEnemyMgr(ids[i]);
		if (mgr) {
			J3DModelData* storedModelData = mgr->getJ3DModelData();

			if (storedModelData) {
				m_modelData = storedModelData;
				return;
			}
		}
	}

	EnemyMgrBase::loadModelData();
	J3DShape* shape;
	for (u16 j = 0; j < m_modelData->getShapeCount(); j++) {
		shape          = m_modelData->m_shapeTable.m_items[j];
		shape->m_flags = (shape->m_flags & (~0xF000)) | 0x2000;
	}
}

/*
 * --INFO--
 * Address:	802EBE7C
 * Size:	000090
 */
void Mgr::loadAnimData()
{
	int ids[2] = {
		EnemyTypeID::EnemyID_MiniHoudai,
		EnemyTypeID::EnemyID_FminiHoudai,
	};

	for (int i = 0; i < 2; i++) {
		EnemyMgrBase* mgr = generalEnemyMgr->getEnemyMgr(ids[i]);
		if (mgr) {
			SysShape::AnimMgr* storedAnimMgr = mgr->m_animMgr;
			if (storedAnimMgr) {
				m_animMgr = storedAnimMgr;
				return;
			}
		}
	}

	EnemyMgrBase::loadAnimData();
}

void Mgr::loadTexData()
{
	SysShape::Model::enableMaterialAnim(m_modelData, 0);
	void* btkFile = nullptr;
	LoadResource::Arg loadArgBtk("/enemy/data/Hanachirashi/hanachirashi_model.btk");
	LoadResource::Node* resourceBtk = gLoadResourceMgr->load(loadArgBtk);
	if (resourceBtk) {
		btkFile = resourceBtk->_30;
	}
	P2ASSERTLINE(__LINE__, btkFile);

	mTexAnimation = new Sys::MatTexAnimation;
	mTexAnimation->attachResource(btkFile, m_modelData);

	void* brkFile = nullptr;
	LoadResource::Arg loadArgBrk("/enemy/data/Hanachirashi/hanachirashi_model.brk");
	LoadResource::Node* resourceBrk = gLoadResourceMgr->load(loadArgBrk);
	if (resourceBrk) {
		brkFile = resourceBrk->_30;
	}
	P2ASSERTLINE(__LINE__, brkFile);

	mTevRegAnimation = new Sys::MatTevRegAnimation;
	mTevRegAnimation->attachResource(brkFile, m_modelData);
}

SysShape::Model* Mgr::createModel()
{
    SysShape::Model* model = new SysShape::Model(m_modelData, 0x80000, m_modelType);
	P2ASSERTLINE(121, model);

	for (u16 i = 0; i < m_modelData->getMaterialCount1(); i++) {
		const char* name = m_modelData->m_materialTable._0C->getName(i);
		if (!strcmp(name, "mat1")) {
			model->m_j3dModel->m_matPackets[i]._2C->newDifferedDisplayList(0x01000200);
		}
	}

	model->updateModel();
	return model;
}

} // namespace MiniHoudai
} // namespace Game
