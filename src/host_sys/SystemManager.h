#pragma once

namespace host_sys
{

class SystemManager
{
public:
    static SystemManager* s_instance;

    u8 _0[0xF0 - 0x0];
    u8 m_unk_0xF0;
    u8 m_unk_0xF1;
    u8 m_unk_0xF2;
    u8 m_unk_0xF3;
};

} // namespace host_sys
