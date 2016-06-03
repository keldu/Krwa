#include "game.h"

#include "objects/World.h"
#include "gl/Render.h"
#include "state/PlayState.h"
#include "logic/kelducallback.h"

#include <iostream>

Game::Game()
{

}

bool Game::run(){



    World world;

    Render render(800, 600, world);
    Player player;
    render.init(player);

    KelduCallback::setCallbacks(&player,render.m_window);

    PlayState state(world, render, player);
    state.start();

    render.close();

    //BLA placeholder TODO
    if(false){
        return true;
    }
    return false;
}

