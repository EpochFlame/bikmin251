#include "Game/Entities/QueenMongus.h"
#include "Game/Entities/Baby.h"
#include "Game/generalEnemyMgr.h"
#include "LoadResource.h"

namespace Game {
namespace Queen {

// this is the most ckit shit ever but idrc anymore
void Obj::createBabyChappy()
{
	EnemyTypeID::EEnemyTypeID birthEnemyID = EnemyTypeID::EnemyID_Baby;
	if (getEnemyTypeID() == EnemyTypeID::EnemyID_QueenMongus) {
		birthEnemyID = EnemyTypeID::EnemyID_BabyMongus;
	}

	Baby::Mgr* babyMgr = static_cast<Baby::Mgr*>(generalEnemyMgr->getEnemyMgr(birthEnemyID));
	if (babyMgr) {
		EnemyBirthArg birthArg;
		birthArg.m_position = m_model->getJoint("body_end")->getWorldMatrix()->getColumn(3);
		birthArg.m_faceDir  = PI + getFaceDir();

		Baby::Obj* baby = static_cast<Baby::Obj*>(babyMgr->birth(birthArg));
		if (baby) {
			f32 angle           = birthArg.m_faceDir;
			Vector3f vel = Vector3f(C_GENERALPARMS.m_fp14.m_value * sinf(angle), 0.0f, C_GENERALPARMS.m_fp14.m_value * cosf(angle));
			baby->init(nullptr);
			baby->setVelocity(vel);
			baby->m_simVelocity = vel;
		}
	}
}
	
} // namespace Queen

namespace QueenMongus {

Mgr::Mgr(int objLimit, u8 modelType)
    : Queen::Mgr(objLimit, modelType)
{
}

void Mgr::doAlloc() { init(new Queen::Parms); }

void Mgr::createObj(int count) { m_obj = new Obj[count]; }

EnemyBase* Mgr::getEnemy(int idx) { return &m_obj[idx]; }

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

// idc this goes here
namespace BabyMongus {

void Obj::initMouthSlots() 
{
	m_mouthSlots.alloc(1);
	m_mouthSlots.setup(0, m_model, "kamujnt");
	for (int i = 0; i < m_mouthSlots.m_max; i++) {
		m_mouthSlots.getSlot(i)->m_radius = 15.0f;
	}
}

Mgr::Mgr(int objLimit, u8 modelType)
    : Baby::Mgr(objLimit, modelType)
{
}

void Mgr::doAlloc() { init(new Baby::Parms); }

void Mgr::createObj(int count) { m_obj = new Obj[count]; }

EnemyBase* Mgr::getEnemy(int idx) { return &m_obj[idx]; }

} // namespace BabyMongus
} // namespace Game
