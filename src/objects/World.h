#pragma once

#include <queue>
#include <vector>
#include <memory>

#include "collision/IColliderContainer.h"
#include "collision/Bulletcontainer.h"

#include "objects/Entity.h"
#include "gl/IDrawable.h"
#include "collision/ICollidable.h"
#include "logic/IUpdatable.h"
#include "logic/idmanager.h"

#include "Box2D/Box2D.h"


class Entity;
class Bulletcontainer;

class World{
public:
	World();

	void UpdateDeffered();

	void addEntity(Entity*);
	void removeEntity(Entity*);

	void addCollider(ICollidable*);
	void removeCollider(ICollidable*);

	void addDrawable(IDrawable*);
	void removeDrawable(IDrawable*);

    void addUpdatable(IUpdatable*);
    void removeUpdatable(IUpdatable*);

	//StandardContainer collisionContainer;
    std::unique_ptr<Bulletcontainer> collisionContainer;
	std::vector<IDrawable*> drawables;
    std::vector<IUpdatable*> updatables;

    long generateID();
    Entity* searchEntityByID(long id);

private:
	std::queue<Entity*> entAdd;
    std::queue<Entity*> entRemove;
    std::queue<ICollidable*> colAdd;
    std::queue<ICollidable*> colRemove;
    std::queue<IDrawable*> drawAdd;
    std::queue<IDrawable*> drawRemove;
    std::queue<IUpdatable*> updateAdd;
    std::queue<IUpdatable*> updateRemove;

	std::vector<std::unique_ptr<Entity>> entities;

    IDManager idGenerator;
};
