//
//  renderer.hpp
//  rayTracer
//
//  Created by Yahya Arakil on 3/30/22.
//

#ifndef renderer_hpp
#define renderer_hpp

#include "imageGenerator.hpp"

class Renderer {
private:
    ImageGenerator& imageGenerator;

public:
    Renderer() = delete;
    Renderer(ImageGenerator&);
    virtual int renderToImage() = 0;
};

#endif /* renderer_hpp */
