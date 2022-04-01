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
#include "hit.hpp"

class RayTracingRenderer : Renderer{
public:
    RayGenerator rayGenerator;
    int validationCode, threadCount;
    
    RayTracingRenderer() = delete;
    RayTracingRenderer(Scene&, float, float, ImageGenerator&);
    
    void computePixel(int, int);
    int renderToImage() override;
    Hit castRay(int, int);
    
    Vector3 determinePixelColor(int, int);
};

#endif /* rayTracingRenderer_hpp */
