#include "string.h"

REPLACE_ASM( //
  0x80005F34, //
  void* memcpy(void* dst, const void* src, size_t len),
  // clang-format off
    // Meh, signed comparison
    subic.  r7, r5, 4;
    bge-    L_MemcpyLong;

    cmpwi   r5, 0;
    beqlr-;

    mtctr   r5;
    lwbrx   r0, r0, r4;
    stb     r0, 0(r3);
    bdzlr-;
    sthbrx  r0, r0, r3;
    bdzlr-;
    srwi    r0, r0, 16;
    stb     r0, 2(r3);
    blr;

L_MemcpyLong:;
    subi    r6, r3, 4;
    subi    r4, r4, 4;

    srwi.   r0, r5, 5;
    beq-    L_MemcpyBegin1Word;

    stw     r14, 0x4(r1);
    mtctr   r0;

L_MemcpyLoop8Words:;
    // Copy 8 words
    lwz     r0, 0x04(r4);
    lwz     r5, 0x08(r4);
    lwz     r8, 0x0C(r4);
    lwz     r9, 0x10(r4);
    lwz     r10, 0x14(r4);
    lwz     r11, 0x18(r4);
    lwz     r12, 0x1C(r4);
    lwzu    r14, 0x20(r4);
    stw     r0, 0x04(r6);
    stw     r5, 0x08(r6);
    stw     r8, 0x0C(r6);
    stw     r9, 0x10(r6);
    stw     r10, 0x14(r6);
    stw     r11, 0x18(r6);
    stw     r12, 0x1C(r6);
    stwu    r14, 0x20(r6);
    bdnz+   L_MemcpyLoop8Words;

    lwz     r14, 0x4(r1);

    add     r7, r7, r3;
    sub     r5, r7, r6;

    rlwinm. r0, r5, 32 - 2, 7;
    bne+    L_MemcpyBegin1Word_2;

L_MemcpyOut:;
    rlwinm. r5, r5, 0, 3;
    beqlr+;
    mtctr   r5;
    li      r7, 4;
    lwbrx   r0, r7, r4;
    stb     r0, 4(r6);
    bdzlr-;
    sthbrx  r0, r7, r6;
    bdzlr-;
    srwi    r0, r0, 16;
    stb     r0, 6(r6);
    blr;

L_MemcpyBegin1Word:;
    rlwinm  r0, r5, 32 - 2, 7;
L_MemcpyBegin1Word_2:;
    mtctr   r0;
    lwzu    r0, 4(r4);
    stwu    r0, 4(r6);
    bdz-    L_MemcpyOut;
    lwzu    r0, 4(r4);
    stwu    r0, 4(r6);
    bdz-    L_MemcpyOut;
    lwzu    r0, 4(r4);
    stwu    r0, 4(r6);
    bdz-    L_MemcpyOut;
    lwzu    r0, 4(r4);
    stwu    r0, 4(r6);
    bdz-    L_MemcpyOut;
    lwzu    r0, 4(r4);
    stwu    r0, 4(r6);
    bdz-    L_MemcpyOut;
    lwzu    r0, 4(r4);
    stwu    r0, 4(r6);
    bdz-    L_MemcpyOut;
    lwzu    r0, 4(r4);
    stwu    r0, 4(r6);
    b       L_MemcpyOut;
  // clang-format on
);

REPLACE_ASM( //
  0x80006038, //
  void* memset(void* dst, int value, size_t len),
  // clang-format off
    cmpwi   r5, 4;
    blt-    L_MemsetVeryShort;

    // Align up to 4 bytes in case it's misaligned
    rlwinm. r6, r3, 0, 3;
    beq+    L_MemsetPreWordAligned;
    cmpwi   r6, 2;
    subfic  r6, r6, 4;
    stb     r4, 0(r3);
    bgt-    L_MemsetPreWordAlignDone;
    stb     r4, 1(r3);
    beq+    L_MemsetPreWordAlignDone;
    stb     r4, 2(r3);
L_MemsetPreWordAlignDone:;
    sub     r5, r5, r6;

L_MemsetPreWordAligned:;
    add     r6, r3, r6;

    rlwimi  r4, r4, 8, 0, 31-8;
    rlwimi  r4, r4, 16, 0, 31-16;

    // cache line stop boundary
    addi    r7, r6, 31;
    rlwinm  r9, r7, 0, ~31;
    subc.   r7, r9, r6;

    rlwinm  r8, r5, 0, ~3;
    cmplw   cr7, r7, r8;
    blt-    cr7, L_MemsetPreWordMinBoundary;
    mr.     r7, r8;

L_MemsetPreWordMinBoundary:;
    beq-    L_MemsetCacheAligned;

    srwi    r8, r7, 2;
    mtctr   r8;
    stw     r4, 0x0(r6);
    bdz-    L_MemsetPreWordOut;
    stw     r4, 0x4(r6);
    bdz-    L_MemsetPreWordOut;
    stw     r4, 0x8(r6);
    bdz-    L_MemsetPreWordOut;
    stw     r4, 0xC(r6);
    bdz-    L_MemsetPreWordOut;
    stw     r4, 0x10(r6);
    bdz-    L_MemsetPreWordOut;
    stw     r4, 0x14(r6);
    bdz-    L_MemsetPreWordOut;
    stw     r4, 0x18(r6);
L_MemsetPreWordOut:;
    sub     r5, r5, r7;

L_MemsetCacheAligned:;
    rlwinm. r6, r5, 0, ~31;
    add     r7, r6, r9;
    sub     r5, r5, r6;
    beq+    L_MemsetPostWordAligned;

    cmpwi   r4, 0;
    bne-    L_MemsetCacheAlignedNonZero;

L_MemsetCacheAlignedZeroLoop:;
    subic.  r6, r6, 32;
    dcbz    r6, r9;
    bgt+    L_MemsetCacheAlignedZeroLoop;

L_MemsetPostWordAligned:;
    rlwinm. r6, r5, 0, ~3;
    beq-    L_MemsetPostWordOut;

    cmplwi  r6, 0x8;
    stw     r4, 0x0(r7);
    blt-    L_MemsetPostWordOut;
    stw     r4, 0x4(r7);
    beq-    L_MemsetPostWordOut;
    stw     r4, 0x8(r7);
    cmpwi   r6, 0x8+0x8;
    blt-    L_MemsetPostWordOut;
    stw     r4, 0xC(r7);
    beq-    L_MemsetPostWordOut;
    stw     r4, 0x10(r7);
    cmpwi   r6, 0x10+0x8;
    blt-    L_MemsetPostWordOut;
    stw     r4, 0x14(r7);
    beq-    L_MemsetPostWordOut;
    stw     r4, 0x18(r7);

L_MemsetPostWordOut:;
    sub.    r5, r5, r6;
    beqlr-;

    add     r7, r7, r5;
    cmpwi   r5, 2;
    stb     r4, -1(r7);
    bltlr-;
    stb     r4, -2(r7);
    beqlr+;
    stb     r4, -3(r7);
    blr;

L_MemsetVeryShort:;
    cmpwi   r5, 0;
    beqlr-;

    cmpwi   r5, 2;
    stb     r4, 0(r3);
    bltlr-;
    stb     r4, 1(r3);
    beqlr+;
    stb     r4, 2(r3);
    blr;

L_MemsetCacheAlignedNonZero:;
    srwi    r0, r6, 5;
    mtctr   r0;
    subi    r9, r9, 4;

L_MemsetCacheAlignedNonZeroLoop:;
    stw     r4, 0x04(r9);
    stw     r4, 0x08(r9);
    stw     r4, 0x0C(r9);
    stw     r4, 0x10(r9);
    stw     r4, 0x14(r9);
    stw     r4, 0x18(r9);
    stw     r4, 0x1C(r9);
    stwu    r4, 0x20(r9);
    bdnz+   L_MemsetCacheAlignedNonZeroLoop;
    b       L_MemsetPostWordAligned;
  // clang-format on
);

EXTERN_TEXT(
  0x8000F314, //
  int memcmp(const void* s1, const void* s2, size_t n)
);

EXTERN_TEXT(
  0x80013120, //
  char* strcpy(char* dst, const char* src)
);

EXTERN_TEXT(
  0x8001329C, //
  int strcmp(const char* s1, const char* s2)
);

EXTERN_TEXT(
  0x800135F0, //
  char* strstr(const char* haystack, const char* needle)
);

EXTERN_TEXT(
  0x80021254, //
  size_t strlen(const char* str)
);
