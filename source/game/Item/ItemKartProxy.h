#pragma once

#include "ItemGeoKart.h"
#include "ItemPoint.h"
#include "ItemSlot.h"
#include "ItemStock.h"
#include <Kart/KartObjectProxy.h>

namespace Item
{

class ItemKartProxy : public Kart::KartObjectProxy
{
public:
    ~ItemKartProxy() = default;

    void Init(u32 index);

    /* 0x80797928 */
    void Calc();

    void ActivateMushroomBoost();

    void ActivateMegaMushroom();

    void ActivateBullet();

private:
    FILL(0x00C, 0x018);

public:
    /* 0x018 */ u8 m_playerID;
    /* 0x019 */ bool m_isMaster; // Is a human player (not a CPU)
    /* 0x01A */ bool m_isRemote; // Is a player from another console (online)
    /* 0x01B */ bool m_isBike;

private:
    FILL(0x01C, 0x044);

public:
    /* 0x044 */ ItemPoint m_itemPoint;
    /* 0x054 */ ItemSlot m_itemSlot;
    /* 0x088 */ ItemStock m_itemStock;
    /* 0x0B4 */ ItemGeoKart m_itemGeoKart;
    /* 0x234 */ s32 m_localPlayerID;

private:
    FILL(0x238, 0x248);
};

static_assert(sizeof(ItemKartProxy) == 0x248);

} // namespace Item
