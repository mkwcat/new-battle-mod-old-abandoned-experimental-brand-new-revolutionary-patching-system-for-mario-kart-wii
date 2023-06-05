#pragma once

#include "ControlGroup.h"
#include "MessageGroup.h"
#include "Page.h"
#include "PageID.h"
#include "UIAnimator.h"
#include <game/sys/Mii.h>
#include <nw4r/ut/ut_RTTI.h>
#include <system/Common.h>

namespace ui
{

#define UI_H_INSTANTIATE_TYPEINFO()                                            \
  public:                                                                      \
  _Pragma("GCC diagnostic push");                                              \
  _Pragma("GCC diagnostic ignored \"-Winconsistent-missing-override\"");       \
  INSTANTIATE_TYPEINFO;                                                        \
  virtual const char* RTTI_TypeName() const;                                   \
  _Pragma("GCC diagnostic pop");

// There is a limitation in the method we define external data in that it 1.
// can't be defined in a header file, and 2. will need to rerun the static
// constructor of the datatype. This is a little dirty, but this mod is not
// intended to be a sophisticated techincal showcase.
// We could always initialize the typeInfo as nullptr here, as StaticR.rel
// initializes after this module, but this is not something I really want to
// rely on.

#define UI_H_EXTERN_TYPEINFO(_GETTYPEINFO)                                     \
  public:                                                                      \
  _Pragma("GCC diagnostic push");                                              \
  _Pragma("GCC diagnostic ignored \"-Winconsistent-missing-override\"");       \
  EXTERN_TEXT(                                                                 \
    _GETTYPEINFO,                                                              \
    virtual const nw4r::ut::detail::RuntimeTypeInfo* GetRuntimeTypeInfo()      \
  );                                                                           \
  virtual const char* RTTI_TypeName() const;                                   \
  _Pragma("GCC diagnostic pop");                                               \
  static const nw4r::ut::detail::RuntimeTypeInfo typeInfo

#define UI_CPP_EXTERN_TYPEINFO_DERIVED(_ADDR, _OBJ, _BASE)                     \
  EXTERN_DATA(                                                                 \
    _ADDR,                                                                     \
    const nw4r::ut::detail::RuntimeTypeInfo _OBJ::typeInfo(&_BASE::typeInfo)   \
  )

#define UI_CPP_EXTERN_TYPEINFO_ROOT(_ADDR, _OBJ)                               \
  EXTERN_DATA(                                                                 \
    _ADDR, const nw4r::ut::detail::RuntimeTypeInfo _OBJ::typeInfo(nullptr)     \
  )

#define UI_CPP_EXTERN_TYPENAME(_ADDR, _OBJ)                                    \
  EXTERN_TEXT(_ADDR, const char* _OBJ::RTTI_TypeName() const)

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
    UIControl();
    /* VT+0x08 */ virtual ~UIControl();

    void Debug();

    /* VT+0x0C */ virtual void Init();
    /* VT+0x10 */ virtual void Calc();
    /* VT+0x14 */ virtual void Draw();

    void Solve();

    EXTERN_TEXT(
      0x805BE600, //
      /* VT+0x18 */ virtual void OnInit()
    );

    EXTERN_TEXT(
      0x805BD2E0, //
      /* VT+0x1C */ virtual void OnCalc()
    );

    void PageEvent(Page::SlideDir dir, PageID page);

    /* VT+0x20 */ virtual void SolveAnim();

    EXTERN_TEXT(
      0x805BD2DC, //
      /* VT+0x24 */ virtual void OnPageEvent(Page::SlideDir dir, PageID page)
    );

public:
    void InitControlGroup(u32 count);
    void SetControl(u32 index, UIControl* control);

    f32 GetSlideDelay();

    void SetGroup(ControlGroup* group, u32 drawPass);

    void SetSlideSound(s32 forwardSound, s32 backSound);

    const char* GetTypeName() const;

protected:
    UI_H_EXTERN_TYPEINFO(
      /* VT+0x28 */ 0x80606BDC /* VT+0x2C */
    );

public:
    void SolvePropagate();
    void SolveScreenSpace();

    /* VT+0x30 */ virtual void VT_0x30();

    void FUN_0x8063D648();

    EXTERN_TEXT(
      0x805BD2D8, //
      /* VT+0x34 */ virtual void VT_0x34()
    );

    void PlaySound(s32 sound, s32 param_2);

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
    /* 0x00 */ s32 numbers[9];
    /* 0x24 */ s32 msgIds[9];
    /* 0x48 */ sys::Mii* miis[9];
    /* 0x6C */ u8 licenses[9];
    /* 0x78 */ s32 playerIds[9];
    /* 0x9C */ const wchar_t* strings[9];
    /* 0xC0 */ u32 unk_0xC0;
};

static_assert(sizeof(MsgFormatParam) == 0xC4);

class LayoutUIControl : public UIControl
{
    UI_H_EXTERN_TYPEINFO(
      /* VT+0x28 */ 0x80606BD0 /* VT+0x2C */
    );

public:
    LayoutUIControl();

    /* VT+0x08 */ virtual ~LayoutUIControl() override;

    /* VT+0x0C */ virtual void Init() override;
    /* VT+0x10 */ virtual void Calc() override;
    /* VT+0x14 */ virtual void Draw() override;

    /* VT+0x30 */ virtual void VT_0x30() override;
    /* VT+0x38 */ virtual void VT_0x38();

    void SetParentPane(const char* pane);

    /**
     * Set the text of the specified pane to the message ID.
     */
    void
    SetMessage(const char* pane, int msgId, MsgFormatParam* param = nullptr);

    /**
     * Set the text of every pane in the layout to the message ID.
     */
    void SetMessageAll(int msgId, MsgFormatParam* param = nullptr);

    /**
     * Clear the text of the specified pane.
     */
    void ClearMessage(const char* pane);

    /**
     * Clear the text of every pane in the layout.
     */
    void ClearMessageAll();

    /**
     * Set the picture layout.
     */
    void SetPictureLayout(const char* dir, const char* filename);

    /**
     * Set a picture pane to a picture from the picture layout.
     */
    void SetPicture(const char* pane, const char* picture);

    /**
     * Check if the current picture layout has a picture with the specified
     * name.
     */
    bool HasPicture(const char* picture);

    /**
     * Set a picture pane to a render of a Mii.
     */
    void SetMiiPicture(const char* pane, void* miiGroup, u32 index, u32 preset);

    /**
     * Set the visibility flag of a pane.
     */
    void SetPaneVisible(const char* pane, bool visible);

    /**
     * Something movie related
     */
    void FUN_0x8063E58C(const char* param_1);

    /**
     * Set the rectangle coordinates of the movie to draw to the pane.
     */
    void SetMovieCoords(
      const char* pane, float top, float bottom, float left, float right
    );

    /* 0x098 */ UIAnimator m_animator;
    /* 0x0A8 */ u8 m_mainLayout[0x9C]; // Missing struct, just fill
    /* 0x144 */ MessageGroup m_msgGroup;
    /* 0x158 */ MessageGroup m_commonGroup;
    /* 0x16C */ void* m_iconPane;
    /* 0x170 */ void* m_mainPane;
};

static_assert(sizeof(LayoutUIControl) == 0x174);

class LayoutUIControlScaleFade : public LayoutUIControl
{
    UI_H_EXTERN_TYPEINFO(
      /* VT+0x28 */ 0x8063E924 /* VT+0x2C */
    );

public:
    LayoutUIControlScaleFade();
    virtual ~LayoutUIControlScaleFade() override;

    virtual void SolveAnim() override;
};

static_assert(sizeof(LayoutUIControlScaleFade) == 0x174);

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
