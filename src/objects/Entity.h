#pragma once

#include <string>

#include "World.h"
#include "Transform.h"


class World;

class Entity{
public:
    Entity(World&,Vec2f);

    Transform transform;
    std::string name;

    virtual void die() = 0;

protected:

	World* m_world;

	virtual void tellWorldSenpai() = 0;
};
