#include "Game/Entities/PikiBaby.h"
#include "LoadResource.h"

namespace Game {
namespace PikiBaby {

Mgr::Mgr(int objLimit, u8 modelType)
    : EnemyMgrBase(objLimit, modelType)
{
    m_name = "";
}

SysShape::Model* Mgr::createModel()
{
    SysShape::Model* model = new SysShape::Model(m_modelData, 0x80000, m_modelType);
	P2ASSERTLINE(__LINE__, model);

	J3DModel* j3dModel = model->m_j3dModel;
	for (u16 i = 0; i < m_modelData->getMaterialCount1(); i++) {
		const char* name = m_modelData->m_materialTable.m_materialNames->getName(i);
		if (!strcmp(name, "body1")) {
			j3dModel->m_matPackets[i]._2C->newDifferedDisplayList(0x01000000);
		}
	}

	model->updateModel();
	return model;
}

void Mgr::loadTexData()
{
	SysShape::Model::enableMaterialAnim(m_modelData, 0);
	void* brkFile = nullptr;
	LoadResource::Arg loadArgBrk("/enemy/data/PikiBabyRed/piki_dead.brk");
	LoadResource::Node* resourceBrk = gLoadResourceMgr->load(loadArgBrk);
	if (resourceBrk) {
		brkFile = resourceBrk->_30;
	}
	P2ASSERTLINE(__LINE__, brkFile);

	mTevRegAnim = new Sys::MatTevRegAnimation;
	mTevRegAnim->attachResource(brkFile, m_modelData);
}
        
} // namespace PikiBaby

namespace PikiBabyRed {

Mgr::Mgr(int objLimit, u8 modelType)
    : PikiBaby::Mgr(objLimit, modelType)
{
    m_name = "";
}

void Mgr::doAlloc() { init(new Baby::Parms); }

void Mgr::createObj(int count) { m_obj = new Obj[count]; }

EnemyBase*Mgr:: getEnemy(int idx) { return &m_obj[idx]; }

} // namespace PikiBabyRed


namespace PikiBabyYellow {

Mgr::Mgr(int objLimit, u8 modelType)
    : PikiBaby::Mgr(objLimit, modelType)
{
    m_name = "";
}

void Mgr::doAlloc() { init(new Baby::Parms); }

void Mgr::createObj(int count) { m_obj = new Obj[count]; }

EnemyBase*Mgr:: getEnemy(int idx) { return &m_obj[idx]; }
	
} // namespace PikiBabyYellow

namespace PikiBabyBlue {

Mgr::Mgr(int objLimit, u8 modelType)
    : PikiBaby::Mgr(objLimit, modelType)
{
    m_name = "";
}

void Mgr::doAlloc() { init(new Baby::Parms); }

void Mgr::createObj(int count) { m_obj = new Obj[count]; }

EnemyBase*Mgr:: getEnemy(int idx) { return &m_obj[idx]; }
	
} // namespace PikiBabyBlue
} // namespace Game
