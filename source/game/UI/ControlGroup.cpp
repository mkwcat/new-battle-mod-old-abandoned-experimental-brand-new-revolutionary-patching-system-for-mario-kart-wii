#include "ControlGroup.h"

namespace UI
{

EXTERN_TEXT(
  0x805C23E4, //
  ControlGroup::ControlGroup()
);

EXTERN_TEXT(
  0x805C2400, //
  ControlGroup::~ControlGroup()
);

EXTERN_TEXT(
  0x805C2460, //
  void ControlGroup::Create(UIControl* parent, u32 count)
);

EXTERN_TEXT(
  0x805C2620, //
  void ControlGroup::Create(Page* page, u32 count)
);

EXTERN_TEXT(
  0x805C27DC, //
  void ControlGroup::Set(u32 index, UIControl* control)
);

EXTERN_TEXT(
  0x805C2804, //
  void ControlGroup::Debug()
);

EXTERN_TEXT(
  0x805C2868, //
  void ControlGroup::Init()
);

EXTERN_TEXT(
  0x805C28D8, //
  void ControlGroup::Calc()
);

EXTERN_TEXT(
  0x805C2948, //
  void ControlGroup::Draw()
);

EXTERN_TEXT(
  0x805C2A5C, //
  void ControlGroup::Solve()
);

EXTERN_TEXT(
  0x805C2AC0, //
  UIControl* ControlGroup::Get(u32 index)
);

EXTERN_TEXT(
  0x805C2AD0, //
  void ControlGroup::Transform(Handler<UIControl*> function)
);

} // namespace UI
