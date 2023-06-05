#pragma once

#include <egg/math/eggVector.h>

namespace sys
{

class MapdataStartPoint
{
public:
    struct SData {
        EGG::Vector3f position;
        EGG::Vector3f rotation;
        // Pre Revision 1830: End of structure
        s16 playerIndex;
    };

    MapdataStartPoint(const SData* data)
      : m_data(data)
    {
    }

private:
    const SData* m_data;
    s8 m_enemyPoint;
};

static_assert(sizeof(MapdataStartPoint) == 0x8);

class CourseMap
{
public:
    // Static Instance: 0x809BD6E8
    static CourseMap* s_instance;

    EXTERN_TEXT(
      0x80514B30, //
      MapdataStartPoint* GetStartPoint(u8 index)
    );
};

} // namespace sys
