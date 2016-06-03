#pragma once

#include "objects/Entity.h"
#include "objects/World.h"
#include "collision/ICollidable.h"
#include "gl/IDrawable.h"
#include "gl/Unitdraw.h"
#include "gl/Unitdrawcontainer.h"

class Unit: public Entity, public IDrawable{
public:

    virtual void draw(const mat4f& vp);
    virtual void die();

    static Unit* createInstance(World &a_world, Vec2f a_pos);
protected:
    Unit(World &a_world,Vec2f a_pos);

    Unitdraw* drawUnit;

    virtual void tellWorldSenpai();

    static Unitdrawcontainer drawer;
};
