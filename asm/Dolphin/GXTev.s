.include "macros.inc"
.section .data, "wa"  # 0x8049E220 - 0x804EFC20
.balign 8
.global TEVCOpTableST0
TEVCOpTableST0:
	.4byte 0xC008F8AF
	.4byte 0xC008A89F
	.4byte 0xC008AC8F
	.4byte 0xC008FFF8
	.4byte 0xC008FFFA
.global TEVCOpTableST1
TEVCOpTableST1:
	.4byte 0xC008F80F
	.4byte 0xC008089F
	.4byte 0xC0080C8F
	.4byte 0xC008FFF8
	.4byte 0xC008FFF0
.global TEVAOpTableST0
TEVAOpTableST0:
	.4byte 0xC108F2F0
	.4byte 0xC108FFD0
	.4byte 0xC108F2F0
	.4byte 0xC108FFC0
	.4byte 0xC108FFD0
.global TEVAOpTableST1
TEVAOpTableST1:
	.4byte 0xC108F070
	.4byte 0xC108FF80
	.4byte 0xC108F070
	.4byte 0xC108FFC0
	.4byte 0xC108FF80
.global c2r$364
c2r$364:
	.4byte 0x00000000
	.4byte 0x00000001
	.4byte 0x00000000
	.4byte 0x00000001
	.4byte 0x00000000
	.4byte 0x00000001
	.4byte 0x00000007
	.4byte 0x00000005
	.4byte 0x00000006
	.4byte 0x00000000

.section .text, "ax"  # 0x800056C0 - 0x80472F00
.global GXSetTevOp
GXSetTevOp:
/* 800E847C 000E53BC  2C 03 00 00 */	cmpwi r3, 0
/* 800E8480 000E53C0  3C A0 80 4B */	lis r5, TEVCOpTableST0@ha
/* 800E8484 000E53C4  38 05 87 78 */	addi r0, r5, TEVCOpTableST0@l
/* 800E8488 000E53C8  40 82 00 14 */	bne .L_800E849C
/* 800E848C 000E53CC  54 84 10 3A */	slwi r4, r4, 2
/* 800E8490 000E53D0  7C A0 22 14 */	add r5, r0, r4
/* 800E8494 000E53D4  39 25 00 28 */	addi r9, r5, 0x28
/* 800E8498 000E53D8  48 00 00 18 */	b .L_800E84B0
.L_800E849C:
/* 800E849C 000E53DC  54 84 10 3A */	slwi r4, r4, 2
/* 800E84A0 000E53E0  7C A0 22 14 */	add r5, r0, r4
/* 800E84A4 000E53E4  7D 20 22 14 */	add r9, r0, r4
/* 800E84A8 000E53E8  38 A5 00 14 */	addi r5, r5, 0x14
/* 800E84AC 000E53EC  39 29 00 3C */	addi r9, r9, 0x3c
.L_800E84B0:
/* 800E84B0 000E53F0  80 E2 92 90 */	lwz r7, __GXData@sda21(r2)
/* 800E84B4 000E53F4  54 63 10 3A */	slwi r3, r3, 2
/* 800E84B8 000E53F8  80 05 00 00 */	lwz r0, 0(r5)
/* 800E84BC 000E53FC  38 A0 00 61 */	li r5, 0x61
/* 800E84C0 000E5400  7C C7 1A 14 */	add r6, r7, r3
/* 800E84C4 000E5404  80 66 01 30 */	lwz r3, 0x130(r6)
/* 800E84C8 000E5408  3C 80 CC 01 */	lis r4, 0xCC008000@ha
/* 800E84CC 000E540C  98 A4 80 00 */	stb r5, 0xCC008000@l(r4)
/* 800E84D0 000E5410  54 63 00 0E */	rlwinm r3, r3, 0, 0, 7
/* 800E84D4 000E5414  50 03 02 3E */	rlwimi r3, r0, 0, 8, 0x1f
/* 800E84D8 000E5418  90 64 80 00 */	stw r3, 0xCC008000@l(r4)
/* 800E84DC 000E541C  38 00 00 00 */	li r0, 0
/* 800E84E0 000E5420  90 66 01 30 */	stw r3, 0x130(r6)
/* 800E84E4 000E5424  81 06 01 70 */	lwz r8, 0x170(r6)
/* 800E84E8 000E5428  80 69 00 00 */	lwz r3, 0(r9)
/* 800E84EC 000E542C  55 08 07 0E */	rlwinm r8, r8, 0, 0x1c, 7
/* 800E84F0 000E5430  98 A4 80 00 */	stb r5, 0xCC008000@l(r4)
/* 800E84F4 000E5434  50 68 02 36 */	rlwimi r8, r3, 0, 8, 0x1b
/* 800E84F8 000E5438  91 04 80 00 */	stw r8, 0xCC008000@l(r4)
/* 800E84FC 000E543C  91 06 01 70 */	stw r8, 0x170(r6)
/* 800E8500 000E5440  B0 07 00 02 */	sth r0, 2(r7)
/* 800E8504 000E5444  4E 80 00 20 */	blr 

.global GXSetTevColorIn
GXSetTevColorIn:
/* 800E8508 000E5448  81 22 92 90 */	lwz r9, __GXData@sda21(r2)
/* 800E850C 000E544C  54 63 10 3A */	slwi r3, r3, 2
/* 800E8510 000E5450  38 00 00 61 */	li r0, 0x61
/* 800E8514 000E5454  7D 09 1A 14 */	add r8, r9, r3
/* 800E8518 000E5458  81 48 01 30 */	lwz r10, 0x130(r8)
/* 800E851C 000E545C  3C 60 CC 01 */	lis r3, 0xCC008000@ha
/* 800E8520 000E5460  50 8A 64 26 */	rlwimi r10, r4, 0xc, 0x10, 0x13
/* 800E8524 000E5464  98 03 80 00 */	stb r0, 0xCC008000@l(r3)
/* 800E8528 000E5468  38 8A 00 00 */	addi r4, r10, 0
/* 800E852C 000E546C  50 A4 45 2E */	rlwimi r4, r5, 8, 0x14, 0x17
/* 800E8530 000E5470  50 C4 26 36 */	rlwimi r4, r6, 4, 0x18, 0x1b
/* 800E8534 000E5474  50 E4 07 3E */	rlwimi r4, r7, 0, 0x1c, 0x1f
/* 800E8538 000E5478  90 83 80 00 */	stw r4, 0xCC008000@l(r3)
/* 800E853C 000E547C  38 00 00 00 */	li r0, 0
/* 800E8540 000E5480  90 88 01 30 */	stw r4, 0x130(r8)
/* 800E8544 000E5484  B0 09 00 02 */	sth r0, 2(r9)
/* 800E8548 000E5488  4E 80 00 20 */	blr 

.global GXSetTevAlphaIn
GXSetTevAlphaIn:
/* 800E854C 000E548C  81 22 92 90 */	lwz r9, __GXData@sda21(r2)
/* 800E8550 000E5490  54 63 10 3A */	slwi r3, r3, 2
/* 800E8554 000E5494  38 00 00 61 */	li r0, 0x61
/* 800E8558 000E5498  7D 09 1A 14 */	add r8, r9, r3
/* 800E855C 000E549C  81 48 01 70 */	lwz r10, 0x170(r8)
/* 800E8560 000E54A0  3C 60 CC 01 */	lis r3, 0xCC008000@ha
/* 800E8564 000E54A4  50 8A 6C 24 */	rlwimi r10, r4, 0xd, 0x10, 0x12
/* 800E8568 000E54A8  98 03 80 00 */	stb r0, 0xCC008000@l(r3)
/* 800E856C 000E54AC  38 8A 00 00 */	addi r4, r10, 0
/* 800E8570 000E54B0  50 A4 54 EA */	rlwimi r4, r5, 0xa, 0x13, 0x15
/* 800E8574 000E54B4  50 C4 3D B0 */	rlwimi r4, r6, 7, 0x16, 0x18
/* 800E8578 000E54B8  50 E4 26 76 */	rlwimi r4, r7, 4, 0x19, 0x1b
/* 800E857C 000E54BC  90 83 80 00 */	stw r4, 0xCC008000@l(r3)
/* 800E8580 000E54C0  38 00 00 00 */	li r0, 0
/* 800E8584 000E54C4  90 88 01 70 */	stw r4, 0x170(r8)
/* 800E8588 000E54C8  B0 09 00 02 */	sth r0, 2(r9)
/* 800E858C 000E54CC  4E 80 00 20 */	blr 

.global GXSetTevColorOp
GXSetTevColorOp:
/* 800E8590 000E54D0  80 02 92 90 */	lwz r0, __GXData@sda21(r2)
/* 800E8594 000E54D4  54 69 10 3A */	slwi r9, r3, 2
/* 800E8598 000E54D8  2C 04 00 01 */	cmpwi r4, 1
/* 800E859C 000E54DC  7C 60 4A 14 */	add r3, r0, r9
/* 800E85A0 000E54E0  80 63 01 30 */	lwz r3, 0x130(r3)
/* 800E85A4 000E54E4  50 83 93 5A */	rlwimi r3, r4, 0x12, 0xd, 0xd
/* 800E85A8 000E54E8  39 43 00 00 */	addi r10, r3, 0
/* 800E85AC 000E54EC  41 81 00 10 */	bgt .L_800E85BC
/* 800E85B0 000E54F0  50 CA A2 96 */	rlwimi r10, r6, 0x14, 0xa, 0xb
/* 800E85B4 000E54F4  50 AA 83 9E */	rlwimi r10, r5, 0x10, 0xe, 0xf
/* 800E85B8 000E54F8  48 00 00 10 */	b .L_800E85C8
.L_800E85BC:
/* 800E85BC 000E54FC  38 00 00 03 */	li r0, 3
/* 800E85C0 000E5500  50 8A 9A 96 */	rlwimi r10, r4, 0x13, 0xa, 0xb
/* 800E85C4 000E5504  50 0A 83 9E */	rlwimi r10, r0, 0x10, 0xe, 0xf
.L_800E85C8:
/* 800E85C8 000E5508  38 00 00 61 */	li r0, 0x61
/* 800E85CC 000E550C  80 82 92 90 */	lwz r4, __GXData@sda21(r2)
/* 800E85D0 000E5510  3C A0 CC 01 */	lis r5, 0xCC008000@ha
/* 800E85D4 000E5514  98 05 80 00 */	stb r0, 0xCC008000@l(r5)
/* 800E85D8 000E5518  50 EA 9B 18 */	rlwimi r10, r7, 0x13, 0xc, 0xc
/* 800E85DC 000E551C  51 0A B2 12 */	rlwimi r10, r8, 0x16, 8, 9
/* 800E85E0 000E5520  91 45 80 00 */	stw r10, 0xCC008000@l(r5)
/* 800E85E4 000E5524  7C 64 4A 14 */	add r3, r4, r9
/* 800E85E8 000E5528  38 00 00 00 */	li r0, 0
/* 800E85EC 000E552C  91 43 01 30 */	stw r10, 0x130(r3)
/* 800E85F0 000E5530  B0 04 00 02 */	sth r0, 2(r4)
/* 800E85F4 000E5534  4E 80 00 20 */	blr 

.global GXSetTevAlphaOp
GXSetTevAlphaOp:
/* 800E85F8 000E5538  80 02 92 90 */	lwz r0, __GXData@sda21(r2)
/* 800E85FC 000E553C  54 69 10 3A */	slwi r9, r3, 2
/* 800E8600 000E5540  2C 04 00 01 */	cmpwi r4, 1
/* 800E8604 000E5544  7C 60 4A 14 */	add r3, r0, r9
/* 800E8608 000E5548  80 63 01 70 */	lwz r3, 0x170(r3)
/* 800E860C 000E554C  50 83 93 5A */	rlwimi r3, r4, 0x12, 0xd, 0xd
/* 800E8610 000E5550  39 43 00 00 */	addi r10, r3, 0
/* 800E8614 000E5554  41 81 00 10 */	bgt .L_800E8624
/* 800E8618 000E5558  50 CA A2 96 */	rlwimi r10, r6, 0x14, 0xa, 0xb
/* 800E861C 000E555C  50 AA 83 9E */	rlwimi r10, r5, 0x10, 0xe, 0xf
/* 800E8620 000E5560  48 00 00 10 */	b .L_800E8630
.L_800E8624:
/* 800E8624 000E5564  38 00 00 03 */	li r0, 3
/* 800E8628 000E5568  50 8A 9A 96 */	rlwimi r10, r4, 0x13, 0xa, 0xb
/* 800E862C 000E556C  50 0A 83 9E */	rlwimi r10, r0, 0x10, 0xe, 0xf
.L_800E8630:
/* 800E8630 000E5570  38 00 00 61 */	li r0, 0x61
/* 800E8634 000E5574  80 82 92 90 */	lwz r4, __GXData@sda21(r2)
/* 800E8638 000E5578  3C A0 CC 01 */	lis r5, 0xCC008000@ha
/* 800E863C 000E557C  98 05 80 00 */	stb r0, 0xCC008000@l(r5)
/* 800E8640 000E5580  50 EA 9B 18 */	rlwimi r10, r7, 0x13, 0xc, 0xc
/* 800E8644 000E5584  51 0A B2 12 */	rlwimi r10, r8, 0x16, 8, 9
/* 800E8648 000E5588  91 45 80 00 */	stw r10, 0xCC008000@l(r5)
/* 800E864C 000E558C  7C 64 4A 14 */	add r3, r4, r9
/* 800E8650 000E5590  38 00 00 00 */	li r0, 0
/* 800E8654 000E5594  91 43 01 70 */	stw r10, 0x170(r3)
/* 800E8658 000E5598  B0 04 00 02 */	sth r0, 2(r4)
/* 800E865C 000E559C  4E 80 00 20 */	blr 

.global GXSetTevColor
GXSetTevColor:
/* 800E8660 000E55A0  88 A4 00 00 */	lbz r5, 0(r4)
/* 800E8664 000E55A4  54 67 08 3C */	slwi r7, r3, 1
/* 800E8668 000E55A8  88 04 00 03 */	lbz r0, 3(r4)
/* 800E866C 000E55AC  38 60 00 00 */	li r3, 0
/* 800E8670 000E55B0  50 A3 05 7E */	rlwimi r3, r5, 0, 0x15, 0x1f
/* 800E8674 000E55B4  39 03 00 00 */	addi r8, r3, 0
/* 800E8678 000E55B8  88 C4 00 02 */	lbz r6, 2(r4)
/* 800E867C 000E55BC  50 08 62 66 */	rlwimi r8, r0, 0xc, 9, 0x13
/* 800E8680 000E55C0  88 04 00 01 */	lbz r0, 1(r4)
/* 800E8684 000E55C4  39 20 00 00 */	li r9, 0
/* 800E8688 000E55C8  80 62 92 90 */	lwz r3, __GXData@sda21(r2)
/* 800E868C 000E55CC  50 C9 05 7E */	rlwimi r9, r6, 0, 0x15, 0x1f
/* 800E8690 000E55D0  38 C9 00 00 */	addi r6, r9, 0
/* 800E8694 000E55D4  50 06 62 66 */	rlwimi r6, r0, 0xc, 9, 0x13
/* 800E8698 000E55D8  38 07 00 E0 */	addi r0, r7, 0xe0
/* 800E869C 000E55DC  50 08 C0 0E */	rlwimi r8, r0, 0x18, 0, 7
/* 800E86A0 000E55E0  38 07 00 E1 */	addi r0, r7, 0xe1
/* 800E86A4 000E55E4  50 06 C0 0E */	rlwimi r6, r0, 0x18, 0, 7
/* 800E86A8 000E55E8  38 A0 00 61 */	li r5, 0x61
/* 800E86AC 000E55EC  3C 80 CC 01 */	lis r4, 0xCC008000@ha
/* 800E86B0 000E55F0  98 A4 80 00 */	stb r5, 0xCC008000@l(r4)
/* 800E86B4 000E55F4  38 00 00 00 */	li r0, 0
/* 800E86B8 000E55F8  91 04 80 00 */	stw r8, 0xCC008000@l(r4)
/* 800E86BC 000E55FC  98 A4 80 00 */	stb r5, 0xCC008000@l(r4)
/* 800E86C0 000E5600  90 C4 80 00 */	stw r6, 0xCC008000@l(r4)
/* 800E86C4 000E5604  98 A4 80 00 */	stb r5, 0xCC008000@l(r4)
/* 800E86C8 000E5608  90 C4 80 00 */	stw r6, 0xCC008000@l(r4)
/* 800E86CC 000E560C  98 A4 80 00 */	stb r5, 0xCC008000@l(r4)
/* 800E86D0 000E5610  90 C4 80 00 */	stw r6, 0xCC008000@l(r4)
/* 800E86D4 000E5614  B0 03 00 02 */	sth r0, 2(r3)
/* 800E86D8 000E5618  4E 80 00 20 */	blr 

.global GXSetTevColorS10
GXSetTevColorS10:
/* 800E86DC 000E561C  A8 04 00 00 */	lha r0, 0(r4)
/* 800E86E0 000E5620  54 68 08 3C */	slwi r8, r3, 1
/* 800E86E4 000E5624  38 A0 00 00 */	li r5, 0
/* 800E86E8 000E5628  A8 64 00 06 */	lha r3, 6(r4)
/* 800E86EC 000E562C  50 05 05 7E */	rlwimi r5, r0, 0, 0x15, 0x1f
/* 800E86F0 000E5630  39 25 00 00 */	addi r9, r5, 0
/* 800E86F4 000E5634  A8 C4 00 04 */	lha r6, 4(r4)
/* 800E86F8 000E5638  A8 04 00 02 */	lha r0, 2(r4)
/* 800E86FC 000E563C  38 A0 00 61 */	li r5, 0x61
/* 800E8700 000E5640  3C 80 CC 01 */	lis r4, 0xCC008000@ha
/* 800E8704 000E5644  50 69 62 66 */	rlwimi r9, r3, 0xc, 9, 0x13
/* 800E8708 000E5648  98 A4 80 00 */	stb r5, 0xCC008000@l(r4)
/* 800E870C 000E564C  38 E8 00 E0 */	addi r7, r8, 0xe0
/* 800E8710 000E5650  80 62 92 90 */	lwz r3, __GXData@sda21(r2)
/* 800E8714 000E5654  50 E9 C0 0E */	rlwimi r9, r7, 0x18, 0, 7
/* 800E8718 000E5658  91 24 80 00 */	stw r9, 0xCC008000@l(r4)
/* 800E871C 000E565C  38 E0 00 00 */	li r7, 0
/* 800E8720 000E5660  50 C7 05 7E */	rlwimi r7, r6, 0, 0x15, 0x1f
/* 800E8724 000E5664  38 C7 00 00 */	addi r6, r7, 0
/* 800E8728 000E5668  98 A4 80 00 */	stb r5, 0xCC008000@l(r4)
/* 800E872C 000E566C  50 06 62 66 */	rlwimi r6, r0, 0xc, 9, 0x13
/* 800E8730 000E5670  38 08 00 E1 */	addi r0, r8, 0xe1
/* 800E8734 000E5674  50 06 C0 0E */	rlwimi r6, r0, 0x18, 0, 7
/* 800E8738 000E5678  90 C4 80 00 */	stw r6, 0xCC008000@l(r4)
/* 800E873C 000E567C  38 00 00 00 */	li r0, 0
/* 800E8740 000E5680  98 A4 80 00 */	stb r5, 0xCC008000@l(r4)
/* 800E8744 000E5684  90 C4 80 00 */	stw r6, 0xCC008000@l(r4)
/* 800E8748 000E5688  98 A4 80 00 */	stb r5, 0xCC008000@l(r4)
/* 800E874C 000E568C  90 C4 80 00 */	stw r6, 0xCC008000@l(r4)
/* 800E8750 000E5690  B0 03 00 02 */	sth r0, 2(r3)
/* 800E8754 000E5694  4E 80 00 20 */	blr 

.global GXSetTevKColor
GXSetTevKColor:
/* 800E8758 000E5698  88 A4 00 00 */	lbz r5, 0(r4)
/* 800E875C 000E569C  54 66 08 3C */	slwi r6, r3, 1
/* 800E8760 000E56A0  88 04 00 03 */	lbz r0, 3(r4)
/* 800E8764 000E56A4  38 60 00 00 */	li r3, 0
/* 800E8768 000E56A8  50 A3 06 3E */	rlwimi r3, r5, 0, 0x18, 0x1f
/* 800E876C 000E56AC  38 E3 00 00 */	addi r7, r3, 0
/* 800E8770 000E56B0  88 A4 00 02 */	lbz r5, 2(r4)
/* 800E8774 000E56B4  50 07 63 26 */	rlwimi r7, r0, 0xc, 0xc, 0x13
/* 800E8778 000E56B8  88 04 00 01 */	lbz r0, 1(r4)
/* 800E877C 000E56BC  38 80 00 08 */	li r4, 8
/* 800E8780 000E56C0  80 62 92 90 */	lwz r3, __GXData@sda21(r2)
/* 800E8784 000E56C4  39 00 00 00 */	li r8, 0
/* 800E8788 000E56C8  50 A8 06 3E */	rlwimi r8, r5, 0, 0x18, 0x1f
/* 800E878C 000E56CC  50 08 63 26 */	rlwimi r8, r0, 0xc, 0xc, 0x13
/* 800E8790 000E56D0  50 87 A2 16 */	rlwimi r7, r4, 0x14, 8, 0xb
/* 800E8794 000E56D4  50 88 A2 16 */	rlwimi r8, r4, 0x14, 8, 0xb
/* 800E8798 000E56D8  38 A6 00 E0 */	addi r5, r6, 0xe0
/* 800E879C 000E56DC  50 A7 C0 0E */	rlwimi r7, r5, 0x18, 0, 7
/* 800E87A0 000E56E0  38 A6 00 E1 */	addi r5, r6, 0xe1
/* 800E87A4 000E56E4  38 00 00 61 */	li r0, 0x61
/* 800E87A8 000E56E8  3C 80 CC 01 */	lis r4, 0xCC008000@ha
/* 800E87AC 000E56EC  98 04 80 00 */	stb r0, 0xCC008000@l(r4)
/* 800E87B0 000E56F0  50 A8 C0 0E */	rlwimi r8, r5, 0x18, 0, 7
/* 800E87B4 000E56F4  90 E4 80 00 */	stw r7, 0xCC008000@l(r4)
/* 800E87B8 000E56F8  98 04 80 00 */	stb r0, 0xCC008000@l(r4)
/* 800E87BC 000E56FC  38 00 00 00 */	li r0, 0
/* 800E87C0 000E5700  91 04 80 00 */	stw r8, 0xCC008000@l(r4)
/* 800E87C4 000E5704  B0 03 00 02 */	sth r0, 2(r3)
/* 800E87C8 000E5708  4E 80 00 20 */	blr 

.global GXSetTevKColorSel
GXSetTevKColorSel:
/* 800E87CC 000E570C  7C 65 0E 70 */	srawi r5, r3, 1
/* 800E87D0 000E5710  80 C2 92 90 */	lwz r6, __GXData@sda21(r2)
/* 800E87D4 000E5714  54 60 07 FF */	clrlwi. r0, r3, 0x1f
/* 800E87D8 000E5718  54 A3 10 3A */	slwi r3, r5, 2
/* 800E87DC 000E571C  38 E3 01 B0 */	addi r7, r3, 0x1b0
/* 800E87E0 000E5720  7C E6 3A 14 */	add r7, r6, r7
/* 800E87E4 000E5724  41 82 00 14 */	beq .L_800E87F8
/* 800E87E8 000E5728  80 07 00 00 */	lwz r0, 0(r7)
/* 800E87EC 000E572C  50 80 73 62 */	rlwimi r0, r4, 0xe, 0xd, 0x11
/* 800E87F0 000E5730  90 07 00 00 */	stw r0, 0(r7)
/* 800E87F4 000E5734  48 00 00 10 */	b .L_800E8804
.L_800E87F8:
/* 800E87F8 000E5738  80 07 00 00 */	lwz r0, 0(r7)
/* 800E87FC 000E573C  50 80 25 F6 */	rlwimi r0, r4, 4, 0x17, 0x1b
/* 800E8800 000E5740  90 07 00 00 */	stw r0, 0(r7)
.L_800E8804:
/* 800E8804 000E5744  38 00 00 61 */	li r0, 0x61
/* 800E8808 000E5748  80 62 92 90 */	lwz r3, __GXData@sda21(r2)
/* 800E880C 000E574C  3C A0 CC 01 */	lis r5, 0xCC008000@ha
/* 800E8810 000E5750  98 05 80 00 */	stb r0, 0xCC008000@l(r5)
/* 800E8814 000E5754  38 00 00 00 */	li r0, 0
/* 800E8818 000E5758  80 87 00 00 */	lwz r4, 0(r7)
/* 800E881C 000E575C  90 85 80 00 */	stw r4, 0xCC008000@l(r5)
/* 800E8820 000E5760  B0 03 00 02 */	sth r0, 2(r3)
/* 800E8824 000E5764  4E 80 00 20 */	blr 

.global GXSetTevKAlphaSel
GXSetTevKAlphaSel:
/* 800E8828 000E5768  7C 65 0E 70 */	srawi r5, r3, 1
/* 800E882C 000E576C  80 C2 92 90 */	lwz r6, __GXData@sda21(r2)
/* 800E8830 000E5770  54 60 07 FF */	clrlwi. r0, r3, 0x1f
/* 800E8834 000E5774  54 A3 10 3A */	slwi r3, r5, 2
/* 800E8838 000E5778  38 E3 01 B0 */	addi r7, r3, 0x1b0
/* 800E883C 000E577C  7C E6 3A 14 */	add r7, r6, r7
/* 800E8840 000E5780  41 82 00 14 */	beq .L_800E8854
/* 800E8844 000E5784  80 07 00 00 */	lwz r0, 0(r7)
/* 800E8848 000E5788  50 80 9A 18 */	rlwimi r0, r4, 0x13, 8, 0xc
/* 800E884C 000E578C  90 07 00 00 */	stw r0, 0(r7)
/* 800E8850 000E5790  48 00 00 10 */	b .L_800E8860
.L_800E8854:
/* 800E8854 000E5794  80 07 00 00 */	lwz r0, 0(r7)
/* 800E8858 000E5798  50 80 4C AC */	rlwimi r0, r4, 9, 0x12, 0x16
/* 800E885C 000E579C  90 07 00 00 */	stw r0, 0(r7)
.L_800E8860:
/* 800E8860 000E57A0  38 00 00 61 */	li r0, 0x61
/* 800E8864 000E57A4  80 62 92 90 */	lwz r3, __GXData@sda21(r2)
/* 800E8868 000E57A8  3C A0 CC 01 */	lis r5, 0xCC008000@ha
/* 800E886C 000E57AC  98 05 80 00 */	stb r0, 0xCC008000@l(r5)
/* 800E8870 000E57B0  38 00 00 00 */	li r0, 0
/* 800E8874 000E57B4  80 87 00 00 */	lwz r4, 0(r7)
/* 800E8878 000E57B8  90 85 80 00 */	stw r4, 0xCC008000@l(r5)
/* 800E887C 000E57BC  B0 03 00 02 */	sth r0, 2(r3)
/* 800E8880 000E57C0  4E 80 00 20 */	blr 

.global GXSetTevSwapMode
GXSetTevSwapMode:
/* 800E8884 000E57C4  54 63 10 3A */	slwi r3, r3, 2
/* 800E8888 000E57C8  80 E2 92 90 */	lwz r7, __GXData@sda21(r2)
/* 800E888C 000E57CC  39 03 01 70 */	addi r8, r3, 0x170
/* 800E8890 000E57D0  7D 07 42 14 */	add r8, r7, r8
/* 800E8894 000E57D4  80 08 00 00 */	lwz r0, 0(r8)
/* 800E8898 000E57D8  50 80 07 BE */	rlwimi r0, r4, 0, 0x1e, 0x1f
/* 800E889C 000E57DC  38 60 00 61 */	li r3, 0x61
/* 800E88A0 000E57E0  90 08 00 00 */	stw r0, 0(r8)
/* 800E88A4 000E57E4  3C 80 CC 01 */	lis r4, 0xCC008000@ha
/* 800E88A8 000E57E8  38 00 00 00 */	li r0, 0
/* 800E88AC 000E57EC  80 C8 00 00 */	lwz r6, 0(r8)
/* 800E88B0 000E57F0  50 A6 17 3A */	rlwimi r6, r5, 2, 0x1c, 0x1d
/* 800E88B4 000E57F4  90 C8 00 00 */	stw r6, 0(r8)
/* 800E88B8 000E57F8  98 64 80 00 */	stb r3, 0xCC008000@l(r4)
/* 800E88BC 000E57FC  80 68 00 00 */	lwz r3, 0(r8)
/* 800E88C0 000E5800  90 64 80 00 */	stw r3, 0xCC008000@l(r4)
/* 800E88C4 000E5804  B0 07 00 02 */	sth r0, 2(r7)
/* 800E88C8 000E5808  4E 80 00 20 */	blr 

.global GXSetTevSwapModeTable
GXSetTevSwapModeTable:
/* 800E88CC 000E580C  54 69 08 3C */	lbz r0, 0x7(r2)
/* 800E88D0 000E5810  81 02 92 90 */	cmpwi r0, 1
/* 800E88D4 000E5814  54 63 18 38 */	bne 16
/* 800E88D8 000E5818  39 43 01 B0 */	li r4, 1
/* 800E88DC 000E581C  7D 48 52 14 */	li r5, 1
/* 800E88E0 000E5820  80 6A 00 00 */	li r6, 1
/* 800E88CC 000E580C  54 69 08 3C */	slwi r9, r3, 1
/* 800E88D0 000E5810  81 02 92 90 */	lwz r8, __GXData@sda21(r2)
/* 800E88D4 000E5814  54 63 18 38 */	slwi r3, r3, 3
/* 800E88D8 000E5818  39 43 01 B0 */	addi r10, r3, 0x1b0
/* 800E88DC 000E581C  7D 48 52 14 */	add r10, r8, r10
/* 800E88E0 000E5820  80 6A 00 00 */	lwz r3, 0(r10)
/* 800E88E4 000E5824  50 83 07 BE */	rlwimi r3, r4, 0, 0x1e, 0x1f
/* 800E88E8 000E5828  38 09 00 01 */	addi r0, r9, 1
/* 800E88EC 000E582C  90 6A 00 00 */	stw r3, 0(r10)
/* 800E88F0 000E5830  54 03 10 3A */	slwi r3, r0, 2
/* 800E88F4 000E5834  39 23 01 B0 */	addi r9, r3, 0x1b0
/* 800E88F8 000E5838  80 0A 00 00 */	lwz r0, 0(r10)
/* 800E88FC 000E583C  50 A0 17 3A */	rlwimi r0, r5, 2, 0x1c, 0x1d
/* 800E8900 000E5840  38 A0 00 61 */	li r5, 0x61
/* 800E8904 000E5844  90 0A 00 00 */	stw r0, 0(r10)
/* 800E8908 000E5848  3C 80 CC 01 */	lis r4, 0xCC008000@ha
/* 800E890C 000E584C  7D 28 4A 14 */	add r9, r8, r9
/* 800E8910 000E5850  98 A4 80 00 */	stb r5, 0xCC008000@l(r4)
/* 800E8914 000E5854  38 00 00 00 */	li r0, 0
/* 800E8918 000E5858  80 6A 00 00 */	lwz r3, 0(r10)
/* 800E891C 000E585C  90 64 80 00 */	stw r3, 0xCC008000@l(r4)
/* 800E8920 000E5860  80 69 00 00 */	lwz r3, 0(r9)
/* 800E8924 000E5864  50 C3 07 BE */	rlwimi r3, r6, 0, 0x1e, 0x1f
/* 800E8928 000E5868  90 69 00 00 */	stw r3, 0(r9)
/* 800E892C 000E586C  80 69 00 00 */	lwz r3, 0(r9)
/* 800E8930 000E5870  50 E3 17 3A */	rlwimi r3, r7, 2, 0x1c, 0x1d
/* 800E8934 000E5874  90 69 00 00 */	stw r3, 0(r9)
/* 800E8938 000E5878  98 A4 80 00 */	stb r5, 0xCC008000@l(r4)
/* 800E893C 000E587C  80 69 00 00 */	lwz r3, 0(r9)
/* 800E8940 000E5880  90 64 80 00 */	stw r3, 0xCC008000@l(r4)
/* 800E8944 000E5884  B0 08 00 02 */	sth r0, 2(r8)
/* 800E8948 000E5888  4E 80 00 20 */	blr 

.global GXSetAlphaCompare
GXSetAlphaCompare:
/* 800E894C 000E588C  54 80 06 3E */	clrlwi r0, r4, 0x18
/* 800E8950 000E5890  80 82 92 90 */	lwz r4, __GXData@sda21(r2)
/* 800E8954 000E5894  3D 00 F3 00 */	lis r8, 0xf300
/* 800E8958 000E5898  50 08 06 3E */	rlwimi r8, r0, 0, 0x18, 0x1f
/* 800E895C 000E589C  54 E0 06 3E */	clrlwi r0, r7, 0x18
/* 800E8960 000E58A0  38 E8 00 00 */	addi r7, r8, 0
/* 800E8964 000E58A4  50 07 44 2E */	rlwimi r7, r0, 8, 0x10, 0x17
/* 800E8968 000E58A8  50 67 83 5E */	rlwimi r7, r3, 0x10, 0xd, 0xf
/* 800E896C 000E58AC  50 C7 9A 98 */	rlwimi r7, r6, 0x13, 0xa, 0xc
/* 800E8970 000E58B0  38 00 00 61 */	li r0, 0x61
/* 800E8974 000E58B4  3C 60 CC 01 */	lis r3, 0xCC008000@ha
/* 800E8978 000E58B8  98 03 80 00 */	stb r0, 0xCC008000@l(r3)
/* 800E897C 000E58BC  50 A7 B2 12 */	rlwimi r7, r5, 0x16, 8, 9
/* 800E8980 000E58C0  38 00 00 00 */	li r0, 0
/* 800E8984 000E58C4  90 E3 80 00 */	stw r7, 0xCC008000@l(r3)
/* 800E8988 000E58C8  B0 04 00 02 */	sth r0, 2(r4)
/* 800E898C 000E58CC  4E 80 00 20 */	blr 

.global GXSetZTexture
GXSetZTexture:
/* 800E8990 000E58D0  2C 04 00 13 */	cmpwi r4, 0x13
/* 800E8994 000E58D4  38 00 00 F4 */	li r0, 0xf4
/* 800E8998 000E58D8  38 C0 00 00 */	li r6, 0
/* 800E899C 000E58DC  50 A6 02 3E */	rlwimi r6, r5, 0, 8, 0x1f
/* 800E89A0 000E58E0  50 06 C0 0E */	rlwimi r6, r0, 0x18, 0, 7
/* 800E89A4 000E58E4  38 E0 00 00 */	li r7, 0
/* 800E89A8 000E58E8  41 82 00 28 */	beq .L_800E89D0
/* 800E89AC 000E58EC  40 80 00 10 */	bge .L_800E89BC
/* 800E89B0 000E58F0  2C 04 00 11 */	cmpwi r4, 0x11
/* 800E89B4 000E58F4  41 82 00 14 */	beq .L_800E89C8
/* 800E89B8 000E58F8  48 00 00 28 */	b .L_800E89E0
.L_800E89BC:
/* 800E89BC 000E58FC  2C 04 00 16 */	cmpwi r4, 0x16
/* 800E89C0 000E5900  41 82 00 18 */	beq .L_800E89D8
/* 800E89C4 000E5904  48 00 00 1C */	b .L_800E89E0
.L_800E89C8:
/* 800E89C8 000E5908  39 00 00 00 */	li r8, 0
/* 800E89CC 000E590C  48 00 00 18 */	b .L_800E89E4
.L_800E89D0:
/* 800E89D0 000E5910  39 00 00 01 */	li r8, 1
/* 800E89D4 000E5914  48 00 00 10 */	b .L_800E89E4
.L_800E89D8:
/* 800E89D8 000E5918  39 00 00 02 */	li r8, 2
/* 800E89DC 000E591C  48 00 00 08 */	b .L_800E89E4
.L_800E89E0:
/* 800E89E0 000E5920  39 00 00 02 */	li r8, 2
.L_800E89E4:
/* 800E89E4 000E5924  38 00 00 61 */	li r0, 0x61
/* 800E89E8 000E5928  80 82 92 90 */	lwz r4, __GXData@sda21(r2)
/* 800E89EC 000E592C  3C A0 CC 01 */	lis r5, 0xCC008000@ha
/* 800E89F0 000E5930  98 05 80 00 */	stb r0, 0xCC008000@l(r5)
/* 800E89F4 000E5934  51 07 07 BE */	rlwimi r7, r8, 0, 0x1e, 0x1f
/* 800E89F8 000E5938  50 67 17 3A */	rlwimi r7, r3, 2, 0x1c, 0x1d
/* 800E89FC 000E593C  90 C5 80 00 */	stw r6, 0xCC008000@l(r5)
/* 800E8A00 000E5940  38 60 00 F5 */	li r3, 0xf5
/* 800E8A04 000E5944  50 67 C0 0E */	rlwimi r7, r3, 0x18, 0, 7
/* 800E8A08 000E5948  98 05 80 00 */	stb r0, 0xCC008000@l(r5)
/* 800E8A0C 000E594C  38 00 00 00 */	li r0, 0
/* 800E8A10 000E5950  90 E5 80 00 */	stw r7, 0xCC008000@l(r5)
/* 800E8A14 000E5954  B0 04 00 02 */	sth r0, 2(r4)
/* 800E8A18 000E5958  4E 80 00 20 */	blr 

.global GXSetTevOrder
GXSetTevOrder:
/* 800E8A1C 000E595C  7C 67 0E 70 */	srawi r7, r3, 1
/* 800E8A20 000E5960  81 22 92 90 */	lwz r9, __GXData@sda21(r2)
/* 800E8A24 000E5964  54 AA 06 2C */	rlwinm r10, r5, 0, 0x18, 0x16
/* 800E8A28 000E5968  7C E7 01 94 */	addze r7, r7
/* 800E8A2C 000E596C  54 60 10 3A */	slwi r0, r3, 2
/* 800E8A30 000E5970  7D 09 02 14 */	add r8, r9, r0
/* 800E8A34 000E5974  54 E7 10 3A */	slwi r7, r7, 2
/* 800E8A38 000E5978  90 A8 05 54 */	stw r5, 0x554(r8)
/* 800E8A3C 000E597C  38 E7 01 00 */	addi r7, r7, 0x100
/* 800E8A40 000E5980  28 0A 00 08 */	cmplwi r10, 8
/* 800E8A44 000E5984  38 0A 00 00 */	addi r0, r10, 0
/* 800E8A48 000E5988  7C E9 3A 14 */	add r7, r9, r7
/* 800E8A4C 000E598C  41 80 00 0C */	blt .L_800E8A58
/* 800E8A50 000E5990  39 20 00 00 */	li r9, 0
/* 800E8A54 000E5994  48 00 00 08 */	b .L_800E8A5C
.L_800E8A58:
/* 800E8A58 000E5998  7C 09 03 78 */	mr r9, r0
.L_800E8A5C:
/* 800E8A5C 000E599C  2C 04 00 08 */	cmpwi r4, 8
/* 800E8A60 000E59A0  41 80 00 28 */	blt .L_800E8A88
/* 800E8A64 000E59A4  80 82 92 90 */	lwz r4, __GXData@sda21(r2)
/* 800E8A68 000E59A8  38 00 00 01 */	li r0, 1
/* 800E8A6C 000E59AC  7C 00 18 30 */	slw r0, r0, r3
/* 800E8A70 000E59B0  81 04 05 98 */	lwz r8, 0x598(r4)
/* 800E8A74 000E59B4  39 44 05 98 */	addi r10, r4, 0x598
/* 800E8A78 000E59B8  38 80 00 00 */	li r4, 0
/* 800E8A7C 000E59BC  7D 00 00 78 */	andc r0, r8, r0
/* 800E8A80 000E59C0  90 0A 00 00 */	stw r0, 0(r10)
/* 800E8A84 000E59C4  48 00 00 20 */	b .L_800E8AA4
.L_800E8A88:
/* 800E8A88 000E59C8  81 02 92 90 */	lwz r8, __GXData@sda21(r2)
/* 800E8A8C 000E59CC  38 00 00 01 */	li r0, 1
/* 800E8A90 000E59D0  7C 00 18 30 */	slw r0, r0, r3
/* 800E8A94 000E59D4  39 48 05 98 */	addi r10, r8, 0x598
/* 800E8A98 000E59D8  81 08 05 98 */	lwz r8, 0x598(r8)
/* 800E8A9C 000E59DC  7D 00 03 78 */	or r0, r8, r0
/* 800E8AA0 000E59E0  90 0A 00 00 */	stw r0, 0(r10)
.L_800E8AA4:
/* 800E8AA4 000E59E4  54 60 07 FF */	clrlwi. r0, r3, 0x1f
/* 800E8AA8 000E59E8  41 82 00 74 */	beq .L_800E8B1C
/* 800E8AAC 000E59EC  80 07 00 00 */	lwz r0, 0(r7)
/* 800E8AB0 000E59F0  51 20 64 66 */	rlwimi r0, r9, 0xc, 0x11, 0x13
/* 800E8AB4 000E59F4  2C 06 00 FF */	cmpwi r6, 0xff
/* 800E8AB8 000E59F8  90 07 00 00 */	stw r0, 0(r7)
/* 800E8ABC 000E59FC  80 07 00 00 */	lwz r0, 0(r7)
/* 800E8AC0 000E5A00  50 80 7B A0 */	rlwimi r0, r4, 0xf, 0xe, 0x10
/* 800E8AC4 000E5A04  90 07 00 00 */	stw r0, 0(r7)
/* 800E8AC8 000E5A08  40 82 00 0C */	bne .L_800E8AD4
/* 800E8ACC 000E5A0C  38 60 00 07 */	li r3, 7
/* 800E8AD0 000E5A10  48 00 00 18 */	b .L_800E8AE8
.L_800E8AD4:
/* 800E8AD4 000E5A14  3C 60 80 4B */	lis r3, c2r$364@ha
/* 800E8AD8 000E5A18  54 C4 10 3A */	slwi r4, r6, 2
/* 800E8ADC 000E5A1C  38 03 87 C8 */	addi r0, r3, c2r$364@l
/* 800E8AE0 000E5A20  7C 60 22 14 */	add r3, r0, r4
/* 800E8AE4 000E5A24  80 63 00 00 */	lwz r3, 0(r3)
.L_800E8AE8:
/* 800E8AE8 000E5A28  80 07 00 00 */	lwz r0, 0(r7)
/* 800E8AEC 000E5A2C  50 60 9A 98 */	rlwimi r0, r3, 0x13, 0xa, 0xc
/* 800E8AF0 000E5A30  2C 05 00 FF */	cmpwi r5, 0xff
/* 800E8AF4 000E5A34  90 07 00 00 */	stw r0, 0(r7)
/* 800E8AF8 000E5A38  38 60 00 00 */	li r3, 0
/* 800E8AFC 000E5A3C  41 82 00 10 */	beq .L_800E8B0C
/* 800E8B00 000E5A40  54 A0 05 EF */	rlwinm. r0, r5, 0, 0x17, 0x17
/* 800E8B04 000E5A44  40 82 00 08 */	bne .L_800E8B0C
/* 800E8B08 000E5A48  38 60 00 01 */	li r3, 1
.L_800E8B0C:
/* 800E8B0C 000E5A4C  80 07 00 00 */	lwz r0, 0(r7)
/* 800E8B10 000E5A50  50 60 93 5A */	rlwimi r0, r3, 0x12, 0xd, 0xd
/* 800E8B14 000E5A54  90 07 00 00 */	stw r0, 0(r7)
/* 800E8B18 000E5A58  48 00 00 70 */	b .L_800E8B88
.L_800E8B1C:
/* 800E8B1C 000E5A5C  80 07 00 00 */	lwz r0, 0(r7)
/* 800E8B20 000E5A60  51 20 07 7E */	rlwimi r0, r9, 0, 0x1d, 0x1f
/* 800E8B24 000E5A64  2C 06 00 FF */	cmpwi r6, 0xff
/* 800E8B28 000E5A68  90 07 00 00 */	stw r0, 0(r7)
/* 800E8B2C 000E5A6C  80 07 00 00 */	lwz r0, 0(r7)
/* 800E8B30 000E5A70  50 80 1E B8 */	rlwimi r0, r4, 3, 0x1a, 0x1c
/* 800E8B34 000E5A74  90 07 00 00 */	stw r0, 0(r7)
/* 800E8B38 000E5A78  40 82 00 0C */	bne .L_800E8B44
/* 800E8B3C 000E5A7C  38 60 00 07 */	li r3, 7
/* 800E8B40 000E5A80  48 00 00 18 */	b .L_800E8B58
.L_800E8B44:
/* 800E8B44 000E5A84  3C 60 80 4B */	lis r3, c2r$364@ha
/* 800E8B48 000E5A88  54 C4 10 3A */	slwi r4, r6, 2
/* 800E8B4C 000E5A8C  38 03 87 C8 */	addi r0, r3, c2r$364@l
/* 800E8B50 000E5A90  7C 60 22 14 */	add r3, r0, r4
/* 800E8B54 000E5A94  80 63 00 00 */	lwz r3, 0(r3)
.L_800E8B58:
/* 800E8B58 000E5A98  80 07 00 00 */	lwz r0, 0(r7)
/* 800E8B5C 000E5A9C  50 60 3D B0 */	rlwimi r0, r3, 7, 0x16, 0x18
/* 800E8B60 000E5AA0  2C 05 00 FF */	cmpwi r5, 0xff
/* 800E8B64 000E5AA4  90 07 00 00 */	stw r0, 0(r7)
/* 800E8B68 000E5AA8  38 60 00 00 */	li r3, 0
/* 800E8B6C 000E5AAC  41 82 00 10 */	beq .L_800E8B7C
/* 800E8B70 000E5AB0  54 A0 05 EF */	rlwinm. r0, r5, 0, 0x17, 0x17
/* 800E8B74 000E5AB4  40 82 00 08 */	bne .L_800E8B7C
/* 800E8B78 000E5AB8  38 60 00 01 */	li r3, 1
.L_800E8B7C:
/* 800E8B7C 000E5ABC  80 07 00 00 */	lwz r0, 0(r7)
/* 800E8B80 000E5AC0  50 60 36 72 */	rlwimi r0, r3, 6, 0x19, 0x19
/* 800E8B84 000E5AC4  90 07 00 00 */	stw r0, 0(r7)
.L_800E8B88:
/* 800E8B88 000E5AC8  38 00 00 61 */	li r0, 0x61
/* 800E8B8C 000E5ACC  80 62 92 90 */	lwz r3, __GXData@sda21(r2)
/* 800E8B90 000E5AD0  3C A0 CC 01 */	lis r5, 0xCC008000@ha
/* 800E8B94 000E5AD4  98 05 80 00 */	stb r0, 0xCC008000@l(r5)
/* 800E8B98 000E5AD8  38 00 00 00 */	li r0, 0
/* 800E8B9C 000E5ADC  80 87 00 00 */	lwz r4, 0(r7)
/* 800E8BA0 000E5AE0  90 85 80 00 */	stw r4, 0xCC008000@l(r5)
/* 800E8BA4 000E5AE4  B0 03 00 02 */	sth r0, 2(r3)
/* 800E8BA8 000E5AE8  80 03 05 AC */	lwz r0, 0x5ac(r3)
/* 800E8BAC 000E5AEC  60 00 00 01 */	ori r0, r0, 1
/* 800E8BB0 000E5AF0  90 03 05 AC */	stw r0, 0x5ac(r3)
/* 800E8BB4 000E5AF4  4E 80 00 20 */	blr 

.global GXSetNumTevStages
GXSetNumTevStages:
/* 800E8BB8 000E5AF8  80 82 92 90 */	lwz r4, __GXData@sda21(r2)
/* 800E8BBC 000E5AFC  54 63 06 3E */	clrlwi r3, r3, 0x18
/* 800E8BC0 000E5B00  38 03 FF FF */	addi r0, r3, -1
/* 800E8BC4 000E5B04  80 64 02 04 */	lwz r3, 0x204(r4)
/* 800E8BC8 000E5B08  50 03 54 AA */	rlwimi r3, r0, 0xa, 0x12, 0x15
/* 800E8BCC 000E5B0C  90 64 02 04 */	stw r3, 0x204(r4)
/* 800E8BD0 000E5B10  80 04 05 AC */	lwz r0, 0x5ac(r4)
/* 800E8BD4 000E5B14  60 00 00 04 */	ori r0, r0, 4
/* 800E8BD8 000E5B18  90 04 05 AC */	stw r0, 0x5ac(r4)
/* 800E8BDC 000E5B1C  4E 80 00 20 */	blr 
