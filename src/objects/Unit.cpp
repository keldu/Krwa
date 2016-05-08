#include "Unit.h"
#include "math/Vec3.h"
#include <glm/glm.hpp>

Unitdrawcontainer Unit::drawer;

Unit::Unit(World& world): Entity(world, Vec2f(0.0f,0.0f)), drawUnit(drawer.getInstance("Unit")){
    tellWorldSenpai();
}

void Unit::draw(){
    drawUnit->draw();
}

void Unit::tellWorldSenpai(){
    m_world->addEntity(this);
    m_world->addDrawable(this);
}

void Unit::die(){
    m_world->removeEntity(this);
    m_world->removeDrawable(this);
}
