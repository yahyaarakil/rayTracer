//
//  sphere.cpp
//  rayTracer
//
//  Created by Yahya Arakil on 3/29/22.
//

#include "sphere.hpp"

double Sphere::computeTiSphere(const Vector3& origin, const Vector3& direction, int pm) const {
    double dd = direction ^ direction;
    Vector3 omc = origin - this->position;
    double num = (direction * -1) ^ omc;
    double uSqrt = sqrt(pow(direction ^ omc, 2) - dd * ((omc ^ omc) - pow(this->radius, 2)));
    
    uSqrt *= pm;
    
    return (num + uSqrt) / dd;
}

double Sphere::parameterize(const Vector3& origin, const Vector3& direction) const {
    double t1, t2;
    t1 = this->computeTiSphere(origin, direction, 1);
    t2 = this->computeTiSphere(origin, direction, -1);
    
    return fmin(t1, t2);
}

Sphere::Sphere(const Material& material, const Vector3& position, double radius)
: Object(position, material), radius(radius){}


Vector3 Sphere::getNormal(const Vector3& point) const {
    Vector3 norm = (point - this->position) *-1 / this->radius;
    return norm / norm.magnitude();
}
