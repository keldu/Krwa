#pragma once

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "logic/IControlable.h"
#include "logic/Dummycontrol.h"
#include "gl/Camera.h"

class Camera2D;

class Player{
public:

    Player();

    void setControlled(IControlable* a_cont);

    void left();
    void right();
    void top();
    void bottom();

    Vec2f getPos();

private:
    IControlable* m_controlled;
    Dummycontrol m_dummy;
};
