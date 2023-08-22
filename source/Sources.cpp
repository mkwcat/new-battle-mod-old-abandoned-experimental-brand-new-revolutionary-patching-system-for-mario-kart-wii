#include "system/Common.h"

#include "dwc/WiimmfiCA.cpp"
#include "dwc/dwc_auth_interface.cpp"
#include "dwc/dwc_init.cpp"
#include "dwc/dwc_memfunc.cpp"
#include "egg/core/eggDisposer.cpp"
#include "egg/core/eggDvdFile.cpp"
#include "egg/core/eggDvdRipper.cpp"
#include "egg/core/eggHeap.cpp"
#include "game/Boot/RKSystem.cpp"
#include "game/Boot/Scene.cpp"
#include "game/Boot/SystemManager.cpp"
#include "game/Enemy/AIBattleManager.cpp"
#include "game/Kart/KartCollide.cpp"
#include "game/Kart/KartMove.cpp"
#include "game/Kart/KartObjectManager.cpp"
#include "game/Kart/KartObjectProxy.cpp"
#include "game/Net/Nwc24Manager.cpp"
#include "game/Object/BattleBalloon.cpp"
#include "game/Sound/KartSound.cpp"

#include "game/System/InputManager.cpp"
#include "game/System/MiiManager.cpp"
#include "game/System/NandManager.cpp"
#include "game/System/PlayerRating.cpp"
#include "game/System/RaceEnemyLineController.cpp"
#include "game/System/RaceInfo.cpp"
#include "game/System/RaceManager.cpp"
#include "game/System/RaceMinigameParam.cpp"
#include "game/System/RaceModeBattleBalloon.cpp"
#include "game/System/RaceModeBattleBase.cpp"
#include "game/System/RaceModeBattleCoin.cpp"
#include "game/System/RaceModeBattleWiFiBalloon.cpp"
#include "game/System/RaceModeBattleWiFiCoin.cpp"
#include "game/System/RaceModeMissionRun.cpp"
#include "game/System/RaceModeWiFi.cpp"
#include "game/System/RootScene.cpp"
#include "game/System/SaveManager.cpp"

#include "game/UI/ControlGroup.cpp"
#include "game/UI/Section.cpp"
#include "game/UI/SectionManager.cpp"
#include "game/UI/SystemMessageGroup.cpp"
#include "game/UI/UIControl.cpp"

// MKW: 0x80790AD8 - 0x8079126C
#include "game/Item/ItemConfig.cpp"
// MKW: 0x8079126C - 0x80795CC8
#include "game/Item/ItemGeoKart.cpp"
// MKW: 0x80795CC8 - 0x8079754C
#include "game/Item/ItemGeoObjManager.cpp"
// MKW: 0x8079754C - 0x80798F9C
#include "game/Item/ItemKartProxy.cpp"
// MKW: 0x80798F9C - 0x8079A778
#include "game/Item/ItemManager.cpp"
// MKW: 0x8079A778 - 0x8079D804
#include "game/Item/ItemNetManager.cpp"
// MKW: 0x8079D804 - 0x807A3A24
#include "game/Item/ItemObj.cpp"
// MKW: 0x807A3A24 - 0x807A41C4
#include "game/Item/ItemObjBanana.cpp"
// MKW: 0x807A41C4 - 0x807A6328
#include "game/Item/ItemObjBomhei.cpp"
// MKW: 0x807A6328 - 0x807A78A8
#include "game/Item/ItemObjCommon.cpp"
// MKW: 0x807A78A8 - 0x807A8138
#include "game/Item/ItemObjDummyBox.cpp"
// MKW: ---
#include "game/Item/ItemObjFeather.cpp"
// MKW: 0x807A8138 - 0x807A8394
#include "game/Item/ItemObjGesso.cpp"
// MKW: 0x807A8394 - 0x807A9A80
#include "game/Item/ItemObjGessoDirector.cpp"
// MKW: ---
#include "game/Item/ItemObjItemBox.cpp"
// MKW: 0x807A9A80 - 0x807A9CC0
#include "game/Item/ItemObjKiller.cpp"
// MKW: 0x807A9CC0 - 0x807A9DD4
#include "game/Item/ItemObjKinoko.cpp"
// MKW: 0x807A9DD4 - 0x807A9EE8
#include "game/Item/ItemObjKinokoBig.cpp"
// MKW: 0x807A9EE8 - 0x807A9FF0
#include "game/Item/ItemObjKinokoGolden.cpp"
// MKW: 0x807A9FF0 - 0x807AB9E0
#include "game/Item/ItemObjKoura.cpp"
// MKW: 0x807AB9E0 - 0x807AEAEC
#include "game/Item/ItemObjKouraBlue.cpp"
// MKW: 0x807AEAEC - 0x807AF140
#include "game/Item/ItemObjKouraGreen.cpp"
// MKW: 0x807AF140 - 0x807B1AB0
#include "game/Item/ItemObjPikakumo.cpp"
// MKW: 0x807B1AB0 - 0x807B1BC0
#include "game/Item/ItemObjPowBlock.cpp"
// MKW: 0x807B1BC0 - 0x807B2EF8
#include "game/Item/ItemObjPowBlockDirector.cpp"
// MKW: 0x807B2EF8 - 0x807B6FF0
#include "game/Item/ItemObjSearcher.cpp"
// MKW: 0x807B6FF0 - 0x807B7104
#include "game/Item/ItemObjStar.cpp"
// MKW: 0x807B7104 - 0x807B7B00
#include "game/Item/ItemObjThrow.cpp"
// MKW: 0x807B7B00 - 0x807B7D9C
#include "game/Item/ItemObjThunder.cpp"
// MKW: 0x807B7D9C - 0x807B9F48
#include "game/Item/ItemPoint.cpp"
// MKW: 0x807B9F48 - 0x807BA650
#include "game/Item/ItemSlot.cpp"
// MKW: 0x807BA650 - 0x807BC0F8
#include "game/Item/ItemSlotTable.cpp"
// MKW: 0x807BC0F8 - 0x807BCAE0
#include "game/Item/ItemStock.cpp"
// MKW: 0x807BCAE0 - 0x807BD1D0
#include "game/Item/ItemType.cpp"
// MKW: 0x807BD1D0 - 0x807BD7B4
#include "game/Race/ModeInfo.cpp"

#include "game/Race/Field/DriverModelManager.cpp"

#include "game/Util/Handler.cpp"
#include "game/Util/Random.cpp"
#include "game/Util/Registry.cpp"

#include "nw4r/lyt/lyt_init.cpp"
#include "platform/string.cpp"
#include "revolution/arc/arc.cpp"
#include "revolution/cache.cpp"
#include "revolution/dvd/dvdfs.cpp"
#include "revolution/nhttp.cpp"
#include "revolution/os.cpp"
#include "system/Common.cpp"
