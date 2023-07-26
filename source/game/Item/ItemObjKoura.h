#pragma once

#include "ItemObjSearcher.h"
#include "ItemType.h"

namespace Item
{

class ItemObjKoura : public ItemObjSearcher
{
public:
    static const ItemTypeEntry s_itemType;
    static const ItemTypeEntry s_itemType3;
    static ItemObjConfig s_itemObjConfig;
};

} // namespace Item
