//
//  sphere.hpp
//  rayTracer
//
//  Created by Yahya Arakil on 3/29/22.
//

#ifndef sphere_hpp
#define sphere_hpp

#include "object.hpp"

class Sphere : public Object{
public:
    float radius;
    
    Sphere();
    Sphere(Material, Vector3, float);
    void parameterize() override;
};
#endif /* sphere_hpp */
