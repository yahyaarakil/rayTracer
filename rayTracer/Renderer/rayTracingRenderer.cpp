//
//  rayTracingRenderer.cpp
//  rayTracer
//
//  Created by Yahya Arakil on 3/30/22.
//

#include "rayTracingRenderer.hpp"

RayTracingRenderer::RayTracingRenderer(Scene scene, float t_min, float t_max){
    this->rayGenerator = RayGenerator(scene.camera, t_min, t_max);
    this->validationCode = 0;
}

void renderIntoImage(int);
