#pragma once

#include "ItemConfig.h"
#include "ItemObjCommon.h"
#include "ItemObjThrow.h"
#include "ItemType.h"

namespace Item
{

class ItemObjBanana : public ItemObjCommon
{
public:
    static const ItemTypeEntry s_itemType;
    static const ItemTypeEntry s_itemType3;
    static ItemObjConfig s_itemObjConfig;
};

} // namespace Item
