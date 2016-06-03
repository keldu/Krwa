#pragma once

#include "math/Def.h"
#include <vector>
#include <memory>
#include "objects/Quadrat.h"
#include "Box2D/Box2D.h"
#include "objects/Shipsystem.h"
#include "objects/Ship.h"

class Shipsystem;
class Ship;

class Shipcontainer
{
public:
    Shipcontainer();

    void init(b2Body* a_body);

    void draw(const mat4f& vp, float x, float y, float angle );

    void addtryQuadrat( int x, int y, b2Body* a_body );
    void addQuadrat( int x, int y, b2Body* a_body );
    void removeQuadrat( int x, int y );
    void addEmptyQuadrat( int x, int y, b2Body* a_body );
    bool exists(int x, int y);
    Quadrat* find(int x, int y);

    void addSystem(int x, int y, b2Body *a_body);

    Shipsystem* findSystem(int x, int y);

    void tick(Ship *ship);
    size_t size();

private:
    std::vector< std::unique_ptr<Quadrat> > quadrate;
    std::vector< std::unique_ptr<Shipsystem> > systems;
    //std::vector<Furniture> furnitures;
};
