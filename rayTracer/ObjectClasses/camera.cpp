//
//  camera.cpp
//  rayTracer
//
//  Created by Yahya Arakil on 3/28/22.
//

#include "camera.hpp"

void Camera::print() {
    
}

void Camera::computeM() {
    this->m = this->position + this->gaze * this->distance;
}
void Camera::computeV() {
    this->v = this->up * this->gaze;
}
void Camera::computeQ() {
    this->q = this->m  + this->up * this->left + this->v * this->top;
}
void Camera::computeSuSv() {
    this->su = (this->right - this->left) / this->width;
    this->sv = (this->top - this->bottom) / this->height;
}

Vector3 Camera::computeS(int i, int j) const {
    return this->q + this->up * (this->su * (i+0.5f))  - this->v * (this->sv * (j+0.5f));
}
