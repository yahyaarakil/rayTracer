//
//  renderer.hpp
//  rayTracer
//
//  Created by Yahya Arakil on 3/30/22.
//

#ifndef renderer_hpp
#define renderer_hpp

#include "imageGenerator.hpp"
#include "scene.hpp"

class Renderer {
protected:
    ImageGenerator& imageGenerator;
    Scene& scene;

public:
    Renderer() = delete;
    Renderer(Scene&, ImageGenerator&);
    virtual int renderToImage() = 0;
};

#endif /* renderer_hpp */
