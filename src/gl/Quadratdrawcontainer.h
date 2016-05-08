#pragma once

#include <vector>
#include "gl/Quadratdrawer.h"


class Quadratdrawcontainer{
public:
    Quadratdrawcontainer();

    Quadratdrawer* getdrawer(std::string a_name);

private:
    std::vector<Quadratdrawer> m_drawers;
};
