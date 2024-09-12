#include "Game/Entities/ItemPikihead.h"
#include "Game/PikiMgr.h"
#include "JSystem/J3D/J3DModelLoader.h"

namespace Game {
namespace ItemPikihead {

// allocModels__Q34Game12ItemPikihead3MgrFv
void Mgr::allocModels()
{
	m_monoObjectMgr.alloc(101);
	onAlloc();
}

void Mgr::onLoadResources()
{
    m_modelData[0] = pikiMgr->m_pikiModels[7];

	loadArchive("arc.szs");
	JKRArchive* arc = openTextArc("texts.szs");
	loadAnimMgr(arc, "pikiheadAnimMgr.txt");
	closeTextArc(arc);
}

int getEmptyIndex(MonoObjectMgr<Item>* mgr)
{
    if (!pikiMgr) return mgr->getEmptyIndex();

	for (int i = 0; i < mgr->m_max; i++) {
		if (mgr->m_openIds[i] && pikiMgr->m_openIds[i]) {
			return i;
		}
	}
	return -1;
}

// birthPikiHead__Q24Game12ItemPikiheadFP41MonoObjectMgr<Q34Game12ItemPikihead4Item>
Item* birthPikiHead(MonoObjectMgr<Item>* mgr)
{
    int index = getEmptyIndex(mgr);
	if (index == -1)
		return nullptr;

	Item* result = mgr->m_array;
	result               = &result[index];

	mgr->m_openIds[index] = false;
	mgr->m_activeCount++;
	return result;
}

// createPikiheadModel__Q24Game12ItemPikiheadFPQ34Game12ItemPikihead4Item
SysShape::Model* createPikiheadModel(Item* item)
{
    SysShape::Model* model = pikiMgr->createModel(7, item->_184);

    JKRSolidHeap* solidHeap = pikiMgr->m_modelMgr->m_heaps[item->_184];
    sys->startChangeCurrentHeap(solidHeap);
    
	mgr->onCreateModel(model);

    sys->endChangeCurrentHeap();

	return model;
}

} // namespace ItemPikiHead

int PikiMgr::getSharedEmptyIndex()
{
    if (!ItemPikihead::mgr) return getEmptyIndex();

    for (int i = 0; i < m_max; i++) {
		if (m_openIds[i] && ItemPikihead::mgr->m_monoObjectMgr.m_openIds[i]) {
			return i;
		}
	}
	return -1;
}

// birthPikiModel__Q24Game7PikiMgrFv
Piki* PikiMgr::birthPikiModel() 
{
	int index = getSharedEmptyIndex();
	if (index != -1) {
		Piki* result = &m_array[index];
		m_openIds[index] = false;
		m_activeCount++;
		return result;
	}
	return nullptr;
}
 
// createModelMgr__4GameFiPP12J3DModelDataiUlUlP30IDelegate1<PQ28SysShape5Model>
SysShape::ModelMgr* createModelMgr(int, J3DModelData**, int, u32 flags, u32 viewNum, IDelegate1<SysShape::Model*>* delegate)
{
    return new SysShape::ModelMgr(8, pikiMgr->m_pikiModels, 101, flags, viewNum, delegate);
}

void PikiMgr::loadBmd(int id, char* name)
{
	char pathbuf[256];
	sprintf(pathbuf, "piki_model/%s.bmd", name);
	J3DModelData* data = J3DModelLoaderDataBase::load(m_modelArchive->getResource(pathbuf), 0x60010);
	{
		const u32 lightObjNum = 0;
		const u32 texGenNum   = 0;
		const u32 texCoordNum = 4;
		const u32 tevStageNum = 0;
		u32 dlFlags           = CREATE_DIFF_FLAG(lightObjNum, texGenNum, texCoordNum, tevStageNum);
		data->newSharedDisplayList(dlFlags);
		data->makeSharedDL();
	}

	m_pikiModels[id] = data;
}

// loadPikiHead__Q24Game7PikiMgrFv
void PikiMgr::loadPikiHead()
{
    JKRArchive* arc = JKRArchive::mount("user/Kando/objects/pikihead/arc.szs", JKRArchive::EMM_Mem, sys->mSysHeap, JKRArchive::EMD_Head);

    J3DModelData* data = J3DModelLoaderDataBase::load(arc->getResource("pikihead.bmd"), 0x20000);
	{
		const u32 lightObjNum = 0;
		const u32 texGenNum   = 0;
		const u32 texCoordNum = 4;
		const u32 tevStageNum = 0;
		u32 dlFlags           = CREATE_DIFF_FLAG(lightObjNum, texGenNum, texCoordNum, tevStageNum);
		data->newSharedDisplayList(dlFlags);
	}

    m_pikiModels[7] = data;
}

void PikiMgr::createModelCallback(SysShape::Model*)
{
    // do nothing
}

SysShape::Model* PikiMgr::createModel(int id, int num)
{
    SysShape::Model* model = m_modelMgr->createModel(id, num);
	if (id < 7) {
		model->m_j3dModel->calcMaterial();
		model->m_j3dModel->makeDL();
		model->m_j3dModel->lock();
	}
	return model;
}

} // namespace Game
