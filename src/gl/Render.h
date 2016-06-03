#pragma once


#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "gl/Camera.h"

#include "objects/World.h"

class Render{
public:
    int width, height;
    GLFWwindow* m_window;

    Render(unsigned int, unsigned int, World&);
    void init(Player& a_player);
	void loop();
	void close();
    bool shouldClose();

    Camera2D camera;
protected:
    unsigned int m_width, m_height;
	World* m_world;
    static Render* callbackhelper;
    static void window_size_callback(GLFWwindow* window, int width, int height);
};
