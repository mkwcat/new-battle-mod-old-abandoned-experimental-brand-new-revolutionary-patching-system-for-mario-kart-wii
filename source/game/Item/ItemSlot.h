#pragma once

#include "ItemType.h"

namespace Item
{

class ItemKartProxy;

/**
 * Handles visible item box and determining the item.
 */
class ItemSlot
{
public:
    bool Calc();

private:
    enum class EItemSlotState {
        INACTIVE = 0,
        SPINNING = 1,
        SELECTED = 2,
    };

    /* 0x00 */ ItemKartProxy* m_itemKartProxy;

    /* 0x04 */ EItemSlotState m_state;
    /* 0x08 */ s32 m_frame;
    /* 0x0C */ s32 m_frameCount;
    /* 0x10 */ f32 m_spinDelta;
    /* 0x14 */ f32 m_spinDuration;

    /* 0x18 */ EItemType m_topItem;
    /* 0x1C */ EItemType m_bottomItem;
    /* 0x20 */ EItemType m_decideItem;
    /* 0x24 */ EItemType m_displayItem;

    /* 0x28 */ s16 m_setting;
    /* 0x2A */ u8 m_position;
    /* 0x2B */ bool m_0x2B;
    /* 0x2C */ bool m_isFastSpin;
    /* 0x2D */ bool m_isOnline;
    /* 0x2E */ bool m_isRejected;

    /* 0x30 */ s32 m_totalItemCount;
};

static_assert(sizeof(ItemSlot) == 0x34);

} // namespace Item
