#pragma once

#include "ItemObjCommon.h"
#include "ItemType.h"

namespace Item
{

class ItemObjKouraGreen : public ItemObjCommon
{
public:
    static const ItemTypeEntry s_itemType;
    static const ItemTypeEntry s_itemType3;
    static ItemObjConfig s_itemObjConfig;
};

} // namespace Item
