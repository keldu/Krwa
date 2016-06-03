#pragma once

#include "Box2D/Box2D.h"
#include "Ship.h"
#include "gl/Systemdrawcontainer.h"

class Ship;

class Shipsystem
{
public:
    Shipsystem(int ax, int ay, int axsize, int aysize, std::string a_name, b2Body *a_body);

    int x, y;
    int xsize, ysize;

    void draw(const mat4f& proj);
    virtual void tick(Ship* ship);
protected:
    b2Fixture* m_fixture;

    Systemdrawer* m_drawer;
    static Systemdrawcontainer drawcontainer;

};
