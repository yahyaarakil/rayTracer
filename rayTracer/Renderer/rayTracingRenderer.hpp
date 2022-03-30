//
//  rayTracingRenderer.hpp
//  rayTracer
//
//  Created by Yahya Arakil on 3/30/22.
//

#ifndef rayTracingRenderer_hpp
#define rayTracingRenderer_hpp

#include "rayGenerator.hpp"
#include "scene.hpp"

class RayTracingRenderer{
public:
    RayGenerator rayGenerator;
    Scene scene;
    int validationCode;
    
    RayTracingRenderer() = delete;
    RayTracingRenderer(Scene, float, float);
    
    void renderIntoImage(int);
};

#endif /* rayTracingRenderer_hpp */
