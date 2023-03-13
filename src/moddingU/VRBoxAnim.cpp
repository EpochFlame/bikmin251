#include "Game/mapParts.h"
#include "JSystem/J3D/J3DFileBlock.h"
#include "LoadResource.h"

namespace Game
{

CNode CaveVRBox::texAnims;
CNode CaveVRBox::tevAnims;
int countBrk = 0;
int countBtk = 0;
Sys::MatLoopAnimator* CaveVRBox::animators[2];

void CaveVRBox::clearNodes() {
    CNode* node = texAnims.m_child;
    while (node)
    {
        CNode* copyPtr = node;
        node = node->m_next;
        delete copyPtr;
    }

    node = tevAnims.m_child;
    while (node)
    {
        CNode* copyPtr = node;
        node = node->m_next;
        delete copyPtr;
    }
    
}

void CaveVRBox::loadResources(JKRArchive* rarc) {
    OSReport("loading %x... \n", this);
    void* bmd = rarc->getResource("model.bmd");
    J3DModelData* model = J3DModelLoaderDataBase::load(bmd, 0x20000000);
    model->newSharedDisplayList(0x40000);
    model->makeSharedDL();
    OSReport("model stuff\n");
    m_model = new SysShape::Model(model, 0, 2);
    Mtx identityMatrix;
    PSMTXIdentity(identityMatrix);
    PSMTXCopy(m_model->m_j3dModel->m_posMtx, identityMatrix);
    OSReport("mtx stuff\n");
    m_model->m_j3dModel->calc();
    m_model->m_j3dModel->calcMaterial();
    OSReport("calced\n");
    m_model->enableMaterialAnim(0);
    OSReport("made materials...\n");
	
    clearNodes();
    OSReport("cleaned nodes\n");
    countBtk = 0;
    for (int i = 0; i < 100; i++) {

        char filename[128];
        sprintf(filename, "texanm_%d.btk", i);

        void* btkFile = rarc->getResource(filename);
        

        if (btkFile) {
            TexNode* node = new TexNode;
            texAnims.add(node);
            node->m_anim->attachResource(btkFile, m_model->m_j3dModel->m_modelData);
            countBtk++;
        }
    }

    OSReport("Made btks...\n");

    countBrk = 0;
    for (int i = 0; i < 100; i++) { 

        char filename[128];
        sprintf(filename, "tevanm_%d.brk", i);

        void* brkFile = rarc->getResource(filename);
        if (brkFile) {
            TevNode* node = new TevNode;
            tevAnims.add(node);
            node->m_anim->attachResource(brkFile, m_model->m_j3dModel->m_modelData);
            countBrk++;
        }
    }

    OSReport("Made brks...\n");

    animators[0] = new Sys::MatLoopAnimator[countBtk];
    animators[1] = new Sys::MatLoopAnimator[countBrk];

    for (int i = 0; i < countBtk; i++) {
        TexNode* node = (TexNode*)texAnims.getChildAt(i);
        animators[0][i].start(node->m_anim);
    }

    for (int i = 0; i < countBrk; i++) {
        TevNode* node = (TevNode*)tevAnims.getChildAt(i);
        animators[1][i].start(node->m_anim);
    }

    OSReport("Done!\n");
    OSReport("Count BTK: %i", countBtk);
    OSReport("Count BRK: %i", countBrk);
}

void CaveVRBox::animate() {
    if (m_model) {
        f32 animSpeed = 30.0f;
        for (int i = 0; i < countBtk; i++) {
            animators[0][i].animate(animSpeed);
        }
        for (int i = 0; i < countBrk; i++) {
            animators[1][i].animate(animSpeed);
        }
        m_model->m_j3dModel->calcMaterial();
        m_model->m_j3dModel->diff();
    }
}

} // namespace Game
