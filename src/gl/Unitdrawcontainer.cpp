#include "Unitdrawcontainer.h"

Unitdrawcontainer::Unitdrawcontainer()
{
}

Unitdraw* Unitdrawcontainer::getInstance(std::string name){
    for(Unitdraw& draw : drawer){
        if(draw.name==name){
            return &draw;
        }
    }

    return createInstance(name);
}

Unitdraw* Unitdrawcontainer::createInstance(std::string name){
    drawer.push_back(Unitdraw(name));

    return &drawer.back();
}
