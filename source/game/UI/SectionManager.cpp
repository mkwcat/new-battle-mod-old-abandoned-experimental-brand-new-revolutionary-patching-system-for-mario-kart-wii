#include "SectionManager.h"
#include "GlobalContext.h"
#include "SaveManagerProxy.h"
#include "SystemMessageGroup.h"
#include <Boot/SystemManager.h>
#include <System/MiiManager.h>
#include <System/NandManager.h>
#include <System/RaceInfo.h>
#include <System/RootScene.h>
#include <System/SaveManager.h>
#include <egg/core/eggHeap.h>
#include <nw4r/lyt/lyt_init.h>

namespace UI
{

EXTERN_DATA(
  0x809C1E38, //
  SectionManager* SectionManager::s_instance
);

constexpr int s_debugLicenseId = 0;

bool SectionManager::SelectDebugLicense()
{
    // [Debug] Select a license
    System::SaveManager::s_instance->SelectLicense(s_debugLicenseId);

    if (System::SaveManager::IsInvalidMii(
          System::SaveManager::s_instance->GetSelectedLicense(),
          System::RootScene::s_instance->m_heaps.m_heaps[1]
        ))
        return false;

    m_globalContext->m_licenseId = s_debugLicenseId;

    auto license = System::SaveManager::s_instance->GetSelectedLicense();
    auto sysMgr = Boot::SystemManager::s_instance;
    if (license->m_unk_0x93E6[0] == sysMgr->m_unk_0xF0 &&
        license->m_unk_0x93E6[1] == sysMgr->m_unk_0xF1 &&
        license->m_unk_0x93E6[2] == sysMgr->m_unk_0xF2)
        return false;

    license->m_unk_0x93E6[0] = sysMgr->m_unk_0xF0;
    license->m_unk_0x93E6[1] = sysMgr->m_unk_0xF1;
    license->m_unk_0x93E6[2] = sysMgr->m_unk_0xF2;
    license->m_unk_0x93E6[3] = sysMgr->m_unk_0xF3;

    System::SaveManager::s_instance->GetSelectedLicense()->UNDEF_80549878();
    return true;
}

void SectionManager::DebugBootSetup()
{
    if (!SelectDebugLicense())
        return;

    m_nextSectionId = SECTION_ID_INTRO_BATTLE;
    m_argsSection = SECTION_ID_INTRO_BATTLE;

    auto set = System::RaceInfoManager::GetInfoNext();

    set->SetCourse(System::RaceInfo::COURSE_BLOCK_PLAZA);
    set->SetPlayerCount(12);
    set->SetScreenCount(1);
    set->SetLocalPlayerCount(1);
    set->SetGameMode(System::RaceInfo::GAME_MODE_BATTLE);
    set->SetCameraMode(System::RaceInfo::CAMERA_MODE_GAMEPLAY_INTRO);
    set->GetPlayer(0)->SetCharacter(System::RaceInfoPlayer::CHARACTER_YOSHI);
    set->GetPlayer(0)->SetVehicle(
      System::RaceInfoPlayer::VEHICLE_M_STANDARD_BIKE
    );
    set->GetPlayer(0)->SetType(System::RaceInfoPlayer::PLAYER_TYPE_MASTER);
    set->GetPlayer(0)->SetTeam(System::RaceInfoPlayer::TEAM_NONE);
    set->SetEngineClass(System::RaceInfo::ENGINE_CLASS_50);
    set->SetBattleMode(System::RaceInfo::BATTLE_MODE_BALLOON);

    for (u32 i = 1; i < 6; i++) {
        set->GetPlayer(i)->SetCharacter(System::RaceInfoPlayer::CHARACTER_YOSHI
        );
        set->GetPlayer(i)->SetVehicle(
          System::RaceInfoPlayer::VEHICLE_M_STANDARD_BIKE
        );
        set->GetPlayer(i)->SetType(System::RaceInfoPlayer::PLAYER_TYPE_CPU);
        set->GetPlayer(i)->SetTeam(System::RaceInfoPlayer::TEAM_NONE);
    }

    for (u32 i = 6; i < 12; i++) {
        set->GetPlayer(i)->SetCharacter(System::RaceInfoPlayer::CHARACTER_YOSHI
        );
        set->GetPlayer(i)->SetVehicle(
          System::RaceInfoPlayer::VEHICLE_M_STANDARD_BIKE
        );
        set->GetPlayer(i)->SetType(System::RaceInfoPlayer::PLAYER_TYPE_CPU);
        set->GetPlayer(i)->SetTeam(System::RaceInfoPlayer::TEAM_NONE);
    }
}

REPLACE(
  0x80634E44, //
  void SectionManager::Init()
)
{
    m_currentSection = nullptr;

    m_systemMessageGroup =
      new (System::RootScene::s_instance->m_heaps.m_heaps[1], 4)
        SystemMessageGroup();
    m_systemMessageGroup->Load();

    System::NandManager::s_instance->Init();

    m_saveManagerProxy =
      new (System::RootScene::s_instance->m_heaps.m_heaps[1], 4)
        SaveManagerProxy();
    m_saveManagerProxy->Init();
    m_errorSection = m_saveManagerProxy->GetErrorSection();

    m_globalContext = new GlobalContext();

    nw4r::lyt::LytInit();

    m_registeredPadManager.Init();

    if (System::MiiManager::GetError() != 0 && //
        m_errorSection != SECTION_ID_CANNOT_ACCESS_SYSTEM_MEMORY) {
        m_errorSection = SECTION_ID_CANNOT_ACCESS_MII_DATA;
    }

    m_nextSectionId = m_errorSection == SECTION_ID_NONE
                        ? SECTION_ID_MAIN_MENU_FROM_BOOT
                        : m_errorSection;

    if (m_errorSection == SECTION_ID_NONE) {
        m_debugMode = true;
        DebugBootSetup();
    } else {
        m_debugMode = false;
    }

    m_nextFadeDir = Page::FADE_DIRECTION_FORWARD;
    m_initialized = true;

    // Some bool in DiscCheckThread
    extern u8* UNDEF_80385fc0;
    UNDEF_80385fc0[0x50] = 1;
}

} // namespace UI
