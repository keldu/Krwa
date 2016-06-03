#include "Astronaut.h"

#include <glm/gtx/transform.hpp>

#include <iostream>
#include "logic/KelBoxDef.h"

#include "objects/Ship.h"

Astronaut::Astronaut(World& a_world, Vec2f a_pos, b2World *a_b2world) : Unit(a_world, a_pos), m_controlled(false), m_force(1000),wait(false), desMove(b2Vec2(0,0)) {

    movingHor = 0;
    movingVer = 0;

    b2BodyDef bodydef;
    bodydef.type = b2_dynamicBody;
    bodydef.position.Set(a_pos.x, a_pos.y);
    m_body = a_b2world->CreateBody(&bodydef);

    b2PolygonShape shape;
    shape.SetAsBox(0.4f, 0.4f);

    b2FixtureDef fixdef;
    fixdef.filter.categoryBits = BoxCat_2;
    fixdef.filter.maskBits = BoxCat_2;
    fixdef.shape = &shape;
    fixdef.density = 1.0f;
    fixdef.friction = 0.3f;

    m_fixture = m_body->CreateFixture(&fixdef);

    b2FixtureDef floorFixture;
    floorFixture.filter.categoryBits = BoxCat_1;
    floorFixture.filter.maskBits = BoxCat_1;
    floorFixture.shape = &shape;
    floorFixture.density = 1.0f;
    floorFixture.friction= 0.3f;
    floorFixture.isSensor = true;

    m_floorfix = m_body->CreateFixture(&floorFixture);

    m_floorfix->SetUserData(&userdata);

}

void Astronaut::tick(){
    updateFriction();
    float vx = 0, vy = 0;

    vx = movingHor * 0.5f + m_body->GetLinearVelocity().x;
    vy = movingVer * 0.5f + m_body->GetLinearVelocity().y;

    if(movingHor == 1){

    }else if(movingHor == -1){

    }else{
        ;
    }

    if(movingVer == 1){

    }else if(movingVer == -1){

    }else{
        ;
    }

    m_body->SetLinearVelocity( b2Vec2( vx, vy ) );

    movingHor = 0;
    movingVer = 0;
}

void Astronaut::updateFriction(){
    float angle, angularveloc;
    b2Vec2 position, speed;
    int contact = userdata.getFloorData(speed, position, angularveloc, angle);
    Ship* ship = (Ship*)m_world->searchEntityByID(userdata.getID());

    if(contact <= 0){
        return;
    }
    if(ship == 0L){
        std::cerr<<"hi";
        return;
    }

    position = ship->m_body->GetPosition();
    speed = ship->m_body->GetLinearVelocity();

    angle = ship->m_body->GetAngle();
    angularveloc = ship->m_body->GetAngularVelocity();


    b2Vec2 relativePos = m_body->GetWorldCenter() - position;
    b2Vec2 anguSpeed = angularveloc * b2Vec2( -relativePos.y, relativePos.x );


    b2Vec2 cur = m_body->GetLinearVelocity();


    float friction = Time::getdeltatime() * 5;

    cur += b2Vec2((speed.x + anguSpeed.x - cur.x) * friction, (speed.y + anguSpeed.y - cur.y) * friction );

    float anglediffvel = (angularveloc - m_body->GetAngularVelocity()) * Time::getdeltatime() * 5 + m_body->GetAngularVelocity();


    m_body->SetAngularVelocity(anglediffvel);
    m_body->SetLinearVelocity(cur);
}

Astronaut* Astronaut::createInstance(World &a_world, Vec2f a_pos){
    Astronaut* astro = new Astronaut(a_world, a_pos, &a_world.collisionContainer->m_collisionworld);
    astro->tellWorldSenpai();
    return astro;
}

void Astronaut::die(){
    m_world->removeEntity(this);
    m_world->removeDrawable(this);
    m_world->removeUpdatable(this);

    m_body->DestroyFixture(m_fixture);
    m_body->DestroyFixture(m_floorfix);
    m_world->collisionContainer->m_collisionworld.DestroyBody(m_body);
}

void Astronaut::tellWorldSenpai(){
    m_world->addEntity(this);
    m_world->addDrawable(this);
    m_world->addUpdatable(this);
}

Vec2f Astronaut::getPos(){
    return Vec2f(m_body->GetPosition().x,m_body->GetPosition().y);
}

bool Astronaut::isControlled(){
    return m_controlled;
}

IControlable* Astronaut::takeControl(Vec3f a_color){
    m_color = a_color;
    return this;
}

void Astronaut::moveright(){
    movingHor = 1;
    //m_body->ApplyForce(b2Vec2( m_force * Time::getdeltatime(), 0 ), m_body->GetWorldCenter(), true);
}
void Astronaut::moveleft(){
    movingHor = -1;
    //m_body->ApplyForce(b2Vec2( -m_force * Time::getdeltatime(), 0 ), m_body->GetWorldCenter(), true);

}
void Astronaut::movebot(){
    movingVer = -1;
    //m_body->ApplyForce(b2Vec2( 0, -m_force * Time::getdeltatime() ), m_body->GetWorldCenter(), true);

}
void Astronaut::movetop(){
    movingVer = 1;
    //m_body->ApplyForce(b2Vec2( 0, m_force * Time::getdeltatime() ), m_body->GetWorldCenter(), true);
}

void Astronaut::draw(const mat4f &vp){

    const mat4f model = glm::translate( Vec3f( m_body->GetPosition().x ,m_body->GetPosition().y ,0 ) ) * glm::rotate( m_body->GetAngle() , Vec3f(0,0,1) );
    mat4f mvp = vp * model;

    drawUnit->draw(mvp);

}
