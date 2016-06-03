
#include "PlayState.h"
#include <cmath>

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "logic/Time.h"

#include "objects/Ship.h"
#include "objects/Unit.h"
#include "objects/Quadrat.h"
#include "objects/Astronaut.h"

#include "logic/kelducallback.h"

#include <iostream>

PlayState::PlayState(World& world,Render& render, Player& player): State(world,render,player){
    ;
}

void PlayState::init(){

    Time::timeloop();

    Astronaut* astro = Astronaut::createInstance( *m_world, Vec2f( 7, 0 ) );
    m_player->setControlled(astro);

    Ship* ship = Ship::createInstance( *m_world,Vec2f(0,0));
    ship->init1();
    /*
    Ship* ship2 = Ship::createInstance( *m_world,Vec2f(2,-4));
    ship2->init2();

    Ship* ship3 = Ship::createInstance( *m_world,Vec2f(-2,-4));
    ship3->init2();
    */

}

void PlayState::loop(){
    while(running && !m_render->shouldClose()){

        Time::timeloop();

        m_world->UpdateDeffered();
        //LOGIC


        //COLLISION
        m_world->collisionContainer->checkCollision();

        KelduCallback::handleInput();

        for(IUpdatable* upt : m_world->updatables){
            upt->tick();
        }
        //RENDER
        m_render->loop();

    }

}
