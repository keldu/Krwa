#include "Quadrat.h"

#include "glm/glm.hpp"
#include "glm/gtx/transform.hpp"

#include "logic/KelBoxDef.h"
#include "logic/Time.h"
#include <iostream>

Quadratdrawcontainer Quadrat::drawcontainer;


Quadrat::Quadrat(int ax, int ay , QuadratState a_state, b2Body* a_body): m_drawer(drawcontainer.getdrawer("Quadrat")), x(ax), y(ay), state(Quad_Uninit), air(0), oldAir(0){

    setState(a_state, a_body);

}

void Quadrat::draw(const mat4f& proj ){

    if( state == Quad_Free || state == Quad_Solid){
        const mat4f model = glm::translate( Vec3f(0,0,0));
        mat4f mvp = proj * model;
        m_drawer->draw( mvp, state, air);
    }

}

void Quadrat::setState(QuadratState a_state, b2Body* a_body){

    if(state == a_state){
        return;
    }

    if( state == Quad_Uninit || state == Quad_NULLNODS){

        if( a_state == Quad_Free || a_state == Quad_Solid){
            b2PolygonShape shape;
            b2Vec2 pos( x, y );
            shape.SetAsBox(0.5f,0.5f, pos, 0);

            b2FixtureDef fixdef;
            if(a_state == Quad_Solid){
                fixdef.filter.categoryBits = BoxCat_1 | BoxCat_2;
                fixdef.filter.maskBits = BoxCat_1 | BoxCat_2;
            }else if(a_state == Quad_Free){
                fixdef.filter.categoryBits = BoxCat_1;
                fixdef.filter.maskBits = BoxCat_1;
            }
            fixdef.shape = &shape;
            fixdef.density = 1.0f;
            fixdef.friction = 0.3f;

            m_fixture = a_body->CreateFixture(&fixdef);

            m_fixture->SetUserData(&userdata);        }

    }

    if( state == Quad_Free){
        if( a_state == Quad_Solid){
            b2Filter filter;
            filter.categoryBits = BoxCat_1 | BoxCat_2;
            filter.maskBits = BoxCat_1 | BoxCat_2;
            m_fixture->SetFilterData(filter);

            m_fixture->SetUserData(&userdata);
        }
    }

    state = a_state;
}

void Quadrat::setAir(float a_air){
    air = a_air;
    oldAir = a_air;
}

bool Quadrat::hasNeighboor(int ax, int ay){
    int diffx = ax - x;
    int diffy = ay - y;

    if(diffx == 0 && ( diffy == 1 || diffy == -1 ))
    {
        return true;
    }
    if(diffy == 0 && ( diffx == 1 || diffx == -1 )){
        return true;
    }
    return false;
}

QuadratState Quadrat::getState(){
    return state;
}

void Quadrat::vorstellen(Quadrat &potenz){

    int diffx = potenz.x - x;
    int diffy = potenz.y - y;


    if(diffx == 0 && ( diffy == 1 || diffy == -1 ))
    {
        potenz.nachbarn.push_back(this);
        nachbarn.push_back(&potenz);
    }
    else if(diffy == 0 && ( diffx == 1 || diffx == -1 ))
    {
        potenz.nachbarn.push_back(this);
        nachbarn.push_back(&potenz);
    }

}

void Quadrat::flow(){

    if(state != Quad_Free){
        return;
    }

    int gross = 5 - nachbarn.size();

    ;
    for(auto it = nachbarn.begin(); it != nachbarn.end(); ++it){
        if((oldAir > ((*it)->oldAir))){
            if( (*it)->state == Quad_Free){
                ++gross;
            }
        }
    }
    float maxflow = 50.0f;
    for(auto it = nachbarn.begin(); it != nachbarn.end(); ++it){
        if(!(*it)->flowable()){
            (*it)->setAir(0);
            continue;
        }
        if(state == Quad_NULLNODS){
            continue;
        }
        float diff = oldAir - (*it)->oldAir;
        if(diff > 0.01f){
            diff=diff/gross;
            if(diff > maxflow){
                diff = maxflow;
            }
            diff *= Time::getdeltatime() * 50;
            ((*it)->air) += diff;
            air-=diff;
        }
        if( (*it)->state == Quad_NULLNODS ){
            (*it)->setAir(0);
        }
    }
}

bool Quadrat::flowable(){
    switch(state){
    case Quad_NULLNODS:
    case Quad_Free:
        return true;
    case Quad_Uninit:
    case Quad_Solid:
    default:
        return false;
    }
}
