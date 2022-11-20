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
    SectionManager();
    void Init();

public:
    void* m_currentSection;
    int m_errorSection;
    int m_argsSection;
    int m_nextSectionId;
    int m_lastSectionId;
    int m_animDir;
    int m_nextAnimDir;
    u8 _1C[0x20 - 0x1C];
    bool m_initialized;
    u8 _21[0x34 - 0x21];
    RegisteredPadManager m_registeredPadManager;
    SaveManagerProxy* m_saveManagerProxy;
    SystemMessageGroup* m_systemMessageGroup;
    GlobalContext* m_globalContext;
};

static_assert(sizeof(SectionManager) == 0x9C);

} // namespace ui
