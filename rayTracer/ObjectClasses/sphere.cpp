//
//  sphere.cpp
//  rayTracer
//
//  Created by Yahya Arakil on 3/29/22.
//

#include "sphere.hpp"

void Sphere::parameterize() {
    
}

Sphere::Sphere(const Material& material, const Vector3& position, float radius)
: Object(position, material), radius(radius){}
