#pragma once

#include <Util/Handler.h>

namespace UI
{

class Page;
class UIControl;

class ControlGroup
{
public:
    ControlGroup();
    ~ControlGroup();

    void Create(UIControl* parent, u32 capacity);
    void Create(Page* page, u32 capacity);

    void Set(u32 index, UIControl* control);
    UIControl* Get(u32 index);

    void Debug();

    void Init();
    void Calc();
    void Draw();
    void Solve();
    void Transform(Handler<UIControl*> function);

    /* 0x00 */ UIControl** m_children;
    /* 0x04 */ UIControl** m_childrenSorted;
    /* 0x08 */ UIControl* m_parent;
    /* 0x0C */ Page* m_page;
    /* 0x10 */ u32 m_count;
};

static_assert(sizeof(ControlGroup) == 0x14);

} // namespace UI
