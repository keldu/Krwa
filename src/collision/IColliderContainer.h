#pragma once

#include "collision/ICollidable.h"

class IColliderContainer{
public:
    virtual void Add(ICollidable* obj) = 0;
    virtual void Remove(ICollidable* obj) = 0;
	virtual void checkCollision() = 0;
};
