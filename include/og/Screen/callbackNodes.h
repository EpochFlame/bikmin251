#ifndef _OG_SCREEN_CALLBACKNODES_H
#define _OG_SCREEN_CALLBACKNODES_H

#include "types.h"
#include "JSystem/J2D/J2DPane.h"
#include "og/Screen/ScaleMgr.h"
#include "P2DScreen.h"
#include "SoundID.h"

struct LifeGauge;

namespace JUtility {
struct TColor;
} // namespace JUtility

namespace P2JME {
struct SimpleMessage;
struct TRenderingProcessor;
} // namespace P2JME

namespace og {
namespace Screen {
struct AngleMgr;
struct AnimGroup;
struct AnimScreen;
struct CounterKeta;
struct DataNavi;

/**
 * @size{0x44}
 */
struct CallBack_CatchPiki : public P2DScreen::CallBackNode {
	CallBack_CatchPiki();

	virtual ~CallBack_CatchPiki() { } // _08
	virtual void update();            // _10

	void init(J2DScreen* canvas, u64 tag, u32* pikiType, JKRArchive* arc);
	void setPikiIcon(int);

	// _00     = VTBL
	// _00-_1C = P2DScreen::CallBackNode
	u32* m_pikiType;        // _1C
	J2DPicture* m_pikiIcon; // _20
	u32 m_currPikiType;     // _24
	ScaleMgr m_scaleMgr;    // _28
};

struct CallBack_CounterRV : public P2DScreen::CallBackNode {
	enum EnumCenteringMode { ECM_Unknown0 = 0, ECM_Unknown1 = 1, ECM_UNKNOWN_2 = 2 };

	CallBack_CounterRV(char**, u16, u16, JKRArchive*);

	virtual ~CallBack_CounterRV() { }              // _08 (weak)
	virtual void update();                         // _10
	virtual void draw(Graphics&, J2DGrafContext&); // _14
	virtual void init(J2DScreen*, u64, u64, u64, u32*,
	                  bool);           // _1C
	virtual void show();               // _20
	virtual void hide();               // _24
	virtual void setValue(bool, bool); // _28
	virtual void setValue();           // _2C (weak)

	J2DPane* getMotherPane();
	void setBlind(bool);
	void setCenteringMode(EnumCenteringMode);
	void setCounterUpDown(int, bool, bool);
	void setKetaSub(int, bool, bool);
	void setPuyoAnim(bool);
	void setPuyoAnimZero(bool);
	void setRandMode(bool);
	void setValPtr(u32*);
	void setZeroAlpha(u8);
	void startPuyoUp(f32);

	// _00     = VTBL
	// _00-_1C = P2DScreen::CallBackNode
	char** m_characterTexturePaths;    // _1C
	u32* _20;                          // _20
	u32 _24;                           // _24
	u32 _28;                           // _28
	u16 m_currCounters;                // _2C
	u16 m_counterLimit;                // _2E /* allocated slot count of _7C */
	u16 _30;                           // _30
	f32 _34;                           // _34
	f32 _38;                           // _38
	f32 _3C;                           // _3C
	f32 _40;                           // _40
	f32 m_height;                      // _44
	f32 m_widthMaybe;                  // _48
	f32 m_heightMaybe;                 // _4C
	f32 _50;                           // _50
	f32 _54;                           // _54
	f32 _58;                           // _58
	f32 _5C;                           // _5C
	u32 m_basePosition;                // _60 /* Use J2DBasePosition constants. */
	u8 _64;                            // _64
	u8 _65[7];                         // _65 /* Hopefully this doesn't mess with size. */
	J2DPictureEx* _6C;                 // _6C
	J2DPane* _70;                      // _70
	J2DPane* _74;                      // _74
	J2DPane* m_motherPane;             // _78
	CounterKeta** m_counters;          // _7C
	ResTIMG** m_imgResources;          // _80
	bool m_isPuyoAnim;                 // _84
	bool m_isPuyoAnimZero;             // _85
	bool m_isBlind;                    // _86
	bool m_isHidden;                   // _87
	bool _88;                          // _88
	u8 _89;                            // _89
	EnumCenteringMode m_centeringMode; // _8C
	u8 m_zeroAlpha;                    // _90
	SoundID m_scaleUpSoundID;          // _94
	SoundID m_scaleDownSoundID;        // _98
	u8 _9C;                            // _9C
	f32 _A0;                           // _A0
	f32 _A4;                           // _A4

	static struct {
		f32 _00;
		f32 _04;
		f32 _08;
	} msVal;
};

struct CallBack_CounterDay : public CallBack_CounterRV {
	CallBack_CounterDay(char**, u16, JKRArchive*);

	virtual ~CallBack_CounterDay() { } // _08 (weak)
	virtual void update();             // _10
	virtual void init(J2DScreen*, u64, u64, u64, u32*,
	                  bool); // _1C
	virtual void show();     // _20
	virtual void hide();     // _24
	virtual void setValue(); // _2C

	// _00     = VTBL
	// _00-_A8 = CallBack_CounterRV
	J2DPicture* _A8; // _A8
};

// Size: 0xCC
struct CallBack_CounterSlot : public CallBack_CounterRV {
	CallBack_CounterSlot(char**, u16, u16, JKRArchive*);

	virtual ~CallBack_CounterSlot(); // _08 (weak)
	virtual void update();           // _10
	virtual void init(J2DScreen*, u64, u64, u64, u32*,
	                  bool);           // _1C
	virtual void setValue(bool, bool); // _28
	virtual void setValue();           // _2C (weak)

	void setPuyoParam(f32, f32, f32);
	void slot_up(int);
	void startSlot(f32);

	// _00     = VTBL
	// _00-_A8 = CallBack_CounterRV
	u8 _A8;               // _A8
	u8 _A9;               // _A9
	u8 _AA;               // _AA
	u8 _AB;               // _AB
	u8 _AC;               // _AC
	u32 _B0;              // _B0
	f32 m_timer;          // _B4
	f32 m_updateInterval; // _B8
	f32 m_puyoParm1;      // _BC
	f32 m_puyoParm2;      // _C0
	f32 m_puyoParm3;      // _C4
	SoundID _C8;          // _C8
};

// Size: 0x28
struct CallBack_DrawAfter : public P2DScreen::CallBackNode {
	CallBack_DrawAfter(P2DScreen::Mgr*, u64);

	virtual ~CallBack_DrawAfter() { }                          // _08 (weak)
	virtual void update();                                     // _10
	virtual void draw(Graphics& gfx, J2DGrafContext& context); // _14

	// _00     = VTBL
	// _00-_1C = P2DScreen::CallBackNode
	J2DPictureEx* _1C; // _1C
	J2DPictureEx* _20; // _20
	bool m_isVisible;  // _24
};

// Size: 0x4C
struct CallBack_Furiko : public P2DScreen::CallBackNode {
	inline CallBack_Furiko();

	virtual ~CallBack_Furiko() { }                 // _08 (weak)
	virtual void update();                         // _10
	virtual void draw(Graphics&, J2DGrafContext&); // _14

	void init(J2DPane*, f32, f32, f32);
	void setParam(f32, f32, f32);
	void stop();

	// _00     = VTBL
	// _00-_1C = P2DScreen::CallBackNode
	J2DPane* m_pane;           // _1C
	bool m_canUpdate;          // _20
	bool m_doResetPane;        // _21
	Vector2f m_currPosition;   // _24
	f32 m_offset;              // _2C
	f32 m_param2;              // _30
	f32 m_growth;              // _34
	Vector2f m_goalPosition;   // _38
	Vector2f m_changeModifier; // _40
	f32 m_currPaneAngle;       // _48
};

struct CallBack_LifeGauge : public P2DScreen::CallBackNode {

	enum LifeGaugeType {
		LIFEGAUGE_OLIMAR    = 0,
		LIFEGAUGE_LOUIE     = 1,
		LIFEGAUGE_PRESIDENT = 2,
	};

	CallBack_LifeGauge();

	virtual ~CallBack_LifeGauge() { }                          // _08 (weak)
	virtual void update();                                     // _10
	virtual void draw(Graphics& gfx, J2DGrafContext& context); // _14

	void init(P2DScreen::Mgr* mgr, DataNavi* data, LifeGaugeType lifeGaugeType);
	void moveIcon();
	void setType(LifeGaugeType lifeGaugeType);
	void setOffset(f32 x, f32 y);

	static inline void initialiseStaticValues();

	// _00     = VTBL
	// _00-_1C = P2DScreen::CallBackNode
	DataNavi* m_data;              // _1C
	f32 m_naviLifeRatio;           // _20
	f32 m_widthOrRadiusMaybe;      // _24
	f32 m_offsetX;                 // _28
	f32 m_offsetY;                 // _2C
	f32 _30;                       // _30
	f32 _34;                       // _34
	f32 _38;                       // _38
	f32 m_na_i_d4;                 // _3C
	f32 m_na_i_d8;                 // _40
	f32 m_li_i_d4;                 // _44
	f32 m_li_i_d8;                 // _48
	LifeGauge* m_lifeGauge;        // _4C
	u8 m_isActiveNavi;             // _50
	u8 m_isActiveNaviOld;          // _51
	f32 m_lowLifeSoundTimer;       // _54
	f32 _58;                       // _58
	P2DScreen::Mgr* _5C;           // _5C
	J2DPane* m_pin1;               // _60
	J2DPicture* m_pin2;            // _64
	J2DPane* m_na_i;               // _68
	J2DPane* m_li_i;               // _6C
	J2DPicture* _70;               // _70
	J2DPicture* _74;               // _74
	J2DPicture* _78;               // _78
	J2DPicture* _7C;               // _7C
	J2DPicture* _80;               // _80
	J2DPicture* _84;               // _84
	AngleMgr* m_angleMgr;          // _88
	ScaleMgr* m_scaleMgr;          // _8C
	LifeGaugeType m_lifeGaugeType; // _90
	u8 m_canNaviChange;            // _94
	f32 m_moveTimer;               // _98

	static struct StaticValues {
		inline StaticValues()
		{
			_00 = 0.4f;
			_04 = 0.6f;
			_08 = 0.3f;
			_0C = 0.4f;
		}

		u32 _00; // _00, unknown
		u32 _04; // _04, unknown
		f32 _08; // _08
		f32 _0C; // _0C
	} msVal;
};

// Size: 0x48
struct CallBack_Message : public P2DScreen::CallBackNode {
	CallBack_Message();

	virtual ~CallBack_Message() { }                // _08 (weak)
	virtual void update() { }                      // _10 (weak)
	virtual void draw(Graphics&, J2DGrafContext&); // _14

	// Unused/inlined:
	void drawInfo(J2DGrafContext&);

	// _00     = VTBL
	// _00-_1C = P2DScreen::CallBackNode
	P2JME::SimpleMessage* m_message; // _1C
	u64 m_messageIDAsULL;            // _20
	u32 m_messageIDAs2UL[2];         // _28
	f32 _30;                         // _30
	f32 _34;                         // _34
	f32 m_minX;                      // _38, yes this is floats not a TBox2f or TVec2f
	f32 m_minY;                      // _3C, yes i know it's dumb.
	f32 m_maxX;                      // _40, unfortunately the CallBack_Message ctor is thrown up by a recursion
	f32 m_maxY;                      // _44, and it cannot have a ctor for these elements
};

/**
 * @unused
 */
struct CallBack_MessageAndShadow : public CallBack_Message {
	CallBack_MessageAndShadow(f32, f32, J2DPane*);

	virtual ~CallBack_MessageAndShadow();          // _08
	virtual void draw(Graphics&, J2DGrafContext&); // _14

	// _00     = VTBL
	// _00-_48 = CallBack_Message
};

// Unused/inlined:
void MessageSetInfoShadow(J2DPane*, P2JME::TRenderingProcessor*, J2DPane*);

struct CallBack_Screen : public P2DScreen::CallBackNode {
	CallBack_Screen(P2DScreen::Mgr*, u64);

	virtual ~CallBack_Screen() { }                 // _08 (weak)
	virtual void update();                         // _10
	virtual void draw(Graphics&, J2DGrafContext&); // _14

	void changeScreen(P2DScreen::Mgr*, u64);
	P2DScreen::Mgr* getPartsScreen();

	// _00     = VTBL
	// _00-_1C = P2DScreen::CallBackNode
	P2DScreen::Mgr* m_partsScreen; // _1C
	J2DPane* m_pane;               // _20
	J2DPane* m_textBox;            // _24
	f32 m_scale;                   // _28
	f32 m_xOffs;                   // _2C
	f32 m_yOffs;                   // _30
};

// Size: 0x38
struct CallBack_Picture : public CallBack_Screen {
	CallBack_Picture(P2DScreen::Mgr*, u64);

	virtual ~CallBack_Picture();                   // _08
	virtual void update();                         // _10
	virtual void draw(Graphics&, J2DGrafContext&); // _14

	// _00     = VTBL
	// _00-_34 = CallBack_Screen
	AnimGroup* m_animGroup; // _34
};

struct CallBack_SunMeter : public P2DScreen::CallBackNode {
	CallBack_SunMeter();

	virtual ~CallBack_SunMeter() { } // _08 (weak)
	virtual void update();           // _10

	void init(J2DScreen* canvas, f32* time);
	void startEffectChime();

	// _00     = VTBL
	// _00-_1C = P2DScreen::CallBackNode
	f32 m_timer;             // _1C
	f32* m_currentTime;      // _20, ptr to current time, as fraction (0 = start of day, 1 = end of day)
	J2DPane* m_startPane;    // _24
	J2DPane* m_endPane;      // _28
	J2DPane* m_suniPane;     // _2C
	J2DPane* m_sun1Pane;     // _30
	J2DPane* m_sun2Pane;     // _34
	bool m_hasChimedNoon;    // _38
	bool m_hasChimedMorning; // _39
	bool m_hasChimedEvening; // _3A
	ScaleMgr* m_scaleMgr;    // _3C
};

struct AnimText_Screen : public CallBack_Screen {
	AnimText_Screen(P2DScreen::Mgr*, u64);

	virtual ~AnimText_Screen() { } // _08 (weak)
	virtual void update();         // _10

	void setAnimScreen(AnimScreen*);
	void close();
	void blink(f32, f32);
	void open(f32);
	void stop();
	void setText(u64);

	// unused/inlined
	void setTextAnim(u64);

	// _00     = VTBL
	// _00-_34 = CallBack_Screen
	int m_colorType;            // _34
	AnimScreen* m_anmScreen;    // _38
	bool m_isUpdateSuccess;     // _3C
	J2DTextBox* m_msgBodyPane;  // _40
	J2DTextBox* m_msgBackPane;  // _44 // just a guess
	bool _48;                   // _48
	u32 _4C;                    // _4C
	u64 m_tag;                  // _50
	f32 m_blinkTimer;           // _58
	f32 m_blinkFactor;          // _5C
	f32 m_blinkLevel;           // _60
	f32 _64;                    // _64
	bool m_isBlinking;          // _68
	f32 _6C;                    // _6C
	JUtility::TColor m_color0;  // _70
	JUtility::TColor m_color1;  // _74
	JUtility::TColor m_color2;  // _78
	JUtility::TColor m_color3;  // _7C
	JUtility::TColor m_color4;  // _80
	JUtility::TColor m_color5;  // _84
	JUtility::TColor m_color6;  // _88
	JUtility::TColor m_color7;  // _8C
	JUtility::TColor m_color8;  // _90
	JUtility::TColor m_color9;  // _94
	JUtility::TColor m_color10; // _98
	JUtility::TColor m_color11; // _9C
	JUtility::TColor m_color12; // _A0
	JUtility::TColor m_color13; // _A4
	JUtility::TColor m_color14; // _A8
	JUtility::TColor m_color15; // _AC
	JUtility::TColor m_color16; // _B0
	u8 _B4[4];                  // _B4
};

struct CounterKeta {
	void setSuji(ResTIMG** texList, u32 texIdx);
	void calcScale();

	J2DPicture* m_picture; // _00
	u32 m_textureIndex;    // _04
	ScaleMgr* m_scaleMgr;  // _08
	f32 m_width;           // _0C
	f32 m_height;          // _10
};

extern const char* SujiTex32[11];
extern const char* SujiTexMap[11];

} // namespace Screen
} // namespace og

#endif
