#ifndef _GAME_GAMESYSTEM_H
#define _GAME_GAMESYSTEM_H

#include "types.h"
#include "CNode.h"
#include "ObjectMgr.h"
#include "Game/BaseGameSection.h"
#include "Game/TimeMgr.h"

struct Graphics;
struct JUTTexture;
struct LightMgr;
struct Viewport;
namespace Game {

enum GameSystemMode {
	GSM_STORY_MODE = 0,
	GSM_VERSUS_MODE,
	GSM_ONE_PLAYER_CHALLENGE,
	GSM_TWO_PLAYER_CHALLENGE,
	GSM_PIKLOPEDIA,
};

enum GameSystemFlags {
	GAMESYS_Unk1      = 0x1,
	GAMESYS_IsPlaying = 0x2,
	GAMESYS_Unk3      = 0x4,
	GAMESYS_Unk4      = 0x8,
	GAMESYS_Unk5      = 0x10,
	GAMESYS_Unk6      = 0x20,
	GAMESYS_Unk7      = 0x40,
	GAMESYS_Unk8      = 0x80,
};

struct GameSystem : public NodeObjectMgr<GenericObjectMgr> {
	GameSystem(Game::BaseGameSection*);
	// vtable 1
	virtual ~GameSystem(); // _08
	// vtable 2
	virtual void doAnimation();                 // _64 (weak)
	virtual void doEntry();                     // _68 (weak)
	virtual void doSetView(int viewportNumber); // _6C (weak)
	virtual void doViewCalc();                  // _70 (weak)
	virtual void doSimulation(f32 rate);        // _74 (weak)
	virtual void doDirectDraw(Graphics& gfx);   // _78 (weak)
	virtual void startFrame();                  // _80
	virtual void endFrame();                    // _84
	virtual void doSimpleDraw(Viewport*);       // _88 (weak)
	virtual void directDraw(Graphics&);         // _8C
	virtual void startFadeout(f32);             // _90
	virtual void startFadein(f32);              // _94
	virtual void startFadeoutin(f32);           // _98
	virtual void startFadeblack();              // _9C
	virtual void startFadewhite();              // _A0

	void addObjectMgr_reuse(TObjectNode<GenericObjectMgr>*);
	void addObjectMgr(GenericObjectMgr*);
	s32 calcFrameDist(int);
	void detachAllMgr();
	TObjectNode<GenericObjectMgr>* detachObjectMgr_reuse(GenericObjectMgr*);
	void detachObjectMgr(GenericObjectMgr*);
	GameLightMgr* getLightMgr();
	void init();
	bool isZukanMode();
	bool paused_soft();
	bool paused();
	void setDrawBuffer(int);
	void setFrozen(bool, char*);
	void setMoviePause(bool, char*);
	void setPause(bool, char*, int);
	int startPause(bool, int, char*);

	inline bool isVersusMode() { return m_mode == GSM_VERSUS_MODE; }
	inline bool isMultiplayerMode() { return (m_mode == GSM_VERSUS_MODE || m_mode == GSM_TWO_PLAYER_CHALLENGE); }
	inline bool isChallengeMode() { return (m_mode == GSM_ONE_PLAYER_CHALLENGE || m_mode == GSM_TWO_PLAYER_CHALLENGE); }
	inline bool isStoryMode() { return m_mode == GSM_STORY_MODE; }


	inline void setFlag(u32 flag) { m_flags |= flag; }

	inline void resetFlag(u32 flag) { m_flags &= ~flag; }

	inline bool isFlag(u32 flag) { return m_flags & flag; }

	u8 m_flags;                 // _3C /* bitfield */
	TimeMgr* m_timeMgr;         // _40
	GameSystemMode m_mode;      // _44
	u8 m_inCave;                // _48
	u8 _49;                     // _49
	bool m_isFrozen;            // _4A
	u8 m_isPaused;              // _4B
	bool m_isPausedSoft;        // _4C
	bool m_isMoviePause;        // _4D
	u32 m_frameTimer;           // _50
	JUTTexture* m_xfbTexture;   // _54
	BaseGameSection* m_section; // _58
};

struct OptimiseController : public JKRDisposer, public Parameters {
	OptimiseController()
	    : Parameters(nullptr, "Dynamics")
	    , m_c000(this, 'c000', "�s�N�~����", true, false, true)
	    ,                                                                  // pikmin neck
	    m_c001(this, 'c001', "�R���W�����o�b�t�@�L��", false, false, true) // collision buffer enabled
	{
	}

	virtual ~OptimiseController() { mInstance = nullptr; } // _08

	static void globalInstance();
	static void deleteInstance();

	Parm<bool> m_c000;
	Parm<bool> m_c001;

	static OptimiseController* mInstance;
};

extern GameSystem* gameSystem;

} // namespace Game

#endif
