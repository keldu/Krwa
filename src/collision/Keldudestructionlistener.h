#pragma once

#include "Box2D/Box2D.h"
#include "collision/Fixtureuserdata.h"


class KelduDestructionListener
{
public:
    KelduDestructionListener();

    void SayGoodBye(b2Fixture *fixture){
        FixtureUserData *fixdata = (FixtureUserData*)(fixture->GetUserData());
        if(fixdata == 0L){
            return;
        }


    }

    void SayGoodBye(b2Joint *joint){

    }
};
