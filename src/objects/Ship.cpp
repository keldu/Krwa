#include "Ship.h"


Ship::Ship(World &a_world, Vec2f pos):Entity(a_world, pos),m_width(20), m_height(20){
    ;
}

void Ship::die(){
    m_world->removeEntity(this);
    m_world->removeDrawable(this);
    m_world->removeCollider(this);
    m_world->removeUpdatable(this);
}

void Ship::tellWorldSenpai(){
    m_world->addEntity(this);
    m_world->addDrawable(this);
    m_world->addCollider(this);
    m_world->addUpdatable(this);
}

void Ship::draw(){

}

void Ship::tick(){

}

bool Ship::isTrigger(){
    return false;
}

void Ship::hit(ICollidable *){

}

/*
void Ship::addelement(Shipelement element, int x, int y){

    if( x < m_data.size() ){
        if( y < m_data[x].size() ){
            ;
        }else{
            m_data[x].resize( (y+1) * 1.5);
        }
    }else{
        m_data.resize( (x+1) * 1.5 );
        if( y < m_data[x].size() ){
            ;
        }else{
            m_data[x].resize( (y+1) * 1.5);
        }
    }

    m_data[x][y] = element;

    /*
    if( m_data.size() > x ){
       if( m_data.at(x).size() > y ){
           m_data.at(x).at(y) = element;
       }else{
           m_data.at(x);
       }
    }else{
        for(int i = m_data.size(); i <= x ; ++i){
            m_data.push_back( std::vector<Shipelement>( m_data.at(0).size()) );
        }
    }


}

Shipelement Ship::removeelement(int x, int y){

    if( x < m_data.size() ){
        if( y < m_data[x].size() ){

        } else{
            return Shipelement();
        }
    }else{
        return Shipelement();
    }

    Shipelement toReturn = m_data[x][y];

    return toReturn;

}
*/
