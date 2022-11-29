#include "AIBattleTeamManager.h"

EXTERN_REPL(
  0x80728CC8, void AIBattleTeamManager::Class_0xBC::__TeamPositionUpdate(
                int param_2, Team* team
              )
);

REPLACE(
  0x80728CC8, void AIBattleTeamManager::Class_0xBC::TeamPositionUpdate(
                int param_2, Team* team
              )
)
{
    if (param_2 == 0)
        return;

    // Check if player count is 0
    if (team->m_playerCount == 0)
        return;

    __TeamPositionUpdate(param_2, team);
}
