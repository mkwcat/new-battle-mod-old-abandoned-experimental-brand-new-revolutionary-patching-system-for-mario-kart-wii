#pragma once

namespace System
{

class ResourceManager
{
public:
    class CourseCache
    {
    public:
        EXTERN_TEXT(
          0x80541A70, //
          void Init()
        );

        FILL(0x0, 0x24);
    };

    static_assert(sizeof(CourseCache) == 0x24);

    EXTERN_TEXT(
      0x8053FC4C, //
      static ResourceManager* CreateInstance()
    );

    FILL(0x0, 0x588);
    CourseCache m_courseCache;
    FILL(0x5AC, 0x61C);
};

static_assert(sizeof(ResourceManager) == 0x61C);

} // namespace System
