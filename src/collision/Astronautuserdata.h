#pragma once

#include "collision/Fixtureuserdata.h"

#include "Box2D/Box2D.h"

class Astronaut;

class AstronautUserData : public FixtureUserData
{
public:
    AstronautUserData();

    void applyFriction(float mod), removeFriction(float mod);
    void sendFloorData(b2Vec2 floormovement, b2Vec2 floorpos, float angularveloc, float angle);
    float getFriction();
    int getFloorData(b2Vec2& speed, b2Vec2& position, float& anglespeed, float& angle);

    void incContacts();
    void decContacts();

    void sendID(long a_id);
    long getID(){return shipID; }

private:

    b2Vec2 floorspeed, floorposition;
    float floorangle, floorAngleSpeed;
    b2Body *m_ownerbody;
    float m_friction;

    long shipID;
    int contacts;
};
