#include "og/newScreen/Contena.h"
#include "og/Screen/ContenaCounter.h"
#include "og/Screen/ogScreen.h"
#include "og/Screen/AlphaMgr.h"
#include "og/Screen/StickAnimMgr.h"
#include "og/Screen/anime.h"
#include "og/Sound.h"
#include "System.h"
#include "Controller.h"
#include "trig.h"
#include "Dolphin/arith.h"

namespace og {
namespace newScreen {

void ObjContena::changeMessage(u32 mesg)
{
	if (mState != mesg) {
		mAlphaMgr[mState]->out(0.5f);
		mState = mesg;
		mAlphaMgr[mState]->in(0.3f);
	}
}

void ObjContena::setStickUp()
{
	mAlphaArrow1->in(0.3f);
	mAlphaArrow2->out(0.5f);
	mStickAnimMgr->stickUp();
}

void ObjContena::setStickDown()
{
	mAlphaArrow1->out(0.5f);
	mAlphaArrow2->in(0.3f);
	mStickAnimMgr->stickDown();
}

void ObjContena::setStickUpDown()
{
	mAlphaArrow1->in(0.3f);
	mAlphaArrow2->in(0.3f);
	mStickAnimMgr->stickUpDown();
}
    
/**
 * @note Address: 0x80320AE4
 * @note Size: 0x284
 */
void ObjContena::putinPiki(bool soundType)
{
	u8 pikis = 1;
	if (mController->getButton() & PAD_BUTTON_Y) {
		pikis = 10;
	}

	for (u8 i = 0; i < pikis; i++) {
		if (mDisp->m_currField <= mDisp->m_inOnionCount) {
			if (mState == 1) {
				if (!soundType) {
					ogSound->setError();
				}
			} else {
				ogSound->setError();
				changeMessage(1);
				setStickDown();
			}
			return;
		}

		if (mDisp->m_inSquadCount == 0) {
			if (mState == 4) {
				if (!soundType) {
					ogSound->setError();
				}
			} else {
				ogSound->setError();
				changeMessage(4);
				setStickDown();
			}
		} else {
			changeMessage(0);
			mDisp->m_inOnionCount++;
			mDisp->m_inSquadCount--;
			mDisp->m_inParty2--;
			mDisp->m_onMapCount--;
			mDisp->m_result++;
			mDisp->_28 = (u16)__abs(mDisp->m_result); // should be just abs
			setStickUpDown();
			if (mTimer1 <= 0.0f) {
				mScaleArrow1->up();
				mTimer1 = msVal._38;
			}
			mScaleMgr3->up(0.1f, 30.0f, 0.8f, 0.0f);
			mScaleMgr4->down(0.05f, 35.0f, 0.8f);
			ogSound->setPlusMinus(soundType);
		}
	}

}

/**
 * @note Address: 0x80320D68
 * @note Size: 0x320
 */
void ObjContena::takeoutPiki(bool soundType)
{
	u8 pikis = 1;
	if (mController->getButton() & PAD_BUTTON_Y) {
		pikis = 10;
	}

	for (u8 i = 0; i < pikis; i++) {
		og::Screen::DispMemberContena* disp = mDisp;
		if (disp->m_inSquadCount < disp->m_maxPikiOnField) {
		} else if (mState == 2) {
			if (!soundType) {
				ogSound->setError();
			}
			return;
		} else {
			ogSound->setError();
			changeMessage(2);
			setStickUp();
			return;
		}

		if (disp->m_inOnionCount == 0) {
			if (mState == 3) {
				if (!soundType) {
					ogSound->setError();
				}
				return;
			} else {
				ogSound->setError();
				changeMessage(3);
				setStickUp();
				return;
			}
		} else if (disp->m_onMapCount < disp->m_maxPikiCount) {
		} else if (mState == 5) {
			if (!soundType) {
				ogSound->setError();
			}
			return;
		} else {
			ogSound->setError();
			changeMessage(5);
			setStickUp();
			return;
		}

		changeMessage(0);
		disp->m_inOnionCount--;
		disp->m_inSquadCount++;
		disp->m_inParty2++;
		disp->m_onMapCount++;
		disp->m_result--;
		disp->_28 = (u16)__abs(disp->m_result);
		setStickUpDown();
		if (mTimer2 <= 0.0f) {
			mScaleArrow2->up();
			mTimer2 = msVal._38;
		}
		mScaleMgr4->up(0.1f, 30.0f, 0.8f, 0.0f);
		mScaleMgr3->down(0.05f, 35.0f, 0.8f);
		ogSound->setPlusMinus(soundType);
	}
}

} // namespace newScreen
} // namespace og