#include "Morimura/Zukan.h"
#include "Game/enemyInfo.h"
#include "Game/SingleGame.h"
#include "Game/generalEnemyMgr.h"
#include "Game/Entities/PikiBaby.h"
#include "Dolphin/rand.h"

#define ENEMY_ZUKAN_COUNT 81

namespace Morimura {

// this table connects piklopedia order to the actual game enemy id order
TEnemyZukanIndex eIDInfo[ENEMY_ZUKAN_COUNT] = {
	{ TEnemyZukan::Zukan_Chappy, Game::EnemyTypeID::EnemyID_Chappy },
	{ TEnemyZukan::Zukan_YellowChappy, Game::EnemyTypeID::EnemyID_YellowChappy },
	{ TEnemyZukan::Zukan_BlueChappy, Game::EnemyTypeID::EnemyID_BlueChappy },
	{ TEnemyZukan::Zukan_Kochappy, Game::EnemyTypeID::EnemyID_Kochappy },
	{ TEnemyZukan::Zukan_YellowKochappy, Game::EnemyTypeID::EnemyID_YellowKochappy },
	{ TEnemyZukan::Zukan_BlueKochappy, Game::EnemyTypeID::EnemyID_BlueKochappy },
	{ TEnemyZukan::Zukan_KumaChappy, Game::EnemyTypeID::EnemyID_KumaChappy },
	{ TEnemyZukan::Zukan_KumaKochappy, Game::EnemyTypeID::EnemyID_KumaKochappy },
	{ TEnemyZukan::Zukan_Baby, Game::EnemyTypeID::EnemyID_Baby },
	{ TEnemyZukan::Zukan_FireChappy, Game::EnemyTypeID::EnemyID_FireChappy },
	{ TEnemyZukan::Zukan_Catfish, Game::EnemyTypeID::EnemyID_Catfish },
	{ TEnemyZukan::Zukan_LeafChappy, Game::EnemyTypeID::EnemyID_LeafChappy },
	{ TEnemyZukan::Zukan_Tank, Game::EnemyTypeID::EnemyID_Tank },
	{ TEnemyZukan::Zukan_Wtank, Game::EnemyTypeID::EnemyID_Wtank },
	{ TEnemyZukan::Zukan_Kabuto, Game::EnemyTypeID::EnemyID_Kabuto },
	{ TEnemyZukan::Zukan_Rkabuto, Game::EnemyTypeID::EnemyID_Rkabuto },
	{ TEnemyZukan::Zukan_Mar, Game::EnemyTypeID::EnemyID_Mar },
	{ TEnemyZukan::Zukan_Hanachirashi, Game::EnemyTypeID::EnemyID_Hanachirashi },
	{ TEnemyZukan::Zukan_MiniHoudai, Game::EnemyTypeID::EnemyID_MiniHoudai },
	{ TEnemyZukan::Zukan_Kogane, Game::EnemyTypeID::EnemyID_Kogane },
	{ TEnemyZukan::Zukan_Wealthy, Game::EnemyTypeID::EnemyID_Wealthy },
	{ TEnemyZukan::Zukan_Fart, Game::EnemyTypeID::EnemyID_Fart },
	{ TEnemyZukan::Zukan_UjiB, Game::EnemyTypeID::EnemyID_UjiB },
	{ TEnemyZukan::Zukan_UjiA, Game::EnemyTypeID::EnemyID_UjiA },
	{ TEnemyZukan::Zukan_Tobi, Game::EnemyTypeID::EnemyID_Tobi },
	{ TEnemyZukan::Zukan_Armor, Game::EnemyTypeID::EnemyID_Armor },
	{ TEnemyZukan::Zukan_Imomushi, Game::EnemyTypeID::EnemyID_Imomushi },
	{ TEnemyZukan::Zukan_ElecBug, Game::EnemyTypeID::EnemyID_ElecBug },
	{ TEnemyZukan::Zukan_TamagoMushi, Game::EnemyTypeID::EnemyID_OrangPom },
	{ TEnemyZukan::Zukan_Jigumo, Game::EnemyTypeID::EnemyID_Jigumo },
	{ TEnemyZukan::Zukan_Sarai, Game::EnemyTypeID::EnemyID_Sarai },
	{ TEnemyZukan::Zukan_Demon, Game::EnemyTypeID::EnemyID_Demon },
	{ TEnemyZukan::Zukan_BombSarai, Game::EnemyTypeID::EnemyID_BombSarai },
	{ TEnemyZukan::Zukan_Fuefuki, Game::EnemyTypeID::EnemyID_Fuefuki },
	{ TEnemyZukan::Zukan_FireOtakara, Game::EnemyTypeID::EnemyID_FireOtakara },
	{ TEnemyZukan::Zukan_ElecOtakara, Game::EnemyTypeID::EnemyID_ElecOtakara },
	{ TEnemyZukan::Zukan_WaterOtakara, Game::EnemyTypeID::EnemyID_WaterOtakara },
	{ TEnemyZukan::Zukan_GasOtakara, Game::EnemyTypeID::EnemyID_GasOtakara },
	{ TEnemyZukan::Zukan_BombOtakara, Game::EnemyTypeID::EnemyID_BombOtakara },
	{ TEnemyZukan::Zukan_UmiMushiBlind, Game::EnemyTypeID::EnemyID_UmiMushiBlind },
	{ TEnemyZukan::Zukan_Frog, Game::EnemyTypeID::EnemyID_Frog },
	{ TEnemyZukan::Zukan_MaroFrog, Game::EnemyTypeID::EnemyID_MaroFrog },
	{ TEnemyZukan::Zukan_Tadpole, Game::EnemyTypeID::EnemyID_Tadpole },
	{ TEnemyZukan::Zukan_OniKurage, Game::EnemyTypeID::EnemyID_OniKurage },
	{ TEnemyZukan::Zukan_Kurage, Game::EnemyTypeID::EnemyID_Kurage },
	{ TEnemyZukan::Zukan_PelPlant, Game::EnemyTypeID::EnemyID_Pelplant },
	{ TEnemyZukan::Zukan_BluePom, Game::EnemyTypeID::EnemyID_BluePom },
	{ TEnemyZukan::Zukan_RedPom, Game::EnemyTypeID::EnemyID_RedPom },
	{ TEnemyZukan::Zukan_YellowPom, Game::EnemyTypeID::EnemyID_YellowPom },
	{ TEnemyZukan::Zukan_BlackPom, Game::EnemyTypeID::EnemyID_BlackPom },
	{ TEnemyZukan::Zukan_WhitePom, Game::EnemyTypeID::EnemyID_WhitePom },
	{ TEnemyZukan::Zukan_RandPom, Game::EnemyTypeID::EnemyID_RandPom },
	{ TEnemyZukan::Zukan_Hana, Game::EnemyTypeID::EnemyID_Hana },
	{ TEnemyZukan::Zukan_Sokkuri, Game::EnemyTypeID::EnemyID_Sokkuri },
	{ TEnemyZukan::Zukan_ShijimiChou, Game::EnemyTypeID::EnemyID_ShijimiChou },
	{ TEnemyZukan::Zukan_Qurione, Game::EnemyTypeID::EnemyID_Qurione },
	{ TEnemyZukan::Zukan_PanModoki, Game::EnemyTypeID::EnemyID_PanModoki },
	{ TEnemyZukan::Zukan_Miulin, Game::EnemyTypeID::EnemyID_Miulin },
	{ TEnemyZukan::Zukan_HikariKinoko, Game::EnemyTypeID::EnemyID_HikariKinoko },
	{ TEnemyZukan::Zukan_Clover, Game::EnemyTypeID::EnemyID_Clover },
	{ TEnemyZukan::Zukan_Ooinu_l, Game::EnemyTypeID::EnemyID_Ooinu_l },
	{ TEnemyZukan::Zukan_Tanpopo, Game::EnemyTypeID::EnemyID_Tanpopo },
	{ TEnemyZukan::Zukan_Watage, Game::EnemyTypeID::EnemyID_Watage },
	{ TEnemyZukan::Zukan_Tukushi, Game::EnemyTypeID::EnemyID_Tukushi },
	{ TEnemyZukan::Zukan_Nekojarashi, Game::EnemyTypeID::EnemyID_Nekojarashi },
	{ TEnemyZukan::Zukan_DaiodoRed, Game::EnemyTypeID::EnemyID_DaiodoRed },
	{ TEnemyZukan::Zukan_Magaret, Game::EnemyTypeID::EnemyID_Magaret },
	{ TEnemyZukan::Zukan_Zenmai, Game::EnemyTypeID::EnemyID_Zenmai },
	{ TEnemyZukan::Zukan_Wakame_l, Game::EnemyTypeID::EnemyID_Wakame_l },
	{ TEnemyZukan::Zukan_KingChappy, Game::EnemyTypeID::EnemyID_KingChappy },
	{ TEnemyZukan::Zukan_Queen, Game::EnemyTypeID::EnemyID_Queen },
	{ TEnemyZukan::Zukan_Damagumo, Game::EnemyTypeID::EnemyID_Damagumo },
	{ TEnemyZukan::Zukan_BigFoot, Game::EnemyTypeID::EnemyID_BigFoot },
	{ TEnemyZukan::Zukan_Houdai, Game::EnemyTypeID::EnemyID_Houdai },
	{ TEnemyZukan::Zukan_BigTreasure, Game::EnemyTypeID::EnemyID_BigTreasure },
	{ TEnemyZukan::Zukan_UmiMushi, Game::EnemyTypeID::EnemyID_UmiMushi },
	{ TEnemyZukan::Zukan_OoPanModoki, Game::EnemyTypeID::EnemyID_OoPanModoki },
	{ TEnemyZukan::Zukan_SnakeCrow, Game::EnemyTypeID::EnemyID_SnakeCrow },
	{ TEnemyZukan::Zukan_SnakeWhole, Game::EnemyTypeID::EnemyID_SnakeWhole },
	{ TEnemyZukan::Zukan_DangoMushi, Game::EnemyTypeID::EnemyID_DangoMushi },
	{ TEnemyZukan::Zukan_BlackMan, Game::EnemyTypeID::EnemyID_BlackMan },
};

TEnemyZukanIndex& TEnemyZukanIndex::getIndexInfo(int index)
{
	TEnemyZukanIndex& data = eIDInfo[0];
	for (int i = 0; i < ENEMY_ZUKAN_COUNT; i++) {
		if (eIDInfo[i].mZukanID == index) {
			return eIDInfo[i];
		}
	}
	return eIDInfo[0];
}

} // namespace Morimura

namespace Game {
namespace SingleGame {

void ZukanState::birthPikiBaby(EnemyTypeID::EEnemyTypeID babyType, int count)
{
	PikiBaby::Mgr* mgr = static_cast<PikiBaby::Mgr*>(generalEnemyMgr->getEnemyMgr(babyType));
	if (mgr == nullptr) {
		return;
	}

	EnemyBirthArg arg;
	arg.m_position = m_currentCreature->getPosition();

	for (int i = 0; i < count; i++) {
		f32 theta = randFloat() * TAU;
		arg.m_position.x += 50.0f * sinf(theta);
		arg.m_position.y += 300.0f;
		arg.m_position.z += 50.0f * cosf(theta);
		
		arg.m_faceDir       = theta;

		PikiBaby::Obj* baby = static_cast<PikiBaby::Obj*>(mgr->birth(arg));
		if (baby == nullptr) {
			continue;
		}

		baby->init(nullptr);

		Vector3f vel = Vector3f(0, -100.f, 0);
		baby->setVelocity(vel);
		baby->m_simVelocity = vel;

		baby->m_FSM->transit(baby, Baby::BABY_Born, nullptr);
	}
}

void ZukanState::createPikiBabyTypes()
{
	switch (m_tekiInfoIndex) {
	case EnemyTypeID::EnemyID_Houdai:
		birthPikiBaby(EnemyTypeID::EnemyID_PikiBabyRed, 10);
		break;
	case EnemyTypeID::EnemyID_DangoMushi:
		birthPikiBaby(EnemyTypeID::EnemyID_PikiBabyBlue, 10);
		break;
	case EnemyTypeID::EnemyID_BigTreasure:
		birthPikiBaby(EnemyTypeID::EnemyID_PikiBabyRed, 5);
		birthPikiBaby(EnemyTypeID::EnemyID_PikiBabyBlue, 5);
		birthPikiBaby(EnemyTypeID::EnemyID_PikiBabyYellow, 5);
		break;
	}
}

} // namespace SingleGame
} // namespace Game
