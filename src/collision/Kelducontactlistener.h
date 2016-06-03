#pragma once

#include "Box2D/Box2D.h"

class KelduContactListener : public b2ContactListener
{
public:
    virtual void BeginContact(b2Contact *contact);
    virtual void EndContact(b2Contact *contact);
    KelduContactListener();
private:
    void astronautvsfloorEnter(b2Fixture *astroFix, b2Fixture *floorFix);
    void astronautvsfloorLeave(b2Fixture *astroFix, b2Fixture *floorFix);
};
