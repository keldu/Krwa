#pragma once

#include <vector>
#include <string>
#include "gl/Systemdrawer.h"

class Systemdrawcontainer
{
public:
    Systemdrawcontainer();

    Systemdrawer* getdrawer(std::string a_name);
private:
    std::vector<Systemdrawer> m_drawers;

};
