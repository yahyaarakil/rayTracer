//
//  renderer.cpp
//  rayTracer
//
//  Created by Yahya Arakil on 3/30/22.
//

#include "renderer.hpp"

Renderer::Renderer(Scene& scene, ImageGenerator& imageGenerator)
: scene(scene), imageGenerator(imageGenerator){}
