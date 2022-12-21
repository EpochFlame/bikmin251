#include "CollInfo.h"
#include "Dolphin/mtx.h"
#include "Game/cellPyramid.h"
#include "Game/Creature.h"
#include "Game/gameGenerator.h"
#include "Game/GameSystem.h"
#include "Game/shadowMgr.h"
#include "IDelegate.h"
#include "JSystem/J3D/J3DModel.h"
#include "ObjectTypes.h"
#include "SysShape/Model.h"
#include "Sys/Sphere.h"
#include "types.h"
#include "Vector3.h"
#include "Game/MapMgr.h"
#include "Game/DeathMgr.h"
#include "Game/CollEvent.h"
#include "nans.h"

namespace Game {

Creature* Creature::currOp;
bool Creature::usePacketCulling = true;

inline void Creature::killInline(Game::CreatureKillArg* arg)
{
	endStick();
	setAlive(false);
	Cell::sCurrCellMgr = cellMgr;
	exitCell();
	Cell::sCurrCellMgr = nullptr;
	m_updateContext.exit();
	releaseAllStickers();
	clearCapture();
	onKill(arg);

	if (m_generator) {
		m_generator->informDeath(this);
		m_generator = nullptr;
	}
}

/*
 * --INFO--
 * Address:	8013AE84
 * Size:	00012C
 */
Creature::Creature()
{
	m_collTree  = nullptr;
	m_model     = nullptr;
	m_mass      = 100.0f;
	m_generator = nullptr;

	m_scale = Vector3f(1.0f);

	PSMTXIdentity(m_mainMatrix.m_matrix.mtxView);

	m_objectTypeID = OBJTYPE_INVALID_START;

	for (int i = 0; i < 4; i++) {
		m_flags.byteView[i] = 0;
	}

	m_flags.typeView |= (CF_IS_ATARI | CF_IS_ALIVE | CF_IS_COLLISION_FLICK);
	clearStick();
}

/*
 * --INFO--
 * Address:	8013AFC8
 * Size:	000120
 */
void Creature::init(CreatureInitArg* arg)
{
	m_cellLayerIndex    = 0;
	m_cellRect.p1.x     = 0;
	m_cellRect.p1.y     = 0;
	m_cellRect.p2.x     = 0;
	m_cellRect.p2.y     = 0;
	m_flags.byteView[0] = 0;
	m_flags.byteView[1] = 0;
	m_flags.byteView[2] = 0;
	m_flags.byteView[3] = 0;
	m_flags.typeView |= (CF_IS_ATARI | CF_IS_ALIVE | CF_IS_COLLISION_FLICK);
	clearStick();

	m_updateContext.init(collisionUpdateMgr);
	m_acceleration = Vector3f(0.0f);
	clearCapture();

	m_curTriangle       = nullptr;
	m_collisionPosition = Vector3f(0.0f, 1.0f, 0.0f);
	clearCapture();

	if (getMabiki()) {
		u32* mabiki = getMabiki();
		mabiki[1]   = 0;
		mabiki[0]   = 0;
	}
	onInit(arg);
	onInitPost(arg);
}

/*
 * --INFO--
 * Address:	8013B0F0
 * Size:	0000B4
 */
void Creature::kill(CreatureKillArg* arg) { killInline(arg); }

/*
 * --INFO--
 * Address:	8013B1A8
 * Size:	0000C8
 */
void Creature::setPosition(Vector3f& position, bool skipPostProc)
{
	onSetPosition(position);

	if (skipPostProc) {
		return;
	}

	updateTrMatrix();

	if (m_model) {
		PSMTXCopy(m_mainMatrix.m_matrix.mtxView, m_model->m_j3dModel->m_posMtx);
		m_model->m_j3dModel->calc();
		if (m_collTree) {
			m_collTree->update();
		}
	}

	onSetPositionPost(position);
}

/*
 * --INFO--
 * Address:	8013B274
 * Size:	0000CC
 */
void Creature::initPosition(Vector3f& position)
{
	onSetPosition(position);
	updateTrMatrix();

	if (m_model) {
		PSMTXCopy(m_mainMatrix.m_matrix.mtxView, m_model->m_j3dModel->m_posMtx);
		m_model->m_j3dModel->calc();
		if (m_collTree) {
			m_collTree->update();
		}
	}

	onSetPositionPost(position);
	onInitPosition(position);
}

/*
 * --INFO--
 * Address:	8013B340
 * Size:	0000A0
 */
void Creature::getYVector(Vector3f& outVector)
{
	outVector.x = m_mainMatrix.m_matrix.structView.yx;
	outVector.y = m_mainMatrix.m_matrix.structView.yy;
	outVector.z = m_mainMatrix.m_matrix.structView.yz;
	outVector.normalise();
}

/*
 * --INFO--
 * Address:	8013B3E0
 * Size:	000034
 */
f32 Creature::getBodyRadius()
{
	Sys::Sphere boundingSphere;
	getBoundingSphere(boundingSphere);
	return boundingSphere.m_radius;
}

/*
 * --INFO--
 * Address:	8013B414
 * Size:	000034
 */
f32 Creature::getCellRadius()
{
	Sys::Sphere boundingSphere;
	getBoundingSphere(boundingSphere);
	return boundingSphere.m_radius;
}

/*
 * --INFO--
 * Address:	8013B448
 * Size:	000024
 */
char* Creature::getTypeName() { return ObjType::getName(m_objectTypeID); }

/*
 * --INFO--
 * Address:	8013B46C
 * Size:	00008C
 */
void Creature::getShadowParam(ShadowParam& param)
{
	param.m_position = getPosition();
	param.m_position.y += 0.5f;
	param.m_boundingSphere.m_radius   = 10.0f;
	param.m_size                      = 4.0f;
	param.m_boundingSphere.m_position = Vector3f(0.0f, 1.0f, 0.0f);
}

/*
 * --INFO--
 * Address:	8013B4F8
 * Size:	00000C
 */
bool Creature::needShadow() { return m_lod.m_flags & AILOD_FLAG_NEED_SHADOW; }

/*
 * --INFO--
 * Address:	8013B504
 * Size:	000070
 */
void Creature::getLifeGaugeParam(LifeGaugeParam& param)
{
	param.m_position         = getPosition();
	param.m_healthPercentage = 1.0f;
	param._10                = 10.0f;
	param._14                = 1;
}

/*
 * --INFO--
 * Address:	8013B574
 * Size:	000090
 */
void Creature::save(Stream& output, u8 flags)
{
	if (flags & 1) {
		Vector3f position = getPosition();
		position.write(output);
	}

	doSave(output);
}

/*
 * --INFO--
 * Address:	8013B604
 * Size:	0000E4
 */
void Creature::load(Stream& input, u8 flags)
{
	if (flags & 1) {
		Vector3f position;
		position.read(input);
		setPosition(position, false);
	}

	doLoad(input);
}

/*
 * --INFO--
 * Address:	8013B6E8
 * Size:	0000BC
 */
f32 Creature::calcSphereDistance(Creature* other)
{
	Sys::Sphere otherBoundSphere;
	other->getBoundingSphere(otherBoundSphere);

	Sys::Sphere srcBoundSphere;
	getBoundingSphere(srcBoundSphere);

	Vector3f seperation = srcBoundSphere.m_position - otherBoundSphere.m_position;
	return _length(seperation) - (srcBoundSphere.m_radius + otherBoundSphere.m_radius);
}

/*
 * --INFO--
 * Address:	8013B7A4
 * Size:	0000CC
 */
void Creature::applyAirDrag(f32 a, f32 b, f32 c)
{
	Vector3f vel = getVelocity();

	vel.y -= c * (a * vel.y);
	vel.x -= (vel.x * (a * b));
	vel.z -= (vel.z * (a * b));

	setVelocity(vel);
}

/*
 * --INFO--
 * Address:	8013B870
 * Size:	00003C
 */
void Creature::doAnimation()
{
	if (m_model) {
		m_model->m_j3dModel->calc();
	}
}

/*
 * --INFO--
 * Address:	8013B8AC
 * Size:	000004
 */
void Creature::doEntry() { }

/*
 * --INFO--
 * Address:	8013B8B0
 * Size:	000108
 */
void Creature::doSetView(int viewportNo)
{
	// 2 viewports maximum (2 player modes)
	P2ASSERTBOUNDSLINE(558, 0, viewportNo, 2);

	if (!m_model) {
		return;
	}

	P2ASSERTLINE(563, m_model);

	m_model->setCurrentViewNo((u16)viewportNo);
	if (Creature::usePacketCulling) {
		if (m_lod.m_flags & (16 << viewportNo)) {
			m_model->showPackets();
			return;
		}

		m_model->hidePackets();
		return;
	}

	m_model->showPackets();
}

/*
 * --INFO--
 * Address:	8013B9B8
 * Size:	00002C
 */
void Creature::doViewCalc()
{
	if (m_model) {
		m_model->viewCalc();
	}
}

/*
 * --INFO--
 * Address:	8013B9E4
 * Size:	000010
 */
bool Creature::isPiki() { return m_objectTypeID == OBJTYPE_Piki; }

/*
 * --INFO--
 * Address:	8013B9F4
 * Size:	000014
 */
bool Creature::isNavi() { return m_objectTypeID == OBJTYPE_Navi; }

/*
 * --INFO--
 * Address:	8013BA08
 * Size:	000014
 */
bool Creature::isTeki() { return m_objectTypeID == OBJTYPE_Teki; }

/*
 * --INFO--
 * Address:	8013BA1C
 * Size:	000014
 */
bool Creature::isPellet() { return m_objectTypeID == OBJTYPE_Pellet; }

/*
 * --INFO--
 * Address:	8013BA30
 * Size:	000020
 */
bool Creature::sound_culling() { return !((m_lod.m_flags & AILOD_FLAG_UNKNOWN4) || (m_lod.m_flags & AILOD_FLAG_NEED_SHADOW)); }

/*
 * --INFO--
 * Address:	8013BA50
 * Size:	00009C
 */
void Creature::movie_begin(bool required)
{
	SET_FLAG(m_flags.typeView, CF_IS_MOVIE_ACTOR);

	if (!required) {
		SET_FLAG(m_flags.typeView, CF_IS_MOVIE_EXTRA);
		isPiki();
	} else {
		RESET_FLAG(m_flags.typeView, CF_IS_MOVIE_EXTRA);
		isPiki();
	}
	on_movie_begin(required);
}

/*
 * TODO: Determine if param really should be named "required".
 * --INFO--
 * Address:	8013BAEC
 * Size:	000050
 */
void Creature::movie_end(bool required)
{
	on_movie_end(required);
	RESET_FLAG(m_flags.typeView, CF_IS_MOVIE_ACTOR);
	RESET_FLAG(m_flags.typeView, CF_IS_MOVIE_EXTRA);
}

/*
 * --INFO--
 * Address:	8013BB3C
 * Size:	0000E0
 */
WaterBox* Creature::checkWater(WaterBox* waterBox, Sys::Sphere& boundSphere)
{
	if (waterBox) {
		if (!waterBox->inWater(boundSphere)) {
			if (mapMgr) {
				waterBox = mapMgr->findWater(boundSphere);
			}

			if (!waterBox) {
				outWaterCallback();
				waterBox = nullptr;
			}
		}
	} else {
		WaterBox* wb = nullptr;
		if (mapMgr) {
			wb = mapMgr->findWater(boundSphere);
		}

		waterBox = wb;
		if (waterBox) {
			inWaterCallback(waterBox);
		}
	}

	return waterBox;
}

/*
 * --INFO--
 * Address:	8013BC24
 * Size:	000144
 */
int Creature::checkHell(Creature::CheckHellArg& hellArg)
{
	Vector3f pos = getPosition();

	if (pos.y < -500.0f) {
		if (isPiki() && static_cast<FakePiki*>(this)->isPikmin()) {
			deathMgr->inc(0);
		}

		if (hellArg.m_isKillPiki) {
			killInline(nullptr);
		}

		return 2;
	}

	return pos.y < -300.0f;
}

/*
 * --INFO--
 * Address:	8013BD68
 * Size:	000178
 */
void Creature::updateCell()
{
	if (gameSystem && gameSystem->m_flags & 4) {
		return;
	}

	m_passID = -1;

	Sys::Sphere ball(getPosition());
	ball.m_radius = getCellRadius();

	SweepPrune::Object::m_minX.m_radius = ball.m_position.x - ball.m_radius;
	SweepPrune::Object::m_maxX.m_radius = ball.m_position.x + ball.m_radius;
	SweepPrune::Object::m_minZ.m_radius = ball.m_position.z - ball.m_radius;
	SweepPrune::Object::m_maxZ.m_radius = ball.m_position.z + ball.m_radius;

	SweepPrune::Object* sweepObj = this;

	CellPyramid* mgr;
	sweepObj->m_minX.insertSort((mgr = cellMgr)->m_xNode);
	sweepObj->m_maxX.insertSort(mgr->m_xNode);
	sweepObj->m_minZ.insertSort(mgr->m_zNode);
	sweepObj->m_maxZ.insertSort(mgr->m_zNode);

	if (cellMgr) {
		CellPyramid::sCellBugName = getCreatureName();
		CellPyramid::sCellBugID   = getCreatureID();
		cellMgr->entry(this, ball, m_cellLayerIndex, m_cellRect);
	}
}

/*
 * --INFO--
 * Address:	8013BEE8
 * Size:	000044
 */
int Creature::getCellPikiCount()
{
	if (cellMgr) {
		return cellMgr->getPikiCount(m_cellLayerIndex, m_cellRect);
	}

	return 0;
}

/*
 * --INFO--
 * Address:	8013BF2C
 * Size:	0000B0
 */
void Creature::applyImpulse(Vector3f& unused, Vector3f& impulse)
{
	Vector3f oldVelocity = getVelocity();
	Vector3f newVelocity = oldVelocity;

	newVelocity = newVelocity + (impulse * m_mass);
	setVelocity(newVelocity);
}

/*
 * --INFO--
 * Address:	8013BFDC
 * Size:	0002E4
 */
void Creature::checkCollision(CellObject* cellObj)
{
	Creature* cellCreature = static_cast<Creature*>(cellObj);

	if (isDebugCollision()) {
		getCreatureName();
		cellCreature->getCreatureName();
	}

	if (!cellCreature->isAtari() || !isAtari()) {
		return;
	}

	Creature* creatureObj = cellCreature;

	// TODO: This is cancer, fix
	if (!((!isStickTo() || m_sticker != cellCreature) && (!creatureObj->isStickTo() || creatureObj->m_sticker != this)
	      && !ignoreAtari(creatureObj))
	    || creatureObj->ignoreAtari(this)) {
		return;
	}

	if (!creatureObj->isAlive() || !isAlive()) {
		return;
	}

	isDebugCollision();

	Delegate3<Creature, CollPart*, CollPart*, Vector3f&> delegate
	    = Delegate3<Creature, CollPart*, CollPart*, Vector3f&>(this, &resolveOneColl);
	currOp = creatureObj;

	if (isDebugCollision()) {
		CollTree::mDebug = true;
	}

	bool creatureCheck = true;
	if (!isPiki() && !isNavi()) {
		creatureCheck = false;
	}

	bool objCheck = true;
	if (!cellCreature->isPiki() && !cellCreature->isNavi()) {
		objCheck = false;
	}

	CollPart* collPart1;
	CollPart* collPart2;
	Vector3f vec;

	if ((creatureCheck && objCheck) || (!creatureCheck && !objCheck)) {
		if (m_collTree->checkCollision(creatureObj->m_collTree, &collPart1, &collPart2, vec)) {
			delegate.invoke(collPart1, collPart2, vec);
		}
	} else {
		m_collTree->checkCollisionMulti(creatureObj->m_collTree, (IDelegate3<CollPart*, CollPart*, Vector3<f32>&>*)&delegate);
	}

	CollTree::mDebug = false;
	currOp           = nullptr;
}

/*
 * --INFO--
 * Address:	8013C2C0
 * Size:	0008CC
 */
void Creature::resolveOneColl(CollPart* part1, CollPart* part2, Vector3f& inputVec)
{
	Creature* op = currOp;
	if (!currOp) {
		return;
	}

	if (isDebugCollision()) {
		getCreatureName();
		op->getCreatureName();
	}

	bool flickCheck = false;
	if (!isCollisionFlick() || !op->isCollisionFlick()) {
		flickCheck = true;
	}

	Vector3f vec(-inputVec.x, -inputVec.y, -inputVec.z);
	if (vec.normalise() == 0.0f) {
		vec.x = 0.0f;
		vec.y = 0.0f;
		vec.z = 1.0f;
	}

	Vector3f vel1;
	Vector3f vel2;
	Vector3f disp1 = part1->m_position + (vec * part1->m_radius);
	Vector3f disp2 = part2->m_position - (vec * part2->m_radius);

	getVelocityAt(disp1, vel1);
	op->getVelocityAt(disp2, vel2);

	f32 massRatio;
	f32 massRatioOp;

	f32 sum = m_mass + op->m_mass;
	if (sum > 0.0f) {
		massRatio   = m_mass / sum;
		massRatioOp = 1.0f - massRatio;
	} else {
		massRatio = massRatioOp = 0.5f;
	}

	f32 fps = 1.0f / sys->m_deltaTime;
	if (isNavi() && !op->isNavi()) {
		if (!op->isPiki()) {
			addAccel(m_acceleration, inputVec, massRatio, fps, 0.5f, 0.0f);
		}
	} else {
		setAccel(m_acceleration, inputVec, massRatio, fps, 0.5f, 0.0f);
	}

	if (op->isNavi() && !isNavi()) {
		if (!isPiki()) {
			setOpAccel(op->m_acceleration, inputVec, massRatioOp, fps, 0.5f, 0.0f);
		}
	} else {
		setOpAccel(op->m_acceleration, inputVec, massRatioOp, fps, 0.5f, 0.0f);
	}

	f32 accelMag = m_acceleration.length();
	if (accelMag > 200.0f) {
		f32 accelNorm = 200.0f * (1.0f / accelMag);
		m_acceleration.x *= accelNorm;
		m_acceleration.y *= accelNorm;
		m_acceleration.z *= accelNorm;
	}

	f32 opAccelMag = op->m_acceleration.length();
	if (opAccelMag > 200.0f) {
		f32 opAccelNorm = 200.0f * (1.0f / opAccelMag);
		op->m_acceleration.x *= opAccelNorm;
		op->m_acceleration.y *= opAccelNorm;
		op->m_acceleration.z *= opAccelNorm;
	}

	if (flickCheck) {
		m_acceleration     = Vector3f(0.0f);
		op->m_acceleration = Vector3f(0.0f);
	}

	CollEvent collEvent1(op, part2, part1);

	Vector3f sep = vel1 - vel2;
	f32 sepDot   = sep.x * vec.x + sep.y * vec.y + sep.z * vec.z;
	collisionCallback(collEvent1);

	CollEvent collEvent2(this, part1, part2);

	op->collisionCallback(collEvent2);
	if (sepDot <= 0.0f) {
		if (isDebugCollision()) {
			getCreatureName();
			op->getCreatureName();
		}
	} else {
		isDebugCollision();
		if (flickCheck) {
			isDebugCollision();
			return;
		}

		f32 naviFactor = 0.1f;
		if (isNavi() || op->isNavi()) {
			naviFactor = 0.0f;
		}

		bool checkSum2 = false;
		f32 factor5    = -(1.0f + naviFactor) * sepDot;
		f32 sum2       = m_mass + op->m_mass;
		if (sum2 == 0.0f) {
			sum2      = 2.0f;
			checkSum2 = true;
		}

		sum2 += getAngularEffect(disp1, vec);
		sum2 += op->getAngularEffect(disp2, vec);
		f32 posFac           = factor5 / (sum2);
		Vector3f updatedVec1 = vec * posFac;
		Vector3f updatedVec2 = vec * -posFac;

		if (!checkSum2) {
			applyImpulse(disp1, updatedVec1);
			op->applyImpulse(disp2, updatedVec2);
			return;
		}

		Vector3f updatedVel1 = getVelocity();
		updatedVel1          = Vector3f(updatedVel1.x + updatedVec1.x, updatedVel1.y + updatedVec1.y, updatedVel1.z + updatedVec1.z);
		setVelocity(updatedVel1);

		Vector3f updatedVel2 = op->getVelocity();
		updatedVel2          = Vector3f(updatedVel2.x + updatedVec2.x, updatedVel2.y + updatedVec2.y, updatedVel2.z + updatedVec2.z);
		op->setVelocity(updatedVel2);
	}
}

} // namespace Game
