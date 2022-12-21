#include "og/Screen/callbackNodes.h"
#include "og/Screen/SunMeter.h"
#include "og/Screen/ogScreen.h"
#include "og/Sound.h"
#include "Dolphin/math.h"
#include "types.h"

namespace og {
namespace Screen {
/*
 * --INFO--
 * Address:	........
 * Size:	0000B4
 */
CallBack_SunMeter::CallBack_SunMeter()
{
	m_timer            = 0.0f;
	m_currentTime      = nullptr;
	m_startPane        = nullptr;
	m_endPane          = nullptr;
	m_suniPane         = nullptr;
	m_sun1Pane         = nullptr;
	m_sun2Pane         = nullptr;
	m_hasChimedNoon    = false;
	m_hasChimedMorning = false;
	m_hasChimedEvening = false;
	m_scaleMgr         = new ScaleMgr;
}

/*
 * --INFO--
 * Address:	........
 * Size:	000108
 */
void CallBack_SunMeter::init(J2DScreen* canvas, f32* time)
{
	m_currentTime      = time;
	m_startPane        = canvas->search('stat');
	m_endPane          = canvas->search('goal');
	m_suniPane         = canvas->search('suni');
	m_sun1Pane         = canvas->search('sun1');
	m_sun2Pane         = canvas->search('sun2');
	m_hasChimedNoon    = false;
	m_hasChimedMorning = false;
	m_hasChimedEvening = false;
	m_suniPane->setBasePosition(POS_CENTER);
}

/*
 * --INFO--
 * Address:	80307294
 * Size:	00023C
 */
void CallBack_SunMeter::update()
{
	f32 currentTime = *m_currentTime;
	// Between 0.297 - 0.3, chime
	if (0.297f < currentTime && currentTime < 0.3f && !m_hasChimedMorning) {
		m_hasChimedMorning = true;
		ogSound->setChime();
		startEffectChime();
	}

	// Between 0.497 - 0.5, chime
	if (0.497f < currentTime && currentTime < 0.5f && !m_hasChimedNoon) {
		m_hasChimedNoon = true;
		ogSound->setChimeNoon();
		startEffectChime();
	}

	// Between 0.697 - 0.7, chime
	if (0.697f < currentTime && currentTime < 0.7f && !m_hasChimedEvening) {
		m_hasChimedEvening = true;
		ogSound->setChime();
		startEffectChime();
	}

	m_timer += 1.0f;

	f32 x0 = m_startPane->getBounds()->i.x;
	f32 x1 = m_endPane->getBounds()->i.x;
	f32 y  = m_suniPane->getBounds()->i.y;
	f32 x  = currentTime * (x1 - x0) + x0;
	m_suniPane->move(x, y);

	m_sun1Pane->rotate(m_sun1Pane->_020.getWidth() / 2, m_sun1Pane->_020.getHeight() / 2, J2DROTATE_Z, -m_timer);

	f32 sinVal = sin(-m_timer * DEG2RAD * PI * 2.0f);
	f32 alpha  = sinVal * 64.0f + 191.0f;

	m_sun1Pane->setAlphaFromFloat(alpha);
	m_suniPane->updateScale(m_scaleMgr->calc());
}

/*
 * --INFO--
 * Address:	803074D0
 * Size:	000034
 */
void CallBack_SunMeter::startEffectChime() { m_scaleMgr->up(0.3f, 30.0f, 0.7f, 0.0f); }

/*
 * --INFO--
 * Address:	80307504
 * Size:	000044
 */
SunMeter::SunMeter() { m_currentTime = 0.0f; }

/*
 * --INFO--
 * Address:	80307548
 * Size:	0001B4
 */
void SunMeter::setCallBack()
{
	setAlphaScreen(this);
	m_callBack = new CallBack_SunMeter();
	m_callBack->init(this, &m_currentTime);
	addCallBack('suni', m_callBack);
}
} // namespace Screen
} // namespace og
