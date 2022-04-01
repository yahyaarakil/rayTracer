//
//  rayTracingRenderer.cpp
//  rayTracer
//
//  Created by Yahya Arakil on 3/30/22.
//

#include "rayTracingRenderer.hpp"

RayTracingRenderer::RayTracingRenderer(Scene& scene, float t_min, float t_max, ImageGenerator& imageGenerator)
: Renderer(scene, imageGenerator), rayGenerator(scene.camera, t_min, t_max), validationCode(0) {}

Vector3 RayTracingRenderer::determinePixelColor(int i, int j){
    return Vector3(255, 0, 0);
}

Hit RayTracingRenderer::castRay(const Vector3& direction){
    float t_min = INFINITY, t;
    Object *object = NULL;
    for (Object* objectPtr : this->scene.objects) {
        t = objectPtr->parameterize(this->rayGenerator.position, direction);
        if(t < t_min){
            t_min = t;
            object = objectPtr;
        }
    }
    return Hit(t_min, object);
}

void RayTracingRenderer::computePixel(int i, int j){
    Vector3 direction = this->rayGenerator.computeDirection(this->rayGenerator.computeS(i, j));
    Hit hit = castRay(direction);
//    float t = this->castRay2(direction);
    if (hit.getObject() != NULL && hit.getT() > this->rayGenerator.t_min && hit.getT() < this->rayGenerator.t_max) { // hit
        this->imageGenerator.writeNextPixel(255, 255, 255);
    }
    else {
        this->imageGenerator.writeNextPixel(this->scene.backgroundColor);
    }
}

int RayTracingRenderer::renderToImage() {
    for (int i = 0; i < this->scene.camera.height; ++i) {
        for (int j = 0; j < this->scene.camera.width; ++j) {
            this->computePixel(i, j);
        }
    }
    return 0;
}

