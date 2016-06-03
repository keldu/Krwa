#pragma once

#include <string>

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "gl/Mesh.h"
#include "math/Def.h"



class Unitdraw{
public:
    Unitdraw(std::string);

    std::string name;

    void draw(mat4f& mvp);


    Mesh mesh;

private:

    void load();

    GLuint bufferID, programID, matrixID, uvID;
    GLuint colorID, textureLocationID, texturesamplerID;

    void init();
};
