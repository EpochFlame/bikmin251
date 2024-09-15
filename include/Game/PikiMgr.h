#ifndef _GAME_PIKIMGR_H
#define _GAME_PIKIMGR_H

#include "types.h"

#include "Condition.h"
#include "CNode.h"
#include "MonoObjectMgr.h"

#include "Game/Piki.h"
#include "Game/PikiParms.h"

struct J3DModelData;
struct UpdateMgr;
struct JKRArchive;

namespace SysShape {
struct ModelMgr;
} // namespace SysShape

namespace Game {
struct PikiContainer;

struct PikiMgr : public MonoObjectMgr<Piki> {
	enum PikiSpawnMode {
		PSM_Normal,  // checks if we've hit 100 cap by active pikis or sprouts before spawning (wild pikis, out of onyons, etc)
		PSM_Force,   // does no checks, just spawns (plucking sprouts)
		PSM_Replace, // checks if we can spawn normally; if not, removes 'extra' wild bulbmin (when entering the next cave floor)
	};
	
	PikiMgr();

	// vtable 1
	virtual ~PikiMgr(); // _08 (weak)
	// vtable 2
	virtual void doAnimation();           // _64 (weak)
	virtual void doEntry();               // _68 (weak)
	virtual Piki* birth();                // _7C
	virtual void resetMgr();              // _80 (weak)
	virtual void onAlloc();               // _88
	virtual void doSimpleDraw(Viewport*); // _8C (weak)
	virtual u32 getMatrixLoadType();      // _90 (weak)
	virtual void getMgrName();            // _94 (weak)
	virtual void loadResources();         // _98 (weak)
	virtual void loadResources(int);      // _9C

	void init();
	void setupPiki(Piki*);
	void load(int);
	void loadBmd(int, char*);
	void createModelCallback(SysShape::Model*);
	SysShape::Model* createModel(int, int);
	SysShape::Model* createLeafModel(int, int);
	void setMovieDraw(bool);
	void debugShapeDL(char*);
	void setVsXlu(int, bool);
	void setupSoundViewerAndBas();
	int getColorTransportScale(int);
	void allocStorePikmins();
	void clearStorePikmins();
	void saveStorePikmins(Condition<Piki>*);
	void getStorePikmin(int, int);
	void moveAllPikmins(Vector3f&, f32, Condition<Piki>*);
	void forceEnterPikmins(u8);
	void killDayEndPikmins(PikiContainer&);
	void killAllPikmins();
	void caveSaveFormationPikmins(bool);
	void caveSaveAllPikmins(bool, bool);
	void saveFormationPikmins(PikiContainer&);
	void saveAllPikmins(PikiContainer&);
	int getSharedEmptyIndex();
	void loadPikiHead();
	Piki* birthPikiModel();

	static int mBirthMode;

	s32 m_dopedPikis;               // _30
	s32* m_storedPikis;             // _34
	u8 m_flags[4];                  // _38
	int m_padding[7];               // _3C, blue
	J3DModelData* m_happaModel[5];  // _58
	PikiParms* m_parms;             // _6C
	SysShape::ModelMgr* m_modelMgr; // _70
	UpdateMgr* m_updateMgr;         // _74
	UpdateMgr* m_updateMgr2;        // _78, unsure of type
	JKRArchive* m_modelArchive;     // _7C
	J3DModelData* m_pikiModels[8];  // _80
};

extern PikiMgr* pikiMgr;
} // namespace Game

#endif
