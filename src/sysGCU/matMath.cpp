#include "Matrixf.h"
#include "types.h"

/*
    Generated from dpostproc

    .section .sdata2, "a"     # 0x80516360 - 0x80520E40
    .global lbl_80520510
    lbl_80520510:
        .float 1.0
    .global lbl_80520514
    lbl_80520514:
        .float 0.0
    .global lbl_80520518
    lbl_80520518:
        .float 325.9493
    .global lbl_8052051C
    lbl_8052051C:
        .float -325.9493
    .global lbl_80520520
    lbl_80520520:
        .float 1.5707964
    .global lbl_80520524
    lbl_80520524:
        .float 2.0
*/

/*
 * --INFO--
 * Address:	........
 * Size:	000228
 */
void Matrixf::makeNaturalPosture(Vector3f&)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	80427F90
 * Size:	000344
 */
void Matrixf::makeNaturalPosture(Vector3f&, float)
{
	/*
	stwu     r1, -0x20(r1)
	lfs      f2, 8(r4)
	lfs      f0, 0(r4)
	fabs     f2, f2
	fabs     f3, f0
	frsp     f0, f2
	frsp     f2, f3
	fcmpo    cr0, f2, f0
	ble      lbl_80428118
	fmr      f2, f1
	lfs      f0, lbl_80520514@sda21(r2)
	fcmpo    cr0, f2, f0
	bge      lbl_80427FC8
	fneg     f2, f2

lbl_80427FC8:
	lfs      f3, lbl_80520518@sda21(r2)
	lis      r5, sincosTable___5JMath@ha
	lfs      f0, lbl_80520514@sda21(r2)
	addi     r6, r5, sincosTable___5JMath@l
	fmuls    f2, f2, f3
	fcmpo    cr0, f1, f0
	fctiwz   f0, f2
	stfd     f0, 8(r1)
	lwz      r0, 0xc(r1)
	rlwinm   r0, r0, 3, 0x12, 0x1c
	add      r5, r6, r0
	lfs      f6, 4(r5)
	bge      lbl_80428020
	lfs      f0, lbl_8052051C@sda21(r2)
	fmuls    f0, f1, f0
	fctiwz   f0, f0
	stfd     f0, 0x10(r1)
	lwz      r0, 0x14(r1)
	rlwinm   r0, r0, 3, 0x12, 0x1c
	lfsx     f0, r6, r0
	fneg     f3, f0
	b        lbl_80428038

lbl_80428020:
	fmuls    f0, f1, f3
	fctiwz   f0, f0
	stfd     f0, 0x18(r1)
	lwz      r0, 0x1c(r1)
	rlwinm   r0, r0, 3, 0x12, 0x1c
	lfsx     f3, r6, r0

lbl_80428038:
	lfs      f10, 0(r4)
	lfs      f8, 4(r4)
	fmuls    f1, f10, f6
	lfs      f9, 8(r4)
	lfs      f2, lbl_80520514@sda21(r2)
	fmuls    f0, f8, f3
	fmsubs   f4, f9, f3, f1
	fmuls    f1, f9, f2
	fmsubs   f5, f10, f2, f0
	fmuls    f0, f4, f4
	fmsubs   f3, f8, f6, f1
	fmuls    f1, f5, f5
	fmadds   f0, f3, f3, f0
	fadds    f1, f1, f0
	fcmpo    cr0, f1, f2
	ble      lbl_80428088
	ble      lbl_8042808C
	frsqrte  f0, f1
	fmuls    f1, f0, f1
	b        lbl_8042808C

lbl_80428088:
	fmr      f1, f2

lbl_8042808C:
	lfs      f0, lbl_80520514@sda21(r2)
	fcmpo    cr0, f1, f0
	ble      lbl_804280AC
	lfs      f0, lbl_80520510@sda21(r2)
	fdivs    f0, f0, f1
	fmuls    f3, f3, f0
	fmuls    f4, f4, f0
	fmuls    f5, f5, f0

lbl_804280AC:
	fmuls    f0, f3, f9
	lfs      f6, lbl_80520514@sda21(r2)
	fmuls    f2, f4, f10
	fmuls    f7, f5, f8
	fmsubs   f1, f5, f10, f0
	fmsubs   f2, f3, f8, f2
	fmsubs   f0, f4, f9, f7
	fmuls    f7, f1, f1
	fmuls    f8, f2, f2
	fmadds   f7, f0, f0, f7
	fadds    f7, f8, f7
	fcmpo    cr0, f7, f6
	ble      lbl_804280F0
	ble      lbl_804280F4
	frsqrte  f6, f7
	fmuls    f7, f6, f7
	b        lbl_804280F4

lbl_804280F0:
	fmr      f7, f6

lbl_804280F4:
	lfs      f6, lbl_80520514@sda21(r2)
	fcmpo    cr0, f7, f6
	ble      lbl_80428280
	lfs      f6, lbl_80520510@sda21(r2)
	fdivs    f6, f6, f7
	fmuls    f0, f0, f6
	fmuls    f1, f1, f6
	fmuls    f2, f2, f6
	b        lbl_80428280

lbl_80428118:
	lfs      f2, lbl_80520520@sda21(r2)
	lfs      f0, lbl_80520514@sda21(r2)
	fadds    f3, f2, f1
	fmr      f1, f3
	fcmpo    cr0, f3, f0
	bge      lbl_80428134
	fneg     f1, f3

lbl_80428134:
	lfs      f2, lbl_80520518@sda21(r2)
	lis      r5, sincosTable___5JMath@ha
	lfs      f0, lbl_80520514@sda21(r2)
	addi     r6, r5, sincosTable___5JMath@l
	fmuls    f1, f1, f2
	fcmpo    cr0, f3, f0
	fctiwz   f0, f1
	stfd     f0, 0x18(r1)
	lwz      r0, 0x1c(r1)
	rlwinm   r0, r0, 3, 0x12, 0x1c
	add      r5, r6, r0
	lfs      f1, 4(r5)
	bge      lbl_8042818C
	lfs      f0, lbl_8052051C@sda21(r2)
	fmuls    f0, f3, f0
	fctiwz   f0, f0
	stfd     f0, 0x10(r1)
	lwz      r0, 0x14(r1)
	rlwinm   r0, r0, 3, 0x12, 0x1c
	lfsx     f0, r6, r0
	fneg     f4, f0
	b        lbl_804281A4

lbl_8042818C:
	fmuls    f0, f3, f2
	fctiwz   f0, f0
	stfd     f0, 8(r1)
	lwz      r0, 0xc(r1)
	rlwinm   r0, r0, 3, 0x12, 0x1c
	lfsx     f4, r6, r0

lbl_804281A4:
	lfs      f8, 8(r4)
	lfs      f10, 4(r4)
	fmuls    f0, f4, f8
	lfs      f9, 0(r4)
	lfs      f5, lbl_80520514@sda21(r2)
	fmuls    f3, f1, f10
	fmsubs   f1, f1, f9, f0
	fmuls    f2, f5, f9
	fmsubs   f0, f5, f8, f3
	fmuls    f3, f1, f1
	fmsubs   f2, f4, f10, f2
	fmadds   f3, f0, f0, f3
	fmuls    f4, f2, f2
	fadds    f4, f4, f3
	fcmpo    cr0, f4, f5
	ble      lbl_804281F4
	ble      lbl_804281F8
	frsqrte  f3, f4
	fmuls    f4, f3, f4
	b        lbl_804281F8

lbl_804281F4:
	fmr      f4, f5

lbl_804281F8:
	lfs      f3, lbl_80520514@sda21(r2)
	fcmpo    cr0, f4, f3
	ble      lbl_80428218
	lfs      f3, lbl_80520510@sda21(r2)
	fdivs    f3, f3, f4
	fmuls    f0, f0, f3
	fmuls    f1, f1, f3
	fmuls    f2, f2, f3

lbl_80428218:
	fmuls    f3, f9, f2
	lfs      f6, lbl_80520514@sda21(r2)
	fmuls    f5, f10, f0
	fmuls    f7, f8, f1
	fmsubs   f4, f8, f0, f3
	fmsubs   f5, f9, f1, f5
	fmsubs   f3, f10, f2, f7
	fmuls    f7, f4, f4
	fmuls    f8, f5, f5
	fmadds   f7, f3, f3, f7
	fadds    f7, f8, f7
	fcmpo    cr0, f7, f6
	ble      lbl_8042825C
	ble      lbl_80428260
	frsqrte  f6, f7
	fmuls    f7, f6, f7
	b        lbl_80428260

lbl_8042825C:
	fmr      f7, f6

lbl_80428260:
	lfs      f6, lbl_80520514@sda21(r2)
	fcmpo    cr0, f7, f6
	ble      lbl_80428280
	lfs      f6, lbl_80520510@sda21(r2)
	fdivs    f6, f6, f7
	fmuls    f3, f3, f6
	fmuls    f4, f4, f6
	fmuls    f5, f5, f6

lbl_80428280:
	stfs     f3, 0(r3)
	lis      r5, "zero__10Vector3<f>"@ha
	stfs     f4, 0x10(r3)
	stfs     f5, 0x20(r3)
	lfs      f3, 0(r4)
	stfs     f3, 4(r3)
	lfs      f3, 4(r4)
	stfs     f3, 0x14(r3)
	lfs      f3, 8(r4)
	stfs     f3, 0x24(r3)
	stfs     f0, 8(r3)
	stfs     f1, 0x18(r3)
	stfs     f2, 0x28(r3)
	lfsu     f0, "zero__10Vector3<f>"@l(r5)
	stfs     f0, 0xc(r3)
	lfs      f0, 4(r5)
	stfs     f0, 0x1c(r3)
	lfs      f0, 8(r5)
	stfs     f0, 0x2c(r3)
	addi     r1, r1, 0x20
	blr
	*/
}

/*
 * --INFO--
 * Address:	804282D4
 * Size:	000004
 */
void Matrixf::print(char*) { }

/*
 * --INFO--
 * Address:	804282D8
 * Size:	000288
 */
void Matrixf::makeSRT(Vector3f&, Vector3f&, Vector3f&)
{
	/*
	stwu     r1, -0x60(r1)
	stfd     f31, 0x50(r1)
	psq_st   f31, 88(r1), 0, qr0
	lfs      f4, 0(r5)
	lfs      f0, lbl_80520514@sda21(r2)
	fcmpo    cr0, f4, f0
	bge      lbl_80428320
	lfs      f0, lbl_8052051C@sda21(r2)
	lis      r7, sincosTable___5JMath@ha
	addi     r7, r7, sincosTable___5JMath@l
	fmuls    f0, f4, f0
	fctiwz   f0, f0
	stfd     f0, 8(r1)
	lwz      r0, 0xc(r1)
	rlwinm   r0, r0, 3, 0x12, 0x1c
	lfsx     f0, r7, r0
	fneg     f0, f0
	b        lbl_80428344

lbl_80428320:
	lfs      f0, lbl_80520518@sda21(r2)
	lis      r7, sincosTable___5JMath@ha
	addi     r7, r7, sincosTable___5JMath@l
	fmuls    f0, f4, f0
	fctiwz   f0, f0
	stfd     f0, 0x10(r1)
	lwz      r0, 0x14(r1)
	rlwinm   r0, r0, 3, 0x12, 0x1c
	lfsx     f0, r7, r0

lbl_80428344:
	lfs      f5, 4(r5)
	lfs      f1, lbl_80520514@sda21(r2)
	fcmpo    cr0, f5, f1
	bge      lbl_80428380
	lfs      f1, lbl_8052051C@sda21(r2)
	lis      r7, sincosTable___5JMath@ha
	addi     r7, r7, sincosTable___5JMath@l
	fmuls    f1, f5, f1
	fctiwz   f1, f1
	stfd     f1, 0x18(r1)
	lwz      r0, 0x1c(r1)
	rlwinm   r0, r0, 3, 0x12, 0x1c
	lfsx     f1, r7, r0
	fneg     f1, f1
	b        lbl_804283A4

lbl_80428380:
	lfs      f1, lbl_80520518@sda21(r2)
	lis      r7, sincosTable___5JMath@ha
	addi     r7, r7, sincosTable___5JMath@l
	fmuls    f1, f5, f1
	fctiwz   f1, f1
	stfd     f1, 0x20(r1)
	lwz      r0, 0x24(r1)
	rlwinm   r0, r0, 3, 0x12, 0x1c
	lfsx     f1, r7, r0

lbl_804283A4:
	lfs      f11, 8(r5)
	lfs      f2, lbl_80520514@sda21(r2)
	fcmpo    cr0, f11, f2
	bge      lbl_804283E0
	lfs      f2, lbl_8052051C@sda21(r2)
	lis      r5, sincosTable___5JMath@ha
	addi     r5, r5, sincosTable___5JMath@l
	fmuls    f2, f11, f2
	fctiwz   f2, f2
	stfd     f2, 0x28(r1)
	lwz      r0, 0x2c(r1)
	rlwinm   r0, r0, 3, 0x12, 0x1c
	lfsx     f2, r5, r0
	fneg     f10, f2
	b        lbl_80428404

lbl_804283E0:
	lfs      f2, lbl_80520518@sda21(r2)
	lis      r5, sincosTable___5JMath@ha
	addi     r5, r5, sincosTable___5JMath@l
	fmuls    f2, f11, f2
	fctiwz   f2, f2
	stfd     f2, 0x30(r1)
	lwz      r0, 0x34(r1)
	rlwinm   r0, r0, 3, 0x12, 0x1c
	lfsx     f10, r5, r0

lbl_80428404:
	lfs      f2, lbl_80520514@sda21(r2)
	fcmpo    cr0, f4, f2
	bge      lbl_80428414
	fneg     f4, f4

lbl_80428414:
	lfs      f3, lbl_80520518@sda21(r2)
	lis      r5, sincosTable___5JMath@ha
	lfs      f2, lbl_80520514@sda21(r2)
	addi     r5, r5, sincosTable___5JMath@l
	fmuls    f3, f4, f3
	addi     r5, r5, 4
	fcmpo    cr0, f5, f2
	fctiwz   f2, f3
	stfd     f2, 0x38(r1)
	lwz      r0, 0x3c(r1)
	rlwinm   r0, r0, 3, 0x12, 0x1c
	lfsx     f9, r5, r0
	bge      lbl_8042844C
	fneg     f5, f5

lbl_8042844C:
	lfs      f3, lbl_80520518@sda21(r2)
	lfs      f2, lbl_80520514@sda21(r2)
	fmuls    f3, f5, f3
	fcmpo    cr0, f11, f2
	fctiwz   f2, f3
	stfd     f2, 0x40(r1)
	lwz      r0, 0x44(r1)
	rlwinm   r0, r0, 3, 0x12, 0x1c
	lfsx     f5, r5, r0
	bge      lbl_80428478
	fneg     f11, f11

lbl_80428478:
	lfs      f2, lbl_80520518@sda21(r2)
	fmuls    f8, f5, f10
	fmuls    f4, f0, f5
	lfs      f6, 0(r4)
	fmuls    f2, f11, f2
	fmuls    f31, f9, f10
	fmuls    f13, f0, f1
	fctiwz   f2, f2
	fmuls    f3, f0, f10
	fneg     f7, f1
	stfd     f2, 0x48(r1)
	fmuls    f2, f9, f5
	lwz      r0, 0x4c(r1)
	rlwinm   r0, r0, 3, 0x12, 0x1c
	lfsx     f11, r5, r0
	fmuls    f5, f5, f11
	fmuls    f12, f9, f11
	fmuls    f0, f0, f11
	fmuls    f9, f6, f5
	fmadds   f3, f12, f1, f3
	fmsubs   f0, f31, f1, f0
	stfs     f9, 0(r3)
	fmsubs   f6, f13, f11, f31
	fmadds   f5, f13, f10, f12
	lfs      f1, 0(r4)
	fmuls    f1, f1, f8
	stfs     f1, 0x10(r3)
	lfs      f1, 0(r4)
	fmuls    f1, f1, f7
	stfs     f1, 0x20(r3)
	lfs      f1, 4(r4)
	fmuls    f1, f1, f6
	stfs     f1, 4(r3)
	lfs      f1, 4(r4)
	fmuls    f1, f1, f5
	stfs     f1, 0x14(r3)
	lfs      f1, 4(r4)
	fmuls    f1, f1, f4
	stfs     f1, 0x24(r3)
	lfs      f1, 8(r4)
	fmuls    f1, f1, f3
	stfs     f1, 8(r3)
	lfs      f1, 8(r4)
	fmuls    f0, f1, f0
	stfs     f0, 0x18(r3)
	lfs      f0, 8(r4)
	fmuls    f0, f0, f2
	stfs     f0, 0x28(r3)
	lfs      f0, 0(r6)
	stfs     f0, 0xc(r3)
	lfs      f0, 4(r6)
	stfs     f0, 0x1c(r3)
	lfs      f0, 8(r6)
	stfs     f0, 0x2c(r3)
	psq_l    f31, 88(r1), 0, qr0
	lfd      f31, 0x50(r1)
	addi     r1, r1, 0x60
	blr
	*/
}

/*
 * --INFO--
 * Address:	80428560
 * Size:	000050
 */
void Matrixf::makeST(Vector3f&, Vector3f&)
{
	/*
	lfs      f0, 0(r4)
	lfs      f1, lbl_80520514@sda21(r2)
	stfs     f0, 0(r3)
	stfs     f1, 0x10(r3)
	stfs     f1, 0x20(r3)
	stfs     f1, 4(r3)
	lfs      f0, 4(r4)
	stfs     f0, 0x14(r3)
	stfs     f1, 0x24(r3)
	stfs     f1, 8(r3)
	stfs     f1, 0x18(r3)
	lfs      f0, 8(r4)
	stfs     f0, 0x28(r3)
	lfs      f0, 0(r5)
	stfs     f0, 0xc(r3)
	lfs      f0, 4(r5)
	stfs     f0, 0x1c(r3)
	lfs      f0, 8(r5)
	stfs     f0, 0x2c(r3)
	blr
	*/
}

/*
 * --INFO--
 * Address:	804285B0
 * Size:	000290
 */
void Matrixf::makeSR(Vector3f&, Vector3f&)
{
	/*
	stwu     r1, -0x70(r1)
	stfd     f31, 0x60(r1)
	psq_st   f31, 104(r1), 0, qr0
	stfd     f30, 0x50(r1)
	psq_st   f30, 88(r1), 0, qr0
	lfs      f4, 0(r5)
	lfs      f0, lbl_80520514@sda21(r2)
	fcmpo    cr0, f4, f0
	bge      lbl_80428600
	lfs      f0, lbl_8052051C@sda21(r2)
	lis      r6, sincosTable___5JMath@ha
	addi     r6, r6, sincosTable___5JMath@l
	fmuls    f0, f4, f0
	fctiwz   f0, f0
	stfd     f0, 8(r1)
	lwz      r0, 0xc(r1)
	rlwinm   r0, r0, 3, 0x12, 0x1c
	lfsx     f0, r6, r0
	fneg     f0, f0
	b        lbl_80428624

lbl_80428600:
	lfs      f0, lbl_80520518@sda21(r2)
	lis      r6, sincosTable___5JMath@ha
	addi     r6, r6, sincosTable___5JMath@l
	fmuls    f0, f4, f0
	fctiwz   f0, f0
	stfd     f0, 0x10(r1)
	lwz      r0, 0x14(r1)
	rlwinm   r0, r0, 3, 0x12, 0x1c
	lfsx     f0, r6, r0

lbl_80428624:
	lfs      f5, 4(r5)
	lfs      f1, lbl_80520514@sda21(r2)
	fcmpo    cr0, f5, f1
	bge      lbl_80428660
	lfs      f1, lbl_8052051C@sda21(r2)
	lis      r6, sincosTable___5JMath@ha
	addi     r6, r6, sincosTable___5JMath@l
	fmuls    f1, f5, f1
	fctiwz   f1, f1
	stfd     f1, 0x18(r1)
	lwz      r0, 0x1c(r1)
	rlwinm   r0, r0, 3, 0x12, 0x1c
	lfsx     f1, r6, r0
	fneg     f1, f1
	b        lbl_80428684

lbl_80428660:
	lfs      f1, lbl_80520518@sda21(r2)
	lis      r6, sincosTable___5JMath@ha
	addi     r6, r6, sincosTable___5JMath@l
	fmuls    f1, f5, f1
	fctiwz   f1, f1
	stfd     f1, 0x20(r1)
	lwz      r0, 0x24(r1)
	rlwinm   r0, r0, 3, 0x12, 0x1c
	lfsx     f1, r6, r0

lbl_80428684:
	lfs      f12, 8(r5)
	lfs      f2, lbl_80520514@sda21(r2)
	fcmpo    cr0, f12, f2
	bge      lbl_804286C0
	lfs      f2, lbl_8052051C@sda21(r2)
	lis      r5, sincosTable___5JMath@ha
	addi     r5, r5, sincosTable___5JMath@l
	fmuls    f2, f12, f2
	fctiwz   f2, f2
	stfd     f2, 0x28(r1)
	lwz      r0, 0x2c(r1)
	rlwinm   r0, r0, 3, 0x12, 0x1c
	lfsx     f2, r5, r0
	fneg     f11, f2
	b        lbl_804286E4

lbl_804286C0:
	lfs      f2, lbl_80520518@sda21(r2)
	lis      r5, sincosTable___5JMath@ha
	addi     r5, r5, sincosTable___5JMath@l
	fmuls    f2, f12, f2
	fctiwz   f2, f2
	stfd     f2, 0x30(r1)
	lwz      r0, 0x34(r1)
	rlwinm   r0, r0, 3, 0x12, 0x1c
	lfsx     f11, r5, r0

lbl_804286E4:
	lfs      f2, lbl_80520514@sda21(r2)
	fcmpo    cr0, f4, f2
	bge      lbl_804286F4
	fneg     f4, f4

lbl_804286F4:
	lfs      f3, lbl_80520518@sda21(r2)
	lis      r5, sincosTable___5JMath@ha
	lfs      f2, lbl_80520514@sda21(r2)
	addi     r5, r5, sincosTable___5JMath@l
	fmuls    f3, f4, f3
	addi     r5, r5, 4
	fcmpo    cr0, f5, f2
	fctiwz   f2, f3
	stfd     f2, 0x38(r1)
	lwz      r0, 0x3c(r1)
	rlwinm   r0, r0, 3, 0x12, 0x1c
	lfsx     f10, r5, r0
	bge      lbl_8042872C
	fneg     f5, f5

lbl_8042872C:
	lfs      f3, lbl_80520518@sda21(r2)
	lfs      f2, lbl_80520514@sda21(r2)
	fmuls    f3, f5, f3
	fcmpo    cr0, f12, f2
	fctiwz   f2, f3
	stfd     f2, 0x40(r1)
	lwz      r0, 0x44(r1)
	rlwinm   r0, r0, 3, 0x12, 0x1c
	lfsx     f6, r5, r0
	bge      lbl_80428758
	fneg     f12, f12

lbl_80428758:
	lfs      f2, lbl_80520518@sda21(r2)
	fmuls    f9, f6, f11
	fmuls    f5, f0, f6
	lfs      f7, 0(r4)
	fmuls    f3, f12, f2
	lfs      f2, lbl_80520514@sda21(r2)
	fmuls    f30, f10, f11
	fmuls    f31, f0, f1
	fctiwz   f3, f3
	fmuls    f4, f0, f11
	fneg     f8, f1
	stfd     f3, 0x48(r1)
	fmuls    f3, f10, f6
	lwz      r0, 0x4c(r1)
	rlwinm   r0, r0, 3, 0x12, 0x1c
	lfsx     f12, r5, r0
	fmuls    f6, f6, f12
	fmuls    f13, f10, f12
	fmuls    f0, f0, f12
	fmuls    f10, f7, f6
	fmadds   f4, f13, f1, f4
	fmsubs   f0, f30, f1, f0
	stfs     f10, 0(r3)
	fmsubs   f7, f31, f12, f30
	fmadds   f6, f31, f11, f13
	lfs      f1, 0(r4)
	fmuls    f1, f1, f9
	stfs     f1, 0x10(r3)
	lfs      f1, 0(r4)
	fmuls    f1, f1, f8
	stfs     f1, 0x20(r3)
	lfs      f1, 4(r4)
	fmuls    f1, f1, f7
	stfs     f1, 4(r3)
	lfs      f1, 4(r4)
	fmuls    f1, f1, f6
	stfs     f1, 0x14(r3)
	lfs      f1, 4(r4)
	fmuls    f1, f1, f5
	stfs     f1, 0x24(r3)
	lfs      f1, 8(r4)
	fmuls    f1, f1, f4
	stfs     f1, 8(r3)
	lfs      f1, 8(r4)
	fmuls    f0, f1, f0
	stfs     f0, 0x18(r3)
	lfs      f0, 8(r4)
	fmuls    f0, f0, f3
	stfs     f0, 0x28(r3)
	stfs     f2, 0xc(r3)
	stfs     f2, 0x1c(r3)
	stfs     f2, 0x2c(r3)
	psq_l    f31, 104(r1), 0, qr0
	lfd      f31, 0x60(r1)
	psq_l    f30, 88(r1), 0, qr0
	lfd      f30, 0x50(r1)
	addi     r1, r1, 0x70
	blr
	*/
}

/*
 * --INFO--
 * Address:	80428840
 * Size:	000048
 */
void Matrixf::makeT(Vector3f&)
{
	/*
	lfs      f1, lbl_80520510@sda21(r2)
	lfs      f0, lbl_80520514@sda21(r2)
	stfs     f1, 0(r3)
	stfs     f0, 0x10(r3)
	stfs     f0, 0x20(r3)
	stfs     f0, 4(r3)
	stfs     f1, 0x14(r3)
	stfs     f0, 0x24(r3)
	stfs     f0, 8(r3)
	stfs     f0, 0x18(r3)
	stfs     f1, 0x28(r3)
	lfs      f0, 0(r4)
	stfs     f0, 0xc(r3)
	lfs      f0, 4(r4)
	stfs     f0, 0x1c(r3)
	lfs      f0, 8(r4)
	stfs     f0, 0x2c(r3)
	blr
	*/
}

/*
 * --INFO--
 * Address:	80428888
 * Size:	000230
 */
void Matrixf::makeTR(Vector3f&, Vector3f&)
{
	/*
	stwu     r1, -0x50(r1)
	lfs      f0, lbl_80520514@sda21(r2)
	lfs      f4, 0(r5)
	fcmpo    cr0, f4, f0
	bge      lbl_804288C8
	lfs      f0, lbl_8052051C@sda21(r2)
	lis      r6, sincosTable___5JMath@ha
	addi     r6, r6, sincosTable___5JMath@l
	fmuls    f0, f4, f0
	fctiwz   f0, f0
	stfd     f0, 8(r1)
	lwz      r0, 0xc(r1)
	rlwinm   r0, r0, 3, 0x12, 0x1c
	lfsx     f0, r6, r0
	fneg     f0, f0
	b        lbl_804288EC

lbl_804288C8:
	lfs      f0, lbl_80520518@sda21(r2)
	lis      r6, sincosTable___5JMath@ha
	addi     r6, r6, sincosTable___5JMath@l
	fmuls    f0, f4, f0
	fctiwz   f0, f0
	stfd     f0, 0x10(r1)
	lwz      r0, 0x14(r1)
	rlwinm   r0, r0, 3, 0x12, 0x1c
	lfsx     f0, r6, r0

lbl_804288EC:
	lfs      f5, 4(r5)
	lfs      f1, lbl_80520514@sda21(r2)
	fcmpo    cr0, f5, f1
	bge      lbl_80428928
	lfs      f1, lbl_8052051C@sda21(r2)
	lis      r6, sincosTable___5JMath@ha
	addi     r6, r6, sincosTable___5JMath@l
	fmuls    f1, f5, f1
	fctiwz   f1, f1
	stfd     f1, 0x18(r1)
	lwz      r0, 0x1c(r1)
	rlwinm   r0, r0, 3, 0x12, 0x1c
	lfsx     f1, r6, r0
	fneg     f1, f1
	b        lbl_8042894C

lbl_80428928:
	lfs      f1, lbl_80520518@sda21(r2)
	lis      r6, sincosTable___5JMath@ha
	addi     r6, r6, sincosTable___5JMath@l
	fmuls    f1, f5, f1
	fctiwz   f1, f1
	stfd     f1, 0x20(r1)
	lwz      r0, 0x24(r1)
	rlwinm   r0, r0, 3, 0x12, 0x1c
	lfsx     f1, r6, r0

lbl_8042894C:
	lfs      f7, 8(r5)
	lfs      f2, lbl_80520514@sda21(r2)
	fcmpo    cr0, f7, f2
	bge      lbl_80428988
	lfs      f2, lbl_8052051C@sda21(r2)
	lis      r5, sincosTable___5JMath@ha
	addi     r5, r5, sincosTable___5JMath@l
	fmuls    f2, f7, f2
	fctiwz   f2, f2
	stfd     f2, 0x28(r1)
	lwz      r0, 0x2c(r1)
	rlwinm   r0, r0, 3, 0x12, 0x1c
	lfsx     f2, r5, r0
	fneg     f9, f2
	b        lbl_804289AC

lbl_80428988:
	lfs      f2, lbl_80520518@sda21(r2)
	lis      r5, sincosTable___5JMath@ha
	addi     r5, r5, sincosTable___5JMath@l
	fmuls    f2, f7, f2
	fctiwz   f2, f2
	stfd     f2, 0x30(r1)
	lwz      r0, 0x34(r1)
	rlwinm   r0, r0, 3, 0x12, 0x1c
	lfsx     f9, r5, r0

lbl_804289AC:
	lfs      f2, lbl_80520514@sda21(r2)
	fcmpo    cr0, f4, f2
	bge      lbl_804289BC
	fneg     f4, f4

lbl_804289BC:
	lfs      f3, lbl_80520518@sda21(r2)
	lis      r5, sincosTable___5JMath@ha
	lfs      f2, lbl_80520514@sda21(r2)
	addi     r5, r5, sincosTable___5JMath@l
	fmuls    f3, f4, f3
	addi     r5, r5, 4
	fcmpo    cr0, f5, f2
	fctiwz   f2, f3
	stfd     f2, 0x38(r1)
	lwz      r0, 0x3c(r1)
	rlwinm   r0, r0, 3, 0x12, 0x1c
	lfsx     f6, r5, r0
	bge      lbl_804289F4
	fneg     f5, f5

lbl_804289F4:
	lfs      f3, lbl_80520518@sda21(r2)
	lfs      f2, lbl_80520514@sda21(r2)
	fmuls    f3, f5, f3
	fcmpo    cr0, f7, f2
	fctiwz   f2, f3
	stfd     f2, 0x40(r1)
	lwz      r0, 0x44(r1)
	rlwinm   r0, r0, 3, 0x12, 0x1c
	lfsx     f5, r5, r0
	bge      lbl_80428A20
	fneg     f7, f7

lbl_80428A20:
	lfs      f2, lbl_80520518@sda21(r2)
	fmuls    f8, f5, f9
	fmuls    f4, f0, f5
	fmuls    f2, f7, f2
	fmuls    f12, f0, f1
	fmuls    f13, f6, f9
	fctiwz   f2, f2
	fneg     f7, f1
	fmuls    f3, f0, f9
	stfd     f2, 0x48(r1)
	fmuls    f2, f6, f5
	lwz      r0, 0x4c(r1)
	rlwinm   r0, r0, 3, 0x12, 0x1c
	lfsx     f10, r5, r0
	fmuls    f5, f5, f10
	fmuls    f11, f6, f10
	fmuls    f0, f0, f10
	stfs     f5, 0(r3)
	fmsubs   f6, f12, f10, f13
	fmadds   f5, f12, f9, f11
	stfs     f8, 0x10(r3)
	fmadds   f3, f11, f1, f3
	fmsubs   f0, f13, f1, f0
	stfs     f7, 0x20(r3)
	stfs     f6, 4(r3)
	stfs     f5, 0x14(r3)
	stfs     f4, 0x24(r3)
	stfs     f3, 8(r3)
	stfs     f0, 0x18(r3)
	stfs     f2, 0x28(r3)
	lfs      f0, 0(r4)
	stfs     f0, 0xc(r3)
	lfs      f0, 4(r4)
	stfs     f0, 0x1c(r3)
	lfs      f0, 8(r4)
	stfs     f0, 0x2c(r3)
	addi     r1, r1, 0x50
	blr
	*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	000128
 */
void Matrixf::makeSQT(Vector3f&, Quat&, Vector3f&)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	80428AB8
 * Size:	0000D0
 */
void Matrixf::makeTQ(Vector3f&, Quat&)
{
	/*
	stwu     r1, -0x20(r1)
	stfd     f31, 0x10(r1)
	psq_st   f31, 24(r1), 0, qr0
	lfs      f4, 8(r5)
	lfs      f3, lbl_80520524@sda21(r2)
	lfs      f5, 0xc(r5)
	fmuls    f8, f3, f4
	lfs      f6, 4(r5)
	fmuls    f2, f3, f5
	lfs      f0, 0(r5)
	fmuls    f7, f3, f6
	lfs      f1, lbl_80520510@sda21(r2)
	fmuls    f3, f3, f0
	fmuls    f9, f8, f4
	fmuls    f10, f2, f5
	fmuls    f11, f7, f4
	fmuls    f13, f3, f5
	fsubs    f0, f1, f9
	fmuls    f2, f7, f6
	fmuls    f12, f7, f5
	fmuls    f31, f3, f4
	fsubs    f7, f1, f2
	fsubs    f0, f0, f10
	fsubs    f2, f11, f13
	fadds    f1, f12, f31
	stfs     f0, 0(r3)
	fadds    f0, f11, f13
	fmuls    f5, f8, f5
	fmuls    f6, f3, f6
	stfs     f2, 4(r3)
	fsubs    f4, f7, f10
	stfs     f1, 8(r3)
	fsubs    f2, f12, f31
	fsubs    f3, f5, f6
	stfs     f0, 0x10(r3)
	fadds    f1, f5, f6
	fsubs    f0, f7, f9
	stfs     f4, 0x14(r3)
	stfs     f3, 0x18(r3)
	stfs     f2, 0x20(r3)
	stfs     f1, 0x24(r3)
	stfs     f0, 0x28(r3)
	lfs      f0, 0(r4)
	stfs     f0, 0xc(r3)
	lfs      f0, 4(r4)
	stfs     f0, 0x1c(r3)
	lfs      f0, 8(r4)
	stfs     f0, 0x2c(r3)
	psq_l    f31, 24(r1), 0, qr0
	lfd      f31, 0x10(r1)
	addi     r1, r1, 0x20
	blr
	*/
}

/*
 * --INFO--
 * Address:	80428B88
 * Size:	0000C8
 */
void Matrixf::makeQ(Quat&)
{
	/*
	stwu     r1, -0x20(r1)
	stfd     f31, 0x10(r1)
	psq_st   f31, 24(r1), 0, qr0
	lfs      f4, 8(r4)
	lfs      f3, lbl_80520524@sda21(r2)
	lfs      f5, 0xc(r4)
	fmuls    f8, f3, f4
	lfs      f6, 4(r4)
	fmuls    f1, f3, f5
	lfs      f0, 0(r4)
	fmuls    f7, f3, f6
	lfs      f2, lbl_80520510@sda21(r2)
	fmuls    f9, f3, f0
	lfs      f0, lbl_80520514@sda21(r2)
	fmuls    f10, f8, f4
	fmuls    f11, f1, f5
	fmuls    f12, f7, f4
	fmuls    f31, f9, f5
	fsubs    f1, f2, f10
	fmuls    f3, f7, f6
	fmuls    f13, f7, f5
	fmuls    f4, f9, f4
	fsubs    f7, f2, f3
	fsubs    f1, f1, f11
	fsubs    f3, f12, f31
	fadds    f2, f13, f4
	stfs     f1, 0(r3)
	fadds    f1, f12, f31
	fmuls    f8, f8, f5
	fmuls    f6, f9, f6
	stfs     f3, 4(r3)
	fsubs    f5, f7, f11
	stfs     f2, 8(r3)
	fsubs    f3, f13, f4
	fsubs    f4, f8, f6
	stfs     f1, 0x10(r3)
	fadds    f2, f8, f6
	fsubs    f1, f7, f10
	stfs     f5, 0x14(r3)
	stfs     f4, 0x18(r3)
	stfs     f3, 0x20(r3)
	stfs     f2, 0x24(r3)
	stfs     f1, 0x28(r3)
	stfs     f0, 0xc(r3)
	stfs     f0, 0x1c(r3)
	stfs     f0, 0x2c(r3)
	psq_l    f31, 24(r1), 0, qr0
	lfd      f31, 0x10(r1)
	addi     r1, r1, 0x20
	blr
	*/
}
