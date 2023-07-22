// ModeInfo.cpp
// MKW: 0x807BD1D0 - 0x807BD7B4

#include "ModeInfo.h"

namespace Race
{

EXTERN_DATA(
  0x809C38B8, //
  ModeInfo ModeInfo::s_modeInfo
);

EXTERN_TEXT(
  0x807BD1D0, //
  void ModeInfo::Init()
);

EXTERN_TEXT(
  0x807BD340, //
  void ModeInfo::UpdateFrame()
);

EXTERN_TEXT(
  0x807BD374, //
  u8 ModeInfo::GetPlayerRank(s32 playerId)
);

/**
 * Strange. If the player is not real (not ePlayerType PLAYER_MASTER or
 * PLAYER_UNUSED or PLAYER_GHOST) AND does not have a screen (i.e.
 * splitscreen), then false. However, if the player is index 3 and displayed
 * on screen index 3, and if player index 2 is real AND player index 3 is
 * not, then false.
 */
EXTERN_TEXT(
  0x807BD5BC, //
  bool ModeInfo::IsImportantPlayer(s32 playerId)
);

EXTERN_TEXT(
  0x807BD6E4, //
  bool ModeInfo::UseCompetitionItemLimits()
);

EXTERN_TEXT(
  0x807BD718, //
  Util::Random* ModeInfo::GetPreferredRandom()
);

EXTERN_TEXT(
  0x807BD718, //
  bool ModeInfo::IsKartInJumpAction(Kart::KartObjectProxy* kart)
);

EXTERN_TEXT(
  0x807BD78C, //
  bool ModeInfo::IsKartInJumpActionOrAccident(Kart::KartObjectProxy* kart)
);

} // namespace Race
