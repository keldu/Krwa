#pragma once

#include <vector>
#include <string>

#include "gl/Unitdraw.h"


class Unitdrawcontainer
{
public:
    Unitdrawcontainer();

    Unitdraw* getInstance(std::string);
private:
    Unitdraw* createInstance(std::string);
    std::vector<Unitdraw> drawer;
};

