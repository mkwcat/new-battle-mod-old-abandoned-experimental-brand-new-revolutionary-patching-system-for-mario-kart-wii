#include "KartObjectProxy.h"

namespace Kart
{

EXTERN_TEXT(
  0x8059020C, //
  f32* KartObjectProxy::GetPlayerPosition()
);

EXTERN_TEXT(
  0x80590A5C, //
  u32 KartObjectProxy::GetPlayerID()
);

EXTERN_TEXT(
  0x8059077C, //
  KartMove* KartObjectProxy::GetKartMove()
);

EXTERN_TEXT(
  0x80590794, //
  Sound::KartSound* KartObjectProxy::GetKartSound()
);

EXTERN_TEXT(
  0x805907B0, //
  void KartObjectProxy::PlayVoiceSe(u32 type)
);

EXTERN_TEXT(
  0x8059108C, //
  KartBlink* KartObjectProxy::GetKartBlink()
);

} // namespace Kart
