//
//  scene.hpp
//  rayTracer
//
//  Created by Yahya Arakil on 3/28/22.
//

#ifndef scene_hpp
#define scene_hpp

#include "color.hpp"

class Scene{
private:
    Color backgroundColor;
    int maxRecursionDepth;
    float shadowRayEpsilon;
    
};

#endif /* scene_hpp */
