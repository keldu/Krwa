#pragma once


#include <string>
#include "objects/Entity.h"
#include "gl/Quadratdrawcontainer.h"

class Quadrat : public Entity{
public:
    Quadrat(World& a_world, Vec2f& a_pos);


protected:
    static Quadratdrawcontainer drawcontainer;
private:
    static std::string m_name;
};
