#include "Player.h"


Player::Player() {
    m_controlled = m_dummy.takeControl(Vec3f(0,0,0));
}

void Player::setControlled(IControlable* a_cont){
    m_controlled = a_cont;
}

void Player::bottom(){
    m_controlled->movebot();
}

void Player::top(){
    m_controlled->movetop();
}

void Player::right(){
    m_controlled->moveright();
}

void Player::left(){
    m_controlled->moveleft();
}

Vec2f Player::getPos(){
    return m_controlled->getPos();
}
