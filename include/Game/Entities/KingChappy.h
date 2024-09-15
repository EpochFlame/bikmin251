#ifndef _GAME_ENTITIES_KINGCHAPPY_H
#define _GAME_ENTITIES_KINGCHAPPY_H

#include "Game/EnemyStateMachine.h"
#include "Game/EnemyAnimatorBase.h"
#include "Game/EnemyParmsBase.h"
#include "Game/EnemyMgrBase.h"
#include "Game/JointFuncs.h"
#include "Game/EnemyBase.h"
#include "Game/WalkSmokeEffect.h"
#include "efx/TKch.h"
#include "efx/TEnemyHamon.h"
#include "SysShape/Joint.h"
#include "Collinfo.h"
#include "Sys/MatBaseAnimation.h"
#include "Sys/MatBaseAnimator.h"

/**
 * --Header for Emperor Bulblax (KingChappy)--
 */

namespace Game {
namespace KingChappy {
struct FSM;

enum StateID {
	KINGCHAPPY_Walk     = 0,
	KINGCHAPPY_Attack   = 1,
	KINGCHAPPY_Dead     = 2,
	KINGCHAPPY_Flick    = 3,
	KINGCHAPPY_WarCry   = 4,
	KINGCHAPPY_Damage   = 5,
	KINGCHAPPY_Turn     = 6,
	KINGCHAPPY_Eat      = 7,
	KINGCHAPPY_Hide     = 8,
	KINGCHAPPY_HideWait = 9,
	KINGCHAPPY_Appear   = 10,
	KINGCHAPPY_Caution  = 11,
	KINGCHAPPY_Swallow  = 12,
	KINGCHAPPY_Count,
};

struct Obj : public EnemyBase {
	Obj();

	//////////////// VTABLE
	virtual void onInit(CreatureInitArg* settings);         // _30
	virtual void onKill(CreatureKillArg* settings);         // _34
	virtual void doSimulation(f32);                         // _4C
	virtual void doDirectDraw(Graphics& gfx);               // _50
	virtual f32 getBodyRadius();                            // _54 (weak)
	virtual f32 getCellRadius();                            // _58 (weak)
	virtual void inWaterCallback(WaterBox* wb);             // _84
	virtual bool isUnderground();                           // _D0 (weak)
	virtual void collisionCallback(CollEvent& event);       // _EC
	virtual void getShadowParam(ShadowParam& settings);     // _134
	virtual void applyImpulse(Vector3f&, Vector3f&);        // _18C (weak)
	virtual ~Obj() { }                                      // _1BC (weak)
	virtual void birth(Vector3f&, f32);                     // _1C0
	virtual void setInitialSetting(EnemyInitialParamBase*); // _1C4 (weak)
	virtual void doUpdate();                                // _1CC
	virtual void doAnimationUpdateAnimator();               // _1D8
	virtual void doAnimationCullingOff();                   // _1DC
	virtual void doDebugDraw(Graphics&);                    // _1EC
	virtual void setParameters();                           // _228
	virtual void initMouthSlots();                          // _22C
	virtual void initWalkSmokeEffect();                     // _230
	virtual WalkSmokeEffect::Mgr* getWalkSmokeEffectMgr();  // _234
	virtual void updateEfxHamon();                          // _24C (weak)
	virtual void createEfxHamon();                          // _250 (weak)
	virtual EnemyTypeID::EEnemyTypeID getEnemyTypeID();     // _258 (weak)
	virtual MouthSlots* getMouthSlots();                    // _25C (weak)
	virtual bool damageCallBack(Creature*, f32, CollPart*); // _278
	virtual bool pressCallBack(Creature*, f32, CollPart*);  // _27C (weak)
	virtual bool bombCallBack(Creature*, Vector3f&, f32);   // _294
	virtual bool eatWhitePikminCallBack(Creature*, f32);    // _298 (weak)
	virtual void doStartStoneState();                       // _2A4
	virtual void doFinishStoneState();                      // _2A8
	virtual void startCarcassMotion();                      // _2C4
	virtual void wallCallback(const MoveInfo&);             // _2E8
	virtual f32 getDownSmokeScale();                        // _2EC (weak)
	virtual void doStartMovie();                            // _2F0
	virtual void doEndMovie();                              // _2F4
	virtual void setFSM(FSM*);                              // _2F8 (weak)
	virtual void changeMaterial();
	//////////////// VTABLE END

	void eatBomb();
	void getPikminInMouth(bool);
	void getTonguePosVel(Vector3f&, Vector3f&);
	void setNextGoal();
	void searchTarget();
	void isOutOfTerritory(f32);
	bool forceTransit(int);
	void requestTransit(int);
	void walkFunc();
	void turnFunc(f32);
	void isReachToGoal(f32);
	void checkAttack(bool);
	void checkFlick(bool);
	void checkDead(bool);
	void checkTurn(bool);
	void startMotionSelf(int, SysShape::MotionListener*);
	void endBlendAnimation();
	void leftFootMtxCalc();
	void rightFootMtxCalc();
	void footMtxCalc(f32 (*)[4], Vector3f*, f32*);
	void resetFootPos();
	void fadeAllEffect();
	void createEffect(int);
	void fadeEffect(int);
	void createBounceEffect();
	void startMatAnimation();

    static Sys::MatLoopAnimator sMatAnimator;

	// _00 		= VTBL
	// _00-_2BC	= EnemyBase
	Vector3f mGoalPosition;                       // _2BC, initialised as mHomePosition
	MouthSlots mMouthSlots;                       // _2C8
	SysShape::Joint* mMouthJoint1;                // _2D0, 'kuti'
	SysShape::Joint* mBodyJoint;                  // _2D4, 'kosijnt'
	SysShape::Joint* mTongueJoint1;               // _2D8, 'bero6'
	SysShape::Joint* mTongueJoint2;               // _2DC, 'bero5'
	SysShape::Joint* mMouthJoint2;                // _2E0, 'kuti'
	bool mAllowAnimBlending;                      // _2E4
	StateID mNextState;                           // _2E8
	bool mDoCheckAppear;                          // _2EC
	int mSearchDelayTimer;                        // _2F0, delay being able to search for target after touching a wall
	Vector3f mPrevWalkingCheckPosition;           // _2F4, initialised as mHomePosition (but y = 0.0f)
	Vector3f mFootPosition;                       // _300, used for determining jump crushing
	int mWalkingTimer;                            // _30C
	u16 mLFootJointIndex;                         // _310, index for 'asiL'
	Vector3f mLFootPosition;                      // _314
	f32 mLFootHeightRatio;                        // _320
	u16 mRFootJointIndex;                         // _324, index for 'asiR'
	Vector3f mRFootPosition;                      // _328
	f32 mRFootHeightRatio;                        // _334
	bool mCanEatBombs;                            // _338
	u16* mMouthJointIndices;                      // _33C, indices for mouth joints
	WaterBox* mCurrentWaterBox;                   // _340, no one told morimura theres an enemybase level waterbox
	WalkSmokeEffect::Mgr mWalkSmokeMgr;           // _344
	FSM* mFsm;                                    // _34C
	efx::TKchYodare* mEfxYodare;                  // _350
	efx::TKchDiveSand* mEfxDiveSand;              // _354
	efx::TKchDiveWat* mEfxDiveWater;              // _358
	efx::TKchCryAB* mEfxCryAB;                    // _35C
	efx::TKchCryInd* mEfxCryInd;                  // _360
	efx::TKchSmokeHana* mEfxSmoke;                // _364
	efx::TKchAttackYodare* mEfxAttack;            // _368
	efx::TKchDeadYodare* mEfxDeadYodare;          // _36C
	efx::TKchDeadHana* mEfxDeadHana;              // _370
	efx::TEnemyHamonChasePos* mRightEyeRippleEfx; // _374
	efx::TEnemyHamonChasePos* mLeftEyeRippleEfx;  // _378
	Vector3f mRightEyePosition;                   // _37C
	Vector3f mLeftEyePosition;                    // _388
	bool mIsBig;                                  // _394, ie. is the Bulblax Kingdom Emperor
	                                              // _398 = PelletView
};

struct Mgr : public EnemyMgrBase {
	Mgr(int objLimit, u8 modelType);

	//////////////// VTABLE
	// virtual ~Mgr();                                     // _58 (weak)
	virtual EnemyBase* birth(EnemyBirthArg&); // _70
	virtual void doAlloc();                   // _A8
	virtual SysShape::Model* createModel();   // _B0
	virtual EnemyBase* getEnemy(int index)    // _A4 (weak)
	{
		return &m_obj[index];
	}
	virtual EnemyTypeID::EEnemyTypeID getEnemyTypeID() // _AC (weak)
	{
		return EnemyTypeID::EnemyID_KingChappy;
	}
	virtual void createObj(int count) // _A0 (weak)
	{
		m_obj = new Obj[count];
	}
	virtual void loadTexData();
	//////////////// VTABLE END

	void requestState(Obj*, int);

	// _00 		= VTBL
	// _00-_44	= EnemyMgrBase
	Obj* m_obj; // _44
	Sys::MatTexAnimation* mTexAnimation;
};

struct Parms : public EnemyParmsBase {
	struct ProperParms : public Parameters {
		ProperParms()
		    : Parameters(nullptr, "EnemyParmsBase")
		    , m_fp01(this, 'fp01', "要旋回角度(deg)", 20.0f, 0.0f, 180.0f)       // 'required turning angle (deg)'
		    , m_fp02(this, 'fp02', "出現までの距離", 150.0f, 0.0f, 300.0f)       // 'distance to spawn'
		    , m_fp03(this, 'fp03', "雄たけび有効角度(deg)", 45.0f, 0.0f, 180.0f) // 'roar effective angle (deg)'
		    , m_fp04(this, 'fp04', "雄たけび有効範囲", 100.0f, 0.0f, 300.0f)     // 'roar effective range'
		    , m_fp05(this, 'fp05', "爆弾ダメージ", 200.0f, 0.0f, 600.0f)         // 'bomb damage'
		    , m_fp06(this, 'fp06', "見えない範囲", 70.0f, 0.0f, 200.0f)          // 'invisible range'
		    , m_fp07(this, 'fp07', "旋回終了角度", 10.0f, 0.0f, 180.0f)          // 'turning end angle'
		    , m_fp08(this, 'fp08', "踏み潰し範囲", 45.0f, 0.0f, 200.0f)          // 'trampling range'
		    , m_fp09(this, 'fp09', "出現振り払い範囲", 100.0f, 0.0f, 200.0f)     // 'appearance shake-off range'
		    , m_fp10(this, 'fp10', "出現振り払い力", 200.0f, 0.0f, 400.0f)       // 'appearance shake-off power'
		    , m_fp11(this, 'fp11', "歩きアニメスピード", 1.0f, 0.0f, 3.0f)       // 'walking anime speed'
		    , m_fp12(this, 'fp12', "死雄たけび率", 0.0f, 0.0f, 1.0f)             // 'death rate'
		    , m_fp13(this, 'fp13', "フリック雄たけび率", 0.5f, 0.0f, 1.0f)       // 'flick shout rate'
		    , m_fp14(this, 'fp14', "白ピクミン", 300.0f, 0.0f, 1000.0f)          // 'white pikmin'
		    , m_fp15(this, 'fp15', "bigスケール", 1.0f, 1.0f, 2.0f)              // 'big scale'
		    , m_fp16(this, 'fp16', "bigライフ", 100.0f, 0.0f, 9999.0f)           // 'big life'
		    , m_fp17(this, 'fp17', "big速度", 80.0f, 0.0f, 1000.0f)              // 'big speed'
		    , m_fp18(this, 'fp18', "big回転速度率", 0.1f, 0.0f, 1.0f)            // 'big rotation speed rate'
		    , m_fp19(this, 'fp19', "big回転最大速度", 10.0f, 0.0f, 360.0f)       // 'big rotation maximum speed'
		    , m_fp20(this, 'fp20', "big攻撃可能\角度", 15.0f, 0.0f, 180.0f)      // 'big attack angle'
		    , m_fp21(this, 'fp21', "big攻撃ヒット範囲", 70.0f, 0.0f, 1000.0f)    // 'big attack hit range'
		    , m_ip01(this, 'ip01', "潜伏までの期間", 500, 0, 2000)               // 'period of incubation'
		    , m_ip02(this, 'ip02', "出現までの期間", 200, 0, 1000)               // 'time to appearance'
		    , m_ip03(this, 'ip03', "爆弾ダメージ時間", 10, 0, 200)               // 'bomb damage time'
		{
		}

		Parm<f32> m_fp01; // _804
		Parm<f32> m_fp02; // _82C
		Parm<f32> m_fp03; // _854
		Parm<f32> m_fp04; // _87C
		Parm<f32> m_fp05; // _8A4
		Parm<f32> m_fp06; // _8CC
		Parm<f32> m_fp07; // _8F4
		Parm<f32> m_fp08; // _91C
		Parm<f32> m_fp09; // _944
		Parm<f32> m_fp10; // _96C
		Parm<f32> m_fp11; // _994
		Parm<f32> m_fp12; // _9BC
		Parm<f32> m_fp13; // _9E4
		Parm<f32> m_fp14; // _A0C
		Parm<f32> m_fp15; // _A34
		Parm<f32> m_fp16; // _A5C
		Parm<f32> m_fp17; // _A84
		Parm<f32> m_fp18; // _AAC
		Parm<f32> m_fp19; // _AD4
		Parm<f32> m_fp20; // _AFC
		Parm<f32> m_fp21; // _B24
		Parm<int> m_ip01; // _B4C
		Parm<int> m_ip02; // _B74
		Parm<int> m_ip03; // _B9C
	};

	Parms()
	{
		_BC8 = 0;
		_BC9 = 0;
		_BCA = 1;
		_BCB = 1;
		_BCC = 0;
		_BD0 = 3.0f;
	}

	virtual void read(Stream& stream) // _08 (weak)
	{
		CreatureParms::read(stream);
		m_general.read(stream);
		m_properParms.read(stream);
	}

	// _00-_7F8	= EnemyParmsBase
	ProperParms m_properParms; // _7F8
	u8 _BC8;                   // _BC8
	u8 _BC9;                   // _BC9
	u8 _BCA;                   // _BCA
	u8 _BCB;                   // _BCB
	u8 _BCC;                   // _BCC
	f32 _BD0;                  // _BD0
};

struct ProperAnimator : public EnemyBlendAnimatorBase {
	virtual ~ProperAnimator(); // _08 (weak)

	// _00      = VTBL
	// _00-_60  = EnemyBlendAnimatorBase
	SysShape::Animator m_specificAnimator;
};

/////////////////////////////////////////////////////////////////
// STATE MACHINE DEFINITIONS

struct FSM : public EnemyStateMachine {
	virtual void init(EnemyBase*); // _08

	// _00		= VTBL
	// _00-_1C	= EnemyStateMachine
};

struct State : public EnemyFSMState {
	// _00		= VTBL
	// _00-_10 	= EnemyFSMState
};

struct StateAppear : public State {
	StateAppear(int);

	virtual void init(EnemyBase*, StateArg*); // _08
	virtual void exec(EnemyBase*);            // _0C

	// _00		= VTBL
	// _00-_10 	= EnemyFSMState
};

struct StateAttack : public State {
	StateAttack(int);

	virtual void init(EnemyBase*, StateArg*); // _08
	virtual void exec(EnemyBase*);            // _0C
	virtual void cleanup(EnemyBase*);         // _10

	// _00		= VTBL
	// _00-_10 	= EnemyFSMState
};

struct StateCaution : public State {
	StateCaution(int);

	virtual void init(EnemyBase*, StateArg*); // _08
	virtual void exec(EnemyBase*);            // _0C

	// _00		= VTBL
	// _00-_10 	= EnemyFSMState
};

struct StateDamage : public State {
	StateDamage(int);

	virtual void init(EnemyBase*, StateArg*); // _08
	virtual void exec(EnemyBase*);            // _0C
	virtual void cleanup(EnemyBase*);         // _10

	// _00		= VTBL
	// _00-_10 	= EnemyFSMState
};

struct StateDead : public State {
	StateDead(int);

	virtual void init(EnemyBase*, StateArg*); // _08
	virtual void exec(EnemyBase*);            // _0C
	virtual void cleanup(EnemyBase*);         // _10

	// _00		= VTBL
	// _00-_10 	= EnemyFSMState
};

struct StateEat : public State {
	StateEat(int);

	virtual void init(EnemyBase*, StateArg*); // _08
	virtual void exec(EnemyBase*);            // _0C

	// _00		= VTBL
	// _00-_10 	= EnemyFSMState
};

struct StateFlick : public State {
	StateFlick(int);

	virtual void init(EnemyBase*, StateArg*); // _08
	virtual void exec(EnemyBase*);            // _0C
	virtual void cleanup(EnemyBase*);         // _10

	// _00		= VTBL
	// _00-_10 	= EnemyFSMState
};

struct StateHide : public State {
	StateHide(int);

	virtual void init(EnemyBase*, StateArg*); // _08
	virtual void exec(EnemyBase*);            // _0C
	virtual void cleanup(EnemyBase*);         // _10

	// _00		= VTBL
	// _00-_10 	= EnemyFSMState
};

struct StateHideWait : public State {
	StateHideWait(int);

	virtual void init(EnemyBase*, StateArg*); // _08
	virtual void exec(EnemyBase*);            // _0C
	virtual void cleanup(EnemyBase*);         // _10

	// _00		= VTBL
	// _00-_10 	= EnemyFSMState
};

struct StateSwallow : public State {
	StateSwallow(int);

	virtual void init(EnemyBase*, StateArg*); // _08
	virtual void exec(EnemyBase*);            // _0C

	// _00		= VTBL
	// _00-_10 	= EnemyFSMState
};

struct StateTurn : public State {
	StateTurn(int);

	virtual void init(EnemyBase*, StateArg*); // _08
	virtual void exec(EnemyBase*);            // _0C

	// _00		= VTBL
	// _00-_10 	= EnemyFSMState
};

struct StateWalk : public State {
	StateWalk(int);

	virtual void init(EnemyBase*, StateArg*); // _08
	virtual void exec(EnemyBase*);            // _0C
	virtual void cleanup(EnemyBase*);         // _10

	// _00		= VTBL
	// _00-_10 	= EnemyFSMState
};

struct StateWarCry : public State {
	StateWarCry(int);

	virtual void init(EnemyBase*, StateArg*); // _08
	virtual void exec(EnemyBase*);            // _0C
	virtual void cleanup(EnemyBase*);         // _10

	// _00		= VTBL
	// _00-_10 	= EnemyFSMState
};
/////////////////////////////////////////////////////////////////
} // namespace KingChappy
} // namespace Game

#endif
