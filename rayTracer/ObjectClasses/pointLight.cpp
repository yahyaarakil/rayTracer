//
//  pointLight.cpp
//  rayTracer
//
//  Created by Yahya Arakil on 3/28/22.
//

#include "pointLight.hpp"

PointLight::PointLight(const Vector3& position, const Vector3& intensity)
: Object (position, Material()), intensity(intensity) {}

double PointLight::parameterize(const Vector3& origin, const Vector3& direction) const {
    return -1;
}
