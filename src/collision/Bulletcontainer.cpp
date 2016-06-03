#include "Bulletcontainer.h"

#include <algorithm>



Bulletcontainer::Bulletcontainer(World *a_world): m_collisionworld(b2Vec2(0,0)), m_world(a_world){
    m_collisionworld.SetContactListener(&contactlistener);

    b2BodyDef spacedef;
    spacedef.gravityScale = 0.0f;
    spacedef.fixedRotation = true;
    spacedef.allowSleep = true;
    spacedef.angle = 0;
    spacedef.type = b2_staticBody;

    m_spacebody = m_collisionworld.CreateBody(&spacedef);
}

void Bulletcontainer::Add(ICollidable *obj){
    m_collidables.push_back(obj);
}

void Bulletcontainer::Remove(ICollidable *obj){
    for(auto it = m_collidables.begin(); it!=m_collidables.end(); ++it){
        if(*it == obj){
            std::swap(*it,m_collidables.back());
            m_collidables.pop_back();
        }
    }
}

void Bulletcontainer::checkCollision(){
    m_collisionworld.Step(Time::getdeltatime(),10,10);
}
