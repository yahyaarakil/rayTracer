//
//  pointLight.cpp
//  rayTracer
//
//  Created by Yahya Arakil on 3/28/22.
//

#include "pointLight.hpp"

PointLight::PointLight(int index, Vector3 position, Vector3 intensity)
: Object (position.x, position.y, position.z, 0, 0, 0) {
    this->index = index;
    this->intensity = intensity;
}

void PointLight::print() {
    
}
