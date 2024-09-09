#include "Game/Entities/MiniHoudai.h"

namespace Game {
namespace NormMiniHoudai {

/*
 * --INFO--
 * Address:	803015F8
 * Size:	000090
 */
Obj::Obj() 
{ 
    mMatAnimators = new Sys::MatLoopAnimator[2];
}

void Obj::onInit(CreatureInitArg* arg)
{
    MiniHoudai::Obj::onInit(arg);
    mMatAnimators[0].start(C_MGR->mTexAnimation);
    mMatAnimators[1].start(C_MGR->mTevRegAnimation);
}

void Obj::changeMaterial()
{
    J3DModelData* modelData = nullptr;
	J3DModel* model         = m_model->m_j3dModel;
	modelData               = model->m_modelData;

	model->calcMaterial();

	if (isAlive()) {
		mMatAnimators[0].animate(30.0f);
		mMatAnimators[1].animate(30.0f);
	}

	for (u16 i = 0; i < modelData->m_materialTable.m_count1; i++) {
		j3dSys.m_matPacket = &model->m_matPackets[i];
		J3DMaterial* mat  = modelData->m_materialTable.m_materials1[i];
		mat->diff(j3dSys.m_matPacket->_2C->_34);
	}
}

} // namespace NormMiniHoudai
} // namespace Game
