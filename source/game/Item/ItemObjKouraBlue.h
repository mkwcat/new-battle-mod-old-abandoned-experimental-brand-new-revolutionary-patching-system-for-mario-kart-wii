#pragma once

#include "ItemObjSearcher.h"
#include "ItemType.h"

namespace Item
{

class ItemObjKouraBlue : public ItemObjSearcher
{
public:
    static const ItemTypeEntry s_itemType;
    static ItemObjConfig s_itemObjConfig;
};

} // namespace Item
