#pragma once

namespace Item
{

enum eItemType {
    ITEM_KOURA_GREEN = 0x00,
    ITEM_KOURA_RED = 0x01,
    ITEM_BANANA = 0x02,
    ITEM_DUMMY_BOX = 0x03,
    ITEM_KINOKO = 0x04,
    ITEM_KINOKO_3 = 0x05,
    ITEM_BOMHEI = 0x06,
    ITEM_KOURA_BLUE = 0x07,
    ITEM_THUNDER = 0x08,
    ITEM_STAR = 0x09,
    ITEM_KINOKO_GOLDEN = 0x0A,
    ITEM_KINOKO_BIG = 0x0B,
    ITEM_GESSO = 0x0C,
    ITEM_POW_BLOCK = 0x0D,
    ITEM_KUMO = 0x0E,
    ITEM_KILLER = 0x0F,
    ITEM_KOURA_GREEN_3 = 0x10,
    ITEM_KOURA_RED_3 = 0x11,
    ITEM_BANANA_3 = 0x12,

    ITEM_BASE_COUNT = 0x13,
    ITEM_EMPTY = 0x14,

    // Expanded items (start at 0x15)
    ITEM_EXP_START = 0x15,

    ITEM_FEATHER = 0x15,

    ITEM_EXP_END,
    ITEM_EXP_COUNT = ITEM_EXP_END - ITEM_EXP_START,
};

static inline bool IsValid_eItemType(eItemType item)
{
    if (item < ITEM_KOURA_GREEN) {
        return false;
    }

    if (item < ITEM_BASE_COUNT) {
        return true;
    }

    if (item < ITEM_EXP_START) {
        return false;
    }

    if (item < ITEM_EXP_END) {
        return true;
    }

    return false;
}

enum eItemGeoObjType {
    ITEM_GEO_OBJ_KOURA_GREEN = 0x00,
    ITEM_GEO_OBJ_KOURA_RED = 0x01,
    ITEM_GEO_OBJ_BANANA = 0x02,
    ITEM_GEO_OBJ_KINOKO = 0x03,
    ITEM_GEO_OBJ_STAR = 0x04,
    ITEM_GEO_OBJ_KOURA_BLUE = 0x05,
    ITEM_GEO_OBJ_THUNDER = 0x06,
    ITEM_GEO_OBJ_DUMMY_BOX = 0x07,
    ITEM_GEO_OBJ_KINOKO_BIG = 0x08,
    ITEM_GEO_OBJ_BOMHEI = 0x09,
    ITEM_GEO_OBJ_GESSO = 0x0A,
    ITEM_GEO_OBJ_POW_BLOCK = 0x0B,
    ITEM_GEO_OBJ_KINOKO_GOLDEN = 0x0C,
    ITEM_GEO_OBJ_KILLER = 0x0D,
    ITEM_GEO_OBJ_KUMO = 0x0E,

    ITEM_GEO_OBJ_BASE_COUNT = 0x0F,
    ITEM_GEO_OBJ_EMPTY = 0x10,

    // Expanded items (start at 0x1C)
    ITEM_GEO_OBJ_EXP_START = 0x1C,

    ITEM_GEO_OBJ_FEATHER = 0x1C,

    ITEM_GEO_OBJ_EXP_END,
    ITEM_GEO_OBJ_EXP_COUNT = ITEM_GEO_OBJ_EXP_END - ITEM_GEO_OBJ_EXP_START,
};

static inline bool IsValid_eItemGeoObjType(eItemGeoObjType item)
{
    if (item < ITEM_GEO_OBJ_KOURA_GREEN) {
        return false;
    }

    if (item < ITEM_GEO_OBJ_BASE_COUNT) {
        return true;
    }

    if (item < ITEM_GEO_OBJ_EXP_START) {
        return false;
    }

    if (item < ITEM_GEO_OBJ_EXP_END) {
        return true;
    }

    return false;
}

enum eItemTrail {
    ITEM_TRAIL_NONE = 0, // e.g. Bullet Bill
    ITEM_TRAIL_HOLD = 1, // e.g. Banana
    ITEM_TRAIL_TAIL = 2, // e.g. Triple Banana
    ITEM_TRAIL_CIRCLE = 3, // e.g. Triple Shell
};

class ItemKartProxy;

typedef void (*ItemUseHandler)(ItemKartProxy* kart);

struct ItemTypeEntry {
    /* 0x00 */ bool m_0x00;
    /* 0x01 */ bool m_0x01;
    /* 0x04 */ eItemGeoObjType m_objType;
    /* 0x08 */ u32 m_objCount;
    /* 0x0C */ u32 m_0x0C;
    /* 0x10 */ u8 m_0x10;
    /* 0x14 */ eItemTrail m_trailType;
    /* 0x18 */ ItemUseHandler m_useHandler;
};

extern ItemTypeEntry g_itemTypeTable[ITEM_EXP_END];

void InitItemTypeTable();

} // namespace Item
