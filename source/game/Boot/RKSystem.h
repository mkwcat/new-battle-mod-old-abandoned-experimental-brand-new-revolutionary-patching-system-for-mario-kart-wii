#pragma once

namespace Boot
{

class RKSystem
{
public:
    static RKSystem* s_instance;

    FILL(0x0, 0x40);
    void* m_soundManager;
};

} // namespace Boot
