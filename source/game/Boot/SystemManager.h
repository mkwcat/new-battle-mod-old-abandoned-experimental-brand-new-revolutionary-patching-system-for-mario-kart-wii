#pragma once

namespace Boot
{

class SystemManager
{
public:
    static SystemManager* s_instance;

    enum {
        ASPECT_RATIO_4_3 = 0,
        ASPECT_RATIO_16_9 = 1,
    };

    enum class Language : u32 {
        Japanese = 0, // [Check]
        English = 1,
        German = 2,
        French = 3,
        Spanish = 4,
        Italian = 5,
    };

    FILL(0x0, 0x58);
    /* 0x58 */ u32 m_aspectRatio;
    /* 0x5C */ Language m_language;
    /* 0x60 */ Language m_strapLanguage;
    FILL(0x64, 0xF0);
    u8 m_unk_0xF0;
    u8 m_unk_0xF1;
    u8 m_unk_0xF2;
    u8 m_unk_0xF3;
};

} // namespace Boot
