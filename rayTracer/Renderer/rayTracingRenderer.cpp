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
    printf("%d, %d\n", this->scene.camera.height, this->scene.camera.width);
    for (int i = 0; i < this->scene.camera.height; ++i) {
        for (int j = 0; j < this->scene.camera.width; ++j) {
            Vector3 color = determinePixelColor(i, j);
            this->imageGenerator.writeNextPixel(color.x, color.y, color.z);
        }
    }
    return 0;
}
