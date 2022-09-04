#pragma once

#include "Vec3.hpp"

struct AABB {
    Vec3 min;
    Vec3 max;
    bool empty;
};