//
//  sphere.cpp
//  rayTracer
//
//  Created by Yahya Arakil on 3/29/22.
//

#include "sphere.hpp"

Sphere::Sphere()
: Object(){
    
}

void Sphere::parameterize() {
    
}

Sphere::Sphere(Material material, Vector3 position, float radius)
: Object(position){
    this->radius = radius;
    this->material = material;
}
