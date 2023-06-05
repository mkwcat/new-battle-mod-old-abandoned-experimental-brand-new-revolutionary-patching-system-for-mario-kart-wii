#include "KartCollide.h"
#include "game/sys/RaceConfig.h"

EXTERN_REPL(
  0x80573ED4, //
  void kart::KartCollide::UpdateRespawn()
)

REPLACE(
  0x80573ED4, //
  void kart::KartCollide::UpdateRespawnCall()
)
{
    auto state = m_accessor->m_state;

    // Don't run for online players
    if (state->b_OnlineRemote)
        return;

    if (sys::RaceConfig::s_instance->m_currentRace.IsBalloonBattle()) {
        // Don't run for eliminated players
        if (state->b_BattleSideline || state->b_PostBattleSideline)
            return;
    }

    UpdateRespawn();
}
