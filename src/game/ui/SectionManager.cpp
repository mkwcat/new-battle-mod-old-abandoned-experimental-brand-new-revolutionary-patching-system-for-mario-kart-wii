#include "SectionManager.h"
#include "GlobalContext.h"
#include "SaveManagerProxy.h"
#include "SystemMessageGroup.h"
#include <egg/core/eggHeap.h>
#include <game/sys/MiiManager.h>
#include <game/sys/NandManager.h>
#include <game/sys/RootScene.h>
#include <nw4r/lyt/lyt_init.h>

REPLACE(0x80634E44, void ui::SectionManager::Init())
{
    m_currentSection = nullptr;

    m_systemMessageGroup =
      new (sys::RootScene::s_instance->heaps[1], 4) SystemMessageGroup();
    m_systemMessageGroup->Load();

    sys::NandManager::s_instance->Init();

    m_saveManagerProxy =
      new (sys::RootScene::s_instance->heaps[1], 4) SaveManagerProxy();
    m_saveManagerProxy->Init();
    m_errorSection = m_saveManagerProxy->GetErrorSection();

    m_globalContext = new GlobalContext();

    nw4r::lyt::LytInit();

    m_registeredPadManager.Init();

    if (sys::MiiManager::GetError() != 0 && m_errorSection != 0x14) {
        m_errorSection = 0x15;
    }

    m_nextSectionId = m_errorSection == -1 ? 0x3F : m_errorSection;

    m_nextAnimDir = 0;
    m_initialized = true;

    // Some bool in DiscCheckThread
    extern u8* UNDEF_80385fc0;
    UNDEF_80385fc0[0x50] = 1;
}
