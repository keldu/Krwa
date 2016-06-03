#include "Ship.h"
#include <iostream>
#include <memory>

#include "glm/glm.hpp"
#include "glm/gtx/transform.hpp"

Ship::Ship(World &a_world, Vec2f pos, b2World *a_b2world):Entity(a_world, pos),m_width(0), m_height(0){

    container = std::make_unique<Shipcontainer>();

    b2BodyDef bodydef;
    bodydef.type = b2_dynamicBody;
    bodydef.position.Set(pos.x, pos.y);
    m_body = a_b2world->CreateBody(&bodydef);

    m_body->SetUserData(&userdata);

    userdata.shipID = id;

    container->init( m_body );

    addtryQuadrat( 0, 0);
}

void Ship::die(){

    m_world->removeEntity(this);
    m_world->removeDrawable(this);
    m_world->removeUpdatable(this);

    m_world->collisionContainer->m_collisionworld.DestroyBody(m_body);

}

void Ship::tellWorldSenpai(){

    m_world->addEntity(this);
    m_world->addDrawable(this);
    m_world->addUpdatable(this);

}

Quadrat* Ship::findQuadrat(int x, int y){
    return container->find(x,y);
}

void Ship::draw(const mat4f& vp ){

    container->draw( vp, m_body->GetPosition().x, m_body->GetPosition().y, m_body->GetAngle() );
    /*
    mat4f mvp= vp * glm::translate(Vec3f(m_body->GetPosition().x,m_body->GetPosition().y,0)) * glm::rotate( m_body->GetAngle(), Vec3f(0,0,1) );
    for(auto quad = quadrate.begin(); quad != quadrate.end(); ++quad){
        mat4f qmvp = mvp * glm::translate(Vec3f((*quad)->x,(*quad)->y,0));
        (*quad)->draw(qmvp) ;
    }
    */
}

void Ship::tick(){

    container->tick(this);


    if(container->size() <= 0){
        die();
    }
    /*
    for(auto quad = quadrate.begin(); quad != quadrate.end(); ++quad){
        (*quad)->oldAir = (*quad)->air;
    }

    for(auto quad = quadrate.begin(); quad != quadrate.end(); ++quad){
        (*quad)->flow();
    }
    */
}

void Ship::addtryQuadrat( int x, int y ){

    container->addtryQuadrat(x,y,m_body);
    /*
    bool foundNeighboor = false;

    for(auto quad = quadrate.begin(); quad != quadrate.end(); ++quad){
        if((*quad)->hasNeighboor(x,y)){
            foundNeighboor = true;
            break;
        }
    }

    if(foundNeighboor){
        addQuadrat(x,y);
    }
    */
}

void Ship::addQuadrat(int x, int y){


    container->addQuadrat(x,y,m_body);
    /*

    quadrate.push_back(std::unique_ptr<Quadrat>(new Quadrat( x, y , Quad_Free, m_body )));

    for(auto quad = quadrate.begin(); quad != quadrate.end(); ++quad){
        (*(quadrate.back())).vorstellen(**quad);
    }

    int arx[4] = { x, x, x - 1, x + 1 };
    int ary[4] = { y - 1, y + 1, y, y };

    for(int i = 0; i < 4; ++i){
        addEmptyQuadrat( arx[i], ary[i] );
    }
    */
}

void Ship::addEmptyQuadrat(int x, int y){
    container->addEmptyQuadrat(x,y,m_body);
    /*
    quadrate.push_back(std::unique_ptr<Quadrat>(new Quadrat( x, y , Quad_Empty, m_body )));
    */
}

/*
void Ship::addFurniture(int x, int y, int xsize, int ysize){
    int xmax = x + xsize;
    int ymax = y + ysize;
    for(auto quad = quadrate.begin(); quad != quadrate.end(); ++quad){
        for(int i = x; i < xmax; ++i){
            for(int j = y; j < ymax; ++j){
                ;
            }
        }
    }
}
*/

void Ship::init2(){
    m_body->SetType(b2_staticBody);
}

void Ship::init1(){

    int size = 5;

    for(int i = 0; i<=size; ++i){
        for(int j = 0; j<=size; ++j){
            if(i != 0 || j != 0){
                addtryQuadrat(i,j);
            }
        }
        for(int j = -1; j>=-size; --j){
                addtryQuadrat(i,j);
        }
    }

    for(int i = -1; i>=-size; --i){
        for(int j = 0; j<=size; ++j){
            if(i != 0 || j != 0){
                addtryQuadrat(i,j);
            }
        }
        for(int j = -1; j>=-size; --j){
                addtryQuadrat(i,j);
        }
    }

    Quadrat* found = container->find(1,1);
    if(found != 0L){
        //found->setAir(20);
    }

    container->addSystem(2,2,m_body);

    int solidsize = 4;
    for(int i = -solidsize; i <= solidsize; ++i){
        for(int j = -solidsize; j <= solidsize; ++j){
            if( ( i == solidsize || i == -solidsize || j == solidsize || j == -solidsize ) ){
                Quadrat* found = container->find(i,j);
                if(found != 0L && ( i != 0 || j != solidsize )){
                    found->setState(Quad_Solid, m_body);
                }
            }
        }
    }

}

Ship* Ship::createInstance(World &a_world, Vec2f a_pos){

    Ship* ship = new Ship( a_world, a_pos, &a_world.collisionContainer->m_collisionworld );

    ship->tellWorldSenpai();

    return ship;
}
