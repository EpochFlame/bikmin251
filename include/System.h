#ifndef _SYSTEM_H
#define _SYSTEM_H

#include "types.h"
#include "DvdThreadCommand.h"
#include "Dolphin/gx.h"
#include "SysTimers.h"
#include "JSystem/JKR/JKRHeap.h"
#include "node.h"
#include "BitFlag.h"

struct Graphics;
struct OSContext;
struct _GXRenderModeObj;
struct HeapStatus;

void Pikmin2DefaultMemoryErrorRoutine(void*, u32, s32);
void kando_panic_f(bool, const char*, s32, const char*, ...);
extern void preUserCallback(unsigned short, OSContext*, unsigned long, unsigned long);

typedef s32 ERenderMode;

struct HeapInfo : public Node, public JKRDisposer {
	virtual ~HeapInfo(); // _20 (weak)

	void search(HeapInfo*);

	// _00-_24 = Node
	// _20     = VTBL (Node)
	// _24-_3C = JKRDisposer
	u32 _3C;         // _3C, unknown
	int _40;         // _40
	u32 _44;         // _44, unknown
	HeapStatus* _48; // _48
	HeapStatus* _4C; // _4C
};

struct HeapStatus {
	HeapStatus();

	HeapInfo mHeapInfo; // _00
	u8 _50;             // _50, unknown
};

namespace Game {
namespace CommonSaveData {
struct Mgr;
};

namespace MemoryCard {
struct Mgr;
}
} // namespace Game

struct System {
	enum LanguageID { LANG_ENGLISH = 0, LANG_FRENCH, LANG_GERMAN, LANG_HOL_UNUSED, LANG_ITALIAN, LANG_JAPANESE, LANG_SPANISH };
	struct FragmentationChecker {
		FragmentationChecker(char*, bool);
		~FragmentationChecker();
	};

	System();
	~System();

	static _GXRenderModeObj* getRenderModeObj();
	static void assert_fragmentation(char*);
	static void createSoundSystem();
	static void loadSoundResource();
	static void initialize();

	void enableCPULockDetector(int);
	int disableCPULockDetector();
	void construct();
	void constructWithDvdAccessFirst();
	void constructWithDvdAccessSecond();
	void createRomFont(struct JKRHeap*);
	void destroyRomFont();
	void loadResourceFirst();
	void loadResourceSecond();
	int run();
	float getTime();
	void clearOptionBlockSaveFlag();
	void setOptionBlockSaveFlag();
	Game::CommonSaveData::Mgr* getPlayCommonData();
	void dvdLoadUseCallBack(struct DvdThreadCommand*, struct IDelegate*);
	void deleteThreads();
	struct JFWDisplay* setCurrentDisplay(struct JFWDisplay*);
	u32 clearCurrentDisplay(struct JFWDisplay*);
	bool beginFrame();
	void endFrame();
	void beginRender();
	void endRender();
	ERenderMode setRenderMode(ERenderMode);
	void changeRenderMode(ERenderMode);
	// Possibilities: HeapStatus*, bool, ???
	u32 heapStatusStart(char*, JKRHeap*);
	void heapStatusEnd(char*);
	void heapStatusDump(bool);
	void heapStatusIndividual();
	void heapStatusNormal();
	void resetOn(bool);
	void resetPermissionOn();
	bool isResetActive();
	void activeGP();
	void inactiveGP();
	bool isDvdErrorOccured();
	void initCurrentHeapMutex();
	void startChangeCurrentHeap(JKRHeap*);
	void endChangeCurrentHeap();
	void addGenNode(struct CNode*);
	void initGenNode();
	void refreshGenNode();
	void setFrameRate(int);
	bool dvdLoadSyncNoBlock(struct DvdThreadCommand*);
	int dvdLoadSyncAllNoBlock();

	// _00-_18 = OSMutex
	JKRHeap* mBackupHeap;                 // _18
	u32 mCpuRetraceCount;                 // _1C
	u32 mCpuLockCount;                    // _20
	Graphics* m_gfx;                       // _24
	SysTimers* m_timers;                   // _28
	u32 _2C;                              // _2C
	u32 _30;                              // _30
	u32 _34;                              // _34
	JKRHeap* mSysHeap;                    // _38
	struct GameFlow* mGameFlow;           // _3C
	struct DvdThread* mDvdThread;         // _40
	struct ResetManager* mResetMgr;       // _44
	struct DvdStatus* mDvdStatus;         // _48
	struct JFWDisplay* m_display;          // _4C
	HeapStatus* mHeapStatus;              // _50
	f32 m_deltaTime;                       // _54
	struct JKRTask* mTask;                // _58
	Game::MemoryCard::Mgr* m_cardMgr;     // _5C
	Game::CommonSaveData::Mgr* mPlayData; // _60
	f32 m_fpsFactor;                      // _64
	DvdThreadCommand mThreadCommand;      // _68
	LanguageID m_region;                  // _D4
	BitFlag<u32> m_flags;                 // _D8
	struct JUTRomFont* m_romFont;         // _DC
};

extern System* sys;

#endif
