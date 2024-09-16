#include "Game/Entities/Houdai.h"

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

    if (sMatAnimator._08 < sMatAnimator.m_animation->getFrameMax() - 1 && m_FSM->getCurrID(this) == HOUDAI_Land) {
        sMatAnimator.animate(30.0f);
    }

    // diff material
    for (u16 i = 0; i < modelData->m_materialTable.m_count1; i++) {
		j3dSys.m_matPacket = &model->m_matPackets[i];
		J3DMaterial* mat  = modelData->m_materialTable.m_materials1[i];
		mat->diff(j3dSys.m_matPacket->_2C->_34);
	}
}

} // namespace Houdai    
} // namespace Game
