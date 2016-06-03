#include "kelducallback.h"

#include <iostream>

Player* KelduCallback::m_player = 0L;

bool KelduCallback::pressed[512];

void KelduCallback::setCallbacks(Player *a_player, GLFWwindow* a_window){
    m_player = a_player;

    glfwSetKeyCallback( a_window, key_callback );
}

void KelduCallback::handleInput(){
    if(pressed[GLFW_KEY_W]){
        m_player->top();
    }
    if(pressed[GLFW_KEY_A]){
        m_player->left();
    }
    if(pressed[GLFW_KEY_S]){
        m_player->bottom();
    }
    if(pressed[GLFW_KEY_D]){
        m_player->right();
    }


}

void KelduCallback::key_callback(GLFWwindow *window, int key, int scancode, int action, int mods){

    if(key == GLFW_KEY_W){
        if(action == GLFW_PRESS){
            pressed[GLFW_KEY_W] = true;
        }else if( action == GLFW_RELEASE){
            pressed[GLFW_KEY_W] = false;
        }
    }

    if(key == GLFW_KEY_A){
        if(action == GLFW_PRESS){
            pressed[GLFW_KEY_A] = true;
        }else if( action == GLFW_RELEASE){
            pressed[GLFW_KEY_A] = false;
        }
    }

    if(key == GLFW_KEY_S){
        if(action == GLFW_PRESS){
            pressed[GLFW_KEY_S] = true;
        }else if( action == GLFW_RELEASE){
            pressed[GLFW_KEY_S] = false;
        }
    }

    if(key == GLFW_KEY_D){
        if(action == GLFW_PRESS){
            pressed[GLFW_KEY_D] = true;
        }else if( action == GLFW_RELEASE){
            pressed[GLFW_KEY_D] = false;
        }
    }

}
