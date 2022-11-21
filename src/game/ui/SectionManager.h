#pragma once

#include "RegisteredPadManager.h"

namespace ui
{

class GlobalContext;
class SaveManagerProxy;
class SystemMessageGroup;

class SectionManager
{
public:
    static SectionManager* s_instance;

    SectionManager();
    void Init(); // Replaced

    bool SelectDebugLicense(); // Added
    void DebugBootSetup(); // Added

    void* m_currentSection;
    int m_errorSection;
    int m_argsSection;
    int m_nextSectionId;
    int m_lastSectionId;
    int m_animDir;
    int m_nextAnimDir;
    u8 _1C[0x20 - 0x1C];
    bool m_initialized;
    u8 _21[0x23 - 0x21];
    bool m_debugMode; // Added
    u8 _24[0x34 - 0x24];
    RegisteredPadManager m_registeredPadManager;
    SaveManagerProxy* m_saveManagerProxy;
    SystemMessageGroup* m_systemMessageGroup;
    GlobalContext* m_globalContext;
};

static_assert(sizeof(SectionManager) == 0x9C);

} // namespace ui
