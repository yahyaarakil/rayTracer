//
//  pointLight.cpp
//  rayTracer
//
//  Created by Yahya Arakil on 3/28/22.
//

#include "pointLight.hpp"

PointLight::PointLight(Vector3 position, Vector3 intensity)
: Object (position) {
    this->intensity = intensity;
}

void PointLight::parameterize() {
    
}
