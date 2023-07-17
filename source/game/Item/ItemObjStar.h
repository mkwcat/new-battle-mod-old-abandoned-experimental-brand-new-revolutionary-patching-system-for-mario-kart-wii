#pragma once

#include "ItemObjCommon.h"
#include "ItemType.h"

namespace Item
{

class ItemObjStar : public ItemObjCommon
{
public:
    static const ItemTypeEntry s_itemType;
    static ItemObjConfig s_itemObjConfig;

    static void UseHandler(ItemKartProxy* kart);
};

} // namespace Item
