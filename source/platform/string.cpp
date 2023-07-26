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

EXTERN_TEXT(
  0x80006038, //
  void* memset(void* dst, int value, size_t len)
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
  0x800135F0, //
  char* strstr(const char* haystack, const char* needle)
);

EXTERN_TEXT(
  0x80021254, //
  size_t strlen(const char* str)
);
