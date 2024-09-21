#include "Game/Entities/KingChappy.h"
#include "Game/generalEnemyMgr.h"
#include "LoadResource.h"
#include "JSystem/JUT/JUTNameTab.h"
#include "LoadResource.h"

namespace Game {
namespace KingChappy {

static const char kingChappyMgrName[] = "kingChappyMgr";

/*
 * --INFO--
 * Address:	8035C288
 * Size:	000050
 */
Mgr::Mgr(int objLimit, u8 modelType)
    : EnemyMgrBase(objLimit, modelType)
{
	m_name = "キングチャッピーマネージャー"; // king chappy manager
}

/*
 * --INFO--
 * Address:	8035C2D8
 * Size:	000048
 */
void Mgr::doAlloc() { init(new Parms); }

/*
 * --INFO--
 * Address:	8035C980
 * Size:	000020
 */
EnemyBase* Mgr::birth(EnemyBirthArg& birthArg) { return EnemyMgrBase::birth(birthArg); }

/*
 * --INFO--
 * Address:	8035C9A0
 * Size:	000020
 */
SysShape::Model* Mgr::createModel() 
{ 	
	SysShape::Model* model = new SysShape::Model(m_modelData, 0x80000, m_modelType);
	P2ASSERTLINE(__LINE__, model);

	for (u16 i = 0; i < m_modelData->getMaterialCount1(); i++) {
		const char* name = m_modelData->m_materialTable.m_materialNames->getName(i);
		if (!strcmp(name, "gmp_body") || !strcmp(name, "gmp_body_v_x")) {
			model->m_j3dModel->m_matPackets[i]._2C->newDifferedDisplayList(0x01000200);
		}
	}

	model->updateModel();
	return model;
}

/*
 * --INFO--
 * Address:	8035C9C0
 * Size:	0000EC
 */
void Mgr::requestState(Obj* kingChappy, int stateID)
{
	for (int i = 0; i < getMaxObjects(); i++) {
		Obj* enemy = static_cast<Obj*>(getEnemy(i));
		P2ASSERTLINE(65, enemy);
		if (enemy->isAlive() && enemy != kingChappy && stateID != enemy->getStateID() && enemy->getStateID() != KINGCHAPPY_Dead) {
			if (enemy->forceTransit(stateID)) {
				return;
			}
		}
	}
}

void Mgr::loadTexData()
{
	SysShape::Model::enableMaterialAnim(m_modelData, 0);
	void* btkFile = nullptr;
	LoadResource::Arg loadArgBtk("/enemy/data/KingChappy/emperor_model.btk");
	LoadResource::Node* resourceBtk = gLoadResourceMgr->load(loadArgBtk);
	if (resourceBtk) {
		btkFile = resourceBtk->_30;
	}
	P2ASSERTLINE(__LINE__, btkFile);

	mTexAnimation = new Sys::MatTexAnimation;
	mTexAnimation->attachResource(btkFile, m_modelData);
}

} // namespace KingChappy
} // namespace Game
