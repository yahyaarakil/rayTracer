//
//  scene.hpp
//  rayTracer
//
//  Created by Yahya Arakil on 3/28/22.
//

#ifndef scene_hpp
#define scene_hpp

#include "vector3.hpp"
#include "object.hpp"
#include "camera.hpp"
#include "material.hpp"
#include <vector>

class Scene{
private:
    Vector3 backgroundColor;
    Vector3 ambientLight;
    int maxRecursionDepth;
    float shadowRayEpsilon;
    
    std::vector<Material> materials;
    std::vector<Object> objects;
};

#endif /* scene_hpp */
