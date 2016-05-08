#pragma once


#include <GL/glew.h>
#include <GLFW/glfw3.h>


#include "objects/World.h"

class Render{
public:
    int width, height;
    GLFWwindow* m_window;

    Render(unsigned int, unsigned int, World&);
    void init();
	void loop();
	void close();
    bool shouldClose();
protected:
    unsigned int m_width, m_height;
    GLuint vertexbuffer, programID;
	World* m_world;
};
