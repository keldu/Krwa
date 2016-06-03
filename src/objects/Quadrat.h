#pragma once

#include <string>
#include "objects/Entity.h"
#include "gl/Quadratdrawcontainer.h"
#include "collision/Quadratuserdata.h"

enum QuadratState{
    Quad_Uninit = 0,
    Quad_Solid,
    Quad_Free,
    Quad_NULLNODS
};



class Quadrat{
public:

    Quadrat(int ax, int ay, QuadratState a_state, b2Body* a_body);

    void draw(const mat4f& proj);

    bool hasNeighboor(int ax, int ay);
    void vorstellen(Quadrat& potenz);

    void setState(QuadratState a_state, b2Body* a_body);
    void setAir(float a_air);

    QuadratState getState();

    void flow();

    int x, y;
    float air;
    float oldAir;

    b2Fixture* m_fixture;

protected:

    bool flowable();

    const float halfSize = 0.5f;

    std::vector<Quadrat*> nachbarn;

    QuadratState state;
    float health;

    Quadratdrawer* m_drawer;
    static Quadratdrawcontainer drawcontainer;

private:
    QuadratUserData userdata;


};
