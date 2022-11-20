#include "UIControl.h"

// There is a limitation in the method we define external data in that it 1.
// can't be defined in a header file, and 2. will need to rerun the static
// constructor of the datatype. This is a little dirty, but this mod is not
// intended to be a sophisticated techincal showcase.
// We could always initialize the typeInfo as nullptr here, as StaticR.rel
// initializes after this module, but this is not something I really want to
// rely on.

#define UI_EXTERN_TYPEINFO_DERIVED(_ADDR, _OBJ, _BASE)                         \
  EXTERN_DATA(                                                                 \
    _ADDR, const nw4r::ut::detail::RuntimeTypeInfo ui::_OBJ::typeInfo(     \
                 &_BASE::typeInfo                                              \
               )                                                               \
  )

#define UI_EXTERN_TYPEINFO_ROOT(_ADDR, _OBJ)                                   \
  EXTERN_DATA(                                                                 \
    _ADDR, const nw4r::ut::detail::RuntimeTypeInfo ui::_OBJ::typeInfo(nullptr) \
  )

UI_EXTERN_TYPEINFO_ROOT(0x809C1E80, UIControl);
UI_EXTERN_TYPEINFO_DERIVED(0x809C1E84, LayoutUIControl, UIControl);
