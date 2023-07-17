#pragma once

#include "ItemObjSearch.h"
#include "ItemType.h"

namespace Item
{

class ItemObjKoura : public ItemObjSearch
{
public:
    static const ItemTypeEntry s_itemType;
    static const ItemTypeEntry s_itemType3;
    static ItemObjConfig s_itemObjConfig;
};

} // namespace Item
