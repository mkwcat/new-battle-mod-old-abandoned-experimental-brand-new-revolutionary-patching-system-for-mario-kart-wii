#pragma once

#include "Mii.h"
#include "Timer.h"

namespace sys
{

struct RawGhostData {
    u8 m_header[0x88];
    u8 m_data[0x27FC - 0x88];
    u32 m_checksum;

    EXTERN_TEXT(
      0x8051D0E0, //
      bool Compress(RawGhostData* out)
    );

    EXTERN_TEXT(
      0x8051D388, //
      u32 GetFileSize() const
    );
};

static_assert(sizeof(RawGhostData) == 0x2800);

class GhostData
{
public:
    EXTERN_TEXT(
      0x8051C270, //
      GhostData()
    );

    EXTERN_TEXT(
      0x8051C7F4, //
      void MakeHeader(RawGhostData* out)
    );

    EXTERN_TEXT(
      0x8051CA80, //
      void MakeFile(RawGhostData* out)
    );

    EXTERN_TEXT(
      0x8051CB1C, //
      void MakeGhostFromPlayer(int playerId)
    );

    /* 0x00 */ bool m_valid;
    /* 0x02 */ wchar_t m_userData[10];
    /* 0x18 */ MiiData m_mii;
    /* 0x64 */ u8 m_lapCount;
    /* 0x68 */ Timer::Time m_lapTimes[5];
    /* 0xA4 */ Timer::Time m_finishTime;
    /* 0xB0 */ int m_characterId;
    /* 0xB4 */ int m_vehicleId;
    /* 0xB8 */ int m_courseId;
    /* 0xBC */ int m_controllerId;
    /* 0xC0 */ u8 m_year;
    /* 0xC1 */ u8 m_month;
    /* 0xC2 */ u8 m_day;
    /* 0xC4 */ u32 unk_0xC4;
    /* 0xC8 */ u8 m_driftType;
    /* 0xCC */ u32 m_country;
    /* 0xD0 */ u32 m_inputDataLen;
    /* 0xD4 */ u8* m_inputData;
};

static_assert(sizeof(GhostData) == 0xD8);

} // namespace sys
