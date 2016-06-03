#include "Render.h"

#include <iostream>

#include <fstream>

Render::Render(unsigned int w, unsigned int h, World& world): m_width(w), m_height(h), m_world(&world){
    callbackhelper=this;
}

void Render::init(Player& player){

    if(!glfwInit()){
        std::cerr<<"ERROR: Could not init GLFW\n";
        return;
    }

    glfwDefaultWindowHints();
    glfwWindowHint(GLFW_SAMPLES, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3); // We want OpenGL 3.3
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    m_window = glfwCreateWindow(m_width, m_height, "Game2", NULL, NULL);

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

    glfwSetInputMode( m_window, GLFW_STICKY_KEYS, GL_FALSE);

    //REMOVE FROM HERE
    GLuint VertexArrayID;
    glGenVertexArrays(1, &VertexArrayID);
    glBindVertexArray(VertexArrayID);

    camera.observe(player);
    camera.watchPlayer();
    camera.updateSize( (1.0f * m_width ) / m_height, 5);

    glfwSetWindowSizeCallback(m_window, window_size_callback);

    //BUT FIRST THIS
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    // Enable depth test
    glEnable(GL_DEPTH_TEST);
    // Accept fragment if it closer to the camera than the former one
    glDepthFunc(GL_LESS);

}

void Render::loop(){
    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    camera.watchPlayer();

    for(IDrawable* dr : m_world->drawables){
        dr->draw(camera.projection());
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

void Render::window_size_callback(GLFWwindow *window, int width, int height){
    glViewport(0,0,width,height);
    callbackhelper->camera.updateSize( (1.0f*width) / height, 10);
    callbackhelper->m_width     = width;
    callbackhelper->m_height    = height;
}

Render* Render::callbackhelper = 0;
