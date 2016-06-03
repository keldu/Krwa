#include "Oxygengenerator.h"

Oxygengenerator::Oxygengenerator(int ax, int ay, int axsize, int aysize, b2Body *a_body): Shipsystem(ax, ay, axsize, aysize, "Oxygengenerator", a_body)
{

}

void Oxygengenerator::tick(Ship *ship){
    Quadrat* quad = ship->findQuadrat(x,y);
    if(quad == 0L){
        return;
    }

    quad->setAir( quad->air + Time::getdeltatime() * productionrate);
}
