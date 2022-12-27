#pragma once

#include "game/util/Random.h"

namespace sys
{

class Timer
{
public:
    // vtable 0x808B34C4, linked in RaceManager.cpp
    EXTERN_TEXT(0x80532DE0, virtual ~Timer());
    EXTERN_TEXT(0x80532D44, virtual void Reset());
    EXTERN_TEXT(0x805336A0, virtual void Update());

    class Time
    {
    public:
        // vtable 0x808B2D44, linked in GhostData.cpp
        EXTERN_TEXT(0x8051C374, Time());
        EXTERN_TEXT(0x8051C334, virtual ~Time());

        /* 0x4 */ u16 m_minutes;
        /* 0x6 */ u8 m_seconds;
        /* 0x8 */ u16 m_milliseconds;
        /* 0xA */ bool m_valid;
    };

    static_assert(sizeof(Time) == 0xC);

    /* 0x04 */ Time m_time[3];
    /* 0x24 */ util::Random m_random;
    /* 0x40 */ u8 m_unk_0x40;
    /* 0x41 */ bool m_started;
    /* 0x42 */ bool m_reverse;
    /* 0x44 */ u32 m_timeLimit;
    FILL(0x48, 0x50);
};

static_assert(sizeof(Timer) == 0x50);

} // namespace sys
