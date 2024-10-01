#ifndef _MORIMURA_CHALLENGE_H
#define _MORIMURA_CHALLENGE_H

#include "Morimura/DayEndCount.h"
#include "Morimura/Window.h"
#include "Screen/Enums.h"
#include "og/Screen/ogScreen.h"
#include "efx2d/T2DCursor.h"

struct JKRExpHeap;

namespace og {
namespace Screen {
struct DispMemberWorldMapInfoWin0;
}
} // namespace og

namespace Game {
struct Challenge2D_TitleInfo;
struct Challenge2D_ResultInfo;
struct Vs2D_TitleInfo;
} // namespace Game

namespace Morimura {
struct DispMemberChallengeResult : public og::Screen::DispMemberBase {
	DispMemberChallengeResult()
	    : og::Screen::DispMemberBase()
	{
		m_resultInfo = nullptr;
		m_heap       = nullptr;
		_10          = 0;
	}

	virtual u32 getSize() { return sizeof(DispMemberChallengeResult); } // _08 (weak)
	virtual u32 getOwnerID() { return OWNER_MRMR; }                     // _0C (weak)
	virtual u64 getMemberID() { return MEMBER_CHALLENGE_RESULT; }       // _10 (weak)

	// _00     = VTBL
	// _00-_08 = og::Screen::DispMemberBase
	Game::Challenge2D_ResultInfo* m_resultInfo; // _08
	JKRExpHeap* m_heap;                         // _0C
	int _10;                                    // _10
};

struct DispMemberChallengeSelect : public og::Screen::DispMemberBase {
	DispMemberChallengeSelect()
	{
		m_titleInfo            = nullptr;
		m_debugExpHeap         = nullptr;
		m_stageNumber          = -1;
		m_selectedStageIndex   = 0;
		m_playType             = 0;
		_1C                    = 0;
		m_dispWorldMapInfoWin0 = nullptr;
	}

	virtual u32 getSize() { return sizeof(DispMemberChallengeSelect); } // _08 (weak)
	virtual u32 getOwnerID() { return OWNER_MRMR; }                     // _0C (weak)
	virtual u64 getMemberID() { return MEMBER_CHALLENGE_SELECT; }       // _10 (weak)

	// _00     = VTBL
	// _00-_08 = og::Screen::DispMemberBase
	Game::Challenge2D_TitleInfo* m_titleInfo;                       // _08
	JKRExpHeap* m_debugExpHeap;                                     // _0C
	int m_stageNumber;                                              // _10
	int m_selectedStageIndex;                                       // _14
	int m_playType;                                                 // _18
	int _1C;                                                        // _1C
	og::Screen::DispMemberWorldMapInfoWin0* m_dispWorldMapInfoWin0; // _20
};

struct TChallengePlayModeScreen : public TScreenBase {
	TChallengePlayModeScreen(JKRArchive*, int);

	virtual void create(const char*, u32);        // _08
	virtual void update();                        // _0C
	virtual void draw(Graphics&, J2DPerspGraph*); // _10

	// _00     = VTBL
	// _00-_18 = TScreenBase
	J2DPane* mPaneList0[2];                      // _18
	J2DPicture* mSphereTex;                      // _20
	J2DPane* mPane3;                             // _24
	J2DPane* mPane4;                             // _28
	J2DPane* mPane5;                             // _2C
	J2DPane* mPaneList1[3];                      // _30
	og::Screen::ScaleMgr* mScaleMgr[2];          // _3C
	og::Screen::AnimText_Screen* mAnimScreen[4]; // _44
	og::Screen::CallBack_Furiko* mFuriko;        // _54
	efx2d::T2DCursor* mEfxCursor1;               // _58
	efx2d::T2DCursor* mEfxCursor2;               // _5C
	Vector2f mEfxCursorPos1;                     // _60
	Vector2f mEfxCursorPos2;                     // _68
	Vector2f mPane1Pos;                          // _70
	Vector2f mPane2Pos;                          // _78
	int mState;                                  // _80
	bool mDoShowNoController;                    // _84
	f32 mNoControllerTimer;                      // _88
	f32 mTimer;                                  // _8C
	f32 mTimer2;                                 // _90
	f32 mMovePos;                                // _94
	f32 mAlphaTimer;                             // _98
	f32 mScale;                                  // _9C
	f32 mAngleTimers[3];                         // _A0
};

struct TChallengeResultDemoScreen : public TScreenBase {
	virtual void create(const char*, u32);        // _08
	virtual void update();                        // _0C
	virtual void draw(Graphics&, J2DPerspGraph*); // _10

	// _00     = VTBL
	// _00-_18 = TScreenBase
	og::Screen::AnimPane* _18; // _18
	og::Screen::AnimPane* _1C; // _1C
	og::Screen::AnimPane* _20; // _20
	u8 _24;                    // _24
};

struct TChallengeScreen : public TScreenBase {
	TChallengeScreen(JKRArchive*, int);

	virtual void create(const char*, u32); // _08
	virtual void update();                 // _0C
	virtual void createAnimPane(char*);    // _14
	virtual void updateBckPane();          // _18

	bool isRandAnimStart();

	// _00     = VTBL
	// _00-_18 = TScreenBase
	int m_animPaneCount;                // _18
	og::Screen::AnimPane** m_animPanes; // _1C
	u32 _20;                            // _20, unknown
	u32 _24;                            // _24, unknown
	u8 _28;                             // _28
};

struct TChallengeResultScreen : public TChallengeScreen {
	virtual void create(const char*, u32); // _08
	virtual void createAnimPane(char*);    // _14
	virtual void updateBckPane();          // _18

	// _00     = VTBL
	// _00-_2C = TChallengeScreen
	og::Screen::AnimPane* _2C; // _2C
};

struct TChallengeEndCount : public TDayEndCount {
	TChallengeEndCount();

	virtual ~TChallengeEndCount();      // _08 (weak)
	virtual void doCreate(JKRArchive*); // _4C

	// _00     = VTBL1
	// _18     = VTBL2
	// _00-_D4 = TDayEndCount
};

struct TChallengeEndCount1p : public TChallengeEndCount {
	TChallengeEndCount1p();

	virtual ~TChallengeEndCount1p(); // _08 (weak)
	virtual bool doUpdate();         // _58

	// _00     = VTBL1
	// _18     = VTBL2
	// _00-_D4 = TChallengeEndCount
};

struct TChallengeEndCount2p : public TChallengeEndCount {
	TChallengeEndCount2p();

	virtual ~TChallengeEndCount2p(); // _08 (weak)
	virtual bool doUpdate();         // _58

	// _00     = VTBL1
	// _18     = VTBL2
	// _00-_D4 = TChallengeEndCount
};

struct TChallengeResult : public TTestBase {
	struct VectorUnit {
		f32 _00; // _00
		f32 _04; // _04
		f32 _08; // _08
		f32 _0C; // _0C
	};

	TChallengeResult();

	virtual ~TChallengeResult();                             // _08 (weak)
	virtual void doCreate(JKRArchive*);                      // _4C
	virtual bool doUpdate();                                 // _58
	virtual void doUpdateFadeoutFinish();                    // _64
	virtual void doDraw(Graphics& gfx);                      // _68
	virtual og::Screen::DispMemberBase* getDispMemberBase(); // _78 (weak)

	void setInfo();
	void updateDemo();
	void changeAnimDemo();
	void startRankInDemo();
	void startDemo();
	void fadeEffect();

	// _00     = VTBL1
	// _18     = VTBL2
	// _00-_78 = TTestBase
	JKRArchive* _78;                                // _78
	TChallengeResultScreen* m_resultScreen;         // _7C
	TChallengeResultDemoScreen* m_resultDemoScreen; // _80
	u8 _84[0x178];                                  // _84, TODO: fill these in from ghidra
};

struct TChallengeSelect : public TTestBase {
	TChallengeSelect();

	virtual ~TChallengeSelect();                             // _08 (weak)
	virtual void doCreate(JKRArchive*);                      // _4C
	virtual bool doUpdate();                                 // _58
	virtual void doUpdateFadeoutFinish();                    // _64
	virtual void doDraw(Graphics& gfx);                      // _68
	virtual og::Screen::DispMemberBase* getDispMemberBase(); // _78 (weak)

	void setInfo(int);
	void setStageName(int);
	void getState(int);
	void getAfterState(int);
	void isChangeState(int);
	void getIndexMax();
	void openWindow();
	void closeWindow();
	void reset();
	void demoStart();

	static int mRightOffset;          // 0
	static int mDownOffset;           // 0
	static u8 mFrameAnimAlpha;        // 0
	static bool mAllCourseOpen;       // false
	static bool mForceDemoStart;      // false
	static int mDivePikiNum;          // 0
	static JKRHeap* mDebugHeapParent; // nullptr, may be a different JKR heap type
	static JKRExpHeap* mDebugHeap;    // nullptr, may be a different JKR heap type

	static bool mSelected1p;       // true
	static f32 mAlphaSpeed;        // 0.05f
	static s16 mFlashAnimInterval; // 300
	static f32 mTextFlashVal;      // 1.0f
	static bool mConnect2p;        // true
	static f32 mPanelMoveVal;      // 1.0f
	static f32 mPanelMoveRate;     // 0.25f
	static f32 mCircleY;           // 100.0f
	static f32 mTimerSpeed;        // 0.15f
	static f32 mMoveSpeed;         // 12.0f
	static f32 mSelectIconScale;   // 1.5f
	static ResTIMG* mIconTexture[4];

	// _00     = VTBL1
	// _18     = VTBL2
	// _00-_78 = TTestBase
	JKRArchive* _78; // _78
	u8 _7C[0xD4];    // _7C, TODO: fill these in from ghidra
};

struct TChallengeResultScene : public THIOScene {
	virtual SceneType getSceneType();                       // _08 (weak)
	virtual ScreenOwnerID getOwnerID();                     // _0C (weak)
	virtual ScreenMemberID getMemberID();                   // _10 (weak)
	virtual const char* getResName() const;                 // _1C (weak)
	virtual void doCreateObj(JKRArchive*);                  // _20 (weak)
	virtual void doUserCallBackFunc(Resource::MgrCommand*); // _24

	// _00      = VTBL
	// _00-_224 = THIOScene
	// _220, treat as TChallengeResult*
};

struct TChallengeSelectScene : public THIOScene {
	virtual SceneType getSceneType();             // _08 (weak)
	virtual ScreenOwnerID getOwnerID();           // _0C (weak)
	virtual ScreenMemberID getMemberID();         // _10 (weak)
	virtual const char* getResName() const;       // _1C (weak)
	virtual void doCreateObj(JKRArchive*);        // _20 (weak)
	virtual bool doStart(Screen::StartSceneArg*); // _3C

	// _00      = VTBL
	// _00-_224 = THIOScene
	// _220, treat as TChallengeSelect*
	TConfirmEndWindow* m_confirmEndWindow; // _224
};

struct TChallengeSelectExplanationWindow : TSelectExplanationWindow {
	virtual void create(const char*, u32); // _08
	virtual void screenScaleUp();          // _14

	// _00     = VTBL
	// _00-_30 = TSelectExplanationWindow
};
} // namespace Morimura

#endif
