#include "World.h"

World::World():
    collisionContainer(new Bulletcontainer(this))
    {

	}

long World::generateID(){
    return idGenerator.generateID();
}

Entity* World::searchEntityByID(long id){

    for(auto it = entities.begin(); it != entities.end(); ++it){
        if( id == (**it).getID() ){
            return &(**it);
        }
    }
    return 0L;

}

void World::UpdateDeffered(){

    for(; !updateRemove.empty(); updateRemove.pop()){
        IUpdatable* upd = updateRemove.front();
        for(auto it = updatables.begin(); it!=updatables.end(); ++it){
            if(upd == (*it)){
                std::swap(updatables.back(),(*it));
                updatables.pop_back();
                break;
            }
        }
    }

    for(; !drawRemove.empty(); drawRemove.pop()){
        IDrawable* draw = drawRemove.front();
        for(auto it = drawables.begin(); it!=drawables.end(); ++it){
            if(draw == (*it)){
                std::swap(drawables.back(),(*it));
                drawables.pop_back();
                break;
            }
        }
    }

    for(; !colRemove.empty(); colRemove.pop()){
        collisionContainer->Remove(colRemove.front());

    }


    for(;!entRemove.empty();entRemove.pop()){
        Entity* ent = entRemove.front();
        for(auto it = entities.begin(); it != entities.end(); ++it){
            if(ent == (*it).get()){
                std::swap(entities.back(), *it);
                entities.pop_back();
                break;
            }
        }
    }


    for(;!entAdd.empty();entAdd.pop()){
        entities.push_back(std::unique_ptr<Entity>(entAdd.front()));
	}

    for(; !colAdd.empty(); colAdd.pop()){
        collisionContainer->Add(colAdd.front());
    }

    for(; !drawAdd.empty(); drawAdd.pop()){
        drawables.push_back(drawAdd.front());
    }

    for(; !updateAdd.empty(); updateAdd.pop()){
        updatables.push_back(updateAdd.front());
    }
}

void World::addEntity(Entity* ent){
    entAdd.push(ent);
}

void World::removeEntity(Entity* ent){
	entRemove.push(ent);
}

void World::addCollider(ICollidable* col){
	colAdd.push(col);
}

void World::removeCollider(ICollidable* col){
	colRemove.push(col);
}

void World::addDrawable(IDrawable* draw){
	drawAdd.push(draw);
}

void World::removeDrawable(IDrawable* draw){
	drawRemove.push(draw);
}

void World::addUpdatable(IUpdatable *update){
    updateAdd.push(update);
}

void World::removeUpdatable(IUpdatable *update){
    updateRemove.push(update);
}
