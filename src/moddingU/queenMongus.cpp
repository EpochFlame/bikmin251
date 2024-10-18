#include "Game/Entities/QueenMongus.h"
#include "LoadResource.h"

namespace Game {
namespace QueenMongus {

Mgr::Mgr(int objLimit, u8 modelType)
    : Queen::Mgr(objLimit, modelType)
{

}

void Mgr::doAlloc() { init(new Queen::Parms); }

void Mgr::createObj(int count) { m_obj = new Obj[count]; }

EnemyBase*Mgr:: getEnemy(int idx) { return &m_obj[idx]; }

void Mgr::loadTexData()
{
	SysShape::Model::enableMaterialAnim(m_modelData, 0);
	void* btkFile = nullptr;
	LoadResource::Arg loadArgBtk("/enemy/data/QueenMongus/queenchappy_model.btk");
	LoadResource::Node* resourceBtk = gLoadResourceMgr->load(loadArgBtk);
	if (resourceBtk) {
		btkFile = resourceBtk->_30;
	}
	P2ASSERTLINE(108, btkFile);

	m_texAnimation = new Sys::MatTexAnimation;
	m_texAnimation->attachResource(btkFile, m_modelData);
}
    
} // namespace QueenMongus
} // namespace Game
