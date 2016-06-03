#pragma once

#include <string>
#include <vector>

#include "GL/glew.h"
#include "GLFW/glfw3.h"
#include "gl/Mesh.h"
#include "math/Def.h"



class Quadratdrawer{
public:
    Quadratdrawer(std::string a_name);

    void draw(mat4f& mvp, int texture, float green);

    Mesh mesh;
    std::string name;
private:

    void load();

    GLuint bufferID, programID, matrixID, uvID;
    GLuint colorID, texturesamplerID;
    GLuint textureLocationID, textureLocationID2;
    void init();
};
