#include "Player.h"



Player::Player(){

}

void Player::inputhandling(GLFWwindow *window){
    int state;

    state = glfwGetKey(window, GLFW_KEY_A);

    if(state == GLFW_PRESS){
        pressed[GLFW_KEY_A] = true;
    }else if(state == GLFW_RELEASE){
        pressed[GLFW_KEY_A] = false;
    }

    if(pressed[GLFW_KEY_A]){

    }

    state = glfwGetKey(window, GLFW_KEY_D);

    if(state == GLFW_PRESS){
        pressed[GLFW_KEY_D] = true;
    }else if(state == GLFW_RELEASE){
        pressed[GLFW_KEY_D] = false;
    }

    if(pressed[GLFW_KEY_D]){

    }

    state = glfwGetKey(window, GLFW_KEY_W);

    if(state == GLFW_PRESS){
        pressed[GLFW_KEY_W] = true;
    }else if(state == GLFW_RELEASE){
        pressed[GLFW_KEY_W] = false;
    }

    if(pressed[GLFW_KEY_W]){

    }

    state = glfwGetKey(window, GLFW_KEY_S);

    if(state == GLFW_PRESS){
        pressed[GLFW_KEY_S] = true;
    }else if(state == GLFW_RELEASE){
        pressed[GLFW_KEY_S] = false;
    }

    if(pressed[GLFW_KEY_S]){

    }
}
