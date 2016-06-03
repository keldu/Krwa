#include "Camera.h"

#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtx/transform.hpp>
#include "math/Vec3.h"

Camera2D::Camera2D(): m_ratio(1), m_rad(1), m_ratiorad(1){

}

Camera3D::Camera3D(){

}

void Camera2D::observe(Player &a_player){
    m_player = &a_player;
}

mat4f& Camera2D::projection(){
    return viewproj;
}

void Camera2D::updateSize(float a_ratio, float a_rad){
    m_ratio = a_ratio;
    m_rad   = a_rad;
    m_ratiorad = a_rad * a_ratio;
    proj = glm::ortho( -m_ratiorad, m_ratiorad, -m_rad, m_rad );
    viewproj = proj * view;
}

void Camera2D::watchPlayer(){
    pos = m_player->getPos();

    view = glm::lookAt(Vec3f( pos.x , pos.y , 0), Vec3f( pos.x, pos.y, -1 ), Vec3f( 0, 1, 0 ) );
    viewproj = proj * view;
}

void Camera2D::updatePosition(Vec2f a_pos){

    view = glm::translate(Vec3f(-a_pos.x, -a_pos.y, 0));
    viewproj = proj * view;
}
