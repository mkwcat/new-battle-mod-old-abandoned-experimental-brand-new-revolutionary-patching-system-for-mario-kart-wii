#pragma once

namespace Item
{

class ItemPoint
{
public:
    static void CreateItemPointMap();

    FILL(0x00, 0x10);
};

static_assert(sizeof(ItemPoint) == 0x10);

} // namespace Item
