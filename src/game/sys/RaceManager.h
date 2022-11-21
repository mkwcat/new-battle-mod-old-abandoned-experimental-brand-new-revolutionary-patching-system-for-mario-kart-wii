#pragma once

namespace sys
{

class RaceManager
{
public:
    static RaceManager* s_instance;

    class Mode
    {
    public:
        RaceManager* m_raceManager;
    };

    EXTERN_TEXT(0x805327A0, RaceManager());
    EXTERN_TEXT(0x80532E3C, virtual ~RaceManager());

    EXTERN_TEXT(0x805336A4, u32 GetLapCount() const);

private:
    /* 0x04 */ void* m_random1;
    /* 0x08 */ void* m_random2;
    /* 0x0C */ void* m_players;
    /* 0x10 */ Mode* m_raceMode;
    /* 0x14 */ void* m_timerManager;
    /* 0x18 */ u8* m_playerPolePositions;
    /* 0x1C */ u8 m_finishedPlayerCount;
    /* 0x1E */ u16 m_introTimer;
    /* 0x20 */ u32 m_timer;
    /* 0x24 */ u8 m_battleKtptStart;
    /* 0x28 */ u32 m_course;
    /* 0x2C */ bool m_introSkipped;
    /* 0x2D */ bool m_spectatorMode;
    /* 0x2E */ bool m_canCountdownStart;
    /* 0x2F */ bool m_cutSceneMode;
    /* 0x30 */ bool m_lapCountingEnabled;
    FILL(0x31, 0x3C);
    /* 0x3C */ void* m_kmgFile;
    /* 0x40 */ void* m_elineControlManager;
    /* 0x44 */ f32 m_waterHeightCheck;
    /* 0x48 */ bool m_disableLowerRespawns;
    FILL(0x49, 0x50);
};

static_assert(sizeof(RaceManager) == 0x50);

} // namespace sys
