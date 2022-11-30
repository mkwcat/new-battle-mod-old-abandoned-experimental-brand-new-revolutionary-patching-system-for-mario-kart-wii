#pragma once

#include "RaceMode.h"

namespace sys
{

class RaceModeBattleBalloon
{
public:
    // Note: vtable at 0x808B36E4

    EXTERN_TEXT(0x80539770, virtual bool CanRaceEnd());
    EXTERN_TEXT(0x80535DE8, virtual void vt_0xC());
    EXTERN_TEXT(0x80539574, virtual void vt_0x10());

    // Actually a virtual function
    void PlayerHitByPlayer(u32 attackerId, u32 targetId);
    void PlayerFallOutOfBounds(u32 targetId);
    void PlayerHitByObject(u32 targetId);

    // At 0x80538E00, I don't know what else to call it
    void SidelinePlayer(u8 playerId);
};

} // namespace sys
