//
//  rayTracingRenderer.hpp
//  rayTracer
//
//  Created by Yahya Arakil on 3/30/22.
//

#ifndef rayTracingRenderer_hpp
#define rayTracingRenderer_hpp

#include "../renderer.hpp"
#include "rayGenerator.hpp"
#include "../../Scene/scene.hpp"
#include "hit.hpp"
#include "../../Utilities/progress.hpp"

class RayTracingRenderer : Renderer{
public:
    RayGenerator rayGenerator;
    int validationCode;
    
    RayTracingRenderer() = delete;
    RayTracingRenderer(Scene&, double, double, ImageGenerator&);
    
    int renderToImage() override;
    
    Vector3 determinePixelColor(const Vector3&, const Object&, int) const;
    Hit castRay(const Vector3&, const Vector3&) const ;
};

#endif /* rayTracingRenderer_hpp */
