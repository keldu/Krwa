#include "Entity.h"

Entity::Entity(World& a_world,Vec2f pos): transform() ,m_world(&a_world){
    transform.position = pos;
}
