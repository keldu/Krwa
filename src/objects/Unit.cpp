#include "Unit.h"
#include "math/Vec3.h"
#include <glm/glm.hpp>
#include <glm/gtx/transform.hpp>
#include "math/Def.h"

#include <iostream>

Unitdrawcontainer Unit::drawer;

Unit::Unit(World &a_world, Vec2f a_pos): Entity(a_world, a_pos), drawUnit(drawer.getInstance("Unit")){

}

void Unit::draw(const mat4f& vp){

    const mat4f model = glm::translate( Vec3f( 0 ,0,0));
    mat4f mvp = vp * model;

    drawUnit->draw(mvp);

}

void Unit::tellWorldSenpai(){
    m_world->addEntity(this);
    m_world->addDrawable(this);
}

void Unit::die(){
    m_world->removeEntity(this);
    m_world->removeDrawable(this);
}

Unit* Unit::createInstance(World &a_world, Vec2f a_pos){
    Unit* unit = new Unit(a_world, a_pos);
    unit->tellWorldSenpai();
    return unit;
}
