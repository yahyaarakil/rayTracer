//
//  camera.cpp
//  rayTracer
//
//  Created by Yahya Arakil on 3/28/22.
//

#include "camera.hpp"

Camera::Camera() : Object(){}
Camera::Camera(float x_pos, float y_pos, float z_pos,
               float x_gaze, float y_gaze, float z_gaze,
               float x_up, float y_up, float z_up,
               float left, float right, float bottom, float top,
               float distance, int width, int height)
: Object (x_pos, y_pos, z_pos, x_gaze, y_gaze, z_gaze) {
    this->up.x = x_up;
    this->up.y = y_up;
    this->up.z = z_up;
    
    this->left = left;
    this->right = right;
    this->bottom = bottom;
    this->top = top;
    
    this->distance = top;
    this->width = width;
    this->height = height;
}
