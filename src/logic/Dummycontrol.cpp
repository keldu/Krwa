#include "Dummycontrol.h"

Dummycontrol::Dummycontrol()
{

}

void Dummycontrol::movebot(){

}

void Dummycontrol::moveleft(){

}

void Dummycontrol::moveright(){

}

void Dummycontrol::movetop(){

}

IControlable* Dummycontrol::takeControl(Vec3f color){
    //Do nothing with that

    return this;
}

bool Dummycontrol::isControlled(){
    return true;
}

Vec2f Dummycontrol::getPos(){
    return Vec2f(0,0);
}
