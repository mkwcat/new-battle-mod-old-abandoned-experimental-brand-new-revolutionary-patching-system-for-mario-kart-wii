#pragma once

#include "ItemObjSearch.h"
#include "ItemType.h"

namespace Item
{

class ItemObjKouraBlue : public ItemObjSearch
{
public:
    static const ItemTypeEntry s_itemType;
    static ItemObjConfig s_itemObjConfig;
};

} // namespace Item
