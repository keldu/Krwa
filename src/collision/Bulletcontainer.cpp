#include "Bulletcontainer.h"

#include <algorithm>

Bulletcontainer::Bulletcontainer(World *a_world): m_world(a_world){

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
    ;
}
