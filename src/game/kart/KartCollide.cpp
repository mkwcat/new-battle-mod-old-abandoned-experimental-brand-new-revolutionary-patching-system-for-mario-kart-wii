#include "KartCollide.h"
#include <System/RaceConfig.h>

namespace Kart
{

EXTERN_REPL(
  0x80573ED4, //
  void KartCollide::UpdateRespawn()
)

REPLACE(
  0x80573ED4, //
  void KartCollide::UpdateRespawnCall()
)
{
    auto state = m_accessor->m_state;

    // Don't run for online players
    if (state->b_OnlineRemote)
        return;

    if (System::RaceConfig::s_instance->m_currentRace.IsBalloonBattle()) {
        // Don't run for eliminated players
        if (state->b_BattleSideline || state->b_PostBattleSideline)
            return;
    }

    UpdateRespawn();
}

} // namespace Kart
