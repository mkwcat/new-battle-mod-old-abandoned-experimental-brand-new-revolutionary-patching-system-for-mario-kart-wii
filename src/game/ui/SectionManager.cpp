#include "SectionManager.h"
#include "GlobalContext.h"
#include "SaveManagerProxy.h"
#include "SystemMessageGroup.h"
#include <egg/core/eggHeap.h>
#include <game/sys/MiiManager.h>
#include <game/sys/NandManager.h>
#include <game/sys/RaceConfig.h>
#include <game/sys/RootScene.h>
#include <game/sys/SaveManager.h>
#include <host_sys/SystemManager.h>
#include <nw4r/lyt/lyt_init.h>

EXTERN_DATA(0x809C1E38, ui::SectionManager* ui::SectionManager::s_instance);

constexpr int s_debugLicenseId = 0;

bool ui::SectionManager::SelectDebugLicense()
{
    // [Debug] Select a license
    sys::SaveManager::s_instance->SelectLicense(s_debugLicenseId);

    if (sys::SaveManager::IsInvalidMii(
          sys::SaveManager::s_instance->GetSelectedLicense(),
          sys::RootScene::s_instance->heaps[1]))
        return false;

    m_globalContext->m_licenseId = s_debugLicenseId;

    auto license = sys::SaveManager::s_instance->GetSelectedLicense();
    auto sysMgr = host_sys::SystemManager::s_instance;
    if (license->m_unk_0x93E6[0] == sysMgr->m_unk_0xF0 &&
        license->m_unk_0x93E6[1] == sysMgr->m_unk_0xF1 &&
        license->m_unk_0x93E6[2] == sysMgr->m_unk_0xF2)
        return false;

    license->m_unk_0x93E6[0] = sysMgr->m_unk_0xF0;
    license->m_unk_0x93E6[1] = sysMgr->m_unk_0xF1;
    license->m_unk_0x93E6[2] = sysMgr->m_unk_0xF2;
    license->m_unk_0x93E6[3] = sysMgr->m_unk_0xF3;

    sys::SaveManager::s_instance->GetSelectedLicense()->UNDEF_80549878();
    return true;
}

void ui::SectionManager::DebugBootSetup()
{
    if (!SelectDebugLicense())
        return;

    m_nextSectionId = 0x1B;
    m_argsSection = 0x1B;

    auto set = &sys::RaceConfig::s_instance->m_nextRace;

    set->m_courseId = 0x20;
    set->m_playerCount = 12;
    set->m_hudCount = 1;
    set->m_localPlayerCount = 1;
    set->m_gameMode = sys::RaceConfig::RaceSetting::MODE_BATTLE;
    set->m_players[0].m_characterId = 0x0A; // Yoshi
    set->m_players[0].m_vehicleId = 0x13; // Mach Bike
    set->m_players[0].m_playerType = sys::RaceConfig::Player::PLAYER_REAL_LOCAL;
    set->m_players[0].m_team = sys::RaceConfig::Player::TEAM_NONE;
    set->m_engineClass = sys::RaceConfig::RaceSetting::CC_150;
    set->m_hudPlayerIds[0] = 0;
    set->m_lapCount = 3;
    set->m_cameraMode =
      sys::RaceConfig::RaceSetting::CAMERA_MODE_GAMEPLAY_INTRO;
    set->m_legacyBattleMode = sys::RaceConfig::RaceSetting::BATTLE_BALLOON;
    set->m_battleMode = sys::RaceConfig::RaceSetting::BATTLE_BALLOON;

    for (u32 i = 1; i < 6; i++) {
        set->m_players[i].m_characterId = 0x0A; // Yoshi
        set->m_players[i].m_vehicleId = 0x13; // Mach Bike
        set->m_players[i].m_team = sys::RaceConfig::Player::TEAM_NONE;
        set->m_players[i].m_playerType = sys::RaceConfig::Player::PLAYER_CPU;
    }

    for (u32 i = 6; i < 12; i++) {
        set->m_players[i].m_characterId = 0x0A; // Yoshi
        set->m_players[i].m_vehicleId = 0x13; // Mach Bike
        set->m_players[i].m_team = sys::RaceConfig::Player::TEAM_NONE;
        set->m_players[i].m_playerType = sys::RaceConfig::Player::PLAYER_CPU;
    }
}

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

    if (m_errorSection == -1) {
        m_debugMode = true;
        DebugBootSetup();
    } else {
        m_debugMode = false;
    }

    m_nextAnimDir = 0;
    m_initialized = true;

    // Some bool in DiscCheckThread
    extern u8* UNDEF_80385fc0;
    UNDEF_80385fc0[0x50] = 1;
}
