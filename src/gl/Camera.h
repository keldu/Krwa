#pragma once

#include "math/Def.h"
#include "math/Vec2.h"
#include "logic/Player.h"

class Player;

enum CameraMode{
    CamMode_Player = 0
};

class Camera2D{
public:
    Camera2D();
    mat4f& projection();
    int m_mode;
    Vec2f pos;
    void watchPlayer();
    void observe(Player& a_player);
    void updateSize(float a_ratio, float a_rad);
    void updatePosition(Vec2f a_pos);
    CameraMode mode;
private:
    Player *m_player;
    float m_ratio, m_rad, m_ratiorad;
    mat4f viewproj;
    mat4f view;
    mat4f proj;
};

class Camera3D{
public:
    Camera3D();

};
