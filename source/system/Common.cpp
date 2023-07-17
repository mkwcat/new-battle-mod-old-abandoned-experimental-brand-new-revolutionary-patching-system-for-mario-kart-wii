#include "Common.h"
#include <revolution/os.h>

void __AssertFail(const char* file, u32 line, const char* expression)
{
    OSPanic(file, line, "%s", expression);
}
