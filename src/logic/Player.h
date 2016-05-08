#pragma once

#include <GL/glew.h>
#include <GLFW/glfw3.h>

class Player{
public:

    Player();

    void inputhandling(GLFWwindow* window);
private:
    bool pressed[512];

};
