#include "Game/Entities/KingChappy.h"

namespace Game {
namespace KingChappy {

// startMatAnimation__Q24Game10KingChappyFPQ34Game10KingChappy3Obj
void startMatAnimation(Obj* obj)
{
    obj->mMatAnimator = new Sys::MatLoopAnimator;
    Mgr* mgr = static_cast<Mgr*>(obj->m_mgr);
    obj->mMatAnimator->start(mgr->mTexAnimation);
}

void Obj::changeMaterial()
{
    J3DModel* model = m_model->getJ3DModel();
    J3DModelData* modelData = model->m_modelData;
    model->calcMaterial();

    if (isAlive()) {
        OSReport("animating!\n");
        mMatAnimator->animate(30.0f);
    }

    // diff material
    for (u16 i = 0; i < modelData->m_materialTable.m_count1; i++) {
		j3dSys.m_matPacket = &model->m_matPackets[i];
		J3DMaterial* mat  = modelData->m_materialTable.m_materials1[i];
		mat->diff(j3dSys.m_matPacket->_2C->_34);
	}
}

} // namespace KingChappy
} // namespace Game
