#include "Game/Entities/KingChappy.h"

namespace Game {
namespace KingChappy {

Sys::MatLoopAnimator Obj::sMatAnimator;

// startMatAnimation__Q34Game10KingChappy3ObjFv
void Obj::startMatAnimation()
{
    sMatAnimator.start(C_MGR->mTexAnimation);
}

void Obj::changeMaterial()
{
    J3DModel* model = m_model->getJ3DModel();
    J3DModelData* modelData = model->m_modelData;
    model->calcMaterial();

    if (isAlive()) {
        sMatAnimator.animate(30.0f);
    }

    // diff material
    for (u16 i = 0; i < modelData->m_materialTable.m_count1; i++) {
		j3dSys.m_matPacket = &model->m_matPackets[i];
		J3DMaterial* mat  = modelData->m_materialTable.m_materials1[i];
		mat->diff(j3dSys.m_matPacket->_2C->_34);
	}
}

void Obj::getShadowParam(ShadowParam& param)
{
	param.m_boundingSphere.m_radius = 0.0f;
	param.m_size                    = 0.0f;
}

// crushPikmin__Q34Game10KingChappy3ObjFPQ24Game4Piki
void Obj::crushPikmin(Piki* piki)
{
    if (piki->m_pikiKind == Bulbmin) {
        InteractBury bury(this, C_GENERALPARMS.m_attackDamage.m_value);
        piki->stimulate(bury);       
        return;
    }

    InteractPress press(this, C_GENERALPARMS.m_attackDamage.m_value, nullptr);
    piki->stimulate(press);
}

} // namespace KingChappy
} // namespace Game
