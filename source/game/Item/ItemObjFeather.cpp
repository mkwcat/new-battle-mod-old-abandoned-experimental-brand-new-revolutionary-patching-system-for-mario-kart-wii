// ItemObjFeather.cpp
// MKW: ---

#include "ItemObjFeather.h"

namespace Item
{

const ItemTypeEntry ItemObjFeather::s_itemType = {
  .m_0x00 = true,
  .m_0x01 = true,
  .m_objType = ITEM_GEO_OBJ_FEATHER,
  .m_objCount = 1,
  .m_0x0C = 0,
  .m_0x10 = 0,
  .m_trailType = ITEM_TRAIL_NONE,
  .m_useHandler = ItemObjFeather::UseHandler,
};

ItemObjConfig ItemObjFeather::s_itemObjConfig = {
  .m_constructFunction = ItemObjFeather::Create,
  .m_count = 10,
  .m_competitionCount = 10,
  .m_0x0C = 10,
  .m_0x10 = 10,
  .m_0x14 = 0,
  .m_hasBreakAnimation = false,
  .m_0x16 = 0,
  .m_0x18 = {},
  .m_0x24 = nullptr,
  .m_0x28 = 0,
  .m_0x2C = 0,
  .m_0x30 = 17000.0,
  .m_0x34 = 2.0,
  .m_0x38 = 27.0,
  .m_0x3C = 60.0,
  .m_0x40 = 33.0,
  .m_0x44 = 0.4,
  .m_0x48 = 0.4,
  .m_0x4C = 0.1,
  .m_0x50 = 0.1,
  .m_0x54 = 1.0 / 100.0,
  .m_canLand = false,
  .m_battleScoreOnKartCollide = false,
  .m_destroyOnKartCollide = true,
  .m_0x5B = 0,
  .m_0x5C = 1,
  .m_0x60 = 0,
  .m_hitSound = Sound::SE_DUMMY,
  .m_hitGroundSound = Sound::SE_ITM_KINOKO_GND,
  .m_0x6C = 0.8,
  .m_0x70 = true,
};

ItemObj** ItemObjFeather::Create(u32 objCount)
{
    ItemObj** array = new ItemObj*[objCount];

    for (u32 i = 0; i < objCount; i++) {
        array[i] = new ItemObjFeather();
    }

    return array;
}

void ItemObjFeather::UseHandler(ItemKartProxy* kart)
{
    auto kartMove = kart->GetKartMove();

    kartMove->StartFeatherJump();

    kart->m_itemStock.Remove(1);
}

void ItemObjFeather::CreateModel()
{
    CreateModelInner("feather", "koura_s", 0, 0, 0);
}

} // namespace Item
