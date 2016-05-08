#pragma once

#include "math/Vec3.h"
#include "math/Vec2.h"

class Transform{
public:
	Transform();

    void update(float, float);
    void update(Vec2f);

    Vec2f position;
    Vec2f localpos;
    Vec2f oldlocal;

    Vec2f getTotal(Vec2f loc);

    Transform* parent;
private:

    static Transform anchor;
};
