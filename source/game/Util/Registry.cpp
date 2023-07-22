#include "Registry.h"

namespace Util
{

REPLACE(
  0x80860AF0, //
  const char* GetItemPane(Item::EItemType item, u32 count)
)
{
    switch (item) {
    case Item::ITEM_KOURA_GREEN:
        return "kame_green";

    case Item::ITEM_KOURA_RED:
        return "kame_red";

    case Item::ITEM_BANANA:
        return "banana";

    case Item::ITEM_DUMMY_BOX:
        return "dummybox";

    case Item::ITEM_KINOKO:
        return "kinoko";

    case Item::ITEM_KINOKO_3:
        switch (count) {
        case 1:
            return "kinoko";
        case 2:
            return "kinoko_2";
        case 3:
            return "kinoko_3";
        }
        return "kinoko";

    case Item::ITEM_BOMHEI:
        return "bomb_hei";

    case Item::ITEM_KOURA_BLUE:
        return "kame_wing";

    case Item::ITEM_THUNDER:
        return "thunder";

    case Item::ITEM_STAR:
        return "star";

    case Item::ITEM_KINOKO_GOLDEN:
        return "GoldenKinoko";

    case Item::ITEM_KINOKO_BIG:
        return "kinoko_big";

    case Item::ITEM_GESSO:
        return "gesso";

    case Item::ITEM_POW_BLOCK:
        return "pow";

    case Item::ITEM_KUMO:
        return "thunder_c";

    case Item::ITEM_KILLER:
        return "killer";

    case Item::ITEM_KOURA_GREEN_3:
        return "kame_green_3";

    case Item::ITEM_KOURA_RED_3:
        return "kame_red_3";

    case Item::ITEM_BANANA_3:
        return "banana_3";

    case Item::ITEM_FEATHER:
        return "wanwan";

    default:
        assert(!"Invalid item ID");
        return nullptr;
    }
}

} // namespace Util
