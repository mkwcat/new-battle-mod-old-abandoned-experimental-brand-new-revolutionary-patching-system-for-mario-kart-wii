#pragma once

#include "ItemType.h"
#include <Sound/SoundID.h>
#include <Util/Handler.h>

namespace Item
{

class ItemObj;

typedef ItemObj** (*ItemObjConstructFunction)(u32 objCount);

typedef u32 (*ItemObjConfig0x24)(u32 param_1, u32 param_2, u32 param_3);

struct ItemObjConfig {
    static void InitGlobal();

    /* 0x00 */ ItemObjConstructFunction m_constructFunction;
    /* 0x04 */ u32 m_count;
    /* 0x08 */ u32 m_competitionCount;
    /* 0x0C */ s32 m_0x0C;
    /* 0x10 */ s32 m_0x10;
    /* 0x14 */ u8 m_0x14;
    /* 0x15 */ u8 m_0x15;
    /* 0x16 */ u8 m_0x16;
    /* 0x18 */ PTMF<ItemObj> m_0x18;
    /* 0x24 */ ItemObjConfig0x24 m_0x24;
    /* 0x28 */ u32 m_0x28;
    /* 0x2C */ u8 m_0x2C;
    /* 0x30 */ f32 m_0x30;
    /* 0x34 */ f32 m_0x34;
    /* 0x38 */ f32 m_0x38;
    /* 0x3C */ f32 m_0x3C;
    /* 0x40 */ f32 m_0x40;
    /* 0x44 */ f32 m_0x44;
    /* 0x48 */ f32 m_0x48;
    /* 0x4C */ f32 m_0x4C;
    /* 0x50 */ f32 m_0x50;
    /* 0x54 */ f32 m_0x54;
    /* 0x58 */ bool m_canLand;
    /* 0x59 */ bool m_battleScoreOnKartCollide; // Pop a balloon
    /* 0x5A */ bool m_destroyOnKartCollide;
    /* 0x5B */ u8 m_0x5B;
    /* 0x5C */ s32 m_0x5C;
    /* 0x60 */ u32 m_0x60;
    /* 0x64 */ Sound::eSoundID m_hitSound;
    /* 0x68 */ Sound::eSoundID m_hitGroundSound;
    /* 0x6C */ f32 m_0x6C;
    /* 0x70 */ bool m_0x70;
};

static_assert(sizeof(ItemObjConfig) == 0x74);

extern ItemObjConfig g_itemObjConfigTable[ITEM_GEO_OBJ_EXP_END];

} // namespace Item
