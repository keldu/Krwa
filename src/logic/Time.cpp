#include "Time.h"

#include "GL/glew.h"
#include "GLFW/glfw3.h"

float Time::time = 0;
float Time::oldtime = 0;
float Time::deltatime;

void Time::timeloop(){
    oldtime = time;

    time = glfwGetTime();

    deltatime = time - oldtime;
}

float Time::getdeltatime(){
    return deltatime;
}

float Time::gettime(){
    return time;
}
