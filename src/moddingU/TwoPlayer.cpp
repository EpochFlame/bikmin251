#include "Game/gamePlayData.h"
#include "Game/BaseGameSection.h"
#include "Game/GameSystem.h"
#include "Game/MoviePlayer.h"
#include "Game/Navi.h"
#include "utilityU.h"
#include "PSGame/SceneInfo.h"
namespace TwoPlayer
{
    bool useTwoPlayer = true;
    int deadPlayer = 0;

    void initTwoPlayer() {
        // if (useTwoPlayer) {
        //     Game::playData->_20 |= 1;
        // }
        // else {
        //     Game::playData->_20 &= ~1;
        // }
    }

    // setModeInCutscene__9TwoPlayerFv
    void setModeInCutscene() {
        OSReport("toggle mode called ---------------------------------\n");
        if (useTwoPlayer) {
            
            OSReport("set player mode ---------------------------------\n");
            Game::BaseGameSection* section = Game::gameSystem->m_section;
            if (Game::naviMgr->getAliveCount() == 2) {
                section->setPlayerMode(0);
                Game::moviePlayer->m_viewport     = sys->m_gfx->getViewport(0);
                Game::moviePlayer->m_actingCamera = section->m_olimarCamera;
            }
            else if (section->m_prevNaviIdx == 0) {
                section->setPlayerMode(1);
                Game::moviePlayer->m_viewport     = sys->m_gfx->getViewport(1);
                Game::moviePlayer->m_actingCamera = section->m_louieCamera;
            } else if (section->m_prevNaviIdx == 1) {
                section->setPlayerMode(0);
                Game::moviePlayer->m_viewport     = sys->m_gfx->getViewport(0);
                Game::moviePlayer->m_actingCamera = section->m_olimarCamera;
            }
        }
    }

    // setModeOutCutscene__9TwoPlayerFv
    void setModeOutCutscene() {
        Game::gameSystem->m_section->pmTogglePlayer();
    }
    // loadSound__9TwoPlayerFv
    void loadSound() {
        Game::naviMgr->createPSMDirectorUpdator();
    }

} // namespace TwoPlayer

namespace Game
{
    

void BaseGameSection::pmTogglePlayer()
{
    if (TwoPlayer::useTwoPlayer && naviMgr->getAliveCount() == 2) {
        setPlayerMode(2);
        moviePlayer->m_viewport     = sys->m_gfx->getViewport(0);
        moviePlayer->m_actingCamera = m_olimarCamera;
    }
	else if (m_prevNaviIdx == 0) {
		setPlayerMode(1);
		moviePlayer->m_viewport     = sys->m_gfx->getViewport(1);
		moviePlayer->m_actingCamera = m_louieCamera;
	} else if (m_prevNaviIdx == 1) {
		setPlayerMode(0);
		moviePlayer->m_viewport     = sys->m_gfx->getViewport(0);
		moviePlayer->m_actingCamera = m_olimarCamera;
	}
	onTogglePlayer();
}

void BaseGameSection::setCamController()
{
	Navi* navis[2];

	navis[0] = naviMgr->getAt(0);
	navis[1] = naviMgr->getAt(1);

	switch (m_prevNaviIdx) {
	case 0: {
		PlayCamera* olimarCam        = m_olimarCamera;
		navis[0]->m_camera            = olimarCam;
		navis[0]->m_camera2           = olimarCam;
		Controller* olimarController = m_controllerP1;
        navis[0]->m_padinput       = olimarController;
        navis[0]->m_padinput2       = olimarController;
		navis[1]->disableController();
		moviePlayer->m_targetNavi   = navis[0];
		moviePlayer->m_viewport     = sys->m_gfx->getViewport(0);
		moviePlayer->m_actingCamera = m_olimarCamera;
		if (!gameSystem->isMultiplayerMode()) {
			PSSetCurCameraNo(0);
			//PSPlayerChangeToOrimer();
		}
		break;
	}
	case 1: {
		navis[0]->disableController();
		PlayCamera* louieCam        = m_louieCamera;
		navis[1]->m_camera           = louieCam;
		navis[1]->m_camera2          = louieCam;
		Controller* louieController = (TwoPlayer::useTwoPlayer) ? m_controllerP2 : m_controllerP1;
		navis[1]->m_padinput      = louieController;
		navis[1]->m_padinput2      = louieController;
        navis[0]->disableController();
		moviePlayer->m_targetNavi    = navis[1];
		moviePlayer->m_viewport      = sys->m_gfx->getViewport(1);
		moviePlayer->m_actingCamera  = m_louieCamera;
		if (!gameSystem->isMultiplayerMode()) {
			PSSetCurCameraNo(1);
			//PSPlayerChangeToLugie();
		}
		break;
	}
	case 2: {
		PlayCamera* olimarCam        = m_olimarCamera;
		navis[0]->m_camera            = olimarCam;
		navis[0]->m_camera2           = olimarCam;
		Controller* olimarController = m_controllerP1;
		navis[0]->m_padinput       = olimarController;
		navis[0]->m_padinput2       = olimarController;
		PlayCamera* louieCam         = m_louieCamera;
		navis[1]->m_camera            = louieCam;
		navis[1]->m_camera2           = louieCam;
		Controller* louieController  = m_controllerP2;
		navis[1]->m_padinput       = louieController;
		navis[1]->m_padinput2       = louieController;

		moviePlayer->m_targetNavi   = navis[0];
		moviePlayer->m_actingCamera = m_olimarCamera;
		if (gameSystem->m_mode == GSM_STORY_MODE) {
			PSSetCurCameraNo(0);
		}
		break;
	}
	}
	on_setCamController(m_prevNaviIdx);
}


} // namespace Game
