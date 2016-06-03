#pragma once

#include <vector>

#include "objects/Entity.h"
#include "gl/IDrawable.h"
#include "collision/ICollidable.h"
#include "logic/IUpdatable.h"
#include "objects/Quadrat.h"
#include "objects/Furniture.h"
#include "Box2D/Box2D.h"

#include "objects/Shipcontainer.h"
#include "collision/Shipuserdata.h"

class Quadrat;
class Shipcontainer;

class Ship: public Entity, public IDrawable, public IUpdatable{
public:
    void die();

    void draw(const mat4f& vp );

    void tick();

    void addtryQuadrat( int x, int y );
    void addQuadrat( int x, int y );
    void removeQuadrat( int x, int y );
    void addEmptyQuadrat( int x, int y );

    Quadrat* findQuadrat( int x, int y);

    void addFurniture(int x, int y, int xsize, int ysize);

    static Ship* createInstance( World &a_world, Vec2f a_pos );

    b2Body* m_body;

    void init1();
    void init2();

protected:

    Ship(World& a_world, Vec2f pos, b2World *a_b2world);

    //std::vector< std::unique_ptr<Quadrat> > quadrate;
    //std::vector<Furniture> furnitures;

    std::unique_ptr<Shipcontainer> container;

    int m_width, m_height;
    void tellWorldSenpai();

private:
    ShipUserData userdata;

};
