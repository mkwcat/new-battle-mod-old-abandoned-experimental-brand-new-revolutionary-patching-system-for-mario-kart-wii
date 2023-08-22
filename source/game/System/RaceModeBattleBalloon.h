#pragma once

#include "RaceModeBattleBase.h"

namespace System
{

class RaceModeBattleBalloon : public RaceModeBattleBase
{
public:
    // Note: vtable at 0x808B36E4

    EXTERN_TEXT(
      0x80539770, //
      virtual bool IsFinishReady()
    );

    EXTERN_TEXT(
      0x80535DE8, //
      virtual void ForceFinish()
    );

    EXTERN_TEXT(
      0x80539574, //
      virtual void VT_0x10()
    );

    // Actually a virtual function
    void PlayerHitByPlayer(u32 attackerId, u32 targetId);
    void PlayerFallOutOfBounds(u32 targetId);
    void PlayerHitByObject(u32 targetId);

    // At 0x80538E00, I don't know what else to call it
    void SidelinePlayer(u8 playerId);

private:
    void CalcBase();

public:
    void Calc();

private:
    FILL(0x8, 0x34);
    bool m_hasStarted;
};

} // namespace System
