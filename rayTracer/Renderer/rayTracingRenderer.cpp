//
//  rayTracingRenderer.cpp
//  rayTracer
//
//  Created by Yahya Arakil on 3/30/22.
//

#include "rayTracingRenderer.hpp"

RayTracingRenderer::RayTracingRenderer(Scene scene, float t_min, float t_max, ImageGenerator& imageGenerator)
: Renderer(imageGenerator), rayGenerator(scene.camera, t_min, t_max), validationCode(0) {}

int RayTracingRenderer::renderToImage() {
    
    return 0;
}
