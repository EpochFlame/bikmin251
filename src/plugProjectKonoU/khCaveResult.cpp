#include "types.h"
#include "kh/CaveResult.h"
#include "kh/LostItem.h"
#include "Dolphin/rand.h"
#include "efx2d/T2DChangesmoke.h"
#include "PSSystem/PSSystemIF.h"
#include "JSystem/JKR/JKRFileLoader.h"
#include "JSystem/J2D/J2DAnmLoader.h"
#include "og/Screen/ogScreen.h"
#include "og/Screen/StickAnimMgr.h"
#include "og/newScreen/ogUtil.h"
#include "Game/MemoryCard/Mgr.h"
#include "LoadResource.h"
#include "Controller.h"
#include "Dolphin/gx.h"

namespace kh {
namespace Screen {

/*
 * --INFO--
 * Address:	803F8694
 * Size:	00007C
 */
DispCaveResult::DispCaveResult(Game::Result::TNode* node, u32 death, u32 otakara, u32 otakaraMax, u32 pokos, bool paydebt, JKRHeap* heap,
                               bool caveComp)
{
	init(node, death, caveComp);
	m_totalPokos       = pokos;
	m_debtPayed        = paydebt;
	m_collectedOtakara = otakara;
	m_maxOtakara       = otakaraMax;
	m_heap             = heap;
}

/*
 * --INFO--
 * Address:	803F8710
 * Size:	0000AC
 */
void DispCaveResult::init(Game::Result::TNode* node, u32 death, bool caveComp)
{
	m_resultNode        = node;
	m_lostTreasures     = 0;
	_14                 = 0;
	m_cavePokos         = 0;
	m_treasureNodeCount = 0;

	FOREACH_NODE(Game::Result::TNode, m_resultNode->m_child, cNode)
	{
		if (cNode->m_quantity > 0 || cNode->m_isLost != 0) {
			_14++;
		}
		m_treasureNodeCount++;
		m_lostTreasures += cNode->m_isLost;

		if (cNode->m_quantity > 0 || !cNode->m_isLost) {
			m_cavePokos += cNode->m_pokoValue;
		}
	}

	m_deadPikis  = death;
	m_caveComp   = caveComp;
	m_isFinished = 0;
}

/*
 * --INFO--
 * Address:	803F87BC
 * Size:	000134
 */
ObjCaveResult::ObjCaveResult()
{
	m_saveMgr        = nullptr;
	m_resultNode     = nullptr;
	m_screenComplete = nullptr;
	m_screenDropItem = nullptr;
	m_screenMain     = nullptr;

	m_completeAnim      = nullptr;
	m_mainAnim          = nullptr;
	m_completeAnimColor = nullptr;
	m_mainAnimColor     = nullptr;
	m_animTexSRT        = nullptr;
	m_animTevReg        = nullptr;

	m_animTimers[5] = 0.0f;
	m_animTimers[4] = 0.0f;
	m_animTimers[3] = 0.0f;
	m_animTimers[1] = 0.0f;
	m_animTimers[2] = 0.0f;
	m_animTimers[0] = 0.0f;

	m_efxComp   = nullptr;
	m_stickAnim = nullptr;

	m_fadePane4         = nullptr;
	m_fadePaneDownArrow = nullptr;
	m_fadePaneUpArrow   = nullptr;
	m_fadePane1         = nullptr;

	m_counterTotalPokos        = nullptr;
	m_counterTreasureMax       = nullptr;
	m_counterTreasureCollected = nullptr;
	m_counterOtaValues[1]      = nullptr;
	m_counterOtaValues[0]      = nullptr;
	m_counterDeadPiki          = nullptr;
	m_counterCavePokos         = nullptr;

	m_totalPokos       = 0;
	m_maxOtakara       = 0;
	m_otakaraCount     = 0;
	m_currOtaValues[1] = 0;
	m_currOtaValues[0] = 0;
	m_deadPiki         = 0;
	m_cavePokos        = 0;

	m_scrollPos         = 0.0f;
	m_scrollUpDown      = 0.0f;
	m_scrollSelIndex    = -6;
	m_scrollSelIndexMax = 0;
	m_scrollTargetDist  = msVal._1C;

	m_scrollMoveTimer  = 0;
	_EC                = 0;
	_E8                = 0;
	m_status           = 3;
	m_changeStateDelay = 0;
	_F8                = 0;
	m_flag             = 0;
	m_alpha            = 255;
	_107               = 0;
	_106               = 0;
}

/*
 * --INFO--
 * Address:	803F88F0
 * Size:	000B08
 */
void ObjCaveResult::doCreate(JKRArchive* arc)
{

	JUT_ASSERTLINE(191, getDispMember()->isID(OWNER_KH, MEMBER_CAVE_RESULT), "disp member err");

	DispCaveResult* disp = static_cast<DispCaveResult*>(getDispMember());

	m_screenMain = new P2DScreen::Mgr_tuning;
	m_screenMain->set("result_doukutu.blo", 0x1040000, arc);

	m_screenDropItem = new P2DScreen::Mgr_tuning;
	m_screenDropItem->set("result_doukutu_drop_item.blo", 0x1040000, arc);

	void* file      = JKRFileLoader::getGlbResource("result_doukutu.bck", arc);
	m_mainAnim      = static_cast<J2DAnmTransform*>(J2DAnmLoaderDataBase::load(file));
	file            = JKRFileLoader::getGlbResource("result_doukutu.bpk", arc);
	m_mainAnimColor = static_cast<J2DAnmColor*>(J2DAnmLoaderDataBase::load(file));
	file            = JKRFileLoader::getGlbResource("result_doukutu.btk", arc);
	m_animTexSRT    = static_cast<J2DAnmTextureSRTKey*>(J2DAnmLoaderDataBase::load(file));
	file            = JKRFileLoader::getGlbResource("result_doukutu.brk", arc);
	m_animTevReg    = static_cast<J2DAnmTevRegKey*>(J2DAnmLoaderDataBase::load(file));

	m_screenMain->setAnimation(m_mainAnim);
	m_screenMain->setAnimation(m_mainAnimColor);
	m_screenMain->setAnimation(m_animTexSRT);
	m_screenMain->setAnimation(m_animTevReg);

	JKRHeap* oldHeap = getCurrentHeap();
	if (disp->m_heap) {
		disp->m_heap->becomeCurrentHeap();
	}

	m_screenComplete = new P2DScreen::Mgr_tuning;
	m_screenComplete->set("doukutu_complete.blo", 0x40000, arc);

	file           = JKRFileLoader::getGlbResource("doukutu_complete.bck", arc);
	m_completeAnim = static_cast<J2DAnmTransform*>(J2DAnmLoaderDataBase::load(file));

	file                = JKRFileLoader::getGlbResource("doukutu_complete.bpk", arc);
	m_completeAnimColor = static_cast<J2DAnmColor*>(J2DAnmLoaderDataBase::load(file));

	m_screenComplete->setAnimation(m_completeAnim);
	m_screenComplete->setAnimation(m_completeAnimColor);
	m_screenComplete->animation();

	og::Screen::setCallBackMessage(m_screenMain);
	m_resultNode = disp->m_resultNode;

	Game::Result::TNode* cNode = static_cast<Game::Result::TNode*>(m_resultNode->m_child);

	while (cNode) {
		cNode->m_itemMgr = new kh::Screen::LostItemMgr(cNode->m_isLost);
		cNode            = static_cast<Game::Result::TNode*>(cNode->m_next);
	}

	if (disp->m_treasureNodeCount > 6) {
		setFlag(CAVERESFLAG_CanScroll);
		m_scrollSelIndexMax = disp->m_treasureNodeCount - 6;
	}

	m_scrollUpDown = m_screenMain->search('Nsetp01')->getBounds()->i.y - m_screenMain->search('Nsetp00')->getBounds()->i.y;
	m_scrollPos    = m_scrollUpDown * (int)(1 - m_scrollSelIndex);

	kh::Screen::setInfAlpha(m_screenMain->search('Nicon00'));
	kh::Screen::setInfAlpha(m_screenMain->search('Nicon01'));

	m_cavePokos    = 0;
	m_deadPiki     = 0;
	m_otakaraCount = disp->m_collectedOtakara + disp->m_lostTreasures - disp->_14;
	m_maxOtakara   = disp->m_maxOtakara;
	m_totalPokos   = disp->m_totalPokos - disp->m_cavePokos;

	u64 debtTag;
	if (disp->m_debtPayed) {
		J2DPane* pane     = m_screenMain->search('Nfi_menu');
		pane->m_isVisible = false;

		pane              = m_screenMain->search('Nco_menu');
		pane->m_isVisible = true;

		debtTag = 'Pcomp01';
	} else {
		J2DPane* pane     = m_screenMain->search('Nfi_menu');
		pane->m_isVisible = true;

		pane              = m_screenMain->search('Nco_menu');
		pane->m_isVisible = false;

		debtTag = 'Pfin01';
	}

	if (disp->m_caveComp || (disp->m_maxOtakara != disp->m_collectedOtakara)) {
		J2DPane* pane     = m_screenMain->search('Pananorm');
		pane->m_isVisible = true;

		pane              = m_screenMain->search('Panacomp');
		pane->m_isVisible = false;
	} else {
		J2DPane* pane     = m_screenMain->search('Pananorm');
		pane->m_isVisible = false;

		pane              = m_screenMain->search('Panacomp');
		pane->m_isVisible = true;
	}

	m_screenMain->search('Panacomp')->setBasePosition(POS_CENTER);

	og::Screen::CallBack_Picture* pic = og::Screen::setCallBack_3DStick(arc, m_screenMain, 'PICT_004');
	m_stickAnim                       = new og::Screen::StickAnimMgr(pic);
	m_stickAnim->stickUpDown();

	m_fadePaneUpArrow = kh::Screen::khUtilFadePane::create(m_screenMain, 'Nyame_u', 16);
	m_fadePaneUpArrow->fadeout();
	m_fadePaneDownArrow = kh::Screen::khUtilFadePane::create(m_screenMain, 'Nyame_l', 16);
	m_fadePaneDownArrow->fadeout();
	m_fadePane1 = kh::Screen::khUtilFadePane::create(m_screenMain, 'PICT_004', 16);
	m_fadePane1->add(m_screenMain->search('N_3d'));
	m_fadePane1->fadeout();
	m_fadePane4 = kh::Screen::khUtilFadePane::create(m_screenMain, 'Nmain_m', 16);
	m_fadePane4->fadeout();

	m_counterCavePokos         = og::Screen::setCallBack_CounterRV(m_screenMain, 'Ptomadp1', &m_cavePokos, 6, true, false, arc);
	m_counterDeadPiki          = og::Screen::setCallBack_CounterRV(m_screenMain, 'Ppiki1', &m_deadPiki, 3, true, false, arc);
	m_counterOtaValues[0]      = og::Screen::setCallBack_CounterRV(m_screenMain, 'Pmad00_1', &m_currOtaValues[0], 4, false, false, arc);
	m_counterOtaValues[1]      = og::Screen::setCallBack_CounterRV(m_screenMain, 'Pmad01_1', &m_currOtaValues[1], 4, false, false, arc);
	m_counterTreasureCollected = og::Screen::setCallBack_CounterRV(m_screenMain, 'Pota_1', &m_otakaraCount, 2, true, true, arc);
	m_counterTreasureMax       = og::Screen::setCallBack_CounterRV(m_screenMain, 'Pota_to1', &m_maxOtakara, 2, false, true, arc);
	m_counterTotalPokos        = og::Screen::setCallBack_CounterRV(m_screenMain, debtTag, &m_totalPokos, 9, false, false, arc);
	m_counterTreasureMax->setCenteringMode(og::Screen::CallBack_CounterRV::ECM_Unknown1);

	if (!disp->m_debtPayed && (disp->m_caveComp || disp->m_maxOtakara != disp->m_collectedOtakara)) {
		J2DPane* compPane     = m_counterTreasureMax->getMotherPane();
		compPane->m_isVisible = false;
		compPane              = m_counterTreasureCollected->getMotherPane();
		compPane->add(msVal._10, msVal._14);

		J2DPane* pane     = m_screenMain->search('PICT_008');
		pane->m_isVisible = false;

		pane              = m_screenMain->search('Ptits14');
		pane->m_isVisible = false;

		pane              = m_screenMain->search('Ptits15');
		pane->m_isVisible = false;
	}
	m_scaleMgr = new og::Screen::ScaleMgr;

	J2DPane* pane     = m_screenMain->search('Nsetp02');
	pane->m_isVisible = false;

	pane              = m_screenMain->search('Nsetp03');
	pane->m_isVisible = false;

	pane              = m_screenMain->search('Nsetp04');
	pane->m_isVisible = false;

	pane              = m_screenMain->search('Nsetp05');
	pane->m_isVisible = false;

	pane              = m_screenMain->search('Piname00');
	pane->m_messageID = '0101_00';

	pane              = m_screenMain->search('Piname01');
	pane->m_messageID = '0101_00';

	m_saveMgr = ebi::Save::TMgr::createInstance();
	loadSaveMgrResources();
	m_saveMgr->setControllers(getGamePad());
	m_saveMgr->m_saveType = 1;
	m_efxComp             = new efx2d::T2DCavecompLoop;

	if (disp->m_heap) {
		oldHeap->becomeCurrentHeap();
	}
}

/*
 * --INFO--
 * Address:	803F93F8
 * Size:	00034C
 */
bool ObjCaveResult::doUpdate()
{
	JUT_ASSERTLINE(376, getDispMember()->isID(OWNER_KH, MEMBER_CAVE_RESULT), "disp member err");

	DispCaveResult* disp = static_cast<DispCaveResult*>(getDispMember());
	updateAnimation();

	if (isFlag(CAVERESFLAG_SaveOpen)) {
		m_saveMgr->update();
		if (m_saveMgr->isFinish()) {
			switch (m_saveMgr->_474) {
			case 2:
			case 0:
				disp->m_isFinished = 1;
				break;

			case 1:
				resetFlag(CAVERESFLAG_SaveOpen);
				break;
			}
		}

	} else {
		switch (m_status) {
		case CAVERES_Normal:
			statusNormal();
			break;
		case CAVERES_ScrollUp:
			statusScrollUp();
			break;
		case CAVERES_ScrollDown:
			statusScrollDown();
			break;
		case CAVERES_ForceScroll:
			statusForceScroll();
			break;
		case CAVERES_DrumRoll:
			statusDrumRoll();
			break;
		case CAVERES_Lost:
			statusLost();
			break;
		case CAVERES_DecP:
			statusDecP();
			break;
		case CAVERES_Effect:
			statusEffect();
			break;
		case CAVERES_AllMoney:
			statusAllMoney();
			break;
		}

		Controller* pad = getGamePad();
		if (pad->m_padButton.m_buttonDown & Controller::PRESS_A) {
			if (!isFlag(CAVERESFLAG_PikisKilledShown)) {
				setFlag(CAVERESFLAG_FinishAutoScroll);
			}
			if (m_status == CAVERES_Normal) {
				setFlag(CAVERESFLAG_SaveOpen);
				m_efxComp->fade();
				m_saveMgr->start();
			}
		}

		if (isFlag(CAVERESFLAG_FinishAutoScroll)) {
			m_scrollSelIndex  = m_scrollSelIndexMax;
			m_scrollPos       = -m_scrollUpDown * (f32)m_scrollSelIndex;
			m_scrollMoveTimer = 0;
			m_cavePokos       = disp->m_cavePokos;
			m_deadPiki        = disp->m_deadPikis;
			m_totalPokos      = disp->m_totalPokos;
			m_otakaraCount    = disp->m_collectedOtakara;
			m_counterCavePokos->startPuyoUp(1.0f);
			m_counterDeadPiki->startPuyoUp(1.0f);
			m_counterTotalPokos->startPuyoUp(1.0f);
			PSSystem::spSysIF->playSystemSe(PSSE_SY_REGI_SUM_UP, 0);
			pikminSE();

			if (disp->m_caveComp) {
				m_status           = CAVERES_Effect;
				m_changeStateDelay = msVal._3B;
			} else {
				m_otakaraCount = disp->m_collectedOtakara;
				m_status       = CAVERES_Normal;
			}

			kh::Screen::LostItemMgr* mgr;
			FOREACH_NODE(Game::Result::TNode, m_resultNode->m_child, cNode)
			{
				mgr = cNode->m_itemMgr;
				if ((int)mgr->isFlag(0x1) != 1 && mgr->m_maxPanes != 0) {
					mgr->setFlag(0x2);
				}
			}
			resetFlag(CAVERESFLAG_FinishAutoScroll);
			setFlag(CAVERESFLAG_PikisKilledShown);
		}
	}

	if (!isFlag(CAVERESFLAG_SaveOpen) && (m_status != CAVERES_Effect) && m_alpha != 0) {
		m_alpha -= msVal._3A;
	}

	return false;
}

/*
 * --INFO--
 * Address:	803F9744
 * Size:	000760
 */
void ObjCaveResult::doDraw(Graphics& gfx)
{
	J2DPane* pane1       = m_screenMain->search('NALL2');
	J2DPane* paneList[2] = { m_screenMain->search('Nsetp00'), m_screenMain->search('Nsetp01') };
	J2DPane* pane2       = m_screenMain->search('N3DALL');

	u64 nametags[2] = { 'Piname00', 'Piname01' };
	u64 icontags[2] = { 'iPicon00', 'iPicon01' };

	gfx.m_orthoGraph.setPort();
	pane1->m_isVisible       = true;
	pane2->m_isVisible       = false;
	paneList[0]->m_isVisible = false;
	paneList[1]->m_isVisible = false;

	J2DPane** list = paneList;
	m_screenMain->draw(gfx, gfx.m_orthoGraph);

	u32 x, y, wd, ht;
	x  = 0;
	y  = 0;
	wd = 0;
	ht = 0;
	GXGetScissor(&x, &y, &wd, &ht);
	GXSetScissor(x, _E8, wd, _EC);

	pane1->m_isVisible = false;
	pane2->m_isVisible = false;

	f32 offs = m_scrollUpDown * 2.0f;
	for (int i = 0; i < 2; i++) {
		list[i]->add(0.0f, m_scrollPos - offs);
	}

	for (int i = 0; i < 2; i++) {
		J2DPane* pane     = m_screenMain->search(nametags[i]);
		pane->m_isVisible = true;
		pane              = m_screenMain->search(icontags[i]);
		pane->m_isVisible = true;
		m_counterOtaValues[i]->show();
	}

	u32 i = 0;
	int next;
	FOREACH_NODE(Game::Result::TNode, m_resultNode->m_child, cNode)
	{
		u32 isOdd = i & 1;
		f32 calc  = (f32)i * m_scrollUpDown + m_scrollPos;

		if (calc < -m_scrollUpDown || _EC < calc) {
			paneList[isOdd]->add(0.0f, offs);
		} else {
			if (((int)cNode->m_itemMgr->m_flags & LOSTITEM_Unk2) == 2) {
				if (cNode->m_quantity < 0) {
					next = 0;
				} else {
					next = cNode->_30 * cNode->m_quantity;
				}
				setAlpha(isOdd, 48);
			} else {
				next = cNode->getNextIndex(cNode->_30, cNode->m_isLost);
				setAlpha(isOdd, 255);
			}
			J2DPane* pane                = paneList[isOdd];
			pane->m_isVisible            = false;
			paneList[isOdd]->m_isVisible = true;
			paneList[isOdd]->add(0.0f, offs);
			setTex(m_screenMain, icontags[isOdd], cNode->m_texture->_20);
			u64 tag = cNode->m_mesgTag;
			if (tag == 0) {
				m_screenMain->search(icontags[isOdd])->m_isVisible = false;
			} else {
				m_screenMain->search(icontags[isOdd])->m_messageID = tag;
			}
			m_currOtaValues[isOdd] = next;
			m_counterOtaValues[isOdd]->update();
			m_screenMain->draw(gfx, gfx.m_orthoGraph);
		}
		i++;
	}

	for (; i < 6; i++) {
		int isOdd                    = i & 1;
		paneList[isOdd]->m_isVisible = false;
		paneList[isOdd]->m_isVisible = true;
		paneList[isOdd]->add(0.0f, offs);
		setAlpha(isOdd, 255);
		m_screenMain->search(icontags[isOdd])->m_isVisible = false;
		m_screenMain->search(nametags[isOdd])->m_isVisible = false;
		m_counterOtaValues[i]->hide();
		m_screenMain->draw(gfx, gfx.m_orthoGraph);
	}

	GXSetScissor(x, y, wd, ht);
	pane1->m_isVisible       = true;
	pane2->m_isVisible       = false;
	paneList[0]->m_isVisible = false;
	paneList[1]->m_isVisible = false;
	m_screenMain->draw(gfx, gfx.m_orthoGraph);

	FOREACH_NODE(Game::Result::TNode, m_resultNode->m_child, cNode)
	{
		cNode->m_itemMgr->draw(m_screenDropItem, 'iPicon00', cNode->m_texture->_20, gfx);
	}

	if (m_alpha) {
		gfx.m_orthoGraph.setPort();
		JUtility::TColor c(m_alpha);
		gfx.m_orthoGraph.setColor(c);

		int x = System::getRenderModeObj()->fbWidth;
		int y = System::getRenderModeObj()->efbHeight;
		JGeometry::TBox2f box(0.0f, x, 0.0f, y);
		gfx.m_orthoGraph.fillBox(box);
	}

	if (isFlag(CAVERESFLAG_DrawComp)) {
		gfx.m_orthoGraph.setPort();
		m_screenComplete->draw(gfx, gfx.m_orthoGraph);
	}

	if (isFlag(CAVERESFLAG_SaveOpen)) {
		gfx.m_orthoGraph.setPort();
		m_saveMgr->draw();
	}

	/*
stwu     r1, -0xd0(r1)
mflr     r0
stw      r0, 0xd4(r1)
stfd     f31, 0xc0(r1)
psq_st   f31, 200(r1), 0, qr0
stfd     f30, 0xb0(r1)
psq_st   f30, 184(r1), 0, qr0
stmw     r20, 0x80(r1)
mr       r20, r3
lis      r5, 0x414C4C32@ha
lwz      r3, 0x40(r3)
mr       r21, r4
addi     r6, r5, 0x414C4C32@l
li       r5, 0x4e
lwz      r12, 0(r3)
lwz      r12, 0x3c(r12)
mtctr    r12
bctrl
mr       r29, r3
lwz      r3, 0x40(r20)
lwz      r7, lbl_80520EC0@sda21(r2)
lis      r5, 0x74703030@ha
lwz      r12, 0(r3)
lis      r4, 0x004E7365@ha
lwz      r0, lbl_80520EC4@sda21(r2)
addi     r6, r5, 0x74703030@l
lwz      r12, 0x3c(r12)
addi     r5, r4, 0x004E7365@l
stw      r7, 0x2c(r1)
stw      r0, 0x30(r1)
mtctr    r12
bctrl
stw      r3, 0x2c(r1)
lis      r5, 0x74703031@ha
lwz      r3, 0x40(r20)
lis      r4, 0x004E7365@ha
addi     r6, r5, 0x74703031@l
lwz      r12, 0(r3)
addi     r5, r4, 0x004E7365@l
lwz      r12, 0x3c(r12)
mtctr    r12
bctrl
stw      r3, 0x30(r1)
lis      r4, 0x44414C4C@ha
lwz      r3, 0x40(r20)
addi     r6, r4, 0x44414C4C@l
li       r5, 0x4e33
lwz      r12, 0(r3)
lwz      r12, 0x3c(r12)
mtctr    r12
bctrl
lis      r5, lbl_80498450@ha
lfdu     f3, lbl_80498450@l(r5)
lis      r4, lbl_80498460@ha
lfdu     f1, lbl_80498460@l(r4)
lfd      f2, 8(r5)
mr       r30, r3
lfd      f0, 8(r4)
addi     r3, r21, 0xbc
stfd     f3, 0x58(r1)
stfd     f2, 0x60(r1)
stfd     f1, 0x48(r1)
stfd     f0, 0x50(r1)
lwz      r12, 0xbc(r21)
lwz      r12, 0x14(r12)
mtctr    r12
bctrl
li       r3, 1
li       r0, 0
stb      r3, 0xb0(r29)
mr       r4, r21
lwz      r6, 0x2c(r1)
addi     r22, r1, 0x2c
stb      r0, 0xb0(r30)
addi     r5, r21, 0xbc
lwz      r3, 0x30(r1)
stb      r0, 0xb0(r6)
stb      r0, 0xb0(r3)
lwz      r3, 0x40(r20)
lwz      r12, 0(r3)
lwz      r12, 0x9c(r12)
mtctr    r12
bctrl
li       r0, 0
addi     r3, r1, 0x28
stw      r0, 0x28(r1)
addi     r4, r1, 0x24
addi     r5, r1, 0x20
addi     r6, r1, 0x1c
stw      r0, 0x24(r1)
stw      r0, 0x20(r1)
stw      r0, 0x1c(r1)
bl       GXGetScissor
lwz      r3, 0x28(r1)
lwz      r4, 0xe8(r20)
lwz      r5, 0x20(r1)
lwz      r6, 0xec(r20)
bl       GXSetScissor
li       r0, 0
lfs      f1, lbl_8051FFBC@sda21(r2)
stb      r0, 0xb0(r29)
li       r23, 0
stb      r0, 0xb0(r30)
lfs      f0, 0xd4(r20)
fmuls    f30, f1, f0

lbl_803F98E8:
lwz      r3, 0(r22)
lfs      f0, 0xd0(r20)
lwz      r12, 0(r3)
fsubs    f2, f0, f30
lfs      f1, lbl_8051FFA8@sda21(r2)
lwz      r12, 0x14(r12)
mtctr    r12
bctrl
addi     r23, r23, 1
addi     r22, r22, 4
cmpwi    r23, 2
blt      lbl_803F98E8
mr       r24, r20
addi     r22, r1, 0x58
addi     r23, r1, 0x48
li       r25, 0

lbl_803F9928:
lwz      r3, 0x40(r20)
lwz      r5, 0(r22)
lwz      r12, 0(r3)
lwz      r6, 4(r22)
lwz      r12, 0x3c(r12)
mtctr    r12
bctrl
li       r0, 1
stb      r0, 0xb0(r3)
lwz      r3, 0x40(r20)
lwz      r5, 0(r23)
lwz      r12, 0(r3)
lwz      r6, 4(r23)
lwz      r12, 0x3c(r12)
mtctr    r12
bctrl
li       r0, 1
stb      r0, 0xb0(r3)
lwz      r3, 0xa0(r24)
lwz      r12, 0(r3)
lwz      r12, 0x20(r12)
mtctr    r12
bctrl
addi     r25, r25, 1
addi     r23, r23, 8
cmpwi    r25, 2
addi     r24, r24, 4
addi     r22, r22, 8
blt      lbl_803F9928
lwz      r3, 0x3c(r20)
li       r24, 0
lfd      f31, lbl_8051FFC0@sda21(r2)
lis      r31, 0x4330
lwz      r23, 0x24(r3)
b        lbl_803F9BCC

lbl_803F99B4:
stw      r24, 0x6c(r1)
clrlwi   r26, r24, 0x1f
lfs      f3, 0xd4(r20)
stw      r31, 0x68(r1)
lfs      f1, 0xd0(r20)
fneg     f0, f3
lfd      f2, 0x68(r1)
fsubs    f2, f2, f31
fmadds   f1, f2, f3, f1
fcmpo    cr0, f1, f0
blt      lbl_803F9A00
lwz      r3, 0xec(r20)
lis      r0, 0x4330
stw      r0, 0x68(r1)
stw      r3, 0x6c(r1)
lfd      f0, 0x68(r1)
fsubs    f0, f0, f31
fcmpo    cr0, f0, f1
bge      lbl_803F9A28

lbl_803F9A00:
slwi     r0, r26, 2
addi     r3, r1, 0x2c
lwzx     r3, r3, r0
fmr      f2, f30
lfs      f1, lbl_8051FFA8@sda21(r2)
lwz      r12, 0(r3)
lwz      r12, 0x14(r12)
mtctr    r12
bctrl
b        lbl_803F9BC4

lbl_803F9A28:
lwz      r3, 0x48(r23)
lwz      r0, 8(r3)
rlwinm   r0, r0, 0, 0x1e, 0x1e
cmpwi    r0, 2
bne      lbl_803F9A6C
lwz      r3, 0x3c(r23)
cmpwi    r3, 0
bge      lbl_803F9A50
li       r22, 0
b        lbl_803F9A58

lbl_803F9A50:
lwz      r0, 0x30(r23)
mullw    r22, r0, r3

lbl_803F9A58:
mr       r3, r20
mr       r4, r26
li       r5, 0x30
bl       setAlpha__Q32kh6Screen13ObjCaveResultFiUc
b        lbl_803F9AA0

lbl_803F9A6C:
lwz      r4, 0x3c(r23)
lwz      r3, 0x30(r23)
lwz      r0, 0x34(r23)
cmpwi    r4, 0
add      r0, r3, r0
bge      lbl_803F9A8C
lwz      r22, 0x38(r23)
b        lbl_803F9A90

lbl_803F9A8C:
mullw    r22, r0, r4

lbl_803F9A90:
mr       r3, r20
mr       r4, r26
li       r5, 0xff
bl       setAlpha__Q32kh6Screen13ObjCaveResultFiUc

lbl_803F9AA0:
cntlzw   r0, r26
addi     r3, r1, 0x2c
rlwinm   r0, r0, 0x1d, 0x16, 0x1d
slwi     r25, r26, 2
lwzx     r4, r3, r0
li       r5, 0
lwzx     r3, r3, r25
li       r0, 1
stb      r5, 0xb0(r4)
fmr      f2, f30
lfs      f1, lbl_8051FFA8@sda21(r2)
stb      r0, 0xb0(r3)
lwz      r12, 0(r3)
lwz      r12, 0x14(r12)
mtctr    r12
bctrl
lwz      r4, 0x2c(r23)
slwi     r26, r26, 3
addi     r0, r1, 0x58
lwz      r3, 0x40(r20)
add      r6, r0, r26
lwz      r7, 0x20(r4)
lwz      r5, 0(r6)
lwz      r6, 4(r6)
bl       setTex__Q22kh6ScreenFP9J2DScreenUxPC7ResTIMG
lwz      r28, 0x40(r23)
li       r3, 0
lwz      r27, 0x44(r23)
xor      r0, r28, r3
xor      r3, r27, r3
or.      r0, r3, r0
bne      lbl_803F9B50
lwz      r3, 0x40(r20)
addi     r0, r1, 0x48
add      r6, r0, r26
lwz      r12, 0(r3)
lwz      r5, 0(r6)
lwz      r12, 0x3c(r12)
lwz      r6, 4(r6)
mtctr    r12
bctrl
li       r0, 0
stb      r0, 0xb0(r3)
b        lbl_803F9B8C

lbl_803F9B50:
lwz      r3, 0x40(r20)
addi     r0, r1, 0x48
add      r6, r0, r26
lwz      r12, 0(r3)
lwz      r5, 0(r6)
lwz      r12, 0x3c(r12)
lwz      r6, 4(r6)
mtctr    r12
bctrl
li       r0, 1
li       r4, 0
addc     r0, r27, r0
stw      r0, 0x1c(r3)
adde     r0, r28, r4
stw      r0, 0x18(r3)

lbl_803F9B8C:
add      r3, r20, r25
stw      r22, 0xbc(r3)
lwz      r3, 0xa0(r3)
lwz      r12, 0(r3)
lwz      r12, 0x10(r12)
mtctr    r12
bctrl
lwz      r3, 0x40(r20)
mr       r4, r21
addi     r5, r21, 0xbc
lwz      r12, 0(r3)
lwz      r12, 0x9c(r12)
mtctr    r12
bctrl

lbl_803F9BC4:
lwz      r23, 0x18(r23)
addi     r24, r24, 1

lbl_803F9BCC:
cmplwi   r23, 0
bne      lbl_803F99B4
addi     r26, r1, 0x2c
addi     r23, r1, 0x58
addi     r22, r1, 0x48
b        lbl_803F9CC0

lbl_803F9BE4:
clrlwi   r27, r24, 0x1f
rlwinm   r25, r24, 2, 0x1d, 0x1d
cntlzw   r0, r27
li       r5, 0
rlwinm   r0, r0, 0x1d, 0x16, 0x1d
lwzx     r3, r26, r25
lwzx     r4, r26, r0
li       r0, 1
fmr      f2, f30
lfs      f1, lbl_8051FFA8@sda21(r2)
stb      r5, 0xb0(r4)
stb      r0, 0xb0(r3)
lwz      r12, 0(r3)
lwz      r12, 0x14(r12)
mtctr    r12
bctrl
mr       r3, r20
mr       r4, r27
li       r5, 0xff
bl       setAlpha__Q32kh6Screen13ObjCaveResultFiUc
lwz      r3, 0x40(r20)
slwi     r27, r27, 3
add      r6, r23, r27
lwz      r12, 0(r3)
lwz      r5, 0(r6)
lwz      r12, 0x3c(r12)
lwz      r6, 4(r6)
mtctr    r12
bctrl
li       r0, 0
add      r6, r22, r27
stb      r0, 0xb0(r3)
lwz      r3, 0x40(r20)
lwz      r5, 0(r6)
lwz      r12, 0(r3)
lwz      r6, 4(r6)
lwz      r12, 0x3c(r12)
mtctr    r12
bctrl
li       r4, 0
addi     r0, r25, 0xa0
stb      r4, 0xb0(r3)
lwzx     r3, r20, r0
lwz      r12, 0(r3)
lwz      r12, 0x24(r12)
mtctr    r12
bctrl
lwz      r3, 0x40(r20)
mr       r4, r21
addi     r5, r21, 0xbc
lwz      r12, 0(r3)
lwz      r12, 0x9c(r12)
mtctr    r12
bctrl
addi     r24, r24, 1

lbl_803F9CC0:
cmplwi   r24, 6
blt      lbl_803F9BE4
lwz      r3, 0x28(r1)
lwz      r4, 0x24(r1)
lwz      r5, 0x20(r1)
lwz      r6, 0x1c(r1)
bl       GXSetScissor
li       r7, 0
li       r0, 1
stb      r7, 0xb0(r29)
mr       r4, r21
lwz      r6, 0x2c(r1)
addi     r5, r21, 0xbc
stb      r0, 0xb0(r30)
lwz      r3, 0x30(r1)
stb      r7, 0xb0(r6)
stb      r7, 0xb0(r3)
lwz      r3, 0x40(r20)
lwz      r12, 0(r3)
lwz      r12, 0x9c(r12)
mtctr    r12
bctrl
lwz      r3, 0x3c(r20)
lis      r23, 0x6f6e
lis      r22, 0x6950
lwz      r24, 0x24(r3)
b        lbl_803F9D50

lbl_803F9D2C:
lwz      r7, 0x2c(r24)
mr       r8, r21
lwz      r3, 0x48(r24)
addi     r6, r23, 0x3030
lwz      r4, 0x44(r20)
addi     r5, r22, 0x6963
lwz      r7, 0x20(r7)
bl
draw__Q32kh6Screen11LostItemMgrFPQ29P2DScreen10Mgr_tuningUxPC7ResTIMGR8Graphics
lwz      r24, 0x18(r24)

lbl_803F9D50:
cmplwi   r24, 0
bne      lbl_803F9D2C
lbz      r0, 0x105(r20)
cmplwi   r0, 0
beq      lbl_803F9E1C
addi     r3, r21, 0xbc
lwz      r12, 0xbc(r21)
lwz      r12, 0x14(r12)
mtctr    r12
bctrl
lbz      r0, 0x105(r20)
li       r8, 0
stb      r8, 0x18(r1)
addi     r3, r21, 0xbc
addi     r4, r1, 8
addi     r5, r1, 0xc
stb      r8, 0x19(r1)
addi     r6, r1, 0x10
addi     r7, r1, 0x14
stb      r8, 0x1a(r1)
stb      r0, 0x1b(r1)
lwz      r0, 0x18(r1)
stw      r0, 0x14(r1)
stw      r0, 0x10(r1)
stw      r0, 0xc(r1)
stw      r0, 8(r1)
bl
setColor__14J2DGrafContextFQ28JUtility6TColorQ28JUtility6TColorQ28JUtility6TColorQ28JUtility6TColor
bl       getRenderModeObj__6SystemFv
lhz      r22, 6(r3)
bl       getRenderModeObj__6SystemFv
lhz      r4, 4(r3)
lis      r0, 0x4330
lfs      f3, lbl_8051FFA8@sda21(r2)
addi     r3, r21, 0xbc
stw      r4, 0x6c(r1)
addi     r4, r1, 0x34
lfd      f2, lbl_8051FFC0@sda21(r2)
stw      r0, 0x68(r1)
lfd      f0, 0x68(r1)
stw      r22, 0x74(r1)
fsubs    f1, f0, f2
stw      r0, 0x70(r1)
lfd      f0, 0x70(r1)
fadds    f1, f3, f1
stfs     f3, 0x34(r1)
fsubs    f0, f0, f2
stfs     f3, 0x38(r1)
fadds    f0, f3, f0
stfs     f1, 0x3c(r1)
stfs     f0, 0x40(r1)
bl       "fillBox__14J2DGrafContextFRCQ29JGeometry8TBox2<f>"

lbl_803F9E1C:
lbz      r0, 0x104(r20)
rlwinm.  r0, r0, 0, 0x1b, 0x1b
beq      lbl_803F9E58
addi     r3, r21, 0xbc
lwz      r12, 0xbc(r21)
lwz      r12, 0x14(r12)
mtctr    r12
bctrl
lwz      r3, 0x48(r20)
mr       r4, r21
addi     r5, r21, 0xbc
lwz      r12, 0(r3)
lwz      r12, 0x9c(r12)
mtctr    r12
bctrl

lbl_803F9E58:
lbz      r0, 0x104(r20)
rlwinm.  r0, r0, 0, 0x1d, 0x1d
beq      lbl_803F9E80
addi     r3, r21, 0x190
lwz      r12, 0x190(r21)
lwz      r12, 0x14(r12)
mtctr    r12
bctrl
lwz      r3, 0x38(r20)
bl       draw__Q33ebi4Save4TMgrFv

lbl_803F9E80:
psq_l    f31, 200(r1), 0, qr0
lfd      f31, 0xc0(r1)
psq_l    f30, 184(r1), 0, qr0
lfd      f30, 0xb0(r1)
lmw      r20, 0x80(r1)
lwz      r0, 0xd4(r1)
mtlr     r0
addi     r1, r1, 0xd0
blr
	*/
}

/*
 * --INFO--
 * Address:	803F9EA4
 * Size:	000068
 */
bool ObjCaveResult::doUpdateFadein()
{
	updateAnimation();

	m_alpha -= msVal._38;
	if (m_alpha < msVal._38) {
		m_alpha = 0;
		return true;
	}

	return false;
}

/*
 * --INFO--
 * Address:	803F9F0C
 * Size:	000014
 */
void ObjCaveResult::doUpdateFadeinFinish()
{
	_FC  = 175.0f;
	_100 = 224.5f;
}

/*
 * --INFO--
 * Address:	803F9F20
 * Size:	00006C
 */
bool ObjCaveResult::doUpdateFadeout()
{
	updateAnimation();
	m_alpha += msVal._38;
	if (m_alpha > (255 - msVal._38)) {
		m_alpha = 255;
		return true;
	}
	return false;
}

/*
 * --INFO--
 * Address:	803F9F8C
 * Size:	0001DC
 */
void ObjCaveResult::statusNormal()
{
	if (isFlag(CAVERESFLAG_CanScroll)) {
		// at top of scroll list
		if (!m_scrollSelIndex) {
			m_fadePaneUpArrow->fadeout();
			m_fadePaneDownArrow->fadein();
			m_stickAnim->stickDown();
		}
		// at bottom of scroll list
		else if (m_scrollSelIndex == m_scrollSelIndexMax) {
			m_fadePaneUpArrow->fadein();
			m_fadePaneDownArrow->fadeout();
			m_stickAnim->stickUp();
		}
		// in middle of sroll list
		else {
			m_fadePaneUpArrow->fadein();
			m_fadePaneDownArrow->fadein();
			m_stickAnim->stickUpDown();
		}
		m_fadePane1->fadein();
	} else {
		m_fadePaneUpArrow->fadeout();
		m_fadePaneDownArrow->fadeout();
		m_fadePane1->fadeout();
	}

	m_fadePane4->fadein();
	if (isFlag(CAVERESFLAG_CanScroll)) {
		// press up, begin scroll up state
		if (getGamePad()->m_padButton.m_mask & (Controller::PRESS_DPAD_UP | Controller::UNKNOWN_32) && m_scrollSelIndex) {
			m_scrollSelIndex--;
			if (_106 >= 1) {
				m_scrollTargetDist = msVal._20;
			} else {
				_106++;
			}

			_107     = 0;
			m_status = CAVERES_ScrollUp;
			statusScrollUp();
			return;
		}

		// press down, begin scroll down state
		if (getGamePad()->m_padButton.m_mask & (Controller::PRESS_DPAD_DOWN | Controller::UNKNOWN_31)
		    && m_scrollSelIndex != m_scrollSelIndexMax) {
			m_scrollSelIndex++;
			if (_107 >= 1) {
				m_scrollTargetDist = msVal._20;
			} else {
				_107++;
			}
			_106     = 0;
			m_status = CAVERES_ScrollDown;
			statusScrollDown();
			return;
		}

		_107               = 0;
		_106               = 0;
		m_scrollTargetDist = msVal._1C;
	}
}

/*
 * --INFO--
 * Address:	803FA168
 * Size:	0000F4
 */
void ObjCaveResult::statusScrollUp()
{
	m_scrollPos = -(((m_scrollMoveTimer * m_scrollUpDown)
	                 + (m_scrollSelIndex * m_scrollUpDown) * ((m_scrollSelIndex + 1) * m_scrollTargetDist - m_scrollMoveTimer))
	                / m_scrollTargetDist);
	int e       = m_scrollMoveTimer;
	m_scrollMoveTimer++;
	if (e == m_scrollTargetDist) {
		m_scrollMoveTimer = 1;
		m_status          = CAVERES_Normal;
	}
	PSSystem::spSysIF->playSystemSe(PSSE_SY_REGI_ROLL, 0);
	/*
stwu     r1, -0x30(r1)
mflr     r0
lis      r6, 0x4330
lfd      f4, lbl_8051FFB0@sda21(r2)
stw      r0, 0x34(r1)
lwz      r4, 0xd8(r3)
stw      r6, 0x18(r1)
addi     r0, r4, 1
xoris    r5, r4, 0x8000
xoris    r0, r0, 0x8000
lwz      r8, 0xe0(r3)
stw      r0, 0x1c(r1)
lwz      r7, 0xe4(r3)
lfd      f0, 0x18(r1)
subf     r0, r7, r8
stw      r5, 0x14(r1)
xoris    r4, r0, 0x8000
fsubs    f0, f0, f4
stw      r6, 0x10(r1)
xoris    r7, r7, 0x8000
lfs      f3, 0xd4(r3)
xoris    r0, r8, 0x8000
lfd      f2, 0x10(r1)
stw      r4, 0x24(r1)
fmuls    f1, f3, f0
fsubs    f2, f2, f4
stw      r6, 0x20(r1)
lfd      f0, 0x20(r1)
fmuls    f2, f3, f2
stw      r7, 0xc(r1)
fsubs    f0, f0, f4
stw      r6, 8(r1)
lfd      f3, 8(r1)
fmuls    f1, f1, f0
stw      r0, 0x2c(r1)
fsubs    f3, f3, f4
stw      r6, 0x28(r1)
lfd      f0, 0x28(r1)
fmadds   f1, f3, f2, f1
fsubs    f0, f0, f4
fdivs    f0, f1, f0
fneg     f0, f0
stfs     f0, 0xd0(r3)
lwz      r4, 0xe4(r3)
addi     r0, r4, 1
stw      r0, 0xe4(r3)
lwz      r0, 0xe0(r3)
cmpw     r4, r0
bne      lbl_803FA23C
li       r4, 1
li       r0, 0
stw      r4, 0xe4(r3)
stw      r0, 0xf0(r3)

lbl_803FA23C:
lwz      r3, spSysIF__8PSSystem@sda21(r13)
li       r4, 0x101a
li       r5, 0
bl       playSystemSe__Q28PSSystem5SysIFFUlUl
lwz      r0, 0x34(r1)
mtlr     r0
addi     r1, r1, 0x30
blr
	*/
}

/*
 * --INFO--
 * Address:	803FA25C
 * Size:	0000F4
 */
void ObjCaveResult::statusScrollDown()
{
	m_scrollPos = -(((m_scrollMoveTimer * m_scrollUpDown)
	                 + (m_scrollSelIndex * m_scrollUpDown) * ((m_scrollSelIndex - 1) * m_scrollTargetDist - m_scrollMoveTimer))
	                / m_scrollTargetDist);
	int e       = m_scrollMoveTimer;
	m_scrollMoveTimer++;
	if (e == m_scrollTargetDist) {
		m_scrollMoveTimer = 1;
		m_status          = CAVERES_Normal;
	}
	PSSystem::spSysIF->playSystemSe(PSSE_SY_REGI_ROLL, 0);
	/*
stwu     r1, -0x30(r1)
mflr     r0
lis      r6, 0x4330
lfd      f4, lbl_8051FFB0@sda21(r2)
stw      r0, 0x34(r1)
lwz      r4, 0xd8(r3)
stw      r6, 0x18(r1)
addi     r0, r4, -1
xoris    r5, r4, 0x8000
xoris    r0, r0, 0x8000
lwz      r8, 0xe0(r3)
stw      r0, 0x1c(r1)
lwz      r7, 0xe4(r3)
lfd      f0, 0x18(r1)
subf     r0, r7, r8
stw      r5, 0x14(r1)
xoris    r4, r0, 0x8000
fsubs    f0, f0, f4
stw      r6, 0x10(r1)
xoris    r7, r7, 0x8000
lfs      f3, 0xd4(r3)
xoris    r0, r8, 0x8000
lfd      f2, 0x10(r1)
stw      r4, 0x24(r1)
fmuls    f1, f3, f0
fsubs    f2, f2, f4
stw      r6, 0x20(r1)
lfd      f0, 0x20(r1)
fmuls    f2, f3, f2
stw      r7, 0xc(r1)
fsubs    f0, f0, f4
stw      r6, 8(r1)
lfd      f3, 8(r1)
fmuls    f1, f1, f0
stw      r0, 0x2c(r1)
fsubs    f3, f3, f4
stw      r6, 0x28(r1)
lfd      f0, 0x28(r1)
fmadds   f1, f3, f2, f1
fsubs    f0, f0, f4
fdivs    f0, f1, f0
fneg     f0, f0
stfs     f0, 0xd0(r3)
lwz      r4, 0xe4(r3)
addi     r0, r4, 1
stw      r0, 0xe4(r3)
lwz      r0, 0xe0(r3)
cmpw     r4, r0
bne      lbl_803FA330
li       r4, 1
li       r0, 0
stw      r4, 0xe4(r3)
stw      r0, 0xf0(r3)

lbl_803FA330:
lwz      r3, spSysIF__8PSSystem@sda21(r13)
li       r4, 0x101a
li       r5, 0
bl       playSystemSe__Q28PSSystem5SysIFFUlUl
lwz      r0, 0x34(r1)
mtlr     r0
addi     r1, r1, 0x30
blr
	*/
}

/*
 * --INFO--
 * Address:	803FA350
 * Size:	0002F0
 */
void ObjCaveResult::statusForceScroll()
{
	m_scrollPos = -(((m_scrollMoveTimer * m_scrollUpDown)
	                 + (m_scrollSelIndex * m_scrollUpDown) * ((m_scrollSelIndex - 1) * m_scrollTargetDist - m_scrollMoveTimer))
	                / m_scrollTargetDist);

	int e = m_scrollMoveTimer;
	m_scrollMoveTimer++;
	if (e == m_scrollTargetDist) {
		if (m_scrollSelIndex == m_scrollSelIndexMax) {
			bool check        = false;
			m_scrollMoveTimer = 1;
			FOREACH_NODE(Game::Result::TNode, m_resultNode->m_child, cNode)
			{
				if ((cNode->m_itemMgr->m_flags & LOSTITEM_Unk2 != 2) && cNode->m_isLost) {
					m_status           = CAVERES_Lost;
					check              = true;
					m_changeStateDelay = 0;
				}
			}
			if (check) {
				m_status           = CAVERES_AllMoney;
				m_changeStateDelay = msVal._3B;
			}
		} else {
			JUT_ASSERTLINE(829, getDispMember()->isID(OWNER_KH, MEMBER_CAVE_RESULT), "disp member err");
			getDispMember();
			Game::Result::TNode* node = static_cast<Game::Result::TNode*>(m_resultNode->m_child);
			for (int i = 0; node && i != m_scrollSelIndex + 6; i++) {
				node = static_cast<Game::Result::TNode*>(node->m_next);
			}
			if (node && !node->m_isLost) {
				if (node->m_quantity > 0) {
					m_otakaraCount++;
				}
				if (node->m_quantity > 0 || !node->m_isLost) {
					m_cavePokos += node->m_pokoValue;
				}
				PSSystem::spSysIF->playSystemSe(PSSE_SY_COIN_COUNT, 0);
			}
			m_scrollMoveTimer = 1;
			m_scrollSelIndex++;
		}
	}
	int i = 0;
	JGeometry::TVec2f pos(_FC, _100);
	FOREACH_NODE(Game::Result::TNode, m_resultNode->m_child, cNode)
	{
		if (i == m_scrollSelIndex + 2 && ((cNode->m_itemMgr->m_flags & LOSTITEM_Unk1) != 1)) {
			cNode->m_itemMgr->init(pos, 0);
		}
		i++;
	}
	PSSystem::spSysIF->playSystemSe(PSSE_SY_REGI_ROLL, 0);
	/*
stwu     r1, -0x50(r1)
mflr     r0
lis      r6, 0x4330
lfd      f4, lbl_8051FFB0@sda21(r2)
stw      r0, 0x54(r1)
stw      r31, 0x4c(r1)
mr       r31, r3
stw      r30, 0x48(r1)
stw      r29, 0x44(r1)
lwz      r4, 0xd8(r3)
stw      r6, 0x20(r1)
addi     r0, r4, -1
xoris    r5, r4, 0x8000
xoris    r0, r0, 0x8000
lwz      r8, 0xe0(r3)
stw      r0, 0x24(r1)
lwz      r7, 0xe4(r3)
lfd      f0, 0x20(r1)
subf     r0, r7, r8
stw      r5, 0x1c(r1)
xoris    r4, r0, 0x8000
fsubs    f0, f0, f4
stw      r6, 0x18(r1)
xoris    r7, r7, 0x8000
lfs      f3, 0xd4(r3)
xoris    r0, r8, 0x8000
lfd      f2, 0x18(r1)
stw      r4, 0x2c(r1)
fmuls    f1, f3, f0
fsubs    f2, f2, f4
stw      r6, 0x28(r1)
lfd      f0, 0x28(r1)
fmuls    f2, f3, f2
stw      r7, 0x14(r1)
fsubs    f0, f0, f4
stw      r6, 0x10(r1)
lfd      f3, 0x10(r1)
fmuls    f1, f1, f0
stw      r0, 0x34(r1)
fsubs    f3, f3, f4
stw      r6, 0x30(r1)
lfd      f0, 0x30(r1)
fmadds   f1, f3, f2, f1
fsubs    f0, f0, f4
fdivs    f0, f1, f0
fneg     f0, f0
stfs     f0, 0xd0(r3)
lwz      r4, 0xe4(r3)
addi     r0, r4, 1
stw      r0, 0xe4(r3)
lwz      r0, 0xe0(r3)
cmpw     r4, r0
bne      lbl_803FA59C
lwz      r4, 0xd8(r31)
lwz      r0, 0xdc(r31)
cmpw     r4, r0
bne      lbl_803FA4B0
li       r0, 1
li       r5, 0
stw      r0, 0xe4(r31)
li       r3, 5
li       r0, 0
lwz      r4, 0x3c(r31)
lwz      r6, 0x24(r4)
b        lbl_803FA484

lbl_803FA454:
lwz      r4, 0x48(r6)
lwz      r4, 8(r4)
rlwinm   r4, r4, 0, 0x1e, 0x1e
cmpwi    r4, 2
beq      lbl_803FA480
lwz      r4, 0x34(r6)
cmpwi    r4, 0
beq      lbl_803FA480
stw      r3, 0xf0(r31)
li       r5, 1
stw      r0, 0xf4(r31)

lbl_803FA480:
lwz      r6, 0x18(r6)

lbl_803FA484:
cmplwi   r6, 0
bne      lbl_803FA454
clrlwi.  r0, r5, 0x18
bne      lbl_803FA59C
li       r0, 8
lis      r3, msVal__Q32kh6Screen13ObjCaveResult@ha
stw      r0, 0xf0(r31)
addi     r3, r3, msVal__Q32kh6Screen13ObjCaveResult@l
lbz      r0, 0x3b(r3)
stw      r0, 0xf4(r31)
b        lbl_803FA59C

lbl_803FA4B0:
bl       getDispMember__Q26Screen7ObjBaseFv
lis      r5, 0x52534C54@ha
li       r4, 0x4b48
addi     r6, r5, 0x52534C54@l
li       r5, 0x435f
bl       isID__Q32og6Screen14DispMemberBaseFUlUx
clrlwi.  r0, r3, 0x18
bne      lbl_803FA4EC
lis      r3, lbl_80498360@ha
lis      r5, lbl_80498374@ha
addi     r3, r3, lbl_80498360@l
li       r4, 0x33d
addi     r5, r5, lbl_80498374@l
crclr    6
bl       panic_f__12JUTExceptionFPCciPCce

lbl_803FA4EC:
mr       r3, r31
bl       getDispMember__Q26Screen7ObjBaseFv
lwz      r3, 0x3c(r31)
li       r4, 0
lwz      r5, 0x24(r3)
b        lbl_803FA50C

lbl_803FA504:
lwz      r5, 0x18(r5)
addi     r4, r4, 1

lbl_803FA50C:
cmplwi   r5, 0
beq      lbl_803FA524
lwz      r3, 0xd8(r31)
addi     r0, r3, 6
cmpw     r4, r0
bne      lbl_803FA504

lbl_803FA524:
cmplwi   r5, 0
beq      lbl_803FA588
lwz      r0, 0x34(r5)
cmpwi    r0, 0
bne      lbl_803FA588
lwz      r0, 0x3c(r5)
cmpwi    r0, 0
ble      lbl_803FA550
lwz      r3, 0xc4(r31)
addi     r0, r3, 1
stw      r0, 0xc4(r31)

lbl_803FA550:
lwz      r0, 0x3c(r5)
cmpwi    r0, 0
bgt      lbl_803FA568
lwz      r0, 0x34(r5)
cmpwi    r0, 0
bne      lbl_803FA578

lbl_803FA568:
lwz      r3, 0xb4(r31)
lwz      r0, 0x38(r5)
add      r0, r3, r0
stw      r0, 0xb4(r31)

lbl_803FA578:
lwz      r3, spSysIF__8PSSystem@sda21(r13)
li       r4, 0x181e
li       r5, 0
bl       playSystemSe__Q28PSSystem5SysIFFUlUl

lbl_803FA588:
li       r0, 1
stw      r0, 0xe4(r31)
lwz      r3, 0xd8(r31)
addi     r0, r3, 1
stw      r0, 0xd8(r31)

lbl_803FA59C:
lfs      f0, 0xfc(r31)
li       r30, 0
stfs     f0, 8(r1)
lfs      f0, 0x100(r31)
stfs     f0, 0xc(r1)
lwz      r3, 0x3c(r31)
lwz      r29, 0x24(r3)
b        lbl_803FA60C

lbl_803FA5BC:
lwz      r4, 0xd8(r31)
lwz      r3, 0x48(r29)
addi     r0, r4, 2
cmpw     r30, r0
bne      lbl_803FA604
lwz      r0, 8(r3)
clrlwi   r0, r0, 0x1f
cmpwi    r0, 1
beq      lbl_803FA604
srwi     r4, r30, 0x1f
clrlwi   r0, r30, 0x1f
xor      r0, r0, r4
subf     r5, r4, r0
addi     r4, r1, 8
neg      r0, r5
or       r0, r0, r5
srwi     r5, r0, 0x1f
bl       "init__Q32kh6Screen11LostItemMgrFRCQ29JGeometry8TVec2<f>b"

lbl_803FA604:
lwz      r29, 0x18(r29)
addi     r30, r30, 1

lbl_803FA60C:
cmplwi   r29, 0
bne      lbl_803FA5BC
lwz      r3, spSysIF__8PSSystem@sda21(r13)
li       r4, 0x101a
li       r5, 0
bl       playSystemSe__Q28PSSystem5SysIFFUlUl
lwz      r0, 0x54(r1)
lwz      r31, 0x4c(r1)
lwz      r30, 0x48(r1)
lwz      r29, 0x44(r1)
mtlr     r0
addi     r1, r1, 0x50
blr
	*/
}

/*
 * --INFO--
 * Address:	803FA640
 * Size:	00001C
 */
void ObjCaveResult::statusDrumRoll()
{
	m_changeStateDelay = msVal._3B;
	m_status           = CAVERES_AllMoney;
}

/*
 * --INFO--
 * Address:	803FA65C
 * Size:	0000C0
 */
void ObjCaveResult::statusAllMoney()
{
	if (!m_changeStateDelay) {
		JUT_ASSERTLINE(910, getDispMember()->isID(OWNER_KH, MEMBER_CAVE_RESULT), "disp member err");
		DispCaveResult* disp = static_cast<DispCaveResult*>(getDispMember());
		m_totalPokos         = disp->m_totalPokos;
		m_counterTotalPokos->startPuyoUp(1.0f);
		PSSystem::spSysIF->playSystemSe(PSSE_SY_REGI_SUM_UP, 0);
		m_changeStateDelay = msVal._3B;
		m_status           = CAVERES_DecP;
	} else {
		m_changeStateDelay--;
	}
	/*
stwu     r1, -0x10(r1)
mflr     r0
stw      r0, 0x14(r1)
stw      r31, 0xc(r1)
mr       r31, r3
lwz      r4, 0xf4(r3)
cmpwi    r4, 0
bne      lbl_803FA700
bl       getDispMember__Q26Screen7ObjBaseFv
lis      r5, 0x52534C54@ha
li       r4, 0x4b48
addi     r6, r5, 0x52534C54@l
li       r5, 0x435f
bl       isID__Q32og6Screen14DispMemberBaseFUlUx
clrlwi.  r0, r3, 0x18
bne      lbl_803FA6B8
lis      r3, lbl_80498360@ha
lis      r5, lbl_80498374@ha
addi     r3, r3, lbl_80498360@l
li       r4, 0x38e
addi     r5, r5, lbl_80498374@l
crclr    6
bl       panic_f__12JUTExceptionFPCciPCce

lbl_803FA6B8:
mr       r3, r31
bl       getDispMember__Q26Screen7ObjBaseFv
lwz      r0, 0x28(r3)
lfs      f1, lbl_8051FFB8@sda21(r2)
stw      r0, 0xcc(r31)
lwz      r3, 0xb0(r31)
bl       startPuyoUp__Q32og6Screen18CallBack_CounterRVFf
lwz      r3, spSysIF__8PSSystem@sda21(r13)
li       r4, 0x1814
li       r5, 0
bl       playSystemSe__Q28PSSystem5SysIFFUlUl
lis      r3, msVal__Q32kh6Screen13ObjCaveResult@ha
li       r0, 6
addi     r3, r3, msVal__Q32kh6Screen13ObjCaveResult@l
lbz      r3, 0x3b(r3)
stw      r3, 0xf4(r31)
stw      r0, 0xf0(r31)
b        lbl_803FA708

lbl_803FA700:
addi     r0, r4, -1
stw      r0, 0xf4(r31)

lbl_803FA708:
lwz      r0, 0x14(r1)
lwz      r31, 0xc(r1)
mtlr     r0
addi     r1, r1, 0x10
blr
	*/
}

/*
 * --INFO--
 * Address:	803FA71C
 * Size:	0000E8
 */
void ObjCaveResult::statusDecP()
{
	if (!m_changeStateDelay) {
		JUT_ASSERTLINE(934, getDispMember()->isID(OWNER_KH, MEMBER_CAVE_RESULT), "disp member err");
		DispCaveResult* disp = static_cast<DispCaveResult*>(getDispMember());
		m_deadPiki           = disp->m_deadPikis;
		m_counterDeadPiki->startPuyoUp(1.0f);
		pikminSE();
		if (disp->m_caveComp) {
			m_status           = CAVERES_Effect;
			m_changeStateDelay = msVal._3B;
		} else {
			m_status = CAVERES_Normal;
		}
		setFlag(CAVERESFLAG_PikisKilledShown);
	} else {
		m_changeStateDelay--;
	}
	/*
stwu     r1, -0x10(r1)
mflr     r0
stw      r0, 0x14(r1)
stw      r31, 0xc(r1)
mr       r31, r3
stw      r30, 8(r1)
lwz      r4, 0xf4(r3)
cmpwi    r4, 0
bne      lbl_803FA7E4
bl       getDispMember__Q26Screen7ObjBaseFv
lis      r5, 0x52534C54@ha
li       r4, 0x4b48
addi     r6, r5, 0x52534C54@l
li       r5, 0x435f
bl       isID__Q32og6Screen14DispMemberBaseFUlUx
clrlwi.  r0, r3, 0x18
bne      lbl_803FA77C
lis      r3, lbl_80498360@ha
lis      r5, lbl_80498374@ha
addi     r3, r3, lbl_80498360@l
li       r4, 0x3a6
addi     r5, r5, lbl_80498374@l
crclr    6
bl       panic_f__12JUTExceptionFPCciPCce

lbl_803FA77C:
mr       r3, r31
bl       getDispMember__Q26Screen7ObjBaseFv
mr       r30, r3
lfs      f1, lbl_8051FFB8@sda21(r2)
lwz      r0, 0x2c(r3)
stw      r0, 0xb8(r31)
lwz      r3, 0x9c(r31)
bl       startPuyoUp__Q32og6Screen18CallBack_CounterRVFf
mr       r3, r31
bl       pikminSE__Q32kh6Screen13ObjCaveResultFv
lbz      r0, 0x31(r30)
cmplwi   r0, 0
beq      lbl_803FA7CC
li       r0, 7
lis      r3, msVal__Q32kh6Screen13ObjCaveResult@ha
stw      r0, 0xf0(r31)
addi     r3, r3, msVal__Q32kh6Screen13ObjCaveResult@l
lbz      r0, 0x3b(r3)
stw      r0, 0xf4(r31)
b        lbl_803FA7D4

lbl_803FA7CC:
li       r0, 0
stw      r0, 0xf0(r31)

lbl_803FA7D4:
lbz      r0, 0x104(r31)
ori      r0, r0, 8
stb      r0, 0x104(r31)
b        lbl_803FA7EC

lbl_803FA7E4:
addi     r0, r4, -1
stw      r0, 0xf4(r31)

lbl_803FA7EC:
lwz      r0, 0x14(r1)
lwz      r31, 0xc(r1)
lwz      r30, 8(r1)
mtlr     r0
addi     r1, r1, 0x10
blr
	*/
}

/*
 * --INFO--
 * Address:	803FA804
 * Size:	000110
 */
void ObjCaveResult::statusLost()
{
	if (!m_changeStateDelay) {
		int i = 0;
		JGeometry::TVec2f pos(_FC, _100);
		FOREACH_NODE(Game::Result::TNode, m_resultNode->m_child, cNode)
		{
			if (cNode->m_isLost != 0 && ((cNode->m_itemMgr->m_flags & LOSTITEM_Unk2) != 2)) {
				pos.y += _100 * m_scrollUpDown;
				cNode->m_itemMgr->init(pos, i & 1);
				m_changeStateDelay = m_scrollTargetDist;
				return;
			}
			i++;
		}
		m_status           = CAVERES_AllMoney;
		m_changeStateDelay = msVal._3B;
	} else {
		m_changeStateDelay--;
	}

	/*
stwu     r1, -0x20(r1)
mflr     r0
stw      r0, 0x24(r1)
stw      r31, 0x1c(r1)
mr       r31, r3
lwz      r3, 0xf4(r3)
cmpwi    r3, 0
bne      lbl_803FA8F8
lfs      f0, 0xfc(r31)
li       r6, 0
stfs     f0, 8(r1)
lfs      f0, 0x100(r31)
stfs     f0, 0xc(r1)
lwz      r3, 0x3c(r31)
lwz      r4, 0x24(r3)
b        lbl_803FA8D4

lbl_803FA844:
lwz      r0, 0x34(r4)
cmpwi    r0, 0
beq      lbl_803FA8CC
lwz      r3, 0x48(r4)
lwz      r0, 8(r3)
rlwinm   r0, r0, 0, 0x1e, 0x1e
cmpwi    r0, 2
beq      lbl_803FA8CC
lwz      r5, 0xdc(r31)
addi     r4, r6, -3
lis      r0, 0x4330
lfd      f2, lbl_8051FFB0@sda21(r2)
subf     r4, r5, r4
stw      r0, 0x10(r1)
xoris    r0, r4, 0x8000
lfs      f3, 0xd4(r31)
stw      r0, 0x14(r1)
srwi     r4, r6, 0x1f
clrlwi   r0, r6, 0x1f
lfs      f0, 0xc(r1)
lfd      f1, 0x10(r1)
xor      r0, r0, r4
subf     r4, r4, r0
fsubs    f1, f1, f2
neg      r0, r4
or       r0, r0, r4
addi     r4, r1, 8
srwi     r5, r0, 0x1f
fmadds   f0, f3, f1, f0
stfs     f0, 0xc(r1)
bl       "init__Q32kh6Screen11LostItemMgrFRCQ29JGeometry8TVec2<f>b"
lwz      r0, 0xe0(r31)
stw      r0, 0xf4(r31)
b        lbl_803FA900

lbl_803FA8CC:
lwz      r4, 0x18(r4)
addi     r6, r6, 1

lbl_803FA8D4:
cmplwi   r4, 0
bne      lbl_803FA844
li       r0, 8
lis      r3, msVal__Q32kh6Screen13ObjCaveResult@ha
stw      r0, 0xf0(r31)
addi     r3, r3, msVal__Q32kh6Screen13ObjCaveResult@l
lbz      r0, 0x3b(r3)
stw      r0, 0xf4(r31)
b        lbl_803FA900

lbl_803FA8F8:
addi     r0, r3, -1
stw      r0, 0xf4(r31)

lbl_803FA900:
lwz      r0, 0x24(r1)
lwz      r31, 0x1c(r1)
mtlr     r0
addi     r1, r1, 0x20
blr
	*/
}

/*
 * --INFO--
 * Address:	803FA914
 * Size:	0001D4
 */
void ObjCaveResult::statusEffect()
{
	if (!m_changeStateDelay) {
		if (!isFlag(CAVERESFLAG_DrawComp)) {
			m_screenMain->search('Pananorm')->m_isVisible = false;
			m_screenMain->search('Panacomp')->m_isVisible = true;
			m_scaleMgr->up();
			m_counterTreasureMax->getMotherPane()->m_isVisible = true;
			m_counterTreasureCollected->getMotherPane()->add(-msVal._10, -msVal._14);
			m_screenMain->search('PICT_008')->m_isVisible = true;
			m_screenMain->search('Ptits14')->m_isVisible  = true;
			m_screenMain->search('Ptits15')->m_isVisible  = true;
			m_status                                      = CAVERES_Normal;
			PSSystem::spSysIF->playSystemSe(PSSE_SY_WMAP_CAVE_NAME, 0);
		} else {
			if (m_alpha < msVal._39)
				m_alpha += msVal._3A;
		}
	} else {
		m_changeStateDelay--;
		if (m_changeStateDelay == 0) {
			setFlag(CAVERESFLAG_DrawComp);
			PSSystem::spSysIF->playSystemSe(PSSE_DOKUTSU_COMPLETE, 0);
		}
	}
	/*
stwu     r1, -0x10(r1)
mflr     r0
stw      r0, 0x14(r1)
stw      r31, 0xc(r1)
mr       r31, r3
lwz      r3, 0xf4(r3)
cmpwi    r3, 0
bne      lbl_803FAAA4
lbz      r0, 0x104(r31)
rlwinm.  r0, r0, 0, 0x1b, 0x1b
bne      lbl_803FAA7C
lwz      r3, 0x40(r31)
lis      r5, 0x6E6F726D@ha
lis      r4, 0x50616E61@ha
lwz      r12, 0(r3)
addi     r6, r5, 0x6E6F726D@l
addi     r5, r4, 0x50616E61@l
lwz      r12, 0x3c(r12)
mtctr    r12
bctrl
li       r0, 0
lis      r5, 0x636F6D70@ha
stb      r0, 0xb0(r3)
lis      r4, 0x50616E61@ha
addi     r6, r5, 0x636F6D70@l
lwz      r3, 0x40(r31)
addi     r5, r4, 0x50616E61@l
lwz      r12, 0(r3)
lwz      r12, 0x3c(r12)
mtctr    r12
bctrl
li       r0, 1
stb      r0, 0xb0(r3)
lwz      r3, 0x84(r31)
bl       up__Q32og6Screen8ScaleMgrFv
lwz      r3, 0xac(r31)
bl       getMotherPane__Q32og6Screen18CallBack_CounterRVFv
li       r0, 1
stb      r0, 0xb0(r3)
lwz      r3, 0xa8(r31)
bl       getMotherPane__Q32og6Screen18CallBack_CounterRVFv
lis      r4, msVal__Q32kh6Screen13ObjCaveResult@ha
lwz      r12, 0(r3)
addi     r4, r4, msVal__Q32kh6Screen13ObjCaveResult@l
lfs      f1, 0x10(r4)
lfs      f0, 0x14(r4)
lwz      r12, 0x14(r12)
fneg     f1, f1
fneg     f2, f0
mtctr    r12
bctrl
lwz      r3, 0x40(r31)
lis      r5, 0x5F303038@ha
lis      r4, 0x50494354@ha
lwz      r12, 0(r3)
addi     r6, r5, 0x5F303038@l
addi     r5, r4, 0x50494354@l
lwz      r12, 0x3c(r12)
mtctr    r12
bctrl
li       r0, 1
lis      r5, 0x74733134@ha
stb      r0, 0xb0(r3)
lis      r4, 0x00507469@ha
addi     r6, r5, 0x74733134@l
lwz      r3, 0x40(r31)
addi     r5, r4, 0x00507469@l
lwz      r12, 0(r3)
lwz      r12, 0x3c(r12)
mtctr    r12
bctrl
li       r0, 1
lis      r5, 0x74733135@ha
stb      r0, 0xb0(r3)
lis      r4, 0x00507469@ha
addi     r6, r5, 0x74733135@l
lwz      r3, 0x40(r31)
addi     r5, r4, 0x00507469@l
lwz      r12, 0(r3)
lwz      r12, 0x3c(r12)
mtctr    r12
bctrl
li       r4, 1
li       r0, 0
stb      r4, 0xb0(r3)
li       r4, 0x1840
li       r5, 0
stw      r0, 0xf0(r31)
lwz      r3, spSysIF__8PSSystem@sda21(r13)
bl       playSystemSe__Q28PSSystem5SysIFFUlUl

lbl_803FAA7C:
lis      r3, msVal__Q32kh6Screen13ObjCaveResult@ha
lbz      r4, 0x105(r31)
addi     r3, r3, msVal__Q32kh6Screen13ObjCaveResult@l
lbz      r0, 0x39(r3)
cmplw    r4, r0
bge      lbl_803FAAD4
lbz      r0, 0x3a(r3)
add      r0, r4, r0
stb      r0, 0x105(r31)
b        lbl_803FAAD4

lbl_803FAAA4:
addi     r0, r3, -1
stw      r0, 0xf4(r31)
lwz      r0, 0xf4(r31)
cmpwi    r0, 0
bne      lbl_803FAAD4
lbz      r0, 0x104(r31)
li       r4, 0x1833
li       r5, 0
ori      r0, r0, 0x10
stb      r0, 0x104(r31)
lwz      r3, spSysIF__8PSSystem@sda21(r13)
bl       playSystemSe__Q28PSSystem5SysIFFUlUl

lbl_803FAAD4:
lwz      r0, 0x14(r1)
lwz      r31, 0xc(r1)
mtlr     r0
addi     r1, r1, 0x10
blr
	*/
}

/*
 * --INFO--
 * Address:	803FAAE8
 * Size:	000564
 */
void ObjCaveResult::updateAnimation()
{
	FOREACH_NODE(Game::Result::TNode, m_resultNode->m_child, cNode) { cNode->m_itemMgr->update(); }
	/*
stwu     r1, -0xb0(r1)
mflr     r0
stw      r0, 0xb4(r1)
stfd     f31, 0xa0(r1)
psq_st   f31, 168(r1), 0, qr0
stw      r31, 0x9c(r1)
stw      r30, 0x98(r1)
mr       r31, r3
lis      r4, 0x6D61736B@ha
lwz      r3, 0x40(r3)
addi     r6, r4, 0x6D61736B@l
li       r5, 0x4e
lwz      r12, 0(r3)
lwz      r12, 0x3c(r12)
mtctr    r12
bctrl
mr       r4, r3
addi     r3, r1, 0x34
li       r5, 0
bl       getGlbVtx__7J2DPaneCFUc
lwz      r3, 0x40(r31)
lis      r4, 0x6D61736B@ha
lwz      r7, 0x34(r1)
addi     r6, r4, 0x6D61736B@l
lwz      r12, 0(r3)
li       r5, 0x4e
lwz      r4, 0x38(r1)
lwz      r0, 0x3c(r1)
lwz      r12, 0x3c(r12)
stw      r7, 0x64(r1)
stw      r4, 0x68(r1)
stw      r0, 0x6c(r1)
mtctr    r12
bctrl
mr       r4, r3
addi     r3, r1, 0x28
li       r5, 3
bl       getGlbVtx__7J2DPaneCFUc
lfs      f0, lbl_8051FFD0@sda21(r2)
lfs      f31, 0x68(r1)
lwz      r4, 0x28(r1)
lwz      r3, 0x2c(r1)
fadds    f1, f0, f31
lwz      r0, 0x30(r1)
stw      r4, 0x58(r1)
stw      r3, 0x5c(r1)
stw      r0, 0x60(r1)
bl       __cvt_fp2unsigned
lfs      f0, 0x5c(r1)
stw      r3, 0xe8(r31)
fsubs    f1, f0, f31
bl       __cvt_fp2unsigned
stw      r3, 0xec(r31)
lfs      f0, 0x64(r31)
lwz      r3, 0x4c(r31)
stfs     f0, 8(r3)
lfs      f0, 0x6c(r31)
lwz      r3, 0x54(r31)
stfs     f0, 8(r3)
lfs      f0, 0x74(r31)
lwz      r3, 0x5c(r31)
stfs     f0, 8(r3)
lfs      f0, 0x78(r31)
lwz      r3, 0x60(r31)
stfs     f0, 8(r3)
lwz      r3, 0x40(r31)
bl       animation__9J2DScreenFv
lbz      r0, 0x104(r31)
rlwinm.  r0, r0, 0, 0x1d, 0x1d
bne      lbl_803FAD30
lfs      f1, 0x64(r31)
lis      r0, 0x4330
lfs      f0, lbl_8051FFB8@sda21(r2)
stw      r0, 0x88(r1)
fadds    f0, f1, f0
lfd      f1, lbl_8051FFB0@sda21(r2)
stfs     f0, 0x64(r31)
lwz      r3, 0x4c(r31)
lfs      f2, 0x64(r31)
lha      r0, 6(r3)
xoris    r0, r0, 0x8000
stw      r0, 0x8c(r1)
lfd      f0, 0x88(r1)
fsubs    f0, f0, f1
fcmpo    cr0, f2, f0
cror     2, 1, 2
bne      lbl_803FAC4C
lfs      f0, lbl_8051FFA8@sda21(r2)
stfs     f0, 0x64(r31)

lbl_803FAC4C:
lfs      f1, 0x6c(r31)
lis      r0, 0x4330
lfs      f0, lbl_8051FFB8@sda21(r2)
stw      r0, 0x88(r1)
fadds    f0, f1, f0
lfd      f1, lbl_8051FFB0@sda21(r2)
stfs     f0, 0x6c(r31)
lwz      r3, 0x54(r31)
lfs      f2, 0x6c(r31)
lha      r0, 6(r3)
xoris    r0, r0, 0x8000
stw      r0, 0x8c(r1)
lfd      f0, 0x88(r1)
fsubs    f0, f0, f1
fcmpo    cr0, f2, f0
cror     2, 1, 2
bne      lbl_803FAC98
lfs      f0, lbl_8051FFA8@sda21(r2)
stfs     f0, 0x6c(r31)

lbl_803FAC98:
lfs      f1, 0x74(r31)
lis      r0, 0x4330
lfs      f0, lbl_8051FFB8@sda21(r2)
stw      r0, 0x88(r1)
fadds    f0, f1, f0
lfd      f1, lbl_8051FFB0@sda21(r2)
stfs     f0, 0x74(r31)
lwz      r3, 0x5c(r31)
lfs      f2, 0x74(r31)
lha      r0, 6(r3)
xoris    r0, r0, 0x8000
stw      r0, 0x8c(r1)
lfd      f0, 0x88(r1)
fsubs    f0, f0, f1
fcmpo    cr0, f2, f0
cror     2, 1, 2
bne      lbl_803FACE4
lfs      f0, lbl_8051FFA8@sda21(r2)
stfs     f0, 0x74(r31)

lbl_803FACE4:
lfs      f1, 0x78(r31)
lis      r0, 0x4330
lfs      f0, lbl_8051FFB8@sda21(r2)
stw      r0, 0x88(r1)
fadds    f0, f1, f0
lfd      f1, lbl_8051FFB0@sda21(r2)
stfs     f0, 0x78(r31)
lwz      r3, 0x60(r31)
lfs      f2, 0x78(r31)
lha      r0, 6(r3)
xoris    r0, r0, 0x8000
stw      r0, 0x8c(r1)
lfd      f0, 0x88(r1)
fsubs    f0, f0, f1
fcmpo    cr0, f2, f0
cror     2, 1, 2
bne      lbl_803FAD30
lfs      f0, lbl_8051FFA8@sda21(r2)
stfs     f0, 0x78(r31)

lbl_803FAD30:
lwz      r3, 0x40(r31)
lwz      r12, 0(r3)
lwz      r12, 0x30(r12)
mtctr    r12
bctrl
lwz      r3, 0x84(r31)
bl       calc__Q32og6Screen8ScaleMgrFv
lwz      r3, 0x40(r31)
lis      r5, 0x636F6D70@ha
lis      r4, 0x50616E61@ha
fmr      f31, f1
lwz      r12, 0(r3)
addi     r6, r5, 0x636F6D70@l
addi     r5, r4, 0x50616E61@l
lwz      r12, 0x3c(r12)
mtctr    r12
bctrl
stfs     f31, 0xcc(r3)
stfs     f31, 0xd0(r3)
lwz      r12, 0(r3)
lwz      r12, 0x2c(r12)
mtctr    r12
bctrl
lbz      r0, 0x104(r31)
rlwinm.  r0, r0, 0, 0x1b, 0x1b
beq      lbl_803FB00C
lfs      f0, 0x68(r31)
lwz      r3, 0x50(r31)
stfs     f0, 8(r3)
lfs      f0, 0x70(r31)
lwz      r3, 0x58(r31)
stfs     f0, 8(r3)
lwz      r3, 0x48(r31)
bl       animation__9J2DScreenFv
lfs      f1, 0x68(r31)
lfs      f0, lbl_8051FFD4@sda21(r2)
fcmpo    cr0, f1, f0
cror     2, 1, 2
bne      lbl_803FAF70
lbz      r0, 0x104(r31)
rlwinm.  r0, r0, 0, 0x1a, 0x1a
bne      lbl_803FAF70
bl       getRenderModeObj__6SystemFv
lhz      r30, 6(r3)
bl       getRenderModeObj__6SystemFv
lhz      r4, 4(r3)
lis      r5, 0x4330
lis      r3, __vt__Q25efx2d3Arg@ha
stw      r5, 0x88(r1)
addi     r0, r3, __vt__Q25efx2d3Arg@l
lfd      f2, lbl_8051FFC0@sda21(r2)
stw      r4, 0x8c(r1)
addi     r4, r1, 0x4c
lfs      f3, lbl_8051FFD0@sda21(r2)
lfd      f0, 0x88(r1)
stw      r30, 0x94(r1)
fsubs    f1, f0, f2
stw      r5, 0x90(r1)
lfd      f0, 0x90(r1)
fmuls    f1, f3, f1
stw      r0, 0x54(r1)
fsubs    f0, f0, f2
stfs     f1, 0x18(r1)
fmuls    f0, f3, f0
lwz      r0, 0x18(r1)
stw      r0, 0x20(r1)
stfs     f0, 0x1c(r1)
lfs      f0, 0x20(r1)
lwz      r0, 0x1c(r1)
stfs     f0, 0x4c(r1)
stw      r0, 0x24(r1)
lfs      f0, 0x24(r1)
stfs     f0, 0x50(r1)
lwz      r3, 0x7c(r31)
lwz      r12, 0(r3)
lwz      r12, 8(r12)
mtctr    r12
bctrl
lwz      r3, 0x48(r31)
lis      r4, 0x4E414C4C@ha
addi     r6, r4, 0x4E414C4C@l
li       r5, 0
lwz      r12, 0(r3)
lwz      r12, 0x3c(r12)
mtctr    r12
bctrl
bl       getPaneCenterY__Q22kh6ScreenFP7J2DPane
lwz      r3, 0x48(r31)
lis      r4, msVal__Q32kh6Screen13ObjCaveResult@ha
addi     r5, r4, msVal__Q32kh6Screen13ObjCaveResult@l
lis      r4, 0x4E414C4C@ha
lwz      r12, 0(r3)
addi     r6, r4, 0x4E414C4C@l
lfs      f0, 8(r5)
li       r5, 0
lwz      r12, 0x3c(r12)
fadds    f31, f0, f1
mtctr    r12
bctrl
bl       getPaneCenterX__Q22kh6ScreenFP7J2DPane
lis      r3, msVal__Q32kh6Screen13ObjCaveResult@ha
li       r8, 0
addi     r3, r3, msVal__Q32kh6Screen13ObjCaveResult@l
stfs     f31, 0xc(r1)
lfs      f0, 4(r3)
lis      r3, __vt__Q25efx2d7TBaseIF@ha
addi     r0, r3, __vt__Q25efx2d7TBaseIF@l
lwz      r3, 0xc(r1)
fadds    f0, f0, f1
lis      r5, __vt__Q25efx2d5TBase@ha
stw      r3, 0x14(r1)
lis      r4, __vt__Q25efx2d8TSimple2@ha
lis      r6, __vt__Q25efx2d3Arg@ha
lis      r3, __vt__Q25efx2d11T2DCavecomp@ha
stfs     f0, 8(r1)
addi     r10, r6, __vt__Q25efx2d3Arg@l
lfs      f0, 0x14(r1)
li       r6, 0xa
lwz      r11, 8(r1)
addi     r9, r5, __vt__Q25efx2d5TBase@l
stw      r0, 0x70(r1)
li       r5, 0xb
addi     r7, r4, __vt__Q25efx2d8TSimple2@l
addi     r0, r3, __vt__Q25efx2d11T2DCavecomp@l
stw      r11, 0x10(r1)
addi     r3, r1, 0x70
addi     r4, r1, 0x40
stw      r9, 0x70(r1)
lfs      f1, 0x10(r1)
stw      r7, 0x70(r1)
stw      r10, 0x48(r1)
stfs     f1, 0x40(r1)
stfs     f0, 0x44(r1)
stb      r8, 0x74(r1)
stb      r8, 0x75(r1)
sth      r6, 0x78(r1)
sth      r5, 0x7a(r1)
stw      r8, 0x7c(r1)
stw      r8, 0x80(r1)
stw      r0, 0x70(r1)
bl       create__Q25efx2d8TSimple2FPQ25efx2d3Arg
lbz      r0, 0x104(r31)
ori      r0, r0, 0x20
stb      r0, 0x104(r31)

lbl_803FAF70:
lis      r3, msVal__Q32kh6Screen13ObjCaveResult@ha
lfs      f1, 0x68(r31)
lfsu     f0, msVal__Q32kh6Screen13ObjCaveResult@l(r3)
lis      r0, 0x4330
stw      r0, 0x90(r1)
fadds    f0, f1, f0
lfd      f3, lbl_8051FFB0@sda21(r2)
lfs      f2, lbl_8051FFB8@sda21(r2)
stfs     f0, 0x68(r31)
lfs      f1, 0x70(r31)
lfs      f0, 0(r3)
fadds    f0, f1, f0
stfs     f0, 0x70(r31)
lwz      r3, 0x50(r31)
lfs      f1, 0x68(r31)
lha      r3, 6(r3)
xoris    r3, r3, 0x8000
stw      r3, 0x94(r1)
lfd      f0, 0x90(r1)
fsubs    f0, f0, f3
fsubs    f0, f0, f2
fcmpo    cr0, f1, f0
cror     2, 1, 2
beq      lbl_803FB000
lwz      r3, 0x58(r31)
stw      r0, 0x90(r1)
lha      r0, 6(r3)
lfs      f1, 0x70(r31)
xoris    r0, r0, 0x8000
stw      r0, 0x94(r1)
lfd      f0, 0x90(r1)
fsubs    f0, f0, f3
fsubs    f0, f0, f2
fcmpo    cr0, f1, f0
cror     2, 1, 2
bne      lbl_803FB00C

lbl_803FB000:
lbz      r0, 0x104(r31)
rlwinm   r0, r0, 0, 0x1c, 0x1a
stb      r0, 0x104(r31)

lbl_803FB00C:
lwz      r3, 0x3c(r31)
lwz      r30, 0x24(r3)
b        lbl_803FB024

lbl_803FB018:
lwz      r3, 0x48(r30)
bl       update__Q32kh6Screen11LostItemMgrFv
lwz      r30, 0x18(r30)

lbl_803FB024:
cmplwi   r30, 0
bne      lbl_803FB018
psq_l    f31, 168(r1), 0, qr0
lwz      r0, 0xb4(r1)
lfd      f31, 0xa0(r1)
lwz      r31, 0x9c(r1)
lwz      r30, 0x98(r1)
mtlr     r0
addi     r1, r1, 0xb0
blr
	*/
}

/*
 * --INFO--
 * Address:	803FB04C
 * Size:	000078
 */
void ObjCaveResult::setAlpha(int index, unsigned char alpha)
{
	u64 tag  = 'Nicon00';
	u64 tag2 = 'Nicon01';
	m_screenMain->search('Nicon00' + index)->setAlpha(alpha);
	/*
stwu     r1, -0x20(r1)
mflr     r0
lis      r6, lbl_80498470@ha
slwi     r4, r4, 3
stw      r0, 0x24(r1)
addi     r0, r1, 8
stw      r31, 0x1c(r1)
mr       r31, r5
lfdu     f1, lbl_80498470@l(r6)
lfd      f0, 8(r6)
add      r6, r0, r4
stfd     f1, 8(r1)
stfd     f0, 0x10(r1)
lwz      r3, 0x40(r3)
lwz      r5, 0(r6)
lwz      r12, 0(r3)
lwz      r6, 4(r6)
lwz      r12, 0x3c(r12)
mtctr    r12
bctrl
lwz      r12, 0(r3)
mr       r4, r31
lwz      r12, 0x24(r12)
mtctr    r12
bctrl
lwz      r0, 0x24(r1)
lwz      r31, 0x1c(r1)
mtlr     r0
addi     r1, r1, 0x20
blr
	*/
}

/*
 * --INFO--
 * Address:	803FB0C4
 * Size:	0000C4
 */
void ObjCaveResult::pikminSE()
{
	uint dead = m_deadPiki;
	if (dead == 0) {
		PSSystem::spSysIF->playSystemSe(PSSE_SY_MENU_PLUS_MINUS, 0);
		PSSystem::spSysIF->playSystemSe(PSSE_PK_RESULT_INCREMENT, 0);
	} else if (dead <= 10) {
		PSSystem::spSysIF->playSystemSe(PSSE_SY_PIKI_DECREMENT, 0);
		PSSystem::spSysIF->playSystemSe(PSSE_PK_VC_SAVED, 0);
	} else if (dead <= 50) {
		PSSystem::spSysIF->playSystemSe(PSSE_SY_PIKI_DECRE_SUM, 0);
		PSSystem::spSysIF->playSystemSe(PSSE_PK_RESULT_DECREMENT, 0);
	} else {
		PSSystem::spSysIF->playSystemSe(PSSE_SY_PIKI_DECRE_SUM, 0);
		PSSystem::spSysIF->playSystemSe(PSSE_PK_VC_GHOST, 0);
	}
	/*
stwu     r1, -0x10(r1)
mflr     r0
stw      r0, 0x14(r1)
lwz      r0, 0xb8(r3)
cmplwi   r0, 0
bne      lbl_803FB100
lwz      r3, spSysIF__8PSSystem@sda21(r13)
li       r4, 0x1806
li       r5, 0
bl       playSystemSe__Q28PSSystem5SysIFFUlUl
lwz      r3, spSysIF__8PSSystem@sda21(r13)
li       r4, 0x285f
li       r5, 0
bl       playSystemSe__Q28PSSystem5SysIFFUlUl
b        lbl_803FB178

lbl_803FB100:
cmplwi   r0, 0xa
bgt      lbl_803FB12C
lwz      r3, spSysIF__8PSSystem@sda21(r13)
li       r4, 0x182a
li       r5, 0
bl       playSystemSe__Q28PSSystem5SysIFFUlUl
lwz      r3, spSysIF__8PSSystem@sda21(r13)
li       r4, 0x2822
li       r5, 0
bl       playSystemSe__Q28PSSystem5SysIFFUlUl
b        lbl_803FB178

lbl_803FB12C:
cmplwi   r0, 0x32
bgt      lbl_803FB158
lwz      r3, spSysIF__8PSSystem@sda21(r13)
li       r4, 0x182b
li       r5, 0
bl       playSystemSe__Q28PSSystem5SysIFFUlUl
lwz      r3, spSysIF__8PSSystem@sda21(r13)
li       r4, 0x2860
li       r5, 0
bl       playSystemSe__Q28PSSystem5SysIFFUlUl
b        lbl_803FB178

lbl_803FB158:
lwz      r3, spSysIF__8PSSystem@sda21(r13)
li       r4, 0x182b
li       r5, 0
bl       playSystemSe__Q28PSSystem5SysIFFUlUl
lwz      r3, spSysIF__8PSSystem@sda21(r13)
li       r4, 0x2810
li       r5, 0
bl       playSystemSe__Q28PSSystem5SysIFFUlUl

lbl_803FB178:
lwz      r0, 0x14(r1)
mtlr     r0
addi     r1, r1, 0x10
blr
	*/
}

/*
 * --INFO--
 * Address:	803FB188
 * Size:	000038
 */
LostItem::LostItem()
{
	m_rect.p1.y = 0.0f;
	m_rect.p1.x = 0.0f;
	m_rect.p2.y = 0.0f;
	m_rect.p2.x = 0.0f;
	m_alpha     = 255;
	_14         = -40;
	_1A         = 0;
	m_angle     = 0;
	m_counter   = false;
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000B8
 */
bool LostItem::update()
{
	bool flag;
	if (m_alpha == 0) {
		flag = true;

	} else {
		if (m_counter == 0) {
			m_alpha += _14;
			if (m_alpha < (int)-_14) {
				m_alpha = 0;
			}
		} else {
			m_counter--;
		}

		flag = false;
		m_rect.p2.y += _10;
		m_rect.p2.x *= 0.85f;
		m_rect.p2.y *= 0.85f;
		m_rect.p1.x += m_rect.p2.x;
		m_rect.p1.y += m_rect.p2.y;
		m_angle += _1A;
	}

	return flag;
}

/*
 * --INFO--
 * Address:	803FB1C0
 * Size:	000080
 */
LostItemMgr::LostItemMgr(int count)
{
	m_maxPanes = count;
	if (count) {
		m_itemList = new LostItem[count];
	} else {
		m_itemList = nullptr;
	}

	m_flags = 0;
}

/*
 * --INFO--
 * Address:	803FB240
 * Size:	0003EC
 */
void LostItemMgr::init(const JGeometry::TVec2f& pos, bool flag)
{
	if (m_maxPanes) {
		f32 x = pos.x;
		f32 y = pos.y;
		if (flag) {
			x += 60.0f;
		}

		for (int i = 0; i < m_maxPanes; i++) {
			f32 x1 = randFloat();
			f32 x2 = randFloat();
			f32 y1 = randFloat();
			f32 y2 = randFloat();

			LostItem item    = m_itemList[i];
			item.m_rect.p1.x = x;
			item.m_rect.p1.y = y;
			item.m_rect.p2.x = 40.0f * randFloat() - 20.0f;
			item.m_rect.p2.y = 32.0f * y2 - 30.0f;
			item._10         = (u16)(4.0f * y1 + 2.0f);
			item._1A         = (u16)(10000.0f * x2 - 5000.0f);
			item.m_counter   = (u8)(10.0f * x1 - 8.0f);
		}
		float xoffs[5] = { kh::Screen::ObjCaveResult::msVal._24, kh::Screen::ObjCaveResult::msVal._28, kh::Screen::ObjCaveResult::msVal._2C,
			               kh::Screen::ObjCaveResult::msVal._30, kh::Screen::ObjCaveResult::msVal._34 };

		if (flag) {
			xoffs[0] += 60.0f;
		}
		f32 efxY = pos.y - 10.0f;
		f32 efxX = pos.x;
		for (int i = 0; i < 5; i++) {
			efx2d::T2DChangesmoke efx;
			efx2d::Arg arg(efxX + xoffs[i], efxY);
			efx.create(&arg);
		}
		PSSystem::spSysIF->playSystemSe(PSSE_SY_PIKI_DECREMENT, 0);
		setFlag(0x1 + 0x2);
	}
	/*
stwu     r1, -0x1c0(r1)
mflr     r0
stw      r0, 0x1c4(r1)
stfd     f31, 0x1b0(r1)
psq_st   f31, 440(r1), 0, qr0
stfd     f30, 0x1a0(r1)
psq_st   f30, 424(r1), 0, qr0
stfd     f29, 0x190(r1)
psq_st   f29, 408(r1), 0, qr0
stfd     f28, 0x180(r1)
psq_st   f28, 392(r1), 0, qr0
stfd     f27, 0x170(r1)
psq_st   f27, 376(r1), 0, qr0
stfd     f26, 0x160(r1)
psq_st   f26, 360(r1), 0, qr0
stfd     f25, 0x150(r1)
psq_st   f25, 344(r1), 0, qr0
stfd     f24, 0x140(r1)
psq_st   f24, 328(r1), 0, qr0
stfd     f23, 0x130(r1)
psq_st   f23, 312(r1), 0, qr0
stfd     f22, 0x120(r1)
psq_st   f22, 296(r1), 0, qr0
stfd     f21, 0x110(r1)
psq_st   f21, 280(r1), 0, qr0
stfd     f20, 0x100(r1)
psq_st   f20, 264(r1), 0, qr0
stfd     f19, 0xf0(r1)
psq_st   f19, 248(r1), 0, qr0
stfd     f18, 0xe0(r1)
psq_st   f18, 232(r1), 0, qr0
stfd     f17, 0xd0(r1)
psq_st   f17, 216(r1), 0, qr0
stfd     f16, 0xc0(r1)
psq_st   f16, 200(r1), 0, qr0
stfd     f15, 0xb0(r1)
psq_st   f15, 184(r1), 0, qr0
stfd     f14, 0xa0(r1)
psq_st   f14, 168(r1), 0, qr0
stmw     r24, 0x80(r1)
mr       r29, r3
mr       r30, r4
lwz      r0, 4(r3)
mr       r31, r5
cmpwi    r0, 0
beq      lbl_803FB588
clrlwi.  r0, r31, 0x18
lfs      f15, 0(r30)
lfs      f14, 4(r30)
beq      lbl_803FB310
lfs      f0, lbl_8051FFDC@sda21(r2)
fadds    f15, f15, f0

lbl_803FB310:
lfd      f20, lbl_8051FFB0@sda21(r2)
li       r25, 0
lfs      f21, lbl_8051FFE0@sda21(r2)
li       r27, 0
lfs      f22, lbl_8051FFE4@sda21(r2)
lis      r26, 0x4330
lfs      f23, lbl_8051FFE8@sda21(r2)
lfs      f24, lbl_8051FFEC@sda21(r2)
lfs      f25, lbl_8051FFD4@sda21(r2)
lfs      f26, lbl_8051FFF0@sda21(r2)
lfs      f27, lbl_8051FFBC@sda21(r2)
lfs      f28, lbl_8051FFF4@sda21(r2)
lfs      f29, lbl_8051FFF8@sda21(r2)
lfs      f30, lbl_80520000@sda21(r2)
lfs      f31, lbl_8051FFFC@sda21(r2)
b        lbl_803FB434

lbl_803FB350:
bl       rand
xoris    r0, r3, 0x8000
stw      r26, 0x48(r1)
stw      r0, 0x4c(r1)
lfd      f0, 0x48(r1)
fsubs    f0, f0, f20
fdivs    f19, f0, f21
bl       rand
xoris    r0, r3, 0x8000
stw      r26, 0x50(r1)
stw      r0, 0x54(r1)
lfd      f0, 0x50(r1)
fsubs    f0, f0, f20
fdivs    f18, f0, f21
bl       rand
xoris    r0, r3, 0x8000
stw      r26, 0x58(r1)
stw      r0, 0x5c(r1)
lfd      f0, 0x58(r1)
fsubs    f0, f0, f20
fdivs    f17, f0, f21
bl       rand
xoris    r0, r3, 0x8000
stw      r26, 0x60(r1)
stw      r0, 0x64(r1)
lfd      f0, 0x60(r1)
fsubs    f0, f0, f20
fdivs    f16, f0, f21
bl       rand
xoris    r3, r3, 0x8000
fmsubs   f1, f28, f18, f29
stw      r3, 0x6c(r1)
fmadds   f0, f30, f19, f31
lwz      r0, 0(r29)
fmsubs   f3, f24, f16, f25
stw      r26, 0x68(r1)
add      r4, r0, r27
fctiwz   f1, f1
lfd      f4, 0x68(r1)
fctiwz   f0, f0
stfs     f15, 0(r4)
fmadds   f2, f26, f17, f27
fsubs    f4, f4, f20
stfd     f1, 0x70(r1)
addi     r27, r27, 0x20
addi     r25, r25, 1
fdivs    f1, f4, f21
stfd     f0, 0x78(r1)
lwz      r3, 0x74(r1)
stfs     f14, 4(r4)
lwz      r0, 0x7c(r1)
fmsubs   f0, f22, f1, f23
stfs     f0, 8(r4)
stfs     f3, 0xc(r4)
stfs     f2, 0x10(r4)
sth      r3, 0x1a(r4)
stb      r0, 0x1d(r4)

lbl_803FB434:
lwz      r0, 4(r29)
cmpw     r25, r0
blt      lbl_803FB350
lis      r4, lbl_80498480@ha
lis      r3, msVal__Q32kh6Screen13ObjCaveResult@ha
addi     r8, r4, lbl_80498480@l
clrlwi.  r0, r31, 0x18
lwz      r7, 0(r8)
addi     r3, r3, msVal__Q32kh6Screen13ObjCaveResult@l
lwz      r6, 4(r8)
lwz      r5, 8(r8)
lwz      r4, 0xc(r8)
lwz      r0, 0x10(r8)
stw      r7, 0x34(r1)
lfs      f4, 0x24(r3)
stw      r6, 0x38(r1)
lfs      f3, 0x28(r3)
stw      r5, 0x3c(r1)
lfs      f2, 0x2c(r3)
stw      r4, 0x40(r1)
lfs      f1, 0x30(r3)
stw      r0, 0x44(r1)
lfs      f0, 0x34(r3)
stfs     f4, 0x34(r1)
stfs     f3, 0x38(r1)
stfs     f2, 0x3c(r1)
stfs     f1, 0x40(r1)
stfs     f0, 0x44(r1)
beq      lbl_803FB4B4
lfs      f0, lbl_8051FFDC@sda21(r2)
fadds    f0, f4, f0
stfs     f0, 0x34(r1)

lbl_803FB4B4:
lfs      f1, 4(r30)
lis      r7, __vt__Q25efx2d7TBaseIF@ha
lfs      f0, lbl_80520000@sda21(r2)
lis      r6, __vt__Q25efx2d5TBase@ha
lis      r5, __vt__Q25efx2d8TSimple1@ha
lis      r4, __vt__Q25efx2d14T2DChangesmoke@ha
lis      r3, __vt__Q25efx2d3Arg@ha
fsubs    f14, f1, f0
lfs      f15, 0(r30)
addi     r25, r1, 0x34
addi     r26, r7, __vt__Q25efx2d7TBaseIF@l
addi     r27, r6, __vt__Q25efx2d5TBase@l
addi     r28, r5, __vt__Q25efx2d8TSimple1@l
addi     r31, r4, __vt__Q25efx2d14T2DChangesmoke@l
addi     r30, r3, __vt__Q25efx2d3Arg@l
li       r24, 0

lbl_803FB4F4:
lfs      f0, 0(r25)
li       r7, 0
stfs     f14, 0x14(r1)
li       r6, 7
fadds    f0, f15, f0
addi     r3, r1, 0x24
stw      r26, 0x24(r1)
addi     r4, r1, 0x18
lwz      r0, 0x14(r1)
stfs     f0, 0x10(r1)
lwz      r5, 0x10(r1)
stw      r27, 0x24(r1)
stw      r5, 8(r1)
stw      r0, 0xc(r1)
lfs      f1, 8(r1)
stw      r28, 0x24(r1)
lfs      f0, 0xc(r1)
stb      r7, 0x28(r1)
stb      r7, 0x29(r1)
sth      r6, 0x2c(r1)
stw      r7, 0x30(r1)
stw      r31, 0x24(r1)
stw      r30, 0x20(r1)
stfs     f1, 0x18(r1)
stfs     f0, 0x1c(r1)
bl       create__Q25efx2d8TSimple1FPQ25efx2d3Arg
addi     r24, r24, 1
addi     r25, r25, 4
cmpwi    r24, 5
blt      lbl_803FB4F4
lwz      r3, spSysIF__8PSSystem@sda21(r13)
li       r4, 0x182a
li       r5, 0
bl       playSystemSe__Q28PSSystem5SysIFFUlUl
lwz      r0, 8(r29)
ori      r0, r0, 3
stw      r0, 8(r29)

lbl_803FB588:
psq_l    f31, 440(r1), 0, qr0
lfd      f31, 0x1b0(r1)
psq_l    f30, 424(r1), 0, qr0
lfd      f30, 0x1a0(r1)
psq_l    f29, 408(r1), 0, qr0
lfd      f29, 0x190(r1)
psq_l    f28, 392(r1), 0, qr0
lfd      f28, 0x180(r1)
psq_l    f27, 376(r1), 0, qr0
lfd      f27, 0x170(r1)
psq_l    f26, 360(r1), 0, qr0
lfd      f26, 0x160(r1)
psq_l    f25, 344(r1), 0, qr0
lfd      f25, 0x150(r1)
psq_l    f24, 328(r1), 0, qr0
lfd      f24, 0x140(r1)
psq_l    f23, 312(r1), 0, qr0
lfd      f23, 0x130(r1)
psq_l    f22, 296(r1), 0, qr0
lfd      f22, 0x120(r1)
psq_l    f21, 280(r1), 0, qr0
lfd      f21, 0x110(r1)
psq_l    f20, 264(r1), 0, qr0
lfd      f20, 0x100(r1)
psq_l    f19, 248(r1), 0, qr0
lfd      f19, 0xf0(r1)
psq_l    f18, 232(r1), 0, qr0
lfd      f18, 0xe0(r1)
psq_l    f17, 216(r1), 0, qr0
lfd      f17, 0xd0(r1)
psq_l    f16, 200(r1), 0, qr0
lfd      f16, 0xc0(r1)
psq_l    f15, 184(r1), 0, qr0
lfd      f15, 0xb0(r1)
psq_l    f14, 168(r1), 0, qr0
lfd      f14, 0xa0(r1)
lmw      r24, 0x80(r1)
lwz      r0, 0x1c4(r1)
mtlr     r0
addi     r1, r1, 0x1c0
blr
	*/
}

/*
 * --INFO--
 * Address:	803FB62C
 * Size:	000108
 */
void LostItemMgr::update()
{
	if (!isFlag(0x1)) {
		return;
	}

	bool doend = true;
	for (int i = 0; i < (int)m_maxPanes; i++) {
		doend &= m_itemList[i].update();
	}

	if (doend) {
		resetFlag(0x1);
	}
}

/*
 * --INFO--
 * Address:	803FB734
 * Size:	000170
 */
void LostItemMgr::draw(P2DScreen::Mgr_tuning* screen, u64 tag, const ResTIMG* timg, Graphics& gfx)
{
	if (isFlag(0x1)) {
		kh::Screen::setTex(screen, tag, timg);
		J2DPane* pane = screen->search(tag);
		for (int i = 0; i < (int)m_maxPanes; i++) {
			pane->_0D4 = JGeometry::TVec2f(m_itemList[i].m_rect.p1.x, m_itemList[i].m_rect.p1.y);
			pane->calcMtx();

			pane->setAlpha(m_itemList[i].m_alpha);
			pane->m_angle = 360.0f * (f32)m_itemList[i].m_angle / 65536.0f;
			pane->calcMtx();

			screen->draw(gfx, gfx.m_orthoGraph);
		}
	}
}

/*
 * --INFO--
 * Address:	803FB8A4
 * Size:	0000A4
 */
void SceneCaveResult::doUserCallBackFunc(Resource::MgrCommand* command)
{
	og::newScreen::makeLanguageResName(m_name, "result_doukutu.szs");
	LoadResource::Arg loadArg(m_name);
	LoadResource::Node* resource = gLoadResourceMgr->mountArchive(loadArg);
	if (resource) {
		JKRArchive* archive = resource->m_archive;
		registObj(new ObjCaveResult, archive);
	} else {
		JUT_PANICLINE(1299, "failed");
	}
}

ObjCaveResult::StaticValues ObjCaveResult::msVal;

} // namespace Screen
} // namespace kh
