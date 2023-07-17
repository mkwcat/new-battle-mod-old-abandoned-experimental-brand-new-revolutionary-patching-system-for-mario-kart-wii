#pragma once

namespace Race
{

class DriverModelManager
{
public:
    static DriverModelManager* s_instance;

    FILL(0x000, 0x160);
    bool m_isAwards;
};

} // namespace Race
