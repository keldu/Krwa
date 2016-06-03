#include "Entity.h"

Entity::Entity(World& a_world,Vec2f pos): transform() ,m_world(&a_world){
    transform.position = pos;
    id = a_world.generateID();
}

//Shouldn't do anything. But Every class should have a similar one
Entity* Entity::createInstance(World& a_world, Vec2f a_pos){
    //Entity* entity = new Entity(a_world, a_pos);
    return 0L;
}
