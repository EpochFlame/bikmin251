#include "Game/gameGenerator.h"
#include "Game/Entities/Pelplant.h"
#include "Game/Entities/Qurione.h"
#include "Game/Entities/Rock.h"
#include "Game/Entities/ElecHiba.h"
#include "Game/PelletBirthBuffer.h"

namespace Game {

#define GENERATOR_CASE(id)                             \
	case id: {                                         \
		m_enemyGenerator = new EnemyGeneratorBase(""); \
		break;                                         \
	}

EnemyGeneratorBase* GenObjectEnemy::createEnemyGenerator()
{
	switch (m_enemyID) {
	case EnemyTypeID::EnemyID_Pelplant:
		m_enemyGenerator = new Pelplant::Generator();
		break;

		GENERATOR_CASE(EnemyTypeID::EnemyID_Kochappy)
		GENERATOR_CASE(EnemyTypeID::EnemyID_BlueKochappy)
		GENERATOR_CASE(EnemyTypeID::EnemyID_YellowKochappy)
		GENERATOR_CASE(EnemyTypeID::EnemyID_Chappy)
		GENERATOR_CASE(EnemyTypeID::EnemyID_BlueChappy)
		GENERATOR_CASE(EnemyTypeID::EnemyID_YellowChappy)
		GENERATOR_CASE(EnemyTypeID::EnemyID_BluePom)
		GENERATOR_CASE(EnemyTypeID::EnemyID_RedPom)
		GENERATOR_CASE(EnemyTypeID::EnemyID_YellowPom)
		GENERATOR_CASE(EnemyTypeID::EnemyID_BlackPom)
		GENERATOR_CASE(EnemyTypeID::EnemyID_WhitePom)
		GENERATOR_CASE(EnemyTypeID::EnemyID_RandPom)
		GENERATOR_CASE(EnemyTypeID::EnemyID_Kogane)
		GENERATOR_CASE(EnemyTypeID::EnemyID_Wealthy)
		GENERATOR_CASE(EnemyTypeID::EnemyID_Fart)
		GENERATOR_CASE(EnemyTypeID::EnemyID_Frog)
		GENERATOR_CASE(EnemyTypeID::EnemyID_MaroFrog)
		GENERATOR_CASE(EnemyTypeID::EnemyID_UjiA)
		GENERATOR_CASE(EnemyTypeID::EnemyID_Tobi)
		GENERATOR_CASE(EnemyTypeID::EnemyID_UjiB)
		GENERATOR_CASE(EnemyTypeID::EnemyID_Armor)

	case EnemyTypeID::EnemyID_Qurione:
		m_enemyGenerator = new Qurione::Generator();
		break;

	case EnemyTypeID::EnemyID_Rock:
		m_enemyGenerator = new Game::Rock::Generator();
		break;

		GENERATOR_CASE(EnemyTypeID::EnemyID_Hiba)
		GENERATOR_CASE(EnemyTypeID::EnemyID_GasHiba)

	case EnemyTypeID::EnemyID_ElecHiba:
		m_enemyGenerator = new Game::ElecHiba::Generator();
		break;

		GENERATOR_CASE(EnemyTypeID::EnemyID_Sarai)
		GENERATOR_CASE(EnemyTypeID::EnemyID_Tank)
		GENERATOR_CASE(EnemyTypeID::EnemyID_Wtank)
		GENERATOR_CASE(EnemyTypeID::EnemyID_Catfish)
		GENERATOR_CASE(EnemyTypeID::EnemyID_Tadpole)
		GENERATOR_CASE(EnemyTypeID::EnemyID_ElecBug)
		GENERATOR_CASE(EnemyTypeID::EnemyID_Mar)
		GENERATOR_CASE(EnemyTypeID::EnemyID_Queen)
		GENERATOR_CASE(EnemyTypeID::EnemyID_Baby)
		GENERATOR_CASE(EnemyTypeID::EnemyID_Demon)
		GENERATOR_CASE(EnemyTypeID::EnemyID_FireChappy)
		GENERATOR_CASE(EnemyTypeID::EnemyID_SnakeCrow)
		GENERATOR_CASE(EnemyTypeID::EnemyID_KumaChappy)
		GENERATOR_CASE(EnemyTypeID::EnemyID_Bomb)
		GENERATOR_CASE(EnemyTypeID::EnemyID_Egg)
		GENERATOR_CASE(EnemyTypeID::EnemyID_PanModoki)
		GENERATOR_CASE(EnemyTypeID::EnemyID_OoPanModoki)
		GENERATOR_CASE(EnemyTypeID::EnemyID_INVALID)
		GENERATOR_CASE(EnemyTypeID::EnemyID_Fuefuki)
		GENERATOR_CASE(EnemyTypeID::EnemyID_Tanpopo)
		GENERATOR_CASE(EnemyTypeID::EnemyID_Watage)
		GENERATOR_CASE(EnemyTypeID::EnemyID_Clover)
		GENERATOR_CASE(EnemyTypeID::EnemyID_HikariKinoko)
		GENERATOR_CASE(EnemyTypeID::EnemyID_Ooinu_s)
		GENERATOR_CASE(EnemyTypeID::EnemyID_KareOoinu_s)
		GENERATOR_CASE(EnemyTypeID::EnemyID_Ooinu_l)
		GENERATOR_CASE(EnemyTypeID::EnemyID_KareOoinu_l)
		GENERATOR_CASE(EnemyTypeID::EnemyID_Wakame_s)
		GENERATOR_CASE(EnemyTypeID::EnemyID_Wakame_l)
		GENERATOR_CASE(EnemyTypeID::EnemyID_Tukushi)
		GENERATOR_CASE(EnemyTypeID::EnemyID_DaiodoRed)
		GENERATOR_CASE(EnemyTypeID::EnemyID_DaiodoGreen)
		GENERATOR_CASE(EnemyTypeID::EnemyID_Magaret)
		GENERATOR_CASE(EnemyTypeID::EnemyID_Nekojarashi)
		GENERATOR_CASE(EnemyTypeID::EnemyID_Chiyogami)
		GENERATOR_CASE(EnemyTypeID::EnemyID_Zenmai)
		GENERATOR_CASE(EnemyTypeID::EnemyID_KingChappy)
		GENERATOR_CASE(EnemyTypeID::EnemyID_Miulin)
		GENERATOR_CASE(EnemyTypeID::EnemyID_Hanachirashi)
		GENERATOR_CASE(EnemyTypeID::EnemyID_Damagumo)
		GENERATOR_CASE(EnemyTypeID::EnemyID_Kurage)
		GENERATOR_CASE(EnemyTypeID::EnemyID_BombSarai)
		GENERATOR_CASE(EnemyTypeID::EnemyID_FireOtakara)
		GENERATOR_CASE(EnemyTypeID::EnemyID_WaterOtakara)
		GENERATOR_CASE(EnemyTypeID::EnemyID_GasOtakara)
		GENERATOR_CASE(EnemyTypeID::EnemyID_ElecOtakara)
		GENERATOR_CASE(EnemyTypeID::EnemyID_BombOtakara)
		GENERATOR_CASE(EnemyTypeID::EnemyID_Jigumo)
		GENERATOR_CASE(EnemyTypeID::EnemyID_INVALID2)
		GENERATOR_CASE(EnemyTypeID::EnemyID_Imomushi)
		GENERATOR_CASE(EnemyTypeID::EnemyID_Houdai)
		GENERATOR_CASE(EnemyTypeID::EnemyID_LeafChappy)
		GENERATOR_CASE(EnemyTypeID::EnemyID_OrangPom)
		GENERATOR_CASE(EnemyTypeID::EnemyID_BigFoot)
		GENERATOR_CASE(EnemyTypeID::EnemyID_SnakeWhole)
		GENERATOR_CASE(EnemyTypeID::EnemyID_UmiMushi)
		GENERATOR_CASE(EnemyTypeID::EnemyID_UmiMushiBlind)
		GENERATOR_CASE(EnemyTypeID::EnemyID_OniKurage)
		GENERATOR_CASE(EnemyTypeID::EnemyID_BigTreasure)
		GENERATOR_CASE(EnemyTypeID::EnemyID_Kabuto)
		GENERATOR_CASE(EnemyTypeID::EnemyID_Rkabuto)
		GENERATOR_CASE(EnemyTypeID::EnemyID_Fkabuto)
		GENERATOR_CASE(EnemyTypeID::EnemyID_KumaKochappy)
		GENERATOR_CASE(EnemyTypeID::EnemyID_ShijimiChou)
		GENERATOR_CASE(EnemyTypeID::EnemyID_MiniHoudai)
		GENERATOR_CASE(EnemyTypeID::EnemyID_FminiHoudai)
		GENERATOR_CASE(EnemyTypeID::EnemyID_Sokkuri)
		GENERATOR_CASE(EnemyTypeID::EnemyID_Hana)
		GENERATOR_CASE(EnemyTypeID::EnemyID_BlackMan)
		GENERATOR_CASE(EnemyTypeID::EnemyID_Tyre)
		GENERATOR_CASE(EnemyTypeID::EnemyID_DangoMushi)

	case EnemyTypeID::EnemyID_Pom:
	case EnemyTypeID::EnemyID_PanHouse:
	case EnemyTypeID::EnemyID_UmiMushiBase:
	case EnemyTypeID::EnemyID_Stone:
	default:
		m_enemyGenerator = new EnemyGeneratorBase("");
		break;
	}

	return m_enemyGenerator;
}

} // namespace Game