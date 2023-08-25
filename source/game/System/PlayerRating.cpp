// PlayerRating.cpp
// MKW: 0x8052CEF8 - 0x8052D298
//
// Decompiled by m8
// https://github.com/riidefi/mkw/blob/master/source/game/system/Rating.cpp

#include "PlayerRating.h"

namespace System
{

EXTERN_TEXT(
  0x8052CEF8, //
  f32 PlayerRating::Calc(f32 x, s32 param_2)
);

EXTERN_TEXT(
  0x8052D00C, //
  f32 PlayerRating::CalcSpline(f32 x, s32 index)
);

EXTERN_TEXT(
  0x8052D068, //
  f32 PlayerRating::CalcPoints(s16 difference, bool isPos)
);

EXTERN_TEXT(
  0x8052D118, //
  s16 PlayerRating::CalcPosPoints(const PlayerRating* opponent) const
);

EXTERN_TEXT(
  0x8052D1C0, //
  s16 PlayerRating::CalcNegPoints(const PlayerRating* opponent) const
);

EXTERN_TEXT(
  0x8052D270, //
  void PlayerRating::UpdatePoints(s32 points)
);

} // namespace System
