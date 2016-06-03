#pragma once

#include <string>

#include "World.h"
#include "Transform.h"


class World;

class Entity{
public:

    Transform transform;
    std::string name;

    virtual void die() = 0;
    long getID(){return id;}

    static Entity* createInstance(World& a_world, Vec2f a_pos);

protected:
    Entity(World&,Vec2f);

	World* m_world;

    long id;

	virtual void tellWorldSenpai() = 0;
};
