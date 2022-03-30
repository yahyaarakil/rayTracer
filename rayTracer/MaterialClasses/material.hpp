//
//  material.hpp
//  rayTracer
//
//  Created by Yahya Arakil on 3/28/22.
//

#ifndef material_hpp
#define material_hpp

#include "vector3.hpp"

class Material{
public:
    Vector3 ambient_reflectance, diffuse_reflectance, specular_reflectance, mirror_reflectance;
    float phong_exp;
    
    Material();
    Material(Vector3, Vector3, Vector3, Vector3, float);
};
#endif /* material_hpp */
