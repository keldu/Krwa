#pragma once

#include "objects/Entity.h"
#include "objects/World.h"
#include "collision/ICollidable.h"
#include "gl/IDrawable.h"
#include "gl/Unitdraw.h"
#include "gl/Unitdrawcontainer.h"

class Unit: public Entity, public IDrawable{
public:
	Unit(World&);

    void draw();

protected:

    Unitdraw* drawUnit;

    void tellWorldSenpai();
    void die();

    static Unitdrawcontainer drawer;
};
