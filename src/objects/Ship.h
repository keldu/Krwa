#pragma once

#include "objects/Entity.h"
#include "gl/IDrawable.h"
#include "collision/ICollidable.h"
#include "logic/IUpdatable.h"

class Ship: public Entity, public IDrawable, public ICollidable, public IUpdatable{
public:
    Ship(World& a_world, Vec2f pos);

    void die();

    void draw();

    void tick();

    bool isTrigger();
    void hit(ICollidable*);

protected:

    int m_width, m_height;
    void tellWorldSenpai();

    ;
};
