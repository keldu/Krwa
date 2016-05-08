#include "PlayState.h"
#include <cmath>

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "logic/Time.h"

#include "objects/Ship.h"

PlayState::PlayState(World& world,Render& render, Player& player): State(world,render,player){
    ;
}


void PlayState::init(){
    ;

    Time::timeloop();

    new Ship(*m_world,Vec2f(0,0));
}


void PlayState::loop(){
    while(running && !m_render->shouldClose()){

        Time::timeloop();

        m_world->UpdateDeffered();
        //LOGIC

        ;
        //COLLISION
        m_world->collisionContainer->checkCollision();

        //RENDER
        m_render->loop();


        //Input
        m_player->inputhandling(m_render->m_window);

    }

}
