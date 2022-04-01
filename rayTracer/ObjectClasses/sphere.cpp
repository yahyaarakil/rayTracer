//
//  sphere.cpp
//  rayTracer
//
//  Created by Yahya Arakil on 3/29/22.
//

#include "sphere.hpp"


float Sphere::computeTiSphere(const Vector3& origin, const Vector3& direction, int pm) const {
    float dd = direction ^ direction;
    Vector3 omc = origin - this->position;
    float num = (direction * -1) ^ omc;
    float uSqrt = sqrt(pow(direction ^ omc, 2) - dd * ((omc ^ omc) - pow(this->radius, 2)));
    
    uSqrt *= pm;
    
    return (num + uSqrt) / dd;
}

float Sphere::parameterize(const Vector3& origin, const Vector3& direction) const {
    float t1, t2;
    t1 = this->computeTiSphere(origin, direction, 1);
    t2 = this->computeTiSphere(origin, direction, -1);
    
    return fmin(t1, t2);
}

Sphere::Sphere(const Material& material, const Vector3& position, float radius)
: Object(position, material), radius(radius){}
