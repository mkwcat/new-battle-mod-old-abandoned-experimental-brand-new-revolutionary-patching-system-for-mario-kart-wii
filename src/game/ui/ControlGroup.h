#pragma once

namespace UI
{

class Page;
class UIControl;

struct ControlGroup {
    EXTERN_TEXT(
      0x805C23E4, //
      ControlGroup()
    );

    EXTERN_TEXT(
      0x805C2400, //
      ~ControlGroup()
    );

    EXTERN_TEXT(
      0x805C2460, //
      void Init(UIControl* parent, int count)
    );

    EXTERN_TEXT(
      0x805C2620, //
      void Init(Page* page, int count)
    );

    EXTERN_TEXT(
      0x805C27DC, //
      void Set(int index, UIControl* control)
    );

    /* 0x00 */ UIControl** m_children;
    /* 0x04 */ UIControl** m_childrenSorted;
    /* 0x08 */ UIControl* m_parent;
    /* 0x0C */ UIControl* m_root;
    /* 0x10 */ int m_count;
};

} // namespace UI
