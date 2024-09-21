#include "JSystem/JAI/JAISound.h"
#include "PSM/EnemyBase.h"
#include "Game/EnemyBase.h"

JAISound* PSStartEnemyGhostSE(Game::EnemyBase* enemy, f32)
{
	JAISound* ghost = enemy->getJAIObject()->startSound(PSSE_EN_ENEMY_GHOST, 0);
	if (ghost) {
		f32 volume = 0.0f;
		f32 pitch  = 0.0f;
		switch (enemy->getEnemyTypeID()) {
		case Game::EnemyTypeID::EnemyID_KingChappy:
			volume = 1.0f;
			pitch  = 0.8f;
			break;
		case Game::EnemyTypeID::EnemyID_FireChappy:
		case Game::EnemyTypeID::EnemyID_KumaChappy:
		case Game::EnemyTypeID::EnemyID_OoPanModoki:
			volume = 1.0f;
			pitch  = 0.9f;
			break;
		case Game::EnemyTypeID::EnemyID_Chappy:
		case Game::EnemyTypeID::EnemyID_BlueChappy:
		case Game::EnemyTypeID::EnemyID_YellowChappy:
			volume = 1.0f;
			pitch  = 1.0f;
			break;
		case Game::EnemyTypeID::EnemyID_MiniHoudai:
			volume = 1.0f;
			pitch  = 1.1f;
			break;
		case Game::EnemyTypeID::EnemyID_SnakeCrow:
		case Game::EnemyTypeID::EnemyID_SnakeWhole:
		case Game::EnemyTypeID::EnemyID_Kabuto:
		case Game::EnemyTypeID::EnemyID_Hana:
			volume = 1.0f;
			pitch  = 1.2f;
			break;
		case Game::EnemyTypeID::EnemyID_Armor:
		case Game::EnemyTypeID::EnemyID_Catfish:
		case Game::EnemyTypeID::EnemyID_Miulin:
		case Game::EnemyTypeID::EnemyID_BombSarai:
			volume = 0.9f;
			pitch  = 1.3f;
			break;
		case Game::EnemyTypeID::EnemyID_Frog:
		case Game::EnemyTypeID::EnemyID_MaroFrog:
		case Game::EnemyTypeID::EnemyID_Tank:
		case Game::EnemyTypeID::EnemyID_Wtank:
			volume = 0.8f;
			pitch  = 1.4f;
			break;
		case Game::EnemyTypeID::EnemyID_Sarai:
		case Game::EnemyTypeID::EnemyID_ElecBug:
		case Game::EnemyTypeID::EnemyID_Demon:
		case Game::EnemyTypeID::EnemyID_PanModoki:
		case Game::EnemyTypeID::EnemyID_Fuefuki:
		case Game::EnemyTypeID::EnemyID_Jigumo:
		case Game::EnemyTypeID::EnemyID_LeafChappy:
			volume = 0.7f;
			pitch  = 1.5f;
			break;
		case Game::EnemyTypeID::EnemyID_Kochappy:
		case Game::EnemyTypeID::EnemyID_BlueKochappy:
		case Game::EnemyTypeID::EnemyID_YellowKochappy:
		case Game::EnemyTypeID::EnemyID_KumaKochappy:
		case Game::EnemyTypeID::EnemyID_Sokkuri:
			volume = 0.6f;
			pitch  = 1.6f;
			break;
		case Game::EnemyTypeID::EnemyID_Tadpole:
		case Game::EnemyTypeID::EnemyID_Baby:
		case Game::EnemyTypeID::EnemyID_PikiBabyRed:
		case Game::EnemyTypeID::EnemyID_PikiBabyYellow:
		case Game::EnemyTypeID::EnemyID_PikiBabyBlue:
			volume = 0.6f;
			pitch  = 1.7f;
			break;

		case Game::EnemyTypeID::EnemyID_UjiA:
		case Game::EnemyTypeID::EnemyID_UjiB:
		case Game::EnemyTypeID::EnemyID_Tobi:
		case Game::EnemyTypeID::EnemyID_OrangPom:
			volume = 0.5f;
			pitch  = 2.0f;
			break;
		case Game::EnemyTypeID::EnemyID_FireOtakara:
		case Game::EnemyTypeID::EnemyID_WaterOtakara:
		case Game::EnemyTypeID::EnemyID_GasOtakara:
		case Game::EnemyTypeID::EnemyID_ElecOtakara:
			volume = 0.6f;
			pitch  = 1.8f;
			break;
		case Game::EnemyTypeID::EnemyID_ShijimiChou:
			volume = 0.4f;
			pitch  = 2.3f;
			break;
		}
		ghost->setVolume(volume, 0, SOUNDPARAM_Unk0);
		ghost->setPitch(pitch, 0, SOUNDPARAM_Unk0);
	}
	return ghost;
}
