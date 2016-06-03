#include "Astronautuserdata.h"

AstronautUserData::AstronautUserData(): FixtureUserData(FUDtype::Astronaut), m_friction(0), contacts(0), floorAngleSpeed(0), floorspeed(b2Vec2(0,0)), floorposition(b2Vec2(0,0)), floorangle(0), shipID(0)
{

}

float AstronautUserData::getFriction(){
    if(contacts > 0) return 2;

    else return 0;

    //return m_friction;
}

void AstronautUserData::applyFriction(float mod){

    m_friction+=mod;
    contacts++;

}

void AstronautUserData::removeFriction(float mod){

    m_friction-=mod;
    contacts--;

}

void AstronautUserData::sendID(long a_id){
    shipID = a_id;
}

void AstronautUserData::sendFloorData(b2Vec2 floormovement, b2Vec2 floorpos, float angularveloc, float angle){
    floorangle = angle;
    floorspeed = floormovement;
    floorposition = floorpos;
    floorAngleSpeed = angularveloc;
}

int AstronautUserData::getFloorData(b2Vec2& speed, b2Vec2& position, float &anglespeed, float& angle){

    angle = floorangle;
    speed = floorspeed;
    position = floorposition;
    anglespeed = floorAngleSpeed;

    return contacts;
}

void AstronautUserData::decContacts(){
    contacts--;
}

void AstronautUserData::incContacts(){
    contacts++;
}
