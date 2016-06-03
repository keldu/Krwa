#pragma once

#include <vector>

#include <memory>
#include "objects/World.h"
#include "collision/IColliderContainer.h"
#include "Box2D/Box2D.h"
#include "collision/Kelducontactlistener.h"
#include "collision/Keldudestructionlistener.h"
#include "logic/Time.h"

class World;

class Bulletcontainer : public IColliderContainer{
public:
    Bulletcontainer(World*);

    virtual void Add(ICollidable* obj);
    virtual void Remove(ICollidable* obj);
    virtual void checkCollision();

    KelduContactListener contactlistener;
    KelduDestructionListener destructionlistener;
    b2Body *m_spacebody;
    b2World m_collisionworld;
    std::vector<ICollidable*> m_collidables;
private:
    World *m_world;
};
