#include "Game/gamePlayData.h"
#include "Game/BaseGameSection.h"
#include "Game/MoviePlayer.h"
namespace TwoPlayer
{
    bool useTwoPlayer = true;

    void initTwoPlayer() {
        // if (useTwoPlayer) {
        //     Game::playData->_20 |= 1;
        // }
        // else {
        //     Game::playData->_20 &= ~1;
        // }
    }

} // namespace TwoPlayer

namespace Game
{
    

void BaseGameSection::pmTogglePlayer()
{
    if (TwoPlayer::useTwoPlayer) {
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

} // namespace Game
