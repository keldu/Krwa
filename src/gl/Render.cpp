#include "Render.h"

#include <iostream>

#include <fstream>

Render::Render(unsigned int w, unsigned int h, World& world): m_width(w), m_height(h), m_world(&world){

}

void Render::init(){

    if(!glfwInit()){
        std::cerr<<"ERROR: Could not init GLFW\n";
        return;
    }

    glfwDefaultWindowHints();
    //glfwWindowHint(GLFW_SAMPLES, 4); // 4x antialiasing
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3); // We want OpenGL 3.0
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);
    //glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE); //We don't want the old OpenGL

    m_window = glfwCreateWindow(m_width, m_height, "Game1", NULL, NULL);

    if( m_window == NULL){
        std::cerr<<"Failed to create Window\n";
        glfwTerminate();
        return;
    }

    glfwMakeContextCurrent( m_window );
    glewExperimental = true;
    if(glewInit() != GLEW_OK){
        std::cerr<<"Failed to init GLEW\n";
        return;
    }
    glfwSetInputMode( m_window, GLFW_STICKY_KEYS, GL_TRUE);

    //REMOVE FROM HERE
    GLuint VertexArrayID;
    glGenVertexArrays(1, &VertexArrayID);
    glBindVertexArray(VertexArrayID);


    //BUT FIRST THIS
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

    // Enable depth test
    glEnable(GL_DEPTH_TEST);
    // Accept fragment if it closer to the camera than the former one
    glDepthFunc(GL_LESS);
}

void Render::loop(){
    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    for(IDrawable* dr : m_world->drawables){
        dr->draw();
    }

    glfwSwapBuffers( m_window );
    glfwPollEvents();
}

void Render::close(){
    glfwTerminate();
}

bool Render::shouldClose(){
    return glfwWindowShouldClose(m_window) != 0;
}

