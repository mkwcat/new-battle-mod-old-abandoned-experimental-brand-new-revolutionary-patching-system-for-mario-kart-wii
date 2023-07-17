#pragma once

#include "ItemObj.h"

namespace Item
{

class ItemObjCommon : public ItemObj
{
public:
    /* 0x807A6928 */
    ItemObjCommon();

    ~ItemObjCommon() = default;

protected:
    FILL(0x188, 0x18C);
    /* 0x18C */ f32 m_0x18C;
    /* 0x190 */ f32 m_0x190;
    /* 0x194 */ f32 m_0x194;
    FILL(0x198, 0x1A0);
};

static_assert(sizeof(ItemObjCommon) == 0x1A0);

} // namespace Item
