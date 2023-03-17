#include "Game/mapParts.h"
#include "JSystem/J3D/J3DFileBlock.h"
#include "LoadResource.h"

namespace Game {

Sys::MatTexAnimation* CaveVRBox::texAnims[100];
Sys::MatTevRegAnimation* CaveVRBox::tevAnims[100];
int countBrk = 0;
int countBtk = 0;
Sys::MatLoopAnimator* CaveVRBox::animators[2];

void CaveVRBox::loadResources(JKRArchive* rarc)
{
	OSReport("loading %x... \n", this);
	void* bmd           = rarc->getResource("model.bmd");
	J3DModelData* model = J3DModelLoaderDataBase::load(bmd, 0x21240030);
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
	m_model->m_j3dModel->makeDL();
	OSReport("calced\n");
	m_model->enableMaterialAnim(0);
	OSReport("made materials...\n");

	OSReport("cleaned nodes\n");
	countBtk = 0;

	for (int i = 0; i < 99; i++) {

		char filename[128];
		sprintf(filename, "texanm_%d.btk", i);

		void* btkFile = rarc->getResource(filename);

		if (btkFile) {
			delete texAnims[countBtk];
			OSReport("found btkfile\n");
			texAnims[countBtk] = new Sys::MatTexAnimation;
			texAnims[countBtk]->attachResource(btkFile, m_model->m_j3dModel->m_modelData);
			countBtk++;
		}
	}

	OSReport("Made btks...\n");

	countBrk = 0;
	for (int i = 0; i < 99; i++) {

		char filename[128];
		sprintf(filename, "tevanm_%d.brk", i);

		void* brkFile = rarc->getResource(filename);
		if (brkFile) {
			delete tevAnims[countBrk];
			OSReport("found brkfile\n");
			tevAnims[countBrk] = new Sys::MatTevRegAnimation;
			tevAnims[countBrk]->attachResource(brkFile, m_model->m_j3dModel->m_modelData);
			countBrk++;
		}
	}

	OSReport("Made brks...\n");

	animators[0] = new Sys::MatLoopAnimator[countBtk];
	animators[1] = new Sys::MatLoopAnimator[countBrk];

	for (int i = 0; i < countBtk; i++) {
		animators[0][i].start(texAnims[i]);
	}

	for (int i = 0; i < countBrk; i++) {
		animators[1][i].start(tevAnims[i]);
	}

	OSReport("Done!\n");
	OSReport("Count BTK: %i\n", countBtk);
	OSReport("Count BRK: %i\n", countBrk);
}

void CaveVRBox::animate()
{
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

int getCavebox() { return (Game::countBtk > 0 || Game::countBrk > 0) ? 1 : 6; }
