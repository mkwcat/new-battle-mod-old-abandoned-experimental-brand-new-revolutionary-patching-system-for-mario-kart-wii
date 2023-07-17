#pragma once

#include "ItemObjCommon.h"

namespace Item
{

class ItemObjFeather : public ItemObjCommon
{
public:
    static const ItemTypeEntry s_itemType;
    static ItemObjConfig s_itemObjConfig;

    static ItemObj** Create(u32 objCount);

    void CreateModel() override;

    static void UseHandler(ItemKartProxy* kart);
};

} // namespace Item
