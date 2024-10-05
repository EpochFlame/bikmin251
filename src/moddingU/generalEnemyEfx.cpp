#include "efx/TEnemyPiyo.h"
#include "efx/TEnemyPoison.h"
#include "efx/TSekika.h"
#include "efx/TEnemyDead.h"
#include "efx/TEnemyWalkSmoke.h"
#include "efx/TEnemyDownSmoke.h"
#include "efx/TEnemyDownWat.h"
#include "efx/TEnemyDive.h"
#include "efx/TEnemyBomb.h"
#include "efx/TEnemyApsmoke.h"
#include "efx/TEnemyHamon.h"

namespace efx {

bool TEnemyPiyo::create(Arg* arg)
{
	bool nameCheck = strcmp("ArgEnemyType", arg->getName()) == 0;
	P2ASSERTLINE(17, nameCheck);

	ArgEnemyType* argt = static_cast<ArgEnemyType*>(arg);

	bool docreate;
	f32 scale;
	switch (argt->m_typeID) {
	case Game::EnemyTypeID::EnemyID_Chappy:
	case Game::EnemyTypeID::EnemyID_BlueChappy:
	case Game::EnemyTypeID::EnemyID_YellowChappy:
	case Game::EnemyTypeID::EnemyID_KumaChappy:
		scale = 1.75f;
		break;

	case Game::EnemyTypeID::EnemyID_Kochappy:
	case Game::EnemyTypeID::EnemyID_BlueKochappy:
	case Game::EnemyTypeID::EnemyID_YellowKochappy:
	case Game::EnemyTypeID::EnemyID_KumaKochappy:
		scale = 0.65f;
		break;

	case Game::EnemyTypeID::EnemyID_LeafChappy:
		scale = 0.96f;
		break;

	case Game::EnemyTypeID::EnemyID_FireChappy:
		scale = 1.9f;
		break;

	case Game::EnemyTypeID::EnemyID_Baby:
	case Game::EnemyTypeID::EnemyID_PikiBabyRed:
	case Game::EnemyTypeID::EnemyID_PikiBabyYellow:
	case Game::EnemyTypeID::EnemyID_PikiBabyBlue:
		scale = 0.6f;
		break;

	case Game::EnemyTypeID::EnemyID_Tank:
	case Game::EnemyTypeID::EnemyID_Wtank:
		scale = 0.88f;
		break;

	case Game::EnemyTypeID::EnemyID_Frog:
		scale = 1.0f;
		break;

	case Game::EnemyTypeID::EnemyID_MaroFrog:
		scale = 0.93f;
		break;

	case Game::EnemyTypeID::EnemyID_Tadpole:
		scale = 0.53f;
		break;

	case Game::EnemyTypeID::EnemyID_Sarai:
	case Game::EnemyTypeID::EnemyID_Demon:
		scale = 0.78f;
		break;

	case Game::EnemyTypeID::EnemyID_BombSarai:
		scale = 0.75f;
		break;

	case Game::EnemyTypeID::EnemyID_ElecBug:
		docreate = false;
		return docreate;

	case Game::EnemyTypeID::EnemyID_Catfish:
		scale = 1.1f;
		break;

	case Game::EnemyTypeID::EnemyID_UjiA:
	case Game::EnemyTypeID::EnemyID_UjiB:
	case Game::EnemyTypeID::EnemyID_Tobi:
		scale = 0.45f;
		break;

	case Game::EnemyTypeID::EnemyID_Qurione:
		docreate = false;
		return docreate;

	case Game::EnemyTypeID::EnemyID_Egg:
		docreate = false;
		return docreate;

	case Game::EnemyTypeID::EnemyID_Armor:
		scale = 1.15f;
		break;

	case Game::EnemyTypeID::EnemyID_PanModoki:
		scale = 0.8f;
		break;

	case Game::EnemyTypeID::EnemyID_Miulin:
		scale = 1.25f;
		break;

	case Game::EnemyTypeID::EnemyID_Imomushi:
		scale = 0.62f;
		break;

	case Game::EnemyTypeID::EnemyID_OrangPom:
		docreate = false;
		return docreate;

	case Game::EnemyTypeID::EnemyID_Jigumo:
		scale = 0.75f;
		break;

	case Game::EnemyTypeID::EnemyID_FireOtakara:
	case Game::EnemyTypeID::EnemyID_WaterOtakara:
	case Game::EnemyTypeID::EnemyID_GasOtakara:
	case Game::EnemyTypeID::EnemyID_ElecOtakara:
		scale = 0.65f;
		break;

	case Game::EnemyTypeID::EnemyID_Fuefuki:
		scale = 0.77f;
		break;

	case Game::EnemyTypeID::EnemyID_Mar:
		scale = 0.21f;
		break;

	case Game::EnemyTypeID::EnemyID_Hanachirashi:
		scale = 1.35f;
		break;

	case Game::EnemyTypeID::EnemyID_Kurage:
		scale = 1.3f;
		break;

	case Game::EnemyTypeID::EnemyID_OniKurage:
		scale = 1.9f;
		break;

	case Game::EnemyTypeID::EnemyID_ShijimiChou:
		scale = 0.65f;
		break;

	case Game::EnemyTypeID::EnemyID_SnakeCrow:
		docreate = false;
		return docreate;

	case Game::EnemyTypeID::EnemyID_SnakeWhole:
		scale = 1.25f;
		break;

	case Game::EnemyTypeID::EnemyID_KingChappy:
		scale = 2.15f;
		break;

	case Game::EnemyTypeID::EnemyID_MiniHoudai:
	case Game::EnemyTypeID::EnemyID_FminiHoudai:
		scale = 1.45f;
		break;

	case Game::EnemyTypeID::EnemyID_Hana:
		scale = 1.45f;
		break;

	case Game::EnemyTypeID::EnemyID_Kabuto:
	case Game::EnemyTypeID::EnemyID_Rkabuto:
	case Game::EnemyTypeID::EnemyID_Fkabuto:
		scale = 1.4f;
		break;

	case Game::EnemyTypeID::EnemyID_Sokkuri:
		scale = 0.85f;
		break;

	case Game::EnemyTypeID::EnemyID_OoPanModoki:
		scale = 1.55f;
		break;

	case Game::EnemyTypeID::EnemyID_UmiMushi:
		scale = 2.45f;
		break;

	case Game::EnemyTypeID::EnemyID_Kogane:
	case Game::EnemyTypeID::EnemyID_Wealthy:
	case Game::EnemyTypeID::EnemyID_Fart:
		docreate = false;
		return docreate;

	case Game::EnemyTypeID::EnemyID_BombOtakara:
		scale = 0.65f;
		break;

	case Game::EnemyTypeID::EnemyID_BluePom:
	case Game::EnemyTypeID::EnemyID_RedPom:
	case Game::EnemyTypeID::EnemyID_YellowPom:
	case Game::EnemyTypeID::EnemyID_BlackPom:
	case Game::EnemyTypeID::EnemyID_WhitePom:
	case Game::EnemyTypeID::EnemyID_RandPom:
	case Game::EnemyTypeID::EnemyID_Hiba:
	case Game::EnemyTypeID::EnemyID_GasHiba:
	case Game::EnemyTypeID::EnemyID_ElecHiba:
	case Game::EnemyTypeID::EnemyID_Bomb:
	case Game::EnemyTypeID::EnemyID_DangoMushi:
	case Game::EnemyTypeID::EnemyID_Tyre:
	case Game::EnemyTypeID::EnemyID_BlackMan:
		docreate = false;
		return docreate;

	default:
		docreate = false;
		return docreate;
	}

	scale *= argt->m_scale;

	if (TSync::create(arg)) {
		docreate = true;
		m_emitter->setScaleOnly(scale);
		f32 offs = (scale - 1.0f) * 0.5f + 1.0f;
		volatile Vector3f vec1, vec2; // dumb way to get the stack in here.
		vec1.x = scale;
		vec1.y = scale;
		vec1.z = scale;
		vec2.x = offs;
		vec2.y = offs;
		vec2.z = offs;
		m_emitter->setGlobalScale(offs);

	} else {
		docreate = false;
	}

	return docreate;
}

bool TEnemyDead::create(Arg* arg)
{
	bool docreate;
	bool nameCheck = strcmp("ArgEnemyType", arg->getName()) == 0;
	P2ASSERTLINE(312, nameCheck);

	ArgEnemyType* argt = static_cast<ArgEnemyType*>(arg);

	f32 scale;
	switch (argt->m_typeID) {
	case Game::EnemyTypeID::EnemyID_Chappy:
	case Game::EnemyTypeID::EnemyID_BlueChappy:
	case Game::EnemyTypeID::EnemyID_YellowChappy:
	case Game::EnemyTypeID::EnemyID_KumaChappy:
		scale = 1.8f;
		break;

	case Game::EnemyTypeID::EnemyID_Kochappy:
	case Game::EnemyTypeID::EnemyID_BlueKochappy:
	case Game::EnemyTypeID::EnemyID_YellowKochappy:
	case Game::EnemyTypeID::EnemyID_KumaKochappy:
		scale = 0.85f;
		break;

	case Game::EnemyTypeID::EnemyID_LeafChappy:
		scale = 0.9f;
		break;

	case Game::EnemyTypeID::EnemyID_FireChappy:
		scale = 1.8f;
		break;

	case Game::EnemyTypeID::EnemyID_Baby:
	case Game::EnemyTypeID::EnemyID_PikiBabyRed:
	case Game::EnemyTypeID::EnemyID_PikiBabyYellow:
	case Game::EnemyTypeID::EnemyID_PikiBabyBlue:
		scale = 0.8f;
		break;

	case Game::EnemyTypeID::EnemyID_Tank:
	case Game::EnemyTypeID::EnemyID_Wtank:
		scale = 1.0f;
		break;

	case Game::EnemyTypeID::EnemyID_Frog:
		scale = 1.0f;
		break;

	case Game::EnemyTypeID::EnemyID_MaroFrog:
		scale = 1.0f;
		break;

	case Game::EnemyTypeID::EnemyID_Tadpole:
		scale = 0.75f;
		break;

	case Game::EnemyTypeID::EnemyID_Sarai:
	case Game::EnemyTypeID::EnemyID_Demon:
		scale = 0.9f;
		break;

	case Game::EnemyTypeID::EnemyID_BombSarai:
		scale = 1.35f;
		break;

	case Game::EnemyTypeID::EnemyID_ElecBug:
		scale = 0.9f;
		break;

	case Game::EnemyTypeID::EnemyID_Catfish:
		scale = 1.3f;
		break;

	case Game::EnemyTypeID::EnemyID_UjiA:
	case Game::EnemyTypeID::EnemyID_UjiB:
	case Game::EnemyTypeID::EnemyID_Tobi:
		scale = 0.6f;
		break;

	case Game::EnemyTypeID::EnemyID_Qurione:
		scale = 0.6f;
		break;

	case Game::EnemyTypeID::EnemyID_Egg:
		docreate = false;
		return docreate;

	case Game::EnemyTypeID::EnemyID_Armor:
		scale = 1.45f;
		break;

	case Game::EnemyTypeID::EnemyID_PanModoki:
		scale = 0.95f;
		break;

	case Game::EnemyTypeID::EnemyID_Miulin:
		scale = 1.5f;
		break;

	case Game::EnemyTypeID::EnemyID_Imomushi:
		docreate = false;
		return docreate;

	case Game::EnemyTypeID::EnemyID_OrangPom:
		scale = 0.7f;
		break;

	case Game::EnemyTypeID::EnemyID_Jigumo:
		scale = 1.0f;
		break;

	case Game::EnemyTypeID::EnemyID_FireOtakara:
	case Game::EnemyTypeID::EnemyID_WaterOtakara:
	case Game::EnemyTypeID::EnemyID_GasOtakara:
	case Game::EnemyTypeID::EnemyID_ElecOtakara:
		scale = 0.7f;
		break;

	case Game::EnemyTypeID::EnemyID_Fuefuki:
		scale = 0.85f;
		break;

	case Game::EnemyTypeID::EnemyID_Mar:
	case Game::EnemyTypeID::EnemyID_Hanachirashi:
	case Game::EnemyTypeID::EnemyID_Kurage:
	case Game::EnemyTypeID::EnemyID_OniKurage:
		docreate = false;
		return docreate;

	case Game::EnemyTypeID::EnemyID_ShijimiChou: // unused due to bug in Game::ShijimiChou::StateDead::exec; UjiA is used instead
		scale = 0.55f;
		break;

	case Game::EnemyTypeID::EnemyID_SnakeCrow:
		scale = 1.5f;
		break;

	case Game::EnemyTypeID::EnemyID_SnakeWhole:
		scale = 1.5f;
		break;

	case Game::EnemyTypeID::EnemyID_KingChappy:
		scale = 2.0f;
		break;

	case Game::EnemyTypeID::EnemyID_MiniHoudai:
	case Game::EnemyTypeID::EnemyID_FminiHoudai:
		scale = 1.6f;
		break;

	case Game::EnemyTypeID::EnemyID_Hana:
		scale = 1.45f;
		break;

	case Game::EnemyTypeID::EnemyID_Kabuto:
	case Game::EnemyTypeID::EnemyID_Rkabuto:
	case Game::EnemyTypeID::EnemyID_Fkabuto:
		scale = 1.5f;
		break;

	case Game::EnemyTypeID::EnemyID_Sokkuri:
		scale = 0.9f;
		break;

	case Game::EnemyTypeID::EnemyID_OoPanModoki:
		scale = 1.7f;
		break;

	case Game::EnemyTypeID::EnemyID_UmiMushi:
		docreate = false;
		return docreate;

	case Game::EnemyTypeID::EnemyID_Kogane:
	case Game::EnemyTypeID::EnemyID_Wealthy:
	case Game::EnemyTypeID::EnemyID_Fart:
		scale = 0.94f;
		break;

	case Game::EnemyTypeID::EnemyID_BombOtakara:
		scale = 0.7f;
		break;

	case Game::EnemyTypeID::EnemyID_Tyre:
	case Game::EnemyTypeID::EnemyID_BlackMan:
		docreate = false;
		return docreate;

	case Game::EnemyTypeID::EnemyID_DangoMushi:
		scale = 2.5f;
		break;

	case Game::EnemyTypeID::EnemyID_BluePom:
	case Game::EnemyTypeID::EnemyID_RedPom:
	case Game::EnemyTypeID::EnemyID_YellowPom:
	case Game::EnemyTypeID::EnemyID_BlackPom:
	case Game::EnemyTypeID::EnemyID_WhitePom:
	case Game::EnemyTypeID::EnemyID_RandPom:
	case Game::EnemyTypeID::EnemyID_Hiba:
	case Game::EnemyTypeID::EnemyID_GasHiba:
	case Game::EnemyTypeID::EnemyID_ElecHiba:
	case Game::EnemyTypeID::EnemyID_Bomb:
		docreate = false;
		return docreate;

	default:
		docreate = false;
		return docreate;
	}

	scale *= argt->m_scale;

	if (TSimple1::create(arg)) {
		docreate = true;
		volatile Vector3f scaleVec; // dumb.
		scaleVec.x = scale;
		scaleVec.y = scale;
		scaleVec.z = scale;
		m_emitters[0]->setScale(scale);
	} else {
		docreate = false;
	}
	return docreate;
}

bool TEnemyWalkSmoke::create(Arg* arg)
{
	int isSmall;
	bool nameCheck = strcmp("ArgEnemyType", arg->getName()) == 0;
	P2ASSERTLINE(491, nameCheck);

	ArgEnemyType* argt = static_cast<ArgEnemyType*>(arg);
	Vector3f pos       = arg->m_position;

	f32 scale;
	switch (argt->m_typeID) {
	case Game::EnemyTypeID::EnemyID_Chappy:
	case Game::EnemyTypeID::EnemyID_BlueChappy:
	case Game::EnemyTypeID::EnemyID_YellowChappy:
	case Game::EnemyTypeID::EnemyID_KumaChappy:
		scale   = 1.4f;
		isSmall = false;
		break;

	case Game::EnemyTypeID::EnemyID_Kochappy:
	case Game::EnemyTypeID::EnemyID_BlueKochappy:
	case Game::EnemyTypeID::EnemyID_YellowKochappy:
	case Game::EnemyTypeID::EnemyID_KumaKochappy:
		scale   = 1.0f;
		isSmall = true;
		break;

	case Game::EnemyTypeID::EnemyID_LeafChappy:
		scale   = 0.6f;
		isSmall = false;
		break;

	case Game::EnemyTypeID::EnemyID_FireChappy:
		scale   = 1.4f;
		isSmall = false;
		break;

	case Game::EnemyTypeID::EnemyID_Baby:
		return false;
		
	case Game::EnemyTypeID::EnemyID_PikiBabyRed:
	case Game::EnemyTypeID::EnemyID_PikiBabyYellow:
	case Game::EnemyTypeID::EnemyID_PikiBabyBlue:
		scale   = 0.75f;
		isSmall = true;
		break;

	case Game::EnemyTypeID::EnemyID_Tank:
	case Game::EnemyTypeID::EnemyID_Wtank:
		scale   = 1.0f;
		isSmall = true;
		break;

	case Game::EnemyTypeID::EnemyID_Frog:
		return false;

	case Game::EnemyTypeID::EnemyID_MaroFrog:
		return false;

	case Game::EnemyTypeID::EnemyID_Tadpole:
		return false;

	case Game::EnemyTypeID::EnemyID_Sarai:
	case Game::EnemyTypeID::EnemyID_Demon:
		return false;

	case Game::EnemyTypeID::EnemyID_BombSarai:
		return false;

	case Game::EnemyTypeID::EnemyID_ElecBug:
		return false;

	case Game::EnemyTypeID::EnemyID_Catfish:
		return false;

	case Game::EnemyTypeID::EnemyID_UjiA:
	case Game::EnemyTypeID::EnemyID_UjiB:
	case Game::EnemyTypeID::EnemyID_Tobi:
		return false;

	case Game::EnemyTypeID::EnemyID_Qurione:
		return false;

	case Game::EnemyTypeID::EnemyID_Egg:
		return false;

	case Game::EnemyTypeID::EnemyID_Armor:
		return false;

	case Game::EnemyTypeID::EnemyID_PanModoki:
		scale   = 1.3f;
		isSmall = true;
		break;

	case Game::EnemyTypeID::EnemyID_Miulin:
		scale   = 0.9f;
		isSmall = false;
		break;

	case Game::EnemyTypeID::EnemyID_Imomushi:
		return false;

	case Game::EnemyTypeID::EnemyID_OrangPom:
		return false;

	case Game::EnemyTypeID::EnemyID_Jigumo:
		return false;

	case Game::EnemyTypeID::EnemyID_FireOtakara:
	case Game::EnemyTypeID::EnemyID_WaterOtakara:
	case Game::EnemyTypeID::EnemyID_GasOtakara:
	case Game::EnemyTypeID::EnemyID_ElecOtakara:
		scale   = 1.3f;
		isSmall = true;
		break;

	case Game::EnemyTypeID::EnemyID_Fuefuki:
		scale   = 1.5f;
		isSmall = true;
		break;

	case Game::EnemyTypeID::EnemyID_Mar:
	case Game::EnemyTypeID::EnemyID_SnakeCrow:
	case Game::EnemyTypeID::EnemyID_Hanachirashi:
	case Game::EnemyTypeID::EnemyID_Kurage:
	case Game::EnemyTypeID::EnemyID_SnakeWhole:
	case Game::EnemyTypeID::EnemyID_OniKurage:
	case Game::EnemyTypeID::EnemyID_ShijimiChou:
		return false;

	case Game::EnemyTypeID::EnemyID_KingChappy:
		scale   = 1.25f;
		isSmall = false;
		break;

	case Game::EnemyTypeID::EnemyID_MiniHoudai:
	case Game::EnemyTypeID::EnemyID_FminiHoudai:
		scale   = 1.0f;
		isSmall = false;
		break;

	case Game::EnemyTypeID::EnemyID_Hana:
		scale   = 1.6f;
		isSmall = true;
		break;

	case Game::EnemyTypeID::EnemyID_Kabuto:
	case Game::EnemyTypeID::EnemyID_Rkabuto:
	case Game::EnemyTypeID::EnemyID_Fkabuto:
		scale   = 1.6f;
		isSmall = true;
		break;

	case Game::EnemyTypeID::EnemyID_Sokkuri:
		return false;

	case Game::EnemyTypeID::EnemyID_OoPanModoki:
		scale   = 1.0f;
		isSmall = false;
		break;

	case Game::EnemyTypeID::EnemyID_Kogane:
	case Game::EnemyTypeID::EnemyID_Wealthy:
	case Game::EnemyTypeID::EnemyID_Fart:
	case Game::EnemyTypeID::EnemyID_UmiMushi:
		return false;

	case Game::EnemyTypeID::EnemyID_BombOtakara:
		scale   = 1.3f;
		isSmall = true;
		break;

	case Game::EnemyTypeID::EnemyID_BlackMan:
		scale   = 1.0;
		isSmall = false;
		break;

	case Game::EnemyTypeID::EnemyID_Tyre:
		return false;

	case Game::EnemyTypeID::EnemyID_DangoMushi:
		scale   = 1.35f;
		isSmall = false;
		break;

	case Game::EnemyTypeID::EnemyID_BluePom:
	case Game::EnemyTypeID::EnemyID_RedPom:
	case Game::EnemyTypeID::EnemyID_YellowPom:
	case Game::EnemyTypeID::EnemyID_BlackPom:
	case Game::EnemyTypeID::EnemyID_WhitePom:
	case Game::EnemyTypeID::EnemyID_RandPom:
	case Game::EnemyTypeID::EnemyID_Hiba:
	case Game::EnemyTypeID::EnemyID_GasHiba:
	case Game::EnemyTypeID::EnemyID_ElecHiba:
	case Game::EnemyTypeID::EnemyID_Bomb:
		return false;

	default:
		return false;
	}

	scale *= argt->m_scale;
	ArgScale args(pos, scale);
	if (isSmall == 0) {
		TEnemyWalkSmokeM effect(0x05A);
		return effect.create(&args);
	} else if (isSmall == 1) {
		TEnemyWalkSmokeS effect(0x059);
		return effect.create(&args);
	} else {
		return false;
	}
}

TEnemyBombScaleTable::TEnemyBombScaleTable(Game::EnemyTypeID::EEnemyTypeID id)
{
	switch (id) {
	case Game::EnemyTypeID::EnemyID_Chappy:
	case Game::EnemyTypeID::EnemyID_BlueChappy:
	case Game::EnemyTypeID::EnemyID_YellowChappy:
	case Game::EnemyTypeID::EnemyID_KumaChappy:
		mType  = 1;
		mScale = 0.92f;
		break;

	case Game::EnemyTypeID::EnemyID_Kochappy:
	case Game::EnemyTypeID::EnemyID_BlueKochappy:
	case Game::EnemyTypeID::EnemyID_YellowKochappy:
	case Game::EnemyTypeID::EnemyID_KumaKochappy:
		mType  = 2;
		mScale = 1.4f;
		break;

	case Game::EnemyTypeID::EnemyID_LeafChappy:
		mType  = 2;
		mScale = 1.65f;
		break;

	case Game::EnemyTypeID::EnemyID_FireChappy:
		mType  = 1;
		mScale = 0.92f;
		break;

	case Game::EnemyTypeID::EnemyID_Baby:
	case Game::EnemyTypeID::EnemyID_PikiBabyRed:
	case Game::EnemyTypeID::EnemyID_PikiBabyYellow:
	case Game::EnemyTypeID::EnemyID_PikiBabyBlue:
		mType  = 2;
		mScale = 1.0f;
		break;

	case Game::EnemyTypeID::EnemyID_Tank:
	case Game::EnemyTypeID::EnemyID_Wtank:
		mType  = 1;
		mScale = 0.6f;
		break;

	case Game::EnemyTypeID::EnemyID_Frog:
		mType  = 1;
		mScale = 0.7f;
		break;
	case Game::EnemyTypeID::EnemyID_MaroFrog:
		mType  = 1;
		mScale = 0.6f;
		break;

	case Game::EnemyTypeID::EnemyID_Tadpole:
		mType  = 2;
		mScale = 1.2f;
		break;

	case Game::EnemyTypeID::EnemyID_Sarai:
	case Game::EnemyTypeID::EnemyID_Demon:
		mType  = 1;
		mScale = 0.65f;
		break;

	case Game::EnemyTypeID::EnemyID_BombSarai:
		mType  = 1;
		mScale = 0.8f;
		break;

	case Game::EnemyTypeID::EnemyID_ElecBug:
		mType  = 1;
		mScale = 0.65f;
		break;

	case Game::EnemyTypeID::EnemyID_Catfish:
		mType  = 1;
		mScale = 0.75f;
		break;

	case Game::EnemyTypeID::EnemyID_UjiA:
	case Game::EnemyTypeID::EnemyID_UjiB:
	case Game::EnemyTypeID::EnemyID_Tobi:
		mType  = 2;
		mScale = 1.0f;
		break;

	case Game::EnemyTypeID::EnemyID_Qurione:
		mType  = 2;
		mScale = 1.1f;
		break;

	case Game::EnemyTypeID::EnemyID_Egg:
		mType  = 2;
		mScale = 1.5f;
		break;

	case Game::EnemyTypeID::EnemyID_Armor:
		mType  = 1;
		mScale = 0.85f;
		break;

	case Game::EnemyTypeID::EnemyID_PanModoki:
		mType  = 2;
		mScale = 1.6f;
		break;

	case Game::EnemyTypeID::EnemyID_Miulin:
		mType  = 1;
		mScale = 0.8f;
		break;

	case Game::EnemyTypeID::EnemyID_Imomushi:
		mType  = 0;
		mScale = 0.0f;
		break;

	case Game::EnemyTypeID::EnemyID_OrangPom:
		mType  = 2;
		mScale = 1.2f;
		break;

	case Game::EnemyTypeID::EnemyID_Jigumo:
		mType  = 2;
		mScale = 1.5f;
		break;

	case Game::EnemyTypeID::EnemyID_FireOtakara:
	case Game::EnemyTypeID::EnemyID_WaterOtakara:
	case Game::EnemyTypeID::EnemyID_GasOtakara:
	case Game::EnemyTypeID::EnemyID_ElecOtakara:
		mType  = 2;
		mScale = 1.3f;
		break;

	case Game::EnemyTypeID::EnemyID_Fuefuki:
		mType  = 2;
		mScale = 1.4f;
		break;

	case Game::EnemyTypeID::EnemyID_Mar:
		mType  = 1;
		mScale = 1.2f;
		break;

	case Game::EnemyTypeID::EnemyID_Hanachirashi:
		mType  = 1;
		mScale = 0.72f;
		break;

	case Game::EnemyTypeID::EnemyID_Kurage:
		mType  = 1;
		mScale = 0.7f;
		break;

	case Game::EnemyTypeID::EnemyID_OniKurage:
		mType  = 1;
		mScale = 0.9f;
		break;

	case Game::EnemyTypeID::EnemyID_ShijimiChou:
		mType  = 2;
		mScale = 0.9f;
		break;

	case Game::EnemyTypeID::EnemyID_SnakeCrow:
	case Game::EnemyTypeID::EnemyID_SnakeWhole:
		mType  = 0;
		mScale = 0.0f;
		break;

	case Game::EnemyTypeID::EnemyID_KingChappy:
		mType  = 1;
		mScale = 1.25f;
		break;

	case Game::EnemyTypeID::EnemyID_MiniHoudai:
	case Game::EnemyTypeID::EnemyID_FminiHoudai:
		mType  = 1;
		mScale = 0.85f;
		break;

	case Game::EnemyTypeID::EnemyID_Hana:
		mType  = 1;
		mScale = 0.9f;
		break;

	case Game::EnemyTypeID::EnemyID_Kabuto:
	case Game::EnemyTypeID::EnemyID_Rkabuto:
	case Game::EnemyTypeID::EnemyID_Fkabuto:
		mType  = 1;
		mScale = 0.8f;
		break;

	case Game::EnemyTypeID::EnemyID_Sokkuri:
		mType  = 2;
		mScale = 1.4f;
		break;

	case Game::EnemyTypeID::EnemyID_OoPanModoki:
		mType  = 1;
		mScale = 0.85f;
		break;

	case Game::EnemyTypeID::EnemyID_UmiMushi:
		mType  = 1;
		mScale = 1.2f;
		break;

	case Game::EnemyTypeID::EnemyID_Kogane:
	case Game::EnemyTypeID::EnemyID_Wealthy:
	case Game::EnemyTypeID::EnemyID_Fart:
		mType  = 2;
		mScale = 1.25f;
		break;

	case Game::EnemyTypeID::EnemyID_BombOtakara:
		mType  = 2;
		mScale = 1.3f;
		break;

	case Game::EnemyTypeID::EnemyID_BlackMan:
		mType  = 1;
		mScale = 0.75f;
		break;

	case Game::EnemyTypeID::EnemyID_Tyre:
		mType  = 0;
		mScale = 0.0f;
		break;

	case Game::EnemyTypeID::EnemyID_DangoMushi:
		mType  = 1;
		mScale = 1.45f;
		break;

	case Game::EnemyTypeID::EnemyID_Hiba:
	case Game::EnemyTypeID::EnemyID_GasHiba:
	case Game::EnemyTypeID::EnemyID_ElecHiba:
		mType  = 2;
		mScale = 1.0f;
		break;

	case Game::EnemyTypeID::EnemyID_BluePom:
	case Game::EnemyTypeID::EnemyID_RedPom:
	case Game::EnemyTypeID::EnemyID_YellowPom:
	case Game::EnemyTypeID::EnemyID_BlackPom:
	case Game::EnemyTypeID::EnemyID_WhitePom:
	case Game::EnemyTypeID::EnemyID_RandPom:
		mType  = 1;
		mScale = 1.0f;
		break;

	case Game::EnemyTypeID::EnemyID_Bomb:
		mType  = 1;
		mScale = 0.65f;
		break;

	default:
		mType  = 0;
		mScale = 0.0f;
		break;
	}
}

bool TEnemyHamonChasePos::create(Arg* arg)
{
	bool nameCheck = strcmp("ArgEnemyType", arg->getName()) == 0;
	P2ASSERTLINE(1136, nameCheck);

	ArgEnemyType* argt = static_cast<ArgEnemyType*>(arg);

	Vector3f pos = arg->m_position;

	bool docreate;
	f32 scale;
	switch (argt->m_typeID) {
	case Game::EnemyTypeID::EnemyID_Chappy:
	case Game::EnemyTypeID::EnemyID_BlueChappy:
	case Game::EnemyTypeID::EnemyID_YellowChappy:
	case Game::EnemyTypeID::EnemyID_KumaChappy:
		scale = 1.3f;
		break;

	case Game::EnemyTypeID::EnemyID_Kochappy:
	case Game::EnemyTypeID::EnemyID_BlueKochappy:
	case Game::EnemyTypeID::EnemyID_YellowKochappy:
	case Game::EnemyTypeID::EnemyID_KumaKochappy:
		scale = 0.45f;
		break;

	case Game::EnemyTypeID::EnemyID_LeafChappy:
		scale = 0.75f;
		break;

	case Game::EnemyTypeID::EnemyID_FireChappy:
		scale = 1.3f;
		break;

	case Game::EnemyTypeID::EnemyID_Baby:
	case Game::EnemyTypeID::EnemyID_PikiBabyRed:
	case Game::EnemyTypeID::EnemyID_PikiBabyYellow:
	case Game::EnemyTypeID::EnemyID_PikiBabyBlue:
		scale = 0.65f;
		break;

	case Game::EnemyTypeID::EnemyID_Tank:
	case Game::EnemyTypeID::EnemyID_Wtank:
		scale = 0.8f;
		break;

	case Game::EnemyTypeID::EnemyID_Frog:
		scale = 1.00f;
		break;

	case Game::EnemyTypeID::EnemyID_MaroFrog:
		scale = 1.0f;
		break;

	case Game::EnemyTypeID::EnemyID_Tadpole:
		scale = 0.55f;
		break;

	case Game::EnemyTypeID::EnemyID_Sarai:
	case Game::EnemyTypeID::EnemyID_Demon:
		scale = 0.9f;
		break;

	case Game::EnemyTypeID::EnemyID_BombSarai:
		scale = 1.4f;
		break;

	case Game::EnemyTypeID::EnemyID_ElecBug:
		scale = 0.9f;
		break;

	case Game::EnemyTypeID::EnemyID_Catfish:
		scale = 1.0f;
		break;

	case Game::EnemyTypeID::EnemyID_UjiA:
	case Game::EnemyTypeID::EnemyID_UjiB:
	case Game::EnemyTypeID::EnemyID_Tobi:
		scale = 0.45f;
		break;

	case Game::EnemyTypeID::EnemyID_Qurione:
		docreate = false;
		return docreate;

	case Game::EnemyTypeID::EnemyID_Egg:
		scale = 0.65f;
		break;

	case Game::EnemyTypeID::EnemyID_Armor:
		scale = 1.4f;
		break;

	case Game::EnemyTypeID::EnemyID_PanModoki:
		scale = 0.8f;
		break;

	case Game::EnemyTypeID::EnemyID_Miulin:
		scale = 1.15f;
		break;

	case Game::EnemyTypeID::EnemyID_Imomushi:
		scale = 0.6f;
		break;

	case Game::EnemyTypeID::EnemyID_OrangPom:
		scale = 0.6f;
		break;

	case Game::EnemyTypeID::EnemyID_Jigumo:
		scale = 0.9f;
		break;

	case Game::EnemyTypeID::EnemyID_FireOtakara:
	case Game::EnemyTypeID::EnemyID_WaterOtakara:
	case Game::EnemyTypeID::EnemyID_GasOtakara:
	case Game::EnemyTypeID::EnemyID_ElecOtakara:
		scale = 1.1f;
		break;

	case Game::EnemyTypeID::EnemyID_Fuefuki:
		scale = 1.0f;
		break;

	case Game::EnemyTypeID::EnemyID_Mar:
		scale = 2.0f;
		break;

	case Game::EnemyTypeID::EnemyID_Hanachirashi:
		scale = 1.5f;
		break;

	case Game::EnemyTypeID::EnemyID_Kurage:
		scale = 1.35f;
		break;

	case Game::EnemyTypeID::EnemyID_OniKurage:
		scale = 2.0f;
		break;

	case Game::EnemyTypeID::EnemyID_ShijimiChou:
		scale = 0.9f;
		break;

	case Game::EnemyTypeID::EnemyID_SnakeCrow:
		scale = 1.3f;
		break;

	case Game::EnemyTypeID::EnemyID_SnakeWhole:
		scale = 1.3f;
		break;

	case Game::EnemyTypeID::EnemyID_KingChappy:
		scale = 1.85f;
		break;

	case Game::EnemyTypeID::EnemyID_MiniHoudai:
	case Game::EnemyTypeID::EnemyID_FminiHoudai:
		scale = 1.35f;
		break;

	case Game::EnemyTypeID::EnemyID_Hana:
		scale = 1.8f;
		break;

	case Game::EnemyTypeID::EnemyID_Kabuto:
	case Game::EnemyTypeID::EnemyID_Rkabuto:
	case Game::EnemyTypeID::EnemyID_Fkabuto:
		scale = 1.3f;
		break;

	case Game::EnemyTypeID::EnemyID_Sokkuri:
		scale = 1.0f;
		break;

	case Game::EnemyTypeID::EnemyID_OoPanModoki:
		scale = 1.35f;
		break;

	case Game::EnemyTypeID::EnemyID_UmiMushi:
		docreate = false;
		return docreate;

	case Game::EnemyTypeID::EnemyID_Kogane:
		scale = 0.75f;
		break;

	case Game::EnemyTypeID::EnemyID_Wealthy:
		scale = 0.7f;
		break;

	case Game::EnemyTypeID::EnemyID_Fart:
		scale = 0.7f;
		break;

	case Game::EnemyTypeID::EnemyID_BombOtakara:
		scale = 1.1f;
		break;

	case Game::EnemyTypeID::EnemyID_BlackMan:
		scale = 1.5f;
		break;

	case Game::EnemyTypeID::EnemyID_Tyre:
		scale = 1.5f;
		break;

	case Game::EnemyTypeID::EnemyID_DangoMushi:
		scale = 2.8f;
		break;

	case Game::EnemyTypeID::EnemyID_BluePom:
	case Game::EnemyTypeID::EnemyID_RedPom:
	case Game::EnemyTypeID::EnemyID_YellowPom:
	case Game::EnemyTypeID::EnemyID_BlackPom:
	case Game::EnemyTypeID::EnemyID_WhitePom:
	case Game::EnemyTypeID::EnemyID_RandPom:
	case Game::EnemyTypeID::EnemyID_Hiba:
	case Game::EnemyTypeID::EnemyID_GasHiba:
	case Game::EnemyTypeID::EnemyID_ElecHiba:
	case Game::EnemyTypeID::EnemyID_Bomb:
		docreate = false;
		return docreate;

	default:
		docreate = false;
		return docreate;
	}

	scale *= argt->m_scale;
	ArgScale arg2(pos, scale);

	if (!m_hamonM.create(&arg2)) {
		return false;
	} else if (scale > 0.75 && !m_hamonMInd.create(&arg2)) {
		return false;
	} else {
		return true;
	}
}
f32 TEnemyHamon::getLimitDepth_()
{
	f32 depth = 10000.0f;

	switch (m_enemyID) {
	case Game::EnemyTypeID::EnemyID_Chappy:
	case Game::EnemyTypeID::EnemyID_KumaChappy:
	case Game::EnemyTypeID::EnemyID_BlueChappy:
	case Game::EnemyTypeID::EnemyID_YellowChappy:
		depth = 80.0f;
		break;

	case Game::EnemyTypeID::EnemyID_Kochappy:
	case Game::EnemyTypeID::EnemyID_BlueKochappy:
	case Game::EnemyTypeID::EnemyID_YellowKochappy:
	case Game::EnemyTypeID::EnemyID_KumaKochappy:
		depth = 27.0f;
		break;

	case Game::EnemyTypeID::EnemyID_LeafChappy:
		depth = 20.0f;
		break;

	case Game::EnemyTypeID::EnemyID_FireChappy:
		depth = 80.0f;
		break;

	case Game::EnemyTypeID::EnemyID_Baby:
	case Game::EnemyTypeID::EnemyID_PikiBabyRed:
	case Game::EnemyTypeID::EnemyID_PikiBabyYellow:
	case Game::EnemyTypeID::EnemyID_PikiBabyBlue:
		depth = 20.0f;
		break;

	case Game::EnemyTypeID::EnemyID_Tank:
	case Game::EnemyTypeID::EnemyID_Wtank:
		depth = 34.0f;
		break;

	case Game::EnemyTypeID::EnemyID_Frog:
		depth = 40.0f;
		break;

	case Game::EnemyTypeID::EnemyID_MaroFrog:
		depth = 30.0f;
		break;

	case Game::EnemyTypeID::EnemyID_Tadpole:
		depth = 17.0f;
		break;

	case Game::EnemyTypeID::EnemyID_Sarai:
	case Game::EnemyTypeID::EnemyID_Demon:
		depth = 40.0f;
		break;

	case Game::EnemyTypeID::EnemyID_BombSarai:
		depth = 110.0f;
		break;

	case Game::EnemyTypeID::EnemyID_ElecBug:
		depth = 27.0f;
		break;

	case Game::EnemyTypeID::EnemyID_Catfish:
		depth = 30.0f;
		break;

	case Game::EnemyTypeID::EnemyID_UjiA:
	case Game::EnemyTypeID::EnemyID_UjiB:
	case Game::EnemyTypeID::EnemyID_Tobi:
		depth = 12.0f;
		break;

	case Game::EnemyTypeID::EnemyID_Egg:
		depth = 26.0f;
		break;

	case Game::EnemyTypeID::EnemyID_Armor:
		depth = 40.0f;
		break;

	case Game::EnemyTypeID::EnemyID_PanModoki:
		depth = 35.0f;
		break;

	case Game::EnemyTypeID::EnemyID_Miulin:
		depth = 60.0f;
		break;

	case Game::EnemyTypeID::EnemyID_Imomushi:
		depth = 15.0f;
		break;

	case Game::EnemyTypeID::EnemyID_OrangPom:
		depth = 20.0f;
		break;

	case Game::EnemyTypeID::EnemyID_Jigumo:
		depth = 40.0f;
		break;

	case Game::EnemyTypeID::EnemyID_FireOtakara:
	case Game::EnemyTypeID::EnemyID_WaterOtakara:
	case Game::EnemyTypeID::EnemyID_GasOtakara:
	case Game::EnemyTypeID::EnemyID_ElecOtakara:
		depth = 45.0f;
		break;

	case Game::EnemyTypeID::EnemyID_Fuefuki:
		depth = 40.0f;
		break;

	case Game::EnemyTypeID::EnemyID_Mar:
		depth = 80.0f;
		break;

	case Game::EnemyTypeID::EnemyID_Hanachirashi:
		depth = 50.0f;
		break;

	case Game::EnemyTypeID::EnemyID_Kurage:
		depth = 60.0f;
		break;

	case Game::EnemyTypeID::EnemyID_OniKurage:
		depth = 100.0f;
		break;

	case Game::EnemyTypeID::EnemyID_ShijimiChou:
		depth = 20.0f;
		break;

	case Game::EnemyTypeID::EnemyID_Kabuto:
	case Game::EnemyTypeID::EnemyID_Fkabuto:
	case Game::EnemyTypeID::EnemyID_Rkabuto:
		depth = 55.0f;
		break;

	case Game::EnemyTypeID::EnemyID_Sokkuri:
		depth = 12.0f;
		break;

	case Game::EnemyTypeID::EnemyID_OoPanModoki:
		depth = 80.0f;
		break;

	case Game::EnemyTypeID::EnemyID_Kogane:
		depth = 20.0f;
		break;

	case Game::EnemyTypeID::EnemyID_Wealthy:
		depth = 15.0f;
		break;

	case Game::EnemyTypeID::EnemyID_Fart:
		depth = 15.0f;
		break;

	case Game::EnemyTypeID::EnemyID_BombOtakara:
		depth = 45.0f;
		break;

	case Game::EnemyTypeID::EnemyID_BluePom:
	case Game::EnemyTypeID::EnemyID_RedPom:
	case Game::EnemyTypeID::EnemyID_YellowPom:
	case Game::EnemyTypeID::EnemyID_BlackPom:
	case Game::EnemyTypeID::EnemyID_WhitePom:
	case Game::EnemyTypeID::EnemyID_RandPom:
	case Game::EnemyTypeID::EnemyID_Qurione:
	case Game::EnemyTypeID::EnemyID_SnakeCrow:
	case Game::EnemyTypeID::EnemyID_SnakeWhole:
	case Game::EnemyTypeID::EnemyID_KingChappy:
	case Game::EnemyTypeID::EnemyID_MiniHoudai:
	case Game::EnemyTypeID::EnemyID_FminiHoudai:
	case Game::EnemyTypeID::EnemyID_Hana:
	case Game::EnemyTypeID::EnemyID_UmiMushi:
	case Game::EnemyTypeID::EnemyID_Tyre:
	case Game::EnemyTypeID::EnemyID_BlackMan:
	case Game::EnemyTypeID::EnemyID_DangoMushi:
		break;
	}

	return depth;
}

} // namespace efx
