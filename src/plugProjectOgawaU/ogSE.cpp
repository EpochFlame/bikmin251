#include "types.h"
#include "og/Sound.h"
#include "PSSystem/PSSystemIF.h"
#include "SoundID.h"
#include "PSSystem/PSScene.h"
#include "PSSystem/PSGame.h"
#include "PSM/Scene.h"
#include "utilityU.h"

namespace og {

Sound* ogSound;

/*
 * --INFO--
 * Address:	8030C9B0
 * Size:	000028
 */
void Sound::setSE(u32 soundID) { PSSystem::spSysIF->playSystemSe(soundID, 0); }

/*
 * --INFO--
 * Address:	8030C9D8
 * Size:	00002C
 */
void Sound::setLifeDanger(void) { PSSystem::spSysIF->playSystemSe(PSSE_SY_LIFE_DANGER, 0); }

/*
 * --INFO--
 * Address:	8030CA04
 * Size:	0000F4
 */
void Sound::setChimeNoon(void)
{
	PSSystem::spSysIF->playSystemSe(PSSE_SY_TIME_SIGNAL_NOON, 0);

	PSSystem::SceneMgr* mgr = PSSystem::getSceneMgr();
	PSSystem::checkSceneMgr(mgr);
	PSM::Scene_Ground* scene = static_cast<PSM::Scene_Ground*>(mgr->getChildScene());
	scene                    = (scene->isGameScene()) ? scene : nullptr;
	scene->changeEnvSE_Noon();
}

/*
 * --INFO--
 * Address:	8030CAF8
 * Size:	00002C
 */
void Sound::setChime(void) { PSSystem::spSysIF->playSystemSe(PSSE_SY_TIME_SIGNAL_SMALL, 0); }

/*
 * --INFO--
 * Address:	8030CB24
 * Size:	00002C
 */
void Sound::setDecide(void) { PSSystem::spSysIF->playSystemSe(PSSE_SY_MENU_DECIDE, 0); }

/*
 * --INFO--
 * Address:	8030CB50
 * Size:	00002C
 */
void Sound::setCancel(void) { PSSystem::spSysIF->playSystemSe(PSSE_SY_MENU_CANCEL, 0); }

/*
 * --INFO--
 * Address:	8030CB7C
 * Size:	00002C
 */
void Sound::setCursor(void) { PSSystem::spSysIF->playSystemSe(PSSE_SY_MENU_CURSOR, 0); }

/*
 * --INFO--
 * Address:	8030CBA8
 * Size:	00002C
 */
void Sound::setOpen(void) { PSSystem::spSysIF->playSystemSe(PSSE_SY_MENU_OPEN, 0); }

/*
 * --INFO--
 * Address:	8030CBD4
 * Size:	00002C
 */
void Sound::setClose(void) { PSSystem::spSysIF->playSystemSe(PSSE_SY_MENU_CLOSE, 0); }

/*
 * --INFO--
 * Address:	........
 * Size:	00002C
 */
void Sound::setPause(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	8030CC00
 * Size:	000048
 */
void Sound::setPlusMinus(bool isRepeat)
{
	if (isRepeat) {
		PSSystem::spSysIF->playSystemSe(PSSE_SY_PLUS_MINUS_REPEAT, 0);
	} else {
		PSSystem::spSysIF->playSystemSe(PSSE_SY_MENU_PLUS_MINUS, 0);
	}
}

/*
 * --INFO--
 * Address:	8030CC48
 * Size:	00002C
 */
void Sound::setSMenuLR(void) { PSSystem::spSysIF->playSystemSe(PSSE_SY_MENU_PLUS_MINUS, 0); }

/*
 * --INFO--
 * Address:	8030CC74
 * Size:	00002C
 */
void Sound::setError(void) { PSSystem::spSysIF->playSystemSe(PSSE_SY_MENU_ERROR, 0); }

/*
 * --INFO--
 * Address:	8030CCA0
 * Size:	00002C
 */
void Sound::setZoomIn(void) { PSSystem::spSysIF->playSystemSe(PSSE_SY_MENU_ZOOMIN, 0); }

/*
 * --INFO--
 * Address:	8030CCCC
 * Size:	00002C
 */
void Sound::setZoomOut(void) { PSSystem::spSysIF->playSystemSe(PSSE_SY_MENU_ZOOMOUT, 0); }

/*
 * --INFO--
 * Address:	8030CCF8
 * Size:	00002C
 */
void Sound::setScroll(void) { PSSystem::spSysIF->playSystemSe(PSSE_SY_MENU_SCROLL, 0); }

/*
 * --INFO--
 * Address:	8030CD24
 * Size:	00002C
 */
void Sound::setOpenDoukutu(void) { PSSystem::spSysIF->playSystemSe(PSSE_SY_MESSAGE_EXIT, 0); }

/*
 * --INFO--
 * Address:	8030CD50
 * Size:	00002C
 */
void Sound::setSaveCave(void) { PSSystem::spSysIF->playSystemSe(PSSE_SAVESELECTPAD, 0); }

/*
 * --INFO--
 * Address:	8030CD7C
 * Size:	00002C
 */
void Sound::setOpenWMapMenu(void) { PSSystem::spSysIF->playSystemSe(PSSE_SY_MESSAGE_EXIT, 0); }

/*
 * --INFO--
 * Address:	8030CDA8
 * Size:	00002C
 */
void Sound::setOpenTotalPoko(void) { PSSystem::spSysIF->playSystemSe(PSSE_SY_REGI_DRAWER_OPEN, 0); }

/*
 * --INFO--
 * Address:	8030CDD4
 * Size:	00002C
 */
void Sound::setCloseTotalPoko(void) { PSSystem::spSysIF->playSystemSe(PSSE_SY_REGI_RECEIPT, 0); }

/*
 * --INFO--
 * Address:	8030CE00
 * Size:	00002C
 */
void Sound::setPlusTotalPoko(void) { PSSystem::spSysIF->playSystemSe(PSSE_SY_REGI_SUM_UP, 0); }

/*
 * --INFO--
 * Address:	8030CE2C
 * Size:	00002C
 */
void Sound::setOpenFinalMsg(void) { PSSystem::spSysIF->playSystemSe(PSSE_SY_MESSAGE_EXIT, 0); }

/*
 * --INFO--
 * Address:	8030CE58
 * Size:	00002C
 */
void Sound::setSprayAdd(void) { PSSystem::spSysIF->playSystemSe(PSSE_SY_STORED_SPRAY, 0); }

/*
 * --INFO--
 * Address:	8030CE84
 * Size:	00002C
 */
void Sound::setTimeCarry(void) { PSSystem::spSysIF->playSystemSe(PSSE_SY_PIKI_INCRE_SUM, 0); }

/*
 * --INFO--
 * Address:	........
 * Size:	00002C
 */
void Sound::setSensorSE(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	8030CEB0
 * Size:	00002C
 */
void Sound::setGetSensor(void) { PSSystem::spSysIF->playSystemSe(PSSE_SY_EQUIP_LADER, 0); }

/*
 * --INFO--
 * Address:	8030CEDC
 * Size:	00002C
 */
void Sound::setFloorComplete(void) { PSSystem::spSysIF->playSystemSe(PSSE_SY_FLOOR_COMPLETE, 0); }

/*
 * --INFO--
 * Address:	8030CF08
 * Size:	00002C
 */
void Sound::setGraySensor(void) { PSSystem::spSysIF->playSystemSe(PSSE_SY_LADER_TURN_GRAY, 0); }

/*
 * --INFO--
 * Address:	8030CF34
 * Size:	00002C
 */
void Sound::setGetSpray(void) { PSSystem::spSysIF->playSystemSe(PSSE_SY_EQUIP_SPLAY, 0); }

/*
 * --INFO--
 * Address:	........
 * Size:	00002C
 */
void Sound::setItemName(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	8030CF60
 * Size:	00002C
 */
void Sound::setKanteiExit(void) { PSSystem::spSysIF->playSystemSe(PSSE_SY_KANTEI_OUT, 0); }

/*
 * --INFO--
 * Address:	8030CF8C
 * Size:	000004
 */
void Sound::setFloorTitle(void) { }

/*
 * --INFO--
 * Address:	8030CF90
 * Size:	00002C
 */
void Sound::setVsTitle(void) { PSSystem::spSysIF->playSystemSe(PSSE_SY_2P_RULE_WAIT, 0); }

/*
 * --INFO--
 * Address:	8030CFBC
 * Size:	00002C
 */
void Sound::setBdamaGet(void) { PSSystem::spSysIF->playSystemSe(PSSE_SY_2P_MARBLE_COUNT, 0); }

/*
 * --INFO--
 * Address:	8030CFE8
 * Size:	000004
 */
void Sound::setNaviChange(int) { }

/*
 * --INFO--
 * Address:	........
 * Size:	00002C
 */
void Sound::setVsTitleAbutton(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000D4
 */
void Sound::stopSound(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	8030CFEC
 * Size:	0000E0
 */
void Sound::setVsWin1P(void)
{
	PSStart2DStream(0xc0011043);

	PSSystem::SceneMgr* mgr = PSSystem::getSceneMgr();
	PSSystem::checkSceneMgr(mgr);
	PSM::Scene_Game* scene = static_cast<PSM::Scene_Game*>(mgr->getChildScene());
	scene->stopAllSound(2);
	PSMuteSE_on2D();
}

/*
 * --INFO--
 * Address:	8030D0CC
 * Size:	0000E0
 */
void Sound::setVsWin2P(void)
{
	PSStart2DStream(0xc0011044);

	PSSystem::SceneMgr* mgr = PSSystem::getSceneMgr();
	PSSystem::checkSceneMgr(mgr);
	PSM::Scene_Game* scene = static_cast<PSM::Scene_Game*>(mgr->getChildScene());
	scene->stopAllSound(2);
	PSMuteSE_on2D();
}

/*
 * --INFO--
 * Address:	8030D1AC
 * Size:	0000E0
 */
void Sound::setVsDraw(void)
{
	PSStart2DStream(0xc0011045);

	PSSystem::SceneMgr* mgr = PSSystem::getSceneMgr();
	PSSystem::checkSceneMgr(mgr);
	PSM::Scene_Game* scene = static_cast<PSM::Scene_Game*>(mgr->getChildScene());
	scene->stopAllSound(2);
	PSMuteSE_on2D();
}

/*
 * --INFO--
 * Address:	8030D28C
 * Size:	00002C
 */
void Sound::setWarning(void) { PSSystem::spSysIF->playSystemSe(PSSE_SY_MESSAGE_WARNING, 0); }
} // namespace og
