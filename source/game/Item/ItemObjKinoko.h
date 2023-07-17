#pragma once

#include "ItemObjCommon.h"
#include "ItemType.h"

namespace Item
{

class ItemObjKinoko : public ItemObjCommon
{
public:
    static const ItemTypeEntry s_itemType;
    static const ItemTypeEntry s_itemType3;
    static ItemObjConfig s_itemObjConfig;

    static void UseHandler(ItemKartProxy* kart);
};

} // namespace Item
