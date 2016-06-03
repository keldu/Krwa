#pragma once

#include "logic/IControlable.h"

class Dummycontrol : public IControlable {
public:
    Dummycontrol();
    virtual Vec2f getPos();
    virtual bool isControlled();
    virtual IControlable* takeControl(Vec3f);
    virtual void movetop();
    virtual void movebot();
    virtual void moveleft();
    virtual void moveright();
};
