#include "Kelducontactlistener.h"
#include "collision/Fixtureuserdata.h"

#include "collision/Astronautuserdata.h"
#include "collision/Shipuserdata.h"

KelduContactListener::KelduContactListener()
{

}

void KelduContactListener::BeginContact(b2Contact *contact){
    FixtureUserData* bodyUserA = (FixtureUserData*)(contact->GetFixtureA()->GetUserData());
    FixtureUserData* bodyUserB = (FixtureUserData*)(contact->GetFixtureB()->GetUserData());

    if(!bodyUserA || !bodyUserB){
        return;
    }

    if(bodyUserA->getType() == FUDtype::Floor && bodyUserB->getType() == FUDtype::Astronaut){
        astronautvsfloorEnter( contact->GetFixtureB(), contact->GetFixtureA() );
    }
    if(bodyUserB->getType() == FUDtype::Floor && bodyUserA->getType() == FUDtype::Astronaut){
        astronautvsfloorEnter( contact->GetFixtureA(), contact->GetFixtureB() );
    }
}

void KelduContactListener::EndContact(b2Contact *contact){
    FixtureUserData* bodyUserA = (FixtureUserData*)(contact->GetFixtureA()->GetUserData());
    FixtureUserData* bodyUserB = (FixtureUserData*)(contact->GetFixtureB()->GetUserData());
    if(!bodyUserA || !bodyUserB){
        return;
    }

    if(bodyUserA->getType() == FUDtype::Floor && bodyUserB->getType() == FUDtype::Astronaut){

        FixtureUserData* ship;
        if( ship = (FixtureUserData*)(contact->GetFixtureA()->GetBody()->GetUserData())){
            if( ship->getType() == FUDtype::Ship ){
                astronautvsfloorLeave( contact->GetFixtureB(), contact->GetFixtureA() );
            }
        }
    }
    if(bodyUserB->getType() == FUDtype::Floor && bodyUserA->getType() == FUDtype::Astronaut){
        FixtureUserData* ship;
        if( ship = (FixtureUserData*)(contact->GetFixtureB()->GetBody()->GetUserData())){
            if( ship->getType() == FUDtype::Ship ){
                astronautvsfloorLeave( contact->GetFixtureA(), contact->GetFixtureB() );
            }
        }
    }
}

void KelduContactListener::astronautvsfloorEnter(b2Fixture *astroFix, b2Fixture *floorFix){

    ((AstronautUserData*)(astroFix->GetUserData()))->incContacts();
    ((AstronautUserData*)(astroFix->GetUserData()))->sendID(((ShipUserData*)(floorFix->GetBody()->GetUserData()))->shipID);
    //((AstronautUserData*)(astroFix->GetUserData()))
    //((AstronautUserData*)(astroFix->GetUserData()))->sendFloorData(floorFix->GetBody()->GetLinearVelocity(), floorFix->GetBody()->GetWorldCenter(), floorFix->GetBody()->GetAngularVelocity(), floorFix->GetBody()->GetAngle());

}

void KelduContactListener::astronautvsfloorLeave(b2Fixture *astroFix, b2Fixture *floorFix){

    ((AstronautUserData*)(astroFix->GetUserData()))->decContacts();

}
