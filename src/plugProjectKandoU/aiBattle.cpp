#include "types.h"

#include "PikiAI.h"
#include "Game/Piki.h"

/*
    Generated from dpostproc

    .section .rodata  # 0x804732E0 - 0x8049E220
    .global lbl_80483890
    lbl_80483890:
        .4byte 0x61694261
        .4byte 0x74746C65
        .4byte 0x00000000
        .4byte 0x41637442
        .4byte 0x6174746C
        .4byte 0x65417267
        .4byte 0x00000000
        .4byte 0x61694261
        .4byte 0x74746C65
        .4byte 0x2E637070
        .4byte 0x00000000
        .asciz "P2Assert"
        .skip 3
        .4byte 0x41637469
        .4byte 0x6F6E4172
        .4byte 0x67000000
        .4byte 0x41707072
        .4byte 0x6F616368
        .4byte 0x506F7341
        .4byte 0x6374696F
        .4byte 0x6E417267
        .4byte 0x00000000
        .4byte 0x00000000

    .section .data, "wa"  # 0x8049E220 - 0x804EFC20
    .global __vt__Q26PikiAI9ActBattle
    __vt__Q26PikiAI9ActBattle:
        .4byte 0
        .4byte 0
        .4byte init__Q26PikiAI9ActBattleFPQ26PikiAI9ActionArg
        .4byte exec__Q26PikiAI9ActBattleFv
        .4byte cleanup__Q26PikiAI9ActBattleFv
        .4byte emotion_success__Q26PikiAI9ActBattleFv
        .4byte emotion_fail__Q26PikiAI6ActionFv
        .4byte applicable__Q26PikiAI6ActionFv
        .4byte getNextAIType__Q26PikiAI6ActionFv
        .4byte bounceCallback__Q26PikiAI6ActionFPQ24Game4PikiPQ23Sys8Triangle
        .4byte
   collisionCallback__Q26PikiAI9ActBattleFPQ24Game4PikiRQ24Game9CollEvent .4byte
   platCallback__Q26PikiAI6ActionFPQ24Game4PikiRQ24Game9PlatEvent .4byte
   doDirectDraw__Q26PikiAI6ActionFR8Graphics .4byte
   "wallCallback__Q26PikiAI6ActionFR10Vector3<f>" .4byte
   getInfo__Q26PikiAI6ActionFPc .4byte
   onKeyEvent__Q26PikiAI9ActBattleFRCQ28SysShape8KeyEvent .4byte 0 .4byte 0
        .4byte "@32@4@onKeyEvent__Q26PikiAI9ActBattleFRCQ28SysShape8KeyEvent"
        .4byte 0

    .section .sdata2, "a"     # 0x80516360 - 0x80520E40
    .global lbl_8051A320
    lbl_8051A320:
        .4byte 0x42617474
        .4byte 0x6C650000
    .global lbl_8051A328
    lbl_8051A328:
        .4byte 0x47000000
    .global lbl_8051A32C
    lbl_8051A32C:
        .float 0.5
    .global lbl_8051A330
    lbl_8051A330:
        .4byte 0x3F666666
    .global lbl_8051A334
    lbl_8051A334:
        .4byte 0x42700000
    .global lbl_8051A338
    lbl_8051A338:
        .4byte 0x00000000
    .global lbl_8051A33C
    lbl_8051A33C:
        .4byte 0xC47A0000
    .global lbl_8051A340
    lbl_8051A340:
        .4byte 0x43300000
        .4byte 0x80000000
    .global lbl_8051A348
    lbl_8051A348:
        .4byte 0x41200000
    .global lbl_8051A34C
    lbl_8051A34C:
        .float 1.0
    .global lbl_8051A350
    lbl_8051A350:
        .4byte 0x42480000
    .global lbl_8051A354
    lbl_8051A354:
        .4byte 0x42C80000
    .global lbl_8051A358
    lbl_8051A358:
        .4byte 0x400CCCCD
    .global lbl_8051A35C
    lbl_8051A35C:
        .4byte 0x40200000
    .global lbl_8051A360
    lbl_8051A360:
        .4byte 0xBF800000
        .4byte 0x00000000
*/

#include "PikiAI.h"
#include "Game/EnemyBase.h"
#include "Game/enemyInfo.h"
#include "Game/gameStat.h"
#include "Game/PikiState.h"
#include "Game/Footmark.h"
#include "Dolphin/rand.h"
#include "utilityU.h"

namespace PikiAI {

/*
 * --INFO--
 * Address:	8022ECB4
 * Size:	0000B8
 */
ActBattle::ActBattle(Game::Piki* p)
    : Action(p)
{
	_1C           = 0;
	m_name        = "Battle";
	m_approachPos = new ActApproachPos(p);
}

/*
 * --INFO--
 * Address:	8022ED6C
 * Size:	000044
 */
void ActBattle::emotion_success()
{
	Game::EmotionStateArg arg(1); // will need to create new derived StateArg struct for this eventually
	m_parent->m_fsm->transit(m_parent, 19, &arg);
}

/*
 * --INFO--
 * Address:	8022EDB0
 * Size:	000300
 * TODO
 */
void ActBattle::init(PikiAI::ActionArg* arg)
{
	PikiAI::ActBattleArg* cArg = static_cast<PikiAI::ActBattleArg*>(arg);

	u8 assert = 0;
	if (cArg) {
		char* name = cArg->getName();
		bool st    = strcmp("ActBattleArg", name) == 0;
		if (st) {
			assert = 1;
		}
	}
	P2ASSERTLINE(179, assert);

	m_other = cArg->m_aggressor;

	Game::InteractBattle battle(m_parent);
	m_other->stimulate(battle);
	if (cArg->m_isAttackStart) {
		SET_FLAG(_1C, 2);
	} else if (m_other == m_other->getVsBattlePiki()) {
		SET_FLAG(_1C, 2);
	} else {
		RESET_FLAG(_1C, 2);
	}
	initApproach();
	_1D = 0;

	Vector3f otherPos = m_other->getPosition();
	Vector3f thisPos  = m_parent->getPosition();

	Vector3f midPoint = (otherPos + thisPos) * 0.5f;
	Sys::Sphere itSphere(midPoint, 10.0f);
	Game::CellIteratorArg citArg(itSphere);

	Game::CellIterator cellIt(citArg);
	CI_LOOP(cellIt)
	{
		Game::Creature* c = static_cast<Game::Creature*>(*cellIt);
		Vector3f cPos     = itSphere.m_position - c->getPosition();
		_normalise(cPos);

		cPos.x *= 50.0f;
		cPos.y = 100.0f;
		cPos.z *= 50.0f;
		Game::InteractWind wind(m_parent, 0.0f, &cPos);
		c->stimulate(wind);
	}
}

/*
 * --INFO--
 * Address:	8022F0B0
 * Size:	0000EC
 */
int ActBattle::exec(void)
{
	if (!m_other || !m_other->isAlive() || m_other != m_parent->getVsBattlePiki() || m_parent != m_other->getVsBattlePiki()) {
		return 0;
	}

	if (!(_1C & 2)) {
		return 2;
	}

	PSMGetPikiBattleD()->_54++;

	switch (m_state) {
	case PIKIAI_ACTBATTLE_APPROACH:
		execApproach();
		break;
	case PIKIAI_ACTBATTLE_BATTLE:
		execBattle();
		break;
	case PIKIAI_ACTBATTLE_DAMAGE:
		execDamage();
		break;
	}

	return 1;
}

/*
 * --INFO--
 * Address:	8022F19C
 * Size:	00000C
 */
void ActBattle::cleanup() { m_other = nullptr; }

/*
 * --INFO--
 * Address:	8022F1A8
 * Size:	000004
 */
void ActBattle::collisionCallback(Game::Piki*, Game::CollEvent&) { }

/*
 * --INFO--
 * Address:	8022F1AC
 * Size:	000484
 */
void ActBattle::onKeyEvent(SysShape::KeyEvent const& event)
{
	switch (m_state) {
	case PIKIAI_ACTBATTLE_BATTLE: {
		switch (event.m_type) {
		case KEYEVENT_END:
			initApproach();

			u8 old = ++_1D;
			if (old >= (randFloat() * 2.2f)) {
				// WTF?
			}
			break;
		}
		break;
	}
	default:
		break;
	}

	/*
	.loc_0x0:
	  stwu      r1, -0xB0(r1)
	  mflr      r0
	  stw       r0, 0xB4(r1)
	  stfd      f31, 0xA0(r1)
	  psq_st    f31,0xA8(r1),0,0
	  stfd      f30, 0x90(r1)
	  psq_st    f30,0x98(r1),0,0
	  stw       r31, 0x8C(r1)
	  stw       r30, 0x88(r1)
	  mr        r31, r3
	  lbz       r0, 0x14(r3)
	  cmplwi    r0, 0x1
	  bne-      .loc_0x450
	  lwz       r0, 0x1C(r4)
	  cmpwi     r0, 0x3E8
	  beq-      .loc_0x2A4
	  bge-      .loc_0x45C
	  cmpwi     r0, 0x2
	  beq-      .loc_0x50
	  b         .loc_0x45C

	.loc_0x50:
	  lwz       r3, 0x10(r31)
	  cmplwi    r3, 0
	  beq-      .loc_0x78
	  bl        -0xE73C0
	  cmpwi     r3, 0xD
	  bne-      .loc_0x78
	  lwz       r3, 0x10(r31)
	  bl        -0xE7404
	  mr        r30, r3
	  b         .loc_0x7C

	.loc_0x78:
	  li        r30, 0

	.loc_0x7C:
	  cmplwi    r30, 0
	  beq-      .loc_0x168
	  lbz       r0, 0x14(r30)
	  cmplwi    r0, 0x2
	  beq-      .loc_0x168
	  bl        -0x165C9C
	  xoris     r3, r3, 0x8000
	  lis       r0, 0x4330
	  stw       r3, 0x6C(r1)
	  lfd       f3, -0x4020(r2)
	  stw       r0, 0x68(r1)
	  lfs       f1, -0x4038(r2)
	  lfd       f2, 0x68(r1)
	  lfs       f0, -0x4034(r2)
	  fsubs     f2, f2, f3
	  fdivs     f1, f2, f1
	  fcmpo     cr0, f1, f0
	  ble-      .loc_0x168
	  lwz       r0, 0x10(r30)
	  cmplwi    r0, 0
	  beq-      .loc_0x160
	  bl        -0x165CDC
	  xoris     r3, r3, 0x8000
	  lis       r0, 0x4330
	  stw       r3, 0x6C(r1)
	  lfd       f3, -0x4020(r2)
	  stw       r0, 0x68(r1)
	  lfs       f1, -0x4038(r2)
	  lfd       f2, 0x68(r1)
	  lfs       f0, -0x4030(r2)
	  fsubs     f2, f2, f3
	  fdivs     f1, f2, f1
	  fcmpo     cr0, f1, f0
	  ble-      .loc_0x160
	  mr        r3, r30
	  bl        .loc_0x484
	  lwz       r5, 0x10(r30)
	  lis       r3, 0x804B
	  subi      r4, r3, 0x5D00
	  lfs       f2, -0x402C(r2)
	  lfs       f1, -0x4028(r2)
	  lis       r3, 0x804B
	  lfs       f0, -0x4024(r2)
	  addi      r0, r3, 0x4E04
	  stw       r4, 0x50(r1)
	  addi      r4, r1, 0x50
	  stw       r5, 0x54(r1)
	  stw       r0, 0x50(r1)
	  stfs      f2, 0x58(r1)
	  stfs      f1, 0x5C(r1)
	  stfs      f0, 0x60(r1)
	  lwz       r3, 0x4(r30)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x1A4(r12)
	  mtctr     r12
	  bctrl
	  b         .loc_0x168

	.loc_0x160:
	  mr        r3, r30
	  bl        .loc_0x484

	.loc_0x168:
	  lwz       r3, 0x4(r31)
	  bl        -0xE5338
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x204
	  lis       r3, 0x804B
	  lis       r4, 0x804E
	  subi      r0, r3, 0x5808
	  lis       r3, 0x804B
	  stw       r0, 0x44(r1)
	  addi      r4, r4, 0x6A78
	  li        r0, 0x149
	  li        r7, 0
	  stw       r4, 0x44(r1)
	  addi      r6, r3, 0x4B9C
	  lis       r3, 0x8051
	  lis       r4, 0x804B
	  sth       r0, 0x48(r1)
	  addi      r5, r3, 0x41E4
	  lfs       f2, 0x0(r5)
	  subi      r0, r4, 0x5814
	  stw       r7, 0x4C(r1)
	  addi      r3, r1, 0x44
	  lfs       f1, 0x4(r5)
	  addi      r4, r1, 0x34
	  stw       r6, 0x44(r1)
	  lfs       f0, 0x8(r5)
	  lwz       r5, 0x4(r31)
	  lfs       f3, 0x25C(r5)
	  lfs       f4, 0x260(r5)
	  lfs       f5, 0x264(r5)
	  stfs      f2, 0x38(r1)
	  stfs      f1, 0x3C(r1)
	  stfs      f0, 0x40(r1)
	  stw       r0, 0x34(r1)
	  stfs      f3, 0x38(r1)
	  stfs      f4, 0x3C(r1)
	  stfs      f5, 0x40(r1)
	  bl        0x17FBDC
	  b         .loc_0x28C

	.loc_0x204:
	  lis       r3, 0x804B
	  lis       r4, 0x804E
	  subi      r0, r3, 0x5808
	  lis       r3, 0x804B
	  stw       r0, 0x28(r1)
	  addi      r4, r4, 0x6A78
	  li        r0, 0x148
	  li        r7, 0
	  stw       r4, 0x28(r1)
	  addi      r6, r3, 0x4B88
	  lis       r3, 0x8051
	  lis       r4, 0x804B
	  sth       r0, 0x2C(r1)
	  addi      r5, r3, 0x41E4
	  lfs       f2, 0x0(r5)
	  subi      r0, r4, 0x5814
	  stw       r7, 0x30(r1)
	  addi      r3, r1, 0x28
	  lfs       f1, 0x4(r5)
	  addi      r4, r1, 0x18
	  stw       r6, 0x28(r1)
	  lfs       f0, 0x8(r5)
	  lwz       r5, 0x4(r31)
	  lfs       f3, 0x25C(r5)
	  lfs       f4, 0x260(r5)
	  lfs       f5, 0x264(r5)
	  stfs      f2, 0x1C(r1)
	  stfs      f1, 0x20(r1)
	  stfs      f0, 0x24(r1)
	  stw       r0, 0x18(r1)
	  stfs      f3, 0x1C(r1)
	  stfs      f4, 0x20(r1)
	  stfs      f5, 0x24(r1)
	  bl        0x17FB50

	.loc_0x28C:
	  lwz       r3, 0x4(r31)
	  li        r5, 0x2808
	  lwz       r4, 0x10(r31)
	  li        r6, 0x1
	  bl        -0xE6AF4
	  b         .loc_0x45C

	.loc_0x2A4:
	  bl        .loc_0x484
	  bl        -0x165EB4
	  xoris     r3, r3, 0x8000
	  lis       r0, 0x4330
	  stw       r3, 0x6C(r1)
	  lbz       r3, 0x1D(r31)
	  stw       r0, 0x68(r1)
	  lfd       f2, -0x4020(r2)
	  addi      r0, r3, 0x1
	  lfd       f0, 0x68(r1)
	  rlwinm    r4,r0,0,24,31
	  lfs       f1, -0x4038(r2)
	  fsubs     f2, f0, f2
	  lfs       f0, -0x4008(r2)
	  stb       r0, 0x1D(r31)
	  fdivs     f1, f2, f1
	  fmuls     f0, f0, f1
	  fctiwz    f0, f0
	  stfd      f0, 0x70(r1)
	  lwz       r3, 0x74(r1)
	  addi      r0, r3, 0x6
	  cmpw      r4, r0
	  blt-      .loc_0x45C
	  lwz       r3, 0x10(r31)
	  cmplwi    r3, 0
	  beq-      .loc_0x440
	  bl        -0xE69D4
	  lwz       r5, 0x4(r31)
	  cmplw     r3, r5
	  bne-      .loc_0x440
	  lwz       r3, 0x10(r31)
	  lis       r4, 0x4330
	  lbz       r0, 0x2B9(r5)
	  lbz       r5, 0x2B9(r3)
	  xoris     r0, r0, 0x8000
	  stw       r4, 0x70(r1)
	  xoris     r5, r5, 0x8000
	  lfd       f3, -0x4020(r2)
	  stw       r5, 0x74(r1)
	  lfs       f4, -0x4034(r2)
	  lfd       f0, 0x70(r1)
	  stw       r0, 0x6C(r1)
	  fsubs     f2, f0, f3
	  lfs       f1, -0x4014(r2)
	  stw       r4, 0x68(r1)
	  lfd       f0, 0x68(r1)
	  fmadds    f31, f4, f2, f1
	  fsubs     f0, f0, f3
	  fmadds    f30, f4, f0, f1
	  bl        -0xE5534
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x378
	  lfs       f31, -0x4004(r2)

	.loc_0x378:
	  lwz       r3, 0x4(r31)
	  bl        -0xE5548
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x38C
	  lfs       f30, -0x4004(r2)

	.loc_0x38C:
	  bl        -0x165F98
	  xoris     r3, r3, 0x8000
	  lis       r0, 0x4330
	  stw       r3, 0x7C(r1)
	  fadds     f0, f30, f31
	  lfd       f3, -0x4020(r2)
	  stw       r0, 0x78(r1)
	  lfs       f1, -0x4038(r2)
	  fdivs     f0, f30, f0
	  lfd       f2, 0x78(r1)
	  fsubs     f2, f2, f3
	  fdivs     f1, f2, f1
	  fcmpo     cr0, f1, f0
	  cror      2, 0, 0x2
	  bne-      .loc_0x404
	  li        r0, 0
	  li        r3, -0x1
	  stb       r0, 0x14(r1)
	  li        r0, 0x1
	  addi      r6, r1, 0x10
	  li        r5, 0x18
	  stw       r3, 0x10(r1)
	  stb       r0, 0x14(r1)
	  lwz       r4, 0x10(r31)
	  lwz       r3, 0x28C(r4)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x14(r12)
	  mtctr     r12
	  bctrl
	  b         .loc_0x45C

	.loc_0x404:
	  li        r0, 0
	  li        r3, -0x1
	  stb       r0, 0xC(r1)
	  li        r0, 0x1
	  addi      r6, r1, 0x8
	  li        r5, 0x18
	  stw       r3, 0x8(r1)
	  stb       r0, 0xC(r1)
	  lwz       r4, 0x10(r31)
	  lwz       r3, 0x28C(r4)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x14(r12)
	  mtctr     r12
	  bctrl
	  b         .loc_0x45C

	.loc_0x440:
	  lbz       r0, 0x1C(r31)
	  rlwinm    r0,r0,0,31,29
	  stb       r0, 0x1C(r31)
	  b         .loc_0x45C

	.loc_0x450:
	  cmplwi    r0, 0x2
	  bne-      .loc_0x45C
	  bl        .loc_0x484

	.loc_0x45C:
	  psq_l     f31,0xA8(r1),0,0
	  lfd       f31, 0xA0(r1)
	  psq_l     f30,0x98(r1),0,0
	  lfd       f30, 0x90(r1)
	  lwz       r31, 0x8C(r1)
	  lwz       r0, 0xB4(r1)
	  lwz       r30, 0x88(r1)
	  mtlr      r0
	  addi      r1, r1, 0xB0
	  blr

	.loc_0x484:
	*/
}

/*
 * --INFO--
 * Address:	8022F630
 * Size:	0000BC
 * TODO: WTF is going on in approach arg?
 */
void ActBattle::initApproach()
{
	if (m_other) {
		Vector3f pos = m_other->getPosition();

		PikiAI::ApproachPosActionArg arg(pos, 10.0f, -1.0f, 0, 1);
		m_approachPos->init(&arg);
		m_state = PIKIAI_ACTBATTLE_APPROACH;
	}
}

/*
 * --INFO--
 * Address:	8022F6EC
 * Size:	000050
 */
int ActBattle::execApproach()
{
	if (!m_approachPos->exec()) {
		initBattle();
	}

	return 1;
}

/*
 * --INFO--
 * Address:	8022F73C
 * Size:	0000C8
 */
void ActBattle::initBattle()
{
	m_state = PIKIAI_ACTBATTLE_BATTLE;

	if (randFloat() > 0.5f) {
		m_parent->startMotion(64, 64, this, nullptr);
	} else {
		m_parent->startMotion(65, 65, this, nullptr);
	}
}

/*
 * --INFO--
 * Address:	8022F804
 * Size:	0000FC
 */
int ActBattle::execBattle(void)
{
	if (!m_parent->assertMotion(64) && !m_parent->assertMotion(65)) {
		if (m_other) {
			Vector3f pos = m_other->getPosition();

			PikiAI::ApproachPosActionArg arg(pos, 10.0f, -1.0f, 0, 1);
			m_approachPos->init(&arg);
			m_state = PIKIAI_ACTBATTLE_APPROACH;
		}
	}

	Game::Piki* parent = m_parent;
	parent->m_velocity = Vector3f(0.0f, 0.0f, 0.0f);

	return 1;
}

/*
 * --INFO--
 * Address:	8022F900
 * Size:	0000E8
 */
int ActBattle::execDamage(void)
{
	if (!m_parent->assertMotion(4)) {
		if (m_other) {
			Vector3f pos = m_other->getPosition();

			PikiAI::ApproachPosActionArg arg(pos, 10.0f, -1.0f, 0, 1);
			m_approachPos->init(&arg);
			m_state = PIKIAI_ACTBATTLE_APPROACH;
		}
	}

	Game::Piki* parent = m_parent;
	parent->m_velocity = Vector3f(0.0f, 0.0f, 0.0f);

	return 1;
}
} // namespace PikiAI