#pragma once

#include "ControlGroup.h"
#include "MessageGroup.h"
#include "Page.h"
#include "UIAnimator.h"
#include <game/sys/Mii.h>
#include <nw4r/ut/ut_RTTI.h>
#include <system/Common.h>

namespace ui
{

#define UI_INSTANTIATE_TYPEINFO(_NAME)                                         \
  public:                                                                      \
  INSTANTIATE_TYPEINFO;                                                        \
  virtual const char* GetTypeName()                                            \
  {                                                                            \
    return #_NAME;                                                             \
  }

#define UI_EXTERN_RTTI(_GETTYPEINFO, _GETTYPENAME)                             \
  public:                                                                      \
  EXTERN_TEXT(                                                                 \
    _GETTYPEINFO,                                                              \
    virtual const nw4r::ut::detail::RuntimeTypeInfo* GetRuntimeTypeInfo()      \
  );                                                                           \
  EXTERN_TEXT(_GETTYPENAME, virtual const char* GetTypeName());                \
  static const nw4r::ut::detail::RuntimeTypeInfo typeInfo

struct ControlPosition {
    ControlPosition()
      : x(0)
      , y(0)
      , z(0)
      , xScale(1)
      , yScale(1)
      , alpha(0xFF)
    {
    }

    /* 0x00 */ f32 x;
    /* 0x04 */ f32 y;
    /* 0x08 */ f32 z;
    /* 0x0C */ f32 xScale;
    /* 0x10 */ f32 yScale;
    /* 0x14 */ u8 alpha;
};

class UIControl
{
public:
    EXTERN_TEXT(0x8063607C, UIControl());
    EXTERN_TEXT(0x8063CFA0, virtual ~UIControl());

    EXTERN_TEXT(0x8063D004, virtual void Init()); // vt + 0xC
    EXTERN_TEXT(0x8063D044, virtual void Calc()); // vt + 0x10
    EXTERN_TEXT(0x8063D084, virtual void Draw()); // vt + 0x14
    EXTERN_TEXT(0x805BE600, virtual void OnInit()); // vt + 0x18
    EXTERN_TEXT(0x805BD2E0, virtual void OnCalc()); // vt + 0x1C
    EXTERN_TEXT(0x8063D194, virtual void SolveAnim()); // vt + 0x20
    EXTERN_TEXT(0x805BD2DC, virtual void OnPageEvent()); // vt + 0x24

    UI_EXTERN_RTTI(0x80606BDC, 0x8063D3C0); // includes vt + 0x28, 0x2C

    EXTERN_TEXT(0x8063D608, virtual void _30());
    EXTERN_TEXT(0x805BD2D8, virtual void _34());

    /* 0x04 */ ControlPosition m_basePos; // code position
    /* 0x1C */ ControlPosition m_layoutPos; // layout position
    /* 0x34 */ ControlPosition m_somePos;
    /* 0x4C */ ControlPosition m_finalPos;

    /* 0x64 */ ControlGroup* m_parent;
    /* 0x68 */ ControlGroup m_children;

    /* 0x7C */ f32 m_zIndex;
    /* 0x80 */ bool m_hidden;
    /* 0x84 */ u32 m_drawPass;
    /* 0x88 */ bool m_slideAnimation;
    /* 0x8C */ f32 m_slideDelay;
    /* 0x90 */ s32 m_forwardSound;
    /* 0x94 */ s32 m_backSound;
};

static_assert(sizeof(UIControl) == 0x98);

struct MsgFormatParam {
    s32 integers[9];
    s32 msgIds[9];
    sys::Mii* miis[9];
    u8 licenseIds[9];
    s32 playerIds[9];
    const wchar_t* strings[9];
    u32 unk_0xC0;
};

static_assert(sizeof(MsgFormatParam) == 0xC4);

class LayoutUIControl : public UIControl
{
    UI_EXTERN_RTTI(0x80606BD0, 0x8063D788);

public:
    EXTERN_TEXT(0x8063D798, LayoutUIControl());
    EXTERN_TEXT(0x8063D8C0, virtual ~LayoutUIControl());

    EXTERN_TEXT(0x8063DAC0, virtual void Init());
    EXTERN_TEXT(0x8063DB00, virtual void Calc());
    EXTERN_TEXT(0x8063DB84, virtual void Draw());
    EXTERN_TEXT(0x8063E61C, virtual void _30());
    EXTERN_TEXT(0x8063D954, virtual void _38());

    EXTERN_TEXT(
      0x8063DCBC, void SetMessage(
                    const char* pane, int msgId, MsgFormatParam* param = nullptr
                  )
    );
    EXTERN_TEXT(
      0x8063DDB4, void SetMessage(int msgId, MsgFormatParam* param = nullptr)
    );

    EXTERN_TEXT(
      0x8063E0F0, void SetTexture(const char* pane, const char* texture)
    );

    /* 0x098 */ UIAnimator m_animator;
    /* 0x0A8 */ u8 m_mainLayout[0x9C]; // Missing struct, just fill
    /* 0x144 */ MessageGroup m_msgGroup;
    /* 0x158 */ MessageGroup m_commonGroup;
    /* 0x16C */ void* m_iconPane;
    /* 0x170 */ void* m_mainPane;
};

static_assert(sizeof(LayoutUIControl) == 0x174);

class CtrlRes
{
public:
    CtrlRes(LayoutUIControl* parent);

    void readFile(
      const char* lytSection, const char* ctrlName, const char* positionEntry,
      const char** animations
    );

    LayoutUIControl* m_parent;
    char fill[0x20];
};

} // namespace ui
