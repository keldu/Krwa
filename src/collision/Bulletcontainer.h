#pragma once

#include <vector>

#include "objects/World.h"
#include "collision/IColliderContainer.h"

class World;

class Bulletcontainer : public IColliderContainer{
public:
    Bulletcontainer(World*);

    virtual void Add(ICollidable* obj);
    virtual void Remove(ICollidable* obj);
    virtual void checkCollision();

private:
    World *m_world;
    std::vector<ICollidable*> m_collidables;

};
