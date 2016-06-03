#include <iostream>

#include "game.h"

int main()
{


    Game game;
    if(game.run()){
        std::cerr<<"An error occured";
        return 1;
    }
    return 0;
}

