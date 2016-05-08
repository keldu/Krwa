#include "Transform.h"

Transform::Transform():position(0,0), localpos(0,0), oldlocal(0,0), parent(&anchor){

}

void Transform::update(float x, float y){
    oldlocal = localpos;
    localpos.x = x;
    localpos.y = y;
}

void Transform::update(Vec2f a_p){
    oldlocal = localpos;
    localpos.x = a_p.x;
    localpos.y = a_p.y;
    position = parent->getTotal(localpos);
}

Vec2f Transform::getTotal(Vec2f loc){
    return loc + position ;
}

Transform Transform::anchor;
