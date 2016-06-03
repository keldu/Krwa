#include "Quadratdrawer.h"

#include <iostream>
#include "math/Vec3.h"
#include "math/Def.h"

#include "gl/shaders.h"
#include "gl/textureloader.h"

Quadratdrawer::Quadratdrawer(std::string a_name): name(a_name){
    init();
}

void Quadratdrawer::draw(mat4f& mvp, int texture, float green){

    glUseProgram(programID);

    glUniformMatrix4fv(matrixID, 1, GL_FALSE, &mvp[0][0]);
    glActiveTexture(GL_TEXTURE0);
    if(texture == 2){
        glBindTexture(GL_TEXTURE_2D, textureLocationID);
    }else if(texture == 1){
        glBindTexture(GL_TEXTURE_2D, textureLocationID2);
    }
    glUniform1i(texturesamplerID, 0);
    glUniform1f(colorID, green);

    glEnableVertexAttribArray(0);
    glBindBuffer(GL_ARRAY_BUFFER, bufferID);

    glVertexAttribPointer(
       0,                  // attribute 0. No particular reason for 0, but must match the layout in the shader.
       3,                  // size
       GL_FLOAT,           // type
       GL_FALSE,           // normalized?
       0,                  // stride
       (void*)0            // array buffer offset
    );

    glEnableVertexAttribArray(1);
    glBindBuffer(GL_ARRAY_BUFFER, uvID);

    glVertexAttribPointer(
        1,                                // attribute. No particular reason for 1, but must match the layout in the shader.
        2,                                // size : U+V => 2
        GL_FLOAT,                         // type
        GL_FALSE,                         // normalized?
        0,                                // stride
        (void*)0                          // array buffer offset
    );

    // Draw the triangle !

    glDrawArrays( GL_TRIANGLES, 0 , mesh.vertices.size() ); // Starting from vertex 0; 3 vertices total -> 1 triangle
    glDisableVertexAttribArray(0);
    glDisableVertexAttribArray(1);

    glBindBuffer(GL_ARRAY_BUFFER, 0);

}

void Quadratdrawer::init(){
    load();

    glGenBuffers(1, &bufferID);
    glBindBuffer(GL_ARRAY_BUFFER, bufferID);

    glBufferData(GL_ARRAY_BUFFER, sizeof(Vec3f) * mesh.vertices.size(), &mesh.vertices.front(), GL_STATIC_DRAW);
    glGenBuffers(1, &uvID);

    glBindBuffer(GL_ARRAY_BUFFER, uvID);
    glBufferData(GL_ARRAY_BUFFER, sizeof(Vec2f) * mesh.uv.size(), &mesh.uv.front(), GL_STATIC_DRAW);

    glBindBuffer(GL_ARRAY_BUFFER, 0);

    programID = LoadShadersVertFrag("Quadrat.vertexshader", "Quadrat.fragmentshader");
    matrixID = glGetUniformLocation(programID, "MVP");
    colorID = glGetUniformLocation(programID, "uColor");
    texturesamplerID = glGetUniformLocation(programID, "myTextureSampler");
}

void Quadratdrawer::load(){

    mesh.vertices.push_back(Vec3f(-0.5,-0.5, -0.6));
    mesh.vertices.push_back(Vec3f( 0.5,-0.5, -0.6));
    mesh.vertices.push_back(Vec3f( 0.5, 0.5, -0.6));
    mesh.vertices.push_back(Vec3f(-0.5,-0.5, -0.6));
    mesh.vertices.push_back(Vec3f( 0.5, 0.5, -0.6));
    mesh.vertices.push_back(Vec3f(-0.5, 0.5, -0.6));

    mesh.uv.push_back(Vec2f(0,0));
    mesh.uv.push_back(Vec2f(1,0));
    mesh.uv.push_back(Vec2f(1,1));
    mesh.uv.push_back(Vec2f(0,0));
    mesh.uv.push_back(Vec2f(1,1));
    mesh.uv.push_back(Vec2f(0,1));

    textureLocationID = loadPNG("Metalfloor.png");
    textureLocationID2 = loadPNG("pngtest.png");
}
