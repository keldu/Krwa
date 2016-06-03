#pragma once

#include <string>
#include "gl/Mesh.h"

#include "GL/glew.h"
#include "GLFW/glfw3.h"
#include "math/Def.h"

class Systemdrawer
{
public:
    Systemdrawer(std::string a_name);

    void draw(mat4f& mvp);

    Mesh mesh;
    std::string name;
private:

    void load();

    GLuint bufferID, programID, matrixID, uvID;
    GLuint colorID, texturesamplerID;
    GLuint textureLocationID;
    void init();
};
