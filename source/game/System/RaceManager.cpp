#include "RaceManager.h"
#include "RaceInfo.h"
#include <Kart/KartMove.h>
#include <Kart/KartObjectManager.h>
#include <Object/BattleBalloon.h>
#include <Race/ModeInfo.h>

namespace System
{

EXTERN_DATA(
  0x809BD730, //
  RaceManager* RaceManager::s_instance
);

EXTERN_TEXT(
  0x8053308C, //
  void RaceMode::Init()
);

EXTERN_TEXT(
  0x805336D8, //
  void RaceMode::CalcPosition()
);

EXTERN_TEXT(
  0x80533BE8, //
  void RaceMode::VT_0x20()
);

EXTERN_TEXT(
  0x80533C34, //
  void RaceMode::FinishIfNeeded(s32 finishedCount, s32 playerCount)
);

EXTERN_TEXT(
  0x80535D14, //
  bool RaceMode::IsFinishReady()
);

EXTERN_TEXT(
  0x80535DE8, //
  void RaceMode::ForceFinish()
);

EXTERN_TEXT(
  0x80535E84, //
  void RaceMode::Calc()
);

EXTERN_TEXT(
  0x80535EF4, //
  void* RaceMode::GetJugemPoint()
);

REPLACE_ASM( //
  0x805362DC, //
  // 3 parameters undocumented
  void RaceManager::GetKartStartPosition(),
  // clang-format off
/* 805362DC 9421FFD0 */  stwu     r1, -48(r1);
/* 805362E0 7C0802A6 */  mflr     r0;
/* 805362E4 90010034 */  stw      r0, 52(r1);
/* 805362E8 39610030 */  addi     r11, r1, 48;
/* 805362EC 4BAEB2A9 */  bl       UNDEF_80021594;
/* 805362F0 3F20809C */  lis      r25, s_instance__Q26System15RaceInfoManager@ha;
/* 805362F4 7C9A2378 */  mr       r26, r4;
/* 805362F8 80F9D728 */  lwz      r7, s_instance__Q26System15RaceInfoManager@l(r25);
/* 805362FC 7CBB2B78 */  mr       r27, r5;
/* 80536300 7CDC3378 */  mr       r28, r6;
/* 80536304 80070B70 */  lwz      r0, 2928(r7);
/* 80536308 2800000C */  cmplwi   r0, 12;
/* 8053630C 41810234 */  bgt-     UNDEF_80536540;
/* 80536310 3C80808B */  lis      r4, UNDEF_808b32e8@ha;
/* 80536314 5400103A */  slwi     r0, r0, 2;
/* 80536318 388432E8 */  addi     r4, r4, UNDEF_808b32e8@l;
/* 8053631C 7C84002E */  lwzx     r4, r4, r0;
/* 80536320 7C8903A6 */  mtctr    r4;
/* 80536324 4E800420 */  bctr;
UNDEF_808b32e8:;
                         // switch jumptable
                         .long    UNDEF_80536540;
                         .long    UNDEF_80536540;
                         .long    UNDEF_80536494;
                         .long    UNDEF_80536328;
                         .long    UNDEF_805364A4;
                         .long    UNDEF_80536494;
                         .long    UNDEF_80536540;
                         .long    UNDEF_80536540;
                         .long    UNDEF_80536540;
                         .long    UNDEF_80536328;
                         .long    UNDEF_80536328;
                         .long    UNDEF_80536450;
                         .long    UNDEF_80536484;

UNDEF_80536328:;
/* 80536328 3C80809C */  lis      r4, UNDEF_809bd6e8@ha;
/* 8053632C 3BE00001 */  li       r31, 1;
/* 80536330 8084D6E8 */  lwz      r4, UNDEF_809bd6e8@l(r4);
/* 80536334 3BA00001 */  li       r29, 1;
/* 80536338 80840008 */  lwz      r4, 8(r4);
/* 8053633C 2C040000 */  cmpwi    r4, 0;
/* 80536340 4182000C */  beq-     UNDEF_8053634c;
/* 80536344 A0040004 */  lhz      r0, 4(r4);
/* 80536348 48000008 */  b        UNDEF_80536350;
UNDEF_8053634c:;
/* 8053634C 38000000 */  li       r0, 0;
UNDEF_80536350:;
/* 80536350 28000001 */  cmplwi   r0, 1;
/* 80536354 4181000C */  bgt-     UNDEF_80536360;
/* 80536358 3BC00000 */  li       r30, 0;
/* 8053635C 480001FC */  b        UNDEF_80536558;
UNDEF_80536360:;
/* 80536360 3C80809C */  lis      r4, s_instance__Q26System15RaceInfoManager@ha;
/* 80536364 3BC00000 */  li       r30, 0;
                         lwz      r4, s_instance__Q26System15RaceInfoManager@l(r4);
                         // Check if teams is enabled
                         lwz      r10, 0xB90(r4);
                         rlwinm.  r0, r10, 0, 30, 30;
                         rlwinm   r8, r6, 0, 31, 31;
                         beq-     UNDEF_80536384;
/* 8053636C 1C0600F0 */  mulli    r0, r6, 240;
/* 80536374 39240028 */  addi     r9, r4, 40;
/* 80536378 7C890214 */  add      r4, r9, r0;
/* 80536380 810400CC */  lwz      r8, 204(r4);
UNDEF_80536384:;
                         li       r5, 0;
                         li       r7, 0;
/* 80536384 7CC903A6 */  mtctr    r6;
/* 80536388 28060000 */  cmplwi   r6, 0;
/* 8053638C 4081002C */  ble-     UNDEF_805363b8;
UNDEF_80536390:;
/* 80536390 54A0063E */  clrlwi   r0, r5, 24;
/* 80536394 1C0000F0 */  mulli    r0, r0, 240;
/* 80536398 7C890214 */  add      r4, r9, r0;
                         rlwinm.  r0, r10, 0, 30, 30;
                         rlwinm   r0, r5, 0, 31, 31;
                         beq-     UNDEF_805363a0;
/* 8053639C 800400CC */  lwz      r0, 204(r4);
UNDEF_805363a0:;
/* 805363A0 7C080000 */  cmpw     r8, r0;
/* 805363A4 4082000C */  bne-     UNDEF_805363b0;
/* 805363A8 38070001 */  addi     r0, r7, 1;
/* 805363AC 5407063E */  clrlwi   r7, r0, 24;
UNDEF_805363b0:;
/* 805363B0 38A50001 */  addi     r5, r5, 1;
/* 805363B4 4200FFDC */  bdnz+    UNDEF_80536390;
UNDEF_805363b8:;
/* 805363B8 2C080001 */  cmpwi    r8, 1;
/* 805363BC 38A00000 */  li       r5, 0;
/* 805363C0 40820008 */  bne-     UNDEF_805363c8;
/* 805363C4 38A00006 */  li       r5, 6;
UNDEF_805363c8:;
/* 805363C8 88830024 */  lbz      r4, 36(r3);
/* 805363CC 3C602AAB */  lis      r3, 10923;
/* 805363D0 3803AAAB */  subi     r0, r3, 21845;
/* 805363D4 3B800000 */  li       r28, 0;
/* 805363D8 7C843A14 */  add      r4, r4, r7;
/* 805363DC 3F20809C */  lis      r25, s_instance__Q26System15RaceInfoManager@ha;
/* 805363E0 7C602096 */  mulhw    r3, r0, r4;
/* 805363E4 54600FFE */  srwi     r0, r3, 31;
/* 805363E8 7C030214 */  add      r0, r3, r0;
/* 805363EC 1C000006 */  mulli    r0, r0, 6;
/* 805363F0 7C002050 */  sub      r0, r4, r0;
/* 805363F4 7C050214 */  add      r0, r5, r0;
/* 805363F8 5418063E */  clrlwi   r24, r0, 24;
/* 805363FC 48000028 */  b        UNDEF_80536424;
UNDEF_80536400:;
/* 80536400 5784063E */  clrlwi   r4, r28, 24;
/* 80536404 4BFDE72D */  bl       UNDEF_80514b30;
/* 80536408 80630000 */  lwz      r3, 0(r3);
/* 8053640C A8030018 */  lha      r0, 24(r3);
/* 80536410 7C180000 */  cmpw     r24, r0;
/* 80536414 4082000C */  bne-     UNDEF_80536420;
/* 80536418 7F9EE378 */  mr       r30, r28;
/* 8053641C 4800013C */  b        UNDEF_80536558;
UNDEF_80536420:;
/* 80536420 3B9C0001 */  addi     r28, r28, 1;
UNDEF_80536424:;
/* 80536424 8079D6E8 */  lwz      r3, UNDEF_809bd6e8@l(r25);
/* 80536428 5785063E */  clrlwi   r5, r28, 24;
/* 8053642C 80830008 */  lwz      r4, 8(r3);
/* 80536430 2C040000 */  cmpwi    r4, 0;
/* 80536434 4082000C */  bne-     UNDEF_80536440;
/* 80536438 38000000 */  li       r0, 0;
/* 8053643C 48000008 */  b        UNDEF_80536444;
UNDEF_80536440:;
/* 80536440 A0040004 */  lhz      r0, 4(r4);
UNDEF_80536444:;
/* 80536444 7C050000 */  cmpw     r5, r0;
/* 80536448 4180FFB8 */  blt+     UNDEF_80536400;
/* 8053644C 4800010C */  b        UNDEF_80536558;
UNDEF_80536450:;
/* 80536450 80070B74 */  lwz      r0, 2932(r7);
/* 80536454 3BE00001 */  li       r31, 1;
/* 80536458 3BA00001 */  li       r29, 1;
/* 8053645C 38600003 */  li       r3, 3;
/* 80536460 2C00000C */  cmpwi    r0, 12;
/* 80536464 40820008 */  bne-     UNDEF_8053646c;
/* 80536468 38600006 */  li       r3, 6;
UNDEF_8053646c:;
/* 8053646C 7C061800 */  cmpw     r6, r3;
/* 80536470 4080000C */  bge-     UNDEF_8053647c;
/* 80536474 7F9EE378 */  mr       r30, r28;
/* 80536478 480000E0 */  b        UNDEF_80536558;
UNDEF_8053647c:;
/* 8053647C 3BC00000 */  li       r30, 0;
/* 80536480 480000D8 */  b        UNDEF_80536558;
UNDEF_80536484:;
/* 80536484 7F9EE378 */  mr       r30, r28;
/* 80536488 3BE00001 */  li       r31, 1;
/* 8053648C 3BA00001 */  li       r29, 1;
/* 80536490 480000C8 */  b        UNDEF_80536558;
UNDEF_80536494:;
/* 80536494 3BE00001 */  li       r31, 1;
/* 80536498 3BA00001 */  li       r29, 1;
/* 8053649C 3BC00000 */  li       r30, 0;
/* 805364A0 480000B8 */  b        UNDEF_80536558;
UNDEF_805364A4:;
/* 805364A4 3FC0809C */  lis      r30, UNDEF_809bd6e8@ha;
/* 805364A8 38800000 */  li       r4, 0;
/* 805364AC 807ED6E8 */  lwz      r3, UNDEF_809bd6e8@l(r30);
/* 805364B0 4BFDE681 */  bl       UNDEF_80514b30;
/* 805364B4 80630000 */  lwz      r3, 0(r3);
/* 805364B8 A8030018 */  lha      r0, 24(r3);
/* 805364BC 2C00FFFF */  cmpwi    r0, -1;
/* 805364C0 40820020 */  bne-     UNDEF_805364e0;
/* 805364C4 8079D728 */  lwz      r3, s_instance__Q26System15RaceInfoManager@l(r25);
/* 805364C8 3BC00000 */  li       r30, 0;
/* 805364CC 8BA30024 */  lbz      r29, 36(r3);
/* 805364D0 7C7CE850 */  sub      r3, r29, r28;
/* 805364D4 38030001 */  addi     r0, r3, 1;
/* 805364D8 541F063E */  clrlwi   r31, r0, 24;
/* 805364DC 4800007C */  b        UNDEF_80536558;
UNDEF_805364e0:;
/* 805364E0 3BE00001 */  li       r31, 1;
/* 805364E4 3BA00001 */  li       r29, 1;
/* 805364E8 3B000000 */  li       r24, 0;
/* 805364EC 48000028 */  b        UNDEF_80536514;
UNDEF_805364f0:;
/* 805364F0 5704063E */  clrlwi   r4, r24, 24;
/* 805364F4 4BFDE63D */  bl       UNDEF_80514b30;
/* 805364F8 80630000 */  lwz      r3, 0(r3);
/* 805364FC A8030018 */  lha      r0, 24(r3);
/* 80536500 7C1C0000 */  cmpw     r28, r0;
/* 80536504 4082000C */  bne-     UNDEF_80536510;
/* 80536508 7F9EE378 */  mr       r30, r28;
/* 8053650C 4800004C */  b        UNDEF_80536558;
UNDEF_80536510:;
/* 80536510 3B180001 */  addi     r24, r24, 1;
UNDEF_80536514:;
/* 80536514 807ED6E8 */  lwz      r3, -10520(r30);
/* 80536518 5705063E */  clrlwi   r5, r24, 24;
/* 8053651C 80830008 */  lwz      r4, 8(r3);
/* 80536520 2C040000 */  cmpwi    r4, 0;
/* 80536524 4082000C */  bne-     UNDEF_80536530;
/* 80536528 38000000 */  li       r0, 0;
/* 8053652C 48000008 */  b        UNDEF_80536534;
UNDEF_80536530:;
/* 80536530 A0040004 */  lhz      r0, 4(r4);
UNDEF_80536534:;
/* 80536534 7C050000 */  cmpw     r5, r0;
/* 80536538 4180FFB8 */  blt+     UNDEF_805364f0;
/* 8053653C 4800001C */  b        UNDEF_80536558;
UNDEF_80536540:;
/* 80536540 8063000C */  lwz      r3, 12(r3);
/* 80536544 54C015BA */  clrlslwi r0, r6, 24, 2;
/* 80536548 8BA70024 */  lbz      r29, 36(r7);
/* 8053654C 3BC00000 */  li       r30, 0;
/* 80536550 7C63002E */  lwzx     r3, r3, r0;
/* 80536554 8BE30020 */  lbz      r31, 32(r3);
UNDEF_80536558:;
/* 80536558 3C60809C */  lis      r3, UNDEF_809bd6e8@ha;
/* 8053655C 57C4063E */  clrlwi   r4, r30, 24;
/* 80536560 8063D6E8 */  lwz      r3, UNDEF_809bd6e8@l(r3);
/* 80536564 4BFDE5CD */  bl       UNDEF_80514b30;
/* 80536568 2C030000 */  cmpwi    r3, 0;
/* 8053656C 4182001C */  beq-     UNDEF_80536588;
/* 80536570 7F44D378 */  mr       r4, r26;
/* 80536574 7F65DB78 */  mr       r5, r27;
/* 80536578 7FE6FB78 */  mr       r6, r31;
/* 8053657C 57A7063E */  clrlwi   r7, r29, 24;
/* 80536580 4BFDE5A5 */  bl       UNDEF_80514b24;
/* 80536584 4800002C */  b        UNDEF_805365b0;
UNDEF_80536588:;
/* 80536588 3C808089 */  lis      r4, UNDEF_80890150@ha;
/* 8053658C 3C608089 */  lis      r3, UNDEF_80890024@ha;
/* 80536590 C0240150 */  lfs      f1, UNDEF_80890150@l(r4);
/* 80536594 D03A0008 */  stfs     f1, 8(r26);
/* 80536598 C003017C */  lfs      f0, UNDEF_8089017c@l(r3);
/* 8053659C D03A0004 */  stfs     f1, 4(r26);
/* 805365A0 D03A0000 */  stfs     f1, 0(r26);
/* 805365A4 D01B0000 */  stfs     f0, 0(r27);
/* 805365A8 D03B0004 */  stfs     f1, 4(r27);
/* 805365AC D03B0008 */  stfs     f1, 8(r27);
UNDEF_805365b0:;
/* 805365B0 39610030 */  addi     r11, r1, 48;
/* 805365B4 4BAEB02D */  bl       UNDEF_800215e0;
/* 805365B8 80010034 */  lwz      r0, 52(r1);
/* 805365BC 7C0803A6 */  mtlr     r0;
/* 805365C0 38210030 */  addi     r1, r1, 48;
/* 805365C4 4E800020 */  blr;
  // clang-format on
);

REPLACE_ASM( //
  0x805365C8, //
  // 3 parameters undocumented
  void* RaceManager::GetKartPoint(s32 playerId),
  // clang-format off
/* 805365C8 9421FFE0 */  stwu     r1, -32(r1);
/* 805365CC 7C0802A6 */  mflr     r0;
/* 805365D0 3CA0809C */  lis      r5, s_instance__Q26System15RaceInfoManager@ha;
/* 805365D4 90010024 */  stw      r0, 36(r1);
/* 805365D8 93E1001C */  stw      r31, 28(r1);
/* 805365DC 3BE00000 */  li       r31, 0;
/* 805365E0 93C10018 */  stw      r30, 24(r1);
/* 805365E4 7C9E2378 */  mr       r30, r4;
/* 805365E8 93A10014 */  stw      r29, 20(r1);
/* 805365EC 93810010 */  stw      r28, 16(r1);
/* 805365F0 80C5D728 */  lwz      r6, s_instance__Q26System15RaceInfoManager@l(r5);
/* 805365F4 80060B70 */  lwz      r0, 2928(r6);
/* 805365F8 2800000C */  cmplwi   r0, 12;
/* 805365FC 418101F8 */  bgt-     UNDEF_805367f4;
/* 80536600 3CA0808B */  lis      r5, UNDEF_808b331c@ha;
/* 80536604 5400103A */  slwi     r0, r0, 2;
/* 80536608 38A5331C */  addi     r5, r5, UNDEF_808b331c@l;
/* 8053660C 7CA5002E */  lwzx     r5, r5, r0;
/* 80536610 7CA903A6 */  mtctr    r5;
/* 80536614 4E800420 */  bctr;
UNDEF_808b331c:;
                         // switch jump table
                         .long    UNDEF_805367f4;
                         .long    UNDEF_805367f4;
                         .long    UNDEF_805367ec;
                         .long    UNDEF_80536618;
                         .long    UNDEF_80536738;
                         .long    UNDEF_805367ec;
                         .long    UNDEF_805367f4;
                         .long    UNDEF_805367f4;
                         .long    UNDEF_805367f4;
                         .long    UNDEF_80536718;
                         .long    UNDEF_80536718;
                         .long    UNDEF_805367b8;
                         .long    UNDEF_805367e4;

UNDEF_80536618:;
/* 80536618 3CA0809C */  lis      r5, UNDEF_809bd6e8@ha;
/* 8053661C 80A5D6E8 */  lwz      r5, UNDEF_809bd6e8@l(r5);
/* 80536620 80A50008 */  lwz      r5, 8(r5);
/* 80536624 2C050000 */  cmpwi    r5, 0;
/* 80536628 4182000C */  beq-     UNDEF_80536634;
/* 8053662C A0050004 */  lhz      r0, 4(r5);
/* 80536630 48000008 */  b        UNDEF_80536638;
UNDEF_80536634:;
/* 80536634 38000000 */  li       r0, 0;
UNDEF_80536638:;
/* 80536638 28000001 */  cmplwi   r0, 1;
/* 8053663C 4181000C */  bgt-     UNDEF_80536648;
/* 80536640 3BE00000 */  li       r31, 0;
/* 80536644 480001B4 */  b        UNDEF_805367f8;
UNDEF_80536648:;
/* 80536648 3CA0809C */  lis      r5, s_instance__Q26System15RaceInfoManager@ha;
/* 8053664C 3BE00000 */  li       r31, 0;
                         lwz      r8, s_instance__Q26System15RaceInfoManager@l(r5);
                         // Check if teams is enabled
                         lwz      r10, 0xB90(r8);
                         rlwinm.  r0, r10, 0, 30, 30;
                         rlwinm   r5, r4, 0, 31, 31;
                         beq-     UNDEF_8053666C;
/* 80536654 1C0400F0 */  mulli    r0, r4, 240;
/* 8053665C 39050028 */  addi     r8, r8, 40;
/* 80536660 7CA80214 */  add      r5, r8, r0;
/* 80536668 80A500CC */  lwz      r5, 204(r5);
UNDEF_8053666C:;
                         li       r6, 0;
                         li       r7, 0;
/* 8053666C 7C8903A6 */  mtctr    r4;
/* 80536670 28040000 */  cmplwi   r4, 0;
/* 80536674 4081002C */  ble-     UNDEF_805366a0;
UNDEF_80536678:;
                         rlwinm.  r0, r10, 0, 30, 30;
                         rlwinm   r0, r6, 0, 31, 31;
                         beq-     UNDEF_80536688;
/* 80536678 54C0063E */  clrlwi   r0, r6, 24;
/* 8053667C 1C0000F0 */  mulli    r0, r0, 240;
/* 80536680 7C880214 */  add      r4, r8, r0;
/* 80536684 800400CC */  lwz      r0, 204(r4);
UNDEF_80536688:;
/* 80536688 7C050000 */  cmpw     r5, r0;
/* 8053668C 4082000C */  bne-     UNDEF_80536698;
/* 80536690 38070001 */  addi     r0, r7, 1;
/* 80536694 5407063E */  clrlwi   r7, r0, 24;
UNDEF_80536698:;
/* 80536698 38C60001 */  addi     r6, r6, 1;
/* 8053669C 4200FFDC */  bdnz+    UNDEF_80536678;
UNDEF_805366a0:;
/* 805366A0 2C050001 */  cmpwi    r5, 1;
/* 805366A4 38A00000 */  li       r5, 0;
/* 805366A8 40820008 */  bne-     UNDEF_805366b0;
/* 805366AC 38A00006 */  li       r5, 6;
UNDEF_805366b0:;
/* 805366B0 88830024 */  lbz      r4, UNDEF_80890024@l(r3);
/* 805366B4 3C602AAB */  lis      r3, 10923;
/* 805366B8 3803AAAB */  subi     r0, r3, 21845;
/* 805366BC 3BC00000 */  li       r30, 0;
/* 805366C0 7C843A14 */  add      r4, r4, r7;
/* 805366C4 3FA0809C */  lis      r29, UNDEF_809bd6e8@ha;
/* 805366C8 7C602096 */  mulhw    r3, r0, r4;
/* 805366CC 54600FFE */  srwi     r0, r3, 31;
/* 805366D0 7C030214 */  add      r0, r3, r0;
/* 805366D4 1C000006 */  mulli    r0, r0, 6;
/* 805366D8 7C002050 */  sub      r0, r4, r0;
/* 805366DC 7C050214 */  add      r0, r5, r0;
/* 805366E0 541C063E */  clrlwi   r28, r0, 24;
/* 805366E4 48000028 */  b        UNDEF_8053670c;
UNDEF_805366e8:;
/* 805366E8 57C4063E */  clrlwi   r4, r30, 24;
/* 805366EC 4BFDE445 */  bl       UNDEF_80514b30;
/* 805366F0 80630000 */  lwz      r3, 0(r3);
/* 805366F4 A8030018 */  lha      r0, 24(r3);
/* 805366F8 7C1C0000 */  cmpw     r28, r0;
/* 805366FC 4082000C */  bne-     UNDEF_80536708;
/* 80536700 7FDFF378 */  mr       r31, r30;
/* 80536704 480000F4 */  b        UNDEF_805367f8;
UNDEF_80536708:;
/* 80536708 3BDE0001 */  addi     r30, r30, 1;
UNDEF_8053670c:;
/* 8053670C 807DD6E8 */  lwz      r3, UNDEF_809bd6e8@l(r29);
/* 80536710 57C5063E */  clrlwi   r5, r30, 24;
/* 80536714 80830008 */  lwz      r4, 8(r3);
UNDEF_80536718:;
/* 80536718 2C040000 */  cmpwi    r4, 0;
/* 8053671C 4082000C */  bne-     UNDEF_80536728;
/* 80536720 38000000 */  li       r0, 0;
/* 80536724 48000008 */  b        UNDEF_8053672c;
UNDEF_80536728:;
/* 80536728 A0040004 */  lhz      r0, 4(r4);
UNDEF_8053672c:;
/* 8053672C 7C050000 */  cmpw     r5, r0;
/* 80536730 4180FFB8 */  blt+     UNDEF_805366e8;
/* 80536734 480000C4 */  b        UNDEF_805367f8;
UNDEF_80536738:;
/* 80536738 3FA0809C */  lis      r29, UNDEF_809bd6e8@ha;
/* 8053673C 38800000 */  li       r4, 0;
/* 80536740 807DD6E8 */  lwz      r3, UNDEF_809bd6e8@l(r29);
/* 80536744 4BFDE3ED */  bl       UNDEF_80514b30;
/* 80536748 80630000 */  lwz      r3, 0(r3);
/* 8053674C A8030018 */  lha      r0, 24(r3);
/* 80536750 2C00FFFF */  cmpwi    r0, -1;
/* 80536754 4082000C */  bne-     UNDEF_80536760;
/* 80536758 3BE00000 */  li       r31, 0;
/* 8053675C 4800009C */  b        UNDEF_805367f8;
UNDEF_80536760:;
/* 80536760 3B800000 */  li       r28, 0;
/* 80536764 48000028 */  b        UNDEF_8053678c;
UNDEF_80536768:;
/* 80536768 5784063E */  clrlwi   r4, r28, 24;
/* 8053676C 4BFDE3C5 */  bl       UNDEF_80514b30;
/* 80536770 80630000 */  lwz      r3, 0(r3);
/* 80536774 A8030018 */  lha      r0, 24(r3);
/* 80536778 7C1E0000 */  cmpw     r30, r0;
/* 8053677C 4082000C */  bne-     UNDEF_80536788;
/* 80536780 7F9FE378 */  mr       r31, r28;
/* 80536784 48000074 */  b        UNDEF_805367f8;
UNDEF_80536788:;
/* 80536788 3B9C0001 */  addi     r28, r28, 1;
UNDEF_8053678c:;
/* 8053678C 807DD6E8 */  lwz      r3, UNDEF_809bd6e8@l(r29);
/* 80536790 5785063E */  clrlwi   r5, r28, 24;
/* 80536794 80830008 */  lwz      r4, 8(r3);
/* 80536798 2C040000 */  cmpwi    r4, 0;
/* 8053679C 4082000C */  bne-     UNDEF_805367a8;
/* 805367A0 38000000 */  li       r0, 0;
/* 805367A4 48000008 */  b        UNDEF_805367ac;
UNDEF_805367a8:;
/* 805367A8 A0040004 */  lhz      r0, 4(r4);
UNDEF_805367ac:;
/* 805367AC 7C050000 */  cmpw     r5, r0;
/* 805367B0 4180FFB8 */  blt+     UNDEF_80536768;
/* 805367B4 48000044 */  b        UNDEF_805367f8;
UNDEF_805367b8:;
/* 805367B8 80060B74 */  lwz      r0, 2932(r6);
/* 805367BC 38600003 */  li       r3, 3;
/* 805367C0 2C00000C */  cmpwi    r0, 12;
/* 805367C4 40820008 */  bne-     UNDEF_805367cc;
/* 805367C8 38600006 */  li       r3, 6;
UNDEF_805367cc:;
/* 805367CC 7C041800 */  cmpw     r4, r3;
/* 805367D0 4080000C */  bge-     UNDEF_805367dc;
/* 805367D4 7FDFF378 */  mr       r31, r30;
/* 805367D8 48000020 */  b        UNDEF_805367f8;
UNDEF_805367dc:;
/* 805367DC 3BE00000 */  li       r31, 0;
/* 805367E0 48000018 */  b        UNDEF_805367f8;
UNDEF_805367e4:;
/* 805367E4 7FDFF378 */  mr       r31, r30;
/* 805367E8 48000010 */  b        UNDEF_805367f8;
UNDEF_805367ec:;
/* 805367EC 3BE00000 */  li       r31, 0;
/* 805367F0 48000008 */  b        UNDEF_805367f8;
UNDEF_805367f4:;
/* 805367F4 3BE00000 */  li       r31, 0;
UNDEF_805367f8:;
/* 805367F8 3C60809C */  lis      r3, UNDEF_809bd6e8@ha;
/* 805367FC 57E4063E */  clrlwi   r4, r31, 24;
/* 80536800 8063D6E8 */  lwz      r3, UNDEF_809bd6e8@l(r3);
/* 80536804 4BFDE32D */  bl       UNDEF_80514b30;
/* 80536808 80010024 */  lwz      r0, 36(r1);
/* 8053680C 83E1001C */  lwz      r31, 28(r1);
/* 80536810 83C10018 */  lwz      r30, 24(r1);
/* 80536814 83A10014 */  lwz      r29, 20(r1);
/* 80536818 83810010 */  lwz      r28, 16(r1);
/* 8053681C 7C0803A6 */  mtlr     r0;
/* 80536820 38210020 */  addi     r1, r1, 32;
/* 80536824 4E800020 */  blr
  // clang-format on
);

EXTERN_TEXT(
  0x805371A4, //
  void RaceMode::VT_0x28()
);

} // namespace System
