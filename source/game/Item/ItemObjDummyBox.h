#pragma once

#include "ItemObjCommon.h"
#include "ItemObjThrow.h"
#include "ItemType.h"

namespace Item
{

class ItemObjDummyBox : public ItemObjCommon
{
public:
    static const ItemTypeEntry s_itemType;
    static ItemObjConfig s_itemObjConfig;
};

} // namespace Item
