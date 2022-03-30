//
//  rayTracingRenderer.cpp
//  rayTracer
//
//  Created by Yahya Arakil on 3/30/22.
//

#include "rayTracingRenderer.hpp"

RayTracingRenderer::RayTracingRenderer(Scene scene){
    this->rayGenerator = RayGenerator(scene.camera);
    this->validationCode = 0;
}

void renderIntoImage(int);
