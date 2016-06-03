#include "Shipcontainer.h"

#include "glm/gtx/transform.hpp"
#include "objects/Oxygengenerator.h"

Shipcontainer::Shipcontainer()
{

}

void Shipcontainer::init(b2Body* a_body){
    addEmptyQuadrat(0, 0, a_body);
}

void Shipcontainer::draw(const mat4f& vp, float x, float y, float angle ){

    mat4f mvp= vp * glm::translate(Vec3f(x, y, 0)) * glm::rotate( angle , Vec3f(0,0,1) );
    for(auto quad = quadrate.begin(); quad != quadrate.end(); ++quad){
        mat4f qmvp = mvp * glm::translate(Vec3f((*quad)->x,(*quad)->y,0));
        (*quad)->draw(qmvp);
    }
    for(auto sys = systems.begin(); sys != systems.end(); ++sys){
        mat4f qmvp = mvp * glm::translate(Vec3f((*sys)->x,(*sys)->y,0));
        (*sys)->draw(qmvp);
    }

}

void Shipcontainer::addtryQuadrat( int x, int y, b2Body* a_body ){

    addQuadrat(x,y, a_body);

}

size_t Shipcontainer::size(){
    return quadrate.size();
}

void Shipcontainer::tick(Ship *ship){

    for(auto sys = systems.begin(); sys != systems.end(); ++sys){
        (*sys)->tick(ship);
    }

    for(auto quad = quadrate.begin(); quad != quadrate.end(); ++quad){
        (*quad)->oldAir = (*quad)->air;
    }

    for(auto quad = quadrate.begin(); quad != quadrate.end(); ++quad){
        (*quad)->flow();
    }
}

Quadrat* Shipcontainer::find(int x, int y){
    for(auto quad = quadrate.begin(); quad != quadrate.end(); ++quad){
        if( (*quad)->x == x && (*quad)->y == y ){
            return &(**quad);
        }
    }
    return 0L;
}

Shipsystem* Shipcontainer::findSystem(int x, int y){
    for(auto sys = systems.begin(); sys != systems.end(); ++sys){
        if( (*sys)->x == x && (*sys)->y == y ){
            return &(**sys);
        }
    }
    return 0L;
}

void Shipcontainer::addQuadrat(int x, int y, b2Body* a_body){

    //quadrate.push_back(std::unique_ptr<Quadrat>(new Quadrat( x, y , Quad_Free, a_body )));


    Quadrat* adder = find( x ,y );
    if(adder == 0L){
        return;
    }
    if( adder->getState() == Quad_NULLNODS){
        adder->setState(Quad_Free, a_body);
    }else{
        return;
    }

    /*

    for(auto quad = quadrate.begin(); quad != quadrate.end(); ++quad){
        adder->vorstellen(**quad);
    }

    */

    int arx[4] = { x, x, x - 1, x + 1 };
    int ary[4] = { y - 1, y + 1, y, y };

    for(int i = 0; i < 4; ++i){
        if(!exists(arx[i],ary[i])){
            addEmptyQuadrat( arx[i], ary[i], a_body );
        }
    }
}

bool Shipcontainer::exists(int x, int y){
    for(auto quad = quadrate.begin(); quad != quadrate.end(); ++quad){
        if( (*quad)->x == x && (*quad)->y == y){
            return true;
        }
    }
    return false;
}

void Shipcontainer::addEmptyQuadrat(int x, int y, b2Body* a_body){
    quadrate.push_back(std::unique_ptr<Quadrat>(new Quadrat( x, y , Quad_NULLNODS, a_body )));
    for(auto quad = quadrate.begin(); quad != quadrate.end(); ++quad){
        quadrate.back()->vorstellen(**quad);
    }
}

void Shipcontainer::addSystem(int x, int y, b2Body *a_body){
    systems.push_back(std::unique_ptr<Shipsystem>( new Oxygengenerator(x,y,1,1,a_body)));
}
