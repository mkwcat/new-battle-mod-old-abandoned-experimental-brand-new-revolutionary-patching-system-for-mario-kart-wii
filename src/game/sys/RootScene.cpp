#include "RootScene.h"
#include "ChannelInstaller.h"
#include "HomeButtonMenu.h"
#include "InputManager.h"
#include "NandManager.h"
#include "ResourceManager.h"
#include "SaveManager.h"
#include <egg/core/eggExpHeap.h>
#include <game/effect/EffectInfo.h>
#include <game/net/NetManager.h>
#include <game/sound/SoundManager.h>
#include <game/ui/FontManager.h>
#include <game/ui/SectionManager.h>
#include <host_sys/RKSystem.h>

EXTERN_DATA(
  0x809BD740, //
  sys::RootScene* sys::RootScene::s_instance
);

REPLACE(
  0x80542D4C, //
  void sys::RootScene::Allocate()
)
{
    // TODO: Randomize memory order like the base game

    m_heaps.SetGroupIDAll(14);
    m_heaps.SetGroupIDAll(0);
    m_heaps.SetGroupIDAll(14);

    auto resMgr = ResourceManager::CreateInstance();
    resMgr->m_courseCache.Init();

    m_heaps.SetGroupIDAll(0);

    {
        m_heaps.SetGroupIDAll(1);
        NandManager::CreateInstance();
        SaveManager::CreateInstance();
        InputManager::CreateInstance();
        MiiManager::CreateInstance();
        ChannelInstaller::CreateInstance();
        RaceConfig::CreateInstance();
        m_heaps.SetGroupIDAll(0);

        m_heaps.SetGroupIDAll(2);
        // TODO: Some kart GFX class CreateInstance
        extern void* UNDEF_805af408();
        UNDEF_805af408();
        m_heaps.SetGroupIDAll(0);

        m_heaps.SetGroupIDAll(6);
        ui::SectionManager::CreateInstance();
        ui::FontManager::CreateInstance();
        m_heaps.SetGroupIDAll(0);

        m_heaps.SetGroupIDAll(7);
        effect::EffectInfo::CreateInstance();
        m_heaps.SetGroupIDAll(0);

        m_heaps.SetGroupIDAll(8);
        auto soundMgr = sound::SoundManager::CreateInstance();
        host_sys::RKSystem::s_instance->m_soundManager = soundMgr;
        m_soundHeap = EGG::ExpHeap::create(0x600100, m_heaps.m_heaps[1], 1);
        soundMgr->Init(m_soundHeap);
        m_heaps.SetGroupIDAll(0);

        m_heaps.SetGroupIDAll(11);
        HomeButtonMenu::CreateInstance(m_heaps.m_heaps[1]);
        m_heaps.SetGroupIDAll(0);

        m_heaps.SetGroupIDAll(13);
        net::NetManager::CreateInstance();
        m_heaps.SetGroupIDAll(0);
    }

    m_heaps.SetGroupIDAll(14);
    m_heaps.SetGroupIDAll(0);
    m_heaps.SetGroupIDAll(0);
}
