//
//  rayGenerator.cpp
//  rayTracer
//
//  Created by Yahya Arakil on 3/30/22.
//

#include "rayGenerator.hpp"

RayGenerator::RayGenerator(Camera camera, double t_min, double t_max)
: t_min(t_min), t_max(t_max){
    this->position = camera.position;
    this->gaze = camera.gaze;
    this->up = camera.up;
    this->left = camera.left;
    this->right = camera.right;
    this->bottom = camera.bottom;
    this->top = camera.top;
    this->distance = camera.distance;
    this->width = camera.width;
    this->height = camera.height;
    
    this->computeVectors();
}
RayGenerator::RayGenerator(){}

void RayGenerator::computeW() {
    this->w = this->gaze * -1;
}
void RayGenerator::computeU() {
    this->u = this->w * this->up;
    this->u *= -1;
}
void RayGenerator::computeV() {
    this->v = this->up;
}
void RayGenerator::computeM() {
    this->m = this->position + this->gaze * this->distance;
}
void RayGenerator::computeQ() {
    this->q = this->m  + this->u * this->left + this->v * this->top;
}
void RayGenerator::computeSuSv() {
    this->su = (this->right - this->left) / this->width;
    this->sv = (this->top - this->bottom) / this->height;
}
void RayGenerator::computeVectors() {
    this->computeW();
    this->computeU();
    this->computeV();
    this->computeM();
    this->computeQ();
    this->computeSuSv();
}

Vector3 RayGenerator::computeDirection(int i, int j) const {
    Vector3 s = this->q + this->u * (this->su * (i+0.5f))  - this->v * (this->sv * (j+0.5f));
    Vector3 direction = s - this->position;
    
    direction /= direction.magnitude();
    return direction;
}
Vector3 RayGenerator::computeR(double t, const Vector3& direction) const {
    return this->position + direction * t;
}
