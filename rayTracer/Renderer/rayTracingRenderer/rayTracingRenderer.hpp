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
#include "progress.hpp"

class RayTracingRenderer : Renderer{
public:
    RayGenerator rayGenerator;
    int validationCode;
    
    RayTracingRenderer() = delete;
    RayTracingRenderer(Scene&, double, double, ImageGenerator&);
    
    int renderToImage() override;
    
    Vector3 determinePixelColor(const Vector3&, const Object&) const;
    Hit castRay(const Vector3&, const Vector3&) const ;
};

#endif /* rayTracingRenderer_hpp */
