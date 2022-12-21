#include "types.h"
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
#include "Dolphin/gx.h"

bool contenaAngleFlag;
f32 contenaAngle;

/*
    Generated from dpostproc

    .section .ctors, "wa"  # 0x80472F00 - 0x804732C0
    .4byte __sinit_ogObjContena_cpp

    .section .rodata  # 0x804732E0 - 0x8049E220
    .global lbl_8048EFE0
    lbl_8048EFE0:
        .4byte 0x6F674F62
        .4byte 0x6A436F6E
        .4byte 0x74656E61
        .4byte 0x2E637070
        .4byte 0x00000000
        .4byte 0x55464F4D
        .4byte 0x454E5520
        .4byte 0x2D2D3E20
        .4byte 0x434F4E54
        .4byte 0x454E4120
        .4byte 0x45525221
        .4byte 0x0A000000
        .4byte 0x45525221
        .4byte 0x20696E20
        .4byte 0x4F626A43
        .4byte 0x6F6E7465
        .4byte 0x6E612043
        .4byte 0x72656174
        .4byte 0x658EB894
        .4byte 0x7381490A
        .4byte 0x00000000
        .4byte 0x636F6E74
        .4byte 0x656E615F
        .4byte 0x622E626C
        .4byte 0x6F000000
        .4byte 0x636F6E74
        .4byte 0x656E615F
        .4byte 0x722E626C
        .4byte 0x6F000000
        .4byte 0x636F6E74
        .4byte 0x656E615F
        .4byte 0x792E626C
        .4byte 0x6F000000
        .4byte 0x636F6E74
        .4byte 0x656E615F
        .4byte 0x626C2E62
        .4byte 0x6C6F0000
        .4byte 0x636F6E74
        .4byte 0x656E615F
        .4byte 0x772E626C
        .4byte 0x6F000000
        .4byte 0x45525221
        .4byte 0x20756E6B
        .4byte 0x6E776F6E
        .4byte 0x20636F6E
        .4byte 0x74656E61
        .4byte 0x20747970
        .4byte 0x65210A00
        .4byte 0x63757073
        .4byte 0x756C652E
        .4byte 0x626C6F00
        .4byte 0x73706F74
        .4byte 0x2E626C6F
        .4byte 0x00000000
        .4byte 0x44617461
        .4byte 0x436F6E74
        .4byte 0x656E6120
        .4byte 0x6973206E
        .4byte 0x6F742066
        .4byte 0x6F756E64
        .4byte 0x210A0000
        .4byte 0x436F6E74
        .4byte 0x656E6120
        .4byte 0x54797065
        .4byte 0x20657272
        .4byte 0x6F72210A
        .4byte 0x00000000
        .4byte 0x82BE82DF
        .4byte 0x82C582B7
        .4byte 0x0A000000
        .4byte 0x53544152
        .4byte 0x54204552
        .4byte 0x52212028
        .4byte 0x4261636B
        .4byte 0x75705363
        .4byte 0x656E6529
        .4byte 0x00000000
        .4byte 0x73657442
        .4byte 0x61636B75
        .4byte 0x70536365
        .4byte 0x6E652045
        .4byte 0x52522100
        .4byte 0x73637265
        .4byte 0x656E4F62
        .4byte 0x6A2E6800
        .asciz "P2Assert"
        .skip 3

    .section .data, "wa"  # 0x8049E220 - 0x804EFC20
    .global __vt__Q32og9newScreen10ObjContena
    __vt__Q32og9newScreen10ObjContena:
        .4byte 0
        .4byte 0
        .4byte __dt__Q32og9newScreen10ObjContenaFv
        .4byte getChildCount__5CNodeFv
        .4byte 0
        .4byte 0
        .4byte "@24@__dt__Q32og9newScreen10ObjContenaFv"
        .4byte update__Q26Screen7ObjBaseFv
        .4byte draw__Q26Screen7ObjBaseFR8Graphics
        .4byte start__Q26Screen7ObjBaseFPCQ26Screen13StartSceneArg
        .4byte end__Q26Screen7ObjBaseFPCQ26Screen11EndSceneArg
        .4byte setOwner__Q26Screen7ObjBaseFPQ26Screen9SceneBase
        .4byte getOwner__Q26Screen7ObjBaseCFv
        .4byte create__Q26Screen7ObjBaseFP10JKRArchive
        .4byte confirmSetScene__Q26Screen7ObjBaseFRQ26Screen11SetSceneArg
        .4byte confirmStartScene__Q26Screen7ObjBaseFPQ26Screen13StartSceneArg
        .4byte confirmEndScene__Q26Screen7ObjBaseFPQ26Screen11EndSceneArg
        .4byte doStart__Q32og9newScreen10ObjContenaFPCQ26Screen13StartSceneArg
        .4byte doEnd__Q32og9newScreen10ObjContenaFPCQ26Screen11EndSceneArg
        .4byte doCreate__Q32og9newScreen10ObjContenaFP10JKRArchive
        .4byte doUpdateFadein__Q32og9newScreen10ObjContenaFv
        .4byte doUpdateFadeinFinish__Q32og9newScreen10ObjContenaFv
        .4byte doUpdate__Q32og9newScreen10ObjContenaFv
        .4byte doUpdateFinish__Q32og9newScreen10ObjContenaFv
        .4byte doUpdateFadeout__Q32og9newScreen10ObjContenaFv
        .4byte doUpdateFadeoutFinish__Q32og9newScreen10ObjContenaFv
        .4byte doDraw__Q32og9newScreen10ObjContenaFR8Graphics
        .4byte doConfirmSetScene__Q26Screen7ObjBaseFRQ26Screen11SetSceneArg
        .4byte doConfirmStartScene__Q26Screen7ObjBaseFPQ26Screen13StartSceneArg
        .4byte doConfirmEndScene__Q26Screen7ObjBaseFRPQ26Screen11EndSceneArg

    .section .bss  # 0x804EFC20 - 0x8051467C
    .global msVal__Q32og9newScreen10ObjContena
    msVal__Q32og9newScreen10ObjContena:
        .skip 0x44

    .section .sbss # 0x80514D80 - 0x80516360
    .global angle$4147
    angle$4147:
        .skip 0x4
    .global init$4148
    init$4148:
        .skip 0x4

    .section .sdata2, "a"     # 0x80516360 - 0x80520E40
    .global lbl_8051DC88
    lbl_8051DC88:
        .4byte 0x44480000
    .global lbl_8051DC8C
    lbl_8051DC8C:
        .4byte 0x00000000
    .global lbl_8051DC90
    lbl_8051DC90:
        .float 0.5
    .global lbl_8051DC94
    lbl_8051DC94:
        .float 1.0
    .global lbl_8051DC98
    lbl_8051DC98:
        .float 0.3
    .global lbl_8051DC9C
    lbl_8051DC9C:
        .float 0.1
    .global lbl_8051DCA0
    lbl_8051DCA0:
        .4byte 0x41F00000
    .global lbl_8051DCA4
    lbl_8051DCA4:
        .4byte 0x3F4CCCCD
    .global lbl_8051DCA8
    lbl_8051DCA8:
        .float 0.05
    .global lbl_8051DCAC
    lbl_8051DCAC:
        .4byte 0x420C0000
    .global lbl_8051DCB0
    lbl_8051DCB0:
        .4byte 0x40C90FDB
    .global lbl_8051DCB4
    lbl_8051DCB4:
        .4byte 0xC3A2F983
    .global lbl_8051DCB8
    lbl_8051DCB8:
        .4byte 0x43A2F983
    .global lbl_8051DCBC
    lbl_8051DCBC:
        .4byte 0x3ECCCCCD
    .global lbl_8051DCC0
    lbl_8051DCC0:
        .4byte 0xBECCCCCD
    .global lbl_8051DCC4
    lbl_8051DCC4:
        .4byte 0x42C80000
    .global lbl_8051DCC8
    lbl_8051DCC8:
        .4byte 0xC2C80000
    .global lbl_8051DCCC
    lbl_8051DCCC:
        .4byte 0x40000000
    .global lbl_8051DCD0
    lbl_8051DCD0:
        .4byte 0x437F0000
    .global lbl_8051DCD4
    lbl_8051DCD4:
        .4byte 0xC4480000
    .global lbl_8051DCD8
    lbl_8051DCD8:
        .4byte 0x41A00000
    .global lbl_8051DCDC
    lbl_8051DCDC:
        .float 0.06
    .global lbl_8051DCE0
    lbl_8051DCE0:
        .4byte 0x3F99999A
    .global lbl_8051DCE4
    lbl_8051DCE4:
        .4byte 0x3F19999A
    .global lbl_8051DCE8
    lbl_8051DCE8:
        .4byte 0x43660000
    .global lbl_8051DCEC
    lbl_8051DCEC:
        .4byte 0x42660000
    .global lbl_8051DCF0
    lbl_8051DCF0:
        .4byte 0x3EDC28F6
    .global lbl_8051DCF4
    lbl_8051DCF4:
        .4byte 0x3E4CCCCD
    .global lbl_8051DCF8
    lbl_8051DCF8:
        .4byte 0x3FE66666
    .global lbl_8051DCFC
    lbl_8051DCFC:
        .4byte 0xBF800000
    .global lbl_8051DD00
    lbl_8051DD00:
        .4byte 0x3F0CCCCD
    .global lbl_8051DD04
    lbl_8051DD04:
        .4byte 0x3D88CE70
*/

namespace og {
namespace newScreen {

/*
 * --INFO--
 * Address:	........
 * Size:	00001C
 */
void ObjContena::setStartPos()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	8031FF44
 * Size:	0001C0
 */
ObjContena::ObjContena(char const* name)
{
	m_inOnionCount   = 100;
	m_currField      = 1000;
	m_inSquadCount   = 0;
	m_maxPikiOnField = 20;
	m_inParty2       = 50;
	m_onMapCount     = 60;
	m_maxPikiCount   = 200;
	m_onyonID        = -1;
	_D8              = 0;
	_DC              = 0;
	_E0              = 0;
	_E4              = 0;
	m_name           = name;
	m_disp           = nullptr;
	m_contena        = nullptr;
	m_controller     = nullptr;

	m_animList[0] = nullptr;
	m_animList[1] = nullptr;
	m_animList[2] = nullptr;
	m_animList[3] = nullptr;
	m_animList[4] = nullptr;
	m_animList[5] = nullptr;
	m_animList[6] = nullptr;
	m_animList[7] = nullptr;
	m_animList[8] = nullptr;
	m_animList[9] = nullptr;

	m_alphaMgr[0] = nullptr;
	m_paneList[0] = nullptr;
	m_alphaMgr[1] = nullptr;
	m_paneList[1] = nullptr;
	m_alphaMgr[2] = nullptr;
	m_paneList[2] = nullptr;
	m_alphaMgr[3] = nullptr;
	m_paneList[3] = nullptr;
	m_alphaMgr[4] = nullptr;
	m_paneList[4] = nullptr;
	m_alphaMgr[5] = nullptr;
	m_paneList[5] = nullptr;

	m_state              = 0;
	m_screenAngle        = 0.0f;
	m_screenState        = 0;
	m_moveTime           = 0.5f;
	m_timer0             = m_moveTime;
	m_dispState          = 1;
	m_furiko             = nullptr;
	m_menuMoveAngle      = 0.0f;
	m_yAnalog            = 0.0f;
	m_spotX              = 0.0f;
	m_spotY              = 0.0f;
	_104                 = 1.0f;
	m_paneSpot           = nullptr;
	m_timer              = 0.0f;
	m_doDraw             = false;
	m_fadeLevel          = 0.0f;
	m_stickAnimMgr       = nullptr;
	m_alphaArrow1        = nullptr;
	m_alphaArrow2        = nullptr;
	m_paneArrowUp        = nullptr;
	m_paneArrowDown      = nullptr;
	m_paneArrowUpPos.x   = 0.0f;
	m_paneArrowUpPos.y   = 0.0f;
	m_paneArrowDownPos.x = 0.0f;
	m_paneArrowDownPos.y = 0.0f;
	m_screenCupsule      = nullptr;
	m_scaleArrow1        = nullptr;
	m_scaleArrow2        = nullptr;
	m_timer1             = 0.0f;
	m_timer2             = 0.0f;
	m_pikiPaneList       = nullptr;
	m_pikiPaneNum        = 0;
	m_paneOnyon          = nullptr;
	m_paneOnyonL         = nullptr;
	m_paneTiretu         = nullptr;
	m_paneTiretul        = nullptr;
	m_payedDebt          = false;
	m_menuMoveAngle      = 800.0f;
	m_yAnalog            = 0.0f;
	m_doDraw             = false;
	/*
	stwu     r1, -0x10(r1)
	mflr     r0
	stw      r0, 0x14(r1)
	stw      r31, 0xc(r1)
	mr       r31, r4
	stw      r30, 8(r1)
	mr       r30, r3
	bl       __ct__Q26Screen7ObjBaseFv
	lis      r3, __vt__Q32og9newScreen10ObjContena@ha
	li       r0, 0x64
	addi     r4, r3, __vt__Q32og9newScreen10ObjContena@l
	li       r9, 0
	stw      r4, 0(r30)
	addi     r4, r4, 0x10
	li       r3, 0x3e8
	li       r8, 0x14
	stw      r4, 0x18(r30)
	li       r7, 0x32
	li       r6, 0x3c
	li       r5, 0xc8
	stw      r0, 0xbc(r30)
	li       r4, -1
	lfs      f3, lbl_8051DC8C@sda21(r2)
	li       r0, 1
	stw      r3, 0xc0(r30)
	mr       r3, r30
	lfs      f2, lbl_8051DC90@sda21(r2)
	stw      r9, 0xc4(r30)
	lfs      f1, lbl_8051DC94@sda21(r2)
	stw      r8, 0xc8(r30)
	lfs      f0, lbl_8051DC88@sda21(r2)
	stw      r7, 0xcc(r30)
	stw      r6, 0xd0(r30)
	stw      r5, 0xd4(r30)
	stw      r4, 0xb8(r30)
	stw      r9, 0xd8(r30)
	stb      r9, 0xdc(r30)
	stw      r9, 0xe0(r30)
	sth      r9, 0xe4(r30)
	stw      r31, 0x14(r30)
	stw      r9, 0x38(r30)
	stw      r9, 0x3c(r30)
	stw      r9, 0x48(r30)
	stw      r9, 0x4c(r30)
	stw      r9, 0x50(r30)
	stw      r9, 0x54(r30)
	stw      r9, 0x58(r30)
	stw      r9, 0x5c(r30)
	stw      r9, 0x60(r30)
	stw      r9, 0x64(r30)
	stw      r9, 0x68(r30)
	stw      r9, 0x6c(r30)
	stw      r9, 0x70(r30)
	stw      r9, 0x74(r30)
	stw      r9, 0x8c(r30)
	stw      r9, 0x78(r30)
	stw      r9, 0x90(r30)
	stw      r9, 0x7c(r30)
	stw      r9, 0x94(r30)
	stw      r9, 0x80(r30)
	stw      r9, 0x98(r30)
	stw      r9, 0x84(r30)
	stw      r9, 0x9c(r30)
	stw      r9, 0x88(r30)
	stw      r9, 0xa0(r30)
	stw      r9, 0xa4(r30)
	stfs     f3, 0xa8(r30)
	stw      r9, 0xac(r30)
	stfs     f2, 0xb0(r30)
	lfs      f2, 0xb0(r30)
	stfs     f2, 0xb4(r30)
	stw      r0, 0xe8(r30)
	stw      r9, 0xec(r30)
	stfs     f3, 0xf0(r30)
	stfs     f3, 0xf4(r30)
	stfs     f3, 0xfc(r30)
	stfs     f3, 0x100(r30)
	stfs     f1, 0x104(r30)
	stw      r9, 0xf8(r30)
	stfs     f3, 0x108(r30)
	stb      r9, 0x10c(r30)
	stfs     f3, 0x110(r30)
	stw      r9, 0x114(r30)
	stw      r9, 0x118(r30)
	stw      r9, 0x11c(r30)
	stw      r9, 0x128(r30)
	stw      r9, 0x12c(r30)
	stfs     f3, 0x130(r30)
	stfs     f3, 0x134(r30)
	stfs     f3, 0x138(r30)
	stfs     f3, 0x13c(r30)
	stw      r9, 0x44(r30)
	stw      r9, 0x120(r30)
	stw      r9, 0x124(r30)
	stfs     f3, 0x140(r30)
	stfs     f3, 0x144(r30)
	stw      r9, 0x14c(r30)
	stw      r9, 0x150(r30)
	stw      r9, 0x154(r30)
	stw      r9, 0x158(r30)
	stw      r9, 0x160(r30)
	stw      r9, 0x164(r30)
	stb      r9, 0x16c(r30)
	stfs     f0, 0xf0(r30)
	stfs     f3, 0xf4(r30)
	stb      r9, 0x10c(r30)
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
 * Address:	80320104
 * Size:	0000AC
 */
ObjContena::~ObjContena(void)
{
	/*
	stwu     r1, -0x10(r1)
	mflr     r0
	stw      r0, 0x14(r1)
	stw      r31, 0xc(r1)
	mr       r31, r4
	stw      r30, 8(r1)
	or.      r30, r3, r3
	beq      lbl_80320194
	lis      r4, __vt__Q32og9newScreen10ObjContena@ha
	addi     r4, r4, __vt__Q32og9newScreen10ObjContena@l
	stw      r4, 0(r30)
	addi     r0, r4, 0x10
	stw      r0, 0x18(r30)
	beq      lbl_80320184
	lis      r4, __vt__Q26Screen7ObjBase@ha
	addi     r4, r4, __vt__Q26Screen7ObjBase@l
	stw      r4, 0(r30)
	addi     r0, r4, 0x10
	stw      r0, 0x18(r30)
	beq      lbl_80320184
	lis      r4, __vt__Q26Screen8IObjBase@ha
	addi     r4, r4, __vt__Q26Screen8IObjBase@l
	stw      r4, 0(r30)
	addi     r0, r4, 0x10
	stw      r0, 0x18(r30)
	bl       del__5CNodeFv
	addi     r3, r30, 0x18
	li       r4, 0
	bl       __dt__11JKRDisposerFv
	mr       r3, r30
	li       r4, 0
	bl       __dt__5CNodeFv

lbl_80320184:
	extsh.   r0, r31
	ble      lbl_80320194
	mr       r3, r30
	bl       __dl__FPv

lbl_80320194:
	lwz      r0, 0x14(r1)
	mr       r3, r30
	lwz      r31, 0xc(r1)
	lwz      r30, 8(r1)
	mtlr     r0
	addi     r1, r1, 0x10
	blr
	*/
}

/*
 * --INFO--
 * Address:	803201B0
 * Size:	000934
 */
void ObjContena::doCreate(JKRArchive* arc)
{
	m_controller = getGamePad();

	og::Screen::DispMemberContena* disp = static_cast<og::Screen::DispMemberContena*>(getDispMember());
	if (disp->isID(OWNER_OGA, MEMBER_CONTENA)) {
		m_disp = disp;
	} else if (disp->isID(OWNER_OGA, MEMBER_UFO_GROUP)) {
		og::Screen::DispMemberUfoGroup* dispufo = static_cast<og::Screen::DispMemberUfoGroup*>(getDispMember());
		switch (dispufo->m_ufoMenu.m_contenaType) {
		case 2:
			m_disp = &dispufo->m_contena1;
			break;
		case 1:
			m_disp = &dispufo->m_contena2;
			break;
		default:
			JUT_PANICLINE(230, "UFOMENU --> CONTENA ERR!\n");
		}
		m_payedDebt = dispufo->m_hasPaidDebt;

	} else if (disp->isID(OWNER_OGA, MEMBER_DUMMY)) {
		m_disp = new og::Screen::DispMemberContena;

	} else {
		JUT_PANICLINE(242, "ERR! in ObjContena Create���s�I\n");
	}
	og::Screen::DispMemberContena* disp2 = m_disp;
	m_onyonID                            = disp2->m_onyonID;
	m_inOnionCount                       = disp2->m_inOnionCount;
	m_currField                          = disp2->m_currField;
	m_inSquadCount                       = disp2->m_inSquadCount;
	m_maxPikiOnField                     = disp2->m_maxPikiOnField;
	m_inParty2                           = disp2->m_inParty2;
	m_onMapCount                         = disp2->m_onMapCount;
	m_maxPikiCount                       = disp2->m_maxPikiCount;
	_D8                                  = disp2->_28;
	_DC                                  = disp2->_2C;
	_E0                                  = disp2->_30;
	_E4                                  = disp2->m_result;
	m_disp->_30                          = 0;
	m_contena                            = new og::Screen::ContenaCounter(m_disp);

	switch (m_disp->m_onyonID) {
	case 0:
		m_contena->setblo("contena_b.blo", arc);
		break;
	case 1:
		m_contena->setblo("contena_r.blo", arc);
		break;
	case 2:
		m_contena->setblo("contena_y.blo", arc);
		break;
	case 3:
		m_contena->setblo("contena_bl.blo", arc);
		break;
	case 4:
		m_contena->setblo("contena_w.blo", arc);
		break;
	default:
		JUT_PANICLINE(266, "ERR! unknwon contena type!\n");
	}

	m_screenCupsule = new P2DScreen::Mgr;
	m_screenCupsule->set("cupsule.blo", 0x1040000, arc);
	og::Screen::setFurikoScreen(m_contena);
	m_screenSpot = new P2DScreen::Mgr_tuning;
	m_screenSpot->set("spot.blo", 0x1040000, arc);
	m_paneSpot = m_screenSpot->search('pspot');
	m_paneSpot->setBasePosition(POS_CENTER);
	m_spotX = m_paneSpot->_0D4.x;
	m_spotY = m_paneSpot->_0D4.y;
	og::Screen::setCallBackMessage(m_contena);
	m_animList[0] = nullptr;
	m_animList[1] = nullptr;
	m_animList[2] = nullptr;
	m_animList[3] = nullptr;
	m_animList[4] = nullptr;
	m_animList[5] = nullptr;
	m_animList[6] = nullptr;
	m_animList[7] = nullptr;
	m_animList[8] = nullptr;
	m_animList[9] = nullptr;

	if (m_contena->search('sh_color')) {
		og::Screen::setCallBackMessage(m_contena);
	}

	m_paneList[0] = m_contena->search('mg_1');
	m_paneList[1] = m_contena->search('mg_2');
	m_paneList[2] = m_contena->search('mg_3');
	m_paneList[3] = m_contena->search('mg_4');
	m_paneList[4] = m_contena->search('mg_5');
	m_paneList[5] = m_contena->search('mg_6');

	for (int i = 0; i < 6; i++) {
		m_paneList[i]->show();
		m_paneList[i]->setInfluencedAlpha(false, false);
		m_alphaMgr[i] = new og::Screen::AlphaMgr;
		m_alphaMgr[i]->out(0.0f);
	}
	m_state = 0;
	m_alphaMgr[m_state]->in(0.0f);
	og::Screen::CallBack_Picture* pic = og::Screen::setCallBack_3DStick(arc, m_contena, 'ota3dl');
	m_stickAnimMgr                    = new og::Screen::StickAnimMgr(pic);
	m_stickAnimMgr->stickUpDown();

	m_paneArrowUp      = og::Screen::TagSearch(m_contena, 'Nya_u');
	m_paneArrowUpPos.x = m_paneArrowUp->_0D4.x;
	m_paneArrowUpPos.y = m_paneArrowUp->_0D4.y;
	m_paneArrowUp->setBasePosition(POS_CENTER);
	m_paneArrowDown      = og::Screen::TagSearch(m_contena, 'Nya_l');
	m_paneArrowDownPos.x = m_paneArrowDown->_0D4.x;
	m_paneArrowDownPos.y = m_paneArrowDown->_0D4.y;
	m_paneArrowDown->setBasePosition(POS_CENTER);
	m_alphaArrow1 = new og::Screen::AlphaMgr;
	m_alphaArrow2 = new og::Screen::AlphaMgr;
	m_alphaArrow1->in(0.3f);
	m_alphaArrow2->in(0.3f);
	m_alpha       = m_paneArrowUp->m_alpha;
	m_scaleArrow1 = new og::Screen::ScaleMgr;
	m_scaleArrow2 = new og::Screen::ScaleMgr;

	m_pikiPaneNum = 0;

	for (int i = 0; i < 100; i++) {
		u64 tag = 'Piki_00' + i;
		if (!m_contena->search(tag))
			break;

		m_pikiPaneNum++;
	}

	m_pikiPaneList = new J2DPane*[m_pikiPaneNum];

	for (int i = 0; i < m_pikiPaneNum; i++) {
		u64 tag           = 'Piki_00' + i;
		J2DPane* pane     = m_contena->search(tag);
		m_pikiPaneList[i] = pane;
		pane->hide();
	}

	m_paneOnyon   = og::Screen::TagSearch(m_contena, 'Nonyon');
	m_paneOnyonL  = og::Screen::TagSearch(m_contena, 'Nonyonl');
	m_paneTiretu  = og::Screen::TagSearch(m_contena, 'Ntiretu');
	m_paneTiretul = og::Screen::TagSearch(m_contena, 'Ntiretul');

	m_scaleMgr3 = new og::Screen::ScaleMgr;
	m_scaleMgr4 = new og::Screen::ScaleMgr;

	int type = m_disp->m_onyonID;
	if (type == 3 || type == 4) {
		J2DPane* pane1 = og::Screen::TagSearch(m_contena, 'P1_1');
		J2DPane* pane2 = og::Screen::TagSearch(m_contena, 'P1_2');
		if (m_payedDebt) {
			pane2->show();
			pane1->hide();
		} else {
			pane1->show();
			pane2->hide();
		}
	}

	/*
	stwu     r1, -0x20(r1)
	mflr     r0
	lis      r5, lbl_8048EFE0@ha
	stw      r0, 0x24(r1)
	stmw     r26, 8(r1)
	mr       r31, r3
	mr       r26, r4
	addi     r28, r5, lbl_8048EFE0@l
	bl       getGamePad__Q26Screen7ObjBaseCFv
	stw      r3, 0x48(r31)
	mr       r3, r31
	bl       getDispMember__Q26Screen7ObjBaseFv
	lis      r4, 0x004F4741@ha
	lis      r6, 0x54454E41@ha
	lis      r5, 0x00434F4E@ha
	mr       r27, r3
	addi     r4, r4, 0x004F4741@l
	addi     r6, r6, 0x54454E41@l
	addi     r5, r5, 0x00434F4E@l
	bl       isID__Q32og6Screen14DispMemberBaseFUlUx
	clrlwi.  r0, r3, 0x18
	beq      lbl_80320210
	stw      r27, 0x38(r31)
	b        lbl_80320348

lbl_80320210:
	lis      r4, 0x004F4741@ha
	lis      r6, 0x5F475250@ha
	lis      r5, 0x0055464F@ha
	mr       r3, r27
	addi     r4, r4, 0x004F4741@l
	addi     r6, r6, 0x5F475250@l
	addi     r5, r5, 0x0055464F@l
	bl       isID__Q32og6Screen14DispMemberBaseFUlUx
	clrlwi.  r0, r3, 0x18
	beq      lbl_8032028C
	lwz      r0, 0x10(r27)
	cmpwi    r0, 2
	beq      lbl_80320260
	bge      lbl_8032026C
	cmpwi    r0, 1
	bge      lbl_80320254
	b        lbl_8032026C

lbl_80320254:
	addi     r0, r27, 0x18
	stw      r0, 0x38(r31)
	b        lbl_80320280

lbl_80320260:
	addi     r0, r27, 0x50
	stw      r0, 0x38(r31)
	b        lbl_80320280

lbl_8032026C:
	addi     r3, r28, 0
	addi     r5, r28, 0x14
	li       r4, 0xe6
	crclr    6
	bl       panic_f__12JUTExceptionFPCciPCce

lbl_80320280:
	lbz      r0, 0x8a(r27)
	stb      r0, 0x16c(r31)
	b        lbl_80320348

lbl_8032028C:
	lis      r4, 0x004F4741@ha
	lis      r6, 0x554D4D59@ha
	mr       r3, r27
	li       r5, 0x44
	addi     r4, r4, 0x004F4741@l
	addi     r6, r6, 0x554D4D59@l
	bl       isID__Q32og6Screen14DispMemberBaseFUlUx
	clrlwi.  r0, r3, 0x18
	beq      lbl_80320334
	li       r3, 0x38
	bl       __nw__FUl
	cmplwi   r3, 0
	beq      lbl_8032032C
	lis      r5, __vt__Q32og6Screen14DispMemberBase@ha
	lis      r4, __vt__Q32og6Screen17DispMemberContena@ha
	addi     r0, r5, __vt__Q32og6Screen14DispMemberBase@l
	li       r10, 0
	stw      r0, 0(r3)
	addi     r0, r4, __vt__Q32og6Screen17DispMemberContena@l
	li       r9, 0x64
	li       r8, 0x3e8
	stw      r10, 4(r3)
	li       r7, 0x14
	li       r6, 0x32
	li       r5, 0x3c
	stw      r0, 0(r3)
	li       r4, 0xc8
	li       r0, -1
	stw      r9, 0xc(r3)
	stw      r8, 0x10(r3)
	stw      r10, 0x14(r3)
	stw      r7, 0x18(r3)
	stw      r6, 0x1c(r3)
	stw      r5, 0x20(r3)
	stw      r4, 0x24(r3)
	stw      r0, 8(r3)
	stw      r10, 0x28(r3)
	stb      r10, 0x2c(r3)
	stw      r10, 0x30(r3)
	sth      r10, 0x34(r3)

lbl_8032032C:
	stw      r3, 0x38(r31)
	b        lbl_80320348

lbl_80320334:
	addi     r3, r28, 0
	addi     r5, r28, 0x30
	li       r4, 0xf2
	crclr    6
	bl       panic_f__12JUTExceptionFPCciPCce

lbl_80320348:
	lwz      r5, 0x38(r31)
	li       r0, 0
	li       r3, 0x178
	lwz      r4, 8(r5)
	stw      r4, 0xb8(r31)
	lwz      r4, 0xc(r5)
	stw      r4, 0xbc(r31)
	lwz      r4, 0x10(r5)
	stw      r4, 0xc0(r31)
	lwz      r4, 0x14(r5)
	stw      r4, 0xc4(r31)
	lwz      r4, 0x18(r5)
	stw      r4, 0xc8(r31)
	lwz      r4, 0x1c(r5)
	stw      r4, 0xcc(r31)
	lwz      r4, 0x20(r5)
	stw      r4, 0xd0(r31)
	lwz      r4, 0x24(r5)
	stw      r4, 0xd4(r31)
	lwz      r4, 0x28(r5)
	stw      r4, 0xd8(r31)
	lbz      r4, 0x2c(r5)
	stb      r4, 0xdc(r31)
	lwz      r4, 0x30(r5)
	stw      r4, 0xe0(r31)
	lha      r4, 0x34(r5)
	sth      r4, 0xe4(r31)
	lwz      r4, 0x38(r31)
	stw      r0, 0x30(r4)
	bl       __nw__FUl
	or.      r0, r3, r3
	beq      lbl_803203D4
	lwz      r4, 0x38(r31)
	bl __ct__Q32og6Screen14ContenaCounterFPQ32og6Screen17DispMemberContena
	mr       r0, r3

lbl_803203D4:
	stw      r0, 0x3c(r31)
	lwz      r3, 0x38(r31)
	lwz      r0, 8(r3)
	cmpwi    r0, 2
	beq      lbl_80320434
	bge      lbl_803203FC
	cmpwi    r0, 0
	beq      lbl_8032040C
	bge      lbl_80320420
	b        lbl_80320470

lbl_803203FC:
	cmpwi    r0, 4
	beq      lbl_8032045C
	bge      lbl_80320470
	b        lbl_80320448

lbl_8032040C:
	lwz      r3, 0x3c(r31)
	mr       r5, r26
	addi     r4, r28, 0x54
	bl       setblo__Q32og6Screen14ContenaCounterFPcP10JKRArchive
	b        lbl_80320484

lbl_80320420:
	lwz      r3, 0x3c(r31)
	mr       r5, r26
	addi     r4, r28, 0x64
	bl       setblo__Q32og6Screen14ContenaCounterFPcP10JKRArchive
	b        lbl_80320484

lbl_80320434:
	lwz      r3, 0x3c(r31)
	mr       r5, r26
	addi     r4, r28, 0x74
	bl       setblo__Q32og6Screen14ContenaCounterFPcP10JKRArchive
	b        lbl_80320484

lbl_80320448:
	lwz      r3, 0x3c(r31)
	mr       r5, r26
	addi     r4, r28, 0x84
	bl       setblo__Q32og6Screen14ContenaCounterFPcP10JKRArchive
	b        lbl_80320484

lbl_8032045C:
	lwz      r3, 0x3c(r31)
	mr       r5, r26
	addi     r4, r28, 0x94
	bl       setblo__Q32og6Screen14ContenaCounterFPcP10JKRArchive
	b        lbl_80320484

lbl_80320470:
	addi     r3, r28, 0
	addi     r5, r28, 0xa4
	li       r4, 0x10a
	crclr    6
	bl       panic_f__12JUTExceptionFPCciPCce

lbl_80320484:
	li       r3, 0x138
	bl       __nw__FUl
	or.      r0, r3, r3
	beq      lbl_8032049C
	bl       __ct__Q29P2DScreen3MgrFv
	mr       r0, r3

lbl_8032049C:
	stw      r0, 0x44(r31)
	mr       r6, r26
	addi     r4, r28, 0xc0
	lis      r5, 0x104
	lwz      r3, 0x44(r31)
	bl       set__9J2DScreenFPCcUlP10JKRArchive
	lwz      r3, 0x3c(r31)
	bl       setFurikoScreen__Q22og6ScreenFPQ29P2DScreen3Mgr
	li       r3, 0x148
	bl       __nw__FUl
	or.      r0, r3, r3
	beq      lbl_803204D4
	bl       __ct__Q29P2DScreen10Mgr_tuningFv
	mr       r0, r3

lbl_803204D4:
	stw      r0, 0x40(r31)
	mr       r6, r26
	addi     r4, r28, 0xcc
	lis      r5, 0x104
	lwz      r3, 0x40(r31)
	bl       set__9J2DScreenFPCcUlP10JKRArchive
	lwz      r3, 0x40(r31)
	lis      r4, 0x73706F74@ha
	addi     r6, r4, 0x73706F74@l
	li       r5, 0x50
	lwz      r12, 0(r3)
	lwz      r12, 0x3c(r12)
	mtctr    r12
	bctrl
	stw      r3, 0xf8(r31)
	li       r4, 4
	lwz      r3, 0xf8(r31)
	bl       setBasePosition__7J2DPaneF15J2DBasePosition
	lwz      r3, 0xf8(r31)
	lfs      f0, 0xd4(r3)
	stfs     f0, 0xfc(r31)
	lwz      r3, 0xf8(r31)
	lfs      f0, 0xd8(r3)
	stfs     f0, 0x100(r31)
	lwz      r3, 0x3c(r31)
	bl       setCallBackMessage__Q22og6ScreenFPQ29P2DScreen3Mgr
	li       r0, 0
	lis      r3, 0x73685F63@ha
	stw      r0, 0x4c(r31)
	lis      r4, 0x6F6C6F72@ha
	addi     r5, r3, 0x73685F63@l
	stw      r0, 0x50(r31)
	addi     r6, r4, 0x6F6C6F72@l
	stw      r0, 0x54(r31)
	stw      r0, 0x58(r31)
	stw      r0, 0x5c(r31)
	stw      r0, 0x60(r31)
	stw      r0, 0x64(r31)
	stw      r0, 0x68(r31)
	stw      r0, 0x6c(r31)
	stw      r0, 0x70(r31)
	lwz      r3, 0x3c(r31)
	lwz      r12, 0(r3)
	lwz      r12, 0x3c(r12)
	mtctr    r12
	bctrl
	cmplwi   r3, 0
	beq      lbl_8032059C
	lwz      r3, 0x3c(r31)
	bl       setCallBackMessage__Q22og6ScreenFPQ29P2DScreen3Mgr

lbl_8032059C:
	lwz      r3, 0x3c(r31)
	lis      r4, 0x6D675F31@ha
	addi     r6, r4, 0x6D675F31@l
	li       r5, 0
	lwz      r12, 0(r3)
	lwz      r12, 0x3c(r12)
	mtctr    r12
	bctrl
	stw      r3, 0x8c(r31)
	lis      r3, 0x6D675F32@ha
	addi     r6, r3, 0x6D675F32@l
	li       r5, 0
	lwz      r3, 0x3c(r31)
	lwz      r12, 0(r3)
	lwz      r12, 0x3c(r12)
	mtctr    r12
	bctrl
	stw      r3, 0x90(r31)
	lis      r3, 0x6D675F33@ha
	addi     r6, r3, 0x6D675F33@l
	li       r5, 0
	lwz      r3, 0x3c(r31)
	lwz      r12, 0(r3)
	lwz      r12, 0x3c(r12)
	mtctr    r12
	bctrl
	stw      r3, 0x94(r31)
	lis      r3, 0x6D675F34@ha
	addi     r6, r3, 0x6D675F34@l
	li       r5, 0
	lwz      r3, 0x3c(r31)
	lwz      r12, 0(r3)
	lwz      r12, 0x3c(r12)
	mtctr    r12
	bctrl
	stw      r3, 0x98(r31)
	lis      r3, 0x6D675F35@ha
	addi     r6, r3, 0x6D675F35@l
	li       r5, 0
	lwz      r3, 0x3c(r31)
	lwz      r12, 0(r3)
	lwz      r12, 0x3c(r12)
	mtctr    r12
	bctrl
	stw      r3, 0x9c(r31)
	lis      r3, 0x6D675F36@ha
	addi     r6, r3, 0x6D675F36@l
	li       r5, 0
	lwz      r3, 0x3c(r31)
	lwz      r12, 0(r3)
	lwz      r12, 0x3c(r12)
	mtctr    r12
	bctrl
	stw      r3, 0xa0(r31)
	mr       r28, r31
	li       r29, 0
	li       r27, 1

lbl_80320680:
	lwz      r3, 0x8c(r28)
	li       r4, 0
	li       r5, 0
	stb      r27, 0xb0(r3)
	lwz      r3, 0x8c(r28)
	bl       setInfluencedAlpha__7J2DPaneFbb
	li       r3, 0x18
	bl       __nw__FUl
	or.      r0, r3, r3
	beq      lbl_803206B0
	bl       __ct__Q32og6Screen8AlphaMgrFv
	mr       r0, r3

lbl_803206B0:
	stw      r0, 0x74(r28)
	lfs      f1, lbl_8051DC8C@sda21(r2)
	lwz      r3, 0x74(r28)
	bl       out__Q32og6Screen8AlphaMgrFf
	addi     r29, r29, 1
	addi     r28, r28, 4
	cmpwi    r29, 6
	blt      lbl_80320680
	li       r0, 0
	lfs      f1, lbl_8051DC8C@sda21(r2)
	stw      r0, 0xa4(r31)
	lwz      r0, 0xa4(r31)
	slwi     r0, r0, 2
	add      r3, r31, r0
	lwz      r3, 0x74(r3)
	bl       in__Q32og6Screen8AlphaMgrFf
	lis      r6, 0x6133646C@ha
	lwz      r4, 0x3c(r31)
	mr       r3, r26
	li       r5, 0x6f74
	addi     r6, r6, 0x6133646C@l
	bl setCallBack_3DStick__Q22og6ScreenFP10JKRArchivePQ29P2DScreen3MgrUx mr
r0, r3 li       r3, 8 mr       r26, r0 bl       __nw__FUl or.      r0, r3,
r3 beq      lbl_8032072C mr       r4, r26 bl
__ct__Q32og6Screen12StickAnimMgrFPQ32og6Screen16CallBack_Picture mr r0, r3

lbl_8032072C:
	stw      r0, 0x114(r31)
	lwz      r3, 0x114(r31)
	bl       stickUpDown__Q32og6Screen12StickAnimMgrFv
	lis      r4, 0x79615F75@ha
	lwz      r3, 0x3c(r31)
	addi     r6, r4, 0x79615F75@l
	li       r5, 0x4e
	bl       TagSearch__Q22og6ScreenFP9J2DScreenUx
	stw      r3, 0x128(r31)
	li       r4, 4
	lwz      r3, 0x128(r31)
	lfs      f0, 0xd4(r3)
	stfs     f0, 0x130(r31)
	lwz      r3, 0x128(r31)
	lfs      f0, 0xd8(r3)
	stfs     f0, 0x134(r31)
	lwz      r3, 0x128(r31)
	bl       setBasePosition__7J2DPaneF15J2DBasePosition
	lis      r4, 0x79615F6C@ha
	lwz      r3, 0x3c(r31)
	addi     r6, r4, 0x79615F6C@l
	li       r5, 0x4e
	bl       TagSearch__Q22og6ScreenFP9J2DScreenUx
	stw      r3, 0x12c(r31)
	li       r4, 4
	lwz      r3, 0x12c(r31)
	lfs      f0, 0xd4(r3)
	stfs     f0, 0x138(r31)
	lwz      r3, 0x12c(r31)
	lfs      f0, 0xd8(r3)
	stfs     f0, 0x13c(r31)
	lwz      r3, 0x12c(r31)
	bl       setBasePosition__7J2DPaneF15J2DBasePosition
	li       r3, 0x18
	bl       __nw__FUl
	or.      r0, r3, r3
	beq      lbl_803207C8
	bl       __ct__Q32og6Screen8AlphaMgrFv
	mr       r0, r3

lbl_803207C8:
	stw      r0, 0x118(r31)
	li       r3, 0x18
	bl       __nw__FUl
	or.      r0, r3, r3
	beq      lbl_803207E4
	bl       __ct__Q32og6Screen8AlphaMgrFv
	mr       r0, r3

lbl_803207E4:
	stw      r0, 0x11c(r31)
	lfs      f1, lbl_8051DC98@sda21(r2)
	lwz      r3, 0x118(r31)
	bl       in__Q32og6Screen8AlphaMgrFf
	lwz      r3, 0x11c(r31)
	lfs      f1, lbl_8051DC98@sda21(r2)
	bl       in__Q32og6Screen8AlphaMgrFf
	lwz      r4, 0x128(r31)
	li       r3, 0x1c
	lbz      r0, 0xb2(r4)
	stb      r0, 0x148(r31)
	bl       __nw__FUl
	or.      r0, r3, r3
	beq      lbl_80320824
	bl       __ct__Q32og6Screen8ScaleMgrFv
	mr       r0, r3

lbl_80320824:
	stw      r0, 0x120(r31)
	li       r3, 0x1c
	bl       __nw__FUl
	or.      r0, r3, r3
	beq      lbl_80320840
	bl       __ct__Q32og6Screen8ScaleMgrFv
	mr       r0, r3

lbl_80320840:
	stw      r0, 0x124(r31)
	li       r0, 0
	lis      r5, 0x66666667@ha
	lis      r4, 0x695F3030@ha
	lis      r3, 0x0050696B@ha
	stw      r0, 0x150(r31)
	addi     r30, r5, 0x66666667@l
	addi     r29, r4, 0x695F3030@l
	addi     r28, r3, 0x0050696B@l
	li       r27, 0

lbl_80320868:
	mulhw    r5, r30, r27
	lwz      r3, 0x3c(r31)
	lwz      r12, 0(r3)
	lwz      r12, 0x3c(r12)
	srawi    r0, r5, 2
	srwi     r4, r0, 0x1f
	add      r0, r0, r4
	mulli    r0, r0, 0xa
	subf     r4, r0, r27
	srawi    r0, r4, 0x1f
	addc     r6, r4, r29
	adde     r7, r0, r28
	srawi    r0, r5, 2
	srwi     r4, r0, 0x1f
	add      r5, r0, r4
	mulhw    r0, r30, r5
	srawi    r0, r0, 2
	srwi     r4, r0, 0x1f
	add      r0, r0, r4
	mulli    r0, r0, 0xa
	subf     r0, r0, r5
	slwi     r4, r0, 8
	srawi    r0, r4, 0x1f
	addc     r6, r6, r4
	adde     r5, r7, r0
	mtctr    r12
	bctrl
	cmplwi   r3, 0
	beq      lbl_803208F4
	lwz      r3, 0x150(r31)
	addi     r27, r27, 1
	cmpwi    r27, 0x64
	addi     r0, r3, 1
	stw      r0, 0x150(r31)
	blt      lbl_80320868

lbl_803208F4:
	lwz      r0, 0x150(r31)
	slwi     r3, r0, 2
	bl       __nwa__FUl
	lis      r6, 0x66666667@ha
	lis      r5, 0x695F3030@ha
	lis      r4, 0x0050696B@ha
	stw      r3, 0x14c(r31)
	addi     r28, r6, 0x66666667@l
	addi     r29, r5, 0x695F3030@l
	addi     r30, r4, 0x0050696B@l
	li       r26, 0
	li       r27, 0
	b        lbl_803209AC

lbl_80320928:
	mulhw    r5, r28, r26
	lwz      r3, 0x3c(r31)
	lwz      r12, 0(r3)
	lwz      r12, 0x3c(r12)
	srawi    r0, r5, 2
	srwi     r4, r0, 0x1f
	add      r0, r0, r4
	mulli    r0, r0, 0xa
	subf     r4, r0, r26
	srawi    r0, r4, 0x1f
	addc     r6, r4, r29
	adde     r7, r0, r30
	srawi    r0, r5, 2
	srwi     r4, r0, 0x1f
	add      r5, r0, r4
	mulhw    r0, r28, r5
	srawi    r0, r0, 2
	srwi     r4, r0, 0x1f
	add      r0, r0, r4
	mulli    r0, r0, 0xa
	subf     r0, r0, r5
	slwi     r4, r0, 8
	srawi    r0, r4, 0x1f
	addc     r6, r6, r4
	adde     r5, r7, r0
	mtctr    r12
	bctrl
	lwz      r4, 0x14c(r31)
	li       r0, 0
	addi     r26, r26, 1
	stwx     r3, r4, r27
	addi     r27, r27, 4
	stb      r0, 0xb0(r3)

lbl_803209AC:
	lwz      r0, 0x150(r31)
	cmpw     r26, r0
	blt      lbl_80320928
	lis      r4, 0x6E796F6E@ha
	lwz      r3, 0x3c(r31)
	addi     r6, r4, 0x6E796F6E@l
	li       r5, 0x4e6f
	bl       TagSearch__Q22og6ScreenFP9J2DScreenUx
	stw      r3, 0x154(r31)
	lis      r5, 0x796F6E49@ha
	lis      r4, 0x004E6F6E@ha
	lwz      r3, 0x3c(r31)
	addi     r6, r5, 0x796F6E49@l
	addi     r5, r4, 0x004E6F6E@l
	bl       TagSearch__Q22og6ScreenFP9J2DScreenUx
	stw      r3, 0x158(r31)
	lis      r5, 0x72657475@ha
	lis      r4, 0x004E7469@ha
	lwz      r3, 0x3c(r31)
	addi     r6, r5, 0x72657475@l
	addi     r5, r4, 0x004E7469@l
	bl       TagSearch__Q22og6ScreenFP9J2DScreenUx
	stw      r3, 0x160(r31)
	lis      r5, 0x65747549@ha
	lis      r4, 0x4E746972@ha
	lwz      r3, 0x3c(r31)
	addi     r6, r5, 0x65747549@l
	addi     r5, r4, 0x4E746972@l
	bl       TagSearch__Q22og6ScreenFP9J2DScreenUx
	stw      r3, 0x164(r31)
	li       r3, 0x1c
	bl       __nw__FUl
	or.      r0, r3, r3
	beq      lbl_80320A3C
	bl       __ct__Q32og6Screen8ScaleMgrFv
	mr       r0, r3

lbl_80320A3C:
	stw      r0, 0x15c(r31)
	li       r3, 0x1c
	bl       __nw__FUl
	or.      r0, r3, r3
	beq      lbl_80320A58
	bl       __ct__Q32og6Screen8ScaleMgrFv
	mr       r0, r3

lbl_80320A58:
	stw      r0, 0x168(r31)
	lwz      r3, 0x38(r31)
	lwz      r0, 8(r3)
	cmpwi    r0, 3
	beq      lbl_80320A74
	cmpwi    r0, 4
	bne      lbl_80320AD0

lbl_80320A74:
	lis      r4, 0x50315F31@ha
	lwz      r3, 0x3c(r31)
	addi     r6, r4, 0x50315F31@l
	li       r5, 0
	bl       TagSearch__Q22og6ScreenFP9J2DScreenUx
	mr       r26, r3
	lis      r4, 0x50315F32@ha
	lwz      r3, 0x3c(r31)
	addi     r6, r4, 0x50315F32@l
	li       r5, 0
	bl       TagSearch__Q22og6ScreenFP9J2DScreenUx
	lbz      r0, 0x16c(r31)
	cmplwi   r0, 0
	beq      lbl_80320AC0
	li       r4, 1
	li       r0, 0
	stb      r4, 0xb0(r26)
	stb      r0, 0xb0(r3)
	b        lbl_80320AD0

lbl_80320AC0:
	li       r4, 1
	li       r0, 0
	stb      r4, 0xb0(r3)
	stb      r0, 0xb0(r26)

lbl_80320AD0:
	lmw      r26, 8(r1)
	lwz      r0, 0x24(r1)
	mtlr     r0
	addi     r1, r1, 0x20
	blr
	*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	00005C
 */
void ObjContena::tairetuOnOff(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000070
 */
void ObjContena::changeMessage(u32)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000014
 */
void ObjContena::isMessage(int)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000048
 */
void ObjContena::setStickUp(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000048
 */
void ObjContena::setStickDown(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000048
 */
void ObjContena::setStickUpDown(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	80320AE4
 * Size:	000284
 */
void ObjContena::putinPiki(bool soundType)
{
	og::Screen::DispMemberContena* disp = m_disp;
	if (disp->m_currField >= disp->m_inOnionCount) {
		if (disp->m_inSquadCount == 0) {
			if (m_state == 4) {
				if (!soundType) {
					ogSound->setError();
				}
			} else {
				ogSound->setError();
				if (m_state != 4) {
					m_alphaMgr[m_state]->out(0.5f);
					m_state = 4;
					m_alphaMgr[m_state]->in(0.3f);
				}
				m_alphaArrow1->out(0.5f);
				m_alphaArrow2->in(0.3f);
				m_stickAnimMgr->stickDown();
			}
		} else {
			if (m_state != 0) {
				m_alphaMgr[m_state]->out(0.5f);
				m_state = 0;
				m_alphaMgr[m_state]->in(0.3f);
			}
			disp->m_inOnionCount++;
			disp->m_inSquadCount--;
			disp->m_inParty2--;
			disp->m_onMapCount--;
			disp->m_result++;
			disp->_28 = fabs(disp->m_result); // should be just abs
			m_alphaArrow1->in(0.3f);
			m_alphaArrow2->in(0.3f);
			m_stickAnimMgr->stickUpDown();
			if (m_timer0 >= 0.0f) {
				m_scaleArrow2->up();
				m_timer0 = msVal._1C;
			}
			m_scaleMgr3->up(0.1f, 30.0f, 0.8f, 0.0f);
			m_scaleMgr4->down(0.05f, 35.0f, 0.8f);
			ogSound->setPlusMinus(soundType);
		}
	} else if (m_state == 1) {
		if (!soundType) {
			ogSound->setError();
		}
	} else {
		ogSound->setError();
		if (m_state != 1) {
			m_alphaMgr[m_state]->out(0.5f);
			m_state = 1;
			m_alphaMgr[m_state]->in(0.3f);
		}
		m_alphaArrow1->in(0.5f);
		m_alphaArrow2->in(0.3f);
		m_stickAnimMgr->stickDown();
	}
	/*
	stwu     r1, -0x20(r1)
	mflr     r0
	stw      r0, 0x24(r1)
	stw      r31, 0x1c(r1)
	stw      r30, 0x18(r1)
	mr       r30, r4
	stw      r29, 0x14(r1)
	mr       r29, r3
	lwz      r31, 0x38(r3)
	lwz      r3, 0x10(r31)
	lwz      r0, 0xc(r31)
	cmplw    r3, r0
	bgt      lbl_80320BA4
	lwz      r0, 0xa4(r29)
	cmpwi    r0, 1
	bne      lbl_80320B38
	clrlwi.  r0, r30, 0x18
	bne      lbl_80320D4C
	lwz      r3, ogSound__2og@sda21(r13)
	bl       setError__Q22og5SoundFv
	b        lbl_80320D4C

lbl_80320B38:
	lwz      r3, ogSound__2og@sda21(r13)
	bl       setError__Q22og5SoundFv
	lwz      r0, 0xa4(r29)
	cmplwi   r0, 1
	beq      lbl_80320B80
	slwi     r0, r0, 2
	lfs      f1, lbl_8051DC90@sda21(r2)
	add      r3, r29, r0
	lwz      r3, 0x74(r3)
	bl       out__Q32og6Screen8AlphaMgrFf
	li       r0, 1
	lfs      f1, lbl_8051DC98@sda21(r2)
	stw      r0, 0xa4(r29)
	lwz      r0, 0xa4(r29)
	slwi     r0, r0, 2
	add      r3, r29, r0
	lwz      r3, 0x74(r3)
	bl       in__Q32og6Screen8AlphaMgrFf

lbl_80320B80:
	lwz      r3, 0x118(r29)
	lfs      f1, lbl_8051DC90@sda21(r2)
	bl       out__Q32og6Screen8AlphaMgrFf
	lwz      r3, 0x11c(r29)
	lfs      f1, lbl_8051DC98@sda21(r2)
	bl       in__Q32og6Screen8AlphaMgrFf
	lwz      r3, 0x114(r29)
	bl       stickDown__Q32og6Screen12StickAnimMgrFv
	b        lbl_80320D4C

lbl_80320BA4:
	lwz      r0, 0x14(r31)
	cmplwi   r0, 0
	bne      lbl_80320C3C
	lwz      r0, 0xa4(r29)
	cmpwi    r0, 4
	bne      lbl_80320BD0
	clrlwi.  r0, r30, 0x18
	bne      lbl_80320D4C
	lwz      r3, ogSound__2og@sda21(r13)
	bl       setError__Q22og5SoundFv
	b        lbl_80320D4C

lbl_80320BD0:
	lwz      r3, ogSound__2og@sda21(r13)
	bl       setError__Q22og5SoundFv
	lwz      r0, 0xa4(r29)
	cmplwi   r0, 4
	beq      lbl_80320C18
	slwi     r0, r0, 2
	lfs      f1, lbl_8051DC90@sda21(r2)
	add      r3, r29, r0
	lwz      r3, 0x74(r3)
	bl       out__Q32og6Screen8AlphaMgrFf
	li       r0, 4
	lfs      f1, lbl_8051DC98@sda21(r2)
	stw      r0, 0xa4(r29)
	lwz      r0, 0xa4(r29)
	slwi     r0, r0, 2
	add      r3, r29, r0
	lwz      r3, 0x74(r3)
	bl       in__Q32og6Screen8AlphaMgrFf

lbl_80320C18:
	lwz      r3, 0x118(r29)
	lfs      f1, lbl_8051DC90@sda21(r2)
	bl       out__Q32og6Screen8AlphaMgrFf
	lwz      r3, 0x11c(r29)
	lfs      f1, lbl_8051DC98@sda21(r2)
	bl       in__Q32og6Screen8AlphaMgrFf
	lwz      r3, 0x114(r29)
	bl       stickDown__Q32og6Screen12StickAnimMgrFv
	b        lbl_80320D4C

lbl_80320C3C:
	lwz      r0, 0xa4(r29)
	cmplwi   r0, 0
	beq      lbl_80320C7C
	slwi     r0, r0, 2
	lfs      f1, lbl_8051DC90@sda21(r2)
	add      r3, r29, r0
	lwz      r3, 0x74(r3)
	bl       out__Q32og6Screen8AlphaMgrFf
	li       r0, 0
	lfs      f1, lbl_8051DC98@sda21(r2)
	stw      r0, 0xa4(r29)
	lwz      r0, 0xa4(r29)
	slwi     r0, r0, 2
	add      r3, r29, r0
	lwz      r3, 0x74(r3)
	bl       in__Q32og6Screen8AlphaMgrFf

lbl_80320C7C:
	lwz      r3, 0xc(r31)
	addi     r0, r3, 1
	stw      r0, 0xc(r31)
	lwz      r3, 0x14(r31)
	addi     r0, r3, -1
	stw      r0, 0x14(r31)
	lwz      r3, 0x1c(r31)
	addi     r0, r3, -1
	stw      r0, 0x1c(r31)
	lwz      r3, 0x20(r31)
	addi     r0, r3, -1
	stw      r0, 0x20(r31)
	lha      r3, 0x34(r31)
	addi     r0, r3, 1
	sth      r0, 0x34(r31)
	lha      r3, 0x34(r31)
	bl       abs
	clrlwi   r0, r3, 0x10
	lfs      f1, lbl_8051DC98@sda21(r2)
	stw      r0, 0x28(r31)
	lwz      r3, 0x118(r29)
	bl       in__Q32og6Screen8AlphaMgrFf
	lwz      r3, 0x11c(r29)
	lfs      f1, lbl_8051DC98@sda21(r2)
	bl       in__Q32og6Screen8AlphaMgrFf
	lwz      r3, 0x114(r29)
	bl       stickUpDown__Q32og6Screen12StickAnimMgrFv
	lfs      f1, 0x140(r29)
	lfs      f0, lbl_8051DC8C@sda21(r2)
	fcmpo    cr0, f1, f0
	cror     2, 0, 2
	bne      lbl_80320D14
	lwz      r3, 0x120(r29)
	bl       up__Q32og6Screen8ScaleMgrFv
	lis      r3, msVal__Q32og9newScreen10ObjContena@ha
	addi     r3, r3, msVal__Q32og9newScreen10ObjContena@l
	lfs      f0, 0x38(r3)
	stfs     f0, 0x140(r29)

lbl_80320D14:
	lwz      r3, 0x15c(r29)
	lfs      f1, lbl_8051DC9C@sda21(r2)
	lfs      f2, lbl_8051DCA0@sda21(r2)
	lfs      f3, lbl_8051DCA4@sda21(r2)
	lfs      f4, lbl_8051DC8C@sda21(r2)
	bl       up__Q32og6Screen8ScaleMgrFffff
	lwz      r3, 0x168(r29)
	lfs      f1, lbl_8051DCA8@sda21(r2)
	lfs      f2, lbl_8051DCAC@sda21(r2)
	lfs      f3, lbl_8051DCA4@sda21(r2)
	bl       down__Q32og6Screen8ScaleMgrFfff
	lwz      r3, ogSound__2og@sda21(r13)
	mr       r4, r30
	bl       setPlusMinus__Q22og5SoundFb

lbl_80320D4C:
	lwz      r0, 0x24(r1)
	lwz      r31, 0x1c(r1)
	lwz      r30, 0x18(r1)
	lwz      r29, 0x14(r1)
	mtlr     r0
	addi     r1, r1, 0x20
	blr
	*/
}

/*
 * --INFO--
 * Address:	80320D68
 * Size:	000320
 */
void ObjContena::takeoutPiki(bool soundType)
{
	og::Screen::DispMemberContena* disp = m_disp;
	if (disp->m_maxPikiOnField >= disp->m_inOnionCount) {
		if (disp->m_inOnionCount == 0) {
			if (m_state == 3) {
				if (!soundType) {
					ogSound->setError();
				}
			} else {
				ogSound->setError();
				if (m_state != 3) {
					m_alphaMgr[m_state]->out(0.5f);
					m_state = 3;
					m_alphaMgr[m_state]->in(0.3f);
				}
				m_alphaArrow1->out(0.3f);
				m_alphaArrow2->in(0.5f);
				m_stickAnimMgr->stickUp();
			}
		} else if (disp->m_onMapCount < disp->m_maxPikiCount) {
			if (m_state != 0) {
				m_alphaMgr[m_state]->out(0.5f);
				m_state = 0;
				m_alphaMgr[m_state]->in(0.3f);
			}
			disp->m_inOnionCount--;
			disp->m_inSquadCount++;
			disp->m_inParty2++;
			disp->m_onMapCount++;
			disp->m_result--;
			disp->_28 = fabs(disp->m_result); // should be just abs
			m_alphaArrow1->in(0.3f);
			m_alphaArrow2->in(0.3f);
			m_stickAnimMgr->stickUpDown();
			if (m_timer1 >= 0.0f) {
				m_scaleArrow2->up();
				m_timer1 = msVal._38;
			}
			m_scaleMgr3->up(0.1f, 30.0f, 0.8f, 0.0f);
			m_scaleMgr4->down(0.05f, 35.0f, 0.8f);
			ogSound->setPlusMinus(soundType);
		} else if (m_state == 5) {
			if (!soundType) {
				ogSound->setError();
			}
		} else {
			ogSound->setError();
			if (m_state != 5) {
				m_alphaMgr[m_state]->out(0.5f);
				m_state = 5;
				m_alphaMgr[m_state]->in(0.3f);
			}
			m_alphaArrow1->in(0.3f);
			m_alphaArrow2->in(0.5f);
			m_stickAnimMgr->stickUp();
		}
	} else if (m_state == 2) {
		if (!soundType) {
			ogSound->setError();
		}
	} else {
		ogSound->setError();
		if (m_state != 2) {
			m_alphaMgr[m_state]->out(0.5f);
			m_state = 2;
			m_alphaMgr[m_state]->in(0.3f);
		}
		m_alphaArrow1->in(0.3f);
		m_alphaArrow2->in(0.5f);
		m_stickAnimMgr->stickUp();
	}
	/*
	stwu     r1, -0x20(r1)
	mflr     r0
	stw      r0, 0x24(r1)
	stw      r31, 0x1c(r1)
	stw      r30, 0x18(r1)
	mr       r30, r4
	stw      r29, 0x14(r1)
	mr       r29, r3
	lwz      r31, 0x38(r3)
	lwz      r3, 0x14(r31)
	lwz      r0, 0x18(r31)
	cmplw    r3, r0
	blt      lbl_80320E28
	lwz      r0, 0xa4(r29)
	cmpwi    r0, 2
	bne      lbl_80320DBC
	clrlwi.  r0, r30, 0x18
	bne      lbl_8032106C
	lwz      r3, ogSound__2og@sda21(r13)
	bl       setError__Q22og5SoundFv
	b        lbl_8032106C

lbl_80320DBC:
	lwz      r3, ogSound__2og@sda21(r13)
	bl       setError__Q22og5SoundFv
	lwz      r0, 0xa4(r29)
	cmplwi   r0, 2
	beq      lbl_80320E04
	slwi     r0, r0, 2
	lfs      f1, lbl_8051DC90@sda21(r2)
	add      r3, r29, r0
	lwz      r3, 0x74(r3)
	bl       out__Q32og6Screen8AlphaMgrFf
	li       r0, 2
	lfs      f1, lbl_8051DC98@sda21(r2)
	stw      r0, 0xa4(r29)
	lwz      r0, 0xa4(r29)
	slwi     r0, r0, 2
	add      r3, r29, r0
	lwz      r3, 0x74(r3)
	bl       in__Q32og6Screen8AlphaMgrFf

lbl_80320E04:
	lwz      r3, 0x118(r29)
	lfs      f1, lbl_8051DC98@sda21(r2)
	bl       in__Q32og6Screen8AlphaMgrFf
	lwz      r3, 0x11c(r29)
	lfs      f1, lbl_8051DC90@sda21(r2)
	bl       out__Q32og6Screen8AlphaMgrFf
	lwz      r3, 0x114(r29)
	bl       stickUp__Q32og6Screen12StickAnimMgrFv
	b        lbl_8032106C

lbl_80320E28:
	lwz      r0, 0xc(r31)
	cmplwi   r0, 0
	bne      lbl_80320EC0
	lwz      r0, 0xa4(r29)
	cmpwi    r0, 3
	bne      lbl_80320E54
	clrlwi.  r0, r30, 0x18
	bne      lbl_8032106C
	lwz      r3, ogSound__2og@sda21(r13)
	bl       setError__Q22og5SoundFv
	b        lbl_8032106C

lbl_80320E54:
	lwz      r3, ogSound__2og@sda21(r13)
	bl       setError__Q22og5SoundFv
	lwz      r0, 0xa4(r29)
	cmplwi   r0, 3
	beq      lbl_80320E9C
	slwi     r0, r0, 2
	lfs      f1, lbl_8051DC90@sda21(r2)
	add      r3, r29, r0
	lwz      r3, 0x74(r3)
	bl       out__Q32og6Screen8AlphaMgrFf
	li       r0, 3
	lfs      f1, lbl_8051DC98@sda21(r2)
	stw      r0, 0xa4(r29)
	lwz      r0, 0xa4(r29)
	slwi     r0, r0, 2
	add      r3, r29, r0
	lwz      r3, 0x74(r3)
	bl       in__Q32og6Screen8AlphaMgrFf

lbl_80320E9C:
	lwz      r3, 0x118(r29)
	lfs      f1, lbl_8051DC98@sda21(r2)
	bl       in__Q32og6Screen8AlphaMgrFf
	lwz      r3, 0x11c(r29)
	lfs      f1, lbl_8051DC90@sda21(r2)
	bl       out__Q32og6Screen8AlphaMgrFf
	lwz      r3, 0x114(r29)
	bl       stickUp__Q32og6Screen12StickAnimMgrFv
	b        lbl_8032106C

lbl_80320EC0:
	lwz      r3, 0x20(r31)
	lwz      r0, 0x24(r31)
	cmplw    r3, r0
	blt      lbl_80320F5C
	lwz      r0, 0xa4(r29)
	cmpwi    r0, 5
	bne      lbl_80320EF0
	clrlwi.  r0, r30, 0x18
	bne      lbl_8032106C
	lwz      r3, ogSound__2og@sda21(r13)
	bl       setError__Q22og5SoundFv
	b        lbl_8032106C

lbl_80320EF0:
	lwz      r3, ogSound__2og@sda21(r13)
	bl       setError__Q22og5SoundFv
	lwz      r0, 0xa4(r29)
	cmplwi   r0, 5
	beq      lbl_80320F38
	slwi     r0, r0, 2
	lfs      f1, lbl_8051DC90@sda21(r2)
	add      r3, r29, r0
	lwz      r3, 0x74(r3)
	bl       out__Q32og6Screen8AlphaMgrFf
	li       r0, 5
	lfs      f1, lbl_8051DC98@sda21(r2)
	stw      r0, 0xa4(r29)
	lwz      r0, 0xa4(r29)
	slwi     r0, r0, 2
	add      r3, r29, r0
	lwz      r3, 0x74(r3)
	bl       in__Q32og6Screen8AlphaMgrFf

lbl_80320F38:
	lwz      r3, 0x118(r29)
	lfs      f1, lbl_8051DC98@sda21(r2)
	bl       in__Q32og6Screen8AlphaMgrFf
	lwz      r3, 0x11c(r29)
	lfs      f1, lbl_8051DC90@sda21(r2)
	bl       out__Q32og6Screen8AlphaMgrFf
	lwz      r3, 0x114(r29)
	bl       stickUp__Q32og6Screen12StickAnimMgrFv
	b        lbl_8032106C

lbl_80320F5C:
	lwz      r0, 0xa4(r29)
	cmplwi   r0, 0
	beq      lbl_80320F9C
	slwi     r0, r0, 2
	lfs      f1, lbl_8051DC90@sda21(r2)
	add      r3, r29, r0
	lwz      r3, 0x74(r3)
	bl       out__Q32og6Screen8AlphaMgrFf
	li       r0, 0
	lfs      f1, lbl_8051DC98@sda21(r2)
	stw      r0, 0xa4(r29)
	lwz      r0, 0xa4(r29)
	slwi     r0, r0, 2
	add      r3, r29, r0
	lwz      r3, 0x74(r3)
	bl       in__Q32og6Screen8AlphaMgrFf

lbl_80320F9C:
	lwz      r3, 0xc(r31)
	addi     r0, r3, -1
	stw      r0, 0xc(r31)
	lwz      r3, 0x14(r31)
	addi     r0, r3, 1
	stw      r0, 0x14(r31)
	lwz      r3, 0x1c(r31)
	addi     r0, r3, 1
	stw      r0, 0x1c(r31)
	lwz      r3, 0x20(r31)
	addi     r0, r3, 1
	stw      r0, 0x20(r31)
	lha      r3, 0x34(r31)
	addi     r0, r3, -1
	sth      r0, 0x34(r31)
	lha      r3, 0x34(r31)
	bl       abs
	clrlwi   r0, r3, 0x10
	lfs      f1, lbl_8051DC98@sda21(r2)
	stw      r0, 0x28(r31)
	lwz      r3, 0x118(r29)
	bl       in__Q32og6Screen8AlphaMgrFf
	lwz      r3, 0x11c(r29)
	lfs      f1, lbl_8051DC98@sda21(r2)
	bl       in__Q32og6Screen8AlphaMgrFf
	lwz      r3, 0x114(r29)
	bl       stickUpDown__Q32og6Screen12StickAnimMgrFv
	lfs      f1, 0x144(r29)
	lfs      f0, lbl_8051DC8C@sda21(r2)
	fcmpo    cr0, f1, f0
	cror     2, 0, 2
	bne      lbl_80321034
	lwz      r3, 0x124(r29)
	bl       up__Q32og6Screen8ScaleMgrFv
	lis      r3, msVal__Q32og9newScreen10ObjContena@ha
	addi     r3, r3, msVal__Q32og9newScreen10ObjContena@l
	lfs      f0, 0x38(r3)
	stfs     f0, 0x144(r29)

lbl_80321034:
	lwz      r3, 0x168(r29)
	lfs      f1, lbl_8051DC9C@sda21(r2)
	lfs      f2, lbl_8051DCA0@sda21(r2)
	lfs      f3, lbl_8051DCA4@sda21(r2)
	lfs      f4, lbl_8051DC8C@sda21(r2)
	bl       up__Q32og6Screen8ScaleMgrFffff
	lwz      r3, 0x15c(r29)
	lfs      f1, lbl_8051DCA8@sda21(r2)
	lfs      f2, lbl_8051DCAC@sda21(r2)
	lfs      f3, lbl_8051DCA4@sda21(r2)
	bl       down__Q32og6Screen8ScaleMgrFfff
	lwz      r3, ogSound__2og@sda21(r13)
	mr       r4, r30
	bl       setPlusMinus__Q22og5SoundFb

lbl_8032106C:
	lwz      r0, 0x24(r1)
	lwz      r31, 0x1c(r1)
	lwz      r30, 0x18(r1)
	lwz      r29, 0x14(r1)
	mtlr     r0
	addi     r1, r1, 0x20
	blr
	*/
}

/*
 * --INFO--
 * Address:	80321088
 * Size:	00033C
 */
bool ObjContena::moveContena(void)
{
	bool ret                            = false;
	og::Screen::DispMemberContena* disp = m_disp;
	int* onyontype                      = &disp->m_onyonID;
	JUT_ASSERTLINE(603, onyontype, "DataContena is not found!\n");
	JUT_ASSERTLINE(607, *onyontype != -1, "Contena Type error!\n");

	if (m_timer1 > 0.0f) {
		m_timer1 -= sys->m_deltaTime;
	}
	if (m_timer2 > 0.0f) {
		m_timer2 -= sys->m_deltaTime;
	}

	if (!disp->_28) {
		disp->_28 = 1;
	} else {
		if (m_controller->m_padButton.m_buttonDown & Controller::PRESS_B) {
			disp                   = m_disp;
			disp->m_onyonID        = m_onyonID;
			disp->m_inOnionCount   = m_inOnionCount;
			disp->m_currField      = m_currField;
			disp->m_inSquadCount   = m_inSquadCount;
			disp->m_maxPikiOnField = m_maxPikiOnField;
			disp->m_inParty2       = m_inParty2;
			disp->m_onMapCount     = m_onMapCount;
			disp->m_maxPikiCount   = m_maxPikiCount;
			disp->_28              = _D8;
			disp->_2C              = _DC;
			disp->_30              = _E0;
			disp->m_result         = _E4;
			disp->_28              = 2;
			m_dispState            = 3;
			disp->m_result         = 0;
			disp->_28              = 0;
			if ((*onyontype == 3 || *onyontype) && disp->_2C) {
				ogSound->setCancel();
			} else {
				ogSound->setClose();
			}
			ret = true;
		} else if (m_controller->m_padButton.m_buttonDown & Controller::PRESS_A) {
			disp->_28   = 2;
			m_dispState = 4;
			ogSound->setDecide();
			ret = true;
		}
	}

	if (disp->_28 == 1) {
		if (m_controller->m_padButton.m_buttonDown & (Controller::PRESS_DPAD_UP | Controller::UNKNOWN_32)) {
			switch (m_screenState) {
			case 0:
				m_screenState = 1;
				putinPiki(false);
				m_timer0 = m_moveTime;
				break;
			case 1:
				m_timer0 -= sys->m_deltaTime;
				if (m_timer0 < 0.0f)
					m_screenState = 2;
				break;
			case 2:
				putinPiki(true);
				break;
			}
			m_screenState = 0;
		} else if (m_controller->m_padButton.m_buttonDown & (Controller::PRESS_DPAD_DOWN | Controller::UNKNOWN_31)) {
			switch (m_screenState) {
			case 0:
				m_screenState = 3;
				putinPiki(false);
				m_timer0 = m_moveTime;
				break;
			case 3:
				m_timer0 -= sys->m_deltaTime;
				if (m_timer0 < 0.0f)
					m_screenState = 4;
				break;
			case 4:
				putinPiki(true);
				break;
			}
			m_screenState = 0;
		} else {
			m_screenState = 0;
		}
	}
	return ret;
	/*
	stwu     r1, -0x20(r1)
	mflr     r0
	lis      r4, lbl_8048EFE0@ha
	stw      r0, 0x24(r1)
	stw      r31, 0x1c(r1)
	li       r31, 0
	stw      r30, 0x18(r1)
	stw      r29, 0x14(r1)
	mr       r29, r3
	stw      r28, 0x10(r1)
	addi     r28, r4, lbl_8048EFE0@l
	lwz      r3, 0x38(r3)
	addic.   r30, r3, 8
	bne      lbl_803210D4
	addi     r3, r28, 0
	addi     r5, r28, 0xd8
	li       r4, 0x25b
	crclr    6
	bl       panic_f__12JUTExceptionFPCciPCce

lbl_803210D4:
	lwz      r0, 0(r30)
	cmpwi    r0, -1
	bne      lbl_803210F4
	addi     r3, r28, 0
	addi     r5, r28, 0xf4
	li       r4, 0x25f
	crclr    6
	bl       panic_f__12JUTExceptionFPCciPCce

lbl_803210F4:
	lfs      f1, 0x140(r29)
	lfs      f0, lbl_8051DC8C@sda21(r2)
	fcmpo    cr0, f1, f0
	ble      lbl_80321114
	lwz      r3, sys@sda21(r13)
	lfs      f0, 0x54(r3)
	fsubs    f0, f1, f0
	stfs     f0, 0x140(r29)

lbl_80321114:
	lfs      f1, 0x144(r29)
	lfs      f0, lbl_8051DC8C@sda21(r2)
	fcmpo    cr0, f1, f0
	ble      lbl_80321134
	lwz      r3, sys@sda21(r13)
	lfs      f0, 0x54(r3)
	fsubs    f0, f1, f0
	stfs     f0, 0x144(r29)

lbl_80321134:
	lwz      r0, 0x28(r30)
	cmpwi    r0, 0
	bne      lbl_8032114C
	li       r0, 1
	stw      r0, 0x28(r30)
	b        lbl_8032123C

lbl_8032114C:
	lwz      r3, 0x48(r29)
	lwz      r3, 0x1c(r3)
	rlwinm.  r0, r3, 0, 0x16, 0x16
	beq      lbl_80321218
	lwz      r6, 0x38(r29)
	li       r4, 2
	lwz      r5, 0xb8(r29)
	li       r3, 3
	li       r0, 0
	stw      r5, 8(r6)
	lwz      r5, 0xbc(r29)
	stw      r5, 0xc(r6)
	lwz      r5, 0xc0(r29)
	stw      r5, 0x10(r6)
	lwz      r5, 0xc4(r29)
	stw      r5, 0x14(r6)
	lwz      r5, 0xc8(r29)
	stw      r5, 0x18(r6)
	lwz      r5, 0xcc(r29)
	stw      r5, 0x1c(r6)
	lwz      r5, 0xd0(r29)
	stw      r5, 0x20(r6)
	lwz      r5, 0xd4(r29)
	stw      r5, 0x24(r6)
	lwz      r5, 0xd8(r29)
	stw      r5, 0x28(r6)
	lbz      r5, 0xdc(r29)
	stb      r5, 0x2c(r6)
	lwz      r5, 0xe0(r29)
	stw      r5, 0x30(r6)
	lha      r5, 0xe4(r29)
	sth      r5, 0x34(r6)
	stw      r4, 0x28(r30)
	stw      r3, 0xe8(r29)
	sth      r0, 0x2c(r30)
	stw      r0, 0x20(r30)
	lwz      r0, 0(r30)
	cmpwi    r0, 3
	beq      lbl_803211F0
	cmpwi    r0, 4
	bne      lbl_80321208

lbl_803211F0:
	lbz      r0, 0x24(r30)
	cmplwi   r0, 0
	beq      lbl_80321208
	lwz      r3, ogSound__2og@sda21(r13)
	bl       setCancel__Q22og5SoundFv
	b        lbl_80321210

lbl_80321208:
	lwz      r3, ogSound__2og@sda21(r13)
	bl       setClose__Q22og5SoundFv

lbl_80321210:
	li       r31, 1
	b        lbl_8032123C

lbl_80321218:
	rlwinm.  r0, r3, 0, 0x17, 0x17
	beq      lbl_8032123C
	li       r3, 2
	li       r0, 4
	stw      r3, 0x28(r30)
	stw      r0, 0xe8(r29)
	lwz      r3, ogSound__2og@sda21(r13)
	bl       setDecide__Q22og5SoundFv
	li       r31, 1

lbl_8032123C:
	lwz      r0, 0x28(r30)
	cmpwi    r0, 1
	bne      lbl_803213A0
	lwz      r4, 0x48(r29)
	lis      r3, 0x08000008@ha
	addi     r0, r3, 0x08000008@l
	lwz      r4, 0x18(r4)
	and.     r0, r4, r0
	beq      lbl_803212F4
	lwz      r0, 0xac(r29)
	cmpwi    r0, 1
	beq      lbl_803212A8
	bge      lbl_8032127C
	cmpwi    r0, 0
	bge      lbl_80321288
	b        lbl_803212E8

lbl_8032127C:
	cmpwi    r0, 3
	bge      lbl_803212E8
	b        lbl_803212D8

lbl_80321288:
	li       r0, 1
	mr       r3, r29
	stw      r0, 0xac(r29)
	li       r4, 0
	bl       putinPiki__Q32og9newScreen10ObjContenaFb
	lfs      f0, 0xb0(r29)
	stfs     f0, 0xb4(r29)
	b        lbl_803213A0

lbl_803212A8:
	lwz      r3, sys@sda21(r13)
	lfs      f2, 0xb4(r29)
	lfs      f1, 0x54(r3)
	lfs      f0, lbl_8051DC8C@sda21(r2)
	fsubs    f1, f2, f1
	stfs     f1, 0xb4(r29)
	lfs      f1, 0xb4(r29)
	fcmpo    cr0, f1, f0
	bge      lbl_803213A0
	li       r0, 2
	stw      r0, 0xac(r29)
	b        lbl_803213A0

lbl_803212D8:
	mr       r3, r29
	li       r4, 1
	bl       putinPiki__Q32og9newScreen10ObjContenaFb
	b        lbl_803213A0

lbl_803212E8:
	li       r0, 0
	stw      r0, 0xac(r29)
	b        lbl_803213A0

lbl_803212F4:
	lis      r3, 0x04000004@ha
	addi     r0, r3, 0x04000004@l
	and.     r0, r4, r0
	beq      lbl_80321398
	lwz      r0, 0xac(r29)
	cmpwi    r0, 3
	beq      lbl_8032134C
	bge      lbl_80321320
	cmpwi    r0, 0
	beq      lbl_8032132C
	b        lbl_8032138C

lbl_80321320:
	cmpwi    r0, 5
	bge      lbl_8032138C
	b        lbl_8032137C

lbl_8032132C:
	li       r0, 3
	mr       r3, r29
	stw      r0, 0xac(r29)
	li       r4, 0
	bl       takeoutPiki__Q32og9newScreen10ObjContenaFb
	lfs      f0, 0xb0(r29)
	stfs     f0, 0xb4(r29)
	b        lbl_803213A0

lbl_8032134C:
	lwz      r3, sys@sda21(r13)
	lfs      f2, 0xb4(r29)
	lfs      f1, 0x54(r3)
	lfs      f0, lbl_8051DC8C@sda21(r2)
	fsubs    f1, f2, f1
	stfs     f1, 0xb4(r29)
	lfs      f1, 0xb4(r29)
	fcmpo    cr0, f1, f0
	bge      lbl_803213A0
	li       r0, 4
	stw      r0, 0xac(r29)
	b        lbl_803213A0

lbl_8032137C:
	mr       r3, r29
	li       r4, 1
	bl       takeoutPiki__Q32og9newScreen10ObjContenaFb
	b        lbl_803213A0

lbl_8032138C:
	li       r0, 0
	stw      r0, 0xac(r29)
	b        lbl_803213A0

lbl_80321398:
	li       r0, 0
	stw      r0, 0xac(r29)

lbl_803213A0:
	lwz      r0, 0x24(r1)
	mr       r3, r31
	lwz      r31, 0x1c(r1)
	lwz      r30, 0x18(r1)
	lwz      r29, 0x14(r1)
	lwz      r28, 0x10(r1)
	mtlr     r0
	addi     r1, r1, 0x20
	blr
	*/
}

/*
 * --INFO--
 * Address:	803213C4
 * Size:	0005FC
 */
void ObjContena::commonUpdate(void)
{
	if (m_contena) {
		for (int i = 0; i < 10; i++) {
			if (m_animList[i])
				m_animList[i]->update();
		}
		for (int i = 0; i < 6; i++) {
			u8 alpha = m_alphaMgr[i]->calc();
			m_paneList[i]->setAlpha(alpha);
		}
		f32 scale1 = m_scaleMgr3->calc();
		f32 scale2 = m_scaleMgr4->calc();
		m_paneOnyonL->updateScale(scale1);
		m_paneTiretul->updateScale(scale2);

		if (!contenaAngleFlag) {
			contenaAngleFlag = true;
			contenaAngle     = 0.0f;
		}
		contenaAngle += msVal._24;
		if (contenaAngle > TAU) {
			contenaAngle -= TAU;
		}
		f32 angle     = pikmin2_cosf(contenaAngle) * msVal._28;
		J2DPane* pane = m_paneArrowUp;
		pane->_0D4.x  = m_paneArrowUpPos.x;
		pane->_0D4.y  = -1.0f + m_paneArrowUpPos.y + angle;
		pane->calcMtx();

		pane         = m_paneArrowDown;
		pane->_0D4.x = m_paneArrowDownPos.x;
		pane->_0D4.y = 1.0f + m_paneArrowDownPos.y - angle;
		pane->calcMtx();

		u8 alpha = m_alphaArrow1->calc();
		m_paneArrowUp->setAlpha(alpha);
		alpha = m_alphaArrow2->calc();
		m_paneArrowDown->setAlpha(alpha);

		f32 scale3 = m_scaleArrow1->calc();
		scale3     = msVal._34 * (scale3 - 1.0f) + 1.0f;
		f32 scale4 = m_scaleArrow2->calc();
		scale4     = msVal._34 * (scale4 - 1.0f) + 1.0f;
		m_paneArrowUp->updateScale(scale3);
		m_paneArrowDown->updateScale(scale4);
	}

	if (msVal._40) {
		f32 input1 = m_controller->m_padSStick.m_xPos;
		f32 input2 = m_controller->m_padSStick.m_yPos;
		if (input1 > 0.4f || input1 < -0.4f) {
			m_menuMoveAngle += input1 * 100.0f;
		}
		if (input2 > 0.4f || input2 < -0.4f) {
			m_yAnalog += input1 * -100.0f;
		}
		if (m_furiko) {
			m_furiko->setParam(msVal._14, msVal._1C, msVal._18);
		}
	}

	for (int i = 0; i < m_pikiPaneNum; i++) {
		if (i + 1 > m_disp->m_inSquadCount) {
			m_pikiPaneList[i]->hide();
		} else {
			m_pikiPaneList[i]->show();
		}
	}
	m_doDraw = true;
	m_contena->setXY(m_menuMoveAngle, m_yAnalog);
	m_screenCupsule->calcMtx();

	m_timer += sys->m_deltaTime;
	f32 time = m_timer;
	if (m_timer > TAU) {
		time = 0.0f;
	}
	m_paneSpot->setOffset(msVal._00 * 2.0f * pikmin2_cosf(time), m_spotX + msVal._04, msVal._00 * pikmin2_sinf(time), m_spotY);
	m_paneSpot->setAlpha(m_screenAngle * 255.0f * msVal._10);
	m_paneSpot->updateScale(msVal._0C * ((1.0f - m_screenAngle) * 2.0f + 1.0f) * _104);
	m_screenSpot->update();
	/*
	stwu     r1, -0x60(r1)
	mflr     r0
	stw      r0, 0x64(r1)
	stfd     f31, 0x50(r1)
	psq_st   f31, 88(r1), 0, qr0
	stfd     f30, 0x40(r1)
	psq_st   f30, 72(r1), 0, qr0
	stw      r31, 0x3c(r1)
	stw      r30, 0x38(r1)
	stw      r29, 0x34(r1)
	mr       r31, r3
	lwz      r0, 0x3c(r3)
	cmplwi   r0, 0
	beq      lbl_803216B4
	li       r29, 0
	mr       r30, r31

lbl_80321404:
	lwz      r3, 0x4c(r30)
	cmplwi   r3, 0
	beq      lbl_80321414
	bl       update__Q32og6Screen12AnimBaseBaseFv

lbl_80321414:
	addi     r29, r29, 1
	addi     r30, r30, 4
	cmpwi    r29, 0xa
	blt      lbl_80321404
	li       r29, 0
	mr       r30, r31

lbl_8032142C:
	lwz      r3, 0x74(r30)
	bl       calc__Q32og6Screen8AlphaMgrFv
	mr       r4, r3
	lwz      r3, 0x8c(r30)
	lwz      r12, 0(r3)
	lwz      r12, 0x24(r12)
	mtctr    r12
	bctrl
	addi     r29, r29, 1
	addi     r30, r30, 4
	cmpwi    r29, 6
	blt      lbl_8032142C
	lwz      r3, 0x15c(r31)
	bl       calc__Q32og6Screen8ScaleMgrFv
	fmr      f30, f1
	lwz      r3, 0x168(r31)
	bl       calc__Q32og6Screen8ScaleMgrFv
	lwz      r3, 0x158(r31)
	fmr      f31, f1
	stfs     f30, 0xcc(r3)
	stfs     f30, 0xd0(r3)
	lwz      r12, 0(r3)
	lwz      r12, 0x2c(r12)
	mtctr    r12
	bctrl
	lwz      r3, 0x164(r31)
	stfs     f31, 0xcc(r3)
	stfs     f31, 0xd0(r3)
	lwz      r12, 0(r3)
	lwz      r12, 0x2c(r12)
	mtctr    r12
	bctrl
	lbz      r0, init$4148@sda21(r13)
	extsb.   r0, r0
	bne      lbl_803214C8
	lfs      f0, lbl_8051DC8C@sda21(r2)
	li       r0, 1
	stb      r0, init$4148@sda21(r13)
	stfs     f0, angle$4147@sda21(r13)

lbl_803214C8:
	lis      r3, msVal__Q32og9newScreen10ObjContena@ha
	lfs      f2, angle$4147@sda21(r13)
	addi     r3, r3, msVal__Q32og9newScreen10ObjContena@l
	lfs      f0, lbl_8051DCB0@sda21(r2)
	lfs      f1, 0x24(r3)
	fadds    f1, f2, f1
	fcmpo    cr0, f1, f0
	stfs     f1, angle$4147@sda21(r13)
	ble      lbl_803214F4
	fsubs    f0, f1, f0
	stfs     f0, angle$4147@sda21(r13)

lbl_803214F4:
	lfs      f2, angle$4147@sda21(r13)
	lis      r3, msVal__Q32og9newScreen10ObjContena@ha
	lfs      f0, lbl_8051DC8C@sda21(r2)
	addi     r3, r3, msVal__Q32og9newScreen10ObjContena@l
	lfs      f1, 0x28(r3)
	fcmpo    cr0, f2, f0
	bge      lbl_8032153C
	lfs      f0, lbl_8051DCB4@sda21(r2)
	lis      r3, sincosTable___5JMath@ha
	addi     r3, r3, sincosTable___5JMath@l
	fmuls    f0, f2, f0
	fctiwz   f0, f0
	stfd     f0, 8(r1)
	lwz      r0, 0xc(r1)
	rlwinm   r0, r0, 3, 0x12, 0x1c
	lfsx     f0, r3, r0
	fneg     f0, f0
	b        lbl_80321560

lbl_8032153C:
	lfs      f0, lbl_8051DCB8@sda21(r2)
	lis      r3, sincosTable___5JMath@ha
	addi     r3, r3, sincosTable___5JMath@l
	fmuls    f0, f2, f0
	fctiwz   f0, f0
	stfd     f0, 0x10(r1)
	lwz      r0, 0x14(r1)
	rlwinm   r0, r0, 3, 0x12, 0x1c
	lfsx     f0, r3, r0

lbl_80321560:
	fmuls    f30, f1, f0
	lfs      f1, 0x134(r31)
	lis      r4, msVal__Q32og9newScreen10ObjContena@ha
	lwz      r3, 0x128(r31)
	addi     r4, r4, msVal__Q32og9newScreen10ObjContena@l
	lfs      f0, 0x130(r31)
	lfs      f2, 0x2c(r4)
	fadds    f1, f1, f30
	stfs     f0, 0xd4(r3)
	fadds    f0, f2, f1
	stfs     f0, 0xd8(r3)
	lwz      r12, 0(r3)
	lwz      r12, 0x2c(r12)
	mtctr    r12
	bctrl
	lfs      f0, 0x13c(r31)
	lis      r3, msVal__Q32og9newScreen10ObjContena@ha
	addi     r4, r3, msVal__Q32og9newScreen10ObjContena@l
	lwz      r3, 0x12c(r31)
	fsubs    f1, f0, f30
	lfs      f2, 0x30(r4)
	lfs      f0, 0x138(r31)
	fadds    f1, f2, f1
	stfs     f0, 0xd4(r3)
	stfs     f1, 0xd8(r3)
	lwz      r12, 0(r3)
	lwz      r12, 0x2c(r12)
	mtctr    r12
	bctrl
	lwz      r3, 0x118(r31)
	bl       calc__Q32og6Screen8AlphaMgrFv
	lbz      r0, 0x148(r31)
	clrlwi   r5, r3, 0x18
	lis      r4, 0x80808081@ha
	lwz      r3, 0x128(r31)
	mullw    r0, r0, r5
	addi     r4, r4, 0x80808081@l
	lwz      r12, 0(r3)
	lwz      r12, 0x24(r12)
	mulhwu   r0, r4, r0
	rlwinm   r4, r0, 0x19, 0x18, 0x1f
	mtctr    r12
	bctrl
	lwz      r3, 0x11c(r31)
	bl       calc__Q32og6Screen8AlphaMgrFv
	lbz      r0, 0x148(r31)
	clrlwi   r5, r3, 0x18
	lis      r4, 0x80808081@ha
	lwz      r3, 0x12c(r31)
	mullw    r0, r0, r5
	addi     r4, r4, 0x80808081@l
	lwz      r12, 0(r3)
	lwz      r12, 0x24(r12)
	mulhwu   r0, r4, r0
	rlwinm   r4, r0, 0x19, 0x18, 0x1f
	mtctr    r12
	bctrl
	lwz      r3, 0x120(r31)
	bl       calc__Q32og6Screen8ScaleMgrFv
	lfs      f2, lbl_8051DC94@sda21(r2)
	lis      r3, msVal__Q32og9newScreen10ObjContena@ha
	addi     r30, r3, msVal__Q32og9newScreen10ObjContena@l
	lwz      r3, 0x124(r31)
	fsubs    f1, f1, f2
	lfs      f0, 0x34(r30)
	fmadds   f30, f0, f1, f2
	bl       calc__Q32og6Screen8ScaleMgrFv
	lwz      r3, 0x128(r31)
	lfs      f0, 0x34(r30)
	lfs      f2, lbl_8051DC94@sda21(r2)
	stfs     f30, 0xcc(r3)
	fsubs    f1, f1, f2
	stfs     f30, 0xd0(r3)
	lwz      r12, 0(r3)
	fmadds   f30, f0, f1, f2
	lwz      r12, 0x2c(r12)
	mtctr    r12
	bctrl
	lwz      r3, 0x12c(r31)
	stfs     f30, 0xcc(r3)
	stfs     f30, 0xd0(r3)
	lwz      r12, 0(r3)
	lwz      r12, 0x2c(r12)
	mtctr    r12
	bctrl

lbl_803216B4:
	lis      r3, msVal__Q32og9newScreen10ObjContena@ha
	addi     r3, r3, msVal__Q32og9newScreen10ObjContena@l
	lbz      r0, 0x40(r3)
	cmplwi   r0, 0
	beq      lbl_80321748
	lwz      r3, 0x48(r31)
	lfs      f0, lbl_8051DCBC@sda21(r2)
	lfs      f2, 0x58(r3)
	lfs      f3, 0x5c(r3)
	fcmpo    cr0, f2, f0
	bgt      lbl_803216EC
	lfs      f0, lbl_8051DCC0@sda21(r2)
	fcmpo    cr0, f2, f0
	bge      lbl_803216FC

lbl_803216EC:
	lfs      f1, lbl_8051DCC4@sda21(r2)
	lfs      f0, 0xf0(r31)
	fmadds   f0, f1, f2, f0
	stfs     f0, 0xf0(r31)

lbl_803216FC:
	lfs      f0, lbl_8051DCBC@sda21(r2)
	fcmpo    cr0, f3, f0
	bgt      lbl_80321714
	lfs      f0, lbl_8051DCC0@sda21(r2)
	fcmpo    cr0, f3, f0
	bge      lbl_80321724

lbl_80321714:
	lfs      f1, lbl_8051DCC8@sda21(r2)
	lfs      f0, 0xf4(r31)
	fmadds   f0, f1, f3, f0
	stfs     f0, 0xf4(r31)

lbl_80321724:
	lwz      r3, 0xec(r31)
	cmplwi   r3, 0
	beq      lbl_80321748
	lis      r4, msVal__Q32og9newScreen10ObjContena@ha
	addi     r4, r4, msVal__Q32og9newScreen10ObjContena@l
	lfs      f1, 0x14(r4)
	lfs      f2, 0x1c(r4)
	lfs      f3, 0x18(r4)
	bl       setParam__Q32og6Screen15CallBack_FurikoFfff

lbl_80321748:
	li       r7, 0
	li       r5, 1
	mr       r8, r7
	mr       r4, r7
	b        lbl_80321794

lbl_8032175C:
	lwz      r3, 0x38(r31)
	addi     r6, r7, 1
	lwz      r0, 0x14(r3)
	cmplw    r6, r0
	bgt      lbl_80321780
	lwz      r3, 0x14c(r31)
	lwzx     r3, r3, r8
	stb      r5, 0xb0(r3)
	b        lbl_8032178C

lbl_80321780:
	lwz      r3, 0x14c(r31)
	lwzx     r3, r3, r8
	stb      r4, 0xb0(r3)

lbl_8032178C:
	addi     r8, r8, 4
	addi     r7, r7, 1

lbl_80321794:
	lwz      r0, 0x150(r31)
	cmpw     r7, r0
	blt      lbl_8032175C
	li       r0, 1
	lfs      f1, mstTuningTransX__Q29P2DScreen10Mgr_tuning@sda21(r2)
	stb      r0, 0x10c(r31)
	lfs      f0, mstTuningTransY__Q29P2DScreen10Mgr_tuning@sda21(r2)
	lfs      f2, 0xf0(r31)
	lfs      f3, 0xf4(r31)
	fadds    f1, f2, f1
	lwz      r3, 0x3c(r31)
	fadds    f0, f3, f0
	stfs     f1, 0x140(r3)
	stfs     f0, 0x144(r3)
	lwz      r3, 0x3c(r31)
	lwz      r12, 0(r3)
	lwz      r12, 0x30(r12)
	mtctr    r12
	bctrl
	lwz      r3, 0x44(r31)
	lwz      r12, 0(r3)
	lwz      r12, 0x30(r12)
	mtctr    r12
	bctrl
	lis      r3, msVal__Q32og9newScreen10ObjContena@ha
	lfs      f2, 0x108(r31)
	addi     r3, r3, msVal__Q32og9newScreen10ObjContena@l
	lfs      f0, lbl_8051DCB0@sda21(r2)
	lfs      f1, 8(r3)
	fadds    f1, f2, f1
	stfs     f1, 0x108(r31)
	lfs      f1, 0x108(r31)
	fcmpo    cr0, f1, f0
	cror     2, 1, 2
	bne      lbl_80321828
	lfs      f0, lbl_8051DC8C@sda21(r2)
	stfs     f0, 0x108(r31)

lbl_80321828:
	lfs      f6, 0x108(r31)
	lfs      f0, lbl_8051DC8C@sda21(r2)
	fmr      f1, f6
	fcmpo    cr0, f6, f0
	bge      lbl_80321840
	fneg     f1, f6

lbl_80321840:
	lfs      f4, lbl_8051DCB8@sda21(r2)
	lis      r3, msVal__Q32og9newScreen10ObjContena@ha
	addi     r4, r3, msVal__Q32og9newScreen10ObjContena@l
	lfs      f5, lbl_8051DCCC@sda21(r2)
	fmuls    f0, f1, f4
	lfs      f7, 0(r4)
	fmuls    f6, f5, f6
	lis      r3, sincosTable___5JMath@ha
	lfs      f1, 4(r4)
	addi     r4, r3, sincosTable___5JMath@l
	fctiwz   f3, f0
	lfs      f2, 0xfc(r31)
	lfs      f0, lbl_8051DC8C@sda21(r2)
	fmuls    f5, f5, f7
	fadds    f1, f2, f1
	stfd     f3, 0x10(r1)
	fcmpo    cr0, f6, f0
	lwz      r0, 0x14(r1)
	rlwinm   r0, r0, 3, 0x12, 0x1c
	add      r3, r4, r0
	lfs      f0, 4(r3)
	fmadds   f2, f5, f0, f1
	bge      lbl_803218C0
	lfs      f0, lbl_8051DCB4@sda21(r2)
	fmuls    f0, f6, f0
	fctiwz   f0, f0
	stfd     f0, 8(r1)
	lwz      r0, 0xc(r1)
	rlwinm   r0, r0, 3, 0x12, 0x1c
	lfsx     f0, r4, r0
	fneg     f1, f0
	b        lbl_803218D8

lbl_803218C0:
	fmuls    f0, f6, f4
	fctiwz   f0, f0
	stfd     f0, 0x18(r1)
	lwz      r0, 0x1c(r1)
	rlwinm   r0, r0, 3, 0x12, 0x1c
	lfsx     f1, r4, r0

lbl_803218D8:
	lfs      f0, 0x100(r31)
	lwz      r3, 0xf8(r31)
	fmadds   f0, f7, f1, f0
	stfs     f2, 0xd4(r3)
	stfs     f0, 0xd8(r3)
	lwz      r12, 0(r3)
	lwz      r12, 0x2c(r12)
	mtctr    r12
	bctrl
	lfs      f1, lbl_8051DCD0@sda21(r2)
	lis      r3, msVal__Q32og9newScreen10ObjContena@ha
	lfs      f0, 0xa8(r31)
	addi     r4, r3, msVal__Q32og9newScreen10ObjContena@l
	lwz      r3, 0xf8(r31)
	fmuls    f1, f1, f0
	lfs      f0, 0x10(r4)
	lwz      r12, 0(r3)
	fmuls    f0, f1, f0
	lwz      r12, 0x24(r12)
	fctiwz   f0, f0
	stfd     f0, 0x20(r1)
	lwz      r4, 0x24(r1)
	mtctr    r12
	bctrl
	lfs      f2, lbl_8051DC94@sda21(r2)
	lis      r3, msVal__Q32og9newScreen10ObjContena@ha
	lfs      f0, 0xa8(r31)
	addi     r4, r3, msVal__Q32og9newScreen10ObjContena@l
	lfs      f3, lbl_8051DCCC@sda21(r2)
	fsubs    f1, f2, f0
	lfs      f0, 0x104(r31)
	lfs      f4, 0xc(r4)
	lwz      r3, 0xf8(r31)
	fmadds   f1, f3, f1, f2
	fmuls    f0, f1, f0
	fmuls    f0, f4, f0
	stfs     f0, 0xcc(r3)
	stfs     f0, 0xd0(r3)
	lwz      r12, 0(r3)
	lwz      r12, 0x2c(r12)
	mtctr    r12
	bctrl
	lwz      r3, 0x40(r31)
	lwz      r12, 0(r3)
	lwz      r12, 0x30(r12)
	mtctr    r12
	bctrl
	psq_l    f31, 88(r1), 0, qr0
	lfd      f31, 0x50(r1)
	psq_l    f30, 72(r1), 0, qr0
	lfd      f30, 0x40(r1)
	lwz      r31, 0x3c(r1)
	lwz      r30, 0x38(r1)
	lwz      r0, 0x64(r1)
	lwz      r29, 0x34(r1)
	mtlr     r0
	addi     r1, r1, 0x60
	blr
	*/
}

/*
 * --INFO--
 * Address:	803219C0
 * Size:	000040
 */
bool ObjContena::doUpdate(void)
{
	bool ret = moveContena();
	commonUpdate();
	return ret;
	/*
	stwu     r1, -0x10(r1)
	mflr     r0
	stw      r0, 0x14(r1)
	stw      r31, 0xc(r1)
	mr       r31, r3
	bl       moveContena__Q32og9newScreen10ObjContenaFv
	mr       r0, r3
	mr       r3, r31
	mr       r31, r0
	bl       commonUpdate__Q32og9newScreen10ObjContenaFv
	lwz      r0, 0x14(r1)
	mr       r3, r31
	lwz      r31, 0xc(r1)
	mtlr     r0
	addi     r1, r1, 0x10
	blr
	*/
}

/*
 * --INFO--
 * Address:	80321A00
 * Size:	000174
 */
void ObjContena::doDraw(Graphics& gfx)
{
	J2DPerspGraph* graf = &gfx.m_perspGraph;
	graf->setPort();
	if (m_doDraw) {
		m_contena->draw(gfx, *graf);

		J2DPane* pane1 = m_contena->search('Pscon');
		J2DPane* pane2 = m_screenCupsule->search('Pscon');
		PSMTXCopy(pane1->_080, pane2->_050);

		pane1 = m_contena->search('Pscon01');
		pane2 = m_screenCupsule->search('Pscon01');
		PSMTXCopy(pane1->_080, pane2->_050);
		m_screenCupsule->draw(gfx, *graf);
	}
	GXSetClipMode(0);
	m_screenSpot->draw(gfx, *graf);
	/*
	stwu     r1, -0x20(r1)
	mflr     r0
	stw      r0, 0x24(r1)
	stw      r31, 0x1c(r1)
	stw      r30, 0x18(r1)
	stw      r29, 0x14(r1)
	mr       r29, r4
	addi     r30, r29, 0x190
	stw      r28, 0x10(r1)
	mr       r28, r3
	mr       r3, r30
	lwz      r12, 0(r30)
	lwz      r12, 0x14(r12)
	mtctr    r12
	bctrl
	lbz      r0, 0x10c(r28)
	cmplwi   r0, 0
	beq      lbl_80321B30
	lwz      r3, 0x3c(r28)
	mr       r4, r29
	mr       r5, r30
	lwz      r12, 0(r3)
	lwz      r12, 0x9c(r12)
	mtctr    r12
	bctrl
	lwz      r3, 0x3c(r28)
	lis      r4, 0x73636F6E@ha
	addi     r6, r4, 0x73636F6E@l
	li       r5, 0x50
	lwz      r12, 0(r3)
	lwz      r12, 0x3c(r12)
	mtctr    r12
	bctrl
	mr       r31, r3
	lwz      r3, 0x44(r28)
	lis      r4, 0x73636F6E@ha
	li       r5, 0x50
	lwz      r12, 0(r3)
	addi     r6, r4, 0x73636F6E@l
	lwz      r12, 0x3c(r12)
	mtctr    r12
	bctrl
	mr       r4, r3
	addi     r3, r31, 0x80
	addi     r4, r4, 0x50
	bl       PSMTXCopy
	lwz      r3, 0x3c(r28)
	lis      r5, 0x6F6E3031@ha
	lis      r4, 0x00507363@ha
	lwz      r12, 0(r3)
	addi     r6, r5, 0x6F6E3031@l
	addi     r5, r4, 0x00507363@l
	lwz      r12, 0x3c(r12)
	mtctr    r12
	bctrl
	mr       r31, r3
	lwz      r3, 0x44(r28)
	lis      r5, 0x6F6E3031@ha
	lis      r4, 0x00507363@ha
	lwz      r12, 0(r3)
	addi     r6, r5, 0x6F6E3031@l
	addi     r5, r4, 0x00507363@l
	lwz      r12, 0x3c(r12)
	mtctr    r12
	bctrl
	mr       r4, r3
	addi     r3, r31, 0x80
	addi     r4, r4, 0x50
	bl       PSMTXCopy
	lwz      r3, 0x44(r28)
	mr       r4, r29
	mr       r5, r30
	lwz      r12, 0(r3)
	lwz      r12, 0x9c(r12)
	mtctr    r12
	bctrl

lbl_80321B30:
	li       r3, 0
	bl       GXSetClipMode
	lwz      r3, 0x40(r28)
	mr       r4, r29
	mr       r5, r30
	lwz      r12, 0(r3)
	lwz      r12, 0x9c(r12)
	mtctr    r12
	bctrl
	lwz      r0, 0x24(r1)
	lwz      r31, 0x1c(r1)
	lwz      r30, 0x18(r1)
	lwz      r29, 0x14(r1)
	lwz      r28, 0x10(r1)
	mtlr     r0
	addi     r1, r1, 0x20
	blr
	*/
}

/*
 * --INFO--
 * Address:	80321B74
 * Size:	000044
 */
bool ObjContena::doStart(::Screen::StartSceneArg const*)
{
	m_fadeLevel     = 0.0f;
	m_menuMoveAngle = 800.0f;
	m_yAnalog       = 0.0f;
	m_doDraw        = false;
	ogSound->setOpen();
	return true;
	/*
	stwu     r1, -0x10(r1)
	mflr     r0
	lfs      f1, lbl_8051DC8C@sda21(r2)
	stw      r0, 0x14(r1)
	li       r0, 0
	lfs      f0, lbl_8051DC88@sda21(r2)
	stfs     f1, 0x110(r3)
	stfs     f0, 0xf0(r3)
	stfs     f1, 0xf4(r3)
	stb      r0, 0x10c(r3)
	lwz      r3, ogSound__2og@sda21(r13)
	bl       setOpen__Q22og5SoundFv
	lwz      r0, 0x14(r1)
	li       r3, 1
	mtlr     r0
	addi     r1, r1, 0x10
	blr
	*/
}

/*
 * --INFO--
 * Address:	80321BB8
 * Size:	000008
 */
bool ObjContena::doEnd(::Screen::EndSceneArg const*) { return true; }

/*
 * --INFO--
 * Address:	80321BC0
 * Size:	000004
 */
void ObjContena::doUpdateFadeinFinish(void) { }

/*
 * --INFO--
 * Address:	80321BC4
 * Size:	00000C
 */
void ObjContena::doUpdateFinish(void)
{
	m_fadeLevel = 0.0f;
	/*
	lfs      f0, lbl_8051DC8C@sda21(r2)
	stfs     f0, 0x110(r3)
	blr
	*/
}

/*
 * --INFO--
 * Address:	80321BD0
 * Size:	000004
 */
void ObjContena::doUpdateFadeoutFinish(void) { }

/*
 * --INFO--
 * Address:	80321BD4
 * Size:	0000A8
 */
bool ObjContena::doUpdateFadein(void)
{
	bool check = false;
	commonUpdate();
	m_fadeLevel += sys->m_deltaTime;
	m_screenAngle   = m_fadeLevel / msVal._20;
	f32 calc        = og::Screen::calcSmooth0to1(m_fadeLevel, msVal._20);
	m_menuMoveAngle = 800.0f * (1.0f - calc);

	if (m_fadeLevel >= msVal._20)
		check = true;
	return check;
	/*
	stwu     r1, -0x20(r1)
	mflr     r0
	stw      r0, 0x24(r1)
	stw      r31, 0x1c(r1)
	stw      r30, 0x18(r1)
	li       r30, 0
	stw      r29, 0x14(r1)
	mr       r29, r3
	bl       commonUpdate__Q32og9newScreen10ObjContenaFv
	lwz      r4, sys@sda21(r13)
	lis      r3, msVal__Q32og9newScreen10ObjContena@ha
	lfs      f1, 0x110(r29)
	addi     r31, r3, msVal__Q32og9newScreen10ObjContena@l
	lfs      f0, 0x54(r4)
	fadds    f0, f1, f0
	stfs     f0, 0x110(r29)
	lfs      f1, 0x110(r29)
	lfs      f0, 0x20(r31)
	fdivs    f0, f1, f0
	stfs     f0, 0xa8(r29)
	lfs      f1, 0x110(r29)
	lfs      f2, 0x20(r31)
	bl       calcSmooth0to1__Q22og6ScreenFff
	lfs      f2, lbl_8051DC94@sda21(r2)
	lfs      f0, lbl_8051DC88@sda21(r2)
	fsubs    f1, f2, f1
	fmuls    f0, f0, f1
	stfs     f0, 0xf0(r29)
	lfs      f1, 0x110(r29)
	lfs      f0, 0x20(r31)
	fcmpo    cr0, f1, f0
	cror     2, 1, 2
	bne      lbl_80321C5C
	li       r30, 1

lbl_80321C5C:
	lwz      r0, 0x24(r1)
	mr       r3, r30
	lwz      r31, 0x1c(r1)
	lwz      r30, 0x18(r1)
	lwz      r29, 0x14(r1)
	mtlr     r0
	addi     r1, r1, 0x20
	blr
	*/
}

/*
 * --INFO--
 * Address:	80321C7C
 * Size:	0001DC
 */
bool ObjContena::doUpdateFadeout(void)
{
	bool check = false;
	commonUpdate();
	m_fadeLevel += sys->m_deltaTime;
	m_screenAngle   = 1.0f - m_fadeLevel / msVal._20;
	f32 calc        = og::Screen::calcSmooth0to1(m_fadeLevel, msVal._20);
	m_menuMoveAngle = -800.0f * calc;
	if (m_fadeLevel >= msVal._20) {
		check                               = true;
		::Screen::SceneBase* scene          = getOwner();
		og::Screen::DispMemberContena* disp = m_disp;
		disp->_30                           = m_dispState;
		if (disp->_30 == 3 && disp->_2C) {
			if (disp->m_onyonID == 4 || disp->m_onyonID == 3) {
				::Screen::SetSceneArg arg(SCENE_UFO_MENU, getDispMember(), false, false);
				if (scene->setScene(arg) && !scene->startScene(nullptr)) {
					JUT_PANICLINE(944, "���߂ł�\n");
				}
			}
		}
		if (!scene->setBackupScene()) {
			JUT_PANICLINE(958, "setBackupScene ERR!");
		} else if (!scene->startScene(nullptr)) {
			JUT_PANICLINE(953, "START ERR! (BackupScene)");
		}
	}
	commonUpdate();
	return check;
	/*
	stwu     r1, -0x30(r1)
	mflr     r0
	lfs      f2, lbl_8051DC94@sda21(r2)
	lis      r5, lbl_8048EFE0@ha
	stw      r0, 0x34(r1)
	stw      r31, 0x2c(r1)
	addi     r31, r5, lbl_8048EFE0@l
	stw      r30, 0x28(r1)
	li       r30, 0
	stw      r29, 0x24(r1)
	stw      r28, 0x20(r1)
	mr       r28, r3
	lis      r3, msVal__Q32og9newScreen10ObjContena@ha
	lwz      r4, sys@sda21(r13)
	addi     r29, r3, msVal__Q32og9newScreen10ObjContena@l
	lfs      f1, 0x110(r28)
	lfs      f0, 0x54(r4)
	fadds    f0, f1, f0
	stfs     f0, 0x110(r28)
	lfs      f1, 0x110(r28)
	lfs      f0, 0x20(r29)
	fdivs    f0, f1, f0
	fsubs    f0, f2, f0
	stfs     f0, 0xa8(r28)
	lfs      f1, 0x110(r28)
	lfs      f2, 0x20(r29)
	bl       calcSmooth0to1__Q22og6ScreenFff
	lfs      f0, lbl_8051DCD4@sda21(r2)
	fmuls    f0, f0, f1
	stfs     f0, 0xf0(r28)
	lfs      f1, 0x110(r28)
	lfs      f0, 0x20(r29)
	fcmpo    cr0, f1, f0
	cror     2, 1, 2
	bne      lbl_80321E2C
	mr       r3, r28
	li       r30, 1
	lwz      r12, 0(r28)
	lwz      r12, 0x30(r12)
	mtctr    r12
	bctrl
	lwz      r4, 0x38(r28)
	mr       r29, r3
	lwz      r0, 0xe8(r28)
	stw      r0, 0x30(r4)
	lwz      r0, 0x30(r4)
	cmpwi    r0, 3
	bne      lbl_80321DDC
	lbz      r0, 0x2c(r4)
	cmplwi   r0, 0
	beq      lbl_80321DDC
	lwz      r0, 8(r4)
	cmpwi    r0, 4
	beq      lbl_80321D5C
	cmpwi    r0, 3
	bne      lbl_80321DDC

lbl_80321D5C:
	mr       r3, r28
	bl       getDispMember__Q26Screen7ObjBaseFv
	lis      r4, __vt__Q26Screen12SceneArgBase@ha
	li       r0, 1
	addi     r5, r4, __vt__Q26Screen12SceneArgBase@l
	lis      r4, __vt__Q26Screen11SetSceneArg@ha
	stw      r5, 8(r1)
	addi     r7, r4, __vt__Q26Screen11SetSceneArg@l
	li       r6, 0x2719
	li       r5, 0
	stb      r0, 0x11(r1)
	addi     r4, r1, 8
	stw      r3, 0x14(r1)
	mr       r3, r29
	stw      r7, 8(r1)
	stw      r6, 0xc(r1)
	stb      r5, 0x10(r1)
	stb      r5, 0x11(r1)
	bl       setScene__Q26Screen9SceneBaseFRQ26Screen11SetSceneArg
	clrlwi.  r0, r3, 0x18
	beq      lbl_80321E2C
	mr       r3, r29
	li       r4, 0
	bl       startScene__Q26Screen9SceneBaseFPQ26Screen13StartSceneArg
	clrlwi.  r0, r3, 0x18
	bne      lbl_80321E2C
	addi     r3, r31, 0
	addi     r5, r31, 0x10c
	li       r4, 0x3b0
	crclr    6
	bl       panic_f__12JUTExceptionFPCciPCce
	b        lbl_80321E2C

lbl_80321DDC:
	mr       r3, r29
	bl       setBackupScene__Q26Screen9SceneBaseFv
	clrlwi.  r0, r3, 0x18
	beq      lbl_80321E18
	mr       r3, r29
	li       r4, 0
	bl       startScene__Q26Screen9SceneBaseFPQ26Screen13StartSceneArg
	clrlwi.  r0, r3, 0x18
	bne      lbl_80321E2C
	addi     r3, r31, 0
	addi     r5, r31, 0x118
	li       r4, 0x3b9
	crclr    6
	bl       panic_f__12JUTExceptionFPCciPCce
	b        lbl_80321E2C

lbl_80321E18:
	addi     r3, r31, 0
	addi     r5, r31, 0x134
	li       r4, 0x3be
	crclr    6
	bl       panic_f__12JUTExceptionFPCciPCce

lbl_80321E2C:
	mr       r3, r28
	bl       commonUpdate__Q32og9newScreen10ObjContenaFv
	lwz      r0, 0x34(r1)
	mr       r3, r30
	lwz      r31, 0x2c(r1)
	lwz      r30, 0x28(r1)
	lwz      r29, 0x24(r1)
	lwz      r28, 0x20(r1)
	mtlr     r0
	addi     r1, r1, 0x30
	blr
	*/
}

} // namespace newScreen
} // namespace og

/*
 * --INFO--
 * Address:	80321E58
 * Size:	0000A8
 */
void __sinit_ogObjContena_cpp(void)
{
	/*
	stwu     r1, -0x20(r1)
	stfd     f31, 0x10(r1)
	psq_st   f31, 24(r1), 0, qr0
	lfs      f31, lbl_8051DCD8@sda21(r2)
	lis      r3, msVal__Q32og9newScreen10ObjContena@ha
	lfs      f13, lbl_8051DCDC@sda21(r2)
	li       r0, 0
	stfsu    f31, msVal__Q32og9newScreen10ObjContena@l(r3)
	lfs      f12, lbl_8051DCE0@sda21(r2)
	lfs      f11, lbl_8051DCE4@sda21(r2)
	lfs      f10, lbl_8051DCAC@sda21(r2)
	lfs      f9, lbl_8051DCE8@sda21(r2)
	lfs      f8, lbl_8051DCEC@sda21(r2)
	lfs      f7, lbl_8051DCF0@sda21(r2)
	lfs      f6, lbl_8051DC98@sda21(r2)
	lfs      f5, lbl_8051DCF4@sda21(r2)
	lfs      f4, lbl_8051DCF8@sda21(r2)
	lfs      f3, lbl_8051DCFC@sda21(r2)
	lfs      f2, lbl_8051DC94@sda21(r2)
	lfs      f1, lbl_8051DD00@sda21(r2)
	lfs      f0, lbl_8051DD04@sda21(r2)
	stfs     f13, 8(r3)
	stfs     f12, 0xc(r3)
	stfs     f11, 0x10(r3)
	stfs     f10, 4(r3)
	stfs     f9, 0x14(r3)
	stfs     f8, 0x18(r3)
	stfs     f7, 0x1c(r3)
	stb      r0, 0x40(r3)
	stfs     f6, 0x20(r3)
	stw      r0, 0x3c(r3)
	stb      r0, 0x41(r3)
	stfs     f5, 0x24(r3)
	stfs     f4, 0x28(r3)
	stfs     f3, 0x2c(r3)
	stfs     f2, 0x30(r3)
	stfs     f1, 0x34(r3)
	stfs     f0, 0x38(r3)
	psq_l    f31, 24(r1), 0, qr0
	lfd      f31, 0x10(r1)
	addi     r1, r1, 0x20
	blr
	*/
}

/*
 * --INFO--
 * Address:	80321F00
 * Size:	000008
 */
// @24 @og::newScreen::ObjContena::~ObjContena(void)
//{
/*
addi     r3, r3, -24
b        __dt__Q32og9newScreen10ObjContenaFv
*/
// }
