#include "Handler.h"

extern "C" {

REPLACE(
  0x800213E4, //
  int __ptmf_test(u32* ptmf)
)
{
    if (ptmf[0] & 1) {
        return ptmf[1] != 0;
    }

    // CodeWarrior PTMF
    if (ptmf[0] == 0 && ptmf[1] == 0 && ptmf[2] == 0) {
        return 0;
    }

    return 1;
}

REPLACE(
  0x80021414, //
  int __ptmf_cmpr(u32* ptmf1, u32* ptmf2)
)
{
    // Return 0 if equal, otherwise 1

    u32 cwPtmf1[3], cwPtmf2[3];

    // Convert to CodeWarrior PTMF
    if (ptmf1[0] & 1) {
        cwPtmf1[0] = ptmf1[2];
        cwPtmf1[1] = ptmf1[1] & 1 ? ptmf1[1] - 1 : 0xFFFFFFFF;
        cwPtmf1[2] = ptmf1[1] & 1 ? 0 : ptmf1[1];
    }

    if (ptmf2[0] & 1) {
        cwPtmf2[0] = ptmf2[2];
        cwPtmf2[1] = ptmf2[1] & 1 ? ptmf2[1] - 1 : 0xFFFFFFFF;
        cwPtmf2[2] = ptmf2[1] & 1 ? 0 : ptmf2[1];
    }

    if (cwPtmf1[0] == cwPtmf2[0] && cwPtmf1[1] == cwPtmf2[1] && //
        cwPtmf1[2] == cwPtmf2[2]) {
        // Equal
        return 0;
    }

    // Not equal
    return 1;
}

REPLACE_ASM( //
  0x80021450, //
  void __ptmf_scall(),
  // clang-format off
    lwz     r11, 0x0(r12);
    rlwinm. r0, r11, 0, 0x1;
    bne-    L_CallClangPTMF;

    // CodeWarrior PTMF
    add     r3, r3, r11;
    lwz     r11, 0x4(r12);
    lwz     r12, 0x8(r12);
    cmpwi   r11, 0;
    blt-    L_CWNotVtablePtr;

    lwzx    r12, r3, r12;
    lwzx    r12, r12, r11;

L_CWNotVtablePtr:;
    mtctr   r12;
    bctr;

L_CallClangPTMF:;
    lwz     r12, 0x4(r12);
    add     r3, r3, r12;
    rlwinm. r0, r11, 0, 0x1;
    blt-    L_ClangNotVtablePtr;

    // This is bad! It doesn't support having a vtable elsewhere in the class.
    lwz     r12, 0(r3);
    add     r11, r12, r11;
    lwz     r11, -0x1(r11);

L_ClangNotVtablePtr:;
    mtctr   r11;
    bctr;

  // clang-format on
);
}
