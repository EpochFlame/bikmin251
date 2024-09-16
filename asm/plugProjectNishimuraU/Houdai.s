.include "macros.inc"
.section .ctors, "wa"  # 0x80472F00 - 0x804732C0
lbl_constructor:
.4byte __sinit_Houdai_cpp

.section .rodata  # 0x804732E0 - 0x8049E220
.balign 8
.global lbl_8048B0D8
lbl_8048B0D8:
	.asciz "rhand1jnt"
	.skip 2
.global lbl_8048B0E4
lbl_8048B0E4:
	.asciz "rhand2jnt"
	.skip 2
.global lbl_8048B0F0
lbl_8048B0F0:
	.asciz "rhand3jnt"
	.skip 2
.global lbl_8048B0FC
lbl_8048B0FC:
	.asciz "lhand1jnt"
	.skip 2
.global lbl_8048B108
lbl_8048B108:
	.asciz "lhand2jnt"
	.skip 2
.global lbl_8048B114
lbl_8048B114:
	.asciz "lhand3jnt"
	.skip 2
.global lbl_8048B120
lbl_8048B120:
	.asciz "rfoot1jnt"
	.skip 2
.global lbl_8048B12C
lbl_8048B12C:
	.asciz "rfoot2jnt"
	.skip 2
.global lbl_8048B138
lbl_8048B138:
	.asciz "rfoot3jnt"
	.skip 2
.global lbl_8048B144
lbl_8048B144:
	.asciz "lfoot1jnt"
	.skip 2
.global lbl_8048B150
lbl_8048B150:
	.asciz "lfoot2jnt"
	.skip 2
.global lbl_8048B15C
lbl_8048B15C:
	.asciz "lfoot3jnt"
	.skip 2
.global lbl_8048B168
lbl_8048B168:
	.4byte lbl_8048B0D8
	.4byte lbl_8048B0E4
	.4byte lbl_8048B0F0
	.4byte lbl_8048B0FC
	.4byte lbl_8048B108
	.4byte lbl_8048B114
	.4byte lbl_8048B120
	.4byte lbl_8048B12C
	.4byte lbl_8048B138
	.4byte lbl_8048B144
	.4byte lbl_8048B150
	.4byte lbl_8048B15C
.global lbl_8048B198
lbl_8048B198:
	.asciz "PSMainSide_ObjSound.h"
	.skip 2
.global lbl_8048B1B0
lbl_8048B1B0:
	.asciz "P2Assert"
	.skip 3
.global lbl_8048B1BC
lbl_8048B1BC:
	.asciz "ef_01_loc"
	.skip 2
.global lbl_8048B1C8
lbl_8048B1C8:
	.asciz "ef_02_loc"
	.skip 2
.global lbl_8048B1D4
lbl_8048B1D4:
	.asciz "ef_03_loc"
	.skip 2
.global lbl_8048B1E0
lbl_8048B1E0:
	.4byte lbl_8048B1BC
	.4byte lbl_8048B1C8
	.4byte lbl_8048B1D4
.global lbl_8048B1EC
lbl_8048B1EC:
	.asciz "ArgPosPos"
	.skip 2

.section .data, "wa"  # 0x8049E220 - 0x804EFC20
.balign 8
.global lbl_804D0E98
lbl_804D0E98:
	.4byte 0x00000000
	.4byte 0x00000000
	.4byte 0x00000000
.global __vt__Q23efx9ArgPosPos
__vt__Q23efx9ArgPosPos:
	.4byte 0
	.4byte 0
	.4byte getName__Q23efx9ArgPosPosFv
.global __vt__Q23efx10THdamaOpen
__vt__Q23efx10THdamaOpen:
	.4byte 0
	.4byte 0
	.4byte create__Q23efx8TSimple1FPQ23efx3Arg
	.4byte forceKill__Q23efx8TSimple1Fv
	.4byte fade__Q23efx8TSimple1Fv
.global __vt__Q23efx14THdamaOnSteam2
__vt__Q23efx14THdamaOnSteam2:
	.4byte 0
	.4byte 0
	.4byte create__Q23efx8TSimple1FPQ23efx3Arg
	.4byte forceKill__Q23efx8TSimple1Fv
	.4byte fade__Q23efx8TSimple1Fv
.global __vt__Q23efx13THdamaOnSmoke
__vt__Q23efx13THdamaOnSmoke:
	.4byte 0
	.4byte 0
	.4byte create__Q23efx8TSimple2FPQ23efx3Arg
	.4byte forceKill__Q23efx8TSimple2Fv
	.4byte fade__Q23efx8TSimple2Fv
.global __vt__Q23efx16THdamaDeadSteamT
__vt__Q23efx16THdamaDeadSteamT:
	.4byte 0
	.4byte 0
	.4byte create__Q23efx8TSimple1FPQ23efx3Arg
	.4byte forceKill__Q23efx8TSimple1Fv
	.4byte fade__Q23efx8TSimple1Fv
.global __vt__Q23efx10TOootaWalk
__vt__Q23efx10TOootaWalk:
	.4byte 0
	.4byte 0
	.4byte create__Q23efx8TSimple2FPQ23efx3Arg
	.4byte forceKill__Q23efx8TSimple2Fv
	.4byte fade__Q23efx8TSimple2Fv
.global __vt__Q23efx15THdamaDeadSteam
__vt__Q23efx15THdamaDeadSteam:
	.4byte 0
	.4byte 0
	.4byte "create__Q23efx29TSyncGroup2<Q23efx9TChaseMtx>FPQ23efx3Arg"
	.4byte "forceKill__Q23efx29TSyncGroup2<Q23efx9TChaseMtx>Fv"
	.4byte "fade__Q23efx29TSyncGroup2<Q23efx9TChaseMtx>Fv"
	.4byte "startDemoDrawOff__Q23efx29TSyncGroup2<Q23efx9TChaseMtx>Fv"
	.4byte "endDemoDrawOn__Q23efx29TSyncGroup2<Q23efx9TChaseMtx>Fv"
.global __vt__Q23efx14THdamaDeadbomb
__vt__Q23efx14THdamaDeadbomb:
	.4byte 0
	.4byte 0
	.4byte "create__Q23efx29TSyncGroup4<Q23efx9TChaseMtx>FPQ23efx3Arg"
	.4byte "forceKill__Q23efx29TSyncGroup4<Q23efx9TChaseMtx>Fv"
	.4byte "fade__Q23efx29TSyncGroup4<Q23efx9TChaseMtx>Fv"
	.4byte "startDemoDrawOff__Q23efx29TSyncGroup4<Q23efx9TChaseMtx>Fv"
	.4byte "endDemoDrawOn__Q23efx29TSyncGroup4<Q23efx9TChaseMtx>Fv"
.global __vt__Q23efx13THdamaSteamBd
__vt__Q23efx13THdamaSteamBd:
	.4byte 0
	.4byte 0
	.4byte create__Q23efx5TSyncFPQ23efx3Arg
	.4byte forceKill__Q23efx5TSyncFv
	.4byte fade__Q23efx5TSyncFv
	.4byte 0
	.4byte 0
	.4byte "@4@__dt__Q23efx13THdamaSteamBdFv"
	.4byte "@4@execute__Q23efx5TSyncFP14JPABaseEmitter"
	.4byte "@4@executeAfter__Q23efx5TSyncFP14JPABaseEmitter"
	.4byte draw__18JPAEmitterCallBackFP14JPABaseEmitter
	.4byte drawAfter__18JPAEmitterCallBackFP14JPABaseEmitter
	.4byte execute__Q23efx5TSyncFP14JPABaseEmitter
	.4byte executeAfter__Q23efx5TSyncFP14JPABaseEmitter
	.4byte doExecuteEmitterOperation__Q23efx10TChaseMtxTFP14JPABaseEmitter
	.4byte doExecuteAfter__Q23efx5TSyncFP14JPABaseEmitter
	.4byte startDemoDrawOff__Q23efx5TSyncFv
	.4byte endDemoDrawOn__Q23efx5TSyncFv
	.4byte __dt__Q23efx13THdamaSteamBdFv
.global __vt__Q23efx14THdamaOnSteam1
__vt__Q23efx14THdamaOnSteam1:
	.4byte 0
	.4byte 0
	.4byte create__Q23efx5TSyncFPQ23efx3Arg
	.4byte forceKill__Q23efx5TSyncFv
	.4byte fade__Q23efx5TSyncFv
	.4byte 0
	.4byte 0
	.4byte "@4@__dt__Q23efx14THdamaOnSteam1Fv"
	.4byte "@4@execute__Q23efx5TSyncFP14JPABaseEmitter"
	.4byte "@4@executeAfter__Q23efx5TSyncFP14JPABaseEmitter"
	.4byte draw__18JPAEmitterCallBackFP14JPABaseEmitter
	.4byte drawAfter__18JPAEmitterCallBackFP14JPABaseEmitter
	.4byte execute__Q23efx5TSyncFP14JPABaseEmitter
	.4byte executeAfter__Q23efx5TSyncFP14JPABaseEmitter
	.4byte doExecuteEmitterOperation__Q23efx10TChaseMtxTFP14JPABaseEmitter
	.4byte doExecuteAfter__Q23efx5TSyncFP14JPABaseEmitter
	.4byte startDemoDrawOff__Q23efx5TSyncFv
	.4byte endDemoDrawOn__Q23efx5TSyncFv
	.4byte __dt__Q23efx14THdamaOnSteam1Fv
.global __vt__Q23efx14THdamaOnHahen1
__vt__Q23efx14THdamaOnHahen1:
	.4byte 0
	.4byte 0
	.4byte create__Q23efx5TSyncFPQ23efx3Arg
	.4byte forceKill__Q23efx5TSyncFv
	.4byte fade__Q23efx5TSyncFv
	.4byte 0
	.4byte 0
	.4byte "@4@__dt__Q23efx14THdamaOnHahen1Fv"
	.4byte "@4@execute__Q23efx5TSyncFP14JPABaseEmitter"
	.4byte "@4@executeAfter__Q23efx5TSyncFP14JPABaseEmitter"
	.4byte draw__18JPAEmitterCallBackFP14JPABaseEmitter
	.4byte drawAfter__18JPAEmitterCallBackFP14JPABaseEmitter
	.4byte execute__Q23efx5TSyncFP14JPABaseEmitter
	.4byte executeAfter__Q23efx5TSyncFP14JPABaseEmitter
	.4byte doExecuteEmitterOperation__Q23efx9TChaseMtxFP14JPABaseEmitter
	.4byte doExecuteAfter__Q23efx5TSyncFP14JPABaseEmitter
	.4byte startDemoDrawOff__Q23efx5TSyncFv
	.4byte endDemoDrawOn__Q23efx5TSyncFv
	.4byte __dt__Q23efx14THdamaOnHahen1Fv
.global __vt__Q23efx11THdamaHahen
__vt__Q23efx11THdamaHahen:
	.4byte 0
	.4byte 0
	.4byte create__Q23efx5TSyncFPQ23efx3Arg
	.4byte forceKill__Q23efx5TSyncFv
	.4byte fade__Q23efx5TSyncFv
	.4byte 0
	.4byte 0
	.4byte "@4@__dt__Q23efx11THdamaHahenFv"
	.4byte "@4@execute__Q23efx5TSyncFP14JPABaseEmitter"
	.4byte "@4@executeAfter__Q23efx5TSyncFP14JPABaseEmitter"
	.4byte draw__18JPAEmitterCallBackFP14JPABaseEmitter
	.4byte drawAfter__18JPAEmitterCallBackFP14JPABaseEmitter
	.4byte execute__Q23efx5TSyncFP14JPABaseEmitter
	.4byte executeAfter__Q23efx5TSyncFP14JPABaseEmitter
	.4byte doExecuteEmitterOperation__Q23efx12TChasePosPosFP14JPABaseEmitter
	.4byte doExecuteAfter__Q23efx5TSyncFP14JPABaseEmitter
	.4byte startDemoDrawOff__Q23efx5TSyncFv
	.4byte endDemoDrawOn__Q23efx5TSyncFv
	.4byte __dt__Q23efx11THdamaHahenFv
.global __vt__Q23efx13THdamaSteamSt
__vt__Q23efx13THdamaSteamSt:
	.4byte 0
	.4byte 0
	.4byte create__Q23efx5TSyncFPQ23efx3Arg
	.4byte forceKill__Q23efx5TSyncFv
	.4byte fade__Q23efx5TSyncFv
	.4byte 0
	.4byte 0
	.4byte "@4@__dt__Q23efx13THdamaSteamStFv"
	.4byte "@4@execute__Q23efx5TSyncFP14JPABaseEmitter"
	.4byte "@4@executeAfter__Q23efx5TSyncFP14JPABaseEmitter"
	.4byte draw__18JPAEmitterCallBackFP14JPABaseEmitter
	.4byte drawAfter__18JPAEmitterCallBackFP14JPABaseEmitter
	.4byte execute__Q23efx5TSyncFP14JPABaseEmitter
	.4byte executeAfter__Q23efx5TSyncFP14JPABaseEmitter
	.4byte doExecuteEmitterOperation__Q23efx9TChaseMtxFP14JPABaseEmitter
	.4byte doExecuteAfter__Q23efx5TSyncFP14JPABaseEmitter
	.4byte startDemoDrawOff__Q23efx5TSyncFv
	.4byte endDemoDrawOn__Q23efx5TSyncFv
	.4byte __dt__Q23efx13THdamaSteamStFv
.global __vt__Q23efx11THdamaSteam
__vt__Q23efx11THdamaSteam:
	.4byte 0
	.4byte 0
	.4byte create__Q23efx5TSyncFPQ23efx3Arg
	.4byte forceKill__Q23efx5TSyncFv
	.4byte fade__Q23efx5TSyncFv
	.4byte 0
	.4byte 0
	.4byte "@4@__dt__Q23efx11THdamaSteamFv"
	.4byte "@4@execute__Q23efx5TSyncFP14JPABaseEmitter"
	.4byte "@4@executeAfter__Q23efx5TSyncFP14JPABaseEmitter"
	.4byte draw__18JPAEmitterCallBackFP14JPABaseEmitter
	.4byte drawAfter__18JPAEmitterCallBackFP14JPABaseEmitter
	.4byte execute__Q23efx5TSyncFP14JPABaseEmitter
	.4byte executeAfter__Q23efx5TSyncFP14JPABaseEmitter
	.4byte doExecuteEmitterOperation__Q23efx9TChaseMtxFP14JPABaseEmitter
	.4byte doExecuteAfter__Q23efx5TSyncFP14JPABaseEmitter
	.4byte startDemoDrawOff__Q23efx5TSyncFv
	.4byte endDemoDrawOn__Q23efx5TSyncFv
	.4byte __dt__Q23efx11THdamaSteamFv
.global __vt__Q23efx14THdamaOnHahen2
__vt__Q23efx14THdamaOnHahen2:
	.4byte 0
	.4byte 0
	.4byte create__Q23efx5TSyncFPQ23efx3Arg
	.4byte forceKill__Q23efx5TSyncFv
	.4byte fade__Q23efx5TSyncFv
	.4byte 0
	.4byte 0
	.4byte "@4@__dt__Q23efx14THdamaOnHahen2Fv"
	.4byte "@4@execute__Q23efx5TSyncFP14JPABaseEmitter"
	.4byte "@4@executeAfter__Q23efx5TSyncFP14JPABaseEmitter"
	.4byte draw__18JPAEmitterCallBackFP14JPABaseEmitter
	.4byte drawAfter__18JPAEmitterCallBackFP14JPABaseEmitter
	.4byte execute__Q23efx5TSyncFP14JPABaseEmitter
	.4byte executeAfter__Q23efx5TSyncFP14JPABaseEmitter
	.4byte doExecuteEmitterOperation__Q23efx12TChasePosPosFP14JPABaseEmitter
	.4byte doExecuteAfter__Q23efx5TSyncFP14JPABaseEmitter
	.4byte startDemoDrawOff__Q23efx5TSyncFv
	.4byte endDemoDrawOn__Q23efx5TSyncFv
	.4byte __dt__Q23efx14THdamaOnHahen2Fv
.global __vt__Q34Game6Houdai3Obj
__vt__Q34Game6Houdai3Obj:
	.4byte 0
	.4byte 0
	.4byte getPosition__Q24Game9EnemyBaseFv
	.4byte checkCollision__Q24Game8CreatureFPQ24Game10CellObject
	.4byte getBoundingSphere__Q24Game9EnemyBaseFRQ23Sys6Sphere
	.4byte collisionUpdatable__Q24Game8CreatureFv
	.4byte isPiki__Q24Game8CreatureFv
	.4byte isNavi__Q24Game8CreatureFv
	.4byte deferPikiCollision__Q24Game10CellObjectFv
	.4byte getTypeName__Q24Game8CreatureFv
	.4byte getObjType__Q24Game8CreatureFv
	.4byte constructor__Q24Game9EnemyBaseFv
	.4byte onInit__Q34Game6Houdai3ObjFPQ24Game15CreatureInitArg
	.4byte onKill__Q34Game6Houdai3ObjFPQ24Game15CreatureKillArg
	.4byte onInitPost__Q24Game9EnemyBaseFPQ24Game15CreatureInitArg
	.4byte doAnimation__Q24Game9EnemyBaseFv
	.4byte doEntry__Q24Game9EnemyBaseFv
	.4byte doSetView__Q24Game9EnemyBaseFi
	.4byte doViewCalc__Q24Game9EnemyBaseFv
	.4byte doSimulation__Q24Game9EnemyBaseFf
	.4byte doDirectDraw__Q34Game6Houdai3ObjFR8Graphics
	.4byte getBodyRadius__Q24Game9EnemyBaseFv
	.4byte getCellRadius__Q24Game9EnemyBaseFv
	.4byte "initPosition__Q24Game8CreatureFR10Vector3<f>"
	.4byte "onInitPosition__Q24Game8CreatureFR10Vector3<f>"
	.4byte getFaceDir__Q24Game9EnemyBaseFv
	.4byte "setVelocity__Q24Game9EnemyBaseFR10Vector3<f>"
	.4byte getVelocity__Q24Game9EnemyBaseFv
	.4byte "onSetPosition__Q24Game9EnemyBaseFR10Vector3<f>"
	.4byte "onSetPositionPost__Q24Game9EnemyBaseFR10Vector3<f>"
	.4byte updateTrMatrix__Q24Game9EnemyBaseFv
	.4byte isTeki__Q24Game9EnemyBaseFv
	.4byte isPellet__Q24Game8CreatureFv
	.4byte inWaterCallback__Q34Game6Houdai3ObjFPQ24Game8WaterBox
	.4byte outWaterCallback__Q34Game6Houdai3ObjFv
	.4byte inWater__Q24Game9EnemyBaseFv
	.4byte getFlockMgr__Q24Game8CreatureFv
	.4byte onStartCapture__Q24Game8CreatureFv
	.4byte onUpdateCapture__Q24Game8CreatureFR7Matrixf
	.4byte onEndCapture__Q24Game8CreatureFv
	.4byte isAtari__Q24Game8CreatureFv
	.4byte setAtari__Q24Game8CreatureFb
	.4byte isAlive__Q24Game8CreatureFv
	.4byte setAlive__Q24Game8CreatureFb
	.4byte isCollisionFlick__Q24Game8CreatureFv
	.4byte setCollisionFlick__Q24Game8CreatureFb
	.4byte isMovieActor__Q24Game8CreatureFv
	.4byte isMovieExtra__Q24Game8CreatureFv
	.4byte isMovieMotion__Q24Game8CreatureFv
	.4byte setMovieMotion__Q24Game8CreatureFb
	.4byte isBuried__Q24Game8CreatureFv
	.4byte isFlying__Q24Game9EnemyBaseFv
	.4byte isUnderground__Q24Game8CreatureFv
	.4byte isLivingThing__Q24Game8CreatureFv
	.4byte isDebugCollision__Q24Game8CreatureFv
	.4byte setDebugCollision__Q24Game8CreatureFb
	.4byte doSave__Q24Game8CreatureFR6Stream
	.4byte doLoad__Q24Game8CreatureFR6Stream
	.4byte bounceCallback__Q24Game8CreatureFPQ23Sys8Triangle
	.4byte collisionCallback__Q24Game9EnemyBaseFRQ24Game9CollEvent
	.4byte platCallback__Q24Game8CreatureFRQ24Game9PlatEvent
	.4byte getJAIObject__Q24Game9EnemyBaseFv
	.4byte getPSCreature__Q24Game9EnemyBaseFv
	.4byte getSound_AILOD__Q24Game8CreatureFv
	.4byte getSound_PosPtr__Q24Game9EnemyBaseFv
	.4byte sound_culling__Q24Game9EnemyBaseFv
	.4byte getSound_CurrAnimFrame__Q24Game9EnemyBaseFv
	.4byte getSound_CurrAnimSpeed__Q24Game9EnemyBaseFv
	.4byte on_movie_begin__Q24Game8CreatureFb
	.4byte on_movie_end__Q24Game8CreatureFb
	.4byte movieStartAnimation__Q24Game8CreatureFUl
	.4byte movieStartDemoAnimation__Q24Game8CreatureFPQ28SysShape8AnimInfo
	.4byte movieSetAnimationLastFrame__Q24Game8CreatureFv
	.4byte "movieSetTranslation__Q24Game8CreatureFR10Vector3<f>f"
	.4byte movieSetFaceDir__Q24Game8CreatureFf
	.4byte "movieGotoPosition__Q24Game8CreatureFR10Vector3<f>"
	.4byte movieUserCommand__Q24Game8CreatureFUlPQ24Game11MoviePlayer
	.4byte getShadowParam__Q34Game6Houdai3ObjFRQ24Game11ShadowParam
	.4byte needShadow__Q24Game9EnemyBaseFv
	.4byte getLifeGaugeParam__Q24Game9EnemyBaseFRQ24Game14LifeGaugeParam
	.4byte getLODSphere__Q24Game9EnemyBaseFRQ23Sys6Sphere
	.4byte getLODCylinder__Q24Game8CreatureFRQ23Sys8Cylinder
	.4byte startPick__Q24Game8CreatureFv
	.4byte endPick__Q24Game8CreatureFb
	.4byte getMabiki__Q24Game8CreatureFv
	.4byte getFootmarks__Q24Game8CreatureFv
	.4byte onStickStart__Q24Game9EnemyBaseFPQ24Game8Creature
	.4byte onStickEnd__Q24Game9EnemyBaseFPQ24Game8Creature
	.4byte onStickStartSelf__Q24Game8CreatureFPQ24Game8Creature
	.4byte onStickEndSelf__Q24Game8CreatureFPQ24Game8Creature
	.4byte isSlotFree__Q24Game8CreatureFs
	.4byte getFreeStickSlot__Q24Game8CreatureFv
	.4byte "getNearFreeStickSlot__Q24Game8CreatureFR10Vector3<f>"
	.4byte getRandomFreeStickSlot__Q24Game8CreatureFv
	.4byte onSlotStickStart__Q24Game8CreatureFPQ24Game8Creatures
	.4byte onSlotStickEnd__Q24Game8CreatureFPQ24Game8Creatures
	.4byte "calcStickSlotGlobal__Q24Game8CreatureFsR10Vector3<f>"
	.4byte "getVelocityAt__Q24Game9EnemyBaseFR10Vector3<f>R10Vector3<f>"
	.4byte "getAngularEffect__Q24Game8CreatureFR10Vector3<f>R10Vector3<f>"
	.4byte "applyImpulse__Q24Game8CreatureFR10Vector3<f>R10Vector3<f>"
	.4byte ignoreAtari__Q24Game8CreatureFPQ24Game8Creature
	.4byte getSuckPos__Q24Game8CreatureFv
	.4byte getGoalPos__Q24Game8CreatureFv
	.4byte isSuckReady__Q24Game8CreatureFv
	.4byte isSuckArriveWait__Q24Game8CreatureFv
	.4byte stimulate__Q24Game9EnemyBaseFRQ24Game11Interaction
	.4byte getCreatureName__Q24Game9EnemyBaseFv
	.4byte getCreatureID__Q24Game9EnemyBaseFv
	.4byte 0
	.4byte 0
	.4byte "@376@onKeyEvent__Q24Game9EnemyBaseFRCQ28SysShape8KeyEvent"
	.4byte __dt__Q34Game6Houdai3ObjFv
	.4byte "birth__Q24Game9EnemyBaseFR10Vector3<f>f"
	.4byte setInitialSetting__Q34Game6Houdai3ObjFPQ24Game21EnemyInitialParamBase
	.4byte update__Q24Game9EnemyBaseFv
	.4byte doUpdate__Q34Game6Houdai3ObjFv
	.4byte doUpdateCommon__Q34Game6Houdai3ObjFv
	.4byte doUpdateCarcass__Q24Game9EnemyBaseFv
	.4byte doAnimationUpdateAnimator__Q24Game9EnemyBaseFv
	.4byte doAnimationCullingOff__Q34Game6Houdai3ObjFv
	.4byte doAnimationCullingOn__Q24Game9EnemyBaseFv
	.4byte doAnimationStick__Q24Game9EnemyBaseFv
	.4byte doSimulationCarcass__Q24Game9EnemyBaseFf
	.4byte doDebugDraw__Q34Game6Houdai3ObjFR8Graphics
	.4byte doSimpleDraw__Q24Game9EnemyBaseFP8Viewport
	.4byte doSimulationGround__Q24Game9EnemyBaseFf
	.4byte doSimulationFlying__Q24Game9EnemyBaseFf
	.4byte doSimulationStick__Q24Game9EnemyBaseFf
	.4byte changeMaterial__Q34Game6Houdai3ObjFv
	.4byte "getCommonEffectPos__Q24Game9EnemyBaseFR10Vector3<f>"
	.4byte getFitEffectPos__Q24Game9EnemyBaseFv
	.4byte viewGetShape__Q24Game9EnemyBaseFv
	.4byte view_start_carrymotion__Q24Game9EnemyBaseFv
	.4byte view_finish_carrymotion__Q24Game9EnemyBaseFv
	.4byte viewStartPreCarryMotion__Q24Game9EnemyBaseFv
	.4byte viewStartCarryMotion__Q24Game9EnemyBaseFv
	.4byte viewOnPelletKilled__Q24Game9EnemyBaseFv
	.4byte getOffsetForMapCollision__Q24Game9EnemyBaseFv
	.4byte setParameters__Q34Game6Houdai3ObjFv
	.4byte initMouthSlots__Q24Game9EnemyBaseFv
	.4byte initWalkSmokeEffect__Q24Game9EnemyBaseFv
	.4byte getWalkSmokeEffectMgr__Q24Game9EnemyBaseFv
	.4byte onKeyEvent__Q24Game9EnemyBaseFRCQ28SysShape8KeyEvent
	.4byte injure__Q24Game9EnemyBaseFv
	.4byte setCollEvent__Q24Game9EnemyBaseFRQ24Game9CollEvent
	.4byte "getEfxHamonPos__Q24Game9EnemyBaseFP10Vector3<f>"
	.4byte createInstanceEfxHamon__Q24Game9EnemyBaseFv
	.4byte updateEfxHamon__Q24Game9EnemyBaseFv
	.4byte createEfxHamon__Q24Game9EnemyBaseFv
	.4byte fadeEfxHamon__Q24Game9EnemyBaseFv
	.4byte getEnemyTypeID__Q34Game6Houdai3ObjFv
	.4byte getMouthSlots__Q24Game9EnemyBaseFv
	.4byte doGetLifeGaugeParam__Q24Game9EnemyBaseFRQ24Game14LifeGaugeParam
	.4byte throwupItem__Q24Game9EnemyBaseFv
	.4byte "getThrowupItemPosition__Q34Game6Houdai3ObjFP10Vector3<f>"
	.4byte "getThrowupItemVelocity__Q34Game6Houdai3ObjFP10Vector3<f>"
	.4byte throwupItemInDeathProcedure__Q34Game6Houdai3ObjFv
	.4byte setLODSphere__Q24Game9EnemyBaseFRQ23Sys6Sphere
	.4byte damageCallBack__Q34Game6Houdai3ObjFPQ24Game8CreaturefP8CollPart
	.4byte pressCallBack__Q24Game9EnemyBaseFPQ24Game8CreaturefP8CollPart
	.4byte flyCollisionCallBack__Q24Game9EnemyBaseFPQ24Game8CreaturefP8CollPart
	.4byte hipdropCallBack__Q24Game9EnemyBaseFPQ24Game8CreaturefP8CollPart
	.4byte dropCallBack__Q24Game9EnemyBaseFPQ24Game8Creature
	.4byte earthquakeCallBack__Q24Game9EnemyBaseFPQ24Game8Creaturef
	.4byte farmCallBack__Q24Game9EnemyBaseFPQ24Game8Creaturef
	.4byte "bombCallBack__Q34Game8BlackMan3ObjFPQ24Game8CreatureR10Vector3<f>f"
	.4byte eatWhitePikminCallBack__Q24Game9EnemyBaseFPQ24Game8Creaturef
	.4byte dopeCallBack__Q24Game9EnemyBaseFPQ24Game8Creaturei
	.4byte doDopeCallBack__Q24Game9EnemyBaseFPQ24Game8Creaturei
	.4byte doStartStoneState__Q34Game6Houdai3ObjFv
	.4byte doFinishStoneState__Q34Game6Houdai3ObjFv
	.4byte getDamageCoeStoneState__Q34Game6Houdai3ObjFv
	.4byte doStartEarthquakeState__Q24Game9EnemyBaseFf
	.4byte doFinishEarthquakeState__Q24Game9EnemyBaseFv
	.4byte doStartEarthquakeFitState__Q24Game9EnemyBaseFv
	.4byte doFinishEarthquakeFitState__Q24Game9EnemyBaseFv
	.4byte lifeRecover__Q24Game9EnemyBaseFv
	.4byte startCarcassMotion__Q24Game9EnemyBaseFv
	.4byte setCarcassArg__Q24Game9EnemyBaseFRQ24Game13PelletViewArg
	.4byte getCarcassArgHeight__Q24Game9EnemyBaseFv
	.4byte doBecomeCarcass__Q24Game9EnemyBaseFv
	.4byte startWaitingBirthTypeDrop__Q24Game9EnemyBaseFv
	.4byte finishWaitingBirthTypeDrop__Q24Game9EnemyBaseFv
	.4byte isFinishableWaitingBirthTypeDrop__Q24Game9EnemyBaseFv
	.4byte doStartWaitingBirthTypeDrop__Q24Game9EnemyBaseFv
	.4byte doFinishWaitingBirthTypeDrop__Q24Game9EnemyBaseFv
	.4byte wallCallback__Q24Game9EnemyBaseFRCQ24Game8MoveInfo
	.4byte getDownSmokeScale__Q24Game9EnemyBaseFv
	.4byte doStartMovie__Q34Game6Houdai3ObjFv
	.4byte doEndMovie__Q34Game6Houdai3ObjFv
	.4byte setFSM__Q34Game6Houdai3ObjFPQ34Game6Houdai3FSM
	.4byte 0
	.4byte 0
	.4byte viewGetBaseScale__Q24Game10PelletViewFv
	.4byte "@1056@12@viewGetShape__Q24Game9EnemyBaseFv"
	.4byte viewGetCollTreeJointIndex__Q24Game10PelletViewFv
	.4byte viewGetCollTreeOffset__Q24Game10PelletViewFv
	.4byte "@1056@12@view_start_carrymotion__Q24Game9EnemyBaseFv"
	.4byte "@1056@12@view_finish_carrymotion__Q24Game9EnemyBaseFv"
	.4byte "@1056@12@viewStartPreCarryMotion__Q24Game9EnemyBaseFv"
	.4byte "@1056@12@viewStartCarryMotion__Q24Game9EnemyBaseFv"
	.4byte "@1056@12@viewOnPelletKilled__Q24Game9EnemyBaseFv"
	.4byte "viewEntryShape__Q24Game10PelletViewFR7MatrixfR10Vector3<f>"
.global __vt__Q34Game6Houdai20HoudaiGroundCallBack
__vt__Q34Game6Houdai20HoudaiGroundCallBack:
	.4byte 0
	.4byte 0
	.4byte invokeOnGround__Q34Game6Houdai20HoudaiGroundCallBackFiPQ24Game8WaterBox
	.4byte invokeOffGround__Q34Game6Houdai20HoudaiGroundCallBackFiPQ24Game8WaterBox
	.4byte 0

.section .sbss # 0x80514D80 - 0x80516360
.balign 8
.global lbl_80515D98
lbl_80515D98:
	.skip 0x4
.global lbl_80515D9C
lbl_80515D9C:
	.skip 0x4

.section .sdata2, "a"     # 0x80516360 - 0x80520E40
.balign 8
.global lbl_8051C4F8
lbl_8051C4F8:
	.4byte 0x00000000
.global lbl_8051C4FC
lbl_8051C4FC:
	.float 1.0
.global lbl_8051C500
lbl_8051C500:
	.float 0.1
.global lbl_8051C504
lbl_8051C504:
	.float 0.25
.global lbl_8051C508
lbl_8051C508:
	.4byte 0x41200000
.global lbl_8051C50C
lbl_8051C50C:
	.4byte 0xC47A0000
.global lbl_8051C510
lbl_8051C510:
	.4byte 0x6B6F7369
	.4byte 0x00000000
.global lbl_8051C518
lbl_8051C518:
	.4byte 0x40000000
.global lbl_8051C51C
lbl_8051C51C:
	.4byte 0x47000000
.global lbl_8051C520
lbl_8051C520:
	.4byte 0x43300000
	.4byte 0x80000000
.global lbl_8051C528
lbl_8051C528:
	.4byte 0x441C4000
.global lbl_8051C52C
lbl_8051C52C:
	.4byte 0x40490FDB
.global lbl_8051C530
lbl_8051C530:
	.4byte 0x3FC90FDB
.global lbl_8051C534
lbl_8051C534:
	.4byte 0xC3A2F983
.global lbl_8051C538
lbl_8051C538:
	.4byte 0x43A2F983
.global lbl_8051C53C
lbl_8051C53C:
	.4byte 0x43340000
.global lbl_8051C540
lbl_8051C540:
	.4byte 0x40C90FDB
.global lbl_8051C544
lbl_8051C544:
	.4byte 0x3F400000
.global lbl_8051C548
lbl_8051C548:
	.4byte 0x42F00000
.global lbl_8051C54C
lbl_8051C54C:
	.4byte 0x40400000
.global lbl_8051C550
lbl_8051C550:
	.4byte 0xBE19999A
.global lbl_8051C554
lbl_8051C554:
	.float 0.5
.global lbl_8051C558
lbl_8051C558:
	.4byte 0xC0000000
.global lbl_8051C55C
lbl_8051C55C:
	.4byte 0x42960000
.global lbl_8051C560
lbl_8051C560:
	.4byte 0x41F00000
.global lbl_8051C564
lbl_8051C564:
	.4byte 0x42700000
.global lbl_8051C568
lbl_8051C568:
	.float 0.7
.global lbl_8051C56C
lbl_8051C56C:
	.4byte 0xBFC00000
.global lbl_8051C570
lbl_8051C570:
	.4byte 0x3F2B851F
.global lbl_8051C574
lbl_8051C574:
	.4byte 0x3F4CCCCD
.global lbl_8051C578
lbl_8051C578:
	.float 0.3
.global lbl_8051C57C
lbl_8051C57C:
	.4byte 0x3F99999A
.global lbl_8051C580
lbl_8051C580:
	.4byte 0x3E333333
.global lbl_8051C584
lbl_8051C584:
	.4byte 0x3EB33333

.section .text, "ax"  # 0x800056C0 - 0x80472F00
.global invokeOnGround__Q34Game6Houdai20HoudaiGroundCallBackFiPQ24Game8WaterBox
invokeOnGround__Q34Game6Houdai20HoudaiGroundCallBackFiPQ24Game8WaterBox:
/* 802BFCB0 002BCBF0  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 802BFCB4 002BCBF4  7C 08 02 A6 */	mflr r0
/* 802BFCB8 002BCBF8  90 01 00 14 */	stw r0, 0x14(r1)
/* 802BFCBC 002BCBFC  80 63 00 04 */	lwz r3, 4(r3)
/* 802BFCC0 002BCC00  48 00 26 19 */	bl createOnGroundEffect__Q34Game6Houdai3ObjFiPQ24Game8WaterBox
/* 802BFCC4 002BCC04  80 01 00 14 */	lwz r0, 0x14(r1)
/* 802BFCC8 002BCC08  7C 08 03 A6 */	mtlr r0
/* 802BFCCC 002BCC0C  38 21 00 10 */	addi r1, r1, 0x10
/* 802BFCD0 002BCC10  4E 80 00 20 */	blr 

.global invokeOffGround__Q34Game6Houdai20HoudaiGroundCallBackFiPQ24Game8WaterBox
invokeOffGround__Q34Game6Houdai20HoudaiGroundCallBackFiPQ24Game8WaterBox:
/* 802BFCD4 002BCC14  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 802BFCD8 002BCC18  7C 08 02 A6 */	mflr r0
/* 802BFCDC 002BCC1C  90 01 00 14 */	stw r0, 0x14(r1)
/* 802BFCE0 002BCC20  80 63 00 04 */	lwz r3, 4(r3)
/* 802BFCE4 002BCC24  48 00 29 79 */	bl createOffGroundEffect__Q34Game6Houdai3ObjFiPQ24Game8WaterBox
/* 802BFCE8 002BCC28  80 01 00 14 */	lwz r0, 0x14(r1)
/* 802BFCEC 002BCC2C  7C 08 03 A6 */	mtlr r0
/* 802BFCF0 002BCC30  38 21 00 10 */	addi r1, r1, 0x10
/* 802BFCF4 002BCC34  4E 80 00 20 */	blr 

.global __ct__Q34Game6Houdai3ObjFv
__ct__Q34Game6Houdai3ObjFv:
/* 802BFCF8 002BCC38  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 802BFCFC 002BCC3C  7C 08 02 A6 */	mflr r0
/* 802BFD00 002BCC40  90 01 00 14 */	stw r0, 0x14(r1)
/* 802BFD04 002BCC44  7C 80 07 35 */	extsh. r0, r4
/* 802BFD08 002BCC48  93 E1 00 0C */	stw r31, 0xc(r1)
/* 802BFD0C 002BCC4C  7C 7F 1B 78 */	mr r31, r3
/* 802BFD10 002BCC50  93 C1 00 08 */	stw r30, 8(r1)
/* 802BFD14 002BCC54  41 82 00 24 */	beq .L_802BFD38
/* 802BFD18 002BCC58  38 1F 04 20 */	addi r0, r31, 0x420
/* 802BFD1C 002BCC5C  3C 60 80 4B */	lis r3, __vt__Q24Game10PelletView@ha
/* 802BFD20 002BCC60  90 1F 01 7C */	stw r0, 0x17c(r31)
/* 802BFD24 002BCC64  38 63 A6 78 */	addi r3, r3, __vt__Q24Game10PelletView@l
/* 802BFD28 002BCC68  38 00 00 00 */	li r0, 0
/* 802BFD2C 002BCC6C  90 7F 04 20 */	stw r3, 0x420(r31)
/* 802BFD30 002BCC70  90 1F 04 24 */	stw r0, 0x424(r31)
/* 802BFD34 002BCC74  90 1F 04 28 */	stw r0, 0x428(r31)
.L_802BFD38:
/* 802BFD38 002BCC78  7F E3 FB 78 */	mr r3, r31
/* 802BFD3C 002BCC7C  38 80 00 00 */	li r4, 0
/* 802BFD40 002BCC80  4B E4 16 61 */	bl __ct__Q24Game9EnemyBaseFv
/* 802BFD44 002BCC84  3C 80 80 4D */	lis r4, __vt__Q34Game6Houdai3Obj@ha
/* 802BFD48 002BCC88  38 1F 04 20 */	addi r0, r31, 0x420
/* 802BFD4C 002BCC8C  38 C4 11 60 */	addi r6, r4, __vt__Q34Game6Houdai3Obj@l
/* 802BFD50 002BCC90  3C 60 80 12 */	lis r3, "__ct__10Vector3<f>Fv"@ha
/* 802BFD54 002BCC94  90 DF 00 00 */	stw r6, 0(r31)
/* 802BFD58 002BCC98  38 A6 01 B0 */	addi r5, r6, 0x1b0
/* 802BFD5C 002BCC9C  39 26 02 FC */	addi r9, r6, 0x2fc
/* 802BFD60 002BCCA0  38 83 F3 48 */	addi r4, r3, "__ct__10Vector3<f>Fv"@l
/* 802BFD64 002BCCA4  90 BF 01 78 */	stw r5, 0x178(r31)
/* 802BFD68 002BCCA8  38 7F 03 04 */	addi r3, r31, 0x304
/* 802BFD6C 002BCCAC  38 A0 00 00 */	li r5, 0
/* 802BFD70 002BCCB0  38 C0 00 0C */	li r6, 0xc
/* 802BFD74 002BCCB4  81 1F 01 7C */	lwz r8, 0x17c(r31)
/* 802BFD78 002BCCB8  38 E0 00 10 */	li r7, 0x10
/* 802BFD7C 002BCCBC  91 28 00 00 */	stw r9, 0(r8)
/* 802BFD80 002BCCC0  81 1F 01 7C */	lwz r8, 0x17c(r31)
/* 802BFD84 002BCCC4  7C 08 00 50 */	subf r0, r8, r0
/* 802BFD88 002BCCC8  90 08 00 0C */	stw r0, 0xc(r8)
/* 802BFD8C 002BCCCC  4B E0 1A B1 */	bl __construct_array
/* 802BFD90 002BCCD0  38 60 00 2C */	li r3, 0x2c
/* 802BFD94 002BCCD4  4B D6 41 11 */	bl __nw__FUl
/* 802BFD98 002BCCD8  7C 7E 1B 79 */	or. r30, r3, r3
/* 802BFD9C 002BCCDC  41 82 00 44 */	beq .L_802BFDE0
/* 802BFDA0 002BCCE0  4B E6 7B D5 */	bl __ct__Q24Game17EnemyAnimatorBaseFv
/* 802BFDA4 002BCCE4  3C 60 80 4D */	lis r3, __vt__Q34Game6Houdai14ProperAnimator@ha
/* 802BFDA8 002BCCE8  3C 80 80 4B */	lis r4, __vt__Q28SysShape12BaseAnimator@ha
/* 802BFDAC 002BCCEC  38 03 0D 80 */	addi r0, r3, __vt__Q34Game6Houdai14ProperAnimator@l
/* 802BFDB0 002BCCF0  3C 60 80 4F */	lis r3, __vt__Q28SysShape8Animator@ha
/* 802BFDB4 002BCCF4  90 1E 00 00 */	stw r0, 0(r30)
/* 802BFDB8 002BCCF8  38 84 B9 88 */	addi r4, r4, __vt__Q28SysShape12BaseAnimator@l
/* 802BFDBC 002BCCFC  38 63 BE 00 */	addi r3, r3, __vt__Q28SysShape8Animator@l
/* 802BFDC0 002BCD00  38 00 00 00 */	li r0, 0
/* 802BFDC4 002BCD04  90 9E 00 10 */	stw r4, 0x10(r30)
/* 802BFDC8 002BCD08  90 7E 00 10 */	stw r3, 0x10(r30)
/* 802BFDCC 002BCD0C  98 1E 00 28 */	stb r0, 0x28(r30)
/* 802BFDD0 002BCD10  90 1E 00 1C */	stw r0, 0x1c(r30)
/* 802BFDD4 002BCD14  90 1E 00 14 */	stw r0, 0x14(r30)
/* 802BFDD8 002BCD18  98 1E 00 28 */	stb r0, 0x28(r30)
/* 802BFDDC 002BCD1C  90 1E 00 20 */	stw r0, 0x20(r30)
.L_802BFDE0:
/* 802BFDE0 002BCD20  93 DF 01 84 */	stw r30, 0x184(r31)
/* 802BFDE4 002BCD24  38 60 00 1C */	li r3, 0x1c
/* 802BFDE8 002BCD28  4B D6 40 BD */	bl __nw__FUl
/* 802BFDEC 002BCD2C  7C 64 1B 79 */	or. r4, r3, r3
/* 802BFDF0 002BCD30  41 82 00 24 */	beq .L_802BFE14
/* 802BFDF4 002BCD34  3C A0 80 4B */	lis r5, __vt__Q24Game17EnemyStateMachine@ha
/* 802BFDF8 002BCD38  3C 60 80 4D */	lis r3, __vt__Q34Game6Houdai3FSM@ha
/* 802BFDFC 002BCD3C  38 05 F9 80 */	addi r0, r5, __vt__Q24Game17EnemyStateMachine@l
/* 802BFE00 002BCD40  38 A0 FF FF */	li r5, -1
/* 802BFE04 002BCD44  90 04 00 00 */	stw r0, 0(r4)
/* 802BFE08 002BCD48  38 03 0D 5C */	addi r0, r3, __vt__Q34Game6Houdai3FSM@l
/* 802BFE0C 002BCD4C  90 A4 00 18 */	stw r5, 0x18(r4)
/* 802BFE10 002BCD50  90 04 00 00 */	stw r0, 0(r4)
.L_802BFE14:
/* 802BFE14 002BCD54  81 9F 00 00 */	lwz r12, 0(r31)
/* 802BFE18 002BCD58  7F E3 FB 78 */	mr r3, r31
/* 802BFE1C 002BCD5C  81 8C 02 F8 */	lwz r12, 0x2f8(r12)
/* 802BFE20 002BCD60  7D 89 03 A6 */	mtctr r12
/* 802BFE24 002BCD64  4E 80 04 21 */	bctrl 
/* 802BFE28 002BCD68  7F E3 FB 78 */	mr r3, r31
/* 802BFE2C 002BCD6C  48 00 0C 51 */	bl createIKSystem__Q34Game6Houdai3ObjFv
/* 802BFE30 002BCD70  7F E3 FB 78 */	mr r3, r31
/* 802BFE34 002BCD74  48 00 11 29 */	bl createShadowSystem__Q34Game6Houdai3ObjFv
/* 802BFE38 002BCD78  7F E3 FB 78 */	mr r3, r31
/* 802BFE3C 002BCD7C  48 00 13 3D */	bl createShotGun__Q34Game6Houdai3ObjFv
/* 802BFE40 002BCD80  7F E3 FB 78 */	mr r3, r31
/* 802BFE44 002BCD84  48 00 1D 21 */	bl createEffect__Q34Game6Houdai3ObjFv
/* 802BFE48 002BCD88  80 01 00 14 */	lwz r0, 0x14(r1)
/* 802BFE4C 002BCD8C  7F E3 FB 78 */	mr r3, r31
/* 802BFE50 002BCD90  83 E1 00 0C */	lwz r31, 0xc(r1)
/* 802BFE54 002BCD94  83 C1 00 08 */	lwz r30, 8(r1)
/* 802BFE58 002BCD98  7C 08 03 A6 */	mtlr r0
/* 802BFE5C 002BCD9C  38 21 00 10 */	addi r1, r1, 0x10
/* 802BFE60 002BCDA0  4E 80 00 20 */	blr 

.global setInitialSetting__Q34Game6Houdai3ObjFPQ24Game21EnemyInitialParamBase
setInitialSetting__Q34Game6Houdai3ObjFPQ24Game21EnemyInitialParamBase:
/* 802BFE64 002BCDA4  4E 80 00 20 */	blr 

.global onInit__Q34Game6Houdai3ObjFPQ24Game15CreatureInitArg
onInit__Q34Game6Houdai3ObjFPQ24Game15CreatureInitArg:
/* 802BFE68 002BCDA8  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 802BFE6C 002BCDAC  7C 08 02 A6 */	mflr r0
/* 802BFE70 002BCDB0  90 01 00 14 */	stw r0, 0x14(r1)
/* 802BFE74 002BCDB4  93 E1 00 0C */	stw r31, 0xc(r1)
/* 802BFE78 002BCDB8  7C 7F 1B 78 */	mr r31, r3
/* 802BFE7C 002BCDBC  4B E4 1B DD */	bl onInit__Q24Game9EnemyBaseFPQ24Game15CreatureInitArg
/* 802BFE80 002BCDC0  7F E3 FB 78 */	mr r3, r31
/* 802BFE84 002BCDC4  4B E4 78 F9 */	bl hardConstraintOn__Q24Game9EnemyBaseFv
/* 802BFE88 002BCDC8  80 7F 01 E0 */	lwz r3, 0x1e0(r31)
/* 802BFE8C 002BCDCC  38 80 FF FF */	li r4, -1
/* 802BFE90 002BCDD0  C0 02 E1 98 */	lfs f0, lbl_8051C4F8@sda21(r2)
/* 802BFE94 002BCDD4  38 00 00 00 */	li r0, 0
/* 802BFE98 002BCDD8  54 65 06 B0 */	rlwinm r5, r3, 0, 0x1a, 0x18
/* 802BFE9C 002BCDDC  7F E3 FB 78 */	mr r3, r31
/* 802BFEA0 002BCDE0  90 BF 01 E0 */	stw r5, 0x1e0(r31)
/* 802BFEA4 002BCDE4  80 BF 01 E0 */	lwz r5, 0x1e0(r31)
/* 802BFEA8 002BCDE8  54 A5 05 24 */	rlwinm r5, r5, 0, 0x14, 0x12
/* 802BFEAC 002BCDEC  90 BF 01 E0 */	stw r5, 0x1e0(r31)
/* 802BFEB0 002BCDF0  80 BF 01 E0 */	lwz r5, 0x1e0(r31)
/* 802BFEB4 002BCDF4  54 A5 06 6E */	rlwinm r5, r5, 0, 0x19, 0x17
/* 802BFEB8 002BCDF8  90 BF 01 E0 */	stw r5, 0x1e0(r31)
/* 802BFEBC 002BCDFC  D0 1F 02 C0 */	stfs f0, 0x2c0(r31)
/* 802BFEC0 002BCE00  D0 1F 02 C4 */	stfs f0, 0x2c4(r31)
/* 802BFEC4 002BCE04  D0 1F 02 C8 */	stfs f0, 0x2c8(r31)
/* 802BFEC8 002BCE08  90 9F 02 D0 */	stw r4, 0x2d0(r31)
/* 802BFECC 002BCE0C  C0 1F 01 98 */	lfs f0, 0x198(r31)
/* 802BFED0 002BCE10  D0 1F 02 D4 */	stfs f0, 0x2d4(r31)
/* 802BFED4 002BCE14  C0 1F 01 9C */	lfs f0, 0x19c(r31)
/* 802BFED8 002BCE18  D0 1F 02 D8 */	stfs f0, 0x2d8(r31)
/* 802BFEDC 002BCE1C  C0 1F 01 A0 */	lfs f0, 0x1a0(r31)
/* 802BFEE0 002BCE20  D0 1F 02 DC */	stfs f0, 0x2dc(r31)
/* 802BFEE4 002BCE24  98 1F 02 EC */	stb r0, 0x2ec(r31)
/* 802BFEE8 002BCE28  48 00 0C A1 */	bl setupIKSystem__Q34Game6Houdai3ObjFv
/* 802BFEEC 002BCE2C  7F E3 FB 78 */	mr r3, r31
/* 802BFEF0 002BCE30  48 00 10 B5 */	bl setupShadowSystem__Q34Game6Houdai3ObjFv
/* 802BFEF4 002BCE34  7F E3 FB 78 */	mr r3, r31
/* 802BFEF8 002BCE38  48 00 05 F1 */	bl setTargetPattern__Q34Game6Houdai3ObjFv
/* 802BFEFC 002BCE3C  C0 02 E1 98 */	lfs f0, lbl_8051C4F8@sda21(r2)
/* 802BFF00 002BCE40  38 00 00 00 */	li r0, 0
/* 802BFF04 002BCE44  7F E3 FB 78 */	mr r3, r31
/* 802BFF08 002BCE48  D0 1F 02 CC */	stfs f0, 0x2cc(r31)
/* 802BFF0C 002BCE4C  98 1F 02 ED */	stb r0, 0x2ed(r31)
/* 802BFF10 002BCE50  C0 1F 01 98 */	lfs f0, 0x198(r31)
/* 802BFF14 002BCE54  D0 1F 02 E0 */	stfs f0, 0x2e0(r31)
/* 802BFF18 002BCE58  C0 1F 01 9C */	lfs f0, 0x19c(r31)
/* 802BFF1C 002BCE5C  D0 1F 02 E4 */	stfs f0, 0x2e4(r31)
/* 802BFF20 002BCE60  C0 1F 01 A0 */	lfs f0, 0x1a0(r31)
/* 802BFF24 002BCE64  D0 1F 02 E8 */	stfs f0, 0x2e8(r31)
/* 802BFF28 002BCE68  48 00 12 99 */	bl setupShotGun__Q34Game6Houdai3ObjFv
/* 802BFF2C 002BCE6C  7F E3 FB 78 */	mr r3, r31
/* 802BFF30 002BCE70  48 00 14 9D */	bl setupCollision__Q34Game6Houdai3ObjFv
/* 802BFF34 002BCE74  7F E3 FB 78 */	mr r3, r31
/* 802BFF38 002BCE78  48 00 21 F9 */	bl setupEffect__Q34Game6Houdai3ObjFv
/* 802BFF3C 002BCE7C  7F E3 FB 78 */	mr r3, r31
/* 802BFF40 002BCE80  38 80 00 00 */	li r4, 0
/* 802BFF44 002BCE84  48 00 2D 49 */	bl startSteamEffect__Q34Game6Houdai3ObjFb
/* 802BFF48 002BCE88  38 00 00 00 */	li r0, 0
/* 802BFF4C 002BCE8C  7F E3 FB 78 */	mr r3, r31
/* 802BFF50 002BCE90  98 1F 02 EF */	stb r0, 0x2ef(r31)
/* 802BFF54 002BCE94  48 00 1A 99 */	bl resetBossAppearBGM__Q34Game6Houdai3ObjFv
/* 802BFF58 002BCE98  80 6D 96 80 */	lwz r3, shadowMgr__4Game@sda21(r13)
/* 802BFF5C 002BCE9C  7F E4 FB 78 */	mr r4, r31
/* 802BFF60 002BCEA0  4B F8 1D 91 */	bl delShadow__Q24Game9ShadowMgrFPQ24Game8Creature
/* 802BFF64 002BCEA4  80 7F 02 BC */	lwz r3, 0x2bc(r31)
/* 802BFF68 002BCEA8  7F E4 FB 78 */	mr r4, r31
/* 802BFF6C 002BCEAC  38 A0 00 01 */	li r5, 1
/* 802BFF70 002BCEB0  38 C0 00 00 */	li r6, 0
/* 802BFF74 002BCEB4  81 83 00 00 */	lwz r12, 0(r3)
/* 802BFF78 002BCEB8  81 8C 00 0C */	lwz r12, 0xc(r12)
/* 802BFF7C 002BCEBC  7D 89 03 A6 */	mtctr r12
/* 802BFF80 002BCEC0  4E 80 04 21 */	bctrl 
mr r3, r31
bl startMatAnimator__Q34Game6Houdai3ObjFv
/* 802BFF84 002BCEC4  7F E3 FB 78 */	mr r3, r31
/* 802BFF88 002BCEC8  81 9F 00 00 */	lwz r12, 0(r31)
/* 802BFF8C 002BCECC  81 8C 01 DC */	lwz r12, 0x1dc(r12)
/* 802BFF90 002BCED0  7D 89 03 A6 */	mtctr r12
/* 802BFF94 002BCED4  4E 80 04 21 */	bctrl 
/* 802BFF98 002BCED8  80 01 00 14 */	lwz r0, 0x14(r1)
/* 802BFF9C 002BCEDC  83 E1 00 0C */	lwz r31, 0xc(r1)
/* 802BFFA0 002BCEE0  7C 08 03 A6 */	mtlr r0
/* 802BFFA4 002BCEE4  38 21 00 10 */	addi r1, r1, 0x10
/* 802BFFA8 002BCEE8  4E 80 00 20 */	blr 

.global onKill__Q34Game6Houdai3ObjFPQ24Game15CreatureKillArg
onKill__Q34Game6Houdai3ObjFPQ24Game15CreatureKillArg:
/* 802BFFAC 002BCEEC  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 802BFFB0 002BCEF0  7C 08 02 A6 */	mflr r0
/* 802BFFB4 002BCEF4  90 01 00 14 */	stw r0, 0x14(r1)
/* 802BFFB8 002BCEF8  93 E1 00 0C */	stw r31, 0xc(r1)
/* 802BFFBC 002BCEFC  7C 9F 23 78 */	mr r31, r4
/* 802BFFC0 002BCF00  93 C1 00 08 */	stw r30, 8(r1)
/* 802BFFC4 002BCF04  7C 7E 1B 78 */	mr r30, r3
/* 802BFFC8 002BCF08  48 00 2D 41 */	bl finishSteamEffect__Q34Game6Houdai3ObjFv
/* 802BFFCC 002BCF0C  7F C3 F3 78 */	mr r3, r30
/* 802BFFD0 002BCF10  48 00 2E 01 */	bl finishChimneyEffect__Q34Game6Houdai3ObjFv
/* 802BFFD4 002BCF14  7F C3 F3 78 */	mr r3, r30
/* 802BFFD8 002BCF18  48 00 13 D1 */	bl forceFinishShotGun__Q34Game6Houdai3ObjFv
/* 802BFFDC 002BCF1C  7F C3 F3 78 */	mr r3, r30
/* 802BFFE0 002BCF20  7F E4 FB 78 */	mr r4, r31
/* 802BFFE4 002BCF24  4B E4 1F 05 */	bl onKill__Q24Game9EnemyBaseFPQ24Game15CreatureKillArg
/* 802BFFE8 002BCF28  80 01 00 14 */	lwz r0, 0x14(r1)
/* 802BFFEC 002BCF2C  83 E1 00 0C */	lwz r31, 0xc(r1)
/* 802BFFF0 002BCF30  83 C1 00 08 */	lwz r30, 8(r1)
/* 802BFFF4 002BCF34  7C 08 03 A6 */	mtlr r0
/* 802BFFF8 002BCF38  38 21 00 10 */	addi r1, r1, 0x10
/* 802BFFFC 002BCF3C  4E 80 00 20 */	blr 

.global setParameters__Q34Game6Houdai3ObjFv
setParameters__Q34Game6Houdai3ObjFv:
/* 802C0000 002BCF40  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 802C0004 002BCF44  7C 08 02 A6 */	mflr r0
/* 802C0008 002BCF48  90 01 00 14 */	stw r0, 0x14(r1)
/* 802C000C 002BCF4C  93 E1 00 0C */	stw r31, 0xc(r1)
/* 802C0010 002BCF50  7C 7F 1B 78 */	mr r31, r3
/* 802C0014 002BCF54  80 8D 93 E8 */	lwz r4, gameSystem__4Game@sda21(r13)
/* 802C0018 002BCF58  28 04 00 00 */	cmplwi r4, 0
/* 802C001C 002BCF5C  41 82 00 50 */	beq .L_802C006C
/* 802C0020 002BCF60  88 04 00 48 */	lbz r0, 0x48(r4)
/* 802C0024 002BCF64  28 00 00 00 */	cmplwi r0, 0
/* 802C0028 002BCF68  41 82 00 44 */	beq .L_802C006C
/* 802C002C 002BCF6C  80 04 00 44 */	lwz r0, 0x44(r4)
/* 802C0030 002BCF70  2C 00 00 00 */	cmpwi r0, 0
/* 802C0034 002BCF74  40 82 00 38 */	bne .L_802C006C
/* 802C0038 002BCF78  80 64 00 58 */	lwz r3, 0x58(r4)
/* 802C003C 002BCF7C  28 03 00 00 */	cmplwi r3, 0
/* 802C0040 002BCF80  41 82 00 2C */	beq .L_802C006C
/* 802C0044 002BCF84  81 83 00 00 */	lwz r12, 0(r3)
/* 802C0048 002BCF88  81 8C 00 78 */	lwz r12, 0x78(r12)
/* 802C004C 002BCF8C  7D 89 03 A6 */	mtctr r12
/* 802C0050 002BCF90  4E 80 04 21 */	bctrl 
/* 802C0054 002BCF94  3C 03 93 A1 */	addis r0, r3, 0x93a1
/* 802C0058 002BCF98  28 00 30 32 */	cmplwi r0, 0x3032
/* 802C005C 002BCF9C  40 82 00 10 */	bne .L_802C006C
/* 802C0060 002BCFA0  80 7F 00 C0 */	lwz r3, 0xc0(r31)
/* 802C0064 002BCFA4  C0 03 09 AC */	lfs f0, 0x9ac(r3)
/* 802C0068 002BCFA8  D0 03 03 5C */	stfs f0, 0x35c(r3)
.L_802C006C:
/* 802C006C 002BCFAC  7F E3 FB 78 */	mr r3, r31
/* 802C0070 002BCFB0  4B E4 2B 69 */	bl setParameters__Q24Game9EnemyBaseFv
/* 802C0074 002BCFB4  80 01 00 14 */	lwz r0, 0x14(r1)
/* 802C0078 002BCFB8  83 E1 00 0C */	lwz r31, 0xc(r1)
/* 802C007C 002BCFBC  7C 08 03 A6 */	mtlr r0
/* 802C0080 002BCFC0  38 21 00 10 */	addi r1, r1, 0x10
/* 802C0084 002BCFC4  4E 80 00 20 */	blr 

.global doUpdateCommon__Q34Game6Houdai3ObjFv
doUpdateCommon__Q34Game6Houdai3ObjFv:
/* 802C013C 002BD07C  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 802C0140 002BD080  7C 08 02 A6 */	mflr r0
/* 802C0144 002BD084  90 01 00 14 */	stw r0, 0x14(r1)
/* 802C0148 002BD088  93 E1 00 0C */	stw r31, 0xc(r1)
/* 802C014C 002BD08C  7C 7F 1B 78 */	mr r31, r3
/* 802C0150 002BD090  4B E4 2D C5 */	bl doUpdateCommon__Q24Game9EnemyBaseFv
/* 802C0154 002BD094  7F E3 FB 78 */	mr r3, r31
/* 802C0158 002BD098  48 00 11 1D */	bl doUpdateCommonShotGun__Q34Game6Houdai3ObjFv
/* 802C015C 002BD09C  7F E3 FB 78 */	mr r3, r31
/* 802C0160 002BD0A0  48 00 17 91 */	bl updateBossBGM__Q34Game6Houdai3ObjFv
/* 802C0164 002BD0A4  80 01 00 14 */	lwz r0, 0x14(r1)
/* 802C0168 002BD0A8  83 E1 00 0C */	lwz r31, 0xc(r1)
/* 802C016C 002BD0AC  7C 08 03 A6 */	mtlr r0
/* 802C0170 002BD0B0  38 21 00 10 */	addi r1, r1, 0x10
/* 802C0174 002BD0B4  4E 80 00 20 */	blr 

.global doAnimationCullingOff__Q34Game6Houdai3ObjFv
doAnimationCullingOff__Q34Game6Houdai3ObjFv:
/* 802C0178 002BD0B8  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 802C017C 002BD0BC  7C 08 02 A6 */	mflr r0
/* 802C0180 002BD0C0  90 01 00 14 */	stw r0, 0x14(r1)
/* 802C0184 002BD0C4  93 E1 00 0C */	stw r31, 0xc(r1)
/* 802C0188 002BD0C8  7C 7F 1B 78 */	mr r31, r3
/* 802C018C 002BD0CC  48 00 10 A1 */	bl setShotGunCallBack__Q34Game6Houdai3ObjFv
/* 802C0190 002BD0D0  80 9F 01 88 */	lwz r4, 0x188(r31)
/* 802C0194 002BD0D4  38 00 00 00 */	li r0, 0
/* 802C0198 002BD0D8  7F E3 FB 78 */	mr r3, r31
/* 802C019C 002BD0DC  98 04 00 24 */	stb r0, 0x24(r4)
/* 802C01A0 002BD0E0  81 9F 00 00 */	lwz r12, 0(r31)
/* 802C01A4 002BD0E4  81 8C 01 D8 */	lwz r12, 0x1d8(r12)
/* 802C01A8 002BD0E8  7D 89 03 A6 */	mtctr r12
/* 802C01AC 002BD0EC  4E 80 04 21 */	bctrl 
/* 802C01B0 002BD0F0  7F E3 FB 78 */	mr r3, r31
/* 802C01B4 002BD0F4  48 00 0C 09 */	bl doAnimationIKSystem__Q34Game6Houdai3ObjFv
/* 802C01B8 002BD0F8  80 9F 01 74 */	lwz r4, 0x174(r31)
/* 802C01BC 002BD0FC  38 7F 01 38 */	addi r3, r31, 0x138
/* 802C01C0 002BD100  80 84 00 08 */	lwz r4, 8(r4)
/* 802C01C4 002BD104  38 84 00 24 */	addi r4, r4, 0x24
/* 802C01C8 002BD108  4B E2 A1 05 */	bl PSMTXCopy
/* 802C01CC 002BD10C  80 7F 01 74 */	lwz r3, 0x174(r31)
/* 802C01D0 002BD110  80 63 00 08 */	lwz r3, 8(r3)
/* 802C01D4 002BD114  81 83 00 00 */	lwz r12, 0(r3)
/* 802C01D8 002BD118  81 8C 00 10 */	lwz r12, 0x10(r12)
/* 802C01DC 002BD11C  7D 89 03 A6 */	mtctr r12
/* 802C01E0 002BD120  4E 80 04 21 */	bctrl 
/* 802C01E4 002BD124  80 7F 01 14 */	lwz r3, 0x114(r31)
/* 802C01E8 002BD128  4B E7 58 B5 */	bl update__8CollTreeFv
/* 802C01EC 002BD12C  7F E3 FB 78 */	mr r3, r31
/* 802C01F0 002BD130  48 00 0E 29 */	bl doAnimationShadowSystem__Q34Game6Houdai3ObjFv
/* 802C01F4 002BD134  7F E3 FB 78 */	mr r3, r31
/* 802C01F8 002BD138  48 00 0C 25 */	bl finishAnimationIKSystem__Q34Game6Houdai3ObjFv
/* 802C01FC 002BD13C  7F E3 FB 78 */	mr r3, r31
/* 802C0200 002BD140  48 00 10 09 */	bl resetShotGunCallBack__Q34Game6Houdai3ObjFv
/* 802C0204 002BD144  80 01 00 14 */	lwz r0, 0x14(r1)
/* 802C0208 002BD148  83 E1 00 0C */	lwz r31, 0xc(r1)
/* 802C020C 002BD14C  7C 08 03 A6 */	mtlr r0
/* 802C0210 002BD150  38 21 00 10 */	addi r1, r1, 0x10
/* 802C0214 002BD154  4E 80 00 20 */	blr 

.global doDirectDraw__Q34Game6Houdai3ObjFR8Graphics
doDirectDraw__Q34Game6Houdai3ObjFR8Graphics:
/* 802C0218 002BD158  4E 80 00 20 */	blr 

.global doDebugDraw__Q34Game6Houdai3ObjFR8Graphics
doDebugDraw__Q34Game6Houdai3ObjFR8Graphics:
/* 802C021C 002BD15C  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 802C0220 002BD160  7C 08 02 A6 */	mflr r0
/* 802C0224 002BD164  90 01 00 14 */	stw r0, 0x14(r1)
/* 802C0228 002BD168  4B E4 5C 45 */	bl doDebugDraw__Q24Game9EnemyBaseFR8Graphics
/* 802C022C 002BD16C  80 01 00 14 */	lwz r0, 0x14(r1)
/* 802C0230 002BD170  7C 08 03 A6 */	mtlr r0
/* 802C0234 002BD174  38 21 00 10 */	addi r1, r1, 0x10
/* 802C0238 002BD178  4E 80 00 20 */	blr 

.global setFSM__Q34Game6Houdai3ObjFPQ34Game6Houdai3FSM
setFSM__Q34Game6Houdai3ObjFPQ34Game6Houdai3FSM:
/* 802C023C 002BD17C  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 802C0240 002BD180  7C 08 02 A6 */	mflr r0
/* 802C0244 002BD184  90 01 00 14 */	stw r0, 0x14(r1)
/* 802C0248 002BD188  93 E1 00 0C */	stw r31, 0xc(r1)
/* 802C024C 002BD18C  7C 7F 1B 78 */	mr r31, r3
/* 802C0250 002BD190  90 83 02 BC */	stw r4, 0x2bc(r3)
/* 802C0254 002BD194  7F E4 FB 78 */	mr r4, r31
/* 802C0258 002BD198  80 63 02 BC */	lwz r3, 0x2bc(r3)
/* 802C025C 002BD19C  81 83 00 00 */	lwz r12, 0(r3)
/* 802C0260 002BD1A0  81 8C 00 08 */	lwz r12, 8(r12)
/* 802C0264 002BD1A4  7D 89 03 A6 */	mtctr r12
/* 802C0268 002BD1A8  4E 80 04 21 */	bctrl 
/* 802C026C 002BD1AC  38 00 00 00 */	li r0, 0
/* 802C0270 002BD1B0  90 1F 02 B4 */	stw r0, 0x2b4(r31)
/* 802C0274 002BD1B4  80 01 00 14 */	lwz r0, 0x14(r1)
/* 802C0278 002BD1B8  83 E1 00 0C */	lwz r31, 0xc(r1)
/* 802C027C 002BD1BC  7C 08 03 A6 */	mtlr r0
/* 802C0280 002BD1C0  38 21 00 10 */	addi r1, r1, 0x10
/* 802C0284 002BD1C4  4E 80 00 20 */	blr 

.global getShadowParam__Q34Game6Houdai3ObjFRQ24Game11ShadowParam
getShadowParam__Q34Game6Houdai3ObjFRQ24Game11ShadowParam:
/* 802C0288 002BD1C8  C0 03 01 8C */	lfs f0, 0x18c(r3)
/* 802C028C 002BD1CC  C0 42 E1 98 */	lfs f2, lbl_8051C4F8@sda21(r2)
/* 802C0290 002BD1D0  D0 04 00 00 */	stfs f0, 0(r4)
/* 802C0294 002BD1D4  C0 22 E1 9C */	lfs f1, lbl_8051C4FC@sda21(r2)
/* 802C0298 002BD1D8  C0 63 01 90 */	lfs f3, 0x190(r3)
/* 802C029C 002BD1DC  C0 02 E1 A0 */	lfs f0, lbl_8051C500@sda21(r2)
/* 802C02A0 002BD1E0  D0 64 00 04 */	stfs f3, 4(r4)
/* 802C02A4 002BD1E4  C0 63 01 94 */	lfs f3, 0x194(r3)
/* 802C02A8 002BD1E8  D0 64 00 08 */	stfs f3, 8(r4)
/* 802C02AC 002BD1EC  D0 44 00 0C */	stfs f2, 0xc(r4)
/* 802C02B0 002BD1F0  D0 24 00 10 */	stfs f1, 0x10(r4)
/* 802C02B4 002BD1F4  D0 44 00 14 */	stfs f2, 0x14(r4)
/* 802C02B8 002BD1F8  D0 04 00 18 */	stfs f0, 0x18(r4)
/* 802C02BC 002BD1FC  D0 04 00 1C */	stfs f0, 0x1c(r4)
/* 802C02C0 002BD200  4E 80 00 20 */	blr 

.global damageCallBack__Q34Game6Houdai3ObjFPQ24Game8CreaturefP8CollPart
damageCallBack__Q34Game6Houdai3ObjFPQ24Game8CreaturefP8CollPart:
/* 802C02C4 002BD204  94 21 FF E0 */	stwu r1, -0x20(r1)
/* 802C02C8 002BD208  7C 08 02 A6 */	mflr r0
/* 802C02CC 002BD20C  90 01 00 24 */	stw r0, 0x24(r1)
/* 802C02D0 002BD210  DB E1 00 10 */	stfd f31, 0x10(r1)
/* 802C02D4 002BD214  F3 E1 00 18 */	psq_st f31, 24(r1), 0, qr0
/* 802C02D8 002BD218  93 E1 00 0C */	stw r31, 0xc(r1)
/* 802C02DC 002BD21C  93 C1 00 08 */	stw r30, 8(r1)
/* 802C02E0 002BD220  7C 9F 23 79 */	or. r31, r4, r4
/* 802C02E4 002BD224  FF E0 08 90 */	fmr f31, f1
/* 802C02E8 002BD228  7C 7E 1B 78 */	mr r30, r3
/* 802C02EC 002BD22C  41 82 00 68 */	beq .L_802C0354
/* 802C02F0 002BD230  28 05 00 00 */	cmplwi r5, 0
/* 802C02F4 002BD234  41 82 00 60 */	beq .L_802C0354
/* 802C02F8 002BD238  7F E3 FB 78 */	mr r3, r31
/* 802C02FC 002BD23C  81 9F 00 00 */	lwz r12, 0(r31)
/* 802C0300 002BD240  81 8C 00 18 */	lwz r12, 0x18(r12)
/* 802C0304 002BD244  7D 89 03 A6 */	mtctr r12
/* 802C0308 002BD248  4E 80 04 21 */	bctrl 
/* 802C030C 002BD24C  54 60 06 3F */	clrlwi. r0, r3, 0x18
/* 802C0310 002BD250  41 82 00 44 */	beq .L_802C0354
/* 802C0314 002BD254  7F E3 FB 78 */	mr r3, r31
/* 802C0318 002BD258  4B ED F2 5D */	bl isStickTo__Q24Game8CreatureFv
/* 802C031C 002BD25C  54 60 06 3F */	clrlwi. r0, r3, 0x18
/* 802C0320 002BD260  41 82 00 34 */	beq .L_802C0354
/* 802C0324 002BD264  7F C3 F3 78 */	mr r3, r30
/* 802C0328 002BD268  4B E4 70 CD */	bl getStateID__Q24Game9EnemyBaseFv
/* 802C032C 002BD26C  2C 03 00 02 */	cmpwi r3, 2
/* 802C0330 002BD270  40 82 00 0C */	bne .L_802C033C
/* 802C0334 002BD274  C0 02 E1 A4 */	lfs f0, lbl_8051C504@sda21(r2)
/* 802C0338 002BD278  EF FF 00 32 */	fmuls f31, f31, f0
.L_802C033C:
/* 802C033C 002BD27C  FC 20 F8 90 */	fmr f1, f31
/* 802C0340 002BD280  C0 42 E1 9C */	lfs f2, lbl_8051C4FC@sda21(r2)
/* 802C0344 002BD284  7F C3 F3 78 */	mr r3, r30
/* 802C0348 002BD288  4B E4 5C E5 */	bl addDamage__Q24Game9EnemyBaseFff
/* 802C034C 002BD28C  38 60 00 01 */	li r3, 1
/* 802C0350 002BD290  48 00 00 08 */	b .L_802C0358
.L_802C0354:
/* 802C0354 002BD294  38 60 00 00 */	li r3, 0
.L_802C0358:
/* 802C0358 002BD298  E3 E1 00 18 */	psq_l f31, 24(r1), 0, qr0
/* 802C035C 002BD29C  80 01 00 24 */	lwz r0, 0x24(r1)
/* 802C0360 002BD2A0  CB E1 00 10 */	lfd f31, 0x10(r1)
/* 802C0364 002BD2A4  83 E1 00 0C */	lwz r31, 0xc(r1)
/* 802C0368 002BD2A8  83 C1 00 08 */	lwz r30, 8(r1)
/* 802C036C 002BD2AC  7C 08 03 A6 */	mtlr r0
/* 802C0370 002BD2B0  38 21 00 20 */	addi r1, r1, 0x20
/* 802C0374 002BD2B4  4E 80 00 20 */	blr 

.global doStartStoneState__Q34Game6Houdai3ObjFv
doStartStoneState__Q34Game6Houdai3ObjFv:
/* 802C0378 002BD2B8  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 802C037C 002BD2BC  7C 08 02 A6 */	mflr r0
/* 802C0380 002BD2C0  90 01 00 14 */	stw r0, 0x14(r1)
/* 802C0384 002BD2C4  93 E1 00 0C */	stw r31, 0xc(r1)
/* 802C0388 002BD2C8  7C 7F 1B 78 */	mr r31, r3
/* 802C038C 002BD2CC  4B E4 2B 69 */	bl doStartStoneState__Q24Game9EnemyBaseFv
/* 802C0390 002BD2D0  7F E3 FB 78 */	mr r3, r31
/* 802C0394 002BD2D4  48 00 24 8D */	bl finishPinchJointEffect__Q34Game6Houdai3ObjFv
/* 802C0398 002BD2D8  7F E3 FB 78 */	mr r3, r31
/* 802C039C 002BD2DC  48 00 29 6D */	bl finishSteamEffect__Q34Game6Houdai3ObjFv
/* 802C03A0 002BD2E0  7F E3 FB 78 */	mr r3, r31
/* 802C03A4 002BD2E4  48 00 2A 2D */	bl finishChimneyEffect__Q34Game6Houdai3ObjFv
/* 802C03A8 002BD2E8  80 7F 03 00 */	lwz r3, 0x300(r31)
/* 802C03AC 002BD2EC  48 00 54 01 */	bl startStoneStateEffectOff__Q34Game6Houdai16HoudaiShotGunMgrFv
/* 802C03B0 002BD2F0  7F E3 FB 78 */	mr r3, r31
/* 802C03B4 002BD2F4  48 00 12 CD */	bl startStoneStateBossAttackLoopBGM__Q34Game6Houdai3ObjFv
/* 802C03B8 002BD2F8  80 01 00 14 */	lwz r0, 0x14(r1)
/* 802C03BC 002BD2FC  83 E1 00 0C */	lwz r31, 0xc(r1)
/* 802C03C0 002BD300  7C 08 03 A6 */	mtlr r0
/* 802C03C4 002BD304  38 21 00 10 */	addi r1, r1, 0x10
/* 802C03C8 002BD308  4E 80 00 20 */	blr 

.global doFinishStoneState__Q34Game6Houdai3ObjFv
doFinishStoneState__Q34Game6Houdai3ObjFv:
/* 802C03CC 002BD30C  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 802C03D0 002BD310  7C 08 02 A6 */	mflr r0
/* 802C03D4 002BD314  90 01 00 14 */	stw r0, 0x14(r1)
/* 802C03D8 002BD318  93 E1 00 0C */	stw r31, 0xc(r1)
/* 802C03DC 002BD31C  7C 7F 1B 78 */	mr r31, r3
/* 802C03E0 002BD320  4B E4 2B 29 */	bl doFinishStoneState__Q24Game9EnemyBaseFv
/* 802C03E4 002BD324  C0 22 E1 9C */	lfs f1, lbl_8051C4FC@sda21(r2)
/* 802C03E8 002BD328  7F E3 FB 78 */	mr r3, r31
/* 802C03EC 002BD32C  C0 42 E1 A8 */	lfs f2, lbl_8051C508@sda21(r2)
/* 802C03F0 002BD330  38 80 00 00 */	li r4, 0
/* 802C03F4 002BD334  C0 62 E1 98 */	lfs f3, lbl_8051C4F8@sda21(r2)
/* 802C03F8 002BD338  C0 82 E1 AC */	lfs f4, lbl_8051C50C@sda21(r2)
/* 802C03FC 002BD33C  4B E5 2D 21 */	bl "flickStickPikmin__Q24Game9EnemyFuncFPQ24Game8CreatureffffP23Condition<Q24Game4Piki>"
/* 802C0400 002BD340  88 1F 02 EC */	lbz r0, 0x2ec(r31)
/* 802C0404 002BD344  28 00 00 00 */	cmplwi r0, 0
/* 802C0408 002BD348  41 82 00 0C */	beq .L_802C0414
/* 802C040C 002BD34C  7F E3 FB 78 */	mr r3, r31
/* 802C0410 002BD350  48 00 23 B5 */	bl startPinchJointEffect__Q34Game6Houdai3ObjFv
.L_802C0414:
/* 802C0414 002BD354  7F E3 FB 78 */	mr r3, r31
/* 802C0418 002BD358  38 80 00 01 */	li r4, 1
/* 802C041C 002BD35C  48 00 28 71 */	bl startSteamEffect__Q34Game6Houdai3ObjFb
/* 802C0420 002BD360  80 7F 03 00 */	lwz r3, 0x300(r31)
/* 802C0424 002BD364  48 00 53 B9 */	bl finishStoneStateEffectOn__Q34Game6Houdai16HoudaiShotGunMgrFv
/* 802C0428 002BD368  7F E3 FB 78 */	mr r3, r31
/* 802C042C 002BD36C  48 00 13 29 */	bl finishStoneStateBossAttackLoopBGM__Q34Game6Houdai3ObjFv
/* 802C0430 002BD370  80 01 00 14 */	lwz r0, 0x14(r1)
/* 802C0434 002BD374  83 E1 00 0C */	lwz r31, 0xc(r1)
/* 802C0438 002BD378  7C 08 03 A6 */	mtlr r0
/* 802C043C 002BD37C  38 21 00 10 */	addi r1, r1, 0x10
/* 802C0440 002BD380  4E 80 00 20 */	blr 

.global doStartMovie__Q34Game6Houdai3ObjFv
doStartMovie__Q34Game6Houdai3ObjFv:
/* 802C0444 002BD384  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 802C0448 002BD388  7C 08 02 A6 */	mflr r0
/* 802C044C 002BD38C  90 01 00 14 */	stw r0, 0x14(r1)
/* 802C0450 002BD390  48 00 2E 3D */	bl effectDrawOff__Q34Game6Houdai3ObjFv
/* 802C0454 002BD394  80 01 00 14 */	lwz r0, 0x14(r1)
/* 802C0458 002BD398  7C 08 03 A6 */	mtlr r0
/* 802C045C 002BD39C  38 21 00 10 */	addi r1, r1, 0x10
/* 802C0460 002BD3A0  4E 80 00 20 */	blr 

.global doEndMovie__Q34Game6Houdai3ObjFv
doEndMovie__Q34Game6Houdai3ObjFv:
/* 802C0464 002BD3A4  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 802C0468 002BD3A8  7C 08 02 A6 */	mflr r0
/* 802C046C 002BD3AC  90 01 00 14 */	stw r0, 0x14(r1)
/* 802C0470 002BD3B0  48 00 2C A1 */	bl effectDrawOn__Q34Game6Houdai3ObjFv
/* 802C0474 002BD3B4  80 01 00 14 */	lwz r0, 0x14(r1)
/* 802C0478 002BD3B8  7C 08 03 A6 */	mtlr r0
/* 802C047C 002BD3BC  38 21 00 10 */	addi r1, r1, 0x10
/* 802C0480 002BD3C0  4E 80 00 20 */	blr 

.global "getThrowupItemPosition__Q34Game6Houdai3ObjFP10Vector3<f>"
"getThrowupItemPosition__Q34Game6Houdai3ObjFP10Vector3<f>":
/* 802C0484 002BD3C4  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 802C0488 002BD3C8  7C 08 02 A6 */	mflr r0
/* 802C048C 002BD3CC  90 01 00 14 */	stw r0, 0x14(r1)
/* 802C0490 002BD3D0  93 E1 00 0C */	stw r31, 0xc(r1)
/* 802C0494 002BD3D4  7C 9F 23 78 */	mr r31, r4
/* 802C0498 002BD3D8  38 82 E1 B0 */	addi r4, r2, lbl_8051C510@sda21
/* 802C049C 002BD3DC  80 63 01 74 */	lwz r3, 0x174(r3)
/* 802C04A0 002BD3E0  48 17 EB 45 */	bl getJoint__Q28SysShape5ModelFPc
/* 802C04A4 002BD3E4  48 16 93 FD */	bl getWorldMatrix__Q28SysShape5JointFv
/* 802C04A8 002BD3E8  C0 43 00 2C */	lfs f2, 0x2c(r3)
/* 802C04AC 002BD3EC  C0 23 00 1C */	lfs f1, 0x1c(r3)
/* 802C04B0 002BD3F0  C0 03 00 0C */	lfs f0, 0xc(r3)
/* 802C04B4 002BD3F4  D0 1F 00 00 */	stfs f0, 0(r31)
/* 802C04B8 002BD3F8  D0 3F 00 04 */	stfs f1, 4(r31)
/* 802C04BC 002BD3FC  D0 5F 00 08 */	stfs f2, 8(r31)
/* 802C04C0 002BD400  83 E1 00 0C */	lwz r31, 0xc(r1)
/* 802C04C4 002BD404  80 01 00 14 */	lwz r0, 0x14(r1)
/* 802C04C8 002BD408  7C 08 03 A6 */	mtlr r0
/* 802C04CC 002BD40C  38 21 00 10 */	addi r1, r1, 0x10
/* 802C04D0 002BD410  4E 80 00 20 */	blr 

.global "getThrowupItemVelocity__Q34Game6Houdai3ObjFP10Vector3<f>"
"getThrowupItemVelocity__Q34Game6Houdai3ObjFP10Vector3<f>":
/* 802C04D4 002BD414  C0 02 E1 98 */	lfs f0, lbl_8051C4F8@sda21(r2)
/* 802C04D8 002BD418  D0 04 00 08 */	stfs f0, 8(r4)
/* 802C04DC 002BD41C  D0 04 00 04 */	stfs f0, 4(r4)
/* 802C04E0 002BD420  D0 04 00 00 */	stfs f0, 0(r4)
/* 802C04E4 002BD424  4E 80 00 20 */	blr 

.global setTargetPattern__Q34Game6Houdai3ObjFv
setTargetPattern__Q34Game6Houdai3ObjFv:
/* 802C04E8 002BD428  94 21 FF E0 */	stwu r1, -0x20(r1)
/* 802C04EC 002BD42C  7C 08 02 A6 */	mflr r0
/* 802C04F0 002BD430  90 01 00 24 */	stw r0, 0x24(r1)
/* 802C04F4 002BD434  38 00 00 01 */	li r0, 1
/* 802C04F8 002BD438  93 E1 00 1C */	stw r31, 0x1c(r1)
/* 802C04FC 002BD43C  7C 7F 1B 78 */	mr r31, r3
/* 802C0500 002BD440  98 03 02 EE */	stb r0, 0x2ee(r3)
/* 802C0504 002BD444  80 6D 93 E8 */	lwz r3, gameSystem__4Game@sda21(r13)
/* 802C0508 002BD448  28 03 00 00 */	cmplwi r3, 0
/* 802C050C 002BD44C  41 82 00 90 */	beq .L_802C059C
/* 802C0510 002BD450  88 03 00 48 */	lbz r0, 0x48(r3)
/* 802C0514 002BD454  28 00 00 00 */	cmplwi r0, 0
/* 802C0518 002BD458  41 82 00 84 */	beq .L_802C059C
/* 802C051C 002BD45C  80 03 00 44 */	lwz r0, 0x44(r3)
/* 802C0520 002BD460  2C 00 00 00 */	cmpwi r0, 0
/* 802C0524 002BD464  40 82 00 78 */	bne .L_802C059C
/* 802C0528 002BD468  80 63 00 58 */	lwz r3, 0x58(r3)
/* 802C052C 002BD46C  28 03 00 00 */	cmplwi r3, 0
/* 802C0530 002BD470  41 82 00 6C */	beq .L_802C059C
/* 802C0534 002BD474  81 83 00 00 */	lwz r12, 0(r3)
/* 802C0538 002BD478  81 8C 00 78 */	lwz r12, 0x78(r12)
/* 802C053C 002BD47C  7D 89 03 A6 */	mtctr r12
/* 802C0540 002BD480  4E 80 04 21 */	bctrl 
/* 802C0544 002BD484  3C 03 93 A1 */	addis r0, r3, 0x93a1
/* 802C0548 002BD488  28 00 30 32 */	cmplwi r0, 0x3032
/* 802C054C 002BD48C  40 82 00 50 */	bne .L_802C059C
/* 802C0550 002BD490  4B E0 90 51 */	bl rand
/* 802C0554 002BD494  6C 63 80 00 */	xoris r3, r3, 0x8000
/* 802C0558 002BD498  3C 00 43 30 */	lis r0, 0x4330
/* 802C055C 002BD49C  90 61 00 0C */	stw r3, 0xc(r1)
/* 802C0560 002BD4A0  C8 62 E1 C0 */	lfd f3, lbl_8051C520@sda21(r2)
/* 802C0564 002BD4A4  90 01 00 08 */	stw r0, 8(r1)
/* 802C0568 002BD4A8  C0 22 E1 BC */	lfs f1, lbl_8051C51C@sda21(r2)
/* 802C056C 002BD4AC  C8 41 00 08 */	lfd f2, 8(r1)
/* 802C0570 002BD4B0  C0 02 E1 B8 */	lfs f0, lbl_8051C518@sda21(r2)
/* 802C0574 002BD4B4  EC 42 18 28 */	fsubs f2, f2, f3
/* 802C0578 002BD4B8  EC 22 08 24 */	fdivs f1, f2, f1
/* 802C057C 002BD4BC  EC 00 00 72 */	fmuls f0, f0, f1
/* 802C0580 002BD4C0  FC 00 00 1E */	fctiwz f0, f0
/* 802C0584 002BD4C4  D8 01 00 10 */	stfd f0, 0x10(r1)
/* 802C0588 002BD4C8  80 61 00 14 */	lwz r3, 0x14(r1)
/* 802C058C 002BD4CC  7C 03 00 D0 */	neg r0, r3
/* 802C0590 002BD4D0  7C 00 1B 78 */	or r0, r0, r3
/* 802C0594 002BD4D4  54 00 0F FE */	srwi r0, r0, 0x1f
/* 802C0598 002BD4D8  98 1F 02 EE */	stb r0, 0x2ee(r31)
.L_802C059C:
/* 802C059C 002BD4DC  80 01 00 24 */	lwz r0, 0x24(r1)
/* 802C05A0 002BD4E0  83 E1 00 1C */	lwz r31, 0x1c(r1)
/* 802C05A4 002BD4E4  7C 08 03 A6 */	mtlr r0
/* 802C05A8 002BD4E8  38 21 00 20 */	addi r1, r1, 0x20
/* 802C05AC 002BD4EC  4E 80 00 20 */	blr 

.global getTargetPosition__Q34Game6Houdai3ObjFv
getTargetPosition__Q34Game6Houdai3ObjFv:
/* 802C05B0 002BD4F0  94 21 FF 90 */	stwu r1, -0x70(r1)
/* 802C05B4 002BD4F4  7C 08 02 A6 */	mflr r0
/* 802C05B8 002BD4F8  90 01 00 74 */	stw r0, 0x74(r1)
/* 802C05BC 002BD4FC  DB E1 00 60 */	stfd f31, 0x60(r1)
/* 802C05C0 002BD500  F3 E1 00 68 */	psq_st f31, 104(r1), 0, qr0
/* 802C05C4 002BD504  DB C1 00 50 */	stfd f30, 0x50(r1)
/* 802C05C8 002BD508  F3 C1 00 58 */	psq_st f30, 88(r1), 0, qr0
/* 802C05CC 002BD50C  93 E1 00 4C */	stw r31, 0x4c(r1)
/* 802C05D0 002BD510  7C 7F 1B 78 */	mr r31, r3
/* 802C05D4 002BD514  C0 23 01 94 */	lfs f1, 0x194(r3)
/* 802C05D8 002BD518  C0 03 01 A0 */	lfs f0, 0x1a0(r3)
/* 802C05DC 002BD51C  80 E3 00 C0 */	lwz r7, 0xc0(r3)
/* 802C05E0 002BD520  EC 41 00 28 */	fsubs f2, f1, f0
/* 802C05E4 002BD524  C0 23 01 8C */	lfs f1, 0x18c(r3)
/* 802C05E8 002BD528  C0 83 01 98 */	lfs f4, 0x198(r3)
/* 802C05EC 002BD52C  C0 07 03 5C */	lfs f0, 0x35c(r7)
/* 802C05F0 002BD530  EC 61 20 28 */	fsubs f3, f1, f4
/* 802C05F4 002BD534  EC 22 00 B2 */	fmuls f1, f2, f2
/* 802C05F8 002BD538  EC 00 00 32 */	fmuls f0, f0, f0
/* 802C05FC 002BD53C  EC 23 08 FA */	fmadds f1, f3, f3, f1
/* 802C0600 002BD540  FC 01 00 40 */	fcmpo cr0, f1, f0
/* 802C0604 002BD544  40 80 02 00 */	bge .L_802C0804
/* 802C0608 002BD548  3C A0 80 4B */	lis r5, "__vt__23Condition<Q24Game4Piki>"@ha
/* 802C060C 002BD54C  3C 80 80 4D */	lis r4, __vt__Q24Game23ConditionNotStickClient@ha
/* 802C0610 002BD550  38 C5 BC 60 */	addi r6, r5, "__vt__23Condition<Q24Game4Piki>"@l
/* 802C0614 002BD554  93 E1 00 0C */	stw r31, 0xc(r1)
/* 802C0618 002BD558  38 04 DB 70 */	addi r0, r4, __vt__Q24Game23ConditionNotStickClient@l
/* 802C061C 002BD55C  38 A1 00 08 */	addi r5, r1, 8
/* 802C0620 002BD560  90 C1 00 08 */	stw r6, 8(r1)
/* 802C0624 002BD564  38 80 00 00 */	li r4, 0
/* 802C0628 002BD568  90 01 00 08 */	stw r0, 8(r1)
/* 802C062C 002BD56C  C0 27 04 24 */	lfs f1, 0x424(r7)
/* 802C0630 002BD570  C0 47 03 D4 */	lfs f2, 0x3d4(r7)
/* 802C0634 002BD574  4B E5 25 31 */	bl "getNearestPikmin__Q24Game9EnemyFuncFPQ24Game8CreatureffPfP23Condition<Q24Game4Piki>"
/* 802C0638 002BD578  28 03 00 00 */	cmplwi r3, 0
/* 802C063C 002BD57C  41 82 00 38 */	beq .L_802C0674
/* 802C0640 002BD580  7C 64 1B 78 */	mr r4, r3
/* 802C0644 002BD584  38 61 00 10 */	addi r3, r1, 0x10
/* 802C0648 002BD588  81 84 00 00 */	lwz r12, 0(r4)
/* 802C064C 002BD58C  81 8C 00 08 */	lwz r12, 8(r12)
/* 802C0650 002BD590  7D 89 03 A6 */	mtctr r12
/* 802C0654 002BD594  4E 80 04 21 */	bctrl 
/* 802C0658 002BD598  C0 01 00 10 */	lfs f0, 0x10(r1)
/* 802C065C 002BD59C  D0 1F 02 D4 */	stfs f0, 0x2d4(r31)
/* 802C0660 002BD5A0  C0 01 00 14 */	lfs f0, 0x14(r1)
/* 802C0664 002BD5A4  D0 1F 02 D8 */	stfs f0, 0x2d8(r31)
/* 802C0668 002BD5A8  C0 01 00 18 */	lfs f0, 0x18(r1)
/* 802C066C 002BD5AC  D0 1F 02 DC */	stfs f0, 0x2dc(r31)
/* 802C0670 002BD5B0  48 00 01 A8 */	b .L_802C0818
.L_802C0674:
/* 802C0674 002BD5B4  C0 3F 01 94 */	lfs f1, 0x194(r31)
/* 802C0678 002BD5B8  C0 1F 02 DC */	lfs f0, 0x2dc(r31)
/* 802C067C 002BD5BC  C0 5F 01 8C */	lfs f2, 0x18c(r31)
/* 802C0680 002BD5C0  EC 61 00 28 */	fsubs f3, f1, f0
/* 802C0684 002BD5C4  C0 3F 02 D4 */	lfs f1, 0x2d4(r31)
/* 802C0688 002BD5C8  C0 02 E1 C8 */	lfs f0, lbl_8051C528@sda21(r2)
/* 802C068C 002BD5CC  EC 42 08 28 */	fsubs f2, f2, f1
/* 802C0690 002BD5D0  EC 23 00 F2 */	fmuls f1, f3, f3
/* 802C0694 002BD5D4  EC 22 08 BA */	fmadds f1, f2, f2, f1
/* 802C0698 002BD5D8  FC 01 00 40 */	fcmpo cr0, f1, f0
/* 802C069C 002BD5DC  40 80 01 7C */	bge .L_802C0818
/* 802C06A0 002BD5E0  80 7F 00 C0 */	lwz r3, 0xc0(r31)
/* 802C06A4 002BD5E4  C0 23 03 5C */	lfs f1, 0x35c(r3)
/* 802C06A8 002BD5E8  C0 03 03 84 */	lfs f0, 0x384(r3)
/* 802C06AC 002BD5EC  EF C1 00 28 */	fsubs f30, f1, f0
/* 802C06B0 002BD5F0  4B E0 8E F1 */	bl rand
/* 802C06B4 002BD5F4  6C 63 80 00 */	xoris r3, r3, 0x8000
/* 802C06B8 002BD5F8  3C 00 43 30 */	lis r0, 0x4330
/* 802C06BC 002BD5FC  90 61 00 24 */	stw r3, 0x24(r1)
/* 802C06C0 002BD600  3C 60 80 51 */	lis r3, atanTable___5JMath@ha
/* 802C06C4 002BD604  80 9F 00 C0 */	lwz r4, 0xc0(r31)
/* 802C06C8 002BD608  38 63 D1 E0 */	addi r3, r3, atanTable___5JMath@l
/* 802C06CC 002BD60C  90 01 00 20 */	stw r0, 0x20(r1)
/* 802C06D0 002BD610  C8 22 E1 C0 */	lfd f1, lbl_8051C520@sda21(r2)
/* 802C06D4 002BD614  C8 01 00 20 */	lfd f0, 0x20(r1)
/* 802C06D8 002BD618  C0 A2 E1 BC */	lfs f5, lbl_8051C51C@sda21(r2)
/* 802C06DC 002BD61C  EC 00 08 28 */	fsubs f0, f0, f1
/* 802C06E0 002BD620  C0 7F 01 8C */	lfs f3, 0x18c(r31)
/* 802C06E4 002BD624  C0 3F 01 98 */	lfs f1, 0x198(r31)
/* 802C06E8 002BD628  C0 84 03 84 */	lfs f4, 0x384(r4)
/* 802C06EC 002BD62C  EC DE 00 32 */	fmuls f6, f30, f0
/* 802C06F0 002BD630  C0 5F 01 94 */	lfs f2, 0x194(r31)
/* 802C06F4 002BD634  EC 23 08 28 */	fsubs f1, f3, f1
/* 802C06F8 002BD638  C0 1F 01 A0 */	lfs f0, 0x1a0(r31)
/* 802C06FC 002BD63C  EC 66 28 24 */	fdivs f3, f6, f5
/* 802C0700 002BD640  EF E4 18 2A */	fadds f31, f4, f3
/* 802C0704 002BD644  EC 42 00 28 */	fsubs f2, f2, f0
/* 802C0708 002BD648  4B D7 4A 01 */	bl "atan2___Q25JMath18TAtanTable<1024,f>CFff"
/* 802C070C 002BD64C  FF C0 08 90 */	fmr f30, f1
/* 802C0710 002BD650  4B E0 8E 91 */	bl rand
/* 802C0714 002BD654  6C 63 80 00 */	xoris r3, r3, 0x8000
/* 802C0718 002BD658  3C 00 43 30 */	lis r0, 0x4330
/* 802C071C 002BD65C  90 61 00 2C */	stw r3, 0x2c(r1)
/* 802C0720 002BD660  C8 42 E1 C0 */	lfd f2, lbl_8051C520@sda21(r2)
/* 802C0724 002BD664  90 01 00 28 */	stw r0, 0x28(r1)
/* 802C0728 002BD668  C0 62 E1 CC */	lfs f3, lbl_8051C52C@sda21(r2)
/* 802C072C 002BD66C  C8 01 00 28 */	lfd f0, 0x28(r1)
/* 802C0730 002BD670  C0 22 E1 BC */	lfs f1, lbl_8051C51C@sda21(r2)
/* 802C0734 002BD674  EC 80 10 28 */	fsubs f4, f0, f2
/* 802C0738 002BD678  C0 42 E1 D0 */	lfs f2, lbl_8051C530@sda21(r2)
/* 802C073C 002BD67C  C0 02 E1 98 */	lfs f0, lbl_8051C4F8@sda21(r2)
/* 802C0740 002BD680  EC 63 01 32 */	fmuls f3, f3, f4
/* 802C0744 002BD684  EC 23 08 24 */	fdivs f1, f3, f1
/* 802C0748 002BD688  EC 3E 08 2A */	fadds f1, f30, f1
/* 802C074C 002BD68C  EC 62 08 2A */	fadds f3, f2, f1
/* 802C0750 002BD690  FC 03 00 40 */	fcmpo cr0, f3, f0
/* 802C0754 002BD694  40 80 00 30 */	bge .L_802C0784
/* 802C0758 002BD698  C0 02 E1 D4 */	lfs f0, lbl_8051C534@sda21(r2)
/* 802C075C 002BD69C  3C 60 80 50 */	lis r3, sincosTable___5JMath@ha
/* 802C0760 002BD6A0  38 63 71 A0 */	addi r3, r3, sincosTable___5JMath@l
/* 802C0764 002BD6A4  EC 03 00 32 */	fmuls f0, f3, f0
/* 802C0768 002BD6A8  FC 00 00 1E */	fctiwz f0, f0
/* 802C076C 002BD6AC  D8 01 00 30 */	stfd f0, 0x30(r1)
/* 802C0770 002BD6B0  80 01 00 34 */	lwz r0, 0x34(r1)
/* 802C0774 002BD6B4  54 00 1C B8 */	rlwinm r0, r0, 3, 0x12, 0x1c
/* 802C0778 002BD6B8  7C 03 04 2E */	lfsx f0, r3, r0
/* 802C077C 002BD6BC  FC 40 00 50 */	fneg f2, f0
/* 802C0780 002BD6C0  48 00 00 28 */	b .L_802C07A8
.L_802C0784:
/* 802C0784 002BD6C4  C0 02 E1 D8 */	lfs f0, lbl_8051C538@sda21(r2)
/* 802C0788 002BD6C8  3C 60 80 50 */	lis r3, sincosTable___5JMath@ha
/* 802C078C 002BD6CC  38 63 71 A0 */	addi r3, r3, sincosTable___5JMath@l
/* 802C0790 002BD6D0  EC 03 00 32 */	fmuls f0, f3, f0
/* 802C0794 002BD6D4  FC 00 00 1E */	fctiwz f0, f0
/* 802C0798 002BD6D8  D8 01 00 38 */	stfd f0, 0x38(r1)
/* 802C079C 002BD6DC  80 01 00 3C */	lwz r0, 0x3c(r1)
/* 802C07A0 002BD6E0  54 00 1C B8 */	rlwinm r0, r0, 3, 0x12, 0x1c
/* 802C07A4 002BD6E4  7C 43 04 2E */	lfsx f2, r3, r0
.L_802C07A8:
/* 802C07A8 002BD6E8  C0 3F 01 98 */	lfs f1, 0x198(r31)
/* 802C07AC 002BD6EC  C0 02 E1 98 */	lfs f0, lbl_8051C4F8@sda21(r2)
/* 802C07B0 002BD6F0  EC 3F 08 BA */	fmadds f1, f31, f2, f1
/* 802C07B4 002BD6F4  FC 03 00 40 */	fcmpo cr0, f3, f0
/* 802C07B8 002BD6F8  D0 3F 02 D4 */	stfs f1, 0x2d4(r31)
/* 802C07BC 002BD6FC  C0 1F 01 9C */	lfs f0, 0x19c(r31)
/* 802C07C0 002BD700  D0 1F 02 D8 */	stfs f0, 0x2d8(r31)
/* 802C07C4 002BD704  40 80 00 08 */	bge .L_802C07CC
/* 802C07C8 002BD708  FC 60 18 50 */	fneg f3, f3
.L_802C07CC:
/* 802C07CC 002BD70C  C0 22 E1 D8 */	lfs f1, lbl_8051C538@sda21(r2)
/* 802C07D0 002BD710  3C 60 80 50 */	lis r3, sincosTable___5JMath@ha
/* 802C07D4 002BD714  38 63 71 A0 */	addi r3, r3, sincosTable___5JMath@l
/* 802C07D8 002BD718  C0 1F 01 A0 */	lfs f0, 0x1a0(r31)
/* 802C07DC 002BD71C  EC 23 00 72 */	fmuls f1, f3, f1
/* 802C07E0 002BD720  FC 20 08 1E */	fctiwz f1, f1
/* 802C07E4 002BD724  D8 21 00 40 */	stfd f1, 0x40(r1)
/* 802C07E8 002BD728  80 01 00 44 */	lwz r0, 0x44(r1)
/* 802C07EC 002BD72C  54 00 1C B8 */	rlwinm r0, r0, 3, 0x12, 0x1c
/* 802C07F0 002BD730  7C 63 02 14 */	add r3, r3, r0
/* 802C07F4 002BD734  C0 23 00 04 */	lfs f1, 4(r3)
/* 802C07F8 002BD738  EC 1F 00 7A */	fmadds f0, f31, f1, f0
/* 802C07FC 002BD73C  D0 1F 02 DC */	stfs f0, 0x2dc(r31)
/* 802C0800 002BD740  48 00 00 18 */	b .L_802C0818
.L_802C0804:
/* 802C0804 002BD744  D0 9F 02 D4 */	stfs f4, 0x2d4(r31)
/* 802C0808 002BD748  C0 1F 01 9C */	lfs f0, 0x19c(r31)
/* 802C080C 002BD74C  D0 1F 02 D8 */	stfs f0, 0x2d8(r31)
/* 802C0810 002BD750  C0 1F 01 A0 */	lfs f0, 0x1a0(r31)
/* 802C0814 002BD754  D0 1F 02 DC */	stfs f0, 0x2dc(r31)
.L_802C0818:
/* 802C0818 002BD758  7F E3 FB 78 */	mr r3, r31
/* 802C081C 002BD75C  38 9F 02 D4 */	addi r4, r31, 0x2d4
/* 802C0820 002BD760  48 00 05 1D */	bl "setIKSystemTargetPosition__Q34Game6Houdai3ObjFR10Vector3<f>"
/* 802C0824 002BD764  E3 E1 00 68 */	psq_l f31, 104(r1), 0, qr0
/* 802C0828 002BD768  CB E1 00 60 */	lfd f31, 0x60(r1)
/* 802C082C 002BD76C  E3 C1 00 58 */	psq_l f30, 88(r1), 0, qr0
/* 802C0830 002BD770  CB C1 00 50 */	lfd f30, 0x50(r1)
/* 802C0834 002BD774  80 01 00 74 */	lwz r0, 0x74(r1)
/* 802C0838 002BD778  83 E1 00 4C */	lwz r31, 0x4c(r1)
/* 802C083C 002BD77C  7C 08 03 A6 */	mtlr r0
/* 802C0840 002BD780  38 21 00 70 */	addi r1, r1, 0x70
/* 802C0844 002BD784  4E 80 00 20 */	blr 

.global setShotGunTargetPosition__Q34Game6Houdai3ObjFv
setShotGunTargetPosition__Q34Game6Houdai3ObjFv:
/* 802C0848 002BD788  94 21 FF 90 */	stwu r1, -0x70(r1)
/* 802C084C 002BD78C  7C 08 02 A6 */	mflr r0
/* 802C0850 002BD790  90 01 00 74 */	stw r0, 0x74(r1)
/* 802C0854 002BD794  DB E1 00 60 */	stfd f31, 0x60(r1)
/* 802C0858 002BD798  F3 E1 00 68 */	psq_st f31, 104(r1), 0, qr0
/* 802C085C 002BD79C  DB C1 00 50 */	stfd f30, 0x50(r1)
/* 802C0860 002BD7A0  F3 C1 00 58 */	psq_st f30, 88(r1), 0, qr0
/* 802C0864 002BD7A4  93 E1 00 4C */	stw r31, 0x4c(r1)
/* 802C0868 002BD7A8  3C A0 80 4B */	lis r5, "__vt__23Condition<Q24Game4Piki>"@ha
/* 802C086C 002BD7AC  3C 80 80 4D */	lis r4, __vt__Q24Game23ConditionNotStickClient@ha
/* 802C0870 002BD7B0  38 05 BC 60 */	addi r0, r5, "__vt__23Condition<Q24Game4Piki>"@l
/* 802C0874 002BD7B4  7C 7F 1B 78 */	mr r31, r3
/* 802C0878 002BD7B8  90 01 00 08 */	stw r0, 8(r1)
/* 802C087C 002BD7BC  38 04 DB 70 */	addi r0, r4, __vt__Q24Game23ConditionNotStickClient@l
/* 802C0880 002BD7C0  90 01 00 08 */	stw r0, 8(r1)
/* 802C0884 002BD7C4  93 E1 00 0C */	stw r31, 0xc(r1)
/* 802C0888 002BD7C8  88 03 02 EE */	lbz r0, 0x2ee(r3)
/* 802C088C 002BD7CC  28 00 00 00 */	cmplwi r0, 0
/* 802C0890 002BD7D0  41 82 00 28 */	beq .L_802C08B8
/* 802C0894 002BD7D4  80 BF 00 C0 */	lwz r5, 0xc0(r31)
/* 802C0898 002BD7D8  38 C1 00 08 */	addi r6, r1, 8
/* 802C089C 002BD7DC  C0 22 E1 DC */	lfs f1, lbl_8051C53C@sda21(r2)
/* 802C08A0 002BD7E0  38 80 00 00 */	li r4, 0
/* 802C08A4 002BD7E4  C0 45 04 4C */	lfs f2, 0x44c(r5)
/* 802C08A8 002BD7E8  38 A0 00 00 */	li r5, 0
/* 802C08AC 002BD7EC  4B E5 27 A5 */	bl "getNearestPikminOrNavi__Q24Game9EnemyFuncFPQ24Game8CreatureffPfP23Condition<Q24Game4Navi>P23Condition<Q24Game4Piki>"
/* 802C08B0 002BD7F0  7C 64 1B 78 */	mr r4, r3
/* 802C08B4 002BD7F4  48 00 00 40 */	b .L_802C08F4
.L_802C08B8:
/* 802C08B8 002BD7F8  80 DF 00 C0 */	lwz r6, 0xc0(r31)
/* 802C08BC 002BD7FC  38 80 00 00 */	li r4, 0
/* 802C08C0 002BD800  C0 22 E1 DC */	lfs f1, lbl_8051C53C@sda21(r2)
/* 802C08C4 002BD804  38 A0 00 00 */	li r5, 0
/* 802C08C8 002BD808  C0 46 04 4C */	lfs f2, 0x44c(r6)
/* 802C08CC 002BD80C  4B E5 1E 29 */	bl "getNearestNavi__Q24Game9EnemyFuncFPQ24Game8CreatureffPfP23Condition<Q24Game4Navi>"
/* 802C08D0 002BD810  7C 64 1B 79 */	or. r4, r3, r3
/* 802C08D4 002BD814  41 82 00 20 */	beq .L_802C08F4
/* 802C08D8 002BD818  80 DF 00 C0 */	lwz r6, 0xc0(r31)
/* 802C08DC 002BD81C  38 A1 00 08 */	addi r5, r1, 8
/* 802C08E0 002BD820  C0 22 E1 DC */	lfs f1, lbl_8051C53C@sda21(r2)
/* 802C08E4 002BD824  38 80 00 00 */	li r4, 0
/* 802C08E8 002BD828  C0 46 04 4C */	lfs f2, 0x44c(r6)
/* 802C08EC 002BD82C  4B E5 22 79 */	bl "getNearestPikmin__Q24Game9EnemyFuncFPQ24Game8CreatureffPfP23Condition<Q24Game4Piki>"
/* 802C08F0 002BD830  7C 64 1B 78 */	mr r4, r3
.L_802C08F4:
/* 802C08F4 002BD834  28 04 00 00 */	cmplwi r4, 0
/* 802C08F8 002BD838  41 82 00 34 */	beq .L_802C092C
/* 802C08FC 002BD83C  81 84 00 00 */	lwz r12, 0(r4)
/* 802C0900 002BD840  38 61 00 10 */	addi r3, r1, 0x10
/* 802C0904 002BD844  81 8C 00 08 */	lwz r12, 8(r12)
/* 802C0908 002BD848  7D 89 03 A6 */	mtctr r12
/* 802C090C 002BD84C  4E 80 04 21 */	bctrl 
/* 802C0910 002BD850  C0 01 00 10 */	lfs f0, 0x10(r1)
/* 802C0914 002BD854  D0 1F 02 E0 */	stfs f0, 0x2e0(r31)
/* 802C0918 002BD858  C0 01 00 14 */	lfs f0, 0x14(r1)
/* 802C091C 002BD85C  D0 1F 02 E4 */	stfs f0, 0x2e4(r31)
/* 802C0920 002BD860  C0 01 00 18 */	lfs f0, 0x18(r1)
/* 802C0924 002BD864  D0 1F 02 E8 */	stfs f0, 0x2e8(r31)
/* 802C0928 002BD868  48 00 01 24 */	b .L_802C0A4C
.L_802C092C:
/* 802C092C 002BD86C  C0 3F 02 C8 */	lfs f1, 0x2c8(r31)
/* 802C0930 002BD870  C0 02 E1 9C */	lfs f0, lbl_8051C4FC@sda21(r2)
/* 802C0934 002BD874  FC 01 00 40 */	fcmpo cr0, f1, f0
/* 802C0938 002BD878  40 81 01 14 */	ble .L_802C0A4C
/* 802C093C 002BD87C  C0 02 E1 98 */	lfs f0, lbl_8051C4F8@sda21(r2)
/* 802C0940 002BD880  D0 1F 02 C8 */	stfs f0, 0x2c8(r31)
/* 802C0944 002BD884  4B E0 8C 5D */	bl rand
/* 802C0948 002BD888  6C 63 80 00 */	xoris r3, r3, 0x8000
/* 802C094C 002BD88C  3C 00 43 30 */	lis r0, 0x4330
/* 802C0950 002BD890  90 61 00 24 */	stw r3, 0x24(r1)
/* 802C0954 002BD894  80 7F 00 C0 */	lwz r3, 0xc0(r31)
/* 802C0958 002BD898  90 01 00 20 */	stw r0, 0x20(r1)
/* 802C095C 002BD89C  C8 42 E1 C0 */	lfd f2, lbl_8051C520@sda21(r2)
/* 802C0960 002BD8A0  C8 01 00 20 */	lfd f0, 0x20(r1)
/* 802C0964 002BD8A4  C0 22 E1 E0 */	lfs f1, lbl_8051C540@sda21(r2)
/* 802C0968 002BD8A8  EC 40 10 28 */	fsubs f2, f0, f2
/* 802C096C 002BD8AC  C0 02 E1 BC */	lfs f0, lbl_8051C51C@sda21(r2)
/* 802C0970 002BD8B0  C3 E3 04 4C */	lfs f31, 0x44c(r3)
/* 802C0974 002BD8B4  EC 21 00 B2 */	fmuls f1, f1, f2
/* 802C0978 002BD8B8  EF C1 00 24 */	fdivs f30, f1, f0
/* 802C097C 002BD8BC  4B E0 8C 25 */	bl rand
/* 802C0980 002BD8C0  6C 63 80 00 */	xoris r3, r3, 0x8000
/* 802C0984 002BD8C4  3C 00 43 30 */	lis r0, 0x4330
/* 802C0988 002BD8C8  90 61 00 2C */	stw r3, 0x2c(r1)
/* 802C098C 002BD8CC  FC 80 F0 90 */	fmr f4, f30
/* 802C0990 002BD8D0  C0 02 E1 98 */	lfs f0, lbl_8051C4F8@sda21(r2)
/* 802C0994 002BD8D4  90 01 00 28 */	stw r0, 0x28(r1)
/* 802C0998 002BD8D8  C8 42 E1 C0 */	lfd f2, lbl_8051C520@sda21(r2)
/* 802C099C 002BD8DC  FC 1E 00 40 */	fcmpo cr0, f30, f0
/* 802C09A0 002BD8E0  C8 21 00 28 */	lfd f1, 0x28(r1)
/* 802C09A4 002BD8E4  C0 02 E1 BC */	lfs f0, lbl_8051C51C@sda21(r2)
/* 802C09A8 002BD8E8  EC 21 10 28 */	fsubs f1, f1, f2
/* 802C09AC 002BD8EC  EC 3F 00 72 */	fmuls f1, f31, f1
/* 802C09B0 002BD8F0  EC A1 00 24 */	fdivs f5, f1, f0
/* 802C09B4 002BD8F4  40 80 00 08 */	bge .L_802C09BC
/* 802C09B8 002BD8F8  FC 80 F0 50 */	fneg f4, f30
.L_802C09BC:
/* 802C09BC 002BD8FC  C0 62 E1 D8 */	lfs f3, lbl_8051C538@sda21(r2)
/* 802C09C0 002BD900  3C 60 80 50 */	lis r3, sincosTable___5JMath@ha
/* 802C09C4 002BD904  C0 02 E1 98 */	lfs f0, lbl_8051C4F8@sda21(r2)
/* 802C09C8 002BD908  38 83 71 A0 */	addi r4, r3, sincosTable___5JMath@l
/* 802C09CC 002BD90C  EC 44 00 F2 */	fmuls f2, f4, f3
/* 802C09D0 002BD910  C0 3F 01 94 */	lfs f1, 0x194(r31)
/* 802C09D4 002BD914  FC 1E 00 40 */	fcmpo cr0, f30, f0
/* 802C09D8 002BD918  C0 9F 01 90 */	lfs f4, 0x190(r31)
/* 802C09DC 002BD91C  FC 00 10 1E */	fctiwz f0, f2
/* 802C09E0 002BD920  D8 01 00 30 */	stfd f0, 0x30(r1)
/* 802C09E4 002BD924  80 01 00 34 */	lwz r0, 0x34(r1)
/* 802C09E8 002BD928  54 00 1C B8 */	rlwinm r0, r0, 3, 0x12, 0x1c
/* 802C09EC 002BD92C  7C 64 02 14 */	add r3, r4, r0
/* 802C09F0 002BD930  C0 03 00 04 */	lfs f0, 4(r3)
/* 802C09F4 002BD934  EC 45 08 3A */	fmadds f2, f5, f0, f1
/* 802C09F8 002BD938  40 80 00 28 */	bge .L_802C0A20
/* 802C09FC 002BD93C  C0 02 E1 D4 */	lfs f0, lbl_8051C534@sda21(r2)
/* 802C0A00 002BD940  EC 1E 00 32 */	fmuls f0, f30, f0
/* 802C0A04 002BD944  FC 00 00 1E */	fctiwz f0, f0
/* 802C0A08 002BD948  D8 01 00 38 */	stfd f0, 0x38(r1)
/* 802C0A0C 002BD94C  80 01 00 3C */	lwz r0, 0x3c(r1)
/* 802C0A10 002BD950  54 00 1C B8 */	rlwinm r0, r0, 3, 0x12, 0x1c
/* 802C0A14 002BD954  7C 04 04 2E */	lfsx f0, r4, r0
/* 802C0A18 002BD958  FC 20 00 50 */	fneg f1, f0
/* 802C0A1C 002BD95C  48 00 00 1C */	b .L_802C0A38
.L_802C0A20:
/* 802C0A20 002BD960  EC 1E 00 F2 */	fmuls f0, f30, f3
/* 802C0A24 002BD964  FC 00 00 1E */	fctiwz f0, f0
/* 802C0A28 002BD968  D8 01 00 40 */	stfd f0, 0x40(r1)
/* 802C0A2C 002BD96C  80 01 00 44 */	lwz r0, 0x44(r1)
/* 802C0A30 002BD970  54 00 1C B8 */	rlwinm r0, r0, 3, 0x12, 0x1c
/* 802C0A34 002BD974  7C 24 04 2E */	lfsx f1, r4, r0
.L_802C0A38:
/* 802C0A38 002BD978  C0 1F 01 8C */	lfs f0, 0x18c(r31)
/* 802C0A3C 002BD97C  EC 05 00 7A */	fmadds f0, f5, f1, f0
/* 802C0A40 002BD980  D0 1F 02 E0 */	stfs f0, 0x2e0(r31)
/* 802C0A44 002BD984  D0 9F 02 E4 */	stfs f4, 0x2e4(r31)
/* 802C0A48 002BD988  D0 5F 02 E8 */	stfs f2, 0x2e8(r31)
.L_802C0A4C:
/* 802C0A4C 002BD98C  7F E3 FB 78 */	mr r3, r31
/* 802C0A50 002BD990  38 9F 02 E0 */	addi r4, r31, 0x2e0
/* 802C0A54 002BD994  48 00 07 91 */	bl "setShotGunTarget__Q34Game6Houdai3ObjFR10Vector3<f>"
/* 802C0A58 002BD998  E3 E1 00 68 */	psq_l f31, 104(r1), 0, qr0
/* 802C0A5C 002BD99C  CB E1 00 60 */	lfd f31, 0x60(r1)
/* 802C0A60 002BD9A0  E3 C1 00 58 */	psq_l f30, 88(r1), 0, qr0
/* 802C0A64 002BD9A4  CB C1 00 50 */	lfd f30, 0x50(r1)
/* 802C0A68 002BD9A8  80 01 00 74 */	lwz r0, 0x74(r1)
/* 802C0A6C 002BD9AC  83 E1 00 4C */	lwz r31, 0x4c(r1)
/* 802C0A70 002BD9B0  7C 08 03 A6 */	mtlr r0
/* 802C0A74 002BD9B4  38 21 00 70 */	addi r1, r1, 0x70
/* 802C0A78 002BD9B8  4E 80 00 20 */	blr 

.global createIKSystem__Q34Game6Houdai3ObjFv
createIKSystem__Q34Game6Houdai3ObjFv:
/* 802C0A7C 002BD9BC  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 802C0A80 002BD9C0  7C 08 02 A6 */	mflr r0
/* 802C0A84 002BD9C4  90 01 00 14 */	stw r0, 0x14(r1)
/* 802C0A88 002BD9C8  93 E1 00 0C */	stw r31, 0xc(r1)
/* 802C0A8C 002BD9CC  7C 7F 1B 78 */	mr r31, r3
/* 802C0A90 002BD9D0  38 60 00 9C */	li r3, 0x9c
/* 802C0A94 002BD9D4  4B D6 34 11 */	bl __nw__FUl
/* 802C0A98 002BD9D8  7C 60 1B 79 */	or. r0, r3, r3
/* 802C0A9C 002BD9DC  41 82 00 0C */	beq .L_802C0AA8
/* 802C0AA0 002BD9E0  4B FE 80 19 */	bl __ct__Q24Game11IKSystemMgrFv
/* 802C0AA4 002BD9E4  7C 60 1B 78 */	mr r0, r3
.L_802C0AA8:
/* 802C0AA8 002BD9E8  90 1F 02 F0 */	stw r0, 0x2f0(r31)
/* 802C0AAC 002BD9EC  38 60 00 48 */	li r3, 0x48
/* 802C0AB0 002BD9F0  4B D6 33 F5 */	bl __nw__FUl
/* 802C0AB4 002BD9F4  28 03 00 00 */	cmplwi r3, 0
/* 802C0AB8 002BD9F8  41 82 00 88 */	beq .L_802C0B40
/* 802C0ABC 002BD9FC  38 00 FF FF */	li r0, -1
/* 802C0AC0 002BDA00  C0 A2 E1 98 */	lfs f5, lbl_8051C4F8@sda21(r2)
/* 802C0AC4 002BDA04  90 03 00 00 */	stw r0, 0(r3)
/* 802C0AC8 002BDA08  C0 22 E1 E4 */	lfs f1, lbl_8051C544@sda21(r2)
/* 802C0ACC 002BDA0C  D0 A3 00 04 */	stfs f5, 4(r3)
/* 802C0AD0 002BDA10  C0 02 E1 E8 */	lfs f0, lbl_8051C548@sda21(r2)
/* 802C0AD4 002BDA14  D0 A3 00 08 */	stfs f5, 8(r3)
/* 802C0AD8 002BDA18  C0 42 E1 EC */	lfs f2, lbl_8051C54C@sda21(r2)
/* 802C0ADC 002BDA1C  D0 23 00 0C */	stfs f1, 0xc(r3)
/* 802C0AE0 002BDA20  C0 22 E1 F0 */	lfs f1, lbl_8051C550@sda21(r2)
/* 802C0AE4 002BDA24  D0 03 00 10 */	stfs f0, 0x10(r3)
/* 802C0AE8 002BDA28  C0 02 E1 F4 */	lfs f0, lbl_8051C554@sda21(r2)
/* 802C0AEC 002BDA2C  D0 43 00 14 */	stfs f2, 0x14(r3)
/* 802C0AF0 002BDA30  C0 42 E1 A8 */	lfs f2, lbl_8051C508@sda21(r2)
/* 802C0AF4 002BDA34  D0 23 00 18 */	stfs f1, 0x18(r3)
/* 802C0AF8 002BDA38  C0 22 E1 F8 */	lfs f1, lbl_8051C558@sda21(r2)
/* 802C0AFC 002BDA3C  D0 03 00 1C */	stfs f0, 0x1c(r3)
/* 802C0B00 002BDA40  C0 02 E1 FC */	lfs f0, lbl_8051C55C@sda21(r2)
/* 802C0B04 002BDA44  D0 43 00 20 */	stfs f2, 0x20(r3)
/* 802C0B08 002BDA48  C0 82 E2 00 */	lfs f4, lbl_8051C560@sda21(r2)
/* 802C0B0C 002BDA4C  D0 23 00 24 */	stfs f1, 0x24(r3)
/* 802C0B10 002BDA50  C0 62 E2 04 */	lfs f3, lbl_8051C564@sda21(r2)
/* 802C0B14 002BDA54  D0 A3 00 28 */	stfs f5, 0x28(r3)
/* 802C0B18 002BDA58  C0 42 E1 A0 */	lfs f2, lbl_8051C500@sda21(r2)
/* 802C0B1C 002BDA5C  D0 03 00 2C */	stfs f0, 0x2c(r3)
/* 802C0B20 002BDA60  C0 22 E2 08 */	lfs f1, lbl_8051C568@sda21(r2)
/* 802C0B24 002BDA64  D0 A3 00 30 */	stfs f5, 0x30(r3)
/* 802C0B28 002BDA68  C0 02 E2 0C */	lfs f0, lbl_8051C56C@sda21(r2)
/* 802C0B2C 002BDA6C  D0 83 00 34 */	stfs f4, 0x34(r3)
/* 802C0B30 002BDA70  D0 63 00 38 */	stfs f3, 0x38(r3)
/* 802C0B34 002BDA74  D0 43 00 3C */	stfs f2, 0x3c(r3)
/* 802C0B38 002BDA78  D0 23 00 40 */	stfs f1, 0x40(r3)
/* 802C0B3C 002BDA7C  D0 03 00 44 */	stfs f0, 0x44(r3)
.L_802C0B40:
/* 802C0B40 002BDA80  90 7F 02 F4 */	stw r3, 0x2f4(r31)
/* 802C0B44 002BDA84  38 60 00 08 */	li r3, 8
/* 802C0B48 002BDA88  4B D6 33 5D */	bl __nw__FUl
/* 802C0B4C 002BDA8C  28 03 00 00 */	cmplwi r3, 0
/* 802C0B50 002BDA90  41 82 00 20 */	beq .L_802C0B70
/* 802C0B54 002BDA94  3C A0 80 4D */	lis r5, __vt__Q24Game19JointGroundCallBack@ha
/* 802C0B58 002BDA98  3C 80 80 4D */	lis r4, __vt__Q34Game6Houdai20HoudaiGroundCallBack@ha
/* 802C0B5C 002BDA9C  38 05 DB 60 */	addi r0, r5, __vt__Q24Game19JointGroundCallBack@l
/* 802C0B60 002BDAA0  90 03 00 00 */	stw r0, 0(r3)
/* 802C0B64 002BDAA4  38 04 14 8C */	addi r0, r4, __vt__Q34Game6Houdai20HoudaiGroundCallBack@l
/* 802C0B68 002BDAA8  90 03 00 00 */	stw r0, 0(r3)
/* 802C0B6C 002BDAAC  93 E3 00 04 */	stw r31, 4(r3)
.L_802C0B70:
/* 802C0B70 002BDAB0  90 7F 02 F8 */	stw r3, 0x2f8(r31)
/* 802C0B74 002BDAB4  80 01 00 14 */	lwz r0, 0x14(r1)
/* 802C0B78 002BDAB8  83 E1 00 0C */	lwz r31, 0xc(r1)
/* 802C0B7C 002BDABC  7C 08 03 A6 */	mtlr r0
/* 802C0B80 002BDAC0  38 21 00 10 */	addi r1, r1, 0x10
/* 802C0B84 002BDAC4  4E 80 00 20 */	blr 

.global setupIKSystem__Q34Game6Houdai3ObjFv
setupIKSystem__Q34Game6Houdai3ObjFv:
/* 802C0B88 002BDAC8  94 21 FF B0 */	stwu r1, -0x50(r1)
/* 802C0B8C 002BDACC  7C 08 02 A6 */	mflr r0
/* 802C0B90 002BDAD0  38 A0 00 00 */	li r5, 0
/* 802C0B94 002BDAD4  90 01 00 54 */	stw r0, 0x54(r1)
/* 802C0B98 002BDAD8  BF 61 00 3C */	stmw r27, 0x3c(r1)
/* 802C0B9C 002BDADC  7C 7F 1B 78 */	mr r31, r3
/* 802C0BA0 002BDAE0  7F E4 FB 78 */	mr r4, r31
/* 802C0BA4 002BDAE4  80 63 02 F0 */	lwz r3, 0x2f0(r3)
/* 802C0BA8 002BDAE8  4B FE 7F 8D */	bl init__Q24Game11IKSystemMgrFPQ24Game9EnemyBasePQ24Game19JointGroundCallBack
/* 802C0BAC 002BDAEC  3C 60 80 49 */	lis r3, lbl_8048B168@ha
/* 802C0BB0 002BDAF0  38 C1 00 08 */	addi r6, r1, 8
/* 802C0BB4 002BDAF4  3B 63 B1 68 */	addi r27, r3, lbl_8048B168@l
/* 802C0BB8 002BDAF8  38 A0 00 00 */	li r5, 0
/* 802C0BBC 002BDAFC  83 9B 00 00 */	lwz r28, 0(r27)
/* 802C0BC0 002BDB00  83 BB 00 04 */	lwz r29, 4(r27)
/* 802C0BC4 002BDB04  83 DB 00 08 */	lwz r30, 8(r27)
/* 802C0BC8 002BDB08  81 9B 00 0C */	lwz r12, 0xc(r27)
/* 802C0BCC 002BDB0C  81 7B 00 10 */	lwz r11, 0x10(r27)
/* 802C0BD0 002BDB10  81 5B 00 14 */	lwz r10, 0x14(r27)
/* 802C0BD4 002BDB14  81 3B 00 18 */	lwz r9, 0x18(r27)
/* 802C0BD8 002BDB18  81 1B 00 1C */	lwz r8, 0x1c(r27)
/* 802C0BDC 002BDB1C  80 FB 00 20 */	lwz r7, 0x20(r27)
/* 802C0BE0 002BDB20  80 9B 00 24 */	lwz r4, 0x24(r27)
/* 802C0BE4 002BDB24  80 7B 00 28 */	lwz r3, 0x28(r27)
/* 802C0BE8 002BDB28  80 1B 00 2C */	lwz r0, 0x2c(r27)
/* 802C0BEC 002BDB2C  93 81 00 08 */	stw r28, 8(r1)
/* 802C0BF0 002BDB30  93 A1 00 0C */	stw r29, 0xc(r1)
/* 802C0BF4 002BDB34  93 C1 00 10 */	stw r30, 0x10(r1)
/* 802C0BF8 002BDB38  91 81 00 14 */	stw r12, 0x14(r1)
/* 802C0BFC 002BDB3C  91 61 00 18 */	stw r11, 0x18(r1)
/* 802C0C00 002BDB40  91 41 00 1C */	stw r10, 0x1c(r1)
/* 802C0C04 002BDB44  91 21 00 20 */	stw r9, 0x20(r1)
/* 802C0C08 002BDB48  91 01 00 24 */	stw r8, 0x24(r1)
/* 802C0C0C 002BDB4C  90 E1 00 28 */	stw r7, 0x28(r1)
/* 802C0C10 002BDB50  90 81 00 2C */	stw r4, 0x2c(r1)
/* 802C0C14 002BDB54  90 61 00 30 */	stw r3, 0x30(r1)
/* 802C0C18 002BDB58  90 01 00 34 */	stw r0, 0x34(r1)
/* 802C0C1C 002BDB5C  80 7F 02 F0 */	lwz r3, 0x2f0(r31)
/* 802C0C20 002BDB60  80 9F 01 74 */	lwz r4, 0x174(r31)
/* 802C0C24 002BDB64  4B FE 80 55 */	bl setupJoint__Q24Game11IKSystemMgrFPQ28SysShape5ModeliPPc
/* 802C0C28 002BDB68  80 7F 02 F0 */	lwz r3, 0x2f0(r31)
/* 802C0C2C 002BDB6C  38 C1 00 14 */	addi r6, r1, 0x14
/* 802C0C30 002BDB70  80 9F 01 74 */	lwz r4, 0x174(r31)
/* 802C0C34 002BDB74  38 A0 00 01 */	li r5, 1
/* 802C0C38 002BDB78  4B FE 80 41 */	bl setupJoint__Q24Game11IKSystemMgrFPQ28SysShape5ModeliPPc
/* 802C0C3C 002BDB7C  80 7F 02 F0 */	lwz r3, 0x2f0(r31)
/* 802C0C40 002BDB80  38 C1 00 20 */	addi r6, r1, 0x20
/* 802C0C44 002BDB84  80 9F 01 74 */	lwz r4, 0x174(r31)
/* 802C0C48 002BDB88  38 A0 00 02 */	li r5, 2
/* 802C0C4C 002BDB8C  4B FE 80 2D */	bl setupJoint__Q24Game11IKSystemMgrFPQ28SysShape5ModeliPPc
/* 802C0C50 002BDB90  80 7F 02 F0 */	lwz r3, 0x2f0(r31)
/* 802C0C54 002BDB94  38 C1 00 2C */	addi r6, r1, 0x2c
/* 802C0C58 002BDB98  80 9F 01 74 */	lwz r4, 0x174(r31)
/* 802C0C5C 002BDB9C  38 A0 00 03 */	li r5, 3
/* 802C0C60 002BDBA0  4B FE 80 19 */	bl setupJoint__Q24Game11IKSystemMgrFPQ28SysShape5ModeliPPc
/* 802C0C64 002BDBA4  3C 80 80 49 */	lis r4, lbl_8048B0F0@ha
/* 802C0C68 002BDBA8  80 7F 02 F0 */	lwz r3, 0x2f0(r31)
/* 802C0C6C 002BDBAC  38 A4 B0 F0 */	addi r5, r4, lbl_8048B0F0@l
/* 802C0C70 002BDBB0  80 9F 01 74 */	lwz r4, 0x174(r31)
/* 802C0C74 002BDBB4  4B FE 80 71 */	bl setupCallBack__Q24Game11IKSystemMgrFPQ28SysShape5ModelPc
/* 802C0C78 002BDBB8  7F E3 FB 78 */	mr r3, r31
/* 802C0C7C 002BDBBC  48 00 00 31 */	bl setIKParameter__Q34Game6Houdai3ObjFv
/* 802C0C80 002BDBC0  80 7F 02 F0 */	lwz r3, 0x2f0(r31)
/* 802C0C84 002BDBC4  80 9F 02 F4 */	lwz r4, 0x2f4(r31)
/* 802C0C88 002BDBC8  4B FE 80 95 */	bl setParameters__Q24Game11IKSystemMgrFPQ24Game13IKSystemParms
/* 802C0C8C 002BDBCC  80 1F 02 F8 */	lwz r0, 0x2f8(r31)
/* 802C0C90 002BDBD0  80 7F 02 F0 */	lwz r3, 0x2f0(r31)
/* 802C0C94 002BDBD4  90 03 00 94 */	stw r0, 0x94(r3)
/* 802C0C98 002BDBD8  BB 61 00 3C */	lmw r27, 0x3c(r1)
/* 802C0C9C 002BDBDC  80 01 00 54 */	lwz r0, 0x54(r1)
/* 802C0CA0 002BDBE0  7C 08 03 A6 */	mtlr r0
/* 802C0CA4 002BDBE4  38 21 00 50 */	addi r1, r1, 0x50
/* 802C0CA8 002BDBE8  4E 80 00 20 */	blr 

.global setIKParameter__Q34Game6Houdai3ObjFv
setIKParameter__Q34Game6Houdai3ObjFv:
/* 802C0CAC 002BDBEC  C0 02 E2 10 */	lfs f0, lbl_8051C570@sda21(r2)
/* 802C0CB0 002BDBF0  80 83 02 F4 */	lwz r4, 0x2f4(r3)
/* 802C0CB4 002BDBF4  D0 04 00 28 */	stfs f0, 0x28(r4)
/* 802C0CB8 002BDBF8  80 A3 00 C0 */	lwz r5, 0xc0(r3)
/* 802C0CBC 002BDBFC  80 83 02 F4 */	lwz r4, 0x2f4(r3)
/* 802C0CC0 002BDC00  C0 05 03 34 */	lfs f0, 0x334(r5)
/* 802C0CC4 002BDC04  D0 04 00 38 */	stfs f0, 0x38(r4)
/* 802C0CC8 002BDC08  80 A3 00 C0 */	lwz r5, 0xc0(r3)
/* 802C0CCC 002BDC0C  80 83 02 F4 */	lwz r4, 0x2f4(r3)
/* 802C0CD0 002BDC10  C0 05 02 E4 */	lfs f0, 0x2e4(r5)
/* 802C0CD4 002BDC14  D0 04 00 2C */	stfs f0, 0x2c(r4)
/* 802C0CD8 002BDC18  80 A3 00 C0 */	lwz r5, 0xc0(r3)
/* 802C0CDC 002BDC1C  80 83 02 F4 */	lwz r4, 0x2f4(r3)
/* 802C0CE0 002BDC20  C0 05 08 1C */	lfs f0, 0x81c(r5)
/* 802C0CE4 002BDC24  D0 04 00 14 */	stfs f0, 0x14(r4)
/* 802C0CE8 002BDC28  80 A3 00 C0 */	lwz r5, 0xc0(r3)
/* 802C0CEC 002BDC2C  80 83 02 F4 */	lwz r4, 0x2f4(r3)
/* 802C0CF0 002BDC30  C0 05 08 44 */	lfs f0, 0x844(r5)
/* 802C0CF4 002BDC34  D0 04 00 18 */	stfs f0, 0x18(r4)
/* 802C0CF8 002BDC38  80 A3 00 C0 */	lwz r5, 0xc0(r3)
/* 802C0CFC 002BDC3C  80 83 02 F4 */	lwz r4, 0x2f4(r3)
/* 802C0D00 002BDC40  C0 05 08 6C */	lfs f0, 0x86c(r5)
/* 802C0D04 002BDC44  D0 04 00 1C */	stfs f0, 0x1c(r4)
/* 802C0D08 002BDC48  80 A3 00 C0 */	lwz r5, 0xc0(r3)
/* 802C0D0C 002BDC4C  80 83 02 F4 */	lwz r4, 0x2f4(r3)
/* 802C0D10 002BDC50  C0 05 08 BC */	lfs f0, 0x8bc(r5)
/* 802C0D14 002BDC54  D0 04 00 20 */	stfs f0, 0x20(r4)
/* 802C0D18 002BDC58  80 A3 00 C0 */	lwz r5, 0xc0(r3)
/* 802C0D1C 002BDC5C  80 83 02 F4 */	lwz r4, 0x2f4(r3)
/* 802C0D20 002BDC60  C0 05 08 94 */	lfs f0, 0x894(r5)
/* 802C0D24 002BDC64  D0 04 00 24 */	stfs f0, 0x24(r4)
/* 802C0D28 002BDC68  80 83 00 C0 */	lwz r4, 0xc0(r3)
/* 802C0D2C 002BDC6C  80 63 02 F4 */	lwz r3, 0x2f4(r3)
/* 802C0D30 002BDC70  C0 04 08 E4 */	lfs f0, 0x8e4(r4)
/* 802C0D34 002BDC74  D0 03 00 10 */	stfs f0, 0x10(r3)
/* 802C0D38 002BDC78  4E 80 00 20 */	blr 

.global "setIKSystemTargetPosition__Q34Game6Houdai3ObjFR10Vector3<f>"
"setIKSystemTargetPosition__Q34Game6Houdai3ObjFR10Vector3<f>":
/* 802C0D3C 002BDC7C  80 63 02 F0 */	lwz r3, 0x2f0(r3)
/* 802C0D40 002BDC80  C0 04 00 00 */	lfs f0, 0(r4)
/* 802C0D44 002BDC84  D0 03 00 2C */	stfs f0, 0x2c(r3)
/* 802C0D48 002BDC88  C0 04 00 04 */	lfs f0, 4(r4)
/* 802C0D4C 002BDC8C  D0 03 00 30 */	stfs f0, 0x30(r3)
/* 802C0D50 002BDC90  C0 04 00 08 */	lfs f0, 8(r4)
/* 802C0D54 002BDC94  D0 03 00 34 */	stfs f0, 0x34(r3)
/* 802C0D58 002BDC98  4E 80 00 20 */	blr 

.global updateIKSystem__Q34Game6Houdai3ObjFv
updateIKSystem__Q34Game6Houdai3ObjFv:
/* 802C0D5C 002BDC9C  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 802C0D60 002BDCA0  7C 08 02 A6 */	mflr r0
/* 802C0D64 002BDCA4  90 01 00 14 */	stw r0, 0x14(r1)
/* 802C0D68 002BDCA8  93 E1 00 0C */	stw r31, 0xc(r1)
/* 802C0D6C 002BDCAC  7C 7F 1B 78 */	mr r31, r3
/* 802C0D70 002BDCB0  80 63 02 F0 */	lwz r3, 0x2f0(r3)
/* 802C0D74 002BDCB4  4B FE 83 71 */	bl doUpdate__Q24Game11IKSystemMgrFv
/* 802C0D78 002BDCB8  80 7F 02 F0 */	lwz r3, 0x2f0(r31)
/* 802C0D7C 002BDCBC  C0 23 00 3C */	lfs f1, 0x3c(r3)
/* 802C0D80 002BDCC0  C0 43 00 40 */	lfs f2, 0x40(r3)
/* 802C0D84 002BDCC4  C0 03 00 38 */	lfs f0, 0x38(r3)
/* 802C0D88 002BDCC8  D0 1F 01 8C */	stfs f0, 0x18c(r31)
/* 802C0D8C 002BDCCC  D0 3F 01 90 */	stfs f1, 0x190(r31)
/* 802C0D90 002BDCD0  D0 5F 01 94 */	stfs f2, 0x194(r31)
/* 802C0D94 002BDCD4  80 7F 02 F0 */	lwz r3, 0x2f0(r31)
/* 802C0D98 002BDCD8  C0 03 00 04 */	lfs f0, 4(r3)
/* 802C0D9C 002BDCDC  D0 1F 01 FC */	stfs f0, 0x1fc(r31)
/* 802C0DA0 002BDCE0  C0 1F 01 FC */	lfs f0, 0x1fc(r31)
/* 802C0DA4 002BDCE4  D0 1F 01 A8 */	stfs f0, 0x1a8(r31)
/* 802C0DA8 002BDCE8  83 E1 00 0C */	lwz r31, 0xc(r1)
/* 802C0DAC 002BDCEC  80 01 00 14 */	lwz r0, 0x14(r1)
/* 802C0DB0 002BDCF0  7C 08 03 A6 */	mtlr r0
/* 802C0DB4 002BDCF4  38 21 00 10 */	addi r1, r1, 0x10
/* 802C0DB8 002BDCF8  4E 80 00 20 */	blr 

.global doAnimationIKSystem__Q34Game6Houdai3ObjFv
doAnimationIKSystem__Q34Game6Houdai3ObjFv:
/* 802C0DBC 002BDCFC  94 21 FF E0 */	stwu r1, -0x20(r1)
/* 802C0DC0 002BDD00  7C 08 02 A6 */	mflr r0
/* 802C0DC4 002BDD04  90 01 00 24 */	stw r0, 0x24(r1)
/* 802C0DC8 002BDD08  93 E1 00 1C */	stw r31, 0x1c(r1)
/* 802C0DCC 002BDD0C  7C 7F 1B 78 */	mr r31, r3
/* 802C0DD0 002BDD10  80 63 02 F0 */	lwz r3, 0x2f0(r3)
/* 802C0DD4 002BDD14  4B FE 83 09 */	bl setAnimationCallBack__Q24Game11IKSystemMgrFv
/* 802C0DD8 002BDD18  80 FF 02 F0 */	lwz r7, 0x2f0(r31)
/* 802C0DDC 002BDD1C  38 7F 01 38 */	addi r3, r31, 0x138
/* 802C0DE0 002BDD20  38 9F 01 68 */	addi r4, r31, 0x168
/* 802C0DE4 002BDD24  38 BF 01 A4 */	addi r5, r31, 0x1a4
/* 802C0DE8 002BDD28  C0 27 00 48 */	lfs f1, 0x48(r7)
/* 802C0DEC 002BDD2C  38 C1 00 08 */	addi r6, r1, 8
/* 802C0DF0 002BDD30  C0 47 00 4C */	lfs f2, 0x4c(r7)
/* 802C0DF4 002BDD34  C0 07 00 44 */	lfs f0, 0x44(r7)
/* 802C0DF8 002BDD38  D0 01 00 08 */	stfs f0, 8(r1)
/* 802C0DFC 002BDD3C  D0 21 00 0C */	stfs f1, 0xc(r1)
/* 802C0E00 002BDD40  D0 41 00 10 */	stfs f2, 0x10(r1)
/* 802C0E04 002BDD44  48 16 74 D5 */	bl "makeSRT__7MatrixfFR10Vector3<f>R10Vector3<f>R10Vector3<f>"
/* 802C0E08 002BDD48  80 01 00 24 */	lwz r0, 0x24(r1)
/* 802C0E0C 002BDD4C  83 E1 00 1C */	lwz r31, 0x1c(r1)
/* 802C0E10 002BDD50  7C 08 03 A6 */	mtlr r0
/* 802C0E14 002BDD54  38 21 00 20 */	addi r1, r1, 0x20
/* 802C0E18 002BDD58  4E 80 00 20 */	blr 

.global finishAnimationIKSystem__Q34Game6Houdai3ObjFv
finishAnimationIKSystem__Q34Game6Houdai3ObjFv:
/* 802C0E1C 002BDD5C  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 802C0E20 002BDD60  7C 08 02 A6 */	mflr r0
/* 802C0E24 002BDD64  90 01 00 14 */	stw r0, 0x14(r1)
/* 802C0E28 002BDD68  80 63 02 F0 */	lwz r3, 0x2f0(r3)
/* 802C0E2C 002BDD6C  4B FE 82 A5 */	bl resetAnimationCallBack__Q24Game11IKSystemMgrFv
/* 802C0E30 002BDD70  80 01 00 14 */	lwz r0, 0x14(r1)
/* 802C0E34 002BDD74  7C 08 03 A6 */	mtlr r0
/* 802C0E38 002BDD78  38 21 00 10 */	addi r1, r1, 0x10
/* 802C0E3C 002BDD7C  4E 80 00 20 */	blr 

.global startProgramedIK__Q34Game6Houdai3ObjFv
startProgramedIK__Q34Game6Houdai3ObjFv:
/* 802C0E40 002BDD80  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 802C0E44 002BDD84  7C 08 02 A6 */	mflr r0
/* 802C0E48 002BDD88  90 01 00 14 */	stw r0, 0x14(r1)
/* 802C0E4C 002BDD8C  80 63 02 F0 */	lwz r3, 0x2f0(r3)
/* 802C0E50 002BDD90  4B FE 7F 31 */	bl startProgramedIK__Q24Game11IKSystemMgrFv
/* 802C0E54 002BDD94  80 01 00 14 */	lwz r0, 0x14(r1)
/* 802C0E58 002BDD98  7C 08 03 A6 */	mtlr r0
/* 802C0E5C 002BDD9C  38 21 00 10 */	addi r1, r1, 0x10
/* 802C0E60 002BDDA0  4E 80 00 20 */	blr 

.global startIKMotion__Q34Game6Houdai3ObjFv
startIKMotion__Q34Game6Houdai3ObjFv:
/* 802C0E64 002BDDA4  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 802C0E68 002BDDA8  7C 08 02 A6 */	mflr r0
/* 802C0E6C 002BDDAC  90 01 00 14 */	stw r0, 0x14(r1)
/* 802C0E70 002BDDB0  80 63 02 F0 */	lwz r3, 0x2f0(r3)
/* 802C0E74 002BDDB4  4B FE 80 95 */	bl startIKMotion__Q24Game11IKSystemMgrFv
/* 802C0E78 002BDDB8  80 01 00 14 */	lwz r0, 0x14(r1)
/* 802C0E7C 002BDDBC  7C 08 03 A6 */	mtlr r0
/* 802C0E80 002BDDC0  38 21 00 10 */	addi r1, r1, 0x10
/* 802C0E84 002BDDC4  4E 80 00 20 */	blr 

.global finishIKMotion__Q34Game6Houdai3ObjFv
finishIKMotion__Q34Game6Houdai3ObjFv:
/* 802C0E88 002BDDC8  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 802C0E8C 002BDDCC  7C 08 02 A6 */	mflr r0
/* 802C0E90 002BDDD0  90 01 00 14 */	stw r0, 0x14(r1)
/* 802C0E94 002BDDD4  80 63 02 F0 */	lwz r3, 0x2f0(r3)
/* 802C0E98 002BDDD8  4B FE 80 95 */	bl finishIKMotion__Q24Game11IKSystemMgrFv
/* 802C0E9C 002BDDDC  80 01 00 14 */	lwz r0, 0x14(r1)
/* 802C0EA0 002BDDE0  7C 08 03 A6 */	mtlr r0
/* 802C0EA4 002BDDE4  38 21 00 10 */	addi r1, r1, 0x10
/* 802C0EA8 002BDDE8  4E 80 00 20 */	blr 

.global forceFinishIKMotion__Q34Game6Houdai3ObjFv
forceFinishIKMotion__Q34Game6Houdai3ObjFv:
/* 802C0EAC 002BDDEC  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 802C0EB0 002BDDF0  7C 08 02 A6 */	mflr r0
/* 802C0EB4 002BDDF4  90 01 00 14 */	stw r0, 0x14(r1)
/* 802C0EB8 002BDDF8  80 63 02 F0 */	lwz r3, 0x2f0(r3)
/* 802C0EBC 002BDDFC  4B FE 80 7D */	bl forceFinishIKMotion__Q24Game11IKSystemMgrFv
/* 802C0EC0 002BDE00  80 01 00 14 */	lwz r0, 0x14(r1)
/* 802C0EC4 002BDE04  7C 08 03 A6 */	mtlr r0
/* 802C0EC8 002BDE08  38 21 00 10 */	addi r1, r1, 0x10
/* 802C0ECC 002BDE0C  4E 80 00 20 */	blr 

.global isFinishIKMotion__Q34Game6Houdai3ObjFv
isFinishIKMotion__Q34Game6Houdai3ObjFv:
/* 802C0ED0 002BDE10  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 802C0ED4 002BDE14  7C 08 02 A6 */	mflr r0
/* 802C0ED8 002BDE18  90 01 00 14 */	stw r0, 0x14(r1)
/* 802C0EDC 002BDE1C  80 63 02 F0 */	lwz r3, 0x2f0(r3)
/* 802C0EE0 002BDE20  4B FE 81 81 */	bl isFinishIKMotion__Q24Game11IKSystemMgrFv
/* 802C0EE4 002BDE24  80 01 00 14 */	lwz r0, 0x14(r1)
/* 802C0EE8 002BDE28  7C 08 03 A6 */	mtlr r0
/* 802C0EEC 002BDE2C  38 21 00 10 */	addi r1, r1, 0x10
/* 802C0EF0 002BDE30  4E 80 00 20 */	blr 

.global startBlendMotion__Q34Game6Houdai3ObjFv
startBlendMotion__Q34Game6Houdai3ObjFv:
/* 802C0EF4 002BDE34  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 802C0EF8 002BDE38  7C 08 02 A6 */	mflr r0
/* 802C0EFC 002BDE3C  90 01 00 14 */	stw r0, 0x14(r1)
/* 802C0F00 002BDE40  80 63 02 F0 */	lwz r3, 0x2f0(r3)
/* 802C0F04 002BDE44  4B FE 80 49 */	bl startBlendMotion__Q24Game11IKSystemMgrFv
/* 802C0F08 002BDE48  80 01 00 14 */	lwz r0, 0x14(r1)
/* 802C0F0C 002BDE4C  7C 08 03 A6 */	mtlr r0
/* 802C0F10 002BDE50  38 21 00 10 */	addi r1, r1, 0x10
/* 802C0F14 002BDE54  4E 80 00 20 */	blr 

.global finishBlendMotion__Q34Game6Houdai3ObjFv
finishBlendMotion__Q34Game6Houdai3ObjFv:
/* 802C0F18 002BDE58  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 802C0F1C 002BDE5C  7C 08 02 A6 */	mflr r0
/* 802C0F20 002BDE60  90 01 00 14 */	stw r0, 0x14(r1)
/* 802C0F24 002BDE64  80 63 02 F0 */	lwz r3, 0x2f0(r3)
/* 802C0F28 002BDE68  4B FE 80 81 */	bl finishBlendMotion__Q24Game11IKSystemMgrFv
/* 802C0F2C 002BDE6C  80 01 00 14 */	lwz r0, 0x14(r1)
/* 802C0F30 002BDE70  7C 08 03 A6 */	mtlr r0
/* 802C0F34 002BDE74  38 21 00 10 */	addi r1, r1, 0x10
/* 802C0F38 002BDE78  4E 80 00 20 */	blr 

.global getTraceCentrePosition__Q34Game6Houdai3ObjFv
getTraceCentrePosition__Q34Game6Houdai3ObjFv:
/* 802C0F3C 002BDE7C  80 84 02 F0 */	lwz r4, 0x2f0(r4)
/* 802C0F40 002BDE80  C0 04 00 44 */	lfs f0, 0x44(r4)
/* 802C0F44 002BDE84  D0 03 00 00 */	stfs f0, 0(r3)
/* 802C0F48 002BDE88  C0 04 00 48 */	lfs f0, 0x48(r4)
/* 802C0F4C 002BDE8C  D0 03 00 04 */	stfs f0, 4(r3)
/* 802C0F50 002BDE90  C0 04 00 4C */	lfs f0, 0x4c(r4)
/* 802C0F54 002BDE94  D0 03 00 08 */	stfs f0, 8(r3)
/* 802C0F58 002BDE98  4E 80 00 20 */	blr 

.global createShadowSystem__Q34Game6Houdai3ObjFv
createShadowSystem__Q34Game6Houdai3ObjFv:
/* 802C0F5C 002BDE9C  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 802C0F60 002BDEA0  7C 08 02 A6 */	mflr r0
/* 802C0F64 002BDEA4  90 01 00 14 */	stw r0, 0x14(r1)
/* 802C0F68 002BDEA8  93 E1 00 0C */	stw r31, 0xc(r1)
/* 802C0F6C 002BDEAC  7C 7F 1B 78 */	mr r31, r3
/* 802C0F70 002BDEB0  38 60 00 C4 */	li r3, 0xc4
/* 802C0F74 002BDEB4  4B D6 2F 31 */	bl __nw__FUl
/* 802C0F78 002BDEB8  7C 60 1B 79 */	or. r0, r3, r3
/* 802C0F7C 002BDEBC  41 82 00 10 */	beq .L_802C0F8C
/* 802C0F80 002BDEC0  7F E4 FB 78 */	mr r4, r31
/* 802C0F84 002BDEC4  4B FF E4 F9 */	bl __ct__Q34Game6Houdai15HoudaiShadowMgrFPQ34Game6Houdai3Obj
/* 802C0F88 002BDEC8  7C 60 1B 78 */	mr r0, r3
.L_802C0F8C:
/* 802C0F8C 002BDECC  90 1F 02 FC */	stw r0, 0x2fc(r31)
/* 802C0F90 002BDED0  80 01 00 14 */	lwz r0, 0x14(r1)
/* 802C0F94 002BDED4  83 E1 00 0C */	lwz r31, 0xc(r1)
/* 802C0F98 002BDED8  7C 08 03 A6 */	mtlr r0
/* 802C0F9C 002BDEDC  38 21 00 10 */	addi r1, r1, 0x10
/* 802C0FA0 002BDEE0  4E 80 00 20 */	blr 

.global setupShadowSystem__Q34Game6Houdai3ObjFv
setupShadowSystem__Q34Game6Houdai3ObjFv:
/* 802C0FA4 002BDEE4  94 21 FF E0 */	stwu r1, -0x20(r1)
/* 802C0FA8 002BDEE8  7C 08 02 A6 */	mflr r0
/* 802C0FAC 002BDEEC  90 01 00 24 */	stw r0, 0x24(r1)
/* 802C0FB0 002BDEF0  BF 61 00 0C */	stmw r27, 0xc(r1)
/* 802C0FB4 002BDEF4  7C 7B 1B 78 */	mr r27, r3
/* 802C0FB8 002BDEF8  80 63 02 FC */	lwz r3, 0x2fc(r3)
/* 802C0FBC 002BDEFC  4B FF E7 3D */	bl init__Q34Game6Houdai15HoudaiShadowMgrFv
/* 802C0FC0 002BDF00  3B A0 00 00 */	li r29, 0
/* 802C0FC4 002BDF04  7F 7E DB 78 */	mr r30, r27
.L_802C0FC8:
/* 802C0FC8 002BDF08  3B 80 00 00 */	li r28, 0
/* 802C0FCC 002BDF0C  7F DF F3 78 */	mr r31, r30
.L_802C0FD0:
/* 802C0FD0 002BDF10  80 7B 02 FC */	lwz r3, 0x2fc(r27)
/* 802C0FD4 002BDF14  7F A4 EB 78 */	mr r4, r29
/* 802C0FD8 002BDF18  7F 85 E3 78 */	mr r5, r28
/* 802C0FDC 002BDF1C  38 DF 03 04 */	addi r6, r31, 0x304
/* 802C0FE0 002BDF20  4B FF E8 C9 */	bl "setJointPosPtr__Q34Game6Houdai15HoudaiShadowMgrFiiP10Vector3<f>"
/* 802C0FE4 002BDF24  3B 9C 00 01 */	addi r28, r28, 1
/* 802C0FE8 002BDF28  3B FF 00 0C */	addi r31, r31, 0xc
/* 802C0FEC 002BDF2C  2C 1C 00 04 */	cmpwi r28, 4
/* 802C0FF0 002BDF30  41 80 FF E0 */	blt .L_802C0FD0
/* 802C0FF4 002BDF34  3B BD 00 01 */	addi r29, r29, 1
/* 802C0FF8 002BDF38  3B DE 00 30 */	addi r30, r30, 0x30
/* 802C0FFC 002BDF3C  2C 1D 00 04 */	cmpwi r29, 4
/* 802C1000 002BDF40  41 80 FF C8 */	blt .L_802C0FC8
/* 802C1004 002BDF44  BB 61 00 0C */	lmw r27, 0xc(r1)
/* 802C1008 002BDF48  80 01 00 24 */	lwz r0, 0x24(r1)
/* 802C100C 002BDF4C  7C 08 03 A6 */	mtlr r0
/* 802C1010 002BDF50  38 21 00 20 */	addi r1, r1, 0x20
/* 802C1014 002BDF54  4E 80 00 20 */	blr 

.global doAnimationShadowSystem__Q34Game6Houdai3ObjFv
doAnimationShadowSystem__Q34Game6Houdai3ObjFv:
/* 802C1018 002BDF58  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 802C101C 002BDF5C  7C 08 02 A6 */	mflr r0
/* 802C1020 002BDF60  90 01 00 14 */	stw r0, 0x14(r1)
/* 802C1024 002BDF64  80 63 02 FC */	lwz r3, 0x2fc(r3)
/* 802C1028 002BDF68  4B FF E8 99 */	bl update__Q34Game6Houdai15HoudaiShadowMgrFv
/* 802C102C 002BDF6C  80 01 00 14 */	lwz r0, 0x14(r1)
/* 802C1030 002BDF70  7C 08 03 A6 */	mtlr r0
/* 802C1034 002BDF74  38 21 00 10 */	addi r1, r1, 0x10
/* 802C1038 002BDF78  4E 80 00 20 */	blr 

.global setShotGunEmitKeepTimerOn__Q34Game6Houdai3ObjFv
setShotGunEmitKeepTimerOn__Q34Game6Houdai3ObjFv:
/* 802C103C 002BDF7C  94 21 FF D0 */	stwu r1, -0x30(r1)
/* 802C1040 002BDF80  7C 08 02 A6 */	mflr r0
/* 802C1044 002BDF84  90 01 00 34 */	stw r0, 0x34(r1)
/* 802C1048 002BDF88  DB E1 00 20 */	stfd f31, 0x20(r1)
/* 802C104C 002BDF8C  F3 E1 00 28 */	psq_st f31, 40(r1), 0, qr0
/* 802C1050 002BDF90  93 E1 00 1C */	stw r31, 0x1c(r1)
/* 802C1054 002BDF94  7C 7F 1B 78 */	mr r31, r3
/* 802C1058 002BDF98  80 63 00 C0 */	lwz r3, 0xc0(r3)
/* 802C105C 002BDF9C  C0 23 09 0C */	lfs f1, 0x90c(r3)
/* 802C1060 002BDFA0  C0 03 09 34 */	lfs f0, 0x934(r3)
/* 802C1064 002BDFA4  EF E1 00 28 */	fsubs f31, f1, f0
/* 802C1068 002BDFA8  4B E0 85 39 */	bl rand
/* 802C106C 002BDFAC  6C 63 80 00 */	xoris r3, r3, 0x8000
/* 802C1070 002BDFB0  3C 00 43 30 */	lis r0, 0x4330
/* 802C1074 002BDFB4  90 61 00 0C */	stw r3, 0xc(r1)
/* 802C1078 002BDFB8  C8 42 E1 C0 */	lfd f2, lbl_8051C520@sda21(r2)
/* 802C107C 002BDFBC  90 01 00 08 */	stw r0, 8(r1)
/* 802C1080 002BDFC0  C0 02 E1 BC */	lfs f0, lbl_8051C51C@sda21(r2)
/* 802C1084 002BDFC4  C8 21 00 08 */	lfd f1, 8(r1)
/* 802C1088 002BDFC8  EC 21 10 28 */	fsubs f1, f1, f2
/* 802C108C 002BDFCC  EC 3F 00 72 */	fmuls f1, f31, f1
/* 802C1090 002BDFD0  EC 01 00 24 */	fdivs f0, f1, f0
/* 802C1094 002BDFD4  D0 1F 02 CC */	stfs f0, 0x2cc(r31)
/* 802C1098 002BDFD8  E3 E1 00 28 */	psq_l f31, 40(r1), 0, qr0
/* 802C109C 002BDFDC  80 01 00 34 */	lwz r0, 0x34(r1)
/* 802C10A0 002BDFE0  CB E1 00 20 */	lfd f31, 0x20(r1)
/* 802C10A4 002BDFE4  83 E1 00 1C */	lwz r31, 0x1c(r1)
/* 802C10A8 002BDFE8  7C 08 03 A6 */	mtlr r0
/* 802C10AC 002BDFEC  38 21 00 30 */	addi r1, r1, 0x30
/* 802C10B0 002BDFF0  4E 80 00 20 */	blr 

.global setShotGunEmitKeepTimerOff__Q34Game6Houdai3ObjFv
setShotGunEmitKeepTimerOff__Q34Game6Houdai3ObjFv:
/* 802C10B4 002BDFF4  94 21 FF D0 */	stwu r1, -0x30(r1)
/* 802C10B8 002BDFF8  7C 08 02 A6 */	mflr r0
/* 802C10BC 002BDFFC  90 01 00 34 */	stw r0, 0x34(r1)
/* 802C10C0 002BE000  DB E1 00 20 */	stfd f31, 0x20(r1)
/* 802C10C4 002BE004  F3 E1 00 28 */	psq_st f31, 40(r1), 0, qr0
/* 802C10C8 002BE008  93 E1 00 1C */	stw r31, 0x1c(r1)
/* 802C10CC 002BE00C  7C 7F 1B 78 */	mr r31, r3
/* 802C10D0 002BE010  80 63 00 C0 */	lwz r3, 0xc0(r3)
/* 802C10D4 002BE014  C0 23 09 5C */	lfs f1, 0x95c(r3)
/* 802C10D8 002BE018  C0 03 09 84 */	lfs f0, 0x984(r3)
/* 802C10DC 002BE01C  EF E1 00 28 */	fsubs f31, f1, f0
/* 802C10E0 002BE020  4B E0 84 C1 */	bl rand
/* 802C10E4 002BE024  6C 63 80 00 */	xoris r3, r3, 0x8000
/* 802C10E8 002BE028  3C 00 43 30 */	lis r0, 0x4330
/* 802C10EC 002BE02C  90 61 00 0C */	stw r3, 0xc(r1)
/* 802C10F0 002BE030  C8 42 E1 C0 */	lfd f2, lbl_8051C520@sda21(r2)
/* 802C10F4 002BE034  90 01 00 08 */	stw r0, 8(r1)
/* 802C10F8 002BE038  C0 02 E1 BC */	lfs f0, lbl_8051C51C@sda21(r2)
/* 802C10FC 002BE03C  C8 21 00 08 */	lfd f1, 8(r1)
/* 802C1100 002BE040  EC 21 10 28 */	fsubs f1, f1, f2
/* 802C1104 002BE044  EC 3F 00 72 */	fmuls f1, f31, f1
/* 802C1108 002BE048  EC 01 00 24 */	fdivs f0, f1, f0
/* 802C110C 002BE04C  D0 1F 02 CC */	stfs f0, 0x2cc(r31)
/* 802C1110 002BE050  E3 E1 00 28 */	psq_l f31, 40(r1), 0, qr0
/* 802C1114 002BE054  80 01 00 34 */	lwz r0, 0x34(r1)
/* 802C1118 002BE058  CB E1 00 20 */	lfd f31, 0x20(r1)
/* 802C111C 002BE05C  83 E1 00 1C */	lwz r31, 0x1c(r1)
/* 802C1120 002BE060  7C 08 03 A6 */	mtlr r0
/* 802C1124 002BE064  38 21 00 30 */	addi r1, r1, 0x30
/* 802C1128 002BE068  4E 80 00 20 */	blr 

.global updateShotGunTimer__Q34Game6Houdai3ObjFv
updateShotGunTimer__Q34Game6Houdai3ObjFv:
/* 802C112C 002BE06C  80 03 01 E0 */	lwz r0, 0x1e0(r3)
/* 802C1130 002BE070  54 00 07 BD */	rlwinm. r0, r0, 0, 0x1e, 0x1e
/* 802C1134 002BE074  41 82 00 10 */	beq .L_802C1144
/* 802C1138 002BE078  C0 02 E1 98 */	lfs f0, lbl_8051C4F8@sda21(r2)
/* 802C113C 002BE07C  D0 03 02 C8 */	stfs f0, 0x2c8(r3)
/* 802C1140 002BE080  4E 80 00 20 */	blr 
.L_802C1144:
/* 802C1144 002BE084  80 8D 9A EC */	lwz r4, sys@sda21(r13)
/* 802C1148 002BE088  C0 23 02 C8 */	lfs f1, 0x2c8(r3)
/* 802C114C 002BE08C  C0 04 00 54 */	lfs f0, 0x54(r4)
/* 802C1150 002BE090  EC 01 00 2A */	fadds f0, f1, f0
/* 802C1154 002BE094  D0 03 02 C8 */	stfs f0, 0x2c8(r3)
/* 802C1158 002BE098  4E 80 00 20 */	blr 

.global isTransitShotGunState__Q34Game6Houdai3ObjFv
isTransitShotGunState__Q34Game6Houdai3ObjFv:
/* 802C115C 002BE09C  80 83 00 C0 */	lwz r4, 0xc0(r3)
/* 802C1160 002BE0A0  C0 23 02 C8 */	lfs f1, 0x2c8(r3)
/* 802C1164 002BE0A4  C0 04 04 74 */	lfs f0, 0x474(r4)
/* 802C1168 002BE0A8  FC 01 00 40 */	fcmpo cr0, f1, f0
/* 802C116C 002BE0AC  7C 00 00 26 */	mfcr r0
/* 802C1170 002BE0B0  54 03 17 FE */	rlwinm r3, r0, 2, 0x1f, 0x1f
/* 802C1174 002BE0B4  4E 80 00 20 */	blr 

.global createShotGun__Q34Game6Houdai3ObjFv
createShotGun__Q34Game6Houdai3ObjFv:
/* 802C1178 002BE0B8  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 802C117C 002BE0BC  7C 08 02 A6 */	mflr r0
/* 802C1180 002BE0C0  90 01 00 14 */	stw r0, 0x14(r1)
/* 802C1184 002BE0C4  93 E1 00 0C */	stw r31, 0xc(r1)
/* 802C1188 002BE0C8  7C 7F 1B 78 */	mr r31, r3
/* 802C118C 002BE0CC  38 60 00 3C */	li r3, 0x3c
/* 802C1190 002BE0D0  4B D6 2D 15 */	bl __nw__FUl
/* 802C1194 002BE0D4  7C 60 1B 79 */	or. r0, r3, r3
/* 802C1198 002BE0D8  41 82 00 10 */	beq .L_802C11A8
/* 802C119C 002BE0DC  7F E4 FB 78 */	mr r4, r31
/* 802C11A0 002BE0E0  48 00 33 35 */	bl __ct__Q34Game6Houdai16HoudaiShotGunMgrFPQ34Game6Houdai3Obj
/* 802C11A4 002BE0E4  7C 60 1B 78 */	mr r0, r3
.L_802C11A8:
/* 802C11A8 002BE0E8  90 1F 03 00 */	stw r0, 0x300(r31)
/* 802C11AC 002BE0EC  80 01 00 14 */	lwz r0, 0x14(r1)
/* 802C11B0 002BE0F0  83 E1 00 0C */	lwz r31, 0xc(r1)
/* 802C11B4 002BE0F4  7C 08 03 A6 */	mtlr r0
/* 802C11B8 002BE0F8  38 21 00 10 */	addi r1, r1, 0x10
/* 802C11BC 002BE0FC  4E 80 00 20 */	blr 

.global setupShotGun__Q34Game6Houdai3ObjFv
setupShotGun__Q34Game6Houdai3ObjFv:
/* 802C11C0 002BE100  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 802C11C4 002BE104  7C 08 02 A6 */	mflr r0
/* 802C11C8 002BE108  90 01 00 14 */	stw r0, 0x14(r1)
/* 802C11CC 002BE10C  80 63 03 00 */	lwz r3, 0x300(r3)
/* 802C11D0 002BE110  48 00 35 45 */	bl setupShotGun__Q34Game6Houdai16HoudaiShotGunMgrFv
/* 802C11D4 002BE114  80 01 00 14 */	lwz r0, 0x14(r1)
/* 802C11D8 002BE118  7C 08 03 A6 */	mtlr r0
/* 802C11DC 002BE11C  38 21 00 10 */	addi r1, r1, 0x10
/* 802C11E0 002BE120  4E 80 00 20 */	blr 

.global "setShotGunTarget__Q34Game6Houdai3ObjFR10Vector3<f>"
"setShotGunTarget__Q34Game6Houdai3ObjFR10Vector3<f>":
/* 802C11E4 002BE124  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 802C11E8 002BE128  7C 08 02 A6 */	mflr r0
/* 802C11EC 002BE12C  90 01 00 14 */	stw r0, 0x14(r1)
/* 802C11F0 002BE130  80 63 03 00 */	lwz r3, 0x300(r3)
/* 802C11F4 002BE134  48 00 36 39 */	bl "setShotGunTarget__Q34Game6Houdai16HoudaiShotGunMgrFR10Vector3<f>"
/* 802C11F8 002BE138  80 01 00 14 */	lwz r0, 0x14(r1)
/* 802C11FC 002BE13C  7C 08 03 A6 */	mtlr r0
/* 802C1200 002BE140  38 21 00 10 */	addi r1, r1, 0x10
/* 802C1204 002BE144  4E 80 00 20 */	blr 

.global resetShotGunCallBack__Q34Game6Houdai3ObjFv
resetShotGunCallBack__Q34Game6Houdai3ObjFv:
/* 802C1208 002BE148  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 802C120C 002BE14C  7C 08 02 A6 */	mflr r0
/* 802C1210 002BE150  90 01 00 14 */	stw r0, 0x14(r1)
/* 802C1214 002BE154  80 63 03 00 */	lwz r3, 0x300(r3)
/* 802C1218 002BE158  48 00 35 B1 */	bl resetCallBack__Q34Game6Houdai16HoudaiShotGunMgrFv
/* 802C121C 002BE15C  80 01 00 14 */	lwz r0, 0x14(r1)
/* 802C1220 002BE160  7C 08 03 A6 */	mtlr r0
/* 802C1224 002BE164  38 21 00 10 */	addi r1, r1, 0x10
/* 802C1228 002BE168  4E 80 00 20 */	blr 

.global setShotGunCallBack__Q34Game6Houdai3ObjFv
setShotGunCallBack__Q34Game6Houdai3ObjFv:
/* 802C122C 002BE16C  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 802C1230 002BE170  7C 08 02 A6 */	mflr r0
/* 802C1234 002BE174  90 01 00 14 */	stw r0, 0x14(r1)
/* 802C1238 002BE178  80 63 03 00 */	lwz r3, 0x300(r3)
/* 802C123C 002BE17C  48 00 35 99 */	bl setCallBack__Q34Game6Houdai16HoudaiShotGunMgrFv
/* 802C1240 002BE180  80 01 00 14 */	lwz r0, 0x14(r1)
/* 802C1244 002BE184  7C 08 03 A6 */	mtlr r0
/* 802C1248 002BE188  38 21 00 10 */	addi r1, r1, 0x10
/* 802C124C 002BE18C  4E 80 00 20 */	blr 

.global doUpdateShotGun__Q34Game6Houdai3ObjFv
doUpdateShotGun__Q34Game6Houdai3ObjFv:
/* 802C1250 002BE190  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 802C1254 002BE194  7C 08 02 A6 */	mflr r0
/* 802C1258 002BE198  90 01 00 14 */	stw r0, 0x14(r1)
/* 802C125C 002BE19C  80 63 03 00 */	lwz r3, 0x300(r3)
/* 802C1260 002BE1A0  48 00 39 A9 */	bl doUpdate__Q34Game6Houdai16HoudaiShotGunMgrFv
/* 802C1264 002BE1A4  80 01 00 14 */	lwz r0, 0x14(r1)
/* 802C1268 002BE1A8  7C 08 03 A6 */	mtlr r0
/* 802C126C 002BE1AC  38 21 00 10 */	addi r1, r1, 0x10
/* 802C1270 002BE1B0  4E 80 00 20 */	blr 

.global doUpdateCommonShotGun__Q34Game6Houdai3ObjFv
doUpdateCommonShotGun__Q34Game6Houdai3ObjFv:
/* 802C1274 002BE1B4  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 802C1278 002BE1B8  7C 08 02 A6 */	mflr r0
/* 802C127C 002BE1BC  90 01 00 14 */	stw r0, 0x14(r1)
/* 802C1280 002BE1C0  80 63 03 00 */	lwz r3, 0x300(r3)
/* 802C1284 002BE1C4  48 00 3A 09 */	bl doUpdateCommon__Q34Game6Houdai16HoudaiShotGunMgrFv
/* 802C1288 002BE1C8  80 01 00 14 */	lwz r0, 0x14(r1)
/* 802C128C 002BE1CC  7C 08 03 A6 */	mtlr r0
/* 802C1290 002BE1D0  38 21 00 10 */	addi r1, r1, 0x10
/* 802C1294 002BE1D4  4E 80 00 20 */	blr 

.global startShotGunRotation__Q34Game6Houdai3ObjFv
startShotGunRotation__Q34Game6Houdai3ObjFv:
/* 802C1298 002BE1D8  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 802C129C 002BE1DC  7C 08 02 A6 */	mflr r0
/* 802C12A0 002BE1E0  90 01 00 14 */	stw r0, 0x14(r1)
/* 802C12A4 002BE1E4  80 63 03 00 */	lwz r3, 0x300(r3)
/* 802C12A8 002BE1E8  48 00 35 35 */	bl startRotation__Q34Game6Houdai16HoudaiShotGunMgrFv
/* 802C12AC 002BE1EC  80 01 00 14 */	lwz r0, 0x14(r1)
/* 802C12B0 002BE1F0  7C 08 03 A6 */	mtlr r0
/* 802C12B4 002BE1F4  38 21 00 10 */	addi r1, r1, 0x10
/* 802C12B8 002BE1F8  4E 80 00 20 */	blr 

.global finishShotGunRotation__Q34Game6Houdai3ObjFv
finishShotGunRotation__Q34Game6Houdai3ObjFv:
/* 802C12BC 002BE1FC  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 802C12C0 002BE200  7C 08 02 A6 */	mflr r0
/* 802C12C4 002BE204  90 01 00 14 */	stw r0, 0x14(r1)
/* 802C12C8 002BE208  80 63 03 00 */	lwz r3, 0x300(r3)
/* 802C12CC 002BE20C  48 00 35 35 */	bl finishRotation__Q34Game6Houdai16HoudaiShotGunMgrFv
/* 802C12D0 002BE210  80 01 00 14 */	lwz r0, 0x14(r1)
/* 802C12D4 002BE214  7C 08 03 A6 */	mtlr r0
/* 802C12D8 002BE218  38 21 00 10 */	addi r1, r1, 0x10
/* 802C12DC 002BE21C  4E 80 00 20 */	blr 

.global isShotGunRotation__Q34Game6Houdai3ObjFv
isShotGunRotation__Q34Game6Houdai3ObjFv:
/* 802C12E0 002BE220  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 802C12E4 002BE224  7C 08 02 A6 */	mflr r0
/* 802C12E8 002BE228  90 01 00 14 */	stw r0, 0x14(r1)
/* 802C12EC 002BE22C  80 63 03 00 */	lwz r3, 0x300(r3)
/* 802C12F0 002BE230  48 00 35 25 */	bl isShotGunRotation__Q34Game6Houdai16HoudaiShotGunMgrFv
/* 802C12F4 002BE234  80 01 00 14 */	lwz r0, 0x14(r1)
/* 802C12F8 002BE238  7C 08 03 A6 */	mtlr r0
/* 802C12FC 002BE23C  38 21 00 10 */	addi r1, r1, 0x10
/* 802C1300 002BE240  4E 80 00 20 */	blr 

.global isShotGunLockOn__Q34Game6Houdai3ObjFv
isShotGunLockOn__Q34Game6Houdai3ObjFv:
/* 802C1304 002BE244  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 802C1308 002BE248  7C 08 02 A6 */	mflr r0
/* 802C130C 002BE24C  90 01 00 14 */	stw r0, 0x14(r1)
/* 802C1310 002BE250  80 63 03 00 */	lwz r3, 0x300(r3)
/* 802C1314 002BE254  48 00 35 09 */	bl isShotGunLockOn__Q34Game6Houdai16HoudaiShotGunMgrFv
/* 802C1318 002BE258  80 01 00 14 */	lwz r0, 0x14(r1)
/* 802C131C 002BE25C  7C 08 03 A6 */	mtlr r0
/* 802C1320 002BE260  38 21 00 10 */	addi r1, r1, 0x10
/* 802C1324 002BE264  4E 80 00 20 */	blr 

.global isFinishShotGun__Q34Game6Houdai3ObjFv
isFinishShotGun__Q34Game6Houdai3ObjFv:
/* 802C1328 002BE268  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 802C132C 002BE26C  7C 08 02 A6 */	mflr r0
/* 802C1330 002BE270  90 01 00 14 */	stw r0, 0x14(r1)
/* 802C1334 002BE274  80 63 03 00 */	lwz r3, 0x300(r3)
/* 802C1338 002BE278  48 00 34 ED */	bl isFinishShotGun__Q34Game6Houdai16HoudaiShotGunMgrFv
/* 802C133C 002BE27C  80 01 00 14 */	lwz r0, 0x14(r1)
/* 802C1340 002BE280  7C 08 03 A6 */	mtlr r0
/* 802C1344 002BE284  38 21 00 10 */	addi r1, r1, 0x10
/* 802C1348 002BE288  4E 80 00 20 */	blr 

.global emitShotGun__Q34Game6Houdai3ObjFv
emitShotGun__Q34Game6Houdai3ObjFv:
/* 802C134C 002BE28C  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 802C1350 002BE290  7C 08 02 A6 */	mflr r0
/* 802C1354 002BE294  90 01 00 14 */	stw r0, 0x14(r1)
/* 802C1358 002BE298  93 E1 00 0C */	stw r31, 0xc(r1)
/* 802C135C 002BE29C  7C 7F 1B 78 */	mr r31, r3
/* 802C1360 002BE2A0  80 63 03 00 */	lwz r3, 0x300(r3)
/* 802C1364 002BE2A4  48 00 34 E5 */	bl emitShotGun__Q34Game6Houdai16HoudaiShotGunMgrFv
/* 802C1368 002BE2A8  7F E3 FB 78 */	mr r3, r31
/* 802C136C 002BE2AC  81 9F 00 00 */	lwz r12, 0(r31)
/* 802C1370 002BE2B0  81 8C 00 F4 */	lwz r12, 0xf4(r12)
/* 802C1374 002BE2B4  7D 89 03 A6 */	mtctr r12
/* 802C1378 002BE2B8  4E 80 04 21 */	bctrl 
/* 802C137C 002BE2BC  81 83 00 00 */	lwz r12, 0(r3)
/* 802C1380 002BE2C0  38 80 59 34 */	li r4, 0x5934
/* 802C1384 002BE2C4  38 A0 00 00 */	li r5, 0
/* 802C1388 002BE2C8  81 8C 00 0C */	lwz r12, 0xc(r12)
/* 802C138C 002BE2CC  7D 89 03 A6 */	mtctr r12
/* 802C1390 002BE2D0  4E 80 04 21 */	bctrl 
/* 802C1394 002BE2D4  80 01 00 14 */	lwz r0, 0x14(r1)
/* 802C1398 002BE2D8  83 E1 00 0C */	lwz r31, 0xc(r1)
/* 802C139C 002BE2DC  7C 08 03 A6 */	mtlr r0
/* 802C13A0 002BE2E0  38 21 00 10 */	addi r1, r1, 0x10
/* 802C13A4 002BE2E4  4E 80 00 20 */	blr 

.global forceFinishShotGun__Q34Game6Houdai3ObjFv
forceFinishShotGun__Q34Game6Houdai3ObjFv:
/* 802C13A8 002BE2E8  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 802C13AC 002BE2EC  7C 08 02 A6 */	mflr r0
/* 802C13B0 002BE2F0  90 01 00 14 */	stw r0, 0x14(r1)
/* 802C13B4 002BE2F4  80 63 03 00 */	lwz r3, 0x300(r3)
/* 802C13B8 002BE2F8  48 00 39 4D */	bl forceFinishShotGun__Q34Game6Houdai16HoudaiShotGunMgrFv
/* 802C13BC 002BE2FC  80 01 00 14 */	lwz r0, 0x14(r1)
/* 802C13C0 002BE300  7C 08 03 A6 */	mtlr r0
/* 802C13C4 002BE304  38 21 00 10 */	addi r1, r1, 0x10
/* 802C13C8 002BE308  4E 80 00 20 */	blr 

.global setupCollision__Q34Game6Houdai3ObjFv
setupCollision__Q34Game6Houdai3ObjFv:
/* 802C13CC 002BE30C  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 802C13D0 002BE310  7C 08 02 A6 */	mflr r0
/* 802C13D4 002BE314  3C 80 72 68 */	lis r4, 0x72687431@ha
/* 802C13D8 002BE318  90 01 00 14 */	stw r0, 0x14(r1)
/* 802C13DC 002BE31C  38 84 74 31 */	addi r4, r4, 0x72687431@l
/* 802C13E0 002BE320  80 63 01 14 */	lwz r3, 0x114(r3)
/* 802C13E4 002BE324  4B E7 4A 61 */	bl getCollPart__8CollTreeFUl
/* 802C13E8 002BE328  28 03 00 00 */	cmplwi r3, 0
/* 802C13EC 002BE32C  41 82 00 08 */	beq .L_802C13F4
/* 802C13F0 002BE330  4B E7 5F AD */	bl makeTubeTree__8CollPartFv
.L_802C13F4:
/* 802C13F4 002BE334  80 01 00 14 */	lwz r0, 0x14(r1)
/* 802C13F8 002BE338  7C 08 03 A6 */	mtlr r0
/* 802C13FC 002BE33C  38 21 00 10 */	addi r1, r1, 0x10
/* 802C1400 002BE340  4E 80 00 20 */	blr 

.global startBossChargeBGM__Q34Game6Houdai3ObjFv
startBossChargeBGM__Q34Game6Houdai3ObjFv:
/* 802C1404 002BE344  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 802C1408 002BE348  7C 08 02 A6 */	mflr r0
/* 802C140C 002BE34C  90 01 00 14 */	stw r0, 0x14(r1)
/* 802C1410 002BE350  93 E1 00 0C */	stw r31, 0xc(r1)
/* 802C1414 002BE354  3B E0 00 00 */	li r31, 0
/* 802C1418 002BE358  93 C1 00 08 */	stw r30, 8(r1)
/* 802C141C 002BE35C  83 C3 02 8C */	lwz r30, 0x28c(r3)
/* 802C1420 002BE360  81 9E 00 28 */	lwz r12, 0x28(r30)
/* 802C1424 002BE364  7F C3 F3 78 */	mr r3, r30
/* 802C1428 002BE368  81 8C 00 1C */	lwz r12, 0x1c(r12)
/* 802C142C 002BE36C  7D 89 03 A6 */	mtctr r12
/* 802C1430 002BE370  4E 80 04 21 */	bctrl 
/* 802C1434 002BE374  2C 03 00 05 */	cmpwi r3, 5
/* 802C1438 002BE378  41 82 00 3C */	beq .L_802C1474
/* 802C143C 002BE37C  7F C3 F3 78 */	mr r3, r30
/* 802C1440 002BE380  81 9E 00 28 */	lwz r12, 0x28(r30)
/* 802C1444 002BE384  81 8C 00 1C */	lwz r12, 0x1c(r12)
/* 802C1448 002BE388  7D 89 03 A6 */	mtctr r12
/* 802C144C 002BE38C  4E 80 04 21 */	bctrl 
/* 802C1450 002BE390  2C 03 00 06 */	cmpwi r3, 6
/* 802C1454 002BE394  41 82 00 20 */	beq .L_802C1474
/* 802C1458 002BE398  7F C3 F3 78 */	mr r3, r30
/* 802C145C 002BE39C  81 9E 00 28 */	lwz r12, 0x28(r30)
/* 802C1460 002BE3A0  81 8C 00 1C */	lwz r12, 0x1c(r12)
/* 802C1464 002BE3A4  7D 89 03 A6 */	mtctr r12
/* 802C1468 002BE3A8  4E 80 04 21 */	bctrl 
/* 802C146C 002BE3AC  2C 03 00 07 */	cmpwi r3, 7
/* 802C1470 002BE3B0  40 82 00 08 */	bne .L_802C1478
.L_802C1474:
/* 802C1474 002BE3B4  3B E0 00 01 */	li r31, 1
.L_802C1478:
/* 802C1478 002BE3B8  57 E0 06 3F */	clrlwi. r0, r31, 0x18
/* 802C147C 002BE3BC  40 82 00 20 */	bne .L_802C149C
/* 802C1480 002BE3C0  3C 60 80 49 */	lis r3, lbl_8048B198@ha
/* 802C1484 002BE3C4  3C A0 80 49 */	lis r5, lbl_8048B1B0@ha
/* 802C1488 002BE3C8  38 63 B1 98 */	addi r3, r3, lbl_8048B198@l
/* 802C148C 002BE3CC  38 80 04 54 */	li r4, 0x454
/* 802C1490 002BE3D0  38 A5 B1 B0 */	addi r5, r5, lbl_8048B1B0@l
/* 802C1494 002BE3D4  4C C6 31 82 */	crclr 6
/* 802C1498 002BE3D8  4B D6 91 A9 */	bl panic_f__12JUTExceptionFPCciPCce
.L_802C149C:
/* 802C149C 002BE3DC  7F C3 F3 78 */	mr r3, r30
/* 802C14A0 002BE3E0  38 80 00 02 */	li r4, 2
/* 802C14A4 002BE3E4  81 9E 00 28 */	lwz r12, 0x28(r30)
/* 802C14A8 002BE3E8  81 8C 00 D4 */	lwz r12, 0xd4(r12)
/* 802C14AC 002BE3EC  7D 89 03 A6 */	mtctr r12
/* 802C14B0 002BE3F0  4E 80 04 21 */	bctrl 
/* 802C14B4 002BE3F4  80 01 00 14 */	lwz r0, 0x14(r1)
/* 802C14B8 002BE3F8  83 E1 00 0C */	lwz r31, 0xc(r1)
/* 802C14BC 002BE3FC  83 C1 00 08 */	lwz r30, 8(r1)
/* 802C14C0 002BE400  7C 08 03 A6 */	mtlr r0
/* 802C14C4 002BE404  38 21 00 10 */	addi r1, r1, 0x10
/* 802C14C8 002BE408  4E 80 00 20 */	blr 

.global startBossAttackLoopBGM__Q34Game6Houdai3ObjFv
startBossAttackLoopBGM__Q34Game6Houdai3ObjFv:
/* 802C14CC 002BE40C  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 802C14D0 002BE410  7C 08 02 A6 */	mflr r0
/* 802C14D4 002BE414  90 01 00 14 */	stw r0, 0x14(r1)
/* 802C14D8 002BE418  93 E1 00 0C */	stw r31, 0xc(r1)
/* 802C14DC 002BE41C  93 C1 00 08 */	stw r30, 8(r1)
/* 802C14E0 002BE420  88 03 02 EF */	lbz r0, 0x2ef(r3)
/* 802C14E4 002BE424  28 00 00 00 */	cmplwi r0, 0
/* 802C14E8 002BE428  40 82 00 A8 */	bne .L_802C1590
/* 802C14EC 002BE42C  38 00 00 01 */	li r0, 1
/* 802C14F0 002BE430  3B E0 00 00 */	li r31, 0
/* 802C14F4 002BE434  98 03 02 EF */	stb r0, 0x2ef(r3)
/* 802C14F8 002BE438  83 C3 02 8C */	lwz r30, 0x28c(r3)
/* 802C14FC 002BE43C  7F C3 F3 78 */	mr r3, r30
/* 802C1500 002BE440  81 9E 00 28 */	lwz r12, 0x28(r30)
/* 802C1504 002BE444  81 8C 00 1C */	lwz r12, 0x1c(r12)
/* 802C1508 002BE448  7D 89 03 A6 */	mtctr r12
/* 802C150C 002BE44C  4E 80 04 21 */	bctrl 
/* 802C1510 002BE450  2C 03 00 05 */	cmpwi r3, 5
/* 802C1514 002BE454  41 82 00 3C */	beq .L_802C1550
/* 802C1518 002BE458  7F C3 F3 78 */	mr r3, r30
/* 802C151C 002BE45C  81 9E 00 28 */	lwz r12, 0x28(r30)
/* 802C1520 002BE460  81 8C 00 1C */	lwz r12, 0x1c(r12)
/* 802C1524 002BE464  7D 89 03 A6 */	mtctr r12
/* 802C1528 002BE468  4E 80 04 21 */	bctrl 
/* 802C152C 002BE46C  2C 03 00 06 */	cmpwi r3, 6
/* 802C1530 002BE470  41 82 00 20 */	beq .L_802C1550
/* 802C1534 002BE474  7F C3 F3 78 */	mr r3, r30
/* 802C1538 002BE478  81 9E 00 28 */	lwz r12, 0x28(r30)
/* 802C153C 002BE47C  81 8C 00 1C */	lwz r12, 0x1c(r12)
/* 802C1540 002BE480  7D 89 03 A6 */	mtctr r12
/* 802C1544 002BE484  4E 80 04 21 */	bctrl 
/* 802C1548 002BE488  2C 03 00 07 */	cmpwi r3, 7
/* 802C154C 002BE48C  40 82 00 08 */	bne .L_802C1554
.L_802C1550:
/* 802C1550 002BE490  3B E0 00 01 */	li r31, 1
.L_802C1554:
/* 802C1554 002BE494  57 E0 06 3F */	clrlwi. r0, r31, 0x18
/* 802C1558 002BE498  40 82 00 20 */	bne .L_802C1578
/* 802C155C 002BE49C  3C 60 80 49 */	lis r3, lbl_8048B198@ha
/* 802C1560 002BE4A0  3C A0 80 49 */	lis r5, lbl_8048B1B0@ha
/* 802C1564 002BE4A4  38 63 B1 98 */	addi r3, r3, lbl_8048B198@l
/* 802C1568 002BE4A8  38 80 04 54 */	li r4, 0x454
/* 802C156C 002BE4AC  38 A5 B1 B0 */	addi r5, r5, lbl_8048B1B0@l
/* 802C1570 002BE4B0  4C C6 31 82 */	crclr 6
/* 802C1574 002BE4B4  4B D6 90 CD */	bl panic_f__12JUTExceptionFPCciPCce
.L_802C1578:
/* 802C1578 002BE4B8  7F C3 F3 78 */	mr r3, r30
/* 802C157C 002BE4BC  38 80 00 08 */	li r4, 8
/* 802C1580 002BE4C0  81 9E 00 28 */	lwz r12, 0x28(r30)
/* 802C1584 002BE4C4  81 8C 00 D4 */	lwz r12, 0xd4(r12)
/* 802C1588 002BE4C8  7D 89 03 A6 */	mtctr r12
/* 802C158C 002BE4CC  4E 80 04 21 */	bctrl 
.L_802C1590:
/* 802C1590 002BE4D0  80 01 00 14 */	lwz r0, 0x14(r1)
/* 802C1594 002BE4D4  83 E1 00 0C */	lwz r31, 0xc(r1)
/* 802C1598 002BE4D8  83 C1 00 08 */	lwz r30, 8(r1)
/* 802C159C 002BE4DC  7C 08 03 A6 */	mtlr r0
/* 802C15A0 002BE4E0  38 21 00 10 */	addi r1, r1, 0x10
/* 802C15A4 002BE4E4  4E 80 00 20 */	blr 

.global finishBossAttackLoopBGM__Q34Game6Houdai3ObjFv
finishBossAttackLoopBGM__Q34Game6Houdai3ObjFv:
/* 802C15A8 002BE4E8  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 802C15AC 002BE4EC  7C 08 02 A6 */	mflr r0
/* 802C15B0 002BE4F0  90 01 00 14 */	stw r0, 0x14(r1)
/* 802C15B4 002BE4F4  93 E1 00 0C */	stw r31, 0xc(r1)
/* 802C15B8 002BE4F8  93 C1 00 08 */	stw r30, 8(r1)
/* 802C15BC 002BE4FC  88 03 02 EF */	lbz r0, 0x2ef(r3)
/* 802C15C0 002BE500  28 00 00 00 */	cmplwi r0, 0
/* 802C15C4 002BE504  41 82 00 A4 */	beq .L_802C1668
/* 802C15C8 002BE508  3B E0 00 00 */	li r31, 0
/* 802C15CC 002BE50C  9B E3 02 EF */	stb r31, 0x2ef(r3)
/* 802C15D0 002BE510  83 C3 02 8C */	lwz r30, 0x28c(r3)
/* 802C15D4 002BE514  81 9E 00 28 */	lwz r12, 0x28(r30)
/* 802C15D8 002BE518  7F C3 F3 78 */	mr r3, r30
/* 802C15DC 002BE51C  81 8C 00 1C */	lwz r12, 0x1c(r12)
/* 802C15E0 002BE520  7D 89 03 A6 */	mtctr r12
/* 802C15E4 002BE524  4E 80 04 21 */	bctrl 
/* 802C15E8 002BE528  2C 03 00 05 */	cmpwi r3, 5
/* 802C15EC 002BE52C  41 82 00 3C */	beq .L_802C1628
/* 802C15F0 002BE530  7F C3 F3 78 */	mr r3, r30
/* 802C15F4 002BE534  81 9E 00 28 */	lwz r12, 0x28(r30)
/* 802C15F8 002BE538  81 8C 00 1C */	lwz r12, 0x1c(r12)
/* 802C15FC 002BE53C  7D 89 03 A6 */	mtctr r12
/* 802C1600 002BE540  4E 80 04 21 */	bctrl 
/* 802C1604 002BE544  2C 03 00 06 */	cmpwi r3, 6
/* 802C1608 002BE548  41 82 00 20 */	beq .L_802C1628
/* 802C160C 002BE54C  7F C3 F3 78 */	mr r3, r30
/* 802C1610 002BE550  81 9E 00 28 */	lwz r12, 0x28(r30)
/* 802C1614 002BE554  81 8C 00 1C */	lwz r12, 0x1c(r12)
/* 802C1618 002BE558  7D 89 03 A6 */	mtctr r12
/* 802C161C 002BE55C  4E 80 04 21 */	bctrl 
/* 802C1620 002BE560  2C 03 00 07 */	cmpwi r3, 7
/* 802C1624 002BE564  40 82 00 08 */	bne .L_802C162C
.L_802C1628:
/* 802C1628 002BE568  3B E0 00 01 */	li r31, 1
.L_802C162C:
/* 802C162C 002BE56C  57 E0 06 3F */	clrlwi. r0, r31, 0x18
/* 802C1630 002BE570  40 82 00 20 */	bne .L_802C1650
/* 802C1634 002BE574  3C 60 80 49 */	lis r3, lbl_8048B198@ha
/* 802C1638 002BE578  3C A0 80 49 */	lis r5, lbl_8048B1B0@ha
/* 802C163C 002BE57C  38 63 B1 98 */	addi r3, r3, lbl_8048B198@l
/* 802C1640 002BE580  38 80 04 54 */	li r4, 0x454
/* 802C1644 002BE584  38 A5 B1 B0 */	addi r5, r5, lbl_8048B1B0@l
/* 802C1648 002BE588  4C C6 31 82 */	crclr 6
/* 802C164C 002BE58C  4B D6 8F F5 */	bl panic_f__12JUTExceptionFPCciPCce
.L_802C1650:
/* 802C1650 002BE590  7F C3 F3 78 */	mr r3, r30
/* 802C1654 002BE594  38 80 00 01 */	li r4, 1
/* 802C1658 002BE598  81 9E 00 28 */	lwz r12, 0x28(r30)
/* 802C165C 002BE59C  81 8C 00 D4 */	lwz r12, 0xd4(r12)
/* 802C1660 002BE5A0  7D 89 03 A6 */	mtctr r12
/* 802C1664 002BE5A4  4E 80 04 21 */	bctrl 
.L_802C1668:
/* 802C1668 002BE5A8  80 01 00 14 */	lwz r0, 0x14(r1)
/* 802C166C 002BE5AC  83 E1 00 0C */	lwz r31, 0xc(r1)
/* 802C1670 002BE5B0  83 C1 00 08 */	lwz r30, 8(r1)
/* 802C1674 002BE5B4  7C 08 03 A6 */	mtlr r0
/* 802C1678 002BE5B8  38 21 00 10 */	addi r1, r1, 0x10
/* 802C167C 002BE5BC  4E 80 00 20 */	blr 

.global startStoneStateBossAttackLoopBGM__Q34Game6Houdai3ObjFv
startStoneStateBossAttackLoopBGM__Q34Game6Houdai3ObjFv:
/* 802C1680 002BE5C0  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 802C1684 002BE5C4  7C 08 02 A6 */	mflr r0
/* 802C1688 002BE5C8  90 01 00 14 */	stw r0, 0x14(r1)
/* 802C168C 002BE5CC  93 E1 00 0C */	stw r31, 0xc(r1)
/* 802C1690 002BE5D0  93 C1 00 08 */	stw r30, 8(r1)
/* 802C1694 002BE5D4  88 03 02 EF */	lbz r0, 0x2ef(r3)
/* 802C1698 002BE5D8  28 00 00 00 */	cmplwi r0, 0
/* 802C169C 002BE5DC  41 82 00 A0 */	beq .L_802C173C
/* 802C16A0 002BE5E0  83 C3 02 8C */	lwz r30, 0x28c(r3)
/* 802C16A4 002BE5E4  3B E0 00 00 */	li r31, 0
/* 802C16A8 002BE5E8  7F C3 F3 78 */	mr r3, r30
/* 802C16AC 002BE5EC  81 9E 00 28 */	lwz r12, 0x28(r30)
/* 802C16B0 002BE5F0  81 8C 00 1C */	lwz r12, 0x1c(r12)
/* 802C16B4 002BE5F4  7D 89 03 A6 */	mtctr r12
/* 802C16B8 002BE5F8  4E 80 04 21 */	bctrl 
/* 802C16BC 002BE5FC  2C 03 00 05 */	cmpwi r3, 5
/* 802C16C0 002BE600  41 82 00 3C */	beq .L_802C16FC
/* 802C16C4 002BE604  7F C3 F3 78 */	mr r3, r30
/* 802C16C8 002BE608  81 9E 00 28 */	lwz r12, 0x28(r30)
/* 802C16CC 002BE60C  81 8C 00 1C */	lwz r12, 0x1c(r12)
/* 802C16D0 002BE610  7D 89 03 A6 */	mtctr r12
/* 802C16D4 002BE614  4E 80 04 21 */	bctrl 
/* 802C16D8 002BE618  2C 03 00 06 */	cmpwi r3, 6
/* 802C16DC 002BE61C  41 82 00 20 */	beq .L_802C16FC
/* 802C16E0 002BE620  7F C3 F3 78 */	mr r3, r30
/* 802C16E4 002BE624  81 9E 00 28 */	lwz r12, 0x28(r30)
/* 802C16E8 002BE628  81 8C 00 1C */	lwz r12, 0x1c(r12)
/* 802C16EC 002BE62C  7D 89 03 A6 */	mtctr r12
/* 802C16F0 002BE630  4E 80 04 21 */	bctrl 
/* 802C16F4 002BE634  2C 03 00 07 */	cmpwi r3, 7
/* 802C16F8 002BE638  40 82 00 08 */	bne .L_802C1700
.L_802C16FC:
/* 802C16FC 002BE63C  3B E0 00 01 */	li r31, 1
.L_802C1700:
/* 802C1700 002BE640  57 E0 06 3F */	clrlwi. r0, r31, 0x18
/* 802C1704 002BE644  40 82 00 20 */	bne .L_802C1724
/* 802C1708 002BE648  3C 60 80 49 */	lis r3, lbl_8048B198@ha
/* 802C170C 002BE64C  3C A0 80 49 */	lis r5, lbl_8048B1B0@ha
/* 802C1710 002BE650  38 63 B1 98 */	addi r3, r3, lbl_8048B198@l
/* 802C1714 002BE654  38 80 04 54 */	li r4, 0x454
/* 802C1718 002BE658  38 A5 B1 B0 */	addi r5, r5, lbl_8048B1B0@l
/* 802C171C 002BE65C  4C C6 31 82 */	crclr 6
/* 802C1720 002BE660  4B D6 8F 21 */	bl panic_f__12JUTExceptionFPCciPCce
.L_802C1724:
/* 802C1724 002BE664  7F C3 F3 78 */	mr r3, r30
/* 802C1728 002BE668  38 80 00 01 */	li r4, 1
/* 802C172C 002BE66C  81 9E 00 28 */	lwz r12, 0x28(r30)
/* 802C1730 002BE670  81 8C 00 D4 */	lwz r12, 0xd4(r12)
/* 802C1734 002BE674  7D 89 03 A6 */	mtctr r12
/* 802C1738 002BE678  4E 80 04 21 */	bctrl 
.L_802C173C:
/* 802C173C 002BE67C  80 01 00 14 */	lwz r0, 0x14(r1)
/* 802C1740 002BE680  83 E1 00 0C */	lwz r31, 0xc(r1)
/* 802C1744 002BE684  83 C1 00 08 */	lwz r30, 8(r1)
/* 802C1748 002BE688  7C 08 03 A6 */	mtlr r0
/* 802C174C 002BE68C  38 21 00 10 */	addi r1, r1, 0x10
/* 802C1750 002BE690  4E 80 00 20 */	blr 

.global finishStoneStateBossAttackLoopBGM__Q34Game6Houdai3ObjFv
finishStoneStateBossAttackLoopBGM__Q34Game6Houdai3ObjFv:
/* 802C1754 002BE694  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 802C1758 002BE698  7C 08 02 A6 */	mflr r0
/* 802C175C 002BE69C  90 01 00 14 */	stw r0, 0x14(r1)
/* 802C1760 002BE6A0  93 E1 00 0C */	stw r31, 0xc(r1)
/* 802C1764 002BE6A4  93 C1 00 08 */	stw r30, 8(r1)
/* 802C1768 002BE6A8  88 03 02 EF */	lbz r0, 0x2ef(r3)
/* 802C176C 002BE6AC  28 00 00 00 */	cmplwi r0, 0
/* 802C1770 002BE6B0  41 82 00 A0 */	beq .L_802C1810
/* 802C1774 002BE6B4  83 C3 02 8C */	lwz r30, 0x28c(r3)
/* 802C1778 002BE6B8  3B E0 00 00 */	li r31, 0
/* 802C177C 002BE6BC  7F C3 F3 78 */	mr r3, r30
/* 802C1780 002BE6C0  81 9E 00 28 */	lwz r12, 0x28(r30)
/* 802C1784 002BE6C4  81 8C 00 1C */	lwz r12, 0x1c(r12)
/* 802C1788 002BE6C8  7D 89 03 A6 */	mtctr r12
/* 802C178C 002BE6CC  4E 80 04 21 */	bctrl 
/* 802C1790 002BE6D0  2C 03 00 05 */	cmpwi r3, 5
/* 802C1794 002BE6D4  41 82 00 3C */	beq .L_802C17D0
/* 802C1798 002BE6D8  7F C3 F3 78 */	mr r3, r30
/* 802C179C 002BE6DC  81 9E 00 28 */	lwz r12, 0x28(r30)
/* 802C17A0 002BE6E0  81 8C 00 1C */	lwz r12, 0x1c(r12)
/* 802C17A4 002BE6E4  7D 89 03 A6 */	mtctr r12
/* 802C17A8 002BE6E8  4E 80 04 21 */	bctrl 
/* 802C17AC 002BE6EC  2C 03 00 06 */	cmpwi r3, 6
/* 802C17B0 002BE6F0  41 82 00 20 */	beq .L_802C17D0
/* 802C17B4 002BE6F4  7F C3 F3 78 */	mr r3, r30
/* 802C17B8 002BE6F8  81 9E 00 28 */	lwz r12, 0x28(r30)
/* 802C17BC 002BE6FC  81 8C 00 1C */	lwz r12, 0x1c(r12)
/* 802C17C0 002BE700  7D 89 03 A6 */	mtctr r12
/* 802C17C4 002BE704  4E 80 04 21 */	bctrl 
/* 802C17C8 002BE708  2C 03 00 07 */	cmpwi r3, 7
/* 802C17CC 002BE70C  40 82 00 08 */	bne .L_802C17D4
.L_802C17D0:
/* 802C17D0 002BE710  3B E0 00 01 */	li r31, 1
.L_802C17D4:
/* 802C17D4 002BE714  57 E0 06 3F */	clrlwi. r0, r31, 0x18
/* 802C17D8 002BE718  40 82 00 20 */	bne .L_802C17F8
/* 802C17DC 002BE71C  3C 60 80 49 */	lis r3, lbl_8048B198@ha
/* 802C17E0 002BE720  3C A0 80 49 */	lis r5, lbl_8048B1B0@ha
/* 802C17E4 002BE724  38 63 B1 98 */	addi r3, r3, lbl_8048B198@l
/* 802C17E8 002BE728  38 80 04 54 */	li r4, 0x454
/* 802C17EC 002BE72C  38 A5 B1 B0 */	addi r5, r5, lbl_8048B1B0@l
/* 802C17F0 002BE730  4C C6 31 82 */	crclr 6
/* 802C17F4 002BE734  4B D6 8E 4D */	bl panic_f__12JUTExceptionFPCciPCce
.L_802C17F8:
/* 802C17F8 002BE738  7F C3 F3 78 */	mr r3, r30
/* 802C17FC 002BE73C  38 80 00 08 */	li r4, 8
/* 802C1800 002BE740  81 9E 00 28 */	lwz r12, 0x28(r30)
/* 802C1804 002BE744  81 8C 00 D4 */	lwz r12, 0xd4(r12)
/* 802C1808 002BE748  7D 89 03 A6 */	mtctr r12
/* 802C180C 002BE74C  4E 80 04 21 */	bctrl 
.L_802C1810:
/* 802C1810 002BE750  80 01 00 14 */	lwz r0, 0x14(r1)
/* 802C1814 002BE754  83 E1 00 0C */	lwz r31, 0xc(r1)
/* 802C1818 002BE758  83 C1 00 08 */	lwz r30, 8(r1)
/* 802C181C 002BE75C  7C 08 03 A6 */	mtlr r0
/* 802C1820 002BE760  38 21 00 10 */	addi r1, r1, 0x10
/* 802C1824 002BE764  4E 80 00 20 */	blr 

.global startBossFlickBGM__Q34Game6Houdai3ObjFv
startBossFlickBGM__Q34Game6Houdai3ObjFv:
/* 802C1828 002BE768  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 802C182C 002BE76C  7C 08 02 A6 */	mflr r0
/* 802C1830 002BE770  90 01 00 14 */	stw r0, 0x14(r1)
/* 802C1834 002BE774  93 E1 00 0C */	stw r31, 0xc(r1)
/* 802C1838 002BE778  3B E0 00 00 */	li r31, 0
/* 802C183C 002BE77C  93 C1 00 08 */	stw r30, 8(r1)
/* 802C1840 002BE780  83 C3 02 8C */	lwz r30, 0x28c(r3)
/* 802C1844 002BE784  81 9E 00 28 */	lwz r12, 0x28(r30)
/* 802C1848 002BE788  7F C3 F3 78 */	mr r3, r30
/* 802C184C 002BE78C  81 8C 00 1C */	lwz r12, 0x1c(r12)
/* 802C1850 002BE790  7D 89 03 A6 */	mtctr r12
/* 802C1854 002BE794  4E 80 04 21 */	bctrl 
/* 802C1858 002BE798  2C 03 00 05 */	cmpwi r3, 5
/* 802C185C 002BE79C  41 82 00 3C */	beq .L_802C1898
/* 802C1860 002BE7A0  7F C3 F3 78 */	mr r3, r30
/* 802C1864 002BE7A4  81 9E 00 28 */	lwz r12, 0x28(r30)
/* 802C1868 002BE7A8  81 8C 00 1C */	lwz r12, 0x1c(r12)
/* 802C186C 002BE7AC  7D 89 03 A6 */	mtctr r12
/* 802C1870 002BE7B0  4E 80 04 21 */	bctrl 
/* 802C1874 002BE7B4  2C 03 00 06 */	cmpwi r3, 6
/* 802C1878 002BE7B8  41 82 00 20 */	beq .L_802C1898
/* 802C187C 002BE7BC  7F C3 F3 78 */	mr r3, r30
/* 802C1880 002BE7C0  81 9E 00 28 */	lwz r12, 0x28(r30)
/* 802C1884 002BE7C4  81 8C 00 1C */	lwz r12, 0x1c(r12)
/* 802C1888 002BE7C8  7D 89 03 A6 */	mtctr r12
/* 802C188C 002BE7CC  4E 80 04 21 */	bctrl 
/* 802C1890 002BE7D0  2C 03 00 07 */	cmpwi r3, 7
/* 802C1894 002BE7D4  40 82 00 08 */	bne .L_802C189C
.L_802C1898:
/* 802C1898 002BE7D8  3B E0 00 01 */	li r31, 1
.L_802C189C:
/* 802C189C 002BE7DC  57 E0 06 3F */	clrlwi. r0, r31, 0x18
/* 802C18A0 002BE7E0  40 82 00 20 */	bne .L_802C18C0
/* 802C18A4 002BE7E4  3C 60 80 49 */	lis r3, lbl_8048B198@ha
/* 802C18A8 002BE7E8  3C A0 80 49 */	lis r5, lbl_8048B1B0@ha
/* 802C18AC 002BE7EC  38 63 B1 98 */	addi r3, r3, lbl_8048B198@l
/* 802C18B0 002BE7F0  38 80 04 54 */	li r4, 0x454
/* 802C18B4 002BE7F4  38 A5 B1 B0 */	addi r5, r5, lbl_8048B1B0@l
/* 802C18B8 002BE7F8  4C C6 31 82 */	crclr 6
/* 802C18BC 002BE7FC  4B D6 8D 85 */	bl panic_f__12JUTExceptionFPCciPCce
.L_802C18C0:
/* 802C18C0 002BE800  7F C3 F3 78 */	mr r3, r30
/* 802C18C4 002BE804  38 80 00 04 */	li r4, 4
/* 802C18C8 002BE808  81 9E 00 28 */	lwz r12, 0x28(r30)
/* 802C18CC 002BE80C  81 8C 00 D4 */	lwz r12, 0xd4(r12)
/* 802C18D0 002BE810  7D 89 03 A6 */	mtctr r12
/* 802C18D4 002BE814  4E 80 04 21 */	bctrl 
/* 802C18D8 002BE818  80 01 00 14 */	lwz r0, 0x14(r1)
/* 802C18DC 002BE81C  83 E1 00 0C */	lwz r31, 0xc(r1)
/* 802C18E0 002BE820  83 C1 00 08 */	lwz r30, 8(r1)
/* 802C18E4 002BE824  7C 08 03 A6 */	mtlr r0
/* 802C18E8 002BE828  38 21 00 10 */	addi r1, r1, 0x10
/* 802C18EC 002BE82C  4E 80 00 20 */	blr 

.global updateBossBGM__Q34Game6Houdai3ObjFv
updateBossBGM__Q34Game6Houdai3ObjFv:
/* 802C18F0 002BE830  94 21 FF E0 */	stwu r1, -0x20(r1)
/* 802C18F4 002BE834  7C 08 02 A6 */	mflr r0
/* 802C18F8 002BE838  90 01 00 24 */	stw r0, 0x24(r1)
/* 802C18FC 002BE83C  93 E1 00 1C */	stw r31, 0x1c(r1)
/* 802C1900 002BE840  3B E0 00 00 */	li r31, 0
/* 802C1904 002BE844  93 C1 00 18 */	stw r30, 0x18(r1)
/* 802C1908 002BE848  93 A1 00 14 */	stw r29, 0x14(r1)
/* 802C190C 002BE84C  7C 7D 1B 78 */	mr r29, r3
/* 802C1910 002BE850  83 C3 02 8C */	lwz r30, 0x28c(r3)
/* 802C1914 002BE854  81 9E 00 28 */	lwz r12, 0x28(r30)
/* 802C1918 002BE858  7F C3 F3 78 */	mr r3, r30
/* 802C191C 002BE85C  81 8C 00 1C */	lwz r12, 0x1c(r12)
/* 802C1920 002BE860  7D 89 03 A6 */	mtctr r12
/* 802C1924 002BE864  4E 80 04 21 */	bctrl 
/* 802C1928 002BE868  2C 03 00 05 */	cmpwi r3, 5
/* 802C192C 002BE86C  41 82 00 3C */	beq .L_802C1968
/* 802C1930 002BE870  7F C3 F3 78 */	mr r3, r30
/* 802C1934 002BE874  81 9E 00 28 */	lwz r12, 0x28(r30)
/* 802C1938 002BE878  81 8C 00 1C */	lwz r12, 0x1c(r12)
/* 802C193C 002BE87C  7D 89 03 A6 */	mtctr r12
/* 802C1940 002BE880  4E 80 04 21 */	bctrl 
/* 802C1944 002BE884  2C 03 00 06 */	cmpwi r3, 6
/* 802C1948 002BE888  41 82 00 20 */	beq .L_802C1968
/* 802C194C 002BE88C  7F C3 F3 78 */	mr r3, r30
/* 802C1950 002BE890  81 9E 00 28 */	lwz r12, 0x28(r30)
/* 802C1954 002BE894  81 8C 00 1C */	lwz r12, 0x1c(r12)
/* 802C1958 002BE898  7D 89 03 A6 */	mtctr r12
/* 802C195C 002BE89C  4E 80 04 21 */	bctrl 
/* 802C1960 002BE8A0  2C 03 00 07 */	cmpwi r3, 7
/* 802C1964 002BE8A4  40 82 00 08 */	bne .L_802C196C
.L_802C1968:
/* 802C1968 002BE8A8  3B E0 00 01 */	li r31, 1
.L_802C196C:
/* 802C196C 002BE8AC  57 E0 06 3F */	clrlwi. r0, r31, 0x18
/* 802C1970 002BE8B0  40 82 00 20 */	bne .L_802C1990
/* 802C1974 002BE8B4  3C 60 80 49 */	lis r3, lbl_8048B198@ha
/* 802C1978 002BE8B8  3C A0 80 49 */	lis r5, lbl_8048B1B0@ha
/* 802C197C 002BE8BC  38 63 B1 98 */	addi r3, r3, lbl_8048B198@l
/* 802C1980 002BE8C0  38 80 04 54 */	li r4, 0x454
/* 802C1984 002BE8C4  38 A5 B1 B0 */	addi r5, r5, lbl_8048B1B0@l
/* 802C1988 002BE8C8  4C C6 31 82 */	crclr 6
/* 802C198C 002BE8CC  4B D6 8C B5 */	bl panic_f__12JUTExceptionFPCciPCce
.L_802C1990:
/* 802C1990 002BE8D0  80 1D 01 F4 */	lwz r0, 0x1f4(r29)
/* 802C1994 002BE8D4  2C 00 00 00 */	cmpwi r0, 0
/* 802C1998 002BE8D8  41 82 00 20 */	beq .L_802C19B8
/* 802C199C 002BE8DC  7F C3 F3 78 */	mr r3, r30
/* 802C19A0 002BE8E0  38 80 00 01 */	li r4, 1
/* 802C19A4 002BE8E4  81 9E 00 28 */	lwz r12, 0x28(r30)
/* 802C19A8 002BE8E8  81 8C 00 D8 */	lwz r12, 0xd8(r12)
/* 802C19AC 002BE8EC  7D 89 03 A6 */	mtctr r12
/* 802C19B0 002BE8F0  4E 80 04 21 */	bctrl 
/* 802C19B4 002BE8F4  48 00 00 1C */	b .L_802C19D0
.L_802C19B8:
/* 802C19B8 002BE8F8  7F C3 F3 78 */	mr r3, r30
/* 802C19BC 002BE8FC  38 80 00 00 */	li r4, 0
/* 802C19C0 002BE900  81 9E 00 28 */	lwz r12, 0x28(r30)
/* 802C19C4 002BE904  81 8C 00 D8 */	lwz r12, 0xd8(r12)
/* 802C19C8 002BE908  7D 89 03 A6 */	mtctr r12
/* 802C19CC 002BE90C  4E 80 04 21 */	bctrl 
.L_802C19D0:
/* 802C19D0 002BE910  80 01 00 24 */	lwz r0, 0x24(r1)
/* 802C19D4 002BE914  83 E1 00 1C */	lwz r31, 0x1c(r1)
/* 802C19D8 002BE918  83 C1 00 18 */	lwz r30, 0x18(r1)
/* 802C19DC 002BE91C  83 A1 00 14 */	lwz r29, 0x14(r1)
/* 802C19E0 002BE920  7C 08 03 A6 */	mtlr r0
/* 802C19E4 002BE924  38 21 00 20 */	addi r1, r1, 0x20
/* 802C19E8 002BE928  4E 80 00 20 */	blr 

.global resetBossAppearBGM__Q34Game6Houdai3ObjFv
resetBossAppearBGM__Q34Game6Houdai3ObjFv:
/* 802C19EC 002BE92C  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 802C19F0 002BE930  7C 08 02 A6 */	mflr r0
/* 802C19F4 002BE934  90 01 00 14 */	stw r0, 0x14(r1)
/* 802C19F8 002BE938  93 E1 00 0C */	stw r31, 0xc(r1)
/* 802C19FC 002BE93C  3B E0 00 00 */	li r31, 0
/* 802C1A00 002BE940  93 C1 00 08 */	stw r30, 8(r1)
/* 802C1A04 002BE944  83 C3 02 8C */	lwz r30, 0x28c(r3)
/* 802C1A08 002BE948  81 9E 00 28 */	lwz r12, 0x28(r30)
/* 802C1A0C 002BE94C  7F C3 F3 78 */	mr r3, r30
/* 802C1A10 002BE950  81 8C 00 1C */	lwz r12, 0x1c(r12)
/* 802C1A14 002BE954  7D 89 03 A6 */	mtctr r12
/* 802C1A18 002BE958  4E 80 04 21 */	bctrl 
/* 802C1A1C 002BE95C  2C 03 00 05 */	cmpwi r3, 5
/* 802C1A20 002BE960  41 82 00 3C */	beq .L_802C1A5C
/* 802C1A24 002BE964  7F C3 F3 78 */	mr r3, r30
/* 802C1A28 002BE968  81 9E 00 28 */	lwz r12, 0x28(r30)
/* 802C1A2C 002BE96C  81 8C 00 1C */	lwz r12, 0x1c(r12)
/* 802C1A30 002BE970  7D 89 03 A6 */	mtctr r12
/* 802C1A34 002BE974  4E 80 04 21 */	bctrl 
/* 802C1A38 002BE978  2C 03 00 06 */	cmpwi r3, 6
/* 802C1A3C 002BE97C  41 82 00 20 */	beq .L_802C1A5C
/* 802C1A40 002BE980  7F C3 F3 78 */	mr r3, r30
/* 802C1A44 002BE984  81 9E 00 28 */	lwz r12, 0x28(r30)
/* 802C1A48 002BE988  81 8C 00 1C */	lwz r12, 0x1c(r12)
/* 802C1A4C 002BE98C  7D 89 03 A6 */	mtctr r12
/* 802C1A50 002BE990  4E 80 04 21 */	bctrl 
/* 802C1A54 002BE994  2C 03 00 07 */	cmpwi r3, 7
/* 802C1A58 002BE998  40 82 00 08 */	bne .L_802C1A60
.L_802C1A5C:
/* 802C1A5C 002BE99C  3B E0 00 01 */	li r31, 1
.L_802C1A60:
/* 802C1A60 002BE9A0  57 E0 06 3F */	clrlwi. r0, r31, 0x18
/* 802C1A64 002BE9A4  40 82 00 20 */	bne .L_802C1A84
/* 802C1A68 002BE9A8  3C 60 80 49 */	lis r3, lbl_8048B198@ha
/* 802C1A6C 002BE9AC  3C A0 80 49 */	lis r5, lbl_8048B1B0@ha
/* 802C1A70 002BE9B0  38 63 B1 98 */	addi r3, r3, lbl_8048B198@l
/* 802C1A74 002BE9B4  38 80 04 54 */	li r4, 0x454
/* 802C1A78 002BE9B8  38 A5 B1 B0 */	addi r5, r5, lbl_8048B1B0@l
/* 802C1A7C 002BE9BC  4C C6 31 82 */	crclr 6
/* 802C1A80 002BE9C0  4B D6 8B C1 */	bl panic_f__12JUTExceptionFPCciPCce
.L_802C1A84:
/* 802C1A84 002BE9C4  7F C3 F3 78 */	mr r3, r30
/* 802C1A88 002BE9C8  38 80 00 00 */	li r4, 0
/* 802C1A8C 002BE9CC  48 19 DF 65 */	bl setAppearFlag__Q23PSM9EnemyBossFb
/* 802C1A90 002BE9D0  80 01 00 14 */	lwz r0, 0x14(r1)
/* 802C1A94 002BE9D4  83 E1 00 0C */	lwz r31, 0xc(r1)
/* 802C1A98 002BE9D8  83 C1 00 08 */	lwz r30, 8(r1)
/* 802C1A9C 002BE9DC  7C 08 03 A6 */	mtlr r0
/* 802C1AA0 002BE9E0  38 21 00 10 */	addi r1, r1, 0x10
/* 802C1AA4 002BE9E4  4E 80 00 20 */	blr 

.global setBossAppearBGM__Q34Game6Houdai3ObjFv
setBossAppearBGM__Q34Game6Houdai3ObjFv:
/* 802C1AA8 002BE9E8  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 802C1AAC 002BE9EC  7C 08 02 A6 */	mflr r0
/* 802C1AB0 002BE9F0  90 01 00 14 */	stw r0, 0x14(r1)
/* 802C1AB4 002BE9F4  93 E1 00 0C */	stw r31, 0xc(r1)
/* 802C1AB8 002BE9F8  3B E0 00 00 */	li r31, 0
/* 802C1ABC 002BE9FC  93 C1 00 08 */	stw r30, 8(r1)
/* 802C1AC0 002BEA00  83 C3 02 8C */	lwz r30, 0x28c(r3)
/* 802C1AC4 002BEA04  81 9E 00 28 */	lwz r12, 0x28(r30)
/* 802C1AC8 002BEA08  7F C3 F3 78 */	mr r3, r30
/* 802C1ACC 002BEA0C  81 8C 00 1C */	lwz r12, 0x1c(r12)
/* 802C1AD0 002BEA10  7D 89 03 A6 */	mtctr r12
/* 802C1AD4 002BEA14  4E 80 04 21 */	bctrl 
/* 802C1AD8 002BEA18  2C 03 00 05 */	cmpwi r3, 5
/* 802C1ADC 002BEA1C  41 82 00 3C */	beq .L_802C1B18
/* 802C1AE0 002BEA20  7F C3 F3 78 */	mr r3, r30
/* 802C1AE4 002BEA24  81 9E 00 28 */	lwz r12, 0x28(r30)
/* 802C1AE8 002BEA28  81 8C 00 1C */	lwz r12, 0x1c(r12)
/* 802C1AEC 002BEA2C  7D 89 03 A6 */	mtctr r12
/* 802C1AF0 002BEA30  4E 80 04 21 */	bctrl 
/* 802C1AF4 002BEA34  2C 03 00 06 */	cmpwi r3, 6
/* 802C1AF8 002BEA38  41 82 00 20 */	beq .L_802C1B18
/* 802C1AFC 002BEA3C  7F C3 F3 78 */	mr r3, r30
/* 802C1B00 002BEA40  81 9E 00 28 */	lwz r12, 0x28(r30)
/* 802C1B04 002BEA44  81 8C 00 1C */	lwz r12, 0x1c(r12)
/* 802C1B08 002BEA48  7D 89 03 A6 */	mtctr r12
/* 802C1B0C 002BEA4C  4E 80 04 21 */	bctrl 
/* 802C1B10 002BEA50  2C 03 00 07 */	cmpwi r3, 7
/* 802C1B14 002BEA54  40 82 00 08 */	bne .L_802C1B1C
.L_802C1B18:
/* 802C1B18 002BEA58  3B E0 00 01 */	li r31, 1
.L_802C1B1C:
/* 802C1B1C 002BEA5C  57 E0 06 3F */	clrlwi. r0, r31, 0x18
/* 802C1B20 002BEA60  40 82 00 20 */	bne .L_802C1B40
/* 802C1B24 002BEA64  3C 60 80 49 */	lis r3, lbl_8048B198@ha
/* 802C1B28 002BEA68  3C A0 80 49 */	lis r5, lbl_8048B1B0@ha
/* 802C1B2C 002BEA6C  38 63 B1 98 */	addi r3, r3, lbl_8048B198@l
/* 802C1B30 002BEA70  38 80 04 54 */	li r4, 0x454
/* 802C1B34 002BEA74  38 A5 B1 B0 */	addi r5, r5, lbl_8048B1B0@l
/* 802C1B38 002BEA78  4C C6 31 82 */	crclr 6
/* 802C1B3C 002BEA7C  4B D6 8B 05 */	bl panic_f__12JUTExceptionFPCciPCce
.L_802C1B40:
/* 802C1B40 002BEA80  7F C3 F3 78 */	mr r3, r30
/* 802C1B44 002BEA84  38 80 00 01 */	li r4, 1
/* 802C1B48 002BEA88  48 19 DE A9 */	bl setAppearFlag__Q23PSM9EnemyBossFb
/* 802C1B4C 002BEA8C  80 01 00 14 */	lwz r0, 0x14(r1)
/* 802C1B50 002BEA90  83 E1 00 0C */	lwz r31, 0xc(r1)
/* 802C1B54 002BEA94  83 C1 00 08 */	lwz r30, 8(r1)
/* 802C1B58 002BEA98  7C 08 03 A6 */	mtlr r0
/* 802C1B5C 002BEA9C  38 21 00 10 */	addi r1, r1, 0x10
/* 802C1B60 002BEAA0  4E 80 00 20 */	blr 

.global createAppearHahenEffect__Q34Game6Houdai3ObjFv
createAppearHahenEffect__Q34Game6Houdai3ObjFv:
/* 802C2C1C 002BFB5C  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 802C2C20 002BFB60  7C 08 02 A6 */	mflr r0
/* 802C2C24 002BFB64  38 80 00 00 */	li r4, 0
/* 802C2C28 002BFB68  90 01 00 14 */	stw r0, 0x14(r1)
/* 802C2C2C 002BFB6C  80 63 03 E4 */	lwz r3, 0x3e4(r3)
/* 802C2C30 002BFB70  81 83 00 00 */	lwz r12, 0(r3)
/* 802C2C34 002BFB74  81 8C 00 08 */	lwz r12, 8(r12)
/* 802C2C38 002BFB78  7D 89 03 A6 */	mtctr r12
/* 802C2C3C 002BFB7C  4E 80 04 21 */	bctrl 
/* 802C2C40 002BFB80  80 01 00 14 */	lwz r0, 0x14(r1)
/* 802C2C44 002BFB84  7C 08 03 A6 */	mtlr r0
/* 802C2C48 002BFB88  38 21 00 10 */	addi r1, r1, 0x10
/* 802C2C4C 002BFB8C  4E 80 00 20 */	blr 

.global createAppearFootEffect__Q34Game6Houdai3ObjFi
createAppearFootEffect__Q34Game6Houdai3ObjFi:
/* 802C2C50 002BFB90  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 802C2C54 002BFB94  7C 08 02 A6 */	mflr r0
/* 802C2C58 002BFB98  90 01 00 14 */	stw r0, 0x14(r1)
/* 802C2C5C 002BFB9C  54 80 10 3A */	slwi r0, r4, 2
/* 802C2C60 002BFBA0  7C 63 02 14 */	add r3, r3, r0
/* 802C2C64 002BFBA4  38 80 00 00 */	li r4, 0
/* 802C2C68 002BFBA8  80 63 03 E8 */	lwz r3, 0x3e8(r3)
/* 802C2C6C 002BFBAC  81 83 00 00 */	lwz r12, 0(r3)
/* 802C2C70 002BFBB0  81 8C 00 08 */	lwz r12, 8(r12)
/* 802C2C74 002BFBB4  7D 89 03 A6 */	mtctr r12
/* 802C2C78 002BFBB8  4E 80 04 21 */	bctrl 
/* 802C2C7C 002BFBBC  80 01 00 14 */	lwz r0, 0x14(r1)
/* 802C2C80 002BFBC0  7C 08 03 A6 */	mtlr r0
/* 802C2C84 002BFBC4  38 21 00 10 */	addi r1, r1, 0x10
/* 802C2C88 002BFBC8  4E 80 00 20 */	blr 

.global createShotGunOpenEffect__Q34Game6Houdai3ObjFv
createShotGunOpenEffect__Q34Game6Houdai3ObjFv:
/* 802C2E28 002BFD68  94 21 FF D0 */	stwu r1, -0x30(r1)
/* 802C2E2C 002BFD6C  7C 08 02 A6 */	mflr r0
/* 802C2E30 002BFD70  38 82 E1 B0 */	addi r4, r2, lbl_8051C510@sda21
/* 802C2E34 002BFD74  90 01 00 34 */	stw r0, 0x34(r1)
/* 802C2E38 002BFD78  80 63 01 74 */	lwz r3, 0x174(r3)
/* 802C2E3C 002BFD7C  48 17 C1 A9 */	bl getJoint__Q28SysShape5ModelFPc
/* 802C2E40 002BFD80  48 16 6A 61 */	bl getWorldMatrix__Q28SysShape5JointFv
/* 802C2E44 002BFD84  3C 80 80 4B */	lis r4, __vt__Q23efx5TBase@ha
/* 802C2E48 002BFD88  C0 43 00 2C */	lfs f2, 0x2c(r3)
/* 802C2E4C 002BFD8C  C0 23 00 1C */	lfs f1, 0x1c(r3)
/* 802C2E50 002BFD90  38 84 A7 F8 */	addi r4, r4, __vt__Q23efx5TBase@l
/* 802C2E54 002BFD94  C0 03 00 0C */	lfs f0, 0xc(r3)
/* 802C2E58 002BFD98  3C 60 80 4E */	lis r3, __vt__Q23efx8TSimple1@ha
/* 802C2E5C 002BFD9C  38 03 6A 78 */	addi r0, r3, __vt__Q23efx8TSimple1@l
/* 802C2E60 002BFDA0  3C A0 80 4B */	lis r5, __vt__Q23efx3Arg@ha
/* 802C2E64 002BFDA4  90 81 00 08 */	stw r4, 8(r1)
/* 802C2E68 002BFDA8  3C 60 80 4D */	lis r3, __vt__Q23efx10THdamaOpen@ha
/* 802C2E6C 002BFDAC  38 85 A7 EC */	addi r4, r5, __vt__Q23efx3Arg@l
/* 802C2E70 002BFDB0  38 C0 02 0A */	li r6, 0x20a
/* 802C2E74 002BFDB4  38 A0 00 00 */	li r5, 0
/* 802C2E78 002BFDB8  90 01 00 08 */	stw r0, 8(r1)
/* 802C2E7C 002BFDBC  38 03 0E B0 */	addi r0, r3, __vt__Q23efx10THdamaOpen@l
/* 802C2E80 002BFDC0  38 61 00 08 */	addi r3, r1, 8
/* 802C2E84 002BFDC4  90 81 00 14 */	stw r4, 0x14(r1)
/* 802C2E88 002BFDC8  38 81 00 14 */	addi r4, r1, 0x14
/* 802C2E8C 002BFDCC  D0 01 00 18 */	stfs f0, 0x18(r1)
/* 802C2E90 002BFDD0  D0 21 00 1C */	stfs f1, 0x1c(r1)
/* 802C2E94 002BFDD4  D0 41 00 20 */	stfs f2, 0x20(r1)
/* 802C2E98 002BFDD8  B0 C1 00 0C */	sth r6, 0xc(r1)
/* 802C2E9C 002BFDDC  90 A1 00 10 */	stw r5, 0x10(r1)
/* 802C2EA0 002BFDE0  90 01 00 08 */	stw r0, 8(r1)
/* 802C2EA4 002BFDE4  48 0E C0 E1 */	bl create__Q23efx8TSimple1FPQ23efx3Arg
/* 802C2EA8 002BFDE8  80 01 00 34 */	lwz r0, 0x34(r1)
/* 802C2EAC 002BFDEC  7C 08 03 A6 */	mtlr r0
/* 802C2EB0 002BFDF0  38 21 00 30 */	addi r1, r1, 0x30
/* 802C2EB4 002BFDF4  4E 80 00 20 */	blr 

.global createDeadBombEffect__Q34Game6Houdai3ObjFv
createDeadBombEffect__Q34Game6Houdai3ObjFv:
/* 802C2EB8 002BFDF8  94 21 FF 20 */	stwu r1, -0xe0(r1)
/* 802C2EBC 002BFDFC  7C 08 02 A6 */	mflr r0
/* 802C2EC0 002BFE00  38 80 00 00 */	li r4, 0
/* 802C2EC4 002BFE04  90 01 00 E4 */	stw r0, 0xe4(r1)
/* 802C2EC8 002BFE08  BE A1 00 B4 */	stmw r21, 0xb4(r1)
/* 802C2ECC 002BFE0C  7C 75 1B 78 */	mr r21, r3
/* 802C2ED0 002BFE10  80 63 04 18 */	lwz r3, 0x418(r3)
/* 802C2ED4 002BFE14  81 83 00 00 */	lwz r12, 0(r3)
/* 802C2ED8 002BFE18  81 8C 00 08 */	lwz r12, 8(r12)
/* 802C2EDC 002BFE1C  7D 89 03 A6 */	mtctr r12
/* 802C2EE0 002BFE20  4E 80 04 21 */	bctrl 
/* 802C2EE4 002BFE24  3C 60 80 51 */	lis r3, "zero__10Vector3<f>"@ha
/* 802C2EE8 002BFE28  7E BB AB 78 */	mr r27, r21
/* 802C2EEC 002BFE2C  3B A3 41 E4 */	addi r29, r3, "zero__10Vector3<f>"@l
/* 802C2EF0 002BFE30  3B 40 00 00 */	li r26, 0
.L_802C2EF4:
/* 802C2EF4 002BFE34  2C 1A 00 00 */	cmpwi r26, 0
/* 802C2EF8 002BFE38  40 82 01 04 */	bne .L_802C2FFC
/* 802C2EFC 002BFE3C  3D 00 80 4B */	lis r8, __vt__Q23efx3Arg@ha
/* 802C2F00 002BFE40  3C E0 80 51 */	lis r7, "zero__10Vector3<f>"@ha
/* 802C2F04 002BFE44  3C C0 80 4D */	lis r6, __vt__Q23efx9ArgPosPos@ha
/* 802C2F08 002BFE48  3C A0 80 4B */	lis r5, __vt__Q23efx5TBase@ha
/* 802C2F0C 002BFE4C  3C 80 80 4E */	lis r4, __vt__Q23efx8TSimple2@ha
/* 802C2F10 002BFE50  3C 60 80 4F */	lis r3, __vt__Q23efx16THdamaDeadHahen2@ha
/* 802C2F14 002BFE54  7F 7C DB 78 */	mr r28, r27
/* 802C2F18 002BFE58  3B C8 A7 EC */	addi r30, r8, __vt__Q23efx3Arg@l
/* 802C2F1C 002BFE5C  3B E7 41 E4 */	addi r31, r7, "zero__10Vector3<f>"@l
/* 802C2F20 002BFE60  3B 06 0E A4 */	addi r24, r6, __vt__Q23efx9ArgPosPos@l
/* 802C2F24 002BFE64  3A E5 A7 F8 */	addi r23, r5, __vt__Q23efx5TBase@l
/* 802C2F28 002BFE68  3A C4 6A 64 */	addi r22, r4, __vt__Q23efx8TSimple2@l
/* 802C2F2C 002BFE6C  3A A3 9F B8 */	addi r21, r3, __vt__Q23efx16THdamaDeadHahen2@l
/* 802C2F30 002BFE70  3B 20 00 00 */	li r25, 0
.L_802C2F34:
/* 802C2F34 002BFE74  81 9C 03 10 */	lwz r12, 0x310(r28)
/* 802C2F38 002BFE78  38 C0 01 FE */	li r6, 0x1fe
/* 802C2F3C 002BFE7C  81 7C 03 14 */	lwz r11, 0x314(r28)
/* 802C2F40 002BFE80  38 A0 01 FF */	li r5, 0x1ff
/* 802C2F44 002BFE84  81 5C 03 18 */	lwz r10, 0x318(r28)
/* 802C2F48 002BFE88  38 00 00 00 */	li r0, 0
/* 802C2F4C 002BFE8C  81 3C 03 04 */	lwz r9, 0x304(r28)
/* 802C2F50 002BFE90  38 61 00 44 */	addi r3, r1, 0x44
/* 802C2F54 002BFE94  81 1C 03 08 */	lwz r8, 0x308(r28)
/* 802C2F58 002BFE98  38 81 00 7C */	addi r4, r1, 0x7c
/* 802C2F5C 002BFE9C  80 FC 03 0C */	lwz r7, 0x30c(r28)
/* 802C2F60 002BFEA0  91 81 00 20 */	stw r12, 0x20(r1)
/* 802C2F64 002BFEA4  C1 1F 00 00 */	lfs f8, 0(r31)
/* 802C2F68 002BFEA8  91 61 00 24 */	stw r11, 0x24(r1)
/* 802C2F6C 002BFEAC  C0 FD 00 04 */	lfs f7, 4(r29)
/* 802C2F70 002BFEB0  91 41 00 28 */	stw r10, 0x28(r1)
/* 802C2F74 002BFEB4  C0 DD 00 08 */	lfs f6, 8(r29)
/* 802C2F78 002BFEB8  91 21 00 2C */	stw r9, 0x2c(r1)
/* 802C2F7C 002BFEBC  C0 41 00 20 */	lfs f2, 0x20(r1)
/* 802C2F80 002BFEC0  91 01 00 30 */	stw r8, 0x30(r1)
/* 802C2F84 002BFEC4  C0 A1 00 2C */	lfs f5, 0x2c(r1)
/* 802C2F88 002BFEC8  90 E1 00 34 */	stw r7, 0x34(r1)
/* 802C2F8C 002BFECC  C0 81 00 30 */	lfs f4, 0x30(r1)
/* 802C2F90 002BFED0  92 E1 00 44 */	stw r23, 0x44(r1)
/* 802C2F94 002BFED4  C0 61 00 34 */	lfs f3, 0x34(r1)
/* 802C2F98 002BFED8  93 C1 00 7C */	stw r30, 0x7c(r1)
/* 802C2F9C 002BFEDC  C0 21 00 24 */	lfs f1, 0x24(r1)
/* 802C2FA0 002BFEE0  92 C1 00 44 */	stw r22, 0x44(r1)
/* 802C2FA4 002BFEE4  C0 01 00 28 */	lfs f0, 0x28(r1)
/* 802C2FA8 002BFEE8  D1 01 00 80 */	stfs f8, 0x80(r1)
/* 802C2FAC 002BFEEC  D0 E1 00 84 */	stfs f7, 0x84(r1)
/* 802C2FB0 002BFEF0  D0 C1 00 88 */	stfs f6, 0x88(r1)
/* 802C2FB4 002BFEF4  93 01 00 7C */	stw r24, 0x7c(r1)
/* 802C2FB8 002BFEF8  D0 A1 00 8C */	stfs f5, 0x8c(r1)
/* 802C2FBC 002BFEFC  D0 81 00 90 */	stfs f4, 0x90(r1)
/* 802C2FC0 002BFF00  D0 61 00 94 */	stfs f3, 0x94(r1)
/* 802C2FC4 002BFF04  D0 41 00 98 */	stfs f2, 0x98(r1)
/* 802C2FC8 002BFF08  D0 21 00 9C */	stfs f1, 0x9c(r1)
/* 802C2FCC 002BFF0C  D0 01 00 A0 */	stfs f0, 0xa0(r1)
/* 802C2FD0 002BFF10  B0 C1 00 48 */	sth r6, 0x48(r1)
/* 802C2FD4 002BFF14  B0 A1 00 4A */	sth r5, 0x4a(r1)
/* 802C2FD8 002BFF18  90 01 00 4C */	stw r0, 0x4c(r1)
/* 802C2FDC 002BFF1C  90 01 00 50 */	stw r0, 0x50(r1)
/* 802C2FE0 002BFF20  92 A1 00 44 */	stw r21, 0x44(r1)
/* 802C2FE4 002BFF24  48 12 98 F5 */	bl create__Q23efx16THdamaDeadHahen2FPQ23efx3Arg
/* 802C2FE8 002BFF28  3B 39 00 01 */	addi r25, r25, 1
/* 802C2FEC 002BFF2C  3B 9C 00 0C */	addi r28, r28, 0xc
/* 802C2FF0 002BFF30  2C 19 00 03 */	cmpwi r25, 3
/* 802C2FF4 002BFF34  41 80 FF 40 */	blt .L_802C2F34
/* 802C2FF8 002BFF38  48 00 00 F4 */	b .L_802C30EC
.L_802C2FFC:
/* 802C2FFC 002BFF3C  3D 00 80 4B */	lis r8, __vt__Q23efx3Arg@ha
/* 802C3000 002BFF40  3C E0 80 51 */	lis r7, "zero__10Vector3<f>"@ha
/* 802C3004 002BFF44  3C C0 80 4D */	lis r6, __vt__Q23efx9ArgPosPos@ha
/* 802C3008 002BFF48  3C A0 80 4B */	lis r5, __vt__Q23efx5TBase@ha
/* 802C300C 002BFF4C  3C 80 80 4E */	lis r4, __vt__Q23efx8TSimple1@ha
/* 802C3010 002BFF50  3C 60 80 4F */	lis r3, __vt__Q23efx16THdamaDeadHahen1@ha
/* 802C3014 002BFF54  7F 7C DB 78 */	mr r28, r27
/* 802C3018 002BFF58  3B E8 A7 EC */	addi r31, r8, __vt__Q23efx3Arg@l
/* 802C301C 002BFF5C  3A A7 41 E4 */	addi r21, r7, "zero__10Vector3<f>"@l
/* 802C3020 002BFF60  3A C6 0E A4 */	addi r22, r6, __vt__Q23efx9ArgPosPos@l
/* 802C3024 002BFF64  3A E5 A7 F8 */	addi r23, r5, __vt__Q23efx5TBase@l
/* 802C3028 002BFF68  3B 04 6A 78 */	addi r24, r4, __vt__Q23efx8TSimple1@l
/* 802C302C 002BFF6C  3B C3 9F CC */	addi r30, r3, __vt__Q23efx16THdamaDeadHahen1@l
/* 802C3030 002BFF70  3B 20 00 00 */	li r25, 0
.L_802C3034:
/* 802C3034 002BFF74  81 7C 03 10 */	lwz r11, 0x310(r28)
/* 802C3038 002BFF78  38 A0 01 FD */	li r5, 0x1fd
/* 802C303C 002BFF7C  81 5C 03 14 */	lwz r10, 0x314(r28)
/* 802C3040 002BFF80  38 00 00 00 */	li r0, 0
/* 802C3044 002BFF84  81 3C 03 18 */	lwz r9, 0x318(r28)
/* 802C3048 002BFF88  38 61 00 38 */	addi r3, r1, 0x38
/* 802C304C 002BFF8C  81 1C 03 04 */	lwz r8, 0x304(r28)
/* 802C3050 002BFF90  38 81 00 54 */	addi r4, r1, 0x54
/* 802C3054 002BFF94  80 FC 03 08 */	lwz r7, 0x308(r28)
/* 802C3058 002BFF98  80 DC 03 0C */	lwz r6, 0x30c(r28)
/* 802C305C 002BFF9C  91 61 00 08 */	stw r11, 8(r1)
/* 802C3060 002BFFA0  C1 15 00 00 */	lfs f8, 0(r21)
/* 802C3064 002BFFA4  91 41 00 0C */	stw r10, 0xc(r1)
/* 802C3068 002BFFA8  C0 FD 00 04 */	lfs f7, 4(r29)
/* 802C306C 002BFFAC  91 21 00 10 */	stw r9, 0x10(r1)
/* 802C3070 002BFFB0  C0 DD 00 08 */	lfs f6, 8(r29)
/* 802C3074 002BFFB4  91 01 00 14 */	stw r8, 0x14(r1)
/* 802C3078 002BFFB8  C0 41 00 08 */	lfs f2, 8(r1)
/* 802C307C 002BFFBC  90 E1 00 18 */	stw r7, 0x18(r1)
/* 802C3080 002BFFC0  C0 A1 00 14 */	lfs f5, 0x14(r1)
/* 802C3084 002BFFC4  90 C1 00 1C */	stw r6, 0x1c(r1)
/* 802C3088 002BFFC8  C0 81 00 18 */	lfs f4, 0x18(r1)
/* 802C308C 002BFFCC  92 E1 00 38 */	stw r23, 0x38(r1)
/* 802C3090 002BFFD0  C0 61 00 1C */	lfs f3, 0x1c(r1)
/* 802C3094 002BFFD4  93 E1 00 54 */	stw r31, 0x54(r1)
/* 802C3098 002BFFD8  C0 21 00 0C */	lfs f1, 0xc(r1)
/* 802C309C 002BFFDC  93 01 00 38 */	stw r24, 0x38(r1)
/* 802C30A0 002BFFE0  C0 01 00 10 */	lfs f0, 0x10(r1)
/* 802C30A4 002BFFE4  D1 01 00 58 */	stfs f8, 0x58(r1)
/* 802C30A8 002BFFE8  D0 E1 00 5C */	stfs f7, 0x5c(r1)
/* 802C30AC 002BFFEC  D0 C1 00 60 */	stfs f6, 0x60(r1)
/* 802C30B0 002BFFF0  92 C1 00 54 */	stw r22, 0x54(r1)
/* 802C30B4 002BFFF4  D0 A1 00 64 */	stfs f5, 0x64(r1)
/* 802C30B8 002BFFF8  D0 81 00 68 */	stfs f4, 0x68(r1)
/* 802C30BC 002BFFFC  D0 61 00 6C */	stfs f3, 0x6c(r1)
/* 802C30C0 002C0000  D0 41 00 70 */	stfs f2, 0x70(r1)
/* 802C30C4 002C0004  D0 21 00 74 */	stfs f1, 0x74(r1)
/* 802C30C8 002C0008  D0 01 00 78 */	stfs f0, 0x78(r1)
/* 802C30CC 002C000C  B0 A1 00 3C */	sth r5, 0x3c(r1)
/* 802C30D0 002C0010  90 01 00 40 */	stw r0, 0x40(r1)
/* 802C30D4 002C0014  93 C1 00 38 */	stw r30, 0x38(r1)
/* 802C30D8 002C0018  48 12 96 8D */	bl create__Q23efx16THdamaDeadHahen1FPQ23efx3Arg
/* 802C30DC 002C001C  3B 39 00 01 */	addi r25, r25, 1
/* 802C30E0 002C0020  3B 9C 00 0C */	addi r28, r28, 0xc
/* 802C30E4 002C0024  2C 19 00 03 */	cmpwi r25, 3
/* 802C30E8 002C0028  41 80 FF 4C */	blt .L_802C3034
.L_802C30EC:
/* 802C30EC 002C002C  3B 5A 00 01 */	addi r26, r26, 1
/* 802C30F0 002C0030  3B 7B 00 30 */	addi r27, r27, 0x30
/* 802C30F4 002C0034  2C 1A 00 04 */	cmpwi r26, 4
/* 802C30F8 002C0038  41 80 FD FC */	blt .L_802C2EF4
/* 802C30FC 002C003C  BA A1 00 B4 */	lmw r21, 0xb4(r1)
/* 802C3100 002C0040  80 01 00 E4 */	lwz r0, 0xe4(r1)
/* 802C3104 002C0044  7C 08 03 A6 */	mtlr r0
/* 802C3108 002C0048  38 21 00 E0 */	addi r1, r1, 0xe0
/* 802C310C 002C004C  4E 80 00 20 */	blr 

.global getName__Q23efx9ArgPosPosFv
getName__Q23efx9ArgPosPosFv:
/* 802C3408 002C0348  3C 60 80 49 */	lis r3, lbl_8048B1EC@ha
/* 802C340C 002C034C  38 63 B1 EC */	addi r3, r3, lbl_8048B1EC@l
/* 802C3410 002C0350  4E 80 00 20 */	blr 

.global __dt__Q23efx13THdamaSteamBdFv
__dt__Q23efx13THdamaSteamBdFv:
/* 802C3414 002C0354  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 802C3418 002C0358  7C 08 02 A6 */	mflr r0
/* 802C341C 002C035C  90 01 00 14 */	stw r0, 0x14(r1)
/* 802C3420 002C0360  93 E1 00 0C */	stw r31, 0xc(r1)
/* 802C3424 002C0364  7C 9F 23 78 */	mr r31, r4
/* 802C3428 002C0368  93 C1 00 08 */	stw r30, 8(r1)
/* 802C342C 002C036C  7C 7E 1B 79 */	or. r30, r3, r3
/* 802C3430 002C0370  41 82 00 64 */	beq .L_802C3494
/* 802C3434 002C0374  3C 60 80 4D */	lis r3, __vt__Q23efx13THdamaSteamBd@ha
/* 802C3438 002C0378  38 63 0F 4C */	addi r3, r3, __vt__Q23efx13THdamaSteamBd@l
/* 802C343C 002C037C  90 7E 00 00 */	stw r3, 0(r30)
/* 802C3440 002C0380  38 03 00 14 */	addi r0, r3, 0x14
/* 802C3444 002C0384  90 1E 00 04 */	stw r0, 4(r30)
/* 802C3448 002C0388  41 82 00 3C */	beq .L_802C3484
/* 802C344C 002C038C  3C 60 80 4E */	lis r3, __vt__Q23efx10TChaseMtxT@ha
/* 802C3450 002C0390  38 63 68 5C */	addi r3, r3, __vt__Q23efx10TChaseMtxT@l
/* 802C3454 002C0394  90 7E 00 00 */	stw r3, 0(r30)
/* 802C3458 002C0398  38 03 00 14 */	addi r0, r3, 0x14
/* 802C345C 002C039C  90 1E 00 04 */	stw r0, 4(r30)
/* 802C3460 002C03A0  41 82 00 24 */	beq .L_802C3484
/* 802C3464 002C03A4  3C 80 80 4E */	lis r4, __vt__Q23efx5TSync@ha
/* 802C3468 002C03A8  38 7E 00 04 */	addi r3, r30, 4
/* 802C346C 002C03AC  38 A4 69 8C */	addi r5, r4, __vt__Q23efx5TSync@l
/* 802C3470 002C03B0  38 80 00 00 */	li r4, 0
/* 802C3474 002C03B4  90 BE 00 00 */	stw r5, 0(r30)
/* 802C3478 002C03B8  38 05 00 14 */	addi r0, r5, 0x14
/* 802C347C 002C03BC  90 1E 00 04 */	stw r0, 4(r30)
/* 802C3480 002C03C0  4B DC C8 1D */	bl __dt__18JPAEmitterCallBackFv
.L_802C3484:
/* 802C3484 002C03C4  7F E0 07 35 */	extsh. r0, r31
/* 802C3488 002C03C8  40 81 00 0C */	ble .L_802C3494
/* 802C348C 002C03CC  7F C3 F3 78 */	mr r3, r30
/* 802C3490 002C03D0  4B D6 0C 25 */	bl __dl__FPv
.L_802C3494:
/* 802C3494 002C03D4  80 01 00 14 */	lwz r0, 0x14(r1)
/* 802C3498 002C03D8  7F C3 F3 78 */	mr r3, r30
/* 802C349C 002C03DC  83 E1 00 0C */	lwz r31, 0xc(r1)
/* 802C34A0 002C03E0  83 C1 00 08 */	lwz r30, 8(r1)
/* 802C34A4 002C03E4  7C 08 03 A6 */	mtlr r0
/* 802C34A8 002C03E8  38 21 00 10 */	addi r1, r1, 0x10
/* 802C34AC 002C03EC  4E 80 00 20 */	blr 

.global __dt__Q23efx14THdamaOnSteam1Fv
__dt__Q23efx14THdamaOnSteam1Fv:
/* 802C34B0 002C03F0  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 802C34B4 002C03F4  7C 08 02 A6 */	mflr r0
/* 802C34B8 002C03F8  90 01 00 14 */	stw r0, 0x14(r1)
/* 802C34BC 002C03FC  93 E1 00 0C */	stw r31, 0xc(r1)
/* 802C34C0 002C0400  7C 9F 23 78 */	mr r31, r4
/* 802C34C4 002C0404  93 C1 00 08 */	stw r30, 8(r1)
/* 802C34C8 002C0408  7C 7E 1B 79 */	or. r30, r3, r3
/* 802C34CC 002C040C  41 82 00 64 */	beq .L_802C3530
/* 802C34D0 002C0410  3C 60 80 4D */	lis r3, __vt__Q23efx14THdamaOnSteam1@ha
/* 802C34D4 002C0414  38 63 0F 98 */	addi r3, r3, __vt__Q23efx14THdamaOnSteam1@l
/* 802C34D8 002C0418  90 7E 00 00 */	stw r3, 0(r30)
/* 802C34DC 002C041C  38 03 00 14 */	addi r0, r3, 0x14
/* 802C34E0 002C0420  90 1E 00 04 */	stw r0, 4(r30)
/* 802C34E4 002C0424  41 82 00 3C */	beq .L_802C3520
/* 802C34E8 002C0428  3C 60 80 4E */	lis r3, __vt__Q23efx10TChaseMtxT@ha
/* 802C34EC 002C042C  38 63 68 5C */	addi r3, r3, __vt__Q23efx10TChaseMtxT@l
/* 802C34F0 002C0430  90 7E 00 00 */	stw r3, 0(r30)
/* 802C34F4 002C0434  38 03 00 14 */	addi r0, r3, 0x14
/* 802C34F8 002C0438  90 1E 00 04 */	stw r0, 4(r30)
/* 802C34FC 002C043C  41 82 00 24 */	beq .L_802C3520
/* 802C3500 002C0440  3C 80 80 4E */	lis r4, __vt__Q23efx5TSync@ha
/* 802C3504 002C0444  38 7E 00 04 */	addi r3, r30, 4
/* 802C3508 002C0448  38 A4 69 8C */	addi r5, r4, __vt__Q23efx5TSync@l
/* 802C350C 002C044C  38 80 00 00 */	li r4, 0
/* 802C3510 002C0450  90 BE 00 00 */	stw r5, 0(r30)
/* 802C3514 002C0454  38 05 00 14 */	addi r0, r5, 0x14
/* 802C3518 002C0458  90 1E 00 04 */	stw r0, 4(r30)
/* 802C351C 002C045C  4B DC C7 81 */	bl __dt__18JPAEmitterCallBackFv
.L_802C3520:
/* 802C3520 002C0460  7F E0 07 35 */	extsh. r0, r31
/* 802C3524 002C0464  40 81 00 0C */	ble .L_802C3530
/* 802C3528 002C0468  7F C3 F3 78 */	mr r3, r30
/* 802C352C 002C046C  4B D6 0B 89 */	bl __dl__FPv
.L_802C3530:
/* 802C3530 002C0470  80 01 00 14 */	lwz r0, 0x14(r1)
/* 802C3534 002C0474  7F C3 F3 78 */	mr r3, r30
/* 802C3538 002C0478  83 E1 00 0C */	lwz r31, 0xc(r1)
/* 802C353C 002C047C  83 C1 00 08 */	lwz r30, 8(r1)
/* 802C3540 002C0480  7C 08 03 A6 */	mtlr r0
/* 802C3544 002C0484  38 21 00 10 */	addi r1, r1, 0x10
/* 802C3548 002C0488  4E 80 00 20 */	blr 

.global __dt__Q23efx14THdamaOnHahen1Fv
__dt__Q23efx14THdamaOnHahen1Fv:
/* 802C354C 002C048C  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 802C3550 002C0490  7C 08 02 A6 */	mflr r0
/* 802C3554 002C0494  90 01 00 14 */	stw r0, 0x14(r1)
/* 802C3558 002C0498  93 E1 00 0C */	stw r31, 0xc(r1)
/* 802C355C 002C049C  7C 9F 23 78 */	mr r31, r4
/* 802C3560 002C04A0  93 C1 00 08 */	stw r30, 8(r1)
/* 802C3564 002C04A4  7C 7E 1B 79 */	or. r30, r3, r3
/* 802C3568 002C04A8  41 82 00 64 */	beq .L_802C35CC
/* 802C356C 002C04AC  3C 60 80 4D */	lis r3, __vt__Q23efx14THdamaOnHahen1@ha
/* 802C3570 002C04B0  38 63 0F E4 */	addi r3, r3, __vt__Q23efx14THdamaOnHahen1@l
/* 802C3574 002C04B4  90 7E 00 00 */	stw r3, 0(r30)
/* 802C3578 002C04B8  38 03 00 14 */	addi r0, r3, 0x14
/* 802C357C 002C04BC  90 1E 00 04 */	stw r0, 4(r30)
/* 802C3580 002C04C0  41 82 00 3C */	beq .L_802C35BC
/* 802C3584 002C04C4  3C 60 80 4E */	lis r3, __vt__Q23efx9TChaseMtx@ha
/* 802C3588 002C04C8  38 63 68 A8 */	addi r3, r3, __vt__Q23efx9TChaseMtx@l
/* 802C358C 002C04CC  90 7E 00 00 */	stw r3, 0(r30)
/* 802C3590 002C04D0  38 03 00 14 */	addi r0, r3, 0x14
/* 802C3594 002C04D4  90 1E 00 04 */	stw r0, 4(r30)
/* 802C3598 002C04D8  41 82 00 24 */	beq .L_802C35BC
/* 802C359C 002C04DC  3C 80 80 4E */	lis r4, __vt__Q23efx5TSync@ha
/* 802C35A0 002C04E0  38 7E 00 04 */	addi r3, r30, 4
/* 802C35A4 002C04E4  38 A4 69 8C */	addi r5, r4, __vt__Q23efx5TSync@l
/* 802C35A8 002C04E8  38 80 00 00 */	li r4, 0
/* 802C35AC 002C04EC  90 BE 00 00 */	stw r5, 0(r30)
/* 802C35B0 002C04F0  38 05 00 14 */	addi r0, r5, 0x14
/* 802C35B4 002C04F4  90 1E 00 04 */	stw r0, 4(r30)
/* 802C35B8 002C04F8  4B DC C6 E5 */	bl __dt__18JPAEmitterCallBackFv
.L_802C35BC:
/* 802C35BC 002C04FC  7F E0 07 35 */	extsh. r0, r31
/* 802C35C0 002C0500  40 81 00 0C */	ble .L_802C35CC
/* 802C35C4 002C0504  7F C3 F3 78 */	mr r3, r30
/* 802C35C8 002C0508  4B D6 0A ED */	bl __dl__FPv
.L_802C35CC:
/* 802C35CC 002C050C  80 01 00 14 */	lwz r0, 0x14(r1)
/* 802C35D0 002C0510  7F C3 F3 78 */	mr r3, r30
/* 802C35D4 002C0514  83 E1 00 0C */	lwz r31, 0xc(r1)
/* 802C35D8 002C0518  83 C1 00 08 */	lwz r30, 8(r1)
/* 802C35DC 002C051C  7C 08 03 A6 */	mtlr r0
/* 802C35E0 002C0520  38 21 00 10 */	addi r1, r1, 0x10
/* 802C35E4 002C0524  4E 80 00 20 */	blr 

.global __dt__Q23efx11THdamaHahenFv
__dt__Q23efx11THdamaHahenFv:
/* 802C35E8 002C0528  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 802C35EC 002C052C  7C 08 02 A6 */	mflr r0
/* 802C35F0 002C0530  90 01 00 14 */	stw r0, 0x14(r1)
/* 802C35F4 002C0534  93 E1 00 0C */	stw r31, 0xc(r1)
/* 802C35F8 002C0538  7C 9F 23 78 */	mr r31, r4
/* 802C35FC 002C053C  93 C1 00 08 */	stw r30, 8(r1)
/* 802C3600 002C0540  7C 7E 1B 79 */	or. r30, r3, r3
/* 802C3604 002C0544  41 82 00 64 */	beq .L_802C3668
/* 802C3608 002C0548  3C 60 80 4D */	lis r3, __vt__Q23efx11THdamaHahen@ha
/* 802C360C 002C054C  38 63 10 30 */	addi r3, r3, __vt__Q23efx11THdamaHahen@l
/* 802C3610 002C0550  90 7E 00 00 */	stw r3, 0(r30)
/* 802C3614 002C0554  38 03 00 14 */	addi r0, r3, 0x14
/* 802C3618 002C0558  90 1E 00 04 */	stw r0, 4(r30)
/* 802C361C 002C055C  41 82 00 3C */	beq .L_802C3658
/* 802C3620 002C0560  3C 60 80 4E */	lis r3, __vt__Q23efx12TChasePosPos@ha
/* 802C3624 002C0564  38 63 68 10 */	addi r3, r3, __vt__Q23efx12TChasePosPos@l
/* 802C3628 002C0568  90 7E 00 00 */	stw r3, 0(r30)
/* 802C362C 002C056C  38 03 00 14 */	addi r0, r3, 0x14
/* 802C3630 002C0570  90 1E 00 04 */	stw r0, 4(r30)
/* 802C3634 002C0574  41 82 00 24 */	beq .L_802C3658
/* 802C3638 002C0578  3C 80 80 4E */	lis r4, __vt__Q23efx5TSync@ha
/* 802C363C 002C057C  38 7E 00 04 */	addi r3, r30, 4
/* 802C3640 002C0580  38 A4 69 8C */	addi r5, r4, __vt__Q23efx5TSync@l
/* 802C3644 002C0584  38 80 00 00 */	li r4, 0
/* 802C3648 002C0588  90 BE 00 00 */	stw r5, 0(r30)
/* 802C364C 002C058C  38 05 00 14 */	addi r0, r5, 0x14
/* 802C3650 002C0590  90 1E 00 04 */	stw r0, 4(r30)
/* 802C3654 002C0594  4B DC C6 49 */	bl __dt__18JPAEmitterCallBackFv
.L_802C3658:
/* 802C3658 002C0598  7F E0 07 35 */	extsh. r0, r31
/* 802C365C 002C059C  40 81 00 0C */	ble .L_802C3668
/* 802C3660 002C05A0  7F C3 F3 78 */	mr r3, r30
/* 802C3664 002C05A4  4B D6 0A 51 */	bl __dl__FPv
.L_802C3668:
/* 802C3668 002C05A8  80 01 00 14 */	lwz r0, 0x14(r1)
/* 802C366C 002C05AC  7F C3 F3 78 */	mr r3, r30
/* 802C3670 002C05B0  83 E1 00 0C */	lwz r31, 0xc(r1)
/* 802C3674 002C05B4  83 C1 00 08 */	lwz r30, 8(r1)
/* 802C3678 002C05B8  7C 08 03 A6 */	mtlr r0
/* 802C367C 002C05BC  38 21 00 10 */	addi r1, r1, 0x10
/* 802C3680 002C05C0  4E 80 00 20 */	blr 

.global __dt__Q23efx13THdamaSteamStFv
__dt__Q23efx13THdamaSteamStFv:
/* 802C3684 002C05C4  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 802C3688 002C05C8  7C 08 02 A6 */	mflr r0
/* 802C368C 002C05CC  90 01 00 14 */	stw r0, 0x14(r1)
/* 802C3690 002C05D0  93 E1 00 0C */	stw r31, 0xc(r1)
/* 802C3694 002C05D4  7C 9F 23 78 */	mr r31, r4
/* 802C3698 002C05D8  93 C1 00 08 */	stw r30, 8(r1)
/* 802C369C 002C05DC  7C 7E 1B 79 */	or. r30, r3, r3
/* 802C36A0 002C05E0  41 82 00 64 */	beq .L_802C3704
/* 802C36A4 002C05E4  3C 60 80 4D */	lis r3, __vt__Q23efx13THdamaSteamSt@ha
/* 802C36A8 002C05E8  38 63 10 7C */	addi r3, r3, __vt__Q23efx13THdamaSteamSt@l
/* 802C36AC 002C05EC  90 7E 00 00 */	stw r3, 0(r30)
/* 802C36B0 002C05F0  38 03 00 14 */	addi r0, r3, 0x14
/* 802C36B4 002C05F4  90 1E 00 04 */	stw r0, 4(r30)
/* 802C36B8 002C05F8  41 82 00 3C */	beq .L_802C36F4
/* 802C36BC 002C05FC  3C 60 80 4E */	lis r3, __vt__Q23efx9TChaseMtx@ha
/* 802C36C0 002C0600  38 63 68 A8 */	addi r3, r3, __vt__Q23efx9TChaseMtx@l
/* 802C36C4 002C0604  90 7E 00 00 */	stw r3, 0(r30)
/* 802C36C8 002C0608  38 03 00 14 */	addi r0, r3, 0x14
/* 802C36CC 002C060C  90 1E 00 04 */	stw r0, 4(r30)
/* 802C36D0 002C0610  41 82 00 24 */	beq .L_802C36F4
/* 802C36D4 002C0614  3C 80 80 4E */	lis r4, __vt__Q23efx5TSync@ha
/* 802C36D8 002C0618  38 7E 00 04 */	addi r3, r30, 4
/* 802C36DC 002C061C  38 A4 69 8C */	addi r5, r4, __vt__Q23efx5TSync@l
/* 802C36E0 002C0620  38 80 00 00 */	li r4, 0
/* 802C36E4 002C0624  90 BE 00 00 */	stw r5, 0(r30)
/* 802C36E8 002C0628  38 05 00 14 */	addi r0, r5, 0x14
/* 802C36EC 002C062C  90 1E 00 04 */	stw r0, 4(r30)
/* 802C36F0 002C0630  4B DC C5 AD */	bl __dt__18JPAEmitterCallBackFv
.L_802C36F4:
/* 802C36F4 002C0634  7F E0 07 35 */	extsh. r0, r31
/* 802C36F8 002C0638  40 81 00 0C */	ble .L_802C3704
/* 802C36FC 002C063C  7F C3 F3 78 */	mr r3, r30
/* 802C3700 002C0640  4B D6 09 B5 */	bl __dl__FPv
.L_802C3704:
/* 802C3704 002C0644  80 01 00 14 */	lwz r0, 0x14(r1)
/* 802C3708 002C0648  7F C3 F3 78 */	mr r3, r30
/* 802C370C 002C064C  83 E1 00 0C */	lwz r31, 0xc(r1)
/* 802C3710 002C0650  83 C1 00 08 */	lwz r30, 8(r1)
/* 802C3714 002C0654  7C 08 03 A6 */	mtlr r0
/* 802C3718 002C0658  38 21 00 10 */	addi r1, r1, 0x10
/* 802C371C 002C065C  4E 80 00 20 */	blr 

.global __dt__Q23efx11THdamaSteamFv
__dt__Q23efx11THdamaSteamFv:
/* 802C3720 002C0660  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 802C3724 002C0664  7C 08 02 A6 */	mflr r0
/* 802C3728 002C0668  90 01 00 14 */	stw r0, 0x14(r1)
/* 802C372C 002C066C  93 E1 00 0C */	stw r31, 0xc(r1)
/* 802C3730 002C0670  7C 9F 23 78 */	mr r31, r4
/* 802C3734 002C0674  93 C1 00 08 */	stw r30, 8(r1)
/* 802C3738 002C0678  7C 7E 1B 79 */	or. r30, r3, r3
/* 802C373C 002C067C  41 82 00 64 */	beq .L_802C37A0
/* 802C3740 002C0680  3C 60 80 4D */	lis r3, __vt__Q23efx11THdamaSteam@ha
/* 802C3744 002C0684  38 63 10 C8 */	addi r3, r3, __vt__Q23efx11THdamaSteam@l
/* 802C3748 002C0688  90 7E 00 00 */	stw r3, 0(r30)
/* 802C374C 002C068C  38 03 00 14 */	addi r0, r3, 0x14
/* 802C3750 002C0690  90 1E 00 04 */	stw r0, 4(r30)
/* 802C3754 002C0694  41 82 00 3C */	beq .L_802C3790
/* 802C3758 002C0698  3C 60 80 4E */	lis r3, __vt__Q23efx9TChaseMtx@ha
/* 802C375C 002C069C  38 63 68 A8 */	addi r3, r3, __vt__Q23efx9TChaseMtx@l
/* 802C3760 002C06A0  90 7E 00 00 */	stw r3, 0(r30)
/* 802C3764 002C06A4  38 03 00 14 */	addi r0, r3, 0x14
/* 802C3768 002C06A8  90 1E 00 04 */	stw r0, 4(r30)
/* 802C376C 002C06AC  41 82 00 24 */	beq .L_802C3790
/* 802C3770 002C06B0  3C 80 80 4E */	lis r4, __vt__Q23efx5TSync@ha
/* 802C3774 002C06B4  38 7E 00 04 */	addi r3, r30, 4
/* 802C3778 002C06B8  38 A4 69 8C */	addi r5, r4, __vt__Q23efx5TSync@l
/* 802C377C 002C06BC  38 80 00 00 */	li r4, 0
/* 802C3780 002C06C0  90 BE 00 00 */	stw r5, 0(r30)
/* 802C3784 002C06C4  38 05 00 14 */	addi r0, r5, 0x14
/* 802C3788 002C06C8  90 1E 00 04 */	stw r0, 4(r30)
/* 802C378C 002C06CC  4B DC C5 11 */	bl __dt__18JPAEmitterCallBackFv
.L_802C3790:
/* 802C3790 002C06D0  7F E0 07 35 */	extsh. r0, r31
/* 802C3794 002C06D4  40 81 00 0C */	ble .L_802C37A0
/* 802C3798 002C06D8  7F C3 F3 78 */	mr r3, r30
/* 802C379C 002C06DC  4B D6 09 19 */	bl __dl__FPv
.L_802C37A0:
/* 802C37A0 002C06E0  80 01 00 14 */	lwz r0, 0x14(r1)
/* 802C37A4 002C06E4  7F C3 F3 78 */	mr r3, r30
/* 802C37A8 002C06E8  83 E1 00 0C */	lwz r31, 0xc(r1)
/* 802C37AC 002C06EC  83 C1 00 08 */	lwz r30, 8(r1)
/* 802C37B0 002C06F0  7C 08 03 A6 */	mtlr r0
/* 802C37B4 002C06F4  38 21 00 10 */	addi r1, r1, 0x10
/* 802C37B8 002C06F8  4E 80 00 20 */	blr 

.global __dt__Q23efx14THdamaOnHahen2Fv
__dt__Q23efx14THdamaOnHahen2Fv:
/* 802C37BC 002C06FC  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 802C37C0 002C0700  7C 08 02 A6 */	mflr r0
/* 802C37C4 002C0704  90 01 00 14 */	stw r0, 0x14(r1)
/* 802C37C8 002C0708  93 E1 00 0C */	stw r31, 0xc(r1)
/* 802C37CC 002C070C  7C 9F 23 78 */	mr r31, r4
/* 802C37D0 002C0710  93 C1 00 08 */	stw r30, 8(r1)
/* 802C37D4 002C0714  7C 7E 1B 79 */	or. r30, r3, r3
/* 802C37D8 002C0718  41 82 00 64 */	beq .L_802C383C
/* 802C37DC 002C071C  3C 60 80 4D */	lis r3, __vt__Q23efx14THdamaOnHahen2@ha
/* 802C37E0 002C0720  38 63 11 14 */	addi r3, r3, __vt__Q23efx14THdamaOnHahen2@l
/* 802C37E4 002C0724  90 7E 00 00 */	stw r3, 0(r30)
/* 802C37E8 002C0728  38 03 00 14 */	addi r0, r3, 0x14
/* 802C37EC 002C072C  90 1E 00 04 */	stw r0, 4(r30)
/* 802C37F0 002C0730  41 82 00 3C */	beq .L_802C382C
/* 802C37F4 002C0734  3C 60 80 4E */	lis r3, __vt__Q23efx12TChasePosPos@ha
/* 802C37F8 002C0738  38 63 68 10 */	addi r3, r3, __vt__Q23efx12TChasePosPos@l
/* 802C37FC 002C073C  90 7E 00 00 */	stw r3, 0(r30)
/* 802C3800 002C0740  38 03 00 14 */	addi r0, r3, 0x14
/* 802C3804 002C0744  90 1E 00 04 */	stw r0, 4(r30)
/* 802C3808 002C0748  41 82 00 24 */	beq .L_802C382C
/* 802C380C 002C074C  3C 80 80 4E */	lis r4, __vt__Q23efx5TSync@ha
/* 802C3810 002C0750  38 7E 00 04 */	addi r3, r30, 4
/* 802C3814 002C0754  38 A4 69 8C */	addi r5, r4, __vt__Q23efx5TSync@l
/* 802C3818 002C0758  38 80 00 00 */	li r4, 0
/* 802C381C 002C075C  90 BE 00 00 */	stw r5, 0(r30)
/* 802C3820 002C0760  38 05 00 14 */	addi r0, r5, 0x14
/* 802C3824 002C0764  90 1E 00 04 */	stw r0, 4(r30)
/* 802C3828 002C0768  4B DC C4 75 */	bl __dt__18JPAEmitterCallBackFv
.L_802C382C:
/* 802C382C 002C076C  7F E0 07 35 */	extsh. r0, r31
/* 802C3830 002C0770  40 81 00 0C */	ble .L_802C383C
/* 802C3834 002C0774  7F C3 F3 78 */	mr r3, r30
/* 802C3838 002C0778  4B D6 08 7D */	bl __dl__FPv
.L_802C383C:
/* 802C383C 002C077C  80 01 00 14 */	lwz r0, 0x14(r1)
/* 802C3840 002C0780  7F C3 F3 78 */	mr r3, r30
/* 802C3844 002C0784  83 E1 00 0C */	lwz r31, 0xc(r1)
/* 802C3848 002C0788  83 C1 00 08 */	lwz r30, 8(r1)
/* 802C384C 002C078C  7C 08 03 A6 */	mtlr r0
/* 802C3850 002C0790  38 21 00 10 */	addi r1, r1, 0x10
/* 802C3854 002C0794  4E 80 00 20 */	blr 

.global inWaterCallback__Q34Game6Houdai3ObjFPQ24Game8WaterBox
inWaterCallback__Q34Game6Houdai3ObjFPQ24Game8WaterBox:
/* 802C3858 002C0798  4E 80 00 20 */	blr 

.global outWaterCallback__Q34Game6Houdai3ObjFv
outWaterCallback__Q34Game6Houdai3ObjFv:
/* 802C385C 002C079C  4E 80 00 20 */	blr 

.global getDamageCoeStoneState__Q34Game6Houdai3ObjFv
getDamageCoeStoneState__Q34Game6Houdai3ObjFv:
/* 802C3860 002C07A0  C0 22 E1 A4 */	lfs f1, lbl_8051C504@sda21(r2)
/* 802C3864 002C07A4  4E 80 00 20 */	blr 

.global throwupItemInDeathProcedure__Q34Game6Houdai3ObjFv
throwupItemInDeathProcedure__Q34Game6Houdai3ObjFv:
/* 802C3868 002C07A8  4E 80 00 20 */	blr 

.global getEnemyTypeID__Q34Game6Houdai3ObjFv
getEnemyTypeID__Q34Game6Houdai3ObjFv:
/* 802C386C 002C07AC  38 60 00 42 */	li r3, 0x42
/* 802C3870 002C07B0  4E 80 00 20 */	blr 

.global __sinit_Houdai_cpp
__sinit_Houdai_cpp:
/* 802C3874 002C07B4  3C 80 80 51 */	lis r4, __float_nan@ha
/* 802C3878 002C07B8  38 00 FF FF */	li r0, -1
/* 802C387C 002C07BC  C0 04 48 B0 */	lfs f0, __float_nan@l(r4)
/* 802C3880 002C07C0  3C 60 80 4D */	lis r3, lbl_804D0E98@ha
/* 802C3884 002C07C4  90 0D 97 18 */	stw r0, lbl_80515D98@sda21(r13)
/* 802C3888 002C07C8  D4 03 0E 98 */	stfsu f0, lbl_804D0E98@l(r3)
/* 802C388C 002C07CC  D0 0D 97 1C */	stfs f0, lbl_80515D9C@sda21(r13)
/* 802C3890 002C07D0  D0 03 00 04 */	stfs f0, 4(r3)
/* 802C3894 002C07D4  D0 03 00 08 */	stfs f0, 8(r3)
/* 802C3898 002C07D8  4E 80 00 20 */	blr 

.global "@1056@12@viewOnPelletKilled__Q24Game9EnemyBaseFv"
"@1056@12@viewOnPelletKilled__Q24Game9EnemyBaseFv":
/* 802C389C 002C07DC  39 60 00 0C */	li r11, 0xc
/* 802C38A0 002C07E0  7D 63 58 2E */	lwzx r11, r3, r11
/* 802C38A4 002C07E4  7C 63 5A 14 */	add r3, r3, r11
/* 802C38A8 002C07E8  38 63 FB E0 */	addi r3, r3, -1056
/* 802C38AC 002C07EC  4B E4 30 70 */	b viewOnPelletKilled__Q24Game9EnemyBaseFv

.global "@1056@12@viewStartCarryMotion__Q24Game9EnemyBaseFv"
"@1056@12@viewStartCarryMotion__Q24Game9EnemyBaseFv":
/* 802C38B0 002C07F0  39 60 00 0C */	li r11, 0xc
/* 802C38B4 002C07F4  7D 63 58 2E */	lwzx r11, r3, r11
/* 802C38B8 002C07F8  7C 63 5A 14 */	add r3, r3, r11
/* 802C38BC 002C07FC  38 63 FB E0 */	addi r3, r3, -1056
/* 802C38C0 002C0800  4B E4 2D E8 */	b viewStartCarryMotion__Q24Game9EnemyBaseFv

.global "@1056@12@viewStartPreCarryMotion__Q24Game9EnemyBaseFv"
"@1056@12@viewStartPreCarryMotion__Q24Game9EnemyBaseFv":
/* 802C38C4 002C0804  39 60 00 0C */	li r11, 0xc
/* 802C38C8 002C0808  7D 63 58 2E */	lwzx r11, r3, r11
/* 802C38CC 002C080C  7C 63 5A 14 */	add r3, r3, r11
/* 802C38D0 002C0810  38 63 FB E0 */	addi r3, r3, -1056
/* 802C38D4 002C0814  4B E4 2D F4 */	b viewStartPreCarryMotion__Q24Game9EnemyBaseFv

.global "@1056@12@view_finish_carrymotion__Q24Game9EnemyBaseFv"
"@1056@12@view_finish_carrymotion__Q24Game9EnemyBaseFv":
/* 802C38D8 002C0818  39 60 00 0C */	li r11, 0xc
/* 802C38DC 002C081C  7D 63 58 2E */	lwzx r11, r3, r11
/* 802C38E0 002C0820  7C 63 5A 14 */	add r3, r3, r11
/* 802C38E4 002C0824  38 63 FB E0 */	addi r3, r3, -1056
/* 802C38E8 002C0828  4B E4 31 90 */	b view_finish_carrymotion__Q24Game9EnemyBaseFv

.global "@1056@12@view_start_carrymotion__Q24Game9EnemyBaseFv"
"@1056@12@view_start_carrymotion__Q24Game9EnemyBaseFv":
/* 802C38EC 002C082C  39 60 00 0C */	li r11, 0xc
/* 802C38F0 002C0830  7D 63 58 2E */	lwzx r11, r3, r11
/* 802C38F4 002C0834  7C 63 5A 14 */	add r3, r3, r11
/* 802C38F8 002C0838  38 63 FB E0 */	addi r3, r3, -1056
/* 802C38FC 002C083C  4B E4 31 50 */	b view_start_carrymotion__Q24Game9EnemyBaseFv

.global "@1056@12@viewGetShape__Q24Game9EnemyBaseFv"
"@1056@12@viewGetShape__Q24Game9EnemyBaseFv":
/* 802C3900 002C0840  39 60 00 0C */	li r11, 0xc
/* 802C3904 002C0844  7D 63 58 2E */	lwzx r11, r3, r11
/* 802C3908 002C0848  7C 63 5A 14 */	add r3, r3, r11
/* 802C390C 002C084C  38 63 FB E0 */	addi r3, r3, -1056
/* 802C3910 002C0850  4B E4 2D 90 */	b viewGetShape__Q24Game9EnemyBaseFv

.global "@4@__dt__Q23efx14THdamaOnHahen2Fv"
"@4@__dt__Q23efx14THdamaOnHahen2Fv":
/* 802C3914 002C0854  38 63 FF FC */	addi r3, r3, -4
/* 802C3918 002C0858  4B FF FE A4 */	b __dt__Q23efx14THdamaOnHahen2Fv

.global "@4@__dt__Q23efx11THdamaSteamFv"
"@4@__dt__Q23efx11THdamaSteamFv":
/* 802C391C 002C085C  38 63 FF FC */	addi r3, r3, -4
/* 802C3920 002C0860  4B FF FE 00 */	b __dt__Q23efx11THdamaSteamFv

.global "@4@__dt__Q23efx13THdamaSteamStFv"
"@4@__dt__Q23efx13THdamaSteamStFv":
/* 802C3924 002C0864  38 63 FF FC */	addi r3, r3, -4
/* 802C3928 002C0868  4B FF FD 5C */	b __dt__Q23efx13THdamaSteamStFv

.global "@4@__dt__Q23efx11THdamaHahenFv"
"@4@__dt__Q23efx11THdamaHahenFv":
/* 802C392C 002C086C  38 63 FF FC */	addi r3, r3, -4
/* 802C3930 002C0870  4B FF FC B8 */	b __dt__Q23efx11THdamaHahenFv

.global "@4@__dt__Q23efx14THdamaOnHahen1Fv"
"@4@__dt__Q23efx14THdamaOnHahen1Fv":
/* 802C3934 002C0874  38 63 FF FC */	addi r3, r3, -4
/* 802C3938 002C0878  4B FF FC 14 */	b __dt__Q23efx14THdamaOnHahen1Fv

.global "@4@__dt__Q23efx14THdamaOnSteam1Fv"
"@4@__dt__Q23efx14THdamaOnSteam1Fv":
/* 802C393C 002C087C  38 63 FF FC */	addi r3, r3, -4
/* 802C3940 002C0880  4B FF FB 70 */	b __dt__Q23efx14THdamaOnSteam1Fv

.global "@4@__dt__Q23efx13THdamaSteamBdFv"
"@4@__dt__Q23efx13THdamaSteamBdFv":
/* 802C3944 002C0884  38 63 FF FC */	addi r3, r3, -4
/* 802C3948 002C0888  4B FF FA CC */	b __dt__Q23efx13THdamaSteamBdFv
