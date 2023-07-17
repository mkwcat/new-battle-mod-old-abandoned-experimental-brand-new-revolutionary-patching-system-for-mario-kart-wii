#pragma once

#include <Kart/KartObjectProxy.h>

namespace Item
{

class ItemKartProxy;

/**
 * Handles kart-based geometry for items (i.e Bullet Bill)
 */
class ItemGeoKart : public Kart::KartObjectProxy
{
private:
    ItemKartProxy* m_parent;

    FILL(0x010, 0x180);
};

static_assert(sizeof(ItemGeoKart) == 0x180);

} // namespace Item
