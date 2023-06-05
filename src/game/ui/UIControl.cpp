#include "UIControl.h"

UI_CPP_EXTERN_TYPEINFO_ROOT(
  0x809C1E80, //
  ui::UIControl
);

EXTERN_TEXT(
  0x8063CE6C, //
  ui::UIControl::UIControl()
);

// 0x8063CF60: Unknown destructor

EXTERN_TEXT(
  0x8063CFA0, //
  ui::UIControl::~UIControl()
);

EXTERN_TEXT(
  0x8063CFFC, //
  void ui::UIControl::Debug()
);

EXTERN_TEXT(
  0x8063D004, //
  void ui::UIControl::Init()
);

EXTERN_TEXT(
  0x8063D044, //
  void ui::UIControl::Calc()
);

EXTERN_TEXT(
  0x8063D084, //
  void ui::UIControl::Draw()
);

EXTERN_TEXT(
  0x8063D0B8, //
  void ui::UIControl::Solve()
);

EXTERN_TEXT(
  0x8063D0E0, //
  void ui::UIControl::PageEvent(Page::SlideDir dir, PageID page)
);

EXTERN_TEXT(
  0x8063D194, //
  void ui::UIControl::SolveAnim()
);

EXTERN_TEXT(
  0x8063D268, //
  void ui::UIControl::InitControlGroup(u32 count)
);

EXTERN_TEXT(
  0x8063D278, //
  void ui::UIControl::SetControl(u32 index, UIControl* control)
);

EXTERN_TEXT(
  0x8063D284, //
  f32 ui::UIControl::GetSlideDelay()
);

EXTERN_TEXT(
  0x8063D398, //
  void ui::UIControl::SetGroup(ControlGroup* group, u32 drawPass)
);

EXTERN_TEXT(
  0x8063D3A4, //
  void ui::UIControl::SetSlideSound(s32 forwardSound, s32 backSound)
);

EXTERN_TEXT(
  0x8063D3B0, //
  const char* ui::UIControl::GetTypeName() const
);

UI_CPP_EXTERN_TYPENAME(
  0x8063D3B0, //
  ui::UIControl
);

EXTERN_TEXT(
  0x8063D3CC, //
  void ui::UIControl::SolvePropagate()
);

EXTERN_TEXT(
  0x8063D550, //
  void ui::UIControl::SolveScreenSpace()
);

EXTERN_TEXT(
  0x8063D608, //
  void ui::UIControl::VT_0x30()
);

EXTERN_TEXT(
  0x8063D648, //
  void ui::UIControl::FUN_0x8063D648()
);

EXTERN_TEXT(
  0x8063D74C, //
  void ui::UIControl::PlaySound(s32 sound, s32 param_2)
);

UI_CPP_EXTERN_TYPEINFO_DERIVED(
  0x809C1E84, //
  ui::LayoutUIControl, ui::UIControl
);

UI_CPP_EXTERN_TYPENAME(
  0x8063D788, //
  ui::LayoutUIControl
);

EXTERN_TEXT(
  0x8063D798, //
  ui::LayoutUIControl::LayoutUIControl()
);

EXTERN_TEXT(
  0x8063D8C0, //
  ui::LayoutUIControl::~LayoutUIControl()
);

EXTERN_TEXT(
  0x8063D954, //
  void ui::LayoutUIControl::VT_0x38()
);

EXTERN_TEXT(
  0x8063D9C0, //
  void ui::LayoutUIControl::SetPictureLayout(
    const char* dir, const char* filename
  )
);

EXTERN_TEXT(
  0x8063DA00, //
  void ui::LayoutUIControl::SetParentPane(const char* pane)
);

EXTERN_TEXT(
  0x8063DAC0, //
  void ui::LayoutUIControl::Init()
);

EXTERN_TEXT(
  0x8063DB00, //
  void ui::LayoutUIControl::Calc()
);

EXTERN_TEXT(
  0x8063DB84, //
  void ui::LayoutUIControl::Draw()
);

EXTERN_TEXT(
  0x8063DCBC, //
  void ui::LayoutUIControl::SetMessage(
    const char* pane, int msgId, MsgFormatParam* param
  )
);

EXTERN_TEXT(
  0x8063DDB4, //
  void ui::LayoutUIControl::SetMessageAll(int msgId, MsgFormatParam* param)
);

// 0x8063DDF4: Function of class defined in SetMessageAll

EXTERN_TEXT(
  0x8063DEEC, //
  void ui::LayoutUIControl::ClearMessage(const char* pane)
);

EXTERN_TEXT(
  0x8063DFC8, //
  void ui::LayoutUIControl::ClearMessageAll()
);

// 8063E000: Function of class defined in ClearMessageAll

EXTERN_TEXT(
  0x8063E0F0, //
  void ui::LayoutUIControl::SetPicture(const char* pane, const char* picture)
);

EXTERN_TEXT(
  0x8063E328, //
  bool ui::LayoutUIControl::HasPicture(const char* picture)
);

EXTERN_TEXT(
  0x8063E3DC, //
  void ui::LayoutUIControl::SetMiiPicture(
    const char* pane, void* miiGroup, u32 index, u32 preset
  )
);

EXTERN_TEXT(
  0x8063E54C, //
  void ui::LayoutUIControl::SetPaneVisible(const char* pane, bool visible)
);

EXTERN_TEXT(
  0x8063E58C, //
  void ui::LayoutUIControl::FUN_0x8063E58C(const char* param_1)
);

EXTERN_TEXT(
  0x8063E5C4, //
  void ui::LayoutUIControl::SetMovieCoords(
    const char* pane, float top, float bottom, float left, float right
  )
);

EXTERN_TEXT(
  0x8063E61C, //
  void ui::LayoutUIControl::VT_0x30()
);

UI_CPP_EXTERN_TYPEINFO_DERIVED(
  0x809C1E88, //
  ui::LayoutUIControlScaleFade, ui::LayoutUIControl
);

UI_CPP_EXTERN_TYPENAME(
  0x8063E664, //
  ui::LayoutUIControlScaleFade
);

EXTERN_TEXT(
  0x8063E674, //
  ui::LayoutUIControlScaleFade::LayoutUIControlScaleFade()
);

EXTERN_TEXT(
  0x8063E7A8, //
  ui::LayoutUIControlScaleFade::~LayoutUIControlScaleFade()
);

EXTERN_TEXT(
  0x8063E840, //
  void ui::LayoutUIControlScaleFade::SolveAnim()
);

// 0x8063E924: Weak defined: ui::LayoutUIControlScaleFade::GetRuntimeTypeInfo

// 0x8063E930: C++ static init
