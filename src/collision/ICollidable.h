#pragma once

#include "math/Rectangle.h"
#include "math/Vec2.h"

class ICollidable{
public:
	virtual bool isTrigger() = 0;
    virtual void hit(ICollidable*) = 0;
};
