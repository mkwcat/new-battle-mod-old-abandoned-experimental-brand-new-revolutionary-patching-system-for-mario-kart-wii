#pragma once

#include <Kart/KartObjectProxy.h>
#include <Util/Random.h>

namespace Race
{

enum {
    MAX_PLAYER_COUNT = 12,
};

class ModeInfo
{
public:
    /* 0x809C38B8 */
    static ModeInfo s_modeInfo;

    /* 0x807BD1D0 */
    static void Init();

    /* 0x807BD340 */
    static void UpdateFrame();

    /* 0x807BD374 */
    static u8 GetPlayerRank(s32 playerId);

    /**
     * Strange. If the player is not real (not ePlayerType PLAYER_MASTER or
     * PLAYER_UNUSED or PLAYER_GHOST) AND does not have a screen (i.e.
     * splitscreen), then false. However, if the player is index 3 and displayed
     * on screen index 3, and if player index 2 is real AND player index 3 is
     * not, then false.
     */
    /* 0x807BD5BC */
    static bool IsImportantPlayer(s32 playerId);

    /* 0x807BD6E4 */
    static bool UseCompetitionItemLimits();

    /* 0x807BD718 */
    static Util::Random* GetPreferredRandom();

    /* 0x807BD718 */
    static bool IsKartInJumpAction(Kart::KartObjectProxy* kart);

    /* 0x807BD78C */
    static bool IsKartInJumpActionOrAccident(Kart::KartObjectProxy* kart);

    /* 0x00 */ u8 m_playerCount;
    /* 0x01 */ bool m_isOnline;
    /* 0x02 */ bool m_isVSRace; // Offline
    /* 0x03 */ bool m_isBattle;
    /* 0x04 */ bool m_isTimeAttack;
    /* 0x05 */ bool m_isTeams;

    /* 0x08 */ u32 m_frame;
    /* 0x0C */ u32 m_frameMod2;
    /* 0x10 */ u32 m_frameMod4;
    /* 0x14 */ u32 m_frameMod8;

    /**
     * Unknown: DriverModel related, enforces a minimum Y value from the
     * wrist_r1 bone?
     *
     * default: 0.0
     * GCN_COOKIE_LAND: 150.0
     * GBA_BATTLE_COURSE_3: 200.0
     * SNES_BATTLE_COURSE_4: 200.0
     * BLOCK_PLAZA: 150.0 */
    /* 0x18 */ f32 m_0x18;

    // Unknown: Changes something with the lighting of the Banana item geo
    // object. Only set on N64 DK's Jungle Parkway.
    /* 0x1C */ bool m_0x1C;
};

} // namespace Race
