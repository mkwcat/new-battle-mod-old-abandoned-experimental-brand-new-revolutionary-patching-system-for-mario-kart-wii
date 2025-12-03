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
    /* 0x00 */ ItemObjConstructFunction m_constructFunction;
    /* 0x04 */ u32 m_count;
    /* 0x08 */ u32 m_competitionCount;
    /* 0x0C */ s32 m_0x0C;
    /* 0x10 */ s32 m_0x10;
    /* 0x14 */ u8 m_0x14;
    /* 0x15 */ bool m_hasBreakAnimation;
    // ? Triggers weird behavior if it tries to land
    /* 0x16 */ bool m_allowedToLand;
    /* 0x18 */ PTMF<ItemObj> m_0x18;
    /* 0x24 */ ItemObjConfig0x24 m_0x24;
    /* 0x28 */ u32 m_0x28;
    /* 0x2C */ u8 m_0x2C;
    /* 0x30 */ f32 m_drawDistance;
    /* 0x34 */ f32 m_0x34;
    /* 0x38 */ f32 m_modelHeightOffset;
    /* 0x3C */ f32 m_0x3C;
    /* 0x40 */ f32 m_throwHorizOffset; // [check]
    /* 0x44 */ f32 m_visualScale; // Overall scale

    // When throwing an item in the base game, the size changes, in what's sort
    // of like a fade animation. These values control how the item scales over
    // time.
    /* 0x48 */ f32 m_finalScale; // Grows to this size after being thrown
    /* 0x4C */ f32 m_scaleIncrement; // Scale to add each frame
    /* 0x50 */ f32 m_0x50; // Seems to be the same as m_scaleIncrement
    /* 0x54 */ f32 m_0x54;
    /* 0x58 */ bool m_canLand;
    /* 0x59 */ bool m_battleScoreOnKartCollide; // Pop a balloon
    /* 0x5A */ bool m_destroyOnKartCollide;
    /* 0x5B */ u8 m_0x5B;
    /* 0x5C */ s32 m_0x5C;
    /* 0x60 */ Sound::ESoundID m_breakSound;
    /* 0x64 */ Sound::ESoundID m_hitSound;
    /* 0x68 */ Sound::ESoundID m_hitGroundSound;
    /* 0x6C */ f32 m_shadowScale;
    /* 0x70 */ bool m_0x70;
};

static_assert(sizeof(ItemObjConfig) == 0x74);

extern ItemObjConfig g_itemObjConfigTable[ITEM_GEO_OBJ_EXP_END];

/* 0x80790AD8 */
void ItemConfig_Init();

/* 0x80790AFC */
void ItemObjConfigTable_Init();

} // namespace Item
