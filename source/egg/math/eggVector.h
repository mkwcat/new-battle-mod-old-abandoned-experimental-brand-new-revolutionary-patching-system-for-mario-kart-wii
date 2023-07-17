#pragma once

namespace EGG
{

struct Vector2f {
    f32 x;
    f32 y;
};

static_assert(sizeof(Vector2f) == 0x8);

struct Vector3f {
    f32 x;
    f32 y;
    f32 z;
};

static_assert(sizeof(Vector2f) == 0xC);

} // namespace EGG
