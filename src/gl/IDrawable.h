#pragma once

#include "math/Def.h"

class IDrawable{
public:
    virtual void draw(const mat4f& vp ) = 0;
};
