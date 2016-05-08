#include "game.h"

#include "objects/World.h"
#include "gl/Render.h"
#include "state/PlayState.h"


Game::Game()
{

}

bool Game::run(){

    World world;

    Render render(800, 600, world);
    render.init();

    Player player;

    PlayState state(world, render, player);
    state.start();

    render.close();

    //BLA placeholder TODO
    if(false){
        return true;
    }
    return false;
}

