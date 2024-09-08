#include "Game/Entities/MiniHoudai.h"
#include "LoadResource.h"

namespace Game {
namespace NormMiniHoudai {

static const char normMiniHoudaiMgrName[] = "246-NormMiniHoudaiMgr";

/*
 * --INFO--
 * Address:	803011F8
 * Size:	000050
 */
Mgr::Mgr(int objLimit, u8 modelType)
    : MiniHoudai::Mgr(objLimit, modelType)
{
	m_name = "ノーマルチビホウダイマネージャ"; // normal little houdai manager
}

/*
 * --INFO--
 * Address:	80301248
 * Size:	000048
 */
void Mgr::doAlloc() { init(new MiniHoudai::Parms); }

/*
 * --INFO--
 * Address:	8030136C
 * Size:	000060
 */
void Mgr::createObj(int count) { m_obj = new Obj[count]; }

/*
 * --INFO--
 * Address:	803014B8
 * Size:	000010
 */
EnemyBase* Mgr::getEnemy(int index) { return &m_obj[index]; }

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

} // namespace NormMiniHoudai
} // namespace Game
