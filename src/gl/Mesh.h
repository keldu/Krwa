#pragma once

#include <vector>
#include "math/Vec2.h"
#include "math/Vec3.h"

struct Mesh{
    std::vector<Vec3f> vertices;
    std::vector<Vec2f> uv;
};
