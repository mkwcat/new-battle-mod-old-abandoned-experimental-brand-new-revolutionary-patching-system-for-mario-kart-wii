#pragma once

namespace host_sys
{

class RKSystem
{
public:
    static RKSystem* s_instance;

    FILL(0x0, 0x40);
    void* m_soundManager;
};

} // namespace host_sys
