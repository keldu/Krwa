#include "Shipsystem.h"

#include "logic/KelBoxDef.h"

#include "glm/gtx/transform.hpp"

Systemdrawcontainer Shipsystem::drawcontainer;

Shipsystem::Shipsystem(int ax, int ay, int axsize, int aysize, std::string a_name, b2Body *a_body): x(ax), y(ay), xsize(axsize), ysize(aysize), m_drawer(drawcontainer.getdrawer(a_name))
{
    b2PolygonShape shape;
    shape.SetAsBox(axsize * 0.5f, aysize * 0.5f,b2Vec2(ax,ay),0);

    b2FixtureDef fixdef;
    fixdef.shape = &shape;
    fixdef.density = 1.0f;
    fixdef.filter.categoryBits = BoxCat_2;
    fixdef.filter.maskBits = BoxCat_2;

    m_fixture = a_body->CreateFixture(&fixdef);
}

void Shipsystem::tick(Ship *ship){

}

void Shipsystem::draw(const mat4f &proj){
    const mat4f model = glm::translate( Vec3f(0,0,0));
    mat4f mvp = proj * model;
    m_drawer->draw(mvp);
}
