#pragma once

#include "ItemType.h"

namespace Item
{

class ItemKartProxy;

class ItemStock
{
public:
    /* 0x807BC940 */
    void Set(eItemType item, bool isMultiItem);

    /* 0x807BC97C */
    void Remove(u32 count);

    /* 0x807BC9C0 */
    void Clear();

private:
    /* 0x00 */ ItemKartProxy* m_parent;

    /* 0x04 */ s32 m_heldItemID;
    /* 0x08 */ s32 m_heldItemCount;

private:
    FILL(0x0C, 0x2C);
};

static_assert(sizeof(ItemStock) == 0x2C);

} // namespace Item
