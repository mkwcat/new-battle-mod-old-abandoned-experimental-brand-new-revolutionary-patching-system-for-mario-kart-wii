#include "UIControl.h"

namespace UI
{

UI_CPP_EXTERN_TYPEINFO_ROOT(
  0x809C1E80, //
  UIControl
);

EXTERN_TEXT(
  0x8063CE6C, //
  UIControl::UIControl()
);

// 0x8063CF60: Unknown destructor

EXTERN_TEXT(
  0x8063CFA0, //
  UIControl::~UIControl()
);

EXTERN_TEXT(
  0x8063CFFC, //
  void UIControl::Debug()
);

EXTERN_TEXT(
  0x8063D004, //
  void UIControl::Init()
);

EXTERN_TEXT(
  0x8063D044, //
  void UIControl::Calc()
);

EXTERN_TEXT(
  0x8063D084, //
  void UIControl::Draw()
);

EXTERN_TEXT(
  0x8063D0B8, //
  void UIControl::Solve()
);

EXTERN_TEXT(
  0x8063D0E0, //
  void UIControl::PageEvent(Page::EFadeDirection dir, EPageID page)
);

EXTERN_TEXT(
  0x8063D194, //
  void UIControl::SolveAnim()
);

EXTERN_TEXT(
  0x8063D268, //
  void UIControl::InitGroup(u32 count)
);

EXTERN_TEXT(
  0x8063D278, //
  void UIControl::SetChild(u32 index, UIControl* control)
);

EXTERN_TEXT(
  0x8063D284, //
  f32 UIControl::GetSlideDelay()
);

EXTERN_TEXT(
  0x8063D398, //
  void UIControl::SetGroup(ControlGroup* group, u32 drawPass)
);

EXTERN_TEXT(
  0x8063D3A4, //
  void UIControl::SetSlideSound(s32 forwardSound, s32 backSound)
);

EXTERN_TEXT(
  0x8063D3B0, //
  const char* UIControl::GetTypeName() const
);

UI_CPP_EXTERN_TYPENAME(
  0x8063D3C0, //
  UIControl
);

EXTERN_TEXT(
  0x8063D3CC, //
  void UIControl::SolvePropagate()
);

EXTERN_TEXT(
  0x8063D550, //
  void UIControl::SolveScreenSpace()
);

EXTERN_TEXT(
  0x8063D608, //
  void UIControl::VT_0x30()
);

EXTERN_TEXT(
  0x8063D648, //
  void UIControl::FUN_0x8063D648()
);

EXTERN_TEXT(
  0x8063D74C, //
  void UIControl::PlaySound(s32 sound, s32 param_2)
);

UI_CPP_EXTERN_TYPEINFO_DERIVED(
  0x809C1E84, //
  LayoutUIControl, UIControl
);

UI_CPP_EXTERN_TYPENAME(
  0x8063D788, //
  LayoutUIControl
);

EXTERN_TEXT(
  0x8063D798, //
  LayoutUIControl::LayoutUIControl()
);

EXTERN_TEXT(
  0x8063D8C0, //
  LayoutUIControl::~LayoutUIControl()
);

EXTERN_TEXT(
  0x8063D954, //
  void LayoutUIControl::VT_0x38()
);

EXTERN_TEXT(
  0x8063D9C0, //
  void LayoutUIControl::SetPictureLayout(const char* dir, const char* filename)
);

EXTERN_TEXT(
  0x8063DA00, //
  void LayoutUIControl::SetParentPane(const char* pane)
);

EXTERN_TEXT(
  0x8063DAC0, //
  void LayoutUIControl::Init()
);

EXTERN_TEXT(
  0x8063DB00, //
  void LayoutUIControl::Calc()
);

EXTERN_TEXT(
  0x8063DB84, //
  void LayoutUIControl::Draw()
);

EXTERN_TEXT(
  0x8063DCBC, //
  void LayoutUIControl::SetMessage(
    const char* pane, int msgId, MsgFormatParam* param
  )
);

EXTERN_TEXT(
  0x8063DDB4, //
  void LayoutUIControl::SetMessageRecursive(int msgId, MsgFormatParam* param)
);

// 0x8063DDF4: Function of class defined in SetMessageAll

EXTERN_TEXT(
  0x8063DEEC, //
  void LayoutUIControl::ClearMessage(const char* pane)
);

EXTERN_TEXT(
  0x8063DFC8, //
  void LayoutUIControl::ClearMessageRecursive()
);

// 8063E000: Function of class defined in ClearMessageAll

EXTERN_TEXT(
  0x8063E0F0, //
  void LayoutUIControl::SetPicture(const char* pane, const char* picture)
);

EXTERN_TEXT(
  0x8063E328, //
  bool LayoutUIControl::HasPicture(const char* picture)
);

EXTERN_TEXT(
  0x8063E3DC, //
  void LayoutUIControl::SetMiiPicture(
    const char* pane, void* miiGroup, u32 index, u32 preset
  )
);

EXTERN_TEXT(
  0x8063E54C, //
  void LayoutUIControl::SetPaneVisible(const char* pane, bool visible)
);

EXTERN_TEXT(
  0x8063E58C, //
  void LayoutUIControl::FUN_0x8063E58C(const char* param_1)
);

EXTERN_TEXT(
  0x8063E5C4, //
  void LayoutUIControl::SetMovieCoords(
    const char* pane, float top, float bottom, float left, float right
  )
);

EXTERN_TEXT(
  0x8063E61C, //
  void LayoutUIControl::VT_0x30()
);

UI_CPP_EXTERN_TYPEINFO_DERIVED(
  0x809C1E88, //
  LayoutUIControlScaleFade, LayoutUIControl
);

UI_CPP_EXTERN_TYPENAME(
  0x8063E664, //
  LayoutUIControlScaleFade
);

EXTERN_TEXT(
  0x8063E674, //
  LayoutUIControlScaleFade::LayoutUIControlScaleFade()
);

EXTERN_TEXT(
  0x8063E7A8, //
  LayoutUIControlScaleFade::~LayoutUIControlScaleFade()
);

EXTERN_TEXT(
  0x8063E840, //
  void LayoutUIControlScaleFade::SolveAnim()
);

// 0x8063E924: Weak defined: LayoutUIControlScaleFade::GetRuntimeTypeInfo

} // namespace UI

// 0x8063E930: C++ static init
