#pragma once

#include "objects/Unit.h"
#include "logic/IControlable.h"
#include "Box2D/Box2D.h"
#include "collision/Astronautuserdata.h"

/*
 *TODO mach mal zeug. Container in world für aktive schiffe und inaktive schiffe, suche per ID aller objekte. ID generator und dann suche nach schiff über ID;
 */

class AstronautUserData;

class Astronaut : public Unit, public IControlable, public IUpdatable{
public:
    //IControlable
    virtual Vec2f getPos();
    virtual bool isControlled();
    virtual IControlable* takeControl(Vec3f a_color);

    virtual void movetop();
    virtual void movebot();
    virtual void moveleft();
    virtual void moveright();

    virtual void tick();

    virtual void die();

    virtual void draw(const mat4f &vp);

    static Astronaut* createInstance(World &a_world, Vec2f a_pos);

protected:

    void updateFriction();

    float m_force;
    float m_friction;

    Astronaut(World &a_world, Vec2f a_pos, b2World *a_b2world);

    virtual void tellWorldSenpai();

    b2Vec2 desMove;

    b2Body *m_body;
    b2Fixture *m_fixture, *m_floorfix;
    b2FrictionJoint *m_frictionjoint;
    Vec3f m_color;
    bool m_controlled;
    short movingHor, movingVer;

    int wait;

private:
    AstronautUserData userdata;

};
