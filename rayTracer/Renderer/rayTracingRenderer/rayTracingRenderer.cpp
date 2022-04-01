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

int RayTracingRenderer::renderToImage() {
    for (int i = 0; i < this->scene.camera.height; ++i) {
        for (int j = 0; j < this->scene.camera.width; ++j) {
            Vector3 direction = this->rayGenerator.computeDirection(this->rayGenerator.computeS(i, j));
            for (Object* object : this->scene.objects) {
                float t = this->rayGenerator.computeTSphere(direction, *((Sphere*)object));
                if (t > this->rayGenerator.t_min) {
                    this->imageGenerator.writeNextPixel(255, 255, 255);
                }
                else {
                    this->imageGenerator.writeNextPixel(this->scene.backgroundColor);
                }
                break;
            }
        }
    }
    return 0;
}
