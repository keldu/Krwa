#pragma once

#include <string>

#include <GL/glew.h>
#include <GLFW/glfw3.h>



class Unitdraw{
public:
    Unitdraw(std::string);

    std::string name;

    void draw();

private:
    GLuint bufferID, programID;
    void init();
};
