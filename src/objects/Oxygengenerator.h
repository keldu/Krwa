#pragma once

#include "objects/Shipsystem.h"

class Oxygengenerator : public Shipsystem
{
public:
    Oxygengenerator(int ax, int ay, int axsize, int aysize, b2Body *a_body);
    void tick(Ship *ship);
protected:
    const float productionrate = 1.0f;
};
