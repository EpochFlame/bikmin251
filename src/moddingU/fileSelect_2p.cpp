#include "Morimura/Challenge.h"
#include "ebi/FileSelect.h"
#include "ebi/Screen/TMainScreen.h"
#include "ebi/FS.h"
#include "TwoPlayer.h"
#include "PSSystem/PSSystemIF.h"
#include "TParticle2dMgr.h"

Morimura::TChallengePlayModeScreen* fs_screen;
u8 fs_bgAlpha;
bool fs_gameSelected;

void ebi::Screen::FileSelect::TMainScreen::doSetArchive(JKRArchive* arc)
{
	doSetArchive_old(arc);

	fs_bgAlpha      = 0;
	fs_gameSelected = false;

	fs_screen = new Morimura::TChallengePlayModeScreen(arc, 0);
	fs_screen->create("select_player.blo", 0x20000);
	fs_screen->mEfxCursor1->setGroup(1);
	fs_screen->mEfxCursor2->setGroup(1);
	fs_screen->mSphereTex = new J2DPicture(static_cast<ResTIMG*>(arc->getResource("timg/sphere.bti")));
}

bool ebi::Screen::FileSelect::TMainScreen::doUpdateStateWait()
{
	bool res = doUpdateStateWait_old();

	// adjust player sel background alpha
	if (!fs_gameSelected) {
		if (fs_screen->mState != 0) {
			if (fs_bgAlpha < 190)
				fs_bgAlpha += 10;
		} else {
			if (fs_bgAlpha > 0)
				fs_bgAlpha -= 10;
		}
	}

	fs_screen->update();

	return res;
}

void ebi::Screen::FileSelect::TMainScreen::doDraw()
{
	doDraw_old();

	J2DPerspGraph* graf = &sys->m_gfx->m_perspGraph;

	graf->setPort();
	JUtility::TColor color(0, 0, 0, fs_bgAlpha);
	graf->setColor(color);
	GXSetAlphaUpdate(GX_FALSE);
	JGeometry::TBox2f bounds(0.0f, 0.0f, 640.0f, 480.0f);
	graf->fillBox(bounds);
	GXSetAlphaUpdate(GX_TRUE);

	fs_screen->draw(*sys->m_gfx, graf);

	// needed for cursor efx to draw in front
	particle2dMgr->draw(1, 0);
}

void ebi::FS::FSMState00_SelectData::do_exec(ebi::FS::TMgr* mgr)
{
	if (mgr->mMainScreen.isWaitScreen()) {
		if (mgr->mController->isButtonDown(Controller::PRESS_A) && fs_screen->mState == 0) {
			PSSystem::spSysIF->playSystemSe(PSSE_SY_MENU_DECIDE, 0);
			fs_screen->mState = 1;
			fs_screen->mTimer = 0.0f;
			fs_screen->mAnimScreen[0]->open(0.1f);
			fs_screen->mAnimScreen[1]->open(0.2f);
			fs_screen->mAnimScreen[2]->open(0.3f);
			fs_screen->mAnimScreen[3]->open(0.4f);

			fs_screen->mAnimScreen[1]->blink(1.0f, 0.0f);
			fs_screen->mAnimScreen[2]->blink(0.0f, 0.0f);
			fs_screen->mDoShowNoController = false;
		} else if (fs_screen->mState == 2) {
			if (mgr->mController->isButtonDown(Controller::PRESS_B)) {
				PSSystem::spSysIF->playSystemSe(PSSE_SY_MENU_CANCEL, 0);
				fs_screen->mTimer = 0.0f;
				fs_screen->mState = 3;
				fs_screen->mAnimScreen[0]->close();
				fs_screen->mAnimScreen[1]->close();
				fs_screen->mAnimScreen[2]->close();
				fs_screen->mAnimScreen[3]->close();
				fs_screen->mEfxCursor1->kill();
				fs_screen->mEfxCursor2->kill();

			} else if (mgr->mController->isButtonDown(Controller::PRESS_A)) {
				int test = JUTGamePad::mPadStatus[1].err;
				OSReport("Controller 2 status: %i\n", test);
				if (Morimura::TChallengeSelect::mSelected1p == 1 || test != -1) {
					PSSystem::spSysIF->playSystemSe(PSSE_SY_MENU_DECIDE, 0);
					fs_screen->mTimer = 0.0f;
					fs_screen->mState = 3;
					fs_screen->mAnimScreen[0]->close();
					fs_screen->mAnimScreen[1]->close();
					fs_screen->mAnimScreen[2]->close();
					fs_screen->mAnimScreen[3]->close();
					fs_screen->mEfxCursor1->kill();
					fs_screen->mEfxCursor2->kill();
					transit(mgr, 2, 0);
					TwoPlayer::setTwoPlayer(Morimura::TChallengeSelect::mSelected1p == 0);
				} else {
					PSSystem::spSysIF->playSystemSe(PSSE_SY_MENU_ERROR, 0);
					fs_screen->mDoShowNoController = 1;
				}
			} else if (mgr->mController->isButtonDown(Controller::PRESS_DPAD_DOWN | 0x4000000)
			           && Morimura::TChallengeSelect::mSelected1p != 0) {
				Morimura::TChallengeSelect::mSelected1p = 0;
				fs_screen->mDoShowNoController          = 0;
				fs_screen->mScaleMgr[1]->up(0.25f, 20.0f, 0.4f, 0.0f);
				fs_screen->mAnimScreen[1]->blink(0.0f, 0.0f);
				fs_screen->mAnimScreen[2]->blink(1.0f, 0.0f);
				PSSystem::spSysIF->playSystemSe(PSSE_SY_MENU_CURSOR, 0);
			} else if (mgr->mController->isButtonDown(Controller::PRESS_DPAD_UP | 0x8000000)
			           && Morimura::TChallengeSelect::mSelected1p != 1) {
				Morimura::TChallengeSelect::mSelected1p = 1;
				fs_screen->mDoShowNoController          = 0;
				fs_screen->mScaleMgr[0]->up(0.25f, 20.0f, 0.4f, 0.0f);
				fs_screen->mAnimScreen[1]->blink(1.0f, 0.0f);
				fs_screen->mAnimScreen[2]->blink(0.0f, 0.0f);
				PSSystem::spSysIF->playSystemSe(PSSE_SY_MENU_CURSOR, 0);
			}
		}
	} else {
		fs_screen->mState = 0;
	}

	if (fs_screen->mState) {
		return;
	}
	do_exec_old(mgr);
}
