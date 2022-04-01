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

Hit RayTracingRenderer::castRay(const Vector3& origin, const Vector3& direction){
    float min_t = INFINITY, t;
    Object* objectP = NULL;
    for (Object* object : this->scene.objects) {
        t = object->parameterize(this->rayGenerator.position, direction);
        
        if (t < min_t){
            objectP = object;
            min_t = t;
        }
    }
    return Hit(min_t, objectP);
}

int RayTracingRenderer::renderToImage() {
    Progress progress(this->scene.camera.height * this->scene.camera.width);
    for (int i = 0; i < this->scene.camera.height; ++i) {
        for (int j = 0; j < this->scene.camera.width; ++j) {
            Vector3 direction = this->rayGenerator.computeDirection(this->rayGenerator.computeS(i, j));
            Hit hit = castRay(this->rayGenerator.position, direction);
            if (hit.getT() > this->rayGenerator.t_min && hit.getT() < this->rayGenerator.t_max) {
                this->imageGenerator.writeNextPixel(255, 255, 255);
            }
            else {
                this->imageGenerator.writeNextPixel(this->scene.backgroundColor);
            }
            
            progress.update();
        }
    }
    std::cout << std::endl;
    return 0;
}
