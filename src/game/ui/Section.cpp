#include "Section.h"

REPLACE(0x8062C3A4, void ui::Section::AddPages(ui::SectionID sectionId))
{
    switch (sectionId) {
    default:
        break;

    case SectionID::Test_6:
        AddPage(PageID::Empty);
        break;

    case SectionID::Test_7:
        AddPage(PageID::Empty);
        break;

    case SectionID::Test_8:
        AddPage(PageID::Empty);
        break;

    case SectionID::Test_9:
        AddPage(PageID::Empty);
        break;

    case SectionID::Test_A:
        AddPage(PageID::Empty);
        break;

    case SectionID::Test_B:
        AddPage(PageID::Empty);
        break;

    case SectionID::Test_C:
        AddPage(PageID::Empty);
        break;

    case SectionID::Test_D:
        AddPage(PageID::Empty);
        break;

    case SectionID::Test_E:
        AddPage(PageID::Empty);
        break;

    case SectionID::Test_F:
        AddPage(PageID::Empty);
        break;

    case SectionID::Create_New_Save:
        AddPage(PageID::SaveDataCorrupt);
        AddPage(PageID::ReadingGhostData);
        AddPage(PageID::Unknown_5D);
        break;

    case SectionID::Corrupted_Save:
        AddPage(PageID::SaveDataCorrupt);
        AddPage(PageID::ReadingGhostData);
        AddPage(PageID::PostToWiiMessageBoard);
        AddPage(PageID::Unknown_5D);
        break;

    case SectionID::Country_Changed:
        AddPage(PageID::SaveDataCorrupt);
        AddPage(PageID::ReadingGhostData);
        AddPage(PageID::PostToWiiMessageBoard);
        AddPage(PageID::Unknown_5D);
        break;

    case SectionID::Game_Cannot_Be_Saved:
        AddPage(PageID::SaveDataError);
        AddPage(PageID::PostToWiiMessageBoard);
        AddPage(PageID::Unknown_5D);
        break;

    case SectionID::Cannot_Access_System_Memory:
        AddPage(PageID::SystemMemoryCorrupt);
        AddPage(PageID::Unknown_5D);
        break;

    case SectionID::Cannot_Access_Mii_Data:
        AddPage(PageID::MiiDataCorrupt);
        AddPage(PageID::Unknown_5D);
        break;

    case SectionID::ESRB_Notice:
        AddPage(PageID::ESRBNotice);
        break;

    case SectionID::Recommend_60Hz_1:
        AddPage(PageID::Recommend60Hz);
        break;

    case SectionID::Recommend_60Hz_2:
        AddPage(PageID::Recommend60Hz);
        break;

    case SectionID::Grand_Prix_Panorama:
        AddPage(PageID::GrandPrixIntro);
        break;

    case SectionID::VS_Race_Panorama:
        AddPage(PageID::VSIntro);
        break;

    case SectionID::Balloon_Battle_Panorama:
        AddPage(PageID::BattleIntro);
        break;

    case SectionID::Mission_Boss_Panorama:
        AddPage(PageID::MissionIntro);
        break;

    case SectionID::Tournament_Boss_Panorama:
        AddPage(PageID::TournamentIntro);
        break;

    case SectionID::Grand_Prix_Gameplay:
        AddPage(PageID::GrandPrix1P);
        AddPage(PageID::PauseMenuGrandPrix);
        AddPage(PageID::AfterMenuGrandPrix);
        AddPage(PageID::ConfirmQuitPrompt);
        AddPage(PageID::ResultRaceUpdate);
        AddPage(PageID::ResultRaceTotal);
        AddPage(PageID::Unknown_3A);
        break;

    case SectionID::Time_Trial_Gameplay:
        AddPage(PageID::TimeTrial1P);
        AddPage(PageID::PauseMenuTimeTrial);
        AddPage(PageID::AfterMenuTimeTrial);
        AddPage(PageID::SendFriendGhostPrompt);
        AddPage(PageID::CheckRankingsPrompt);
        AddPage(PageID::TimeTrialSplits);
        AddPage(PageID::TimeTrialLeaderboard);
        AddPage(PageID::Unknown_3A);
        AddPage(PageID::GhostManager);
        break;

    case SectionID::S_1P_VS_Race_Gameplay:
        AddPage(PageID::VSRace1P);
        AddPage(PageID::PauseMenuVS);
        AddPage(PageID::AfterMenuVS);
        AddPage(PageID::ResultRaceUpdate);
        AddPage(PageID::ResultRaceTotal);
        AddPage(PageID::Unknown_3A);
        break;

    case SectionID::S_2P_VS_Race_Gameplay:
        AddPage(PageID::VSRace2P);
        AddPage(PageID::PauseMenuVS);
        AddPage(PageID::AfterMenuVS);
        AddPage(PageID::ConfirmQuitPrompt);
        AddPage(PageID::ResultRaceUpdate);
        AddPage(PageID::ResultRaceTotal);
        AddPage(PageID::Unknown_3A);
        break;

    case SectionID::S_3P_VS_Race_Gameplay:
        AddPage(PageID::VSRace3P);
        AddPage(PageID::PauseMenuVS);
        AddPage(PageID::AfterMenuVS);
        AddPage(PageID::ConfirmQuitPrompt);
        AddPage(PageID::ResultRaceUpdate);
        AddPage(PageID::ResultRaceTotal);
        AddPage(PageID::Unknown_3A);
        break;

    case SectionID::S_4P_VS_Race_Gameplay:
        AddPage(PageID::VSRace4P);
        AddPage(PageID::PauseMenuVS);
        AddPage(PageID::AfterMenuVS);
        AddPage(PageID::ConfirmQuitPrompt);
        AddPage(PageID::ResultRaceUpdate);
        AddPage(PageID::ResultRaceTotal);
        AddPage(PageID::Unknown_3A);
        break;

    case SectionID::S_1P_Team_VS_Race_Gameplay:
        AddPage(PageID::VSRace1P);
        AddPage(PageID::PauseMenuVS);
        AddPage(PageID::AfterMenuVS);
        AddPage(PageID::ResultRaceUpdate);
        AddPage(PageID::ResultTeamVSTotal);
        AddPage(PageID::Unknown_3A);
        break;

    case SectionID::S_2P_Team_VS_Race_Gameplay:
        AddPage(PageID::VSRace2P);
        AddPage(PageID::PauseMenuVS);
        AddPage(PageID::AfterMenuVS);
        AddPage(PageID::ConfirmQuitPrompt);
        AddPage(PageID::ResultRaceUpdate);
        AddPage(PageID::ResultTeamVSTotal);
        AddPage(PageID::Unknown_3A);
        break;

    case SectionID::S_3P_Team_VS_Race_Gameplay:
        AddPage(PageID::VSRace3P);
        AddPage(PageID::PauseMenuVS);
        AddPage(PageID::AfterMenuVS);
        AddPage(PageID::ConfirmQuitPrompt);
        AddPage(PageID::ResultRaceUpdate);
        AddPage(PageID::ResultTeamVSTotal);
        AddPage(PageID::Unknown_3A);
        break;

    case SectionID::S_4P_Team_VS_Race_Gameplay:
        AddPage(PageID::VSRace4P);
        AddPage(PageID::PauseMenuVS);
        AddPage(PageID::AfterMenuVS);
        AddPage(PageID::ConfirmQuitPrompt);
        AddPage(PageID::ResultRaceUpdate);
        AddPage(PageID::ResultTeamVSTotal);
        AddPage(PageID::Unknown_3A);
        break;

    case SectionID::S_1P_Battle_Gameplay:
        AddPage(PageID::Battle1P);
        AddPage(PageID::PauseMenuBattle);
        AddPage(PageID::AfterMenuBattle);
        AddPage(PageID::AfterMenuFinalRace);
        AddPage(PageID::ResultBattleUpdate);
        AddPage(PageID::ResultBattleTotal);
        AddPage(PageID::Unknown_3A);
        break;

    case SectionID::S_2P_Battle_Gameplay:
        AddPage(PageID::Battle2P);
        AddPage(PageID::PauseMenuBattle);
        AddPage(PageID::AfterMenuBattle);
        AddPage(PageID::AfterMenuFinalRace);
        AddPage(PageID::ConfirmQuitPrompt);
        AddPage(PageID::ResultBattleUpdate);
        AddPage(PageID::ResultBattleTotal);
        AddPage(PageID::Unknown_3A);
        break;

    case SectionID::S_3P_Battle_Gameplay:
        AddPage(PageID::Battle3P);
        AddPage(PageID::PauseMenuBattle);
        AddPage(PageID::AfterMenuBattle);
        AddPage(PageID::AfterMenuFinalRace);
        AddPage(PageID::ConfirmQuitPrompt);
        AddPage(PageID::ResultBattleUpdate);
        AddPage(PageID::ResultBattleTotal);
        AddPage(PageID::Unknown_3A);
        break;

    case SectionID::S_4P_Battle_Gameplay:
        AddPage(PageID::Battle4P);
        AddPage(PageID::PauseMenuBattle);
        AddPage(PageID::AfterMenuBattle);
        AddPage(PageID::AfterMenuFinalRace);
        AddPage(PageID::ConfirmQuitPrompt);
        AddPage(PageID::ResultBattleUpdate);
        AddPage(PageID::ResultBattleTotal);
        AddPage(PageID::Unknown_3A);
        break;

    case SectionID::Mission_Mode_Gameplay:
        AddPage(PageID::Mission1P);
        AddPage(PageID::PauseMenuMission);
        AddPage(PageID::AfterMenuMission);
        AddPage(PageID::ConfirmQuitPrompt);
        AddPage(PageID::Unknown_3A);
        break;

    case SectionID::Tournament_Gameplay:
        AddPage(PageID::Mission1P);
        AddPage(PageID::PauseMenuMission);
        AddPage(PageID::AfterMenuTournament);
        AddPage(PageID::SendTournamentRecord);
        AddPage(PageID::TournamentPersonalLeaderboard);
        AddPage(PageID::Unknown_3A);
        break;

    case SectionID::Grand_Prix_Replay:
        AddPage(PageID::ConfirmQuitPrompt);
        AddPage(PageID::GrandPrixReplay);
        AddPage(PageID::PauseMenuGrandPrixReplay);
        AddPage(PageID::Unknown_3A);
        break;

    case SectionID::Time_Trial_Replay:
        AddPage(PageID::AfterMenuTimeTrial);
        AddPage(PageID::CheckRankingsPrompt);
        AddPage(PageID::GhostRace);
        AddPage(PageID::PauseMenuTimeTrialReplay);
        AddPage(PageID::Unknown_3A);
        AddPage(PageID::GhostManager);
        break;

    case SectionID::Ghost_Race_Gameplay_1:
        AddPage(PageID::TimeTrial1P);
        AddPage(PageID::PauseMenuGhostRace);
        AddPage(PageID::AbandonGhostRacePrompt);
        AddPage(PageID::QuitGhostRacePrompt);
        AddPage(PageID::AfterMenuGhostRace);
        AddPage(PageID::GoToFriendRosterPrompt);
        AddPage(PageID::ConfirmQuitPrompt);
        AddPage(PageID::TimeTrialSplits);
        AddPage(PageID::TimeTrialLeaderboard);
        AddPage(PageID::Unknown_3A);
        break;

    case SectionID::Ghost_Race_Gameplay_2:
        AddPage(PageID::TimeTrial1P);
        AddPage(PageID::PauseMenuGhostRace);
        AddPage(PageID::AbandonGhostRacePrompt);
        AddPage(PageID::QuitGhostRacePrompt);
        AddPage(PageID::AfterMenuGhostRace);
        AddPage(PageID::GoToFriendRosterPrompt);
        AddPage(PageID::ConfirmQuitPrompt);
        AddPage(PageID::TimeTrialSplits);
        AddPage(PageID::TimeTrialLeaderboard);
        AddPage(PageID::Unknown_3A);
        AddPage(PageID::Unknown_88);
        break;

    case SectionID::Watch_Ghost_From_Channel:
        AddPage(PageID::PauseMenuGhostReplay);
        AddPage(PageID::ConfirmQuitPrompt);
        AddPage(PageID::GhostRace);
        AddPage(PageID::Unknown_3A);
        AddPage(PageID::GhostManager);
        break;

    case SectionID::Watch_Ghost_From_Downloads:
        AddPage(PageID::PauseMenuGhostReplay);
        AddPage(PageID::ConfirmQuitPrompt);
        AddPage(PageID::GhostRace);
        AddPage(PageID::Unknown_3A);
        AddPage(PageID::GhostManager);
        break;

    case SectionID::Watch_Ghost_From_Menu:
        AddPage(PageID::PauseMenuGhostReplay);
        AddPage(PageID::ConfirmQuitPrompt);
        AddPage(PageID::GhostRace);
        AddPage(PageID::Unknown_3A);
        AddPage(PageID::GhostManager);
        break;

    case SectionID::Grand_Prix_Award:
        AddPage(PageID::Unknown_3B);
        AddPage(PageID::Unknown_3C);
        break;

    case SectionID::VS_Race_Award:
        AddPage(PageID::Unknown_3B);
        AddPage(PageID::Unknown_3C);
        break;

    case SectionID::Award_37:
        AddPage(PageID::Unknown_3B);
        AddPage(PageID::Unknown_3C);
        break;

    case SectionID::Award_38:
        AddPage(PageID::Unknown_3B);
        AddPage(PageID::Unknown_3C);
        break;

    case SectionID::Ending_Normal_A:
        AddPage(PageID::Unknown_3D);
        break;

    case SectionID::Ending_True_A:
        AddPage(PageID::Unknown_3D);
        break;

    case SectionID::Ending_Normal_B:
        AddPage(PageID::Unknown_3D);
        AddPage(PageID::Unknown_3E);
        break;

    case SectionID::Ending_True_B:
        AddPage(PageID::Unknown_3D);
        AddPage(PageID::Unknown_3E);
        break;

    case SectionID::Congratulations:
        AddPage(PageID::AfterCreditsCongrats);
        AddPage(PageID::ReadingGhostData);
        AddPage(PageID::MenuMessage);
        AddPage(PageID::PostToWiiMessageBoard);
        AddPage(PageID::ModelRender);
        break;

    case SectionID::Congratulations_Complete:
        AddPage(PageID::AfterCreditsCongrats);
        AddPage(PageID::ReadingGhostData);
        AddPage(PageID::MenuMessage);
        AddPage(PageID::PostToWiiMessageBoard);
        AddPage(PageID::ModelRender);
        break;

    case SectionID::Main_Menu_From_Boot:
        AddPage(PageID::PopupMessage);
        AddPage(PageID::Confirm);
        AddPage(PageID::Unknown_54);
        AddPage(PageID::Unknown_55);
        AddPage(PageID::LowBatteryNotification);
        AddPage(PageID::Title);
        AddPage(PageID::Unknown_58);
        AddPage(PageID::OpeningMovie);
        AddPage(PageID::TopMenu);
        AddPage(PageID::MenuOverlay);
        AddPage(PageID::LicenseSelect);
        break;

    case SectionID::Main_Menu_From_Reset:
        AddPage(PageID::PopupMessage);
        AddPage(PageID::Confirm);
        AddPage(PageID::Unknown_54);
        AddPage(PageID::Unknown_55);
        AddPage(PageID::LowBatteryNotification);
        AddPage(PageID::Title);
        AddPage(PageID::Unknown_58);
        AddPage(PageID::OpeningMovie);
        AddPage(PageID::TopMenu);
        AddPage(PageID::MenuOverlay);
        AddPage(PageID::LicenseSelect);
        break;

    case SectionID::Main_Menu_From_Menu:
        AddPage(PageID::PopupMessage);
        AddPage(PageID::Confirm);
        AddPage(PageID::Unknown_54);
        AddPage(PageID::Unknown_55);
        AddPage(PageID::LowBatteryNotification);
        AddPage(PageID::Title);
        AddPage(PageID::Unknown_58);
        AddPage(PageID::OpeningMovie);
        AddPage(PageID::TopMenu);
        AddPage(PageID::MenuOverlay);
        AddPage(PageID::LicenseSelect);
        break;

    case SectionID::Main_Menu_From_New_License:
        AddPage(PageID::PopupMessage);
        AddPage(PageID::Confirm);
        AddPage(PageID::Unknown_54);
        AddPage(PageID::Unknown_55);
        AddPage(PageID::LowBatteryNotification);
        AddPage(PageID::Title);
        AddPage(PageID::Unknown_58);
        AddPage(PageID::OpeningMovie);
        AddPage(PageID::TopMenu);
        AddPage(PageID::MenuOverlay);
        AddPage(PageID::LicenseSelect);
        break;

    case SectionID::Main_Menu_From_License_43:
        AddPage(PageID::PopupMessage);
        AddPage(PageID::Confirm);
        AddPage(PageID::Unknown_54);
        AddPage(PageID::Unknown_55);
        AddPage(PageID::LowBatteryNotification);
        AddPage(PageID::Title);
        AddPage(PageID::Unknown_58);
        AddPage(PageID::OpeningMovie);
        AddPage(PageID::TopMenu);
        AddPage(PageID::MenuOverlay);
        AddPage(PageID::LicenseSelect);
        break;

    case SectionID::Demo:
        AddPage(PageID::Unknown_3A);
        AddPage(PageID::Unknown_5F);
        break;

    case SectionID::Mii_Select_1:
        AddPage(PageID::MenuMessage);
        AddPage(PageID::Confirm);
        AddPage(PageID::Unknown_5D);
        AddPage(PageID::MenuOverlay);
        AddPage(PageID::MiiSelect);
        AddPage(PageID::MiiChanged);
        break;

    case SectionID::Mii_Select_2:
        AddPage(PageID::MenuMessage);
        AddPage(PageID::Confirm);
        AddPage(PageID::Unknown_5D);
        AddPage(PageID::MenuOverlay);
        AddPage(PageID::MiiSelect);
        AddPage(PageID::MiiChanged);
        break;

    case SectionID::License_Settings:
        AddPage(PageID::PopupYesNo);
        AddPage(PageID::MenuMessage);
        AddPage(PageID::Confirm);
        AddPage(PageID::Unknown_5D);
        AddPage(PageID::MenuOverlay);
        AddPage(PageID::MiiSelect);
        AddPage(PageID::MiiChanged);
        AddPage(PageID::LicenseSettingsTop);
        AddPage(PageID::EraseLicense);
        AddPage(PageID::LicenseRecordsOverall);
        AddPage(PageID::LicenseRecordsFavorites);
        AddPage(PageID::LicenseRecordsFriends);
        AddPage(PageID::LicenseRecordsWFC);
        AddPage(PageID::LicenseRecordsOther);
        break;

    case SectionID::Single_Player_From_Menu:
        AddPage(PageID::StartRaceConfirm);
        AddPage(PageID::PopupMessage);
        AddPage(PageID::ReadingGhostData);
        AddPage(PageID::MenuMessage);
        AddPage(PageID::Confirm);
        AddPage(PageID::PostToWiiMessageBoard);
        AddPage(PageID::BackModel);
        AddPage(PageID::MenuOverlay);
        AddPage(PageID::SingleTop);
        AddPage(PageID::GrandPrixClassSelect);
        AddPage(PageID::CharacterSelect);
        AddPage(PageID::VehicleSelect);
        AddPage(PageID::DriftSelect);
        AddPage(PageID::CupSelect);
        AddPage(PageID::CourseSelect);
        AddPage(PageID::TimeAttackTop);
        AddPage(PageID::TimeAttackGhostList);
        AddPage(PageID::VSSelect);
        AddPage(PageID::VSSetting);
        AddPage(PageID::TeamConfirm);
        AddPage(PageID::BattleModeSelect);
        AddPage(PageID::BattleVehicleSelect);
        AddPage(PageID::BattleSetting);
        AddPage(PageID::BattleCupSelect);
        AddPage(PageID::BattleCourseSelect);
        AddPage(PageID::ModelRender);
        AddPage(PageID::GhostManager);
        break;

    case SectionID::Single_Player_TT_Change_Chara:
        AddPage(PageID::StartRaceConfirm);
        AddPage(PageID::PopupMessage);
        AddPage(PageID::ReadingGhostData);
        AddPage(PageID::MenuMessage);
        AddPage(PageID::Confirm);
        AddPage(PageID::PostToWiiMessageBoard);
        AddPage(PageID::BackModel);
        AddPage(PageID::MenuOverlay);
        AddPage(PageID::SingleTop);
        AddPage(PageID::GrandPrixClassSelect);
        AddPage(PageID::CharacterSelect);
        AddPage(PageID::VehicleSelect);
        AddPage(PageID::DriftSelect);
        AddPage(PageID::CupSelect);
        AddPage(PageID::CourseSelect);
        AddPage(PageID::TimeAttackTop);
        AddPage(PageID::TimeAttackGhostList);
        AddPage(PageID::VSSelect);
        AddPage(PageID::VSSetting);
        AddPage(PageID::TeamConfirm);
        AddPage(PageID::BattleModeSelect);
        AddPage(PageID::BattleVehicleSelect);
        AddPage(PageID::BattleSetting);
        AddPage(PageID::BattleCupSelect);
        AddPage(PageID::BattleCourseSelect);
        AddPage(PageID::ModelRender);
        AddPage(PageID::GhostManager);
        break;

    case SectionID::Single_Player_TT_Change_Course:
        AddPage(PageID::StartRaceConfirm);
        AddPage(PageID::PopupMessage);
        AddPage(PageID::ReadingGhostData);
        AddPage(PageID::MenuMessage);
        AddPage(PageID::Confirm);
        AddPage(PageID::PostToWiiMessageBoard);
        AddPage(PageID::BackModel);
        AddPage(PageID::MenuOverlay);
        AddPage(PageID::SingleTop);
        AddPage(PageID::GrandPrixClassSelect);
        AddPage(PageID::CharacterSelect);
        AddPage(PageID::VehicleSelect);
        AddPage(PageID::DriftSelect);
        AddPage(PageID::CupSelect);
        AddPage(PageID::CourseSelect);
        AddPage(PageID::TimeAttackTop);
        AddPage(PageID::TimeAttackGhostList);
        AddPage(PageID::VSSelect);
        AddPage(PageID::VSSetting);
        AddPage(PageID::TeamConfirm);
        AddPage(PageID::BattleModeSelect);
        AddPage(PageID::BattleVehicleSelect);
        AddPage(PageID::BattleSetting);
        AddPage(PageID::BattleCupSelect);
        AddPage(PageID::BattleCourseSelect);
        AddPage(PageID::ModelRender);
        AddPage(PageID::GhostManager);
        break;

    case SectionID::Single_Player_VS_Next_Race:
        AddPage(PageID::StartRaceConfirm);
        AddPage(PageID::PopupYesNo);
        AddPage(PageID::MenuMessage);
        AddPage(PageID::Confirm);
        AddPage(PageID::PostToWiiMessageBoard);
        AddPage(PageID::BackModel);
        AddPage(PageID::MenuOverlay);
        AddPage(PageID::CupSelect);
        AddPage(PageID::CourseSelect);
        AddPage(PageID::ModelRender);
        AddPage(PageID::GhostManager);
        break;

    case SectionID::Single_Player_BT_Next_Battle:
        AddPage(PageID::StartRaceConfirm);
        AddPage(PageID::PopupYesNo);
        AddPage(PageID::MenuMessage);
        AddPage(PageID::Confirm);
        AddPage(PageID::PostToWiiMessageBoard);
        AddPage(PageID::BackModel);
        AddPage(PageID::MenuOverlay);
        AddPage(PageID::BattleCupSelect);
        AddPage(PageID::BattleCourseSelect);
        AddPage(PageID::ModelRender);
        AddPage(PageID::GhostManager);
        break;

    case SectionID::Single_Player_MR_Choose_Mission:
        AddPage(PageID::StartRaceConfirm);
        AddPage(PageID::PopupMessage);
        AddPage(PageID::ReadingGhostData);
        AddPage(PageID::MenuMessage);
        AddPage(PageID::Confirm);
        AddPage(PageID::PostToWiiMessageBoard);
        AddPage(PageID::BackModel);
        AddPage(PageID::MenuOverlay);
        AddPage(PageID::SingleTop);
        AddPage(PageID::GrandPrixClassSelect);
        AddPage(PageID::CharacterSelect);
        AddPage(PageID::VehicleSelect);
        AddPage(PageID::DriftSelect);
        AddPage(PageID::CupSelect);
        AddPage(PageID::CourseSelect);
        AddPage(PageID::TimeAttackTop);
        AddPage(PageID::TimeAttackGhostList);
        AddPage(PageID::VSSelect);
        AddPage(PageID::VSSetting);
        AddPage(PageID::TeamConfirm);
        AddPage(PageID::BattleModeSelect);
        AddPage(PageID::BattleVehicleSelect);
        AddPage(PageID::BattleSetting);
        AddPage(PageID::BattleCupSelect);
        AddPage(PageID::BattleCourseSelect);
        AddPage(PageID::ModelRender);
        AddPage(PageID::GhostManager);
        break;

    case SectionID::Single_Player_Chan_Race_Ghost:
        AddPage(PageID::StartRaceConfirm);
        AddPage(PageID::PopupMessage);
        AddPage(PageID::BackModel);
        AddPage(PageID::MenuOverlay);
        AddPage(PageID::CharacterSelect);
        AddPage(PageID::VehicleSelect);
        AddPage(PageID::DriftSelect);
        AddPage(PageID::ModelRender);
        AddPage(PageID::GhostManager);
        break;

    case SectionID::Single_Player_LB_Race_Ghost:
        AddPage(PageID::StartRaceConfirm);
        AddPage(PageID::PopupMessage);
        AddPage(PageID::BackModel);
        AddPage(PageID::MenuOverlay);
        AddPage(PageID::CharacterSelect);
        AddPage(PageID::VehicleSelect);
        AddPage(PageID::DriftSelect);
        AddPage(PageID::ModelRender);
        AddPage(PageID::GhostManager);
        break;

    case SectionID::Single_Player_List_Race_Ghost:
        AddPage(PageID::StartRaceConfirm);
        AddPage(PageID::PopupMessage);
        AddPage(PageID::BackModel);
        AddPage(PageID::MenuOverlay);
        AddPage(PageID::CharacterSelect);
        AddPage(PageID::VehicleSelect);
        AddPage(PageID::DriftSelect);
        AddPage(PageID::ModelRender);
        AddPage(PageID::GhostManager);
        break;

    case SectionID::Send_Ghost_To_Friend:
        AddPage(PageID::ReadingGhostData);
        AddPage(PageID::MenuMessage);
        AddPage(PageID::BackModel);
        AddPage(PageID::MenuOverlay);
        AddPage(PageID::GhostManager);
        AddPage(PageID::Unknown_B6);
        break;

    case SectionID::Race_Ghost_From_Chan_Boot:
        AddPage(PageID::ReadingGhostData);
        AddPage(PageID::BackModel);
        AddPage(PageID::MenuOverlay);
        AddPage(PageID::GhostManager);
        AddPage(PageID::Unknown_B1);
        AddPage(PageID::Unknown_B2);
        break;

    case SectionID::Watch_Replay_From_Chan_Boot:
        AddPage(PageID::ReadingGhostData);
        AddPage(PageID::BackModel);
        AddPage(PageID::MenuOverlay);
        AddPage(PageID::GhostManager);
        AddPage(PageID::Unknown_B1);
        AddPage(PageID::Unknown_B2);
        break;

    case SectionID::Local_Multiplayer:
        AddPage(PageID::StartRaceConfirm);
        AddPage(PageID::PopupWaiting);
        AddPage(PageID::PopupMessage);
        AddPage(PageID::Confirm);
        AddPage(PageID::BackModel);
        AddPage(PageID::MenuOverlay);
        AddPage(PageID::MiiSelect);
        AddPage(PageID::MultiPadRegister);
        AddPage(PageID::ControllerOptIn);
        AddPage(PageID::PairWiiRemotes);
        AddPage(PageID::ControllerOptInComplete);
        AddPage(PageID::CharacterSelect);
        AddPage(PageID::CupSelect);
        AddPage(PageID::CourseSelect);
        AddPage(PageID::VSSelect);
        AddPage(PageID::VSSetting);
        AddPage(PageID::TeamConfirm);
        AddPage(PageID::BattleModeSelect);
        AddPage(PageID::BattleSetting);
        AddPage(PageID::BattleCupSelect);
        AddPage(PageID::BattleCourseSelect);
        AddPage(PageID::ModelRender);
        AddPage(PageID::MultiTop);
        AddPage(PageID::MultiVehicleSelect);
        AddPage(PageID::MultiDriftSelect);
        AddPage(PageID::MultiTeamSelect);
        break;

    case SectionID::S_1P_Wifi:
        AddPage(PageID::PopupWaiting);
        AddPage(PageID::PopupMessage);
        AddPage(PageID::PopupYesNo);
        AddPage(PageID::ReadingGhostData);
        AddPage(PageID::WifiConnecting);
        AddPage(PageID::MenuMessage);
        AddPage(PageID::Confirm);
        AddPage(PageID::MenuOverlay);
        AddPage(PageID::CharacterSelect);
        AddPage(PageID::VehicleSelect);
        AddPage(PageID::DriftSelect);
        AddPage(PageID::BattleVehicleSelect);
        AddPage(PageID::ModelRender);
        AddPage(PageID::Unknown_84);
        AddPage(PageID::WifiFirstPlay);
        AddPage(PageID::WifiDataSharingPrompt);
        AddPage(PageID::Unknown_87);
        AddPage(PageID::Unknown_88);
        AddPage(PageID::WifiConnectError);
        AddPage(PageID::WifiMenuTop);
        AddPage(PageID::WifiModeSelect);
        AddPage(PageID::WifiFriendsMenu);
        AddPage(PageID::WifiSearchManager);
        AddPage(PageID::WifiGlobeModel);
        AddPage(PageID::WifiFriendRoster);
        AddPage(PageID::WifiNotFriendsYet);
        AddPage(PageID::WifiRemoveFriendCodePrompt);
        AddPage(PageID::WifiRemovingFriendCode);
        AddPage(PageID::WifiFriendRoomWaitingText);
        AddPage(PageID::WifiFriendRoomManager);
        AddPage(PageID::WifiFriendRoom);
        AddPage(PageID::WifiFriendRoomMessageSelect);
        AddPage(PageID::Unknown_A5);
        AddPage(PageID::EnterFriendCode);
        AddPage(PageID::GhostManager);
        break;

    case SectionID::S_1P_Wifi_Globe_Disconnect:
        AddPage(PageID::PopupWaiting);
        AddPage(PageID::PopupMessage);
        AddPage(PageID::PopupYesNo);
        AddPage(PageID::ReadingGhostData);
        AddPage(PageID::WifiConnecting);
        AddPage(PageID::MenuMessage);
        AddPage(PageID::Confirm);
        AddPage(PageID::MenuOverlay);
        AddPage(PageID::CharacterSelect);
        AddPage(PageID::VehicleSelect);
        AddPage(PageID::DriftSelect);
        AddPage(PageID::BattleVehicleSelect);
        AddPage(PageID::ModelRender);
        AddPage(PageID::Unknown_84);
        AddPage(PageID::WifiFirstPlay);
        AddPage(PageID::WifiDataSharingPrompt);
        AddPage(PageID::Unknown_87);
        AddPage(PageID::Unknown_88);
        AddPage(PageID::WifiConnectError);
        AddPage(PageID::WifiMenuTop);
        AddPage(PageID::WifiModeSelect);
        AddPage(PageID::WifiFriendsMenu);
        AddPage(PageID::WifiSearchManager);
        AddPage(PageID::WifiGlobeModel);
        AddPage(PageID::WifiFriendRoster);
        AddPage(PageID::WifiNotFriendsYet);
        AddPage(PageID::WifiRemoveFriendCodePrompt);
        AddPage(PageID::WifiRemovingFriendCode);
        AddPage(PageID::WifiFriendRoomWaitingText);
        AddPage(PageID::WifiFriendRoomManager);
        AddPage(PageID::WifiFriendRoom);
        AddPage(PageID::WifiFriendRoomMessageSelect);
        AddPage(PageID::Unknown_A5);
        AddPage(PageID::EnterFriendCode);
        AddPage(PageID::GhostManager);
        break;

    case SectionID::S_1P_Wifi_From_Find_Friend:
        AddPage(PageID::PopupWaiting);
        AddPage(PageID::PopupMessage);
        AddPage(PageID::PopupYesNo);
        AddPage(PageID::ReadingGhostData);
        AddPage(PageID::WifiConnecting);
        AddPage(PageID::MenuMessage);
        AddPage(PageID::Confirm);
        AddPage(PageID::MenuOverlay);
        AddPage(PageID::CharacterSelect);
        AddPage(PageID::VehicleSelect);
        AddPage(PageID::DriftSelect);
        AddPage(PageID::BattleVehicleSelect);
        AddPage(PageID::ModelRender);
        AddPage(PageID::Unknown_84);
        AddPage(PageID::WifiFirstPlay);
        AddPage(PageID::WifiDataSharingPrompt);
        AddPage(PageID::Unknown_87);
        AddPage(PageID::Unknown_88);
        AddPage(PageID::WifiConnectError);
        AddPage(PageID::WifiMenuTop);
        AddPage(PageID::WifiModeSelect);
        AddPage(PageID::WifiFriendsMenu);
        AddPage(PageID::WifiSearchManager);
        AddPage(PageID::WifiGlobeModel);
        AddPage(PageID::WifiFriendRoster);
        AddPage(PageID::WifiNotFriendsYet);
        AddPage(PageID::WifiRemoveFriendCodePrompt);
        AddPage(PageID::WifiRemovingFriendCode);
        AddPage(PageID::WifiFriendRoomWaitingText);
        AddPage(PageID::WifiFriendRoomManager);
        AddPage(PageID::WifiFriendRoom);
        AddPage(PageID::WifiFriendRoomMessageSelect);
        AddPage(PageID::Unknown_A5);
        AddPage(PageID::EnterFriendCode);
        AddPage(PageID::GhostManager);
        break;

    case SectionID::S_1P_Wifi_VS_Voting:
        AddPage(PageID::PopupYesNo);
        AddPage(PageID::WifiConnecting);
        AddPage(PageID::MenuMessage);
        AddPage(PageID::BackModel);
        AddPage(PageID::MenuOverlay);
        AddPage(PageID::CupSelect);
        AddPage(PageID::CourseSelect);
        AddPage(PageID::ModelRender);
        AddPage(PageID::Unknown_88);
        AddPage(PageID::WifiTimer);
        AddPage(PageID::WifiPlayerList);
        AddPage(PageID::WifiRoulette);
        break;

    case SectionID::S_1P_Wifi_Battle_Voting:
        AddPage(PageID::PopupYesNo);
        AddPage(PageID::WifiConnecting);
        AddPage(PageID::MenuMessage);
        AddPage(PageID::BackModel);
        AddPage(PageID::MenuOverlay);
        AddPage(PageID::BattleCupSelect);
        AddPage(PageID::BattleCourseSelect);
        AddPage(PageID::ModelRender);
        AddPage(PageID::Unknown_88);
        AddPage(PageID::WifiTimer);
        AddPage(PageID::WifiPlayerList);
        AddPage(PageID::WifiRoulette);
        break;

    case SectionID::S_2P_Wifi_Select_Mii:
        AddPage(PageID::Confirm);
        AddPage(PageID::MenuOverlay);
        AddPage(PageID::MiiSelect);
        AddPage(PageID::MultiPadRegister);
        AddPage(PageID::ControllerOptIn);
        AddPage(PageID::PairWiiRemotes);
        AddPage(PageID::ControllerOptInComplete);
        AddPage(PageID::Unknown_8A);
        break;

    case SectionID::S_2P_Wifi:
        AddPage(PageID::PopupWaiting);
        AddPage(PageID::PopupMessage);
        AddPage(PageID::PopupYesNo);
        AddPage(PageID::ReadingGhostData);
        AddPage(PageID::WifiConnecting);
        AddPage(PageID::MenuMessage);
        AddPage(PageID::Confirm);
        AddPage(PageID::MenuOverlay);
        AddPage(PageID::CharacterSelect);
        AddPage(PageID::BattleVehicleSelect);
        AddPage(PageID::ModelRender);
        AddPage(PageID::MultiVehicleSelect);
        AddPage(PageID::MultiDriftSelect);
        AddPage(PageID::Unknown_84);
        AddPage(PageID::WifiFirstPlay);
        AddPage(PageID::WifiDataSharingPrompt);
        AddPage(PageID::Unknown_87);
        AddPage(PageID::Unknown_88);
        AddPage(PageID::WifiConnectError);
        AddPage(PageID::WifiMenuTop);
        AddPage(PageID::WifiModeSelect);
        AddPage(PageID::WifiFriendsMenu);
        AddPage(PageID::WifiSearchManager);
        AddPage(PageID::WifiGlobeModel);
        AddPage(PageID::WifiFriendRoster);
        AddPage(PageID::WifiNotFriendsYet);
        AddPage(PageID::WifiRemoveFriendCodePrompt);
        AddPage(PageID::WifiRemovingFriendCode);
        AddPage(PageID::WifiFriendRoomWaitingText);
        AddPage(PageID::WifiFriendRoomManager);
        AddPage(PageID::WifiFriendRoom);
        AddPage(PageID::WifiFriendRoomMessageSelect);
        AddPage(PageID::Unknown_A5);
        AddPage(PageID::EnterFriendCode);
        AddPage(PageID::GhostManager);
        break;

    case SectionID::S_2P_Wifi_Globe_Disconnect:
        AddPage(PageID::PopupWaiting);
        AddPage(PageID::PopupMessage);
        AddPage(PageID::PopupYesNo);
        AddPage(PageID::ReadingGhostData);
        AddPage(PageID::WifiConnecting);
        AddPage(PageID::MenuMessage);
        AddPage(PageID::Confirm);
        AddPage(PageID::MenuOverlay);
        AddPage(PageID::CharacterSelect);
        AddPage(PageID::BattleVehicleSelect);
        AddPage(PageID::ModelRender);
        AddPage(PageID::MultiVehicleSelect);
        AddPage(PageID::MultiDriftSelect);
        AddPage(PageID::Unknown_84);
        AddPage(PageID::WifiFirstPlay);
        AddPage(PageID::WifiDataSharingPrompt);
        AddPage(PageID::Unknown_87);
        AddPage(PageID::Unknown_88);
        AddPage(PageID::WifiConnectError);
        AddPage(PageID::WifiMenuTop);
        AddPage(PageID::WifiModeSelect);
        AddPage(PageID::WifiFriendsMenu);
        AddPage(PageID::WifiSearchManager);
        AddPage(PageID::WifiGlobeModel);
        AddPage(PageID::WifiFriendRoster);
        AddPage(PageID::WifiNotFriendsYet);
        AddPage(PageID::WifiRemoveFriendCodePrompt);
        AddPage(PageID::WifiRemovingFriendCode);
        AddPage(PageID::WifiFriendRoomWaitingText);
        AddPage(PageID::WifiFriendRoomManager);
        AddPage(PageID::WifiFriendRoom);
        AddPage(PageID::WifiFriendRoomMessageSelect);
        AddPage(PageID::Unknown_A5);
        AddPage(PageID::EnterFriendCode);
        AddPage(PageID::GhostManager);
        break;

    case SectionID::Unknown_5D:
        AddPage(PageID::PopupWaiting);
        AddPage(PageID::PopupMessage);
        AddPage(PageID::PopupYesNo);
        AddPage(PageID::ReadingGhostData);
        AddPage(PageID::WifiConnecting);
        AddPage(PageID::MenuMessage);
        AddPage(PageID::Confirm);
        AddPage(PageID::MenuOverlay);
        AddPage(PageID::CharacterSelect);
        AddPage(PageID::BattleVehicleSelect);
        AddPage(PageID::ModelRender);
        AddPage(PageID::MultiVehicleSelect);
        AddPage(PageID::MultiDriftSelect);
        AddPage(PageID::Unknown_84);
        AddPage(PageID::WifiFirstPlay);
        AddPage(PageID::WifiDataSharingPrompt);
        AddPage(PageID::Unknown_87);
        AddPage(PageID::Unknown_88);
        AddPage(PageID::WifiConnectError);
        AddPage(PageID::WifiMenuTop);
        AddPage(PageID::WifiModeSelect);
        AddPage(PageID::WifiFriendsMenu);
        AddPage(PageID::WifiSearchManager);
        AddPage(PageID::WifiGlobeModel);
        AddPage(PageID::WifiFriendRoster);
        AddPage(PageID::WifiNotFriendsYet);
        AddPage(PageID::WifiRemoveFriendCodePrompt);
        AddPage(PageID::WifiRemovingFriendCode);
        AddPage(PageID::WifiFriendRoomWaitingText);
        AddPage(PageID::WifiFriendRoomManager);
        AddPage(PageID::WifiFriendRoom);
        AddPage(PageID::WifiFriendRoomMessageSelect);
        AddPage(PageID::Unknown_A5);
        AddPage(PageID::EnterFriendCode);
        AddPage(PageID::GhostManager);
        break;

    case SectionID::S_2P_Wifi_VS_Voting:
        AddPage(PageID::PopupYesNo);
        AddPage(PageID::WifiConnecting);
        AddPage(PageID::MenuMessage);
        AddPage(PageID::BackModel);
        AddPage(PageID::MenuOverlay);
        AddPage(PageID::CupSelect);
        AddPage(PageID::CourseSelect);
        AddPage(PageID::ModelRender);
        AddPage(PageID::Unknown_88);
        AddPage(PageID::WifiTimer);
        AddPage(PageID::WifiPlayerList);
        AddPage(PageID::WifiRoulette);
        break;

    case SectionID::S_2P_Wifi_Battle_Voting:
        AddPage(PageID::PopupYesNo);
        AddPage(PageID::WifiConnecting);
        AddPage(PageID::MenuMessage);
        AddPage(PageID::BackModel);
        AddPage(PageID::MenuOverlay);
        AddPage(PageID::BattleCupSelect);
        AddPage(PageID::BattleCourseSelect);
        AddPage(PageID::ModelRender);
        AddPage(PageID::Unknown_88);
        AddPage(PageID::WifiTimer);
        AddPage(PageID::WifiPlayerList);
        AddPage(PageID::WifiRoulette);
        break;

    case SectionID::S_1P_Wifi_Friend_Room_VS_Voting:
        AddPage(PageID::PopupYesNo);
        AddPage(PageID::WifiConnecting);
        AddPage(PageID::MenuMessage);
        AddPage(PageID::BackModel);
        AddPage(PageID::MenuOverlay);
        AddPage(PageID::CupSelect);
        AddPage(PageID::CourseSelect);
        AddPage(PageID::ModelRender);
        AddPage(PageID::Unknown_88);
        AddPage(PageID::WifiTimer);
        AddPage(PageID::WifiPlayerList);
        AddPage(PageID::WifiRoulette);
        break;

    case SectionID::S_1P_Wifi_Friend_Room_Team_VS_Voting:
        AddPage(PageID::PopupYesNo);
        AddPage(PageID::WifiConnecting);
        AddPage(PageID::MenuMessage);
        AddPage(PageID::BackModel);
        AddPage(PageID::MenuOverlay);
        AddPage(PageID::CupSelect);
        AddPage(PageID::CourseSelect);
        AddPage(PageID::ModelRender);
        AddPage(PageID::Unknown_88);
        AddPage(PageID::WifiTimer);
        AddPage(PageID::WifiPlayerList);
        AddPage(PageID::WifiRoulette);
        break;

    case SectionID::S_1P_Wifi_Friend_Room_Balloon_Voting:
        AddPage(PageID::PopupYesNo);
        AddPage(PageID::WifiConnecting);
        AddPage(PageID::MenuMessage);
        AddPage(PageID::BackModel);
        AddPage(PageID::MenuOverlay);
        AddPage(PageID::BattleCupSelect);
        AddPage(PageID::BattleCourseSelect);
        AddPage(PageID::ModelRender);
        AddPage(PageID::Unknown_88);
        AddPage(PageID::WifiTimer);
        AddPage(PageID::WifiPlayerList);
        AddPage(PageID::WifiRoulette);
        break;

    case SectionID::S_1P_Wifi_Friend_Room_Coin_Voting:
        AddPage(PageID::PopupYesNo);
        AddPage(PageID::WifiConnecting);
        AddPage(PageID::MenuMessage);
        AddPage(PageID::BackModel);
        AddPage(PageID::MenuOverlay);
        AddPage(PageID::BattleCupSelect);
        AddPage(PageID::BattleCourseSelect);
        AddPage(PageID::ModelRender);
        AddPage(PageID::Unknown_88);
        AddPage(PageID::WifiTimer);
        AddPage(PageID::WifiPlayerList);
        AddPage(PageID::WifiRoulette);
        break;

    case SectionID::S_2P_Wifi_Friend_Room_VS_Voting:
        AddPage(PageID::PopupYesNo);
        AddPage(PageID::WifiConnecting);
        AddPage(PageID::MenuMessage);
        AddPage(PageID::BackModel);
        AddPage(PageID::MenuOverlay);
        AddPage(PageID::CupSelect);
        AddPage(PageID::CourseSelect);
        AddPage(PageID::ModelRender);
        AddPage(PageID::Unknown_88);
        AddPage(PageID::WifiTimer);
        AddPage(PageID::WifiPlayerList);
        AddPage(PageID::WifiRoulette);
        break;

    case SectionID::S_2P_Wifi_Friend_Room_Team_VS_Voting:
        AddPage(PageID::PopupYesNo);
        AddPage(PageID::WifiConnecting);
        AddPage(PageID::MenuMessage);
        AddPage(PageID::BackModel);
        AddPage(PageID::MenuOverlay);
        AddPage(PageID::CupSelect);
        AddPage(PageID::CourseSelect);
        AddPage(PageID::ModelRender);
        AddPage(PageID::Unknown_88);
        AddPage(PageID::WifiTimer);
        AddPage(PageID::WifiPlayerList);
        AddPage(PageID::WifiRoulette);
        break;

    case SectionID::S_2P_Wifi_Friend_Room_Balloon_Voting:
        AddPage(PageID::PopupYesNo);
        AddPage(PageID::WifiConnecting);
        AddPage(PageID::MenuMessage);
        AddPage(PageID::BackModel);
        AddPage(PageID::MenuOverlay);
        AddPage(PageID::BattleCupSelect);
        AddPage(PageID::BattleCourseSelect);
        AddPage(PageID::ModelRender);
        AddPage(PageID::Unknown_88);
        AddPage(PageID::WifiTimer);
        AddPage(PageID::WifiPlayerList);
        AddPage(PageID::WifiRoulette);
        break;

    case SectionID::S_2P_Wifi_Friend_Room_Coin_Voting:
        AddPage(PageID::PopupYesNo);
        AddPage(PageID::WifiConnecting);
        AddPage(PageID::MenuMessage);
        AddPage(PageID::BackModel);
        AddPage(PageID::MenuOverlay);
        AddPage(PageID::BattleCupSelect);
        AddPage(PageID::BattleCourseSelect);
        AddPage(PageID::ModelRender);
        AddPage(PageID::Unknown_88);
        AddPage(PageID::WifiTimer);
        AddPage(PageID::WifiPlayerList);
        AddPage(PageID::WifiRoulette);
        break;

    case SectionID::S_1P_Wifi_VS_Gameplay:
        AddPage(PageID::ResultOnlineRaceUpdate);
        AddPage(PageID::Unknown_3A);
        AddPage(PageID::WifiRace1P);
        AddPage(PageID::Unknown_45);
        AddPage(PageID::AfterWifiRace);
        AddPage(PageID::ConfirmQuitWifiRace);
        AddPage(PageID::WifiPleaseWait);
        AddPage(PageID::MenuMessage);
        AddPage(PageID::Unknown_88);
        AddPage(PageID::Unknown_94);
        break;

    case SectionID::S_2P_Wifi_VS_Gameplay:
        AddPage(PageID::ResultOnlineRaceUpdate);
        AddPage(PageID::Unknown_3A);
        AddPage(PageID::WifiRace2P);
        AddPage(PageID::Unknown_45);
        AddPage(PageID::AfterWifiRace);
        AddPage(PageID::ConfirmQuitWifiRace);
        AddPage(PageID::WifiPleaseWait);
        AddPage(PageID::MenuMessage);
        AddPage(PageID::Unknown_88);
        AddPage(PageID::Unknown_94);
        break;

    case SectionID::S_1P_Wifi_VS_Live_View:
        AddPage(PageID::Unknown_3A);
        AddPage(PageID::WifiPleaseWait);
        AddPage(PageID::LiveViewVS);
        AddPage(PageID::MenuMessage);
        AddPage(PageID::Unknown_88);
        AddPage(PageID::Unknown_93);
        AddPage(PageID::Unknown_94);
        break;

    case SectionID::S_2P_Wifi_VS_Live_View:
        AddPage(PageID::Unknown_3A);
        AddPage(PageID::WifiPleaseWait);
        AddPage(PageID::LiveViewVS);
        AddPage(PageID::MenuMessage);
        AddPage(PageID::Unknown_88);
        AddPage(PageID::Unknown_93);
        AddPage(PageID::Unknown_94);
        break;

    case SectionID::S_1P_Wifi_BT_Gameplay:
        AddPage(PageID::Battle1P);
        AddPage(PageID::ResultOnlineRaceUpdate);
        AddPage(PageID::ResultBattleUpdate);
        AddPage(PageID::Unknown_3A);
        AddPage(PageID::Unknown_45);
        AddPage(PageID::AfterWifiRace);
        AddPage(PageID::ConfirmQuitWifiRace);
        AddPage(PageID::WifiPleaseWait);
        AddPage(PageID::MenuMessage);
        AddPage(PageID::Unknown_88);
        AddPage(PageID::Unknown_94);
        break;

    case SectionID::S_2P_Wifi_BT_Gameplay:
        AddPage(PageID::Battle2P);
        AddPage(PageID::ResultOnlineRaceUpdate);
        AddPage(PageID::ResultBattleUpdate);
        AddPage(PageID::Unknown_3A);
        AddPage(PageID::Unknown_45);
        AddPage(PageID::AfterWifiRace);
        AddPage(PageID::ConfirmQuitWifiRace);
        AddPage(PageID::WifiPleaseWait);
        AddPage(PageID::MenuMessage);
        AddPage(PageID::Unknown_88);
        AddPage(PageID::Unknown_94);
        break;

    case SectionID::S_1P_Wifi_BT_Live_View:
        AddPage(PageID::ResultBattleUpdate);
        AddPage(PageID::Unknown_3A);
        AddPage(PageID::WifiPleaseWait);
        AddPage(PageID::LiveViewBattle);
        AddPage(PageID::MenuMessage);
        AddPage(PageID::Unknown_88);
        AddPage(PageID::Unknown_93);
        AddPage(PageID::Unknown_94);
        break;

    case SectionID::S_2P_Wifi_BT_Live_View:
        AddPage(PageID::ResultBattleUpdate);
        AddPage(PageID::Unknown_3A);
        AddPage(PageID::WifiPleaseWait);
        AddPage(PageID::LiveViewBattle);
        AddPage(PageID::MenuMessage);
        AddPage(PageID::Unknown_88);
        AddPage(PageID::Unknown_93);
        AddPage(PageID::Unknown_94);
        break;

    case SectionID::S_1P_Wifi_Friend_VS_Gameplay:
        AddPage(PageID::ResultRaceUpdate);
        AddPage(PageID::ResultRaceTotal);
        AddPage(PageID::Unknown_3A);
        AddPage(PageID::WifiFriendRace);
        AddPage(PageID::WifiFriendFinalResults);
        AddPage(PageID::WifiPleaseWait);
        AddPage(PageID::MenuMessage);
        AddPage(PageID::Unknown_88);
        AddPage(PageID::Unknown_94);
        break;

    case SectionID::S_1P_Wifi_Friend_Team_VS_Gameplay:
        AddPage(PageID::ResultRaceUpdate);
        AddPage(PageID::ResultTeamVSTotal);
        AddPage(PageID::Unknown_3A);
        AddPage(PageID::WifiFriendRace);
        AddPage(PageID::WifiFriendFinalResults);
        AddPage(PageID::WifiPleaseWait);
        AddPage(PageID::MenuMessage);
        AddPage(PageID::Unknown_88);
        AddPage(PageID::Unknown_94);
        break;

    case SectionID::S_1P_Wifi_Friend_Balloon_BT_Gameplay:
        AddPage(PageID::Battle1P);
        AddPage(PageID::ResultBattleUpdate);
        AddPage(PageID::ResultBattleTotal);
        AddPage(PageID::Unknown_3A);
        AddPage(PageID::WifiFriendFinalResults);
        AddPage(PageID::WifiPleaseWait);
        AddPage(PageID::MenuMessage);
        AddPage(PageID::Unknown_88);
        AddPage(PageID::Unknown_94);
        break;

    case SectionID::S_1P_Wifi_Friend_Coin_BT_Gameplay:
        AddPage(PageID::Battle1P);
        AddPage(PageID::ResultBattleUpdate);
        AddPage(PageID::ResultBattleTotal);
        AddPage(PageID::Unknown_3A);
        AddPage(PageID::WifiFriendFinalResults);
        AddPage(PageID::WifiPleaseWait);
        AddPage(PageID::MenuMessage);
        AddPage(PageID::Unknown_88);
        AddPage(PageID::Unknown_94);
        break;

    case SectionID::S_2P_Wifi_Friend_VS_Gameplay:
        AddPage(PageID::ResultRaceUpdate);
        AddPage(PageID::ResultRaceTotal);
        AddPage(PageID::Unknown_3A);
        AddPage(PageID::WifiFriendTeamRace);
        AddPage(PageID::WifiFriendFinalResults);
        AddPage(PageID::WifiPleaseWait);
        AddPage(PageID::MenuMessage);
        AddPage(PageID::Unknown_88);
        AddPage(PageID::Unknown_94);
        break;

    case SectionID::S_2P_Wifi_Friend_Team_VS_Gameplay:
        AddPage(PageID::ResultRaceUpdate);
        AddPage(PageID::ResultTeamVSTotal);
        AddPage(PageID::Unknown_3A);
        AddPage(PageID::WifiFriendTeamRace);
        AddPage(PageID::WifiFriendFinalResults);
        AddPage(PageID::WifiPleaseWait);
        AddPage(PageID::MenuMessage);
        AddPage(PageID::Unknown_88);
        AddPage(PageID::Unknown_94);
        break;

    case SectionID::S_2P_Wifi_Friend_Balloon_BT_Gameplay:
        AddPage(PageID::Battle2P);
        AddPage(PageID::ResultBattleUpdate);
        AddPage(PageID::ResultBattleTotal);
        AddPage(PageID::Unknown_3A);
        AddPage(PageID::WifiFriendFinalResults);
        AddPage(PageID::WifiPleaseWait);
        AddPage(PageID::MenuMessage);
        AddPage(PageID::Unknown_88);
        AddPage(PageID::Unknown_94);
        break;

    case SectionID::S_2P_Wifi_Friend_Coin_BT_Gameplay:
        AddPage(PageID::Battle2P);
        AddPage(PageID::ResultBattleUpdate);
        AddPage(PageID::ResultBattleTotal);
        AddPage(PageID::Unknown_3A);
        AddPage(PageID::WifiFriendFinalResults);
        AddPage(PageID::WifiPleaseWait);
        AddPage(PageID::MenuMessage);
        AddPage(PageID::Unknown_88);
        AddPage(PageID::Unknown_94);
        break;

    case SectionID::Wifi_Disconnect_Error:
        AddPage(PageID::Unknown_5D);
        AddPage(PageID::WifiConnectError);
        break;

    case SectionID::Wifi_Disconnect_General:
        AddPage(PageID::Unknown_5D);
        AddPage(PageID::WifiConnectError);
        break;

    case SectionID::Channel_From_Menu:
        AddPage(PageID::PopupMessage);
        AddPage(PageID::MenuMessage);
        AddPage(PageID::Confirm);
        AddPage(PageID::MenuOverlay);
        AddPage(PageID::ChannelTop);
        AddPage(PageID::ChannelRanking);
        AddPage(PageID::ChannelGhost);
        break;

    case SectionID::Channel_From_Check_Rankings:
        AddPage(PageID::PopupMessage);
        AddPage(PageID::MenuMessage);
        AddPage(PageID::Confirm);
        AddPage(PageID::MenuOverlay);
        AddPage(PageID::ChannelTop);
        AddPage(PageID::ChannelRanking);
        AddPage(PageID::ChannelGhost);
        break;

    case SectionID::Channel_From_Downloads:
        AddPage(PageID::PopupMessage);
        AddPage(PageID::MenuMessage);
        AddPage(PageID::Confirm);
        AddPage(PageID::MenuOverlay);
        AddPage(PageID::ChannelTop);
        AddPage(PageID::ChannelRanking);
        AddPage(PageID::ChannelGhost);
        break;

    case SectionID::Time_Trial_Leaderboards:
        AddPage(PageID::PopupYesNo);
        AddPage(PageID::ReadingGhostData);
        AddPage(PageID::WifiConnecting);
        AddPage(PageID::MenuMessage);
        AddPage(PageID::Confirm);
        AddPage(PageID::CupSelect);
        AddPage(PageID::CourseSelect);
        AddPage(PageID::Unknown_84);
        AddPage(PageID::WifiFirstPlay);
        AddPage(PageID::WifiDataSharingPrompt);
        AddPage(PageID::Unknown_88);
        AddPage(PageID::WifiConnectError);
        AddPage(PageID::WifiGlobeModel);
        AddPage(PageID::GhostManager);
        AddPage(PageID::ChannelGhostHistogram);
        AddPage(PageID::Unknown_AA);
        AddPage(PageID::Unknown_AB);
        AddPage(PageID::Unknown_AC);
        AddPage(PageID::Unknown_AD);
        AddPage(PageID::Unknown_AE);
        AddPage(PageID::Unknown_AF);
        break;

    case SectionID::Tournament_Leaderboards:
        AddPage(PageID::PopupYesNo);
        AddPage(PageID::ReadingGhostData);
        AddPage(PageID::WifiConnecting);
        AddPage(PageID::MenuMessage);
        AddPage(PageID::Confirm);
        AddPage(PageID::Unknown_84);
        AddPage(PageID::WifiFirstPlay);
        AddPage(PageID::WifiDataSharingPrompt);
        AddPage(PageID::Unknown_88);
        AddPage(PageID::WifiConnectError);
        AddPage(PageID::WifiGlobeModel);
        AddPage(PageID::Unknown_A9);
        AddPage(PageID::Unknown_AA);
        AddPage(PageID::Unknown_AB);
        AddPage(PageID::Unknown_AE);
        AddPage(PageID::Unknown_AF);
        AddPage(PageID::Unknown_B0);
        break;

    case SectionID::Ghost_Race_With_Data:
        AddPage(PageID::StartRaceConfirm);
        AddPage(PageID::PopupMessage);
        AddPage(PageID::MenuMessage);
        AddPage(PageID::MenuOverlay);
        AddPage(PageID::CharacterSelect);
        AddPage(PageID::VehicleSelect);
        AddPage(PageID::DriftSelect);
        AddPage(PageID::ModelRender);
        AddPage(PageID::Unknown_9F);
        AddPage(PageID::Unknown_A0);
        AddPage(PageID::Unknown_A1);
        break;

    case SectionID::Ghost_Race_Without_Data:
        AddPage(PageID::StartRaceConfirm);
        AddPage(PageID::PopupMessage);
        AddPage(PageID::PopupYesNo);
        AddPage(PageID::WifiConnecting);
        AddPage(PageID::MenuMessage);
        AddPage(PageID::Confirm);
        AddPage(PageID::MenuOverlay);
        AddPage(PageID::CharacterSelect);
        AddPage(PageID::VehicleSelect);
        AddPage(PageID::DriftSelect);
        AddPage(PageID::ModelRender);
        AddPage(PageID::Unknown_84);
        AddPage(PageID::WifiFirstPlay);
        AddPage(PageID::WifiDataSharingPrompt);
        AddPage(PageID::Unknown_88);
        AddPage(PageID::WifiConnectError);
        AddPage(PageID::Unknown_9F);
        AddPage(PageID::Unknown_A0);
        AddPage(PageID::Unknown_A1);
        break;

    case SectionID::Ghost_Race_Next_Race:
        AddPage(PageID::StartRaceConfirm);
        AddPage(PageID::PopupMessage);
        AddPage(PageID::PopupYesNo);
        AddPage(PageID::WifiConnecting);
        AddPage(PageID::MenuMessage);
        AddPage(PageID::Confirm);
        AddPage(PageID::MenuOverlay);
        AddPage(PageID::CharacterSelect);
        AddPage(PageID::VehicleSelect);
        AddPage(PageID::DriftSelect);
        AddPage(PageID::ModelRender);
        AddPage(PageID::Unknown_84);
        AddPage(PageID::WifiFirstPlay);
        AddPage(PageID::WifiDataSharingPrompt);
        AddPage(PageID::Unknown_88);
        AddPage(PageID::WifiConnectError);
        AddPage(PageID::Unknown_A0);
        AddPage(PageID::Unknown_A1);
        break;

    case SectionID::Downloaded_Ghost_Data:
        AddPage(PageID::PopupMessage);
        AddPage(PageID::ReadingGhostData);
        AddPage(PageID::MenuMessage);
        AddPage(PageID::MenuOverlay);
        AddPage(PageID::GhostManager);
        AddPage(PageID::Unknown_B3);
        AddPage(PageID::Unknown_B4);
        AddPage(PageID::Unknown_B5);
        break;

    case SectionID::Friends_List_1:
        AddPage(PageID::PopupWaiting);
        AddPage(PageID::PopupMessage);
        AddPage(PageID::PopupYesNo);
        AddPage(PageID::ReadingGhostData);
        AddPage(PageID::WifiConnecting);
        AddPage(PageID::MenuMessage);
        AddPage(PageID::Confirm);
        AddPage(PageID::MenuOverlay);
        AddPage(PageID::CharacterSelect);
        AddPage(PageID::VehicleSelect);
        AddPage(PageID::DriftSelect);
        AddPage(PageID::BattleVehicleSelect);
        AddPage(PageID::ModelRender);
        AddPage(PageID::Unknown_84);
        AddPage(PageID::WifiFirstPlay);
        AddPage(PageID::WifiDataSharingPrompt);
        AddPage(PageID::Unknown_87);
        AddPage(PageID::Unknown_88);
        AddPage(PageID::WifiConnectError);
        AddPage(PageID::WifiFriendsMenuChannel);
        AddPage(PageID::WifiSearchManager);
        AddPage(PageID::WifiGlobeModel);
        AddPage(PageID::WifiFriendRoster);
        AddPage(PageID::WifiNotFriendsYet);
        AddPage(PageID::WifiRemoveFriendCodePrompt);
        AddPage(PageID::WifiRemovingFriendCode);
        AddPage(PageID::WifiFriendRoomWaitingText);
        AddPage(PageID::WifiFriendRoomManager);
        AddPage(PageID::WifiFriendRoom);
        AddPage(PageID::WifiFriendRoomMessageSelect);
        AddPage(PageID::Unknown_A5);
        AddPage(PageID::EnterFriendCode);
        AddPage(PageID::GhostManager);
        break;

    case SectionID::Friends_List_2:
        AddPage(PageID::PopupWaiting);
        AddPage(PageID::PopupMessage);
        AddPage(PageID::PopupYesNo);
        AddPage(PageID::ReadingGhostData);
        AddPage(PageID::WifiConnecting);
        AddPage(PageID::MenuMessage);
        AddPage(PageID::Confirm);
        AddPage(PageID::MenuOverlay);
        AddPage(PageID::CharacterSelect);
        AddPage(PageID::VehicleSelect);
        AddPage(PageID::DriftSelect);
        AddPage(PageID::BattleVehicleSelect);
        AddPage(PageID::ModelRender);
        AddPage(PageID::Unknown_84);
        AddPage(PageID::WifiFirstPlay);
        AddPage(PageID::WifiDataSharingPrompt);
        AddPage(PageID::Unknown_87);
        AddPage(PageID::Unknown_88);
        AddPage(PageID::WifiConnectError);
        AddPage(PageID::WifiFriendsMenuChannel);
        AddPage(PageID::WifiSearchManager);
        AddPage(PageID::WifiGlobeModel);
        AddPage(PageID::WifiFriendRoster);
        AddPage(PageID::WifiNotFriendsYet);
        AddPage(PageID::WifiRemoveFriendCodePrompt);
        AddPage(PageID::WifiRemovingFriendCode);
        AddPage(PageID::Unknown_9A);
        AddPage(PageID::WifiFriendRoomWaitingText);
        AddPage(PageID::WifiFriendRoomManager);
        AddPage(PageID::WifiFriendRoom);
        AddPage(PageID::WifiFriendRoomMessageSelect);
        AddPage(PageID::Unknown_A5);
        AddPage(PageID::EnterFriendCode);
        AddPage(PageID::GhostManager);
        break;

    case SectionID::Tournament:
        AddPage(PageID::StartRaceConfirm);
        AddPage(PageID::PopupMessage);
        AddPage(PageID::MenuMessage);
        AddPage(PageID::CharacterSelect);
        AddPage(PageID::VehicleSelect);
        AddPage(PageID::DriftSelect);
        AddPage(PageID::ModelRender);
        AddPage(PageID::Unknown_B7);
        AddPage(PageID::Unknown_B8);
        AddPage(PageID::Unknown_BB);
        break;

    case SectionID::Tournament_Change_Chara:
        AddPage(PageID::StartRaceConfirm);
        AddPage(PageID::PopupMessage);
        AddPage(PageID::MenuMessage);
        AddPage(PageID::CharacterSelect);
        AddPage(PageID::VehicleSelect);
        AddPage(PageID::DriftSelect);
        AddPage(PageID::ModelRender);
        AddPage(PageID::Unknown_B7);
        AddPage(PageID::Unknown_B8);
        AddPage(PageID::Unknown_BB);
        break;

    case SectionID::Tournament_Submit_Record:
        AddPage(PageID::PopupYesNo);
        AddPage(PageID::ReadingGhostData);
        AddPage(PageID::WifiConnecting);
        AddPage(PageID::MenuMessage);
        AddPage(PageID::MenuOverlay);
        AddPage(PageID::Unknown_84);
        AddPage(PageID::WifiFirstPlay);
        AddPage(PageID::WifiDataSharingPrompt);
        AddPage(PageID::Unknown_88);
        AddPage(PageID::WifiConnectError);
        AddPage(PageID::Unknown_B9);
        break;

    case SectionID::Tournament_Wii_Wheel_Only:
        AddPage(PageID::Unknown_5B);
        AddPage(PageID::Unknown_BA);
        break;

    case SectionID::Tournament_Wii_Wheel_Only_Bosses:
        AddPage(PageID::Unknown_5B);
        AddPage(PageID::Unknown_BA);
        break;

    case SectionID::Invite_Friends_From_Msg_Board:
        AddPage(PageID::ReadingGhostData);
        AddPage(PageID::MenuMessage);
        AddPage(PageID::Confirm);
        AddPage(PageID::MenuOverlay);
        AddPage(PageID::Unknown_BD);
        AddPage(PageID::Unknown_BE);
        AddPage(PageID::Unknown_BF);
        break;

    case SectionID::Download_Latest_Data:
        AddPage(PageID::WifiConnecting);
        AddPage(PageID::MenuMessage);
        AddPage(PageID::Confirm);
        AddPage(PageID::MenuOverlay);
        AddPage(PageID::Unknown_BC);
        break;

    case SectionID::Options:
        AddPage(PageID::PopupMessage);
        AddPage(PageID::PopupYesNo);
        AddPage(PageID::Unknown_5D);
        AddPage(PageID::OptionTop);
        AddPage(PageID::OptionWifiSettings);
        AddPage(PageID::OptionExplanation);
        AddPage(PageID::OptionSelect2);
        AddPage(PageID::OptionSelect3);
        AddPage(PageID::OptionSetRegionPrompt);
        AddPage(PageID::OptionDisplayRegionPrompt);
        AddPage(PageID::OptionAwait);
        AddPage(PageID::OptionMessage);
        AddPage(PageID::OptionConfirm);
        AddPage(PageID::AddChannelExplanation);
        AddPage(PageID::AddChannelConfirm);
        AddPage(PageID::Unknown_CC);
        break;

    case SectionID::Install_Channel:
        AddPage(PageID::Unknown_5D);
        AddPage(PageID::AddChannelExplanation);
        AddPage(PageID::AddChannelConfirm);
        AddPage(PageID::Unknown_CC);
        break;

    case SectionID::Choose_Region:
        AddPage(PageID::Unknown_5D);
        AddPage(PageID::OptionSetRegionPrompt);
        AddPage(PageID::Unknown_CC);
        break;

    case SectionID::Join_Message_Service:
        AddPage(PageID::PopupYesNo);
        AddPage(PageID::Unknown_5D);
        AddPage(PageID::OptionExplanation);
        AddPage(PageID::OptionSelect2);
        AddPage(PageID::OptionDisplayRegionPrompt);
        AddPage(PageID::OptionAwait);
        AddPage(PageID::OptionMessage);
        AddPage(PageID::OptionConfirm);
        AddPage(PageID::Unknown_CC);
        break;

    case SectionID::Msg_Unlock_Pink:
        AddPage(PageID::Unknown_5B);
        AddPage(PageID::MenuOverlay);
        AddPage(PageID::ModelRender);
        AddPage(PageID::Unknown_CD);
        break;

    case SectionID::Msg_Unlock_Orange:
        AddPage(PageID::Unknown_5B);
        AddPage(PageID::MenuOverlay);
        AddPage(PageID::ModelRender);
        AddPage(PageID::Unknown_CD);
        break;

    case SectionID::Msg_Unlock_Blue:
        AddPage(PageID::Unknown_5B);
        AddPage(PageID::MenuOverlay);
        AddPage(PageID::ModelRender);
        AddPage(PageID::Unknown_CD);
        break;

    case SectionID::Msg_Unlock_Yellow:
        AddPage(PageID::Unknown_5B);
        AddPage(PageID::MenuOverlay);
        AddPage(PageID::ModelRender);
        AddPage(PageID::Unknown_CD);
        break;

    case SectionID::Broken_Mission_Mode_Menu:
        AddPage(PageID::MissionLevelSelect);
        AddPage(PageID::MissionStageSelect);
        AddPage(PageID::MissionPrompt);
        AddPage(PageID::MissionDrift);
        AddPage(PageID::MissionTutorial);
        break;
    }
}
