#include "Section.h"

namespace UI
{

REPLACE(
  0x8062C3A4, //
  void Section::AddPages(ESectionID sectionId)
)
{
    switch (sectionId) {
    default:
        break;

    case SECTION_ID_TEST_06:
        AddPage(PAGE_ID_DUMMY);
        break;

    case SECTION_ID_TEST_07:
        AddPage(PAGE_ID_DUMMY);
        break;

    case SECTION_ID_TEST_08:
        AddPage(PAGE_ID_DUMMY);
        break;

    case SECTION_ID_TEST_09:
        AddPage(PAGE_ID_DUMMY);
        break;

    case SECTION_ID_TEST_0A:
        AddPage(PAGE_ID_DUMMY);
        break;

    case SECTION_ID_TEST_0B:
        AddPage(PAGE_ID_DUMMY);
        break;

    case SECTION_ID_TEST_0C:
        AddPage(PAGE_ID_DUMMY);
        break;

    case SECTION_ID_TEST_0D:
        AddPage(PAGE_ID_DUMMY);
        break;

    case SECTION_ID_TEST_0E:
        AddPage(PAGE_ID_DUMMY);
        break;

    case SECTION_ID_TEST_0F:
        AddPage(PAGE_ID_DUMMY);
        break;

    case SECTION_ID_CREATE_NEW_SAVE:
        AddPage(PAGE_ID_SAVE_DATA_CORRUPT);
        AddPage(PAGE_ID_READING_GHOST_DATA);
        AddPage(PAGE_ID_UNKNOWN_5D);
        break;

    case SECTION_ID_CORRUPTED_SAVE:
        AddPage(PAGE_ID_SAVE_DATA_CORRUPT);
        AddPage(PAGE_ID_READING_GHOST_DATA);
        AddPage(PAGE_ID_POST_TO_WII_MESSAGE_BOARD);
        AddPage(PAGE_ID_UNKNOWN_5D);
        break;

    case SECTION_ID_COUNTRY_CHANGED:
        AddPage(PAGE_ID_SAVE_DATA_CORRUPT);
        AddPage(PAGE_ID_READING_GHOST_DATA);
        AddPage(PAGE_ID_POST_TO_WII_MESSAGE_BOARD);
        AddPage(PAGE_ID_UNKNOWN_5D);
        break;

    case SECTION_ID_GAME_CANNOT_BE_SAVED:
        AddPage(PAGE_ID_SAVE_DATA_ERROR);
        AddPage(PAGE_ID_POST_TO_WII_MESSAGE_BOARD);
        AddPage(PAGE_ID_UNKNOWN_5D);
        break;

    case SECTION_ID_CANNOT_ACCESS_SYSTEM_MEMORY:
        AddPage(PAGE_ID_SYSTEM_MEMORY_CORRUPT);
        AddPage(PAGE_ID_UNKNOWN_5D);
        break;

    case SECTION_ID_CANNOT_ACCESS_MII_DATA:
        AddPage(PAGE_ID_MII_DATA_CORRUPT);
        AddPage(PAGE_ID_UNKNOWN_5D);
        break;

    case SECTION_ID_ESRB_NOTICE:
        AddPage(PAGE_ID_ESRB_NOTICE);
        break;

    case SECTION_ID_RECOMMEND_60HZ_A:
        AddPage(PAGE_ID_RECOMMEND_60HZ);
        break;

    case SECTION_ID_RECOMMEND_60HZ_B:
        AddPage(PAGE_ID_RECOMMEND_60HZ);
        break;

    case SECTION_ID_INTRO_GRAND_PRIX:
        AddPage(PAGE_ID_GRAND_PRIX_INTRO);
        break;

    case SECTION_ID_INTRO_VS:
        AddPage(PAGE_ID_VS_INTRO);
        break;

    case SECTION_ID_INTRO_BATTLE:
        AddPage(PAGE_ID_BATTLE_INTRO);
        break;

    case SECTION_ID_INTRO_BOSS_MISSION:
        AddPage(PAGE_ID_MISSION_INTRO);
        break;

    case SECTION_ID_INTRO_BOSS_COMPETITION:
        AddPage(PAGE_ID_COMPETITION_INTRO);
        break;

    case SECTION_ID_RACE_GRAND_PRIX:
        AddPage(PAGE_ID_GRAND_PRIX_1P);
        AddPage(PAGE_ID_PAUSE_MENU_GRAND_PRIX);
        AddPage(PAGE_ID_AFTER_MENU_GRAND_PRIX);
        AddPage(PAGE_ID_CONFIRM_QUIT_PROMPT);
        AddPage(PAGE_ID_RESULT_RACE_UPDATE);
        AddPage(PAGE_ID_RESULT_RACE_TOTAL);
        AddPage(PAGE_ID_UNKNOWN_3A);
        break;

    case SECTION_ID_RACE_TIME_ATTACK:
        AddPage(PAGE_ID_TIME_ATTACK_1P);
        AddPage(PAGE_ID_PAUSE_MENU_TIME_ATTACK);
        AddPage(PAGE_ID_AFTER_MENU_TIME_ATTACK);
        AddPage(PAGE_ID_SEND_FRIEND_GHOST_PROMPT);
        AddPage(PAGE_ID_CHECK_RANKINGS_PROMPT);
        AddPage(PAGE_ID_TIME_ATTACK_SPLITS);
        AddPage(PAGE_ID_TIME_ATTACK_LEADERBOARD);
        AddPage(PAGE_ID_UNKNOWN_3A);
        AddPage(PAGE_ID_GHOST_MANAGER);
        break;

    case SECTION_ID_RACE_1P_VS:
        AddPage(PAGE_ID_VS_RACE_1P);
        AddPage(PAGE_ID_PAUSE_MENU_VS);
        AddPage(PAGE_ID_AFTER_MENU_VS);
        AddPage(PAGE_ID_RESULT_RACE_UPDATE);
        AddPage(PAGE_ID_RESULT_RACE_TOTAL);
        AddPage(PAGE_ID_UNKNOWN_3A);
        break;

    case SECTION_ID_RACE_2P_VS:
        AddPage(PAGE_ID_VS_RACE_2P);
        AddPage(PAGE_ID_PAUSE_MENU_VS);
        AddPage(PAGE_ID_AFTER_MENU_VS);
        AddPage(PAGE_ID_CONFIRM_QUIT_PROMPT);
        AddPage(PAGE_ID_RESULT_RACE_UPDATE);
        AddPage(PAGE_ID_RESULT_RACE_TOTAL);
        AddPage(PAGE_ID_UNKNOWN_3A);
        break;

    case SECTION_ID_RACE_3P_VS:
        AddPage(PAGE_ID_VS_RACE_3P);
        AddPage(PAGE_ID_PAUSE_MENU_VS);
        AddPage(PAGE_ID_AFTER_MENU_VS);
        AddPage(PAGE_ID_CONFIRM_QUIT_PROMPT);
        AddPage(PAGE_ID_RESULT_RACE_UPDATE);
        AddPage(PAGE_ID_RESULT_RACE_TOTAL);
        AddPage(PAGE_ID_UNKNOWN_3A);
        break;

    case SECTION_ID_RACE_4P_VS:
        AddPage(PAGE_ID_VS_RACE_4P);
        AddPage(PAGE_ID_PAUSE_MENU_VS);
        AddPage(PAGE_ID_AFTER_MENU_VS);
        AddPage(PAGE_ID_CONFIRM_QUIT_PROMPT);
        AddPage(PAGE_ID_RESULT_RACE_UPDATE);
        AddPage(PAGE_ID_RESULT_RACE_TOTAL);
        AddPage(PAGE_ID_UNKNOWN_3A);
        break;

    case SECTION_ID_RACE_1P_TEAM_VS:
        AddPage(PAGE_ID_VS_RACE_1P);
        AddPage(PAGE_ID_PAUSE_MENU_VS);
        AddPage(PAGE_ID_AFTER_MENU_VS);
        AddPage(PAGE_ID_RESULT_RACE_UPDATE);
        AddPage(PAGE_ID_RESULT_TEAM_VS_TOTAL);
        AddPage(PAGE_ID_UNKNOWN_3A);
        break;

    case SECTION_ID_RACE_2P_TEAM_VS:
        AddPage(PAGE_ID_VS_RACE_2P);
        AddPage(PAGE_ID_PAUSE_MENU_VS);
        AddPage(PAGE_ID_AFTER_MENU_VS);
        AddPage(PAGE_ID_CONFIRM_QUIT_PROMPT);
        AddPage(PAGE_ID_RESULT_RACE_UPDATE);
        AddPage(PAGE_ID_RESULT_TEAM_VS_TOTAL);
        AddPage(PAGE_ID_UNKNOWN_3A);
        break;

    case SECTION_ID_RACE_3P_TEAM_VS:
        AddPage(PAGE_ID_VS_RACE_3P);
        AddPage(PAGE_ID_PAUSE_MENU_VS);
        AddPage(PAGE_ID_AFTER_MENU_VS);
        AddPage(PAGE_ID_CONFIRM_QUIT_PROMPT);
        AddPage(PAGE_ID_RESULT_RACE_UPDATE);
        AddPage(PAGE_ID_RESULT_TEAM_VS_TOTAL);
        AddPage(PAGE_ID_UNKNOWN_3A);
        break;

    case SECTION_ID_RACE_4P_TEAM_VS:
        AddPage(PAGE_ID_VS_RACE_4P);
        AddPage(PAGE_ID_PAUSE_MENU_VS);
        AddPage(PAGE_ID_AFTER_MENU_VS);
        AddPage(PAGE_ID_CONFIRM_QUIT_PROMPT);
        AddPage(PAGE_ID_RESULT_RACE_UPDATE);
        AddPage(PAGE_ID_RESULT_TEAM_VS_TOTAL);
        AddPage(PAGE_ID_UNKNOWN_3A);
        break;

    case SECTION_ID_RACE_1P_BATTLE:
        AddPage(PAGE_ID_BATTLE_1P);
        AddPage(PAGE_ID_PAUSE_MENU_BATTLE);
        AddPage(PAGE_ID_AFTER_MENU_BATTLE);
        AddPage(PAGE_ID_AFTER_MENU_FINAL_RACE);
        AddPage(PAGE_ID_RESULT_BATTLE_UPDATE);
        AddPage(PAGE_ID_RESULT_BATTLE_TOTAL);
        AddPage(PAGE_ID_UNKNOWN_3A);
        break;

    case SECTION_ID_RACE_2P_BATTLE:
        AddPage(PAGE_ID_BATTLE_2P);
        AddPage(PAGE_ID_PAUSE_MENU_BATTLE);
        AddPage(PAGE_ID_AFTER_MENU_BATTLE);
        AddPage(PAGE_ID_AFTER_MENU_FINAL_RACE);
        AddPage(PAGE_ID_CONFIRM_QUIT_PROMPT);
        AddPage(PAGE_ID_RESULT_BATTLE_UPDATE);
        AddPage(PAGE_ID_RESULT_BATTLE_TOTAL);
        AddPage(PAGE_ID_UNKNOWN_3A);
        break;

    case SECTION_ID_RACE_3P_BATTLE:
        AddPage(PAGE_ID_BATTLE_3P);
        AddPage(PAGE_ID_PAUSE_MENU_BATTLE);
        AddPage(PAGE_ID_AFTER_MENU_BATTLE);
        AddPage(PAGE_ID_AFTER_MENU_FINAL_RACE);
        AddPage(PAGE_ID_CONFIRM_QUIT_PROMPT);
        AddPage(PAGE_ID_RESULT_BATTLE_UPDATE);
        AddPage(PAGE_ID_RESULT_BATTLE_TOTAL);
        AddPage(PAGE_ID_UNKNOWN_3A);
        break;

    case SECTION_ID_RACE_4P_BATTLE:
        AddPage(PAGE_ID_BATTLE_4P);
        AddPage(PAGE_ID_PAUSE_MENU_BATTLE);
        AddPage(PAGE_ID_AFTER_MENU_BATTLE);
        AddPage(PAGE_ID_AFTER_MENU_FINAL_RACE);
        AddPage(PAGE_ID_CONFIRM_QUIT_PROMPT);
        AddPage(PAGE_ID_RESULT_BATTLE_UPDATE);
        AddPage(PAGE_ID_RESULT_BATTLE_TOTAL);
        AddPage(PAGE_ID_UNKNOWN_3A);
        break;

    case SECTION_ID_RACE_MISSION:
        AddPage(PAGE_ID_MISSION_1P);
        AddPage(PAGE_ID_PAUSE_MENU_MISSION);
        AddPage(PAGE_ID_AFTER_MENU_MISSION);
        AddPage(PAGE_ID_CONFIRM_QUIT_PROMPT);
        AddPage(PAGE_ID_UNKNOWN_3A);
        break;

    case SECTION_ID_RACE_COMPETITION:
        AddPage(PAGE_ID_MISSION_1P);
        AddPage(PAGE_ID_PAUSE_MENU_MISSION);
        AddPage(PAGE_ID_AFTER_MENU_COMPETITION);
        AddPage(PAGE_ID_SEND_COMPETITION_RECORD);
        AddPage(PAGE_ID_COMPETITION_PERSONAL_LEADERBOARD);
        AddPage(PAGE_ID_UNKNOWN_3A);
        break;

    case SECTION_ID_REPLAY_GRAND_PRIX:
        AddPage(PAGE_ID_CONFIRM_QUIT_PROMPT);
        AddPage(PAGE_ID_REPLAY_GRAND_PRIX);
        AddPage(PAGE_ID_PAUSE_MENU_REPLAY_GRAND_PRIX);
        AddPage(PAGE_ID_UNKNOWN_3A);
        break;

    case SECTION_ID_REPLAY_TIME_ATTACK:
        AddPage(PAGE_ID_AFTER_MENU_TIME_ATTACK);
        AddPage(PAGE_ID_CHECK_RANKINGS_PROMPT);
        AddPage(PAGE_ID_GHOST_RACE);
        AddPage(PAGE_ID_PAUSE_MENU_REPLAY_TIME_ATTACK);
        AddPage(PAGE_ID_UNKNOWN_3A);
        AddPage(PAGE_ID_GHOST_MANAGER);
        break;

    case SECTION_ID_REPLAY_GHOST_RACE_A:
        AddPage(PAGE_ID_TIME_ATTACK_1P);
        AddPage(PAGE_ID_PAUSE_MENU_GHOST_RACE);
        AddPage(PAGE_ID_ABANDON_GHOST_RACE_PROMPT);
        AddPage(PAGE_ID_QUIT_GHOST_RACE_PROMPT);
        AddPage(PAGE_ID_AFTER_MENU_GHOST_RACE);
        AddPage(PAGE_ID_GO_TO_FRIEND_ROSTER_PROMPT);
        AddPage(PAGE_ID_CONFIRM_QUIT_PROMPT);
        AddPage(PAGE_ID_TIME_ATTACK_SPLITS);
        AddPage(PAGE_ID_TIME_ATTACK_LEADERBOARD);
        AddPage(PAGE_ID_UNKNOWN_3A);
        break;

    case SECTION_ID_REPLAY_GHOST_RACE_B:
        AddPage(PAGE_ID_TIME_ATTACK_1P);
        AddPage(PAGE_ID_PAUSE_MENU_GHOST_RACE);
        AddPage(PAGE_ID_ABANDON_GHOST_RACE_PROMPT);
        AddPage(PAGE_ID_QUIT_GHOST_RACE_PROMPT);
        AddPage(PAGE_ID_AFTER_MENU_GHOST_RACE);
        AddPage(PAGE_ID_GO_TO_FRIEND_ROSTER_PROMPT);
        AddPage(PAGE_ID_CONFIRM_QUIT_PROMPT);
        AddPage(PAGE_ID_TIME_ATTACK_SPLITS);
        AddPage(PAGE_ID_TIME_ATTACK_LEADERBOARD);
        AddPage(PAGE_ID_UNKNOWN_3A);
        AddPage(PAGE_ID_UNKNOWN_88);
        break;

    case SECTION_ID_WATCH_GHOST_FROM_CHANNEL:
        AddPage(PAGE_ID_PAUSE_MENU_GHOST_REPLAY);
        AddPage(PAGE_ID_CONFIRM_QUIT_PROMPT);
        AddPage(PAGE_ID_GHOST_RACE);
        AddPage(PAGE_ID_UNKNOWN_3A);
        AddPage(PAGE_ID_GHOST_MANAGER);
        break;

    case SECTION_ID_WATCH_GHOST_FROM_DOWNLOADS:
        AddPage(PAGE_ID_PAUSE_MENU_GHOST_REPLAY);
        AddPage(PAGE_ID_CONFIRM_QUIT_PROMPT);
        AddPage(PAGE_ID_GHOST_RACE);
        AddPage(PAGE_ID_UNKNOWN_3A);
        AddPage(PAGE_ID_GHOST_MANAGER);
        break;

    case SECTION_ID_WATCH_GHOST_FROM_MENU:
        AddPage(PAGE_ID_PAUSE_MENU_GHOST_REPLAY);
        AddPage(PAGE_ID_CONFIRM_QUIT_PROMPT);
        AddPage(PAGE_ID_GHOST_RACE);
        AddPage(PAGE_ID_UNKNOWN_3A);
        AddPage(PAGE_ID_GHOST_MANAGER);
        break;

    case SECTION_ID_GRAND_PRIX_AWARD:
        AddPage(PAGE_ID_UNKNOWN_3B);
        AddPage(PAGE_ID_UNKNOWN_3C);
        break;

    case SECTION_ID_VS_RACE_AWARD:
        AddPage(PAGE_ID_UNKNOWN_3B);
        AddPage(PAGE_ID_UNKNOWN_3C);
        break;

    case SECTION_ID_AWARD_A:
        AddPage(PAGE_ID_UNKNOWN_3B);
        AddPage(PAGE_ID_UNKNOWN_3C);
        break;

    case SECTION_ID_AWARD_B:
        AddPage(PAGE_ID_UNKNOWN_3B);
        AddPage(PAGE_ID_UNKNOWN_3C);
        break;

    case SECTION_ID_ENDING_NORMAL_A:
        AddPage(PAGE_ID_UNKNOWN_3D);
        break;

    case SECTION_ID_ENDING_TRUE_A:
        AddPage(PAGE_ID_UNKNOWN_3D);
        break;

    case SECTION_ID_ENDING_NORMAL_B:
        AddPage(PAGE_ID_UNKNOWN_3D);
        AddPage(PAGE_ID_UNKNOWN_3E);
        break;

    case SECTION_ID_ENDING_TRUE_B:
        AddPage(PAGE_ID_UNKNOWN_3D);
        AddPage(PAGE_ID_UNKNOWN_3E);
        break;

    case SECTION_ID_CONGRATULATIONS:
        AddPage(PAGE_ID_AFTER_CREDITS_CONGRATS);
        AddPage(PAGE_ID_READING_GHOST_DATA);
        AddPage(PAGE_ID_MENU_MESSAGE);
        AddPage(PAGE_ID_POST_TO_WII_MESSAGE_BOARD);
        AddPage(PAGE_ID_MODEL_RENDER);
        break;

    case SECTION_ID_CONGRATULATIONS_COMPLETE:
        AddPage(PAGE_ID_AFTER_CREDITS_CONGRATS);
        AddPage(PAGE_ID_READING_GHOST_DATA);
        AddPage(PAGE_ID_MENU_MESSAGE);
        AddPage(PAGE_ID_POST_TO_WII_MESSAGE_BOARD);
        AddPage(PAGE_ID_MODEL_RENDER);
        break;

    case SECTION_ID_MAIN_MENU_FROM_BOOT:
        AddPage(PAGE_ID_POPUP_MESSAGE);
        AddPage(PAGE_ID_CONFIRM);
        AddPage(PAGE_ID_UNKNOWN_54);
        AddPage(PAGE_ID_UNKNOWN_55);
        AddPage(PAGE_ID_LOW_BATTERY_NOTIFICATION);
        AddPage(PAGE_ID_TITLE);
        AddPage(PAGE_ID_UNKNOWN_58);
        AddPage(PAGE_ID_OPENING_MOVIE);
        AddPage(PAGE_ID_TOP_MENU);
        AddPage(PAGE_ID_MENU_OVERLAY);
        AddPage(PAGE_ID_LICENSE_SELECT);
        break;

    case SECTION_ID_MAIN_MENU_FROM_RESET:
        AddPage(PAGE_ID_POPUP_MESSAGE);
        AddPage(PAGE_ID_CONFIRM);
        AddPage(PAGE_ID_UNKNOWN_54);
        AddPage(PAGE_ID_UNKNOWN_55);
        AddPage(PAGE_ID_LOW_BATTERY_NOTIFICATION);
        AddPage(PAGE_ID_TITLE);
        AddPage(PAGE_ID_UNKNOWN_58);
        AddPage(PAGE_ID_OPENING_MOVIE);
        AddPage(PAGE_ID_TOP_MENU);
        AddPage(PAGE_ID_MENU_OVERLAY);
        AddPage(PAGE_ID_LICENSE_SELECT);
        break;

    case SECTION_ID_MAIN_MENU_FROM_MENU:
        AddPage(PAGE_ID_POPUP_MESSAGE);
        AddPage(PAGE_ID_CONFIRM);
        AddPage(PAGE_ID_UNKNOWN_54);
        AddPage(PAGE_ID_UNKNOWN_55);
        AddPage(PAGE_ID_LOW_BATTERY_NOTIFICATION);
        AddPage(PAGE_ID_TITLE);
        AddPage(PAGE_ID_UNKNOWN_58);
        AddPage(PAGE_ID_OPENING_MOVIE);
        AddPage(PAGE_ID_TOP_MENU);
        AddPage(PAGE_ID_MENU_OVERLAY);
        AddPage(PAGE_ID_LICENSE_SELECT);
        break;

    case SECTION_ID_MAIN_MENU_FROM_NEW_LICENSE:
        AddPage(PAGE_ID_POPUP_MESSAGE);
        AddPage(PAGE_ID_CONFIRM);
        AddPage(PAGE_ID_UNKNOWN_54);
        AddPage(PAGE_ID_UNKNOWN_55);
        AddPage(PAGE_ID_LOW_BATTERY_NOTIFICATION);
        AddPage(PAGE_ID_TITLE);
        AddPage(PAGE_ID_UNKNOWN_58);
        AddPage(PAGE_ID_OPENING_MOVIE);
        AddPage(PAGE_ID_TOP_MENU);
        AddPage(PAGE_ID_MENU_OVERLAY);
        AddPage(PAGE_ID_LICENSE_SELECT);
        break;

    case SECTION_ID_MAIN_MENU_FROM_LICENSE43:
        AddPage(PAGE_ID_POPUP_MESSAGE);
        AddPage(PAGE_ID_CONFIRM);
        AddPage(PAGE_ID_UNKNOWN_54);
        AddPage(PAGE_ID_UNKNOWN_55);
        AddPage(PAGE_ID_LOW_BATTERY_NOTIFICATION);
        AddPage(PAGE_ID_TITLE);
        AddPage(PAGE_ID_UNKNOWN_58);
        AddPage(PAGE_ID_OPENING_MOVIE);
        AddPage(PAGE_ID_TOP_MENU);
        AddPage(PAGE_ID_MENU_OVERLAY);
        AddPage(PAGE_ID_LICENSE_SELECT);
        break;

    case SECTION_ID_DEMO:
        AddPage(PAGE_ID_UNKNOWN_3A);
        AddPage(PAGE_ID_UNKNOWN_5F);
        break;

    case SECTION_ID_MII_SELECT1:
        AddPage(PAGE_ID_MENU_MESSAGE);
        AddPage(PAGE_ID_CONFIRM);
        AddPage(PAGE_ID_UNKNOWN_5D);
        AddPage(PAGE_ID_MENU_OVERLAY);
        AddPage(PAGE_ID_MII_SELECT);
        AddPage(PAGE_ID_MII_CHANGED);
        break;

    case SECTION_ID_MII_SELECT2:
        AddPage(PAGE_ID_MENU_MESSAGE);
        AddPage(PAGE_ID_CONFIRM);
        AddPage(PAGE_ID_UNKNOWN_5D);
        AddPage(PAGE_ID_MENU_OVERLAY);
        AddPage(PAGE_ID_MII_SELECT);
        AddPage(PAGE_ID_MII_CHANGED);
        break;

    case SECTION_ID_LICENSE_SETTINGS:
        AddPage(PAGE_ID_POPUP_YES_NO);
        AddPage(PAGE_ID_MENU_MESSAGE);
        AddPage(PAGE_ID_CONFIRM);
        AddPage(PAGE_ID_UNKNOWN_5D);
        AddPage(PAGE_ID_MENU_OVERLAY);
        AddPage(PAGE_ID_MII_SELECT);
        AddPage(PAGE_ID_MII_CHANGED);
        AddPage(PAGE_ID_LICENSE_SETTINGS_TOP);
        AddPage(PAGE_ID_ERASE_LICENSE);
        AddPage(PAGE_ID_LICENSE_RECORDS_OVERALL);
        AddPage(PAGE_ID_LICENSE_RECORDS_FAVORITES);
        AddPage(PAGE_ID_LICENSE_RECORDS_FRIENDS);
        AddPage(PAGE_ID_LICENSE_RECORDS_WFC);
        AddPage(PAGE_ID_LICENSE_RECORDS_OTHER);
        break;

    case SECTION_ID_SINGLE_PLAYER_FROM_MENU:
        AddPage(PAGE_ID_START_RACE_CONFIRM);
        AddPage(PAGE_ID_POPUP_MESSAGE);
        AddPage(PAGE_ID_READING_GHOST_DATA);
        AddPage(PAGE_ID_MENU_MESSAGE);
        AddPage(PAGE_ID_CONFIRM);
        AddPage(PAGE_ID_POST_TO_WII_MESSAGE_BOARD);
        AddPage(PAGE_ID_BACK_MODEL);
        AddPage(PAGE_ID_MENU_OVERLAY);
        AddPage(PAGE_ID_SINGLE_TOP);
        AddPage(PAGE_ID_GRAND_PRIX_CLASS_SELECT);
        AddPage(PAGE_ID_CHARACTER_SELECT);
        AddPage(PAGE_ID_VEHICLE_SELECT);
        AddPage(PAGE_ID_DRIFT_SELECT);
        AddPage(PAGE_ID_CUP_SELECT);
        AddPage(PAGE_ID_COURSE_SELECT);
        AddPage(PAGE_ID_TIME_ATTACK_TOP);
        AddPage(PAGE_ID_TIME_ATTACK_GHOST_LIST);
        AddPage(PAGE_ID_VS_SELECT);
        AddPage(PAGE_ID_VS_SETTING);
        AddPage(PAGE_ID_TEAM_CONFIRM);
        AddPage(PAGE_ID_BATTLE_MODE_SELECT);
        AddPage(PAGE_ID_BATTLE_VEHICLE_SELECT);
        AddPage(PAGE_ID_BATTLE_SETTING);
        AddPage(PAGE_ID_BATTLE_CUP_SELECT);
        AddPage(PAGE_ID_BATTLE_COURSE_SELECT);
        AddPage(PAGE_ID_MODEL_RENDER);
        AddPage(PAGE_ID_GHOST_MANAGER);
        break;

    case SECTION_ID_SINGLE_PLAYER_TA_CHANGE_CHARA:
        AddPage(PAGE_ID_START_RACE_CONFIRM);
        AddPage(PAGE_ID_POPUP_MESSAGE);
        AddPage(PAGE_ID_READING_GHOST_DATA);
        AddPage(PAGE_ID_MENU_MESSAGE);
        AddPage(PAGE_ID_CONFIRM);
        AddPage(PAGE_ID_POST_TO_WII_MESSAGE_BOARD);
        AddPage(PAGE_ID_BACK_MODEL);
        AddPage(PAGE_ID_MENU_OVERLAY);
        AddPage(PAGE_ID_SINGLE_TOP);
        AddPage(PAGE_ID_GRAND_PRIX_CLASS_SELECT);
        AddPage(PAGE_ID_CHARACTER_SELECT);
        AddPage(PAGE_ID_VEHICLE_SELECT);
        AddPage(PAGE_ID_DRIFT_SELECT);
        AddPage(PAGE_ID_CUP_SELECT);
        AddPage(PAGE_ID_COURSE_SELECT);
        AddPage(PAGE_ID_TIME_ATTACK_TOP);
        AddPage(PAGE_ID_TIME_ATTACK_GHOST_LIST);
        AddPage(PAGE_ID_VS_SELECT);
        AddPage(PAGE_ID_VS_SETTING);
        AddPage(PAGE_ID_TEAM_CONFIRM);
        AddPage(PAGE_ID_BATTLE_MODE_SELECT);
        AddPage(PAGE_ID_BATTLE_VEHICLE_SELECT);
        AddPage(PAGE_ID_BATTLE_SETTING);
        AddPage(PAGE_ID_BATTLE_CUP_SELECT);
        AddPage(PAGE_ID_BATTLE_COURSE_SELECT);
        AddPage(PAGE_ID_MODEL_RENDER);
        AddPage(PAGE_ID_GHOST_MANAGER);
        break;

    case SECTION_ID_SINGLE_PLAYER_TA_CHANGE_COURSE:
        AddPage(PAGE_ID_START_RACE_CONFIRM);
        AddPage(PAGE_ID_POPUP_MESSAGE);
        AddPage(PAGE_ID_READING_GHOST_DATA);
        AddPage(PAGE_ID_MENU_MESSAGE);
        AddPage(PAGE_ID_CONFIRM);
        AddPage(PAGE_ID_POST_TO_WII_MESSAGE_BOARD);
        AddPage(PAGE_ID_BACK_MODEL);
        AddPage(PAGE_ID_MENU_OVERLAY);
        AddPage(PAGE_ID_SINGLE_TOP);
        AddPage(PAGE_ID_GRAND_PRIX_CLASS_SELECT);
        AddPage(PAGE_ID_CHARACTER_SELECT);
        AddPage(PAGE_ID_VEHICLE_SELECT);
        AddPage(PAGE_ID_DRIFT_SELECT);
        AddPage(PAGE_ID_CUP_SELECT);
        AddPage(PAGE_ID_COURSE_SELECT);
        AddPage(PAGE_ID_TIME_ATTACK_TOP);
        AddPage(PAGE_ID_TIME_ATTACK_GHOST_LIST);
        AddPage(PAGE_ID_VS_SELECT);
        AddPage(PAGE_ID_VS_SETTING);
        AddPage(PAGE_ID_TEAM_CONFIRM);
        AddPage(PAGE_ID_BATTLE_MODE_SELECT);
        AddPage(PAGE_ID_BATTLE_VEHICLE_SELECT);
        AddPage(PAGE_ID_BATTLE_SETTING);
        AddPage(PAGE_ID_BATTLE_CUP_SELECT);
        AddPage(PAGE_ID_BATTLE_COURSE_SELECT);
        AddPage(PAGE_ID_MODEL_RENDER);
        AddPage(PAGE_ID_GHOST_MANAGER);
        break;

    case SECTION_ID_SINGLE_PLAYER_VS_NEXT_RACE:
        AddPage(PAGE_ID_START_RACE_CONFIRM);
        AddPage(PAGE_ID_POPUP_YES_NO);
        AddPage(PAGE_ID_MENU_MESSAGE);
        AddPage(PAGE_ID_CONFIRM);
        AddPage(PAGE_ID_POST_TO_WII_MESSAGE_BOARD);
        AddPage(PAGE_ID_BACK_MODEL);
        AddPage(PAGE_ID_MENU_OVERLAY);
        AddPage(PAGE_ID_CUP_SELECT);
        AddPage(PAGE_ID_COURSE_SELECT);
        AddPage(PAGE_ID_MODEL_RENDER);
        AddPage(PAGE_ID_GHOST_MANAGER);
        break;

    case SECTION_ID_SINGLE_PLAYER_BT_NEXT_BATTLE:
        AddPage(PAGE_ID_START_RACE_CONFIRM);
        AddPage(PAGE_ID_POPUP_YES_NO);
        AddPage(PAGE_ID_MENU_MESSAGE);
        AddPage(PAGE_ID_CONFIRM);
        AddPage(PAGE_ID_POST_TO_WII_MESSAGE_BOARD);
        AddPage(PAGE_ID_BACK_MODEL);
        AddPage(PAGE_ID_MENU_OVERLAY);
        AddPage(PAGE_ID_BATTLE_CUP_SELECT);
        AddPage(PAGE_ID_BATTLE_COURSE_SELECT);
        AddPage(PAGE_ID_MODEL_RENDER);
        AddPage(PAGE_ID_GHOST_MANAGER);
        break;

    case SECTION_ID_SINGLE_PLAYER_MR_CHOOSE_MISSION:
        AddPage(PAGE_ID_START_RACE_CONFIRM);
        AddPage(PAGE_ID_POPUP_MESSAGE);
        AddPage(PAGE_ID_READING_GHOST_DATA);
        AddPage(PAGE_ID_MENU_MESSAGE);
        AddPage(PAGE_ID_CONFIRM);
        AddPage(PAGE_ID_POST_TO_WII_MESSAGE_BOARD);
        AddPage(PAGE_ID_BACK_MODEL);
        AddPage(PAGE_ID_MENU_OVERLAY);
        AddPage(PAGE_ID_SINGLE_TOP);
        AddPage(PAGE_ID_GRAND_PRIX_CLASS_SELECT);
        AddPage(PAGE_ID_CHARACTER_SELECT);
        AddPage(PAGE_ID_VEHICLE_SELECT);
        AddPage(PAGE_ID_DRIFT_SELECT);
        AddPage(PAGE_ID_CUP_SELECT);
        AddPage(PAGE_ID_COURSE_SELECT);
        AddPage(PAGE_ID_TIME_ATTACK_TOP);
        AddPage(PAGE_ID_TIME_ATTACK_GHOST_LIST);
        AddPage(PAGE_ID_VS_SELECT);
        AddPage(PAGE_ID_VS_SETTING);
        AddPage(PAGE_ID_TEAM_CONFIRM);
        AddPage(PAGE_ID_BATTLE_MODE_SELECT);
        AddPage(PAGE_ID_BATTLE_VEHICLE_SELECT);
        AddPage(PAGE_ID_BATTLE_SETTING);
        AddPage(PAGE_ID_BATTLE_CUP_SELECT);
        AddPage(PAGE_ID_BATTLE_COURSE_SELECT);
        AddPage(PAGE_ID_MODEL_RENDER);
        AddPage(PAGE_ID_GHOST_MANAGER);
        break;

    case SECTION_ID_SINGLE_PLAYER_CHAN_RACE_GHOST:
        AddPage(PAGE_ID_START_RACE_CONFIRM);
        AddPage(PAGE_ID_POPUP_MESSAGE);
        AddPage(PAGE_ID_BACK_MODEL);
        AddPage(PAGE_ID_MENU_OVERLAY);
        AddPage(PAGE_ID_CHARACTER_SELECT);
        AddPage(PAGE_ID_VEHICLE_SELECT);
        AddPage(PAGE_ID_DRIFT_SELECT);
        AddPage(PAGE_ID_MODEL_RENDER);
        AddPage(PAGE_ID_GHOST_MANAGER);
        break;

    case SECTION_ID_SINGLE_PLAYER_LB_RACE_GHOST:
        AddPage(PAGE_ID_START_RACE_CONFIRM);
        AddPage(PAGE_ID_POPUP_MESSAGE);
        AddPage(PAGE_ID_BACK_MODEL);
        AddPage(PAGE_ID_MENU_OVERLAY);
        AddPage(PAGE_ID_CHARACTER_SELECT);
        AddPage(PAGE_ID_VEHICLE_SELECT);
        AddPage(PAGE_ID_DRIFT_SELECT);
        AddPage(PAGE_ID_MODEL_RENDER);
        AddPage(PAGE_ID_GHOST_MANAGER);
        break;

    case SECTION_ID_SINGLE_PLAYER_LIST_RACE_GHOST:
        AddPage(PAGE_ID_START_RACE_CONFIRM);
        AddPage(PAGE_ID_POPUP_MESSAGE);
        AddPage(PAGE_ID_BACK_MODEL);
        AddPage(PAGE_ID_MENU_OVERLAY);
        AddPage(PAGE_ID_CHARACTER_SELECT);
        AddPage(PAGE_ID_VEHICLE_SELECT);
        AddPage(PAGE_ID_DRIFT_SELECT);
        AddPage(PAGE_ID_MODEL_RENDER);
        AddPage(PAGE_ID_GHOST_MANAGER);
        break;

    case SECTION_ID_SEND_GHOST_TO_FRIEND:
        AddPage(PAGE_ID_READING_GHOST_DATA);
        AddPage(PAGE_ID_MENU_MESSAGE);
        AddPage(PAGE_ID_BACK_MODEL);
        AddPage(PAGE_ID_MENU_OVERLAY);
        AddPage(PAGE_ID_GHOST_MANAGER);
        AddPage(PAGE_ID_UNKNOWN_B6);
        break;

    case SECTION_ID_RACE_GHOST_FROM_CHAN_BOOT:
        AddPage(PAGE_ID_READING_GHOST_DATA);
        AddPage(PAGE_ID_BACK_MODEL);
        AddPage(PAGE_ID_MENU_OVERLAY);
        AddPage(PAGE_ID_GHOST_MANAGER);
        AddPage(PAGE_ID_UNKNOWN_B1);
        AddPage(PAGE_ID_UNKNOWN_B2);
        break;

    case SECTION_ID_WATCH_REPLAY_FROM_CHAN_BOOT:
        AddPage(PAGE_ID_READING_GHOST_DATA);
        AddPage(PAGE_ID_BACK_MODEL);
        AddPage(PAGE_ID_MENU_OVERLAY);
        AddPage(PAGE_ID_GHOST_MANAGER);
        AddPage(PAGE_ID_UNKNOWN_B1);
        AddPage(PAGE_ID_UNKNOWN_B2);
        break;

    case SECTION_ID_LOCAL_MULTIPLAYER:
        AddPage(PAGE_ID_START_RACE_CONFIRM);
        AddPage(PAGE_ID_POPUP_WAITING);
        AddPage(PAGE_ID_POPUP_MESSAGE);
        AddPage(PAGE_ID_CONFIRM);
        AddPage(PAGE_ID_BACK_MODEL);
        AddPage(PAGE_ID_MENU_OVERLAY);
        AddPage(PAGE_ID_MII_SELECT);
        AddPage(PAGE_ID_MULTI_PAD_REGISTER);
        AddPage(PAGE_ID_CONTROLLER_OPT_IN);
        AddPage(PAGE_ID_PAIR_WII_REMOTES);
        AddPage(PAGE_ID_CONTROLLER_OPT_IN_COMPLETE);
        AddPage(PAGE_ID_CHARACTER_SELECT);
        AddPage(PAGE_ID_CUP_SELECT);
        AddPage(PAGE_ID_COURSE_SELECT);
        AddPage(PAGE_ID_VS_SELECT);
        AddPage(PAGE_ID_VS_SETTING);
        AddPage(PAGE_ID_TEAM_CONFIRM);
        AddPage(PAGE_ID_BATTLE_MODE_SELECT);
        AddPage(PAGE_ID_BATTLE_SETTING);
        AddPage(PAGE_ID_BATTLE_CUP_SELECT);
        AddPage(PAGE_ID_BATTLE_COURSE_SELECT);
        AddPage(PAGE_ID_MODEL_RENDER);
        AddPage(PAGE_ID_MULTI_TOP);
        AddPage(PAGE_ID_MULTI_VEHICLE_SELECT);
        AddPage(PAGE_ID_MULTI_DRIFT_SELECT);
        AddPage(PAGE_ID_MULTI_TEAM_SELECT);
        break;

    case SECTION_ID_WIFI_1P:
        AddPage(PAGE_ID_POPUP_WAITING);
        AddPage(PAGE_ID_POPUP_MESSAGE);
        AddPage(PAGE_ID_POPUP_YES_NO);
        AddPage(PAGE_ID_READING_GHOST_DATA);
        AddPage(PAGE_ID_WIFI_CONNECTING);
        AddPage(PAGE_ID_MENU_MESSAGE);
        AddPage(PAGE_ID_CONFIRM);
        AddPage(PAGE_ID_MENU_OVERLAY);
        AddPage(PAGE_ID_CHARACTER_SELECT);
        AddPage(PAGE_ID_VEHICLE_SELECT);
        AddPage(PAGE_ID_DRIFT_SELECT);
        AddPage(PAGE_ID_BATTLE_VEHICLE_SELECT);
        AddPage(PAGE_ID_MODEL_RENDER);
        AddPage(PAGE_ID_UNKNOWN_84);
        AddPage(PAGE_ID_WIFI_FIRST_PLAY);
        AddPage(PAGE_ID_WIFI_DATA_SHARING_PROMPT);
        AddPage(PAGE_ID_UNKNOWN_87);
        AddPage(PAGE_ID_UNKNOWN_88);
        AddPage(PAGE_ID_WIFI_CONNECT_ERROR);
        AddPage(PAGE_ID_WIFI_MENU_TOP);
        AddPage(PAGE_ID_WIFI_MODE_SELECT);
        AddPage(PAGE_ID_WIFI_FRIENDS_MENU);
        AddPage(PAGE_ID_WIFI_SEARCH_MANAGER);
        AddPage(PAGE_ID_WIFI_GLOBE_MODEL);
        AddPage(PAGE_ID_WIFI_FRIEND_ROSTER);
        AddPage(PAGE_ID_WIFI_NOT_FRIENDS_YET);
        AddPage(PAGE_ID_WIFI_REMOVE_FRIEND_CODE_PROMPT);
        AddPage(PAGE_ID_WIFI_REMOVING_FRIEND_CODE);
        AddPage(PAGE_ID_WIFI_FRIEND_ROOM_WAITING_TEXT);
        AddPage(PAGE_ID_WIFI_FRIEND_ROOM_MANAGER);
        AddPage(PAGE_ID_WIFI_FRIEND_ROOM);
        AddPage(PAGE_ID_WIFI_FRIEND_ROOM_MESSAGE_SELECT);
        AddPage(PAGE_ID_UNKNOWN_A5);
        AddPage(PAGE_ID_ENTER_FRIEND_CODE);
        AddPage(PAGE_ID_GHOST_MANAGER);
        break;

    case SECTION_ID_WIFI_1P_GLOBE_DISCONNECT:
        AddPage(PAGE_ID_POPUP_WAITING);
        AddPage(PAGE_ID_POPUP_MESSAGE);
        AddPage(PAGE_ID_POPUP_YES_NO);
        AddPage(PAGE_ID_READING_GHOST_DATA);
        AddPage(PAGE_ID_WIFI_CONNECTING);
        AddPage(PAGE_ID_MENU_MESSAGE);
        AddPage(PAGE_ID_CONFIRM);
        AddPage(PAGE_ID_MENU_OVERLAY);
        AddPage(PAGE_ID_CHARACTER_SELECT);
        AddPage(PAGE_ID_VEHICLE_SELECT);
        AddPage(PAGE_ID_DRIFT_SELECT);
        AddPage(PAGE_ID_BATTLE_VEHICLE_SELECT);
        AddPage(PAGE_ID_MODEL_RENDER);
        AddPage(PAGE_ID_UNKNOWN_84);
        AddPage(PAGE_ID_WIFI_FIRST_PLAY);
        AddPage(PAGE_ID_WIFI_DATA_SHARING_PROMPT);
        AddPage(PAGE_ID_UNKNOWN_87);
        AddPage(PAGE_ID_UNKNOWN_88);
        AddPage(PAGE_ID_WIFI_CONNECT_ERROR);
        AddPage(PAGE_ID_WIFI_MENU_TOP);
        AddPage(PAGE_ID_WIFI_MODE_SELECT);
        AddPage(PAGE_ID_WIFI_FRIENDS_MENU);
        AddPage(PAGE_ID_WIFI_SEARCH_MANAGER);
        AddPage(PAGE_ID_WIFI_GLOBE_MODEL);
        AddPage(PAGE_ID_WIFI_FRIEND_ROSTER);
        AddPage(PAGE_ID_WIFI_NOT_FRIENDS_YET);
        AddPage(PAGE_ID_WIFI_REMOVE_FRIEND_CODE_PROMPT);
        AddPage(PAGE_ID_WIFI_REMOVING_FRIEND_CODE);
        AddPage(PAGE_ID_WIFI_FRIEND_ROOM_WAITING_TEXT);
        AddPage(PAGE_ID_WIFI_FRIEND_ROOM_MANAGER);
        AddPage(PAGE_ID_WIFI_FRIEND_ROOM);
        AddPage(PAGE_ID_WIFI_FRIEND_ROOM_MESSAGE_SELECT);
        AddPage(PAGE_ID_UNKNOWN_A5);
        AddPage(PAGE_ID_ENTER_FRIEND_CODE);
        AddPage(PAGE_ID_GHOST_MANAGER);
        break;

    case SECTION_ID_WIFI_1P_FROM_FIND_FRIEND:
        AddPage(PAGE_ID_POPUP_WAITING);
        AddPage(PAGE_ID_POPUP_MESSAGE);
        AddPage(PAGE_ID_POPUP_YES_NO);
        AddPage(PAGE_ID_READING_GHOST_DATA);
        AddPage(PAGE_ID_WIFI_CONNECTING);
        AddPage(PAGE_ID_MENU_MESSAGE);
        AddPage(PAGE_ID_CONFIRM);
        AddPage(PAGE_ID_MENU_OVERLAY);
        AddPage(PAGE_ID_CHARACTER_SELECT);
        AddPage(PAGE_ID_VEHICLE_SELECT);
        AddPage(PAGE_ID_DRIFT_SELECT);
        AddPage(PAGE_ID_BATTLE_VEHICLE_SELECT);
        AddPage(PAGE_ID_MODEL_RENDER);
        AddPage(PAGE_ID_UNKNOWN_84);
        AddPage(PAGE_ID_WIFI_FIRST_PLAY);
        AddPage(PAGE_ID_WIFI_DATA_SHARING_PROMPT);
        AddPage(PAGE_ID_UNKNOWN_87);
        AddPage(PAGE_ID_UNKNOWN_88);
        AddPage(PAGE_ID_WIFI_CONNECT_ERROR);
        AddPage(PAGE_ID_WIFI_MENU_TOP);
        AddPage(PAGE_ID_WIFI_MODE_SELECT);
        AddPage(PAGE_ID_WIFI_FRIENDS_MENU);
        AddPage(PAGE_ID_WIFI_SEARCH_MANAGER);
        AddPage(PAGE_ID_WIFI_GLOBE_MODEL);
        AddPage(PAGE_ID_WIFI_FRIEND_ROSTER);
        AddPage(PAGE_ID_WIFI_NOT_FRIENDS_YET);
        AddPage(PAGE_ID_WIFI_REMOVE_FRIEND_CODE_PROMPT);
        AddPage(PAGE_ID_WIFI_REMOVING_FRIEND_CODE);
        AddPage(PAGE_ID_WIFI_FRIEND_ROOM_WAITING_TEXT);
        AddPage(PAGE_ID_WIFI_FRIEND_ROOM_MANAGER);
        AddPage(PAGE_ID_WIFI_FRIEND_ROOM);
        AddPage(PAGE_ID_WIFI_FRIEND_ROOM_MESSAGE_SELECT);
        AddPage(PAGE_ID_UNKNOWN_A5);
        AddPage(PAGE_ID_ENTER_FRIEND_CODE);
        AddPage(PAGE_ID_GHOST_MANAGER);
        break;

    case SECTION_ID_WIFI_1P_VS_VOTING:
        AddPage(PAGE_ID_POPUP_YES_NO);
        AddPage(PAGE_ID_WIFI_CONNECTING);
        AddPage(PAGE_ID_MENU_MESSAGE);
        AddPage(PAGE_ID_BACK_MODEL);
        AddPage(PAGE_ID_MENU_OVERLAY);
        AddPage(PAGE_ID_CUP_SELECT);
        AddPage(PAGE_ID_COURSE_SELECT);
        AddPage(PAGE_ID_MODEL_RENDER);
        AddPage(PAGE_ID_UNKNOWN_88);
        AddPage(PAGE_ID_WIFI_TIMER);
        AddPage(PAGE_ID_WIFI_PLAYER_LIST);
        AddPage(PAGE_ID_WIFI_ROULETTE);
        break;

    case SECTION_ID_WIFI_1P_BATTLE_VOTING:
        AddPage(PAGE_ID_POPUP_YES_NO);
        AddPage(PAGE_ID_WIFI_CONNECTING);
        AddPage(PAGE_ID_MENU_MESSAGE);
        AddPage(PAGE_ID_BACK_MODEL);
        AddPage(PAGE_ID_MENU_OVERLAY);
        AddPage(PAGE_ID_BATTLE_CUP_SELECT);
        AddPage(PAGE_ID_BATTLE_COURSE_SELECT);
        AddPage(PAGE_ID_MODEL_RENDER);
        AddPage(PAGE_ID_UNKNOWN_88);
        AddPage(PAGE_ID_WIFI_TIMER);
        AddPage(PAGE_ID_WIFI_PLAYER_LIST);
        AddPage(PAGE_ID_WIFI_ROULETTE);
        break;

    case SECTION_ID_WIFI_2P_SELECT_MII:
        AddPage(PAGE_ID_CONFIRM);
        AddPage(PAGE_ID_MENU_OVERLAY);
        AddPage(PAGE_ID_MII_SELECT);
        AddPage(PAGE_ID_MULTI_PAD_REGISTER);
        AddPage(PAGE_ID_CONTROLLER_OPT_IN);
        AddPage(PAGE_ID_PAIR_WII_REMOTES);
        AddPage(PAGE_ID_CONTROLLER_OPT_IN_COMPLETE);
        AddPage(PAGE_ID_UNKNOWN_8A);
        break;

    case SECTION_ID_WIFI_2P:
        AddPage(PAGE_ID_POPUP_WAITING);
        AddPage(PAGE_ID_POPUP_MESSAGE);
        AddPage(PAGE_ID_POPUP_YES_NO);
        AddPage(PAGE_ID_READING_GHOST_DATA);
        AddPage(PAGE_ID_WIFI_CONNECTING);
        AddPage(PAGE_ID_MENU_MESSAGE);
        AddPage(PAGE_ID_CONFIRM);
        AddPage(PAGE_ID_MENU_OVERLAY);
        AddPage(PAGE_ID_CHARACTER_SELECT);
        AddPage(PAGE_ID_BATTLE_VEHICLE_SELECT);
        AddPage(PAGE_ID_MODEL_RENDER);
        AddPage(PAGE_ID_MULTI_VEHICLE_SELECT);
        AddPage(PAGE_ID_MULTI_DRIFT_SELECT);
        AddPage(PAGE_ID_UNKNOWN_84);
        AddPage(PAGE_ID_WIFI_FIRST_PLAY);
        AddPage(PAGE_ID_WIFI_DATA_SHARING_PROMPT);
        AddPage(PAGE_ID_UNKNOWN_87);
        AddPage(PAGE_ID_UNKNOWN_88);
        AddPage(PAGE_ID_WIFI_CONNECT_ERROR);
        AddPage(PAGE_ID_WIFI_MENU_TOP);
        AddPage(PAGE_ID_WIFI_MODE_SELECT);
        AddPage(PAGE_ID_WIFI_FRIENDS_MENU);
        AddPage(PAGE_ID_WIFI_SEARCH_MANAGER);
        AddPage(PAGE_ID_WIFI_GLOBE_MODEL);
        AddPage(PAGE_ID_WIFI_FRIEND_ROSTER);
        AddPage(PAGE_ID_WIFI_NOT_FRIENDS_YET);
        AddPage(PAGE_ID_WIFI_REMOVE_FRIEND_CODE_PROMPT);
        AddPage(PAGE_ID_WIFI_REMOVING_FRIEND_CODE);
        AddPage(PAGE_ID_WIFI_FRIEND_ROOM_WAITING_TEXT);
        AddPage(PAGE_ID_WIFI_FRIEND_ROOM_MANAGER);
        AddPage(PAGE_ID_WIFI_FRIEND_ROOM);
        AddPage(PAGE_ID_WIFI_FRIEND_ROOM_MESSAGE_SELECT);
        AddPage(PAGE_ID_UNKNOWN_A5);
        AddPage(PAGE_ID_ENTER_FRIEND_CODE);
        AddPage(PAGE_ID_GHOST_MANAGER);
        break;

    case SECTION_ID_WIFI_2P_GLOBE_DISCONNECT:
        AddPage(PAGE_ID_POPUP_WAITING);
        AddPage(PAGE_ID_POPUP_MESSAGE);
        AddPage(PAGE_ID_POPUP_YES_NO);
        AddPage(PAGE_ID_READING_GHOST_DATA);
        AddPage(PAGE_ID_WIFI_CONNECTING);
        AddPage(PAGE_ID_MENU_MESSAGE);
        AddPage(PAGE_ID_CONFIRM);
        AddPage(PAGE_ID_MENU_OVERLAY);
        AddPage(PAGE_ID_CHARACTER_SELECT);
        AddPage(PAGE_ID_BATTLE_VEHICLE_SELECT);
        AddPage(PAGE_ID_MODEL_RENDER);
        AddPage(PAGE_ID_MULTI_VEHICLE_SELECT);
        AddPage(PAGE_ID_MULTI_DRIFT_SELECT);
        AddPage(PAGE_ID_UNKNOWN_84);
        AddPage(PAGE_ID_WIFI_FIRST_PLAY);
        AddPage(PAGE_ID_WIFI_DATA_SHARING_PROMPT);
        AddPage(PAGE_ID_UNKNOWN_87);
        AddPage(PAGE_ID_UNKNOWN_88);
        AddPage(PAGE_ID_WIFI_CONNECT_ERROR);
        AddPage(PAGE_ID_WIFI_MENU_TOP);
        AddPage(PAGE_ID_WIFI_MODE_SELECT);
        AddPage(PAGE_ID_WIFI_FRIENDS_MENU);
        AddPage(PAGE_ID_WIFI_SEARCH_MANAGER);
        AddPage(PAGE_ID_WIFI_GLOBE_MODEL);
        AddPage(PAGE_ID_WIFI_FRIEND_ROSTER);
        AddPage(PAGE_ID_WIFI_NOT_FRIENDS_YET);
        AddPage(PAGE_ID_WIFI_REMOVE_FRIEND_CODE_PROMPT);
        AddPage(PAGE_ID_WIFI_REMOVING_FRIEND_CODE);
        AddPage(PAGE_ID_WIFI_FRIEND_ROOM_WAITING_TEXT);
        AddPage(PAGE_ID_WIFI_FRIEND_ROOM_MANAGER);
        AddPage(PAGE_ID_WIFI_FRIEND_ROOM);
        AddPage(PAGE_ID_WIFI_FRIEND_ROOM_MESSAGE_SELECT);
        AddPage(PAGE_ID_UNKNOWN_A5);
        AddPage(PAGE_ID_ENTER_FRIEND_CODE);
        AddPage(PAGE_ID_GHOST_MANAGER);
        break;

    case SECTION_ID_UNKNOWN_5D:
        AddPage(PAGE_ID_POPUP_WAITING);
        AddPage(PAGE_ID_POPUP_MESSAGE);
        AddPage(PAGE_ID_POPUP_YES_NO);
        AddPage(PAGE_ID_READING_GHOST_DATA);
        AddPage(PAGE_ID_WIFI_CONNECTING);
        AddPage(PAGE_ID_MENU_MESSAGE);
        AddPage(PAGE_ID_CONFIRM);
        AddPage(PAGE_ID_MENU_OVERLAY);
        AddPage(PAGE_ID_CHARACTER_SELECT);
        AddPage(PAGE_ID_BATTLE_VEHICLE_SELECT);
        AddPage(PAGE_ID_MODEL_RENDER);
        AddPage(PAGE_ID_MULTI_VEHICLE_SELECT);
        AddPage(PAGE_ID_MULTI_DRIFT_SELECT);
        AddPage(PAGE_ID_UNKNOWN_84);
        AddPage(PAGE_ID_WIFI_FIRST_PLAY);
        AddPage(PAGE_ID_WIFI_DATA_SHARING_PROMPT);
        AddPage(PAGE_ID_UNKNOWN_87);
        AddPage(PAGE_ID_UNKNOWN_88);
        AddPage(PAGE_ID_WIFI_CONNECT_ERROR);
        AddPage(PAGE_ID_WIFI_MENU_TOP);
        AddPage(PAGE_ID_WIFI_MODE_SELECT);
        AddPage(PAGE_ID_WIFI_FRIENDS_MENU);
        AddPage(PAGE_ID_WIFI_SEARCH_MANAGER);
        AddPage(PAGE_ID_WIFI_GLOBE_MODEL);
        AddPage(PAGE_ID_WIFI_FRIEND_ROSTER);
        AddPage(PAGE_ID_WIFI_NOT_FRIENDS_YET);
        AddPage(PAGE_ID_WIFI_REMOVE_FRIEND_CODE_PROMPT);
        AddPage(PAGE_ID_WIFI_REMOVING_FRIEND_CODE);
        AddPage(PAGE_ID_WIFI_FRIEND_ROOM_WAITING_TEXT);
        AddPage(PAGE_ID_WIFI_FRIEND_ROOM_MANAGER);
        AddPage(PAGE_ID_WIFI_FRIEND_ROOM);
        AddPage(PAGE_ID_WIFI_FRIEND_ROOM_MESSAGE_SELECT);
        AddPage(PAGE_ID_UNKNOWN_A5);
        AddPage(PAGE_ID_ENTER_FRIEND_CODE);
        AddPage(PAGE_ID_GHOST_MANAGER);
        break;

    case SECTION_ID_WIFI_2P_VS_VOTING:
        AddPage(PAGE_ID_POPUP_YES_NO);
        AddPage(PAGE_ID_WIFI_CONNECTING);
        AddPage(PAGE_ID_MENU_MESSAGE);
        AddPage(PAGE_ID_BACK_MODEL);
        AddPage(PAGE_ID_MENU_OVERLAY);
        AddPage(PAGE_ID_CUP_SELECT);
        AddPage(PAGE_ID_COURSE_SELECT);
        AddPage(PAGE_ID_MODEL_RENDER);
        AddPage(PAGE_ID_UNKNOWN_88);
        AddPage(PAGE_ID_WIFI_TIMER);
        AddPage(PAGE_ID_WIFI_PLAYER_LIST);
        AddPage(PAGE_ID_WIFI_ROULETTE);
        break;

    case SECTION_ID_WIFI_2P_BATTLE_VOTING:
        AddPage(PAGE_ID_POPUP_YES_NO);
        AddPage(PAGE_ID_WIFI_CONNECTING);
        AddPage(PAGE_ID_MENU_MESSAGE);
        AddPage(PAGE_ID_BACK_MODEL);
        AddPage(PAGE_ID_MENU_OVERLAY);
        AddPage(PAGE_ID_BATTLE_CUP_SELECT);
        AddPage(PAGE_ID_BATTLE_COURSE_SELECT);
        AddPage(PAGE_ID_MODEL_RENDER);
        AddPage(PAGE_ID_UNKNOWN_88);
        AddPage(PAGE_ID_WIFI_TIMER);
        AddPage(PAGE_ID_WIFI_PLAYER_LIST);
        AddPage(PAGE_ID_WIFI_ROULETTE);
        break;

    case SECTION_ID_WIFI_1P_FRIEND_ROOM_VS_VOTING:
        AddPage(PAGE_ID_POPUP_YES_NO);
        AddPage(PAGE_ID_WIFI_CONNECTING);
        AddPage(PAGE_ID_MENU_MESSAGE);
        AddPage(PAGE_ID_BACK_MODEL);
        AddPage(PAGE_ID_MENU_OVERLAY);
        AddPage(PAGE_ID_CUP_SELECT);
        AddPage(PAGE_ID_COURSE_SELECT);
        AddPage(PAGE_ID_MODEL_RENDER);
        AddPage(PAGE_ID_UNKNOWN_88);
        AddPage(PAGE_ID_WIFI_TIMER);
        AddPage(PAGE_ID_WIFI_PLAYER_LIST);
        AddPage(PAGE_ID_WIFI_ROULETTE);
        break;

    case SECTION_ID_WIFI_1P_FRIEND_ROOM_TEAM_VS_VOTING:
        AddPage(PAGE_ID_POPUP_YES_NO);
        AddPage(PAGE_ID_WIFI_CONNECTING);
        AddPage(PAGE_ID_MENU_MESSAGE);
        AddPage(PAGE_ID_BACK_MODEL);
        AddPage(PAGE_ID_MENU_OVERLAY);
        AddPage(PAGE_ID_CUP_SELECT);
        AddPage(PAGE_ID_COURSE_SELECT);
        AddPage(PAGE_ID_MODEL_RENDER);
        AddPage(PAGE_ID_UNKNOWN_88);
        AddPage(PAGE_ID_WIFI_TIMER);
        AddPage(PAGE_ID_WIFI_PLAYER_LIST);
        AddPage(PAGE_ID_WIFI_ROULETTE);
        break;

    case SECTION_ID_WIFI_1P_FRIEND_ROOM_BALLOON_VOTING:
        AddPage(PAGE_ID_POPUP_YES_NO);
        AddPage(PAGE_ID_WIFI_CONNECTING);
        AddPage(PAGE_ID_MENU_MESSAGE);
        AddPage(PAGE_ID_BACK_MODEL);
        AddPage(PAGE_ID_MENU_OVERLAY);
        AddPage(PAGE_ID_BATTLE_CUP_SELECT);
        AddPage(PAGE_ID_BATTLE_COURSE_SELECT);
        AddPage(PAGE_ID_MODEL_RENDER);
        AddPage(PAGE_ID_UNKNOWN_88);
        AddPage(PAGE_ID_WIFI_TIMER);
        AddPage(PAGE_ID_WIFI_PLAYER_LIST);
        AddPage(PAGE_ID_WIFI_ROULETTE);
        break;

    case SECTION_ID_WIFI_1P_FRIEND_ROOM_COIN_VOTING:
        AddPage(PAGE_ID_POPUP_YES_NO);
        AddPage(PAGE_ID_WIFI_CONNECTING);
        AddPage(PAGE_ID_MENU_MESSAGE);
        AddPage(PAGE_ID_BACK_MODEL);
        AddPage(PAGE_ID_MENU_OVERLAY);
        AddPage(PAGE_ID_BATTLE_CUP_SELECT);
        AddPage(PAGE_ID_BATTLE_COURSE_SELECT);
        AddPage(PAGE_ID_MODEL_RENDER);
        AddPage(PAGE_ID_UNKNOWN_88);
        AddPage(PAGE_ID_WIFI_TIMER);
        AddPage(PAGE_ID_WIFI_PLAYER_LIST);
        AddPage(PAGE_ID_WIFI_ROULETTE);
        break;

    case SECTION_ID_WIFI_2P_FRIEND_ROOM_VS_VOTING:
        AddPage(PAGE_ID_POPUP_YES_NO);
        AddPage(PAGE_ID_WIFI_CONNECTING);
        AddPage(PAGE_ID_MENU_MESSAGE);
        AddPage(PAGE_ID_BACK_MODEL);
        AddPage(PAGE_ID_MENU_OVERLAY);
        AddPage(PAGE_ID_CUP_SELECT);
        AddPage(PAGE_ID_COURSE_SELECT);
        AddPage(PAGE_ID_MODEL_RENDER);
        AddPage(PAGE_ID_UNKNOWN_88);
        AddPage(PAGE_ID_WIFI_TIMER);
        AddPage(PAGE_ID_WIFI_PLAYER_LIST);
        AddPage(PAGE_ID_WIFI_ROULETTE);
        break;

    case SECTION_ID_WIFI_2P_FRIEND_ROOM_TEAM_VS_VOTING:
        AddPage(PAGE_ID_POPUP_YES_NO);
        AddPage(PAGE_ID_WIFI_CONNECTING);
        AddPage(PAGE_ID_MENU_MESSAGE);
        AddPage(PAGE_ID_BACK_MODEL);
        AddPage(PAGE_ID_MENU_OVERLAY);
        AddPage(PAGE_ID_CUP_SELECT);
        AddPage(PAGE_ID_COURSE_SELECT);
        AddPage(PAGE_ID_MODEL_RENDER);
        AddPage(PAGE_ID_UNKNOWN_88);
        AddPage(PAGE_ID_WIFI_TIMER);
        AddPage(PAGE_ID_WIFI_PLAYER_LIST);
        AddPage(PAGE_ID_WIFI_ROULETTE);
        break;

    case SECTION_ID_WIFI_2P_FRIEND_ROOM_BALLOON_VOTING:
        AddPage(PAGE_ID_POPUP_YES_NO);
        AddPage(PAGE_ID_WIFI_CONNECTING);
        AddPage(PAGE_ID_MENU_MESSAGE);
        AddPage(PAGE_ID_BACK_MODEL);
        AddPage(PAGE_ID_MENU_OVERLAY);
        AddPage(PAGE_ID_BATTLE_CUP_SELECT);
        AddPage(PAGE_ID_BATTLE_COURSE_SELECT);
        AddPage(PAGE_ID_MODEL_RENDER);
        AddPage(PAGE_ID_UNKNOWN_88);
        AddPage(PAGE_ID_WIFI_TIMER);
        AddPage(PAGE_ID_WIFI_PLAYER_LIST);
        AddPage(PAGE_ID_WIFI_ROULETTE);
        break;

    case SECTION_ID_WIFI_2P_FRIEND_ROOM_COIN_VOTING:
        AddPage(PAGE_ID_POPUP_YES_NO);
        AddPage(PAGE_ID_WIFI_CONNECTING);
        AddPage(PAGE_ID_MENU_MESSAGE);
        AddPage(PAGE_ID_BACK_MODEL);
        AddPage(PAGE_ID_MENU_OVERLAY);
        AddPage(PAGE_ID_BATTLE_CUP_SELECT);
        AddPage(PAGE_ID_BATTLE_COURSE_SELECT);
        AddPage(PAGE_ID_MODEL_RENDER);
        AddPage(PAGE_ID_UNKNOWN_88);
        AddPage(PAGE_ID_WIFI_TIMER);
        AddPage(PAGE_ID_WIFI_PLAYER_LIST);
        AddPage(PAGE_ID_WIFI_ROULETTE);
        break;

    case SECTION_ID_WIFI_1P_RACE_VS:
        AddPage(PAGE_ID_RESULT_ONLINE_RACE_UPDATE);
        AddPage(PAGE_ID_UNKNOWN_3A);
        AddPage(PAGE_ID_WIFI_RACE_1P);
        AddPage(PAGE_ID_UNKNOWN_45);
        AddPage(PAGE_ID_AFTER_WIFI_RACE);
        AddPage(PAGE_ID_CONFIRM_QUIT_WIFI_RACE);
        AddPage(PAGE_ID_WIFI_PLEASE_WAIT);
        AddPage(PAGE_ID_MENU_MESSAGE);
        AddPage(PAGE_ID_UNKNOWN_88);
        AddPage(PAGE_ID_UNKNOWN_94);
        break;

    case SECTION_ID_WIFI_2P_RACE_VS:
        AddPage(PAGE_ID_RESULT_ONLINE_RACE_UPDATE);
        AddPage(PAGE_ID_UNKNOWN_3A);
        AddPage(PAGE_ID_WIFI_RACE_2P);
        AddPage(PAGE_ID_UNKNOWN_45);
        AddPage(PAGE_ID_AFTER_WIFI_RACE);
        AddPage(PAGE_ID_CONFIRM_QUIT_WIFI_RACE);
        AddPage(PAGE_ID_WIFI_PLEASE_WAIT);
        AddPage(PAGE_ID_MENU_MESSAGE);
        AddPage(PAGE_ID_UNKNOWN_88);
        AddPage(PAGE_ID_UNKNOWN_94);
        break;

    case SECTION_ID_WIFI_1P_VS_LIVE_VIEW:
        AddPage(PAGE_ID_UNKNOWN_3A);
        AddPage(PAGE_ID_WIFI_PLEASE_WAIT);
        AddPage(PAGE_ID_LIVE_VIEW_VS);
        AddPage(PAGE_ID_MENU_MESSAGE);
        AddPage(PAGE_ID_UNKNOWN_88);
        AddPage(PAGE_ID_UNKNOWN_93);
        AddPage(PAGE_ID_UNKNOWN_94);
        break;

    case SECTION_ID_WIFI_2P_VS_LIVE_VIEW:
        AddPage(PAGE_ID_UNKNOWN_3A);
        AddPage(PAGE_ID_WIFI_PLEASE_WAIT);
        AddPage(PAGE_ID_LIVE_VIEW_VS);
        AddPage(PAGE_ID_MENU_MESSAGE);
        AddPage(PAGE_ID_UNKNOWN_88);
        AddPage(PAGE_ID_UNKNOWN_93);
        AddPage(PAGE_ID_UNKNOWN_94);
        break;

    case SECTION_ID_WIFI_1P_BT_GAMEPLAY:
        AddPage(PAGE_ID_BATTLE_1P);
        AddPage(PAGE_ID_RESULT_ONLINE_RACE_UPDATE);
        AddPage(PAGE_ID_RESULT_BATTLE_UPDATE);
        AddPage(PAGE_ID_UNKNOWN_3A);
        AddPage(PAGE_ID_UNKNOWN_45);
        AddPage(PAGE_ID_AFTER_WIFI_RACE);
        AddPage(PAGE_ID_CONFIRM_QUIT_WIFI_RACE);
        AddPage(PAGE_ID_WIFI_PLEASE_WAIT);
        AddPage(PAGE_ID_MENU_MESSAGE);
        AddPage(PAGE_ID_UNKNOWN_88);
        AddPage(PAGE_ID_UNKNOWN_94);
        break;

    case SECTION_ID_WIFI_2P_BT_GAMEPLAY:
        AddPage(PAGE_ID_BATTLE_2P);
        AddPage(PAGE_ID_RESULT_ONLINE_RACE_UPDATE);
        AddPage(PAGE_ID_RESULT_BATTLE_UPDATE);
        AddPage(PAGE_ID_UNKNOWN_3A);
        AddPage(PAGE_ID_UNKNOWN_45);
        AddPage(PAGE_ID_AFTER_WIFI_RACE);
        AddPage(PAGE_ID_CONFIRM_QUIT_WIFI_RACE);
        AddPage(PAGE_ID_WIFI_PLEASE_WAIT);
        AddPage(PAGE_ID_MENU_MESSAGE);
        AddPage(PAGE_ID_UNKNOWN_88);
        AddPage(PAGE_ID_UNKNOWN_94);
        break;

    case SECTION_ID_WIFI_1P_BT_LIVE_VIEW:
        AddPage(PAGE_ID_RESULT_BATTLE_UPDATE);
        AddPage(PAGE_ID_UNKNOWN_3A);
        AddPage(PAGE_ID_WIFI_PLEASE_WAIT);
        AddPage(PAGE_ID_LIVE_VIEW_BATTLE);
        AddPage(PAGE_ID_MENU_MESSAGE);
        AddPage(PAGE_ID_UNKNOWN_88);
        AddPage(PAGE_ID_UNKNOWN_93);
        AddPage(PAGE_ID_UNKNOWN_94);
        break;

    case SECTION_ID_WIFI_2P_BT_LIVE_VIEW:
        AddPage(PAGE_ID_RESULT_BATTLE_UPDATE);
        AddPage(PAGE_ID_UNKNOWN_3A);
        AddPage(PAGE_ID_WIFI_PLEASE_WAIT);
        AddPage(PAGE_ID_LIVE_VIEW_BATTLE);
        AddPage(PAGE_ID_MENU_MESSAGE);
        AddPage(PAGE_ID_UNKNOWN_88);
        AddPage(PAGE_ID_UNKNOWN_93);
        AddPage(PAGE_ID_UNKNOWN_94);
        break;

    case SECTION_ID_WIFI_1P_FRIEND_RACE_VS:
        AddPage(PAGE_ID_RESULT_RACE_UPDATE);
        AddPage(PAGE_ID_RESULT_RACE_TOTAL);
        AddPage(PAGE_ID_UNKNOWN_3A);
        AddPage(PAGE_ID_WIFI_FRIEND_RACE);
        AddPage(PAGE_ID_WIFI_FRIEND_FINAL_RESULTS);
        AddPage(PAGE_ID_WIFI_PLEASE_WAIT);
        AddPage(PAGE_ID_MENU_MESSAGE);
        AddPage(PAGE_ID_UNKNOWN_88);
        AddPage(PAGE_ID_UNKNOWN_94);
        break;

    case SECTION_ID_WIFI_1P_FRIEND_RACE_TEAM_VS:
        AddPage(PAGE_ID_RESULT_RACE_UPDATE);
        AddPage(PAGE_ID_RESULT_TEAM_VS_TOTAL);
        AddPage(PAGE_ID_UNKNOWN_3A);
        AddPage(PAGE_ID_WIFI_FRIEND_RACE);
        AddPage(PAGE_ID_WIFI_FRIEND_FINAL_RESULTS);
        AddPage(PAGE_ID_WIFI_PLEASE_WAIT);
        AddPage(PAGE_ID_MENU_MESSAGE);
        AddPage(PAGE_ID_UNKNOWN_88);
        AddPage(PAGE_ID_UNKNOWN_94);
        break;

    case SECTION_ID_WIFI_1P_FRIEND_BALLOON_BT_GAMEPLAY:
        AddPage(PAGE_ID_BATTLE_1P);
        AddPage(PAGE_ID_RESULT_BATTLE_UPDATE);
        AddPage(PAGE_ID_RESULT_BATTLE_TOTAL);
        AddPage(PAGE_ID_UNKNOWN_3A);
        AddPage(PAGE_ID_WIFI_FRIEND_FINAL_RESULTS);
        AddPage(PAGE_ID_WIFI_PLEASE_WAIT);
        AddPage(PAGE_ID_MENU_MESSAGE);
        AddPage(PAGE_ID_UNKNOWN_88);
        AddPage(PAGE_ID_UNKNOWN_94);
        break;

    case SECTION_ID_WIFI_1P_FRIEND_COIN_BT_GAMEPLAY:
        AddPage(PAGE_ID_BATTLE_1P);
        AddPage(PAGE_ID_RESULT_BATTLE_UPDATE);
        AddPage(PAGE_ID_RESULT_BATTLE_TOTAL);
        AddPage(PAGE_ID_UNKNOWN_3A);
        AddPage(PAGE_ID_WIFI_FRIEND_FINAL_RESULTS);
        AddPage(PAGE_ID_WIFI_PLEASE_WAIT);
        AddPage(PAGE_ID_MENU_MESSAGE);
        AddPage(PAGE_ID_UNKNOWN_88);
        AddPage(PAGE_ID_UNKNOWN_94);
        break;

    case SECTION_ID_WIFI_2P_FRIEND_RACE_VS:
        AddPage(PAGE_ID_RESULT_RACE_UPDATE);
        AddPage(PAGE_ID_RESULT_RACE_TOTAL);
        AddPage(PAGE_ID_UNKNOWN_3A);
        AddPage(PAGE_ID_WIFI_FRIEND_TEAM_RACE);
        AddPage(PAGE_ID_WIFI_FRIEND_FINAL_RESULTS);
        AddPage(PAGE_ID_WIFI_PLEASE_WAIT);
        AddPage(PAGE_ID_MENU_MESSAGE);
        AddPage(PAGE_ID_UNKNOWN_88);
        AddPage(PAGE_ID_UNKNOWN_94);
        break;

    case SECTION_ID_WIFI_2P_FRIEND_RACE_TEAM_VS:
        AddPage(PAGE_ID_RESULT_RACE_UPDATE);
        AddPage(PAGE_ID_RESULT_TEAM_VS_TOTAL);
        AddPage(PAGE_ID_UNKNOWN_3A);
        AddPage(PAGE_ID_WIFI_FRIEND_TEAM_RACE);
        AddPage(PAGE_ID_WIFI_FRIEND_FINAL_RESULTS);
        AddPage(PAGE_ID_WIFI_PLEASE_WAIT);
        AddPage(PAGE_ID_MENU_MESSAGE);
        AddPage(PAGE_ID_UNKNOWN_88);
        AddPage(PAGE_ID_UNKNOWN_94);
        break;

    case SECTION_ID_WIFI_2P_FRIEND_BALLOON_BT_GAMEPLAY:
        AddPage(PAGE_ID_BATTLE_2P);
        AddPage(PAGE_ID_RESULT_BATTLE_UPDATE);
        AddPage(PAGE_ID_RESULT_BATTLE_TOTAL);
        AddPage(PAGE_ID_UNKNOWN_3A);
        AddPage(PAGE_ID_WIFI_FRIEND_FINAL_RESULTS);
        AddPage(PAGE_ID_WIFI_PLEASE_WAIT);
        AddPage(PAGE_ID_MENU_MESSAGE);
        AddPage(PAGE_ID_UNKNOWN_88);
        AddPage(PAGE_ID_UNKNOWN_94);
        break;

    case SECTION_ID_WIFI_2P_FRIEND_COIN_BT_GAMEPLAY:
        AddPage(PAGE_ID_BATTLE_2P);
        AddPage(PAGE_ID_RESULT_BATTLE_UPDATE);
        AddPage(PAGE_ID_RESULT_BATTLE_TOTAL);
        AddPage(PAGE_ID_UNKNOWN_3A);
        AddPage(PAGE_ID_WIFI_FRIEND_FINAL_RESULTS);
        AddPage(PAGE_ID_WIFI_PLEASE_WAIT);
        AddPage(PAGE_ID_MENU_MESSAGE);
        AddPage(PAGE_ID_UNKNOWN_88);
        AddPage(PAGE_ID_UNKNOWN_94);
        break;

    case SECTION_ID_WIFI_DISCONNECT_ERROR:
        AddPage(PAGE_ID_UNKNOWN_5D);
        AddPage(PAGE_ID_WIFI_CONNECT_ERROR);
        break;

    case SECTION_ID_WIFI_DISCONNECT_GENERAL:
        AddPage(PAGE_ID_UNKNOWN_5D);
        AddPage(PAGE_ID_WIFI_CONNECT_ERROR);
        break;

    case SECTION_ID_CHANNEL_FROM_MENU:
        AddPage(PAGE_ID_POPUP_MESSAGE);
        AddPage(PAGE_ID_MENU_MESSAGE);
        AddPage(PAGE_ID_CONFIRM);
        AddPage(PAGE_ID_MENU_OVERLAY);
        AddPage(PAGE_ID_CHANNEL_TOP);
        AddPage(PAGE_ID_CHANNEL_RANKING);
        AddPage(PAGE_ID_CHANNEL_GHOST);
        break;

    case SECTION_ID_CHANNEL_FROM_CHECK_RANKINGS:
        AddPage(PAGE_ID_POPUP_MESSAGE);
        AddPage(PAGE_ID_MENU_MESSAGE);
        AddPage(PAGE_ID_CONFIRM);
        AddPage(PAGE_ID_MENU_OVERLAY);
        AddPage(PAGE_ID_CHANNEL_TOP);
        AddPage(PAGE_ID_CHANNEL_RANKING);
        AddPage(PAGE_ID_CHANNEL_GHOST);
        break;

    case SECTION_ID_CHANNEL_FROM_DOWNLOADS:
        AddPage(PAGE_ID_POPUP_MESSAGE);
        AddPage(PAGE_ID_MENU_MESSAGE);
        AddPage(PAGE_ID_CONFIRM);
        AddPage(PAGE_ID_MENU_OVERLAY);
        AddPage(PAGE_ID_CHANNEL_TOP);
        AddPage(PAGE_ID_CHANNEL_RANKING);
        AddPage(PAGE_ID_CHANNEL_GHOST);
        break;

    case SECTION_ID_TIME_ATTACK_LEADERBOARDS:
        AddPage(PAGE_ID_POPUP_YES_NO);
        AddPage(PAGE_ID_READING_GHOST_DATA);
        AddPage(PAGE_ID_WIFI_CONNECTING);
        AddPage(PAGE_ID_MENU_MESSAGE);
        AddPage(PAGE_ID_CONFIRM);
        AddPage(PAGE_ID_CUP_SELECT);
        AddPage(PAGE_ID_COURSE_SELECT);
        AddPage(PAGE_ID_UNKNOWN_84);
        AddPage(PAGE_ID_WIFI_FIRST_PLAY);
        AddPage(PAGE_ID_WIFI_DATA_SHARING_PROMPT);
        AddPage(PAGE_ID_UNKNOWN_88);
        AddPage(PAGE_ID_WIFI_CONNECT_ERROR);
        AddPage(PAGE_ID_WIFI_GLOBE_MODEL);
        AddPage(PAGE_ID_GHOST_MANAGER);
        AddPage(PAGE_ID_CHANNEL_GHOST_HISTOGRAM);
        AddPage(PAGE_ID_UNKNOWN_AA);
        AddPage(PAGE_ID_UNKNOWN_AB);
        AddPage(PAGE_ID_UNKNOWN_AC);
        AddPage(PAGE_ID_UNKNOWN_AD);
        AddPage(PAGE_ID_UNKNOWN_AE);
        AddPage(PAGE_ID_UNKNOWN_AF);
        break;

    case SECTION_ID_COMPETITION_LEADERBOARDS:
        AddPage(PAGE_ID_POPUP_YES_NO);
        AddPage(PAGE_ID_READING_GHOST_DATA);
        AddPage(PAGE_ID_WIFI_CONNECTING);
        AddPage(PAGE_ID_MENU_MESSAGE);
        AddPage(PAGE_ID_CONFIRM);
        AddPage(PAGE_ID_UNKNOWN_84);
        AddPage(PAGE_ID_WIFI_FIRST_PLAY);
        AddPage(PAGE_ID_WIFI_DATA_SHARING_PROMPT);
        AddPage(PAGE_ID_UNKNOWN_88);
        AddPage(PAGE_ID_WIFI_CONNECT_ERROR);
        AddPage(PAGE_ID_WIFI_GLOBE_MODEL);
        AddPage(PAGE_ID_UNKNOWN_A9);
        AddPage(PAGE_ID_UNKNOWN_AA);
        AddPage(PAGE_ID_UNKNOWN_AB);
        AddPage(PAGE_ID_UNKNOWN_AE);
        AddPage(PAGE_ID_UNKNOWN_AF);
        AddPage(PAGE_ID_UNKNOWN_B0);
        break;

    case SECTION_ID_GHOST_RACE_WITH_DATA:
        AddPage(PAGE_ID_START_RACE_CONFIRM);
        AddPage(PAGE_ID_POPUP_MESSAGE);
        AddPage(PAGE_ID_MENU_MESSAGE);
        AddPage(PAGE_ID_MENU_OVERLAY);
        AddPage(PAGE_ID_CHARACTER_SELECT);
        AddPage(PAGE_ID_VEHICLE_SELECT);
        AddPage(PAGE_ID_DRIFT_SELECT);
        AddPage(PAGE_ID_MODEL_RENDER);
        AddPage(PAGE_ID_UNKNOWN_9F);
        AddPage(PAGE_ID_UNKNOWN_A0);
        AddPage(PAGE_ID_UNKNOWN_A1);
        break;

    case SECTION_ID_GHOST_RACE_WITHOUT_DATA:
        AddPage(PAGE_ID_START_RACE_CONFIRM);
        AddPage(PAGE_ID_POPUP_MESSAGE);
        AddPage(PAGE_ID_POPUP_YES_NO);
        AddPage(PAGE_ID_WIFI_CONNECTING);
        AddPage(PAGE_ID_MENU_MESSAGE);
        AddPage(PAGE_ID_CONFIRM);
        AddPage(PAGE_ID_MENU_OVERLAY);
        AddPage(PAGE_ID_CHARACTER_SELECT);
        AddPage(PAGE_ID_VEHICLE_SELECT);
        AddPage(PAGE_ID_DRIFT_SELECT);
        AddPage(PAGE_ID_MODEL_RENDER);
        AddPage(PAGE_ID_UNKNOWN_84);
        AddPage(PAGE_ID_WIFI_FIRST_PLAY);
        AddPage(PAGE_ID_WIFI_DATA_SHARING_PROMPT);
        AddPage(PAGE_ID_UNKNOWN_88);
        AddPage(PAGE_ID_WIFI_CONNECT_ERROR);
        AddPage(PAGE_ID_UNKNOWN_9F);
        AddPage(PAGE_ID_UNKNOWN_A0);
        AddPage(PAGE_ID_UNKNOWN_A1);
        break;

    case SECTION_ID_GHOST_RACE_NEXT_RACE:
        AddPage(PAGE_ID_START_RACE_CONFIRM);
        AddPage(PAGE_ID_POPUP_MESSAGE);
        AddPage(PAGE_ID_POPUP_YES_NO);
        AddPage(PAGE_ID_WIFI_CONNECTING);
        AddPage(PAGE_ID_MENU_MESSAGE);
        AddPage(PAGE_ID_CONFIRM);
        AddPage(PAGE_ID_MENU_OVERLAY);
        AddPage(PAGE_ID_CHARACTER_SELECT);
        AddPage(PAGE_ID_VEHICLE_SELECT);
        AddPage(PAGE_ID_DRIFT_SELECT);
        AddPage(PAGE_ID_MODEL_RENDER);
        AddPage(PAGE_ID_UNKNOWN_84);
        AddPage(PAGE_ID_WIFI_FIRST_PLAY);
        AddPage(PAGE_ID_WIFI_DATA_SHARING_PROMPT);
        AddPage(PAGE_ID_UNKNOWN_88);
        AddPage(PAGE_ID_WIFI_CONNECT_ERROR);
        AddPage(PAGE_ID_UNKNOWN_A0);
        AddPage(PAGE_ID_UNKNOWN_A1);
        break;

    case SECTION_ID_DOWNLOADED_GHOST_DATA:
        AddPage(PAGE_ID_POPUP_MESSAGE);
        AddPage(PAGE_ID_READING_GHOST_DATA);
        AddPage(PAGE_ID_MENU_MESSAGE);
        AddPage(PAGE_ID_MENU_OVERLAY);
        AddPage(PAGE_ID_GHOST_MANAGER);
        AddPage(PAGE_ID_UNKNOWN_B3);
        AddPage(PAGE_ID_UNKNOWN_B4);
        AddPage(PAGE_ID_UNKNOWN_B5);
        break;

    case SECTION_ID_FRIENDS_LIST_A:
        AddPage(PAGE_ID_POPUP_WAITING);
        AddPage(PAGE_ID_POPUP_MESSAGE);
        AddPage(PAGE_ID_POPUP_YES_NO);
        AddPage(PAGE_ID_READING_GHOST_DATA);
        AddPage(PAGE_ID_WIFI_CONNECTING);
        AddPage(PAGE_ID_MENU_MESSAGE);
        AddPage(PAGE_ID_CONFIRM);
        AddPage(PAGE_ID_MENU_OVERLAY);
        AddPage(PAGE_ID_CHARACTER_SELECT);
        AddPage(PAGE_ID_VEHICLE_SELECT);
        AddPage(PAGE_ID_DRIFT_SELECT);
        AddPage(PAGE_ID_BATTLE_VEHICLE_SELECT);
        AddPage(PAGE_ID_MODEL_RENDER);
        AddPage(PAGE_ID_UNKNOWN_84);
        AddPage(PAGE_ID_WIFI_FIRST_PLAY);
        AddPage(PAGE_ID_WIFI_DATA_SHARING_PROMPT);
        AddPage(PAGE_ID_UNKNOWN_87);
        AddPage(PAGE_ID_UNKNOWN_88);
        AddPage(PAGE_ID_WIFI_CONNECT_ERROR);
        AddPage(PAGE_ID_WIFI_FRIENDS_MENU_CHANNEL);
        AddPage(PAGE_ID_WIFI_SEARCH_MANAGER);
        AddPage(PAGE_ID_WIFI_GLOBE_MODEL);
        AddPage(PAGE_ID_WIFI_FRIEND_ROSTER);
        AddPage(PAGE_ID_WIFI_NOT_FRIENDS_YET);
        AddPage(PAGE_ID_WIFI_REMOVE_FRIEND_CODE_PROMPT);
        AddPage(PAGE_ID_WIFI_REMOVING_FRIEND_CODE);
        AddPage(PAGE_ID_WIFI_FRIEND_ROOM_WAITING_TEXT);
        AddPage(PAGE_ID_WIFI_FRIEND_ROOM_MANAGER);
        AddPage(PAGE_ID_WIFI_FRIEND_ROOM);
        AddPage(PAGE_ID_WIFI_FRIEND_ROOM_MESSAGE_SELECT);
        AddPage(PAGE_ID_UNKNOWN_A5);
        AddPage(PAGE_ID_ENTER_FRIEND_CODE);
        AddPage(PAGE_ID_GHOST_MANAGER);
        break;

    case SECTION_ID_FRIENDS_LIST_B:
        AddPage(PAGE_ID_POPUP_WAITING);
        AddPage(PAGE_ID_POPUP_MESSAGE);
        AddPage(PAGE_ID_POPUP_YES_NO);
        AddPage(PAGE_ID_READING_GHOST_DATA);
        AddPage(PAGE_ID_WIFI_CONNECTING);
        AddPage(PAGE_ID_MENU_MESSAGE);
        AddPage(PAGE_ID_CONFIRM);
        AddPage(PAGE_ID_MENU_OVERLAY);
        AddPage(PAGE_ID_CHARACTER_SELECT);
        AddPage(PAGE_ID_VEHICLE_SELECT);
        AddPage(PAGE_ID_DRIFT_SELECT);
        AddPage(PAGE_ID_BATTLE_VEHICLE_SELECT);
        AddPage(PAGE_ID_MODEL_RENDER);
        AddPage(PAGE_ID_UNKNOWN_84);
        AddPage(PAGE_ID_WIFI_FIRST_PLAY);
        AddPage(PAGE_ID_WIFI_DATA_SHARING_PROMPT);
        AddPage(PAGE_ID_UNKNOWN_87);
        AddPage(PAGE_ID_UNKNOWN_88);
        AddPage(PAGE_ID_WIFI_CONNECT_ERROR);
        AddPage(PAGE_ID_WIFI_FRIENDS_MENU_CHANNEL);
        AddPage(PAGE_ID_WIFI_SEARCH_MANAGER);
        AddPage(PAGE_ID_WIFI_GLOBE_MODEL);
        AddPage(PAGE_ID_WIFI_FRIEND_ROSTER);
        AddPage(PAGE_ID_WIFI_NOT_FRIENDS_YET);
        AddPage(PAGE_ID_WIFI_REMOVE_FRIEND_CODE_PROMPT);
        AddPage(PAGE_ID_WIFI_REMOVING_FRIEND_CODE);
        AddPage(PAGE_ID_UNKNOWN_9A);
        AddPage(PAGE_ID_WIFI_FRIEND_ROOM_WAITING_TEXT);
        AddPage(PAGE_ID_WIFI_FRIEND_ROOM_MANAGER);
        AddPage(PAGE_ID_WIFI_FRIEND_ROOM);
        AddPage(PAGE_ID_WIFI_FRIEND_ROOM_MESSAGE_SELECT);
        AddPage(PAGE_ID_UNKNOWN_A5);
        AddPage(PAGE_ID_ENTER_FRIEND_CODE);
        AddPage(PAGE_ID_GHOST_MANAGER);
        break;

    case SECTION_ID_COMPETITION:
        AddPage(PAGE_ID_START_RACE_CONFIRM);
        AddPage(PAGE_ID_POPUP_MESSAGE);
        AddPage(PAGE_ID_MENU_MESSAGE);
        AddPage(PAGE_ID_CHARACTER_SELECT);
        AddPage(PAGE_ID_VEHICLE_SELECT);
        AddPage(PAGE_ID_DRIFT_SELECT);
        AddPage(PAGE_ID_MODEL_RENDER);
        AddPage(PAGE_ID_UNKNOWN_B7);
        AddPage(PAGE_ID_UNKNOWN_B8);
        AddPage(PAGE_ID_UNKNOWN_BB);
        break;

    case SECTION_ID_COMPETITION_CHANGE_CHARA:
        AddPage(PAGE_ID_START_RACE_CONFIRM);
        AddPage(PAGE_ID_POPUP_MESSAGE);
        AddPage(PAGE_ID_MENU_MESSAGE);
        AddPage(PAGE_ID_CHARACTER_SELECT);
        AddPage(PAGE_ID_VEHICLE_SELECT);
        AddPage(PAGE_ID_DRIFT_SELECT);
        AddPage(PAGE_ID_MODEL_RENDER);
        AddPage(PAGE_ID_UNKNOWN_B7);
        AddPage(PAGE_ID_UNKNOWN_B8);
        AddPage(PAGE_ID_UNKNOWN_BB);
        break;

    case SECTION_ID_COMPETITION_SUBMIT_RECORD:
        AddPage(PAGE_ID_POPUP_YES_NO);
        AddPage(PAGE_ID_READING_GHOST_DATA);
        AddPage(PAGE_ID_WIFI_CONNECTING);
        AddPage(PAGE_ID_MENU_MESSAGE);
        AddPage(PAGE_ID_MENU_OVERLAY);
        AddPage(PAGE_ID_UNKNOWN_84);
        AddPage(PAGE_ID_WIFI_FIRST_PLAY);
        AddPage(PAGE_ID_WIFI_DATA_SHARING_PROMPT);
        AddPage(PAGE_ID_UNKNOWN_88);
        AddPage(PAGE_ID_WIFI_CONNECT_ERROR);
        AddPage(PAGE_ID_UNKNOWN_B9);
        break;

    case SECTION_ID_COMPETITION_WII_WHEEL_ONLY:
        AddPage(PAGE_ID_UNKNOWN_5B);
        AddPage(PAGE_ID_UNKNOWN_BA);
        break;

    case SECTION_ID_COMPETITION_WII_WHEEL_ONLY_BOSS:
        AddPage(PAGE_ID_UNKNOWN_5B);
        AddPage(PAGE_ID_UNKNOWN_BA);
        break;

    case SECTION_ID_INVITE_FRIENDS_FROM_MSG_BOARD:
        AddPage(PAGE_ID_READING_GHOST_DATA);
        AddPage(PAGE_ID_MENU_MESSAGE);
        AddPage(PAGE_ID_CONFIRM);
        AddPage(PAGE_ID_MENU_OVERLAY);
        AddPage(PAGE_ID_UNKNOWN_BD);
        AddPage(PAGE_ID_UNKNOWN_BE);
        AddPage(PAGE_ID_UNKNOWN_BF);
        break;

    case SECTION_ID_DOWNLOAD_LATEST_DATA:
        AddPage(PAGE_ID_WIFI_CONNECTING);
        AddPage(PAGE_ID_MENU_MESSAGE);
        AddPage(PAGE_ID_CONFIRM);
        AddPage(PAGE_ID_MENU_OVERLAY);
        AddPage(PAGE_ID_UNKNOWN_BC);
        break;

    case SECTION_ID_OPTIONS:
        AddPage(PAGE_ID_POPUP_MESSAGE);
        AddPage(PAGE_ID_POPUP_YES_NO);
        AddPage(PAGE_ID_UNKNOWN_5D);
        AddPage(PAGE_ID_OPTION_TOP);
        AddPage(PAGE_ID_OPTION_WIFI_SETTINGS);
        AddPage(PAGE_ID_OPTION_EXPLANATION);
        AddPage(PAGE_ID_OPTION_SELECT2);
        AddPage(PAGE_ID_OPTION_SELECT3);
        AddPage(PAGE_ID_OPTION_SET_REGION_PROMPT);
        AddPage(PAGE_ID_OPTION_DISPLAY_REGION_PROMPT);
        AddPage(PAGE_ID_OPTION_AWAIT);
        AddPage(PAGE_ID_OPTION_MESSAGE);
        AddPage(PAGE_ID_OPTION_CONFIRM);
        AddPage(PAGE_ID_ADD_CHANNEL_EXPLANATION);
        AddPage(PAGE_ID_ADD_CHANNEL_CONFIRM);
        AddPage(PAGE_ID_UNKNOWN_CC);
        break;

    case SECTION_ID_INSTALL_CHANNEL:
        AddPage(PAGE_ID_UNKNOWN_5D);
        AddPage(PAGE_ID_ADD_CHANNEL_EXPLANATION);
        AddPage(PAGE_ID_ADD_CHANNEL_CONFIRM);
        AddPage(PAGE_ID_UNKNOWN_CC);
        break;

    case SECTION_ID_CHOOSE_REGION:
        AddPage(PAGE_ID_UNKNOWN_5D);
        AddPage(PAGE_ID_OPTION_SET_REGION_PROMPT);
        AddPage(PAGE_ID_UNKNOWN_CC);
        break;

    case SECTION_ID_JOIN_MESSAGE_SERVICE:
        AddPage(PAGE_ID_POPUP_YES_NO);
        AddPage(PAGE_ID_UNKNOWN_5D);
        AddPage(PAGE_ID_OPTION_EXPLANATION);
        AddPage(PAGE_ID_OPTION_SELECT2);
        AddPage(PAGE_ID_OPTION_DISPLAY_REGION_PROMPT);
        AddPage(PAGE_ID_OPTION_AWAIT);
        AddPage(PAGE_ID_OPTION_MESSAGE);
        AddPage(PAGE_ID_OPTION_CONFIRM);
        AddPage(PAGE_ID_UNKNOWN_CC);
        break;

    case SECTION_ID_MSG_UNLOCK_PINK:
        AddPage(PAGE_ID_UNKNOWN_5B);
        AddPage(PAGE_ID_MENU_OVERLAY);
        AddPage(PAGE_ID_MODEL_RENDER);
        AddPage(PAGE_ID_UNKNOWN_CD);
        break;

    case SECTION_ID_MSG_UNLOCK_ORANGE:
        AddPage(PAGE_ID_UNKNOWN_5B);
        AddPage(PAGE_ID_MENU_OVERLAY);
        AddPage(PAGE_ID_MODEL_RENDER);
        AddPage(PAGE_ID_UNKNOWN_CD);
        break;

    case SECTION_ID_MSG_UNLOCK_BLUE:
        AddPage(PAGE_ID_UNKNOWN_5B);
        AddPage(PAGE_ID_MENU_OVERLAY);
        AddPage(PAGE_ID_MODEL_RENDER);
        AddPage(PAGE_ID_UNKNOWN_CD);
        break;

    case SECTION_ID_MSG_UNLOCK_YELLOW:
        AddPage(PAGE_ID_UNKNOWN_5B);
        AddPage(PAGE_ID_MENU_OVERLAY);
        AddPage(PAGE_ID_MODEL_RENDER);
        AddPage(PAGE_ID_UNKNOWN_CD);
        break;

    case SECTION_ID_DEBUG_MISSION_RUN:
        AddPage(PAGE_ID_MISSION_LEVEL_SELECT);
        AddPage(PAGE_ID_MISSION_STAGE_SELECT);
        AddPage(PAGE_ID_MISSION_PROMPT);
        AddPage(PAGE_ID_MISSION_DRIFT);
        AddPage(PAGE_ID_MISSION_TUTORIAL);
        break;
    }
}

} // namespace UI
