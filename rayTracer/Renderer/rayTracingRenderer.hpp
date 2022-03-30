//
//  rayTracingRenderer.hpp
//  rayTracer
//
//  Created by Yahya Arakil on 3/30/22.
//

#ifndef rayTracingRenderer_hpp
#define rayTracingRenderer_hpp

#include "renderer.hpp"
#include "rayGenerator.hpp"
#include "scene.hpp"

class RayTracingRenderer : Renderer{
public:
    RayGenerator rayGenerator;
    Scene scene;
    int validationCode;
    
    RayTracingRenderer() = delete;
    RayTracingRenderer(Scene, float, float, ImageGenerator&);
    
    int renderToImage() override;
};

#endif /* rayTracingRenderer_hpp */
