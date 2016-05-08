#pragma once

#include <string>

#include "GL/glew.h"
#include "GLFW/glfw3.h"

class Quadratdrawer{
public:
    Quadratdrawer(std::string a_name);

    void draw();

    std::string name;
private:
    GLuint bufferID, programID;
    void init();
};
