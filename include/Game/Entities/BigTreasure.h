#ifndef _GAME_ENTITIES_BIGTREASURE_H
#define _GAME_ENTITIES_BIGTREASURE_H

#include "Game/EnemyStateMachine.h"
#include "Game/EnemyAnimatorBase.h"
#include "Game/EnemyParmsBase.h"
#include "Game/EnemyMgrBase.h"
#include "Game/JointFuncs.h"
#include "Game/EnemyBase.h"
#include "efx/TOoota.h"
#include "efx/TDama.h"
#include "JSystem/J3D/J3DGXColor.h"
#include "Sys/MatBaseAnimation.h"
#include "Sys/MatBaseAnimator.h"
#include "Collinfo.h"

/**
 * --Header for Titan Dweevil (BigTreasure)--
 */

namespace Game {
struct IKSystemMgr;
struct IKSystemParms;

namespace BigTreasure {
struct BigTreasureGroundCallBack;
struct BigTreasureShadowMgr;
struct BigTreasureAttackMgr;
struct FSM;

struct EyeColor {
	inline void set(f32 _r, f32 _g, f32 _b)
	{
		mRgb[0] = _r;
		mRgb[1] = _g;
		mRgb[2] = _b;
	}

	inline EyeColor& operator=(const EyeColor& other)
	{
		mRgb[0] = other.mRgb[0];
		mRgb[1] = other.mRgb[1];
		mRgb[2] = other.mRgb[2];
		return *this;
	}

	inline void operator=(EyeColor& other)
	{
		mRgb[0] = other.mRgb[0];
		mRgb[1] = other.mRgb[1];
		mRgb[2] = other.mRgb[2];
	}

	f32 mRgb[3]; // _00, r=0, g=1, b=2
};

enum StateID {
	BIGTREASURE_NULL      = -1,
	BIGTREASURE_Dead      = 0,
	BIGTREASURE_Stay      = 1,
	BIGTREASURE_Land      = 2,
	BIGTREASURE_Wait      = 3,
	BIGTREASURE_ItemWait  = 4,
	BIGTREASURE_Flick     = 5,
	BIGTREASURE_PreAttack = 6,
	BIGTREASURE_Attack    = 7,
	BIGTREASURE_PutItem   = 8,
	BIGTREASURE_DropItem  = 9,
	BIGTREASURE_Walk      = 10,
	BIGTREASURE_ItemWalk  = 11,
	BIGTREASURE_Count,
};

enum AttackID {
	BIGATTACK_NULL  = -1,
	BIGATTACK_Troll = 0,
	BIGATTACK_Fire  = 1,
	BIGATTACK_Piki  = 2,
	BIGATTACK_Water = 3,
	BIGATTACK_Count = 4,
	BIGATTACK_Gas   = 5
};

enum EyeColorTargetID {
	EYECOLOR_Dark  = 0,
	EYECOLOR_Light = 1,
};

struct Obj : public EnemyBase {
	Obj();

	//////////////// VTABLE
	virtual void onInit(CreatureInitArg* settings);          // _30
	virtual void onKill(CreatureKillArg* settings);          // _34
	virtual void doDirectDraw(Graphics& gfx);                // _50
	virtual void inWaterCallback(WaterBox* wb);              // _84 (weak)
	virtual void outWaterCallback();                         // _88 (weak)
	virtual void getShadowParam(ShadowParam& settings);      // _134
	virtual ~Obj() { }                                       // _1BC (weak)
	virtual void setInitialSetting(EnemyInitialParamBase*);  // _1C4
	virtual void doUpdate();                                 // _1CC
	virtual void doUpdateCommon();                           // _1D0
	virtual void doAnimationUpdateAnimator();                // _1D8
	virtual void doAnimationCullingOff();                    // _1DC
	virtual void doDebugDraw(Graphics&);                     // _1EC
	virtual void changeMaterial();                           // _200
	virtual EnemyTypeID::EEnemyTypeID getEnemyTypeID();      // _258 (weak)
	virtual void getThrowupItemPosition(Vector3f*);          // _268
	virtual void getThrowupItemVelocity(Vector3f*);          // _26C
	virtual void throwupItemInDeathProcedure();              // _270 (weak)
	virtual bool damageCallBack(Creature*, f32, CollPart*);  // _278
	virtual bool hipdropCallBack(Creature*, f32, CollPart*); // _284
	virtual void doStartStoneState();                        // _2A4
	virtual void doFinishStoneState();                       // _2A8
	virtual f32 getDamageCoeStoneState();                    // _2AC (weak)
	virtual void doStartMovie();                             // _2F0
	virtual void doEndMovie();                               // _2F4
	virtual void setFSM(FSM*);                               // _2F8
	//////////////// VTABLE END

	void resetAttackLimitTimer();
	bool isAttackLimitTime();
	void getTargetPosition();
	void createIKSystem();
	void setupIKSystem();
	void setIKParameter();
	void setIKSystemTargetPosition(Vector3f&);
	void updateIKSystem();
	void doAnimationIKSystem();
	void finishAnimationIKSystem();
	void startProgramedIK();
	void startIKMotion();
	void finishIKMotion();
	void forceFinishIKMotion();
	bool isFinishIKMotion();
	void startBlendMotion();
	void finishBlendMotion();
	void checkJointScaleOn();
	void getTraceCentrePosition();
	void getJointPositionPtr(int, int);
	void createShadowSystem();
	void setupShadowSystem();
	void doAnimationShadowSystem();
	void setupCollision();
	void setupTreasure();
	void updateTreasure();
	void dropTreasure();
	bool dropTreasure(int);
	bool isCapturedTreasure();
	bool isCapturedTreasure(int);
	void getCapturedTreasureNum();
	void addTreasureDamage(int, f32);
	void flickStickCollPartPikmin(CollPart*);
	void releaseItemLoozy();
	void createAttack();
	void setupAttack();
	void updateAttack();
	void startAttack();
	void finishAttack();
	void setTreasureAttack();
	int getPreAttackAnimIndex();
	int getAttackAnimIndex();
	int getPutItemAnimIndex();
	int getFireAttackAnimIndex();
	f32 getPreAttackTimeMax();
	f32 getAttackTimeMax();
	bool isNormalAttack(int);
	void resetMaterialColor();
	void resetTargetMatBodyColor(bool);
	void resetCurrentMatBodyColor();
	void resetTargetEyeMatColor();
	void resetCurrentMatEyeColor();
	void setMatEyeAnimSpeed();
	void setAttackMaterialColor(bool);
	void updateMaterialColor();
	void startBlendAnimation(int, bool);
	void endBlendAnimation();
	int getCurrAnimationIndex();
	void startBossChargeBGM();
	void startBossAttackBGM();
	void finishBossAttackBGM();
	void startBossFlickBGM();
	void startBossItemDropBGM();
	void updateBossBGM();
	void resetBossAppearBGM();
	void setBossAppearBGM();
	void createEffect();
	void setupEffect();
	void createOnGroundEffect(int, WaterBox*);
	void createOffGroundEffect(int, WaterBox*);
	void startTreasurePinchSmoke(int);
	void finishTreasurePinchSmoke(int);
	void createDropTreasureEffect(int);
	void createAppearBodyEffect();
	void createAppearLegEffect(int);
	void createDeadBombLegEffect(int);
	void createDeadBombBodyEffect();
	void startDeadBubbleLegEffect(int);
	void finishDeadBubbleLegEffect(int);
	void startDeadBubbleBodyEffect();
	void finishDeadBubbleBodyEffect();
	void startDeadBubbleMouthEffect();
	void finishDeadBubbleMouthEffect();
	void createChangeMaterialEffect();
	void createDeadBombFootEffect();
	void startShineParticleEffect();
	void finishShineParticleEffect();
	void effectDrawOn();
	void effectDrawOff();
	void subShadowScale();
	bool startBigTreasureBootUpDemo();

	void setupBigTreasureCollision();
	void createPikiBaby(EnemyTypeID::EEnemyTypeID type, u8 count, Vector3f& position);

	static bool sHasDoneTrollAttack;

	// _00 		= VTBL
	// _00-_2BC	= EnemyBase
	FSM* mFsm;                                  // _2BC
	f32 mStateTimer;                            // _2C0
	f32 mAttackLimitTimer;                      // _2C4
	StateID mNextState;                         // _2C8
	Vector3f mTargetPosition;                   // _2CC
	f32 mShadowScale;                           // _2D8
	bool mIsFastMatAnim;                        // _2DC
	bool mIsWeaponAttacked[0x4];                // _2DD, used to determine if the weapon should shake
	IKSystemMgr* mIkSystemMgr;                  // _2E4
	IKSystemParms* mIkSystemParms;              // _2E8
	BigTreasureGroundCallBack* mGroundCallBack; // _2EC
	BigTreasureShadowMgr* mShadowMgr;           // _2F0
	BigTreasureAttackMgr* mAttackMgr;           // _2F4
	Vector3f mKosiJointPos;                     // _2F8
	Vector3f mJointPositions[4][4];             // _304
	Pellet* mTreasures[4];                      // _3C4, elec / fire / gas / water
	Pellet* mLouie;                             // _3D4, King of Bugs
	f32 mTreasureHealth[4];                     // _3D8, elec / fire / gas / water
	f32 mTreasureShakeAngle[4];                 // _3E8, used to make treasures shake while being attacked
	CollPart* mTreasureCollParts[4];            // _3F8, elec / fire / gas / water
	int mAttackIndex;                           // _408, see AttackID enum
	J3DGXColorS10 mTargetMatBodyColor;          // _40C
	J3DGXColorS10 mCurrMatBodyColor;            // _414
	int mTargetEyeColorIdx;                     // _41C, 0 = going to dark, 1 = going to light (indexes _438, _45C)
	f32 mClusterEyeAnimSpeeds[3];               // _420, r=0, g=1, b=2
	f32 mSideEyeAnimSpeeds[3];                  // _42C, r=0, g=1, b=2
	EyeColor mTargetClusterEyeColor[2];         // _438, 0 = dark, 1 = light, bounces between
	EyeColor mCurrClusterEyeColor;              // _450
	EyeColor mTargetSideEyeColor[2];            // _45C, 0 = dark, 1 = light, bounces between
	EyeColor mCurrSideEyeColor;                 // _474
	efx::TOootaFoot* mFootFX[4];                // _480
	efx::TDamaFootw* mFootWFX[4];               // _490
	efx::TDamaSmoke* mTreasureSmokeFX[4];       // _4A0
	efx::TOootaStartBody* mStartBodyFX;         // _4B0
	efx::TOootaStartOta* mStartTreasureFX[4];   // _4B4
	efx::TOootaStartLeg* mStartLegFX[4][3];     // _4C4
	efx::TOootaDeadLeg* mDeadLegFX[4][4];       // _4F4, leg bubble effect on death
	efx::TOootaDeadBody* mDeadBodyFX;           // _534, body bubble effect on death
	efx::TOootaDeadAwa* mDeadAwaFX;             // _538, mouth bubble effect on death
	efx::TOootaChangeLeg* mChangeLegFX[4][4];   // _53C
	efx::TOootaChangeBody* mChangeBodyFX;       // _57C
	efx::TOootaParticle* mShineParticleFX;      // _580
	                                            // _584 = PelletView
};

struct Mgr : public EnemyMgrBase {
	Mgr(int objLimit, u8 modelType);

	//////////////// VTABLE
	// virtual ~Mgr();                                     // _58 (weak)
	virtual void createObj(int);                       // _A0
	virtual EnemyBase* getEnemy(int idx);              // _A4
	virtual void doAlloc();                            // _A8
	virtual SysShape::Model* createModel();            // _B0
	virtual void loadModelData();                      // _C8
	virtual EnemyTypeID::EEnemyTypeID getEnemyTypeID() // _AC (weak)
	{
		return EnemyTypeID::EnemyID_BigTreasure;
	}
	virtual J3DModelData* doLoadBmd(void* filename) // _D4 (weak)
	{
		return J3DModelLoaderDataBase::load(filename, 0x01240030);
	}
	//////////////// VTABLE END

	// _00 		= VTBL
	// _00-_44	= EnemyMgrBase
	Obj* m_obj; // _48
};

struct Parms : public EnemyParmsBase {
	struct ProperParms : public Parameters {
		ProperParms()
		    : Parameters(nullptr, "EnemyParmsBase")
		    , mBaseFactor(this, 'fp01', "?????", 3.0f, 0.0f, 10.0f)                 // 'base factor'
		    , mRaiseDecelFactor(this, 'fp02', "??????", -0.2f, -5.0f, 5.0f)         // 'raising deceleration factor'
		    , mDownwardDecelFactor(this, 'fp03', "??????", 0.5f, -5.0f, 5.0f)       // 'downward acceleration factor'
		    , mMinReducedAccelFactor(this, 'fp04', "???????", -2.0f, -10.0f, 10.0f) // 'min reduced acceleration factor'
		    , mMaxDecelAccelFactor(this, 'fp05', "???????", 10.0f, -10.0f, 10.0f)   // 'max deceleration acceleration factor'
		    , mLegSwing(this, 'fp06', "??????", 120.0f, 0.0f, 200.0f)               // 'leg swing'
		    , mElectricityWaitTime(this, 'fp10', "?\???(??)", 2.5f, 0.0f, 10.0f)    // 'wait time (electricity)'
		    , mFireWaitTime1(this, 'fp11', "?\???(?:1)", 2.8f, 0.0f, 10.0f)         // 'wait time (fire:1)'
		    , mFireWaitTime2(this, 'fp31', "?\???(?:2)", 2.5f, 0.0f, 10.0f)         // 'wait time (fire:2)'
		    , mGasWaitTime(this, 'fp12', "?\???(??)", 2.5f, 0.0f, 10.0f)            // 'wait time (gas)'
		    , mWaterWaitTime(this, 'fp13', "?\???(?)", 2.5f, 0.0f, 10.0f)           // 'wait time (water)'
		    , mElecAttackTimeMax(this, 'fp20', "????(??)", 5.0f, 0.0f, 10.0f)       // 'attack time (electricity)'
		    , mFireAttackTimeMax(this, 'fp21', "????(?)", 5.0f, 0.0f, 10.0f)        // 'attack time (fire)'
		    , mGasAttackTimeMax(this, 'fp22', "????(??)", 5.0f, 0.0f, 10.0f)        // 'attack time (gas)'
		    , mWaterAttackTimeMax(this, 'fp23', "????(?)", 5.0f, 0.0f, 10.0f)       // 'attack time (water)'

		    , mBounceCoefficient1_1(this, 'fe00', "????(1-1)", 0.75f, 0.0f, 1.0f)           // 'bounce coefficient (1-1)'
		    , mFrictionCoefficient1_1(this, 'fe01', "????(1-1)", 0.65f, 0.0f, 1.0f)         // 'friction coefficient (1-1)'
		    , mBaseMuzzleVelocityXZ1_1(this, 'fe02', "XZ??Base(1-1)", 100.0f, 0.0f, 500.0f) // 'XZ initial velocity Base (1-1)'
		    , mRandMuzzleVelocityXZ1_1(this, 'fe03', "XZ??Rand(1-1)", 220.0f, 0.0f, 500.0f) // 'XZ initial velocity Rand (1-1)'
		    , mBaseMuzzleVelocityY1_1(this, 'fe04', "Y??Base(1-1)", 170.0f, 0.0f, 500.0f)   // 'Y initial velocity Base (1-1)'
		    , mRandMuzzleVelocityY1_1(this, 'fe05', "Y??Rand(1-1)", 200.0f, 0.0f, 500.0f)   // 'Y initial velocity Rand (1-1)'
		    , mDischargeStart1_1(this, 'fe06', "????(1-1)", 2.7f, 0.0f, 5.0f)               // 'discharge start (1-1)'
		    , mChainInterval1_1(this, 'fe08', "????(1-1)", 0.02f, 0.0f, 1.0f)               // 'chain interval (1-1)'
		    , mDischargeCount1_1(this, 'fe07', "???(1-1)", 10, 0, 16)                       // 'number of discharges (1-1)'

		    , mBounceCoefficient1_2(this, 'fe10', "????(1-2)", 0.7f, 0.0f, 1.0f)            // 'bounce coefficient (1-2)'
		    , mFrictionCoefficient1_2(this, 'fe11', "????(1-2)", 0.65f, 0.0f, 1.0f)         // 'friction coefficient (1-2)'
		    , mBaseMuzzleVelocityXZ1_2(this, 'fe12', "XZ??Base(1-2)", 80.0f, 0.0f, 500.0f)  // 'XZ initial velocity Base (1-2)'
		    , mRandMuzzleVelocityXZ1_2(this, 'fe13', "XZ??Rand(1-2)", 250.0f, 0.0f, 500.0f) // 'XZ initial velocity Rand (1-2)'
		    , mBaseMuzzleVelocityY1_2(this, 'fe14', "Y??Base(1-2)", 350.0f, 0.0f, 500.0f)   // 'Y initial velocity Base (1-2)'
		    , mRandMuzzleVelocityY1_2(this, 'fe15', "Y??Rand(1-2)", 100.0f, 0.0f, 500.0f)   // 'Y initial velocity Rand (1-2)'
		    , mDischargeStart1_2(this, 'fe16', "????(1-2)", 4.5f, 0.0f, 5.0f)               // 'discharge start (1-2)'
		    , mChainInterval1_2(this, 'fe18', "????(1-2)", 0.02f, 0.0f, 1.0f)               // 'chain interval (1-2)'
		    , mDischargeCount1_2(this, 'fe17', "???(1-2)", 12, 0, 16)                       // 'number of discharges (1-2)'

		    , mBounceCoefficient2_1(this, 'fe20', "????(2-1)", 0.97f, 0.0f, 1.0f)          // 'bounce coefficient (2-1)'
		    , mFrictionCoefficient2_1(this, 'fe21', "????(2-1)", 0.75f, 0.0f, 1.0f)        // 'friction coefficient (2-1)'
		    , mBaseMuzzleVelocityXZ2_1(this, 'fe22', "XZ??Base(2-1)", 60.0f, 0.0f, 500.0f) // 'XZ initial velocity Base (2-1)'
		    , mRandMuzzleVelocityXZ2_1(this, 'fe23', "XZ??Rand(2-1)", 70.0f, 0.0f, 500.0f) // 'XZ initial velocity Rand (2-1)'
		    , mBaseMuzzleVelocityY2_1(this, 'fe24', "Y??Base(2-1)", 350.0f, 0.0f, 500.0f)  // 'Y initial velocity Base (2-1)'
		    , mRandMuzzleVelocityY2_1(this, 'fe25', "Y??Rand(2-1)", 100.0f, 0.0f, 500.0f)  // 'Y initial velocity Rand (2-1)'
		    , mDischargeStart2_1(this, 'fe26', "????(2-1)", 0.5f, 0.0f, 5.0f)              // 'discharge start (2-1)'
		    , mChainInterval2_1(this, 'fe28', "????(2-1)", 0.25f, 0.0f, 1.0f)              // 'chain interval (2-1)'
		    , mDischargeCount2_1(this, 'fe27', "???(2-1)", 8, 0, 16)                       // 'number of discharges (2-1)'

		    , mBounceCoefficient2_2(this, 'fe30', "????(2-2)", 0.2f, 0.0f, 1.0f)            // 'bounce coefficient (2-2)'
		    , mFrictionCoefficient2_2(this, 'fe31', "????(2-2)", 0.985f, 0.0f, 1.0f)        // 'friction coefficient (2-2)'
		    , mBaseMuzzleVelocityXZ2_2(this, 'fe32', "XZ??Base(2-2)", 100.0f, 0.0f, 500.0f) // 'XZ initial velocity Base (2-2)'
		    , mRandMuzzleVelocityXZ2_2(this, 'fe33', "XZ??Rand(2-2)", 90.0f, 0.0f, 500.0f)  // 'XZ initial velocity Rand (2-2)'
		    , mBaseMuzzleVelocityY2_2(this, 'fe34', "Y??Base(2-2)", 70.0f, 0.0f, 500.0f)    // 'Y initial velocity Base (2-2)'
		    , mRandMuzzleVelocityY2_2(this, 'fe35', "Y??Rand(2-2)", 20.0f, 0.0f, 500.0f)    // 'Y initial velocity Rand (2-2)'
		    , mDischargeStart2_2(this, 'fe36', "????(2-2)", 0.2f, 0.0f, 5.0f)               // 'discharge start (2-2)'
		    , mChainInterval2_2(this, 'fe38', "????(2-2)", 0.15f, 0.0f, 1.0f)               // 'chain interval (2-2)'
		    , mDischargeCount2_2(this, 'fe37', "???(2-2)", 14, 0, 16)                       // 'number of discharges (2-2)'

		    , mPatternCheckFlame(this, 'fe99', "????????", 0, 0, 4)      // 'pattern check'
		    , mFlameScale1(this, 'ff00', "??????(1)", 1.0f, 0.5f, 5.0f)  // 'flame scale (1)'
		    , mFlameScale2(this, 'ff10', "??????(2)", 1.25f, 0.5f, 5.0f) // 'flame scale (2)'

		    , mPatternCheckRotation(this, 'fg99', "????????", 0, 0, 2)         // 'pattern check'
		    , mRotationSpeed1(this, 'fg00', "??????(1)", 0.015f, 0.01f, 0.03f) // 'rotation speed (1)'
		    , mRotationSpeed2(this, 'fg10', "??????(2)", 0.02f, 0.01f, 0.03f)  // 'rotation speed (2)'
		    , mReversalTime2_1(this, 'fg30', "????(2-1)", 30.0f, 0.0f, 30.0f)  // 'reversal time (2-1)'
		    , mReversalTime2_2(this, 'fg40', "????(2-2)", 2.0f, 0.0f, 30.0f)   // 'reversal time (2-2)'

		    , mPatternCheckWater(this, 'fg99', "????????", 0, 0, 3)                // 'pattern check'
		    , mWaterDischargeInterval1(this, 'fw00', "????(1)", 0.5f, 0.1f, 1.0f)  // 'water discharge interval (1)'
		    , mRandomAngle1(this, 'fw01', "??????(1)", 0.5f, 0.0f, 1.0f)           // 'random angle (1)'
		    , mRandomDistance1(this, 'fw02', "??????(1)", 100.0f, 0.0f, 500.0f)    // 'random distance (1)'
		    , mWaterDischargeInterval2(this, 'fw10', "????(2)", 0.25f, 0.1f, 1.0f) // 'water discharge interval (2)
		    , mRandomAngle2(this, 'fw11', "??????(2)", 0.4f, 0.0f, 1.0f)           // 'random angle (2)'
		    , mRandomDistance2(this, 'fw12', "??????(2)", 50.0f, 0.0f, 500.0f)     // 'random distance (2)'
		    , mPatternCheck4(this, 'fw99', "????????", 0, 0, 2)                    // 'pattern check'
		{
		}

		Parm<f32> mBaseFactor;              // _804
		Parm<f32> mRaiseDecelFactor;        // _82C
		Parm<f32> mDownwardDecelFactor;     // _854
		Parm<f32> mMinReducedAccelFactor;   // _87C
		Parm<f32> mMaxDecelAccelFactor;     // _8A4
		Parm<f32> mLegSwing;                // _8CC
		Parm<f32> mElectricityWaitTime;     // _8F4
		Parm<f32> mFireWaitTime1;           // _91C
		Parm<f32> mFireWaitTime2;           // _944
		Parm<f32> mGasWaitTime;             // _96C
		Parm<f32> mWaterWaitTime;           // _994
		Parm<f32> mElecAttackTimeMax;       // _9BC, fp20
		Parm<f32> mFireAttackTimeMax;       // _9E4, fp21
		Parm<f32> mGasAttackTimeMax;        // _A0C, fp22
		Parm<f32> mWaterAttackTimeMax;      // _A34, fp23
		Parm<f32> mBounceCoefficient1_1;    // _A5C
		Parm<f32> mFrictionCoefficient1_1;  // _A84
		Parm<f32> mBaseMuzzleVelocityXZ1_1; // _AAC
		Parm<f32> mRandMuzzleVelocityXZ1_1; // _AD4
		Parm<f32> mBaseMuzzleVelocityY1_1;  // _AFC
		Parm<f32> mRandMuzzleVelocityY1_1;  // _B24
		Parm<f32> mDischargeStart1_1;       // _B4C
		Parm<f32> mChainInterval1_1;        // _B74
		Parm<int> mDischargeCount1_1;       // _B9C
		Parm<f32> mBounceCoefficient1_2;    // _BC4
		Parm<f32> mFrictionCoefficient1_2;  // _BEC
		Parm<f32> mBaseMuzzleVelocityXZ1_2; // _C14
		Parm<f32> mRandMuzzleVelocityXZ1_2; // _C3C
		Parm<f32> mBaseMuzzleVelocityY1_2;  // _C64
		Parm<f32> mRandMuzzleVelocityY1_2;  // _C8C
		Parm<f32> mDischargeStart1_2;       // _CB4
		Parm<f32> mChainInterval1_2;        // _CDC
		Parm<int> mDischargeCount1_2;       // _D04
		Parm<f32> mBounceCoefficient2_1;    // _D2C
		Parm<f32> mFrictionCoefficient2_1;  // _D54
		Parm<f32> mBaseMuzzleVelocityXZ2_1; // _D7C
		Parm<f32> mRandMuzzleVelocityXZ2_1; // _DA4
		Parm<f32> mBaseMuzzleVelocityY2_1;  // _DCC
		Parm<f32> mRandMuzzleVelocityY2_1;  // _DF4
		Parm<f32> mDischargeStart2_1;       // _E1C
		Parm<f32> mChainInterval2_1;        // _E44
		Parm<int> mDischargeCount2_1;       // _E6C
		Parm<f32> mBounceCoefficient2_2;    // _E94
		Parm<f32> mFrictionCoefficient2_2;  // _EBC
		Parm<f32> mBaseMuzzleVelocityXZ2_2; // _EE4
		Parm<f32> mRandMuzzleVelocityXZ2_2; // _F0C
		Parm<f32> mBaseMuzzleVelocityY2_2;  // _F34
		Parm<f32> mRandMuzzleVelocityY2_2;  // _F5C
		Parm<f32> mDischargeStart2_2;       // _F84
		Parm<f32> mChainInterval2_2;        // _FAC
		Parm<int> mDischargeCount2_2;       // _FD4
		Parm<int> mPatternCheckFlame;       // _FFC
		Parm<f32> mFlameScale1;             // _1024
		Parm<f32> mFlameScale2;             // _104C
		Parm<int> mPatternCheckRotation;    // _1074
		Parm<f32> mRotationSpeed1;          // _109C
		Parm<f32> mRotationSpeed2;          // _10C4
		Parm<f32> mReversalTime2_1;         // _10EC
		Parm<f32> mReversalTime2_2;         // _1114
		Parm<int> mPatternCheckWater;       // _113C
		Parm<f32> mWaterDischargeInterval1; // _1164
		Parm<f32> mRandomAngle1;            // _118C
		Parm<f32> mRandomDistance1;         // _11B4
		Parm<f32> mWaterDischargeInterval2; // _11DC
		Parm<f32> mRandomAngle2;            // _1204
		Parm<f32> mRandomDistance2;         // _122C
		Parm<int> mPatternCheck4;           // _1254
	};

	Parms() { }

	virtual void read(Stream& stream) // _08 (weak)
	{
		CreatureParms::read(stream);
		m_general.read(stream);
		m_properParms.read(stream);
	}

	// _00-_7F8	= EnemyParmsBase
	ProperParms m_properParms; // _7F8
};

enum AnimID {
	BIGTREASUREANIM_NULL    = -1,
	BIGTREASUREANIM_Appear  = 0,
	BIGTREASUREANIM_Appear2 = 1,
	BIGTREASUREANIM_Wait1   = 2,

	// Fire attacks (forward, right, left, back)
	BIGTREASUREANIM_PreAttackF = 3,
	BIGTREASUREANIM_AttackF    = 4,
	BIGTREASUREANIM_AttackEndF = 5,

	BIGTREASUREANIM_PreAttackFR = 6,
	BIGTREASUREANIM_AttackFR    = 7,
	BIGTREASUREANIM_AttackEndFR = 8,

	BIGTREASUREANIM_PreAttackFL = 9,
	BIGTREASUREANIM_AttackFL    = 10,
	BIGTREASUREANIM_AttackEndFL = 11,

	BIGTREASUREANIM_PreAttackFB = 12,
	BIGTREASUREANIM_AttackFB    = 13,
	BIGTREASUREANIM_AttackEndFB = 14,

	// Water attack
	BIGTREASUREANIM_PreAttackW = 15,
	BIGTREASUREANIM_AttackW    = 16,
	BIGTREASUREANIM_AttackEndW = 17,

	// Gas attack
	BIGTREASUREANIM_PreAttackG = 18,
	BIGTREASUREANIM_AttackG    = 19,
	BIGTREASUREANIM_AttackEndG = 20,

	// Elec attack
	BIGTREASUREANIM_PreAttackE = 21,
	BIGTREASUREANIM_AttackE    = 22,
	BIGTREASUREANIM_AttackEndE = 23,

	BIGTREASUREANIM_DropItem = 24,
	BIGTREASUREANIM_Wait2    = 25,
	BIGTREASUREANIM_Flick    = 26,
	BIGTREASUREANIM_Dead     = 27,
	BIGTREASUREANIM_Move1    = 28,
	BIGTREASUREANIM_Wait2_2  = 29, // repeat of Wait2?

	// PikiBaby attack
	BIGTREASUREANIM_PreAttackP = 30,
	BIGTREASUREANIM_AttackP    = 31,
	BIGTREASUREANIM_AttackEndP = 32,

	BIGTREASUREANIM_AnimCount, // 33
};

struct ProperAnimator : public EnemyAnimatorBase {
	virtual ~ProperAnimator(); // _08 (weak)

	// _00 		= VTBL
	// _00-_10	= EnemyAnimatorBase
};

struct BigTreasureShadowMgr;

struct BigTreasureGroundCallBack : public JointGroundCallBack {
	virtual void invokeOnGround(int, WaterBox*);  // _08
	virtual void invokeOffGround(int, WaterBox*); // _0C

	// _00	= VTBL
	Obj* m_obj; // _04
};

/////////////////////////////////////////////////////////////////
// ATTACK DEFINITIONS
enum BigTreasureFireTypes {
	BIGFIRE_Root = 0,
	BIGFIRE_Body = 1,
	BIGFIRE_Tail = 2,
	BIGFIRE_TypeCount, // 3
};

struct AttackShadowNode : public JointShadowNode {
	virtual ~AttackShadowNode(); // _08 (weak)

	void makeShadowSRT();

	// _00      = VTBL
	// _00-_24  = JointShadowNode
	u32 _24; // _24, unknown
	f32 _28; // _28
};

struct BigTreasureAttackData {
	inline BigTreasureAttackData()
	{
		mElecBounceFactor    = 0.75f;
		mElecFrictionFactor  = 0.65f;
		mElecBaseHSpeed      = 100.0f;
		mElecJitterHSpeed    = 220.0f;
		mElecBaseVSpeed      = 170.0f;
		mElecJitterVSpeed    = 200.0f;
		mElecScatterTime     = 2.7f;
		mElecChainOffsetTime = 0.1f;
		mElecMaxNodes        = 15;
		mElecPlacedNodes     = 0;
		mAttackScale         = 1.0f;
		mIsGasRotClockwise   = true;
		mGasArmNum           = 3;
		mGasRotationSpeed    = 0.02f;
		mGasReversalTime     = 30.0f;
		mWaterShotInterval   = 0.5f;
		mWaterJitterAngle    = 0.25f;
		mWaterJitterDistance = 50.0f;
	}

	// Elec attack params
	f32 mElecBounceFactor;    // _00
	f32 mElecFrictionFactor;  // _04
	f32 mElecBaseHSpeed;      // _08
	f32 mElecJitterHSpeed;    // _0C
	f32 mElecBaseVSpeed;      // _10
	f32 mElecJitterVSpeed;    // _14
	f32 mElecScatterTime;     // _18
	f32 mElecChainOffsetTime; // _1C
	int mElecMaxNodes;        // _20
	int mElecPlacedNodes;     // _24

	// Fire/gas attack params
	f32 mAttackScale;        // _28, for fire and gas
	bool mIsGasRotClockwise; // _2C
	int mGasArmNum;          // _30, 3 or 4
	f32 mGasRotationSpeed;   // _34
	f32 mGasReversalTime;    // _38

	// Water attack params
	f32 mWaterShotInterval;   // _3C
	f32 mWaterJitterAngle;    // _40, adds some random jitter on shoot angle so it's not directly at target
	f32 mWaterJitterDistance; // _44, adds some random jitter on shoot distance so it's not directly at target
};

struct BigTreasureElecAttack : public CNode {
	virtual ~BigTreasureElecAttack(); // _08 (weak)

	void update();

	// _00      = VTBL
	// _00-_18  = CNode
	Obj* m_owner;                        // _18
	BigTreasureAttackData* m_attackData; // _1C
	u8 _20;                              // _20
	Sys::Triangle* _24;                  // _24
	Vector3f _28;                        // _28
	Vector3f _34;                        // _34
	u32 _40;                             // _40, unknown
	efx::TChasePosPosLocalZScale3* _44;  // _44
	efx::TOootaElecparts* _48;           // _48
	efx::TChasePos2* _4C;                // _4C
};

struct BigTreasureFireAttack : public CNode {
	virtual ~BigTreasureFireAttack(); // _08 (weak)

	void update();

	// _00      = VTBL
	// _00-_18  = CNode
	Obj* m_owner;                        // _18
	BigTreasureAttackData* m_attackData; // _1C
	f32 _20;                             // _20
	Vector3f _24;                        // _24
	Vector3f _30;                        // _30
};

struct BigTreasureGasAttack : public CNode {
	virtual ~BigTreasureGasAttack(); // _08 (weak)

	void update();

	// _00      = VTBL
	// _00-_18  = CNode
	Obj* m_owner;                        // _18
	BigTreasureAttackData* m_attackData; // _1C
	f32 _20;                             // _20
	Vector3f _24;                        // _24
	Vector3f _30;                        // _30, gas emit position?
};

struct BigTreasureWaterAttack : public CNode {
	virtual ~BigTreasureWaterAttack(); // _08 (weak)

	void update();

	// _00      = VTBL
	// _00-_18  = CNode
	Obj* m_owner;                        // _18
	BigTreasureAttackData* m_attackData; // _1C
	Vector3f _20;                        // _24
	Vector3f _2C;                        // _30
	efx::TChasePos4* _38;                // _38, OootaWbomb?
};

struct BigTreasureAttackMgr {
	BigTreasureAttackMgr(Obj*);

	void init();
	void update();

	void startFireAttack();
	void startNewFireList();
	void updateFireAttack();
	void updateFireEmitPosition();
	void updateFireSePosition(BigTreasureFireAttack*, int);

	void startGasAttack();
	void startNewGasList();
	void updateGasAttack();
	void updateGasEmitPosition();
	void updateGasSePosition(BigTreasureGasAttack*, int);

	void startWaterAttack();
	void startNewWaterList();
	void updateWaterAttack();
	void updateWaterEmitPosition();
	void getWaterTargetCreature();

	void setElecAttackParameter();
	void startElecAttack();
	void updateElecAttack();
	void finishAttack();

	void addAttackShadow(BigTreasureWaterAttack*);
	void addAttackShadow(BigTreasureElecAttack*);
	void delAttackShadow(BigTreasureWaterAttack*);
	void delAttackShadow(BigTreasureElecAttack*);
	void updateAttackShadow();

	// unused/inlined:
	void setFireAttackParameter();
	void finishFireAttack();
	void setGasAttackParameter();
	void finishGasAttack();
	void setWaterAttackParameter();
	void finishWaterAttack();
	void startNewElecList();
	void finishElecAttack();

	bool canStartGasAttack();

	void startPikiAttack();
	void updatePikiAttack();

	static int sPikiBabyCount;

	bool mIsStartAttack[BIGATTACK_Count];          // _00
	Obj* mObj;                                     // _04
	f32 mAttackTimer1;                             // _08, used by all attacks
	f32 mAttackTimer2;                             // _0C, used by gas (reverse rot) and elec (discharge)
	CNode* mActiveFireList;                        // _10
	CNode* mFireAttackNodes;                       // _14
	efx::TOootaFire* mEfxFire;                     // _18
	Vector3f mFireEmitDirection;                   // _1C
	Vector3f mFireNodePosition[BIGFIRE_TypeCount]; // _28, indexed by BigTreasureFireTypes
	CNode* mActiveGasList;                         // _4C
	CNode* mGasAttackNodes;                        // _50
	f32 mGasAttackAngles[4];                       // _54
	Vector3f mGasEmitPosition;                     // _64
	Vector3f mGasSePosition[4];                    // _70
	efx::TOootaGas* mEfxGas[4];                    // _A0
	CNode* mActiveWaterList;                       // _B0
	CNode* mWaterAttackNodes;                      // _B4
	efx::TOootaWbomb* mEfxWaterBomb;               // _B8
	Vector3f mWaterEmitPosition;                   // _BC
	CNode* mActiveElecList;                        // _C8
	CNode* mElecAttackNodes;                       // _CC
	efx::TOootaElecLeg* mEfxElecLeg[4][3];         // _D0
	efx::TOootaElecAttack1* mEfxElecAttack1;       // _100
	efx::TOootaElecAttack2* mEfxElecAttack2;       // _104
	int mElecSENodeIDs[3];                         // _108
	JointShadowRootNode* mShadowRootNode;          // _114
	AttackShadowNode** mAttackShadowNodes;         // _118, array of 16 ptrs
	BigTreasureAttackData* mAttackData;            // _11C
};
/////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////
// STATE MACHINE DEFINITIONS
struct FSM : public EnemyStateMachine {
	virtual void init(EnemyBase*); // _08

	// _00		= VTBL
	// _00-_1C	= EnemyStateMachine
};

struct State : public EnemyFSMState {
	inline State(int stateID, const char* name)
	    : EnemyFSMState(stateID)
	{
		m_name = name;
	}

	// _00		= VTBL
	// _00-_10 	= EnemyFSMState
};

struct StateAttack : public State {
	inline StateAttack()
	    : State(BIGTREASURE_Attack, "attack")
	{
	}

	virtual void init(EnemyBase*, StateArg*); // _08
	virtual void exec(EnemyBase*);            // _0C
	virtual void cleanup(EnemyBase*);         // _10

	// _00		= VTBL
	// _00-_10 	= EnemyFSMState
};

struct StateDead : public State {
	inline StateDead()
	    : State(BIGTREASURE_Dead, "dead")
	{
	}

	virtual void init(EnemyBase*, StateArg*); // _08
	virtual void exec(EnemyBase*);            // _0C
	virtual void cleanup(EnemyBase*);         // _10

	// _00		= VTBL
	// _00-_10 	= EnemyFSMState
};

struct StateDropItem : public State {
	inline StateDropItem()
	    : State(BIGTREASURE_DropItem, "dropitem")
	{
	}

	virtual void init(EnemyBase*, StateArg*); // _08
	virtual void exec(EnemyBase*);            // _0C
	virtual void cleanup(EnemyBase*);         // _10

	// _00		= VTBL
	// _00-_10 	= EnemyFSMState
};

struct StateFlick : public State {
	inline StateFlick()
	    : State(BIGTREASURE_Flick, "flick")
	{
	}

	virtual void init(EnemyBase*, StateArg*); // _08
	virtual void exec(EnemyBase*);            // _0C
	virtual void cleanup(EnemyBase*);         // _10

	// _00		= VTBL
	// _00-_10 	= EnemyFSMState
};

struct StateItemWait : public State {
	inline StateItemWait()
	    : State(BIGTREASURE_ItemWait, "itemwait")
	{
	}

	virtual void init(EnemyBase*, StateArg*); // _08
	virtual void exec(EnemyBase*);            // _0C
	virtual void cleanup(EnemyBase*);         // _10

	// _00		= VTBL
	// _00-_10 	= EnemyFSMState
};

struct StateItemWalk : public State {
	inline StateItemWalk()
	    : State(BIGTREASURE_ItemWalk, "itemwalk")
	{
	}

	virtual void init(EnemyBase*, StateArg*); // _08
	virtual void exec(EnemyBase*);            // _0C
	virtual void cleanup(EnemyBase*);         // _10

	// _00		= VTBL
	// _00-_10 	= EnemyFSMState
};

struct StateLand : public State {
	inline StateLand()
	    : State(BIGTREASURE_Land, "land")
	{
	}

	virtual void init(EnemyBase*, StateArg*); // _08
	virtual void exec(EnemyBase*);            // _0C
	virtual void cleanup(EnemyBase*);         // _10

	// _00		= VTBL
	// _00-_10 	= EnemyFSMState
};

struct StatePreAttack : public State {
	inline StatePreAttack()
	    : State(BIGTREASURE_PreAttack, "preattack")
	{
	}

	virtual void init(EnemyBase*, StateArg*); // _08
	virtual void exec(EnemyBase*);            // _0C
	virtual void cleanup(EnemyBase*);         // _10

	// _00		= VTBL
	// _00-_10 	= EnemyFSMState
};

struct StatePutItem : public State {
	inline StatePutItem()
	    : State(BIGTREASURE_PutItem, "putitem")
	{
	}

	virtual void init(EnemyBase*, StateArg*); // _08
	virtual void exec(EnemyBase*);            // _0C
	virtual void cleanup(EnemyBase*);         // _10

	// _00		= VTBL
	// _00-_10 	= EnemyFSMState
};

struct StateStay : public State {
	inline StateStay()
	    : State(BIGTREASURE_Stay, "stay")
	{
	}

	virtual void init(EnemyBase*, StateArg*); // _08
	virtual void exec(EnemyBase*);            // _0C
	virtual void cleanup(EnemyBase*);         // _10

	// _00		= VTBL
	// _00-_10 	= EnemyFSMState
};

struct StateWait : public State {
	inline StateWait()
	    : State(BIGTREASURE_Wait, "wait")
	{
	}

	virtual void init(EnemyBase*, StateArg*); // _08
	virtual void exec(EnemyBase*);            // _0C
	virtual void cleanup(EnemyBase*);         // _10

	// _00		= VTBL
	// _00-_10 	= EnemyFSMState
};

struct StateWalk : public State {
	inline StateWalk()
	    : State(BIGTREASURE_Walk, "walk")
	{
	}

	virtual void init(EnemyBase*, StateArg*); // _08
	virtual void exec(EnemyBase*);            // _0C
	virtual void cleanup(EnemyBase*);         // _10

	// _00		= VTBL
	// _00-_10 	= EnemyFSMState
};
/////////////////////////////////////////////////////////////////
} // namespace BigTreasure
} // namespace Game

#endif
