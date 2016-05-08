#include "State.h"

State::State(World& world, Render& render, Player& player): running(true), m_world(&world), m_render(&render), m_player(&player){

}

void State::start(){
    init();
    loop();
}
