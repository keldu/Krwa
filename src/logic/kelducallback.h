#pragma once

#include "logic/Player.h"

class KelduCallback
{
public:

    static void setCallbacks(Player* a_player, GLFWwindow* a_window);

    static void handleInput();

private:
    static bool pressed[512];

    KelduCallback() = default;
    static Player* m_player;

    static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);
};
