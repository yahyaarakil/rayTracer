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
    double num = direction ^ omc;
    double uSqrt = sqrt(pow(direction ^ omc, 2) - dd * ((omc ^ omc) - pow(this->radius, 2)));
    
    return ((num *-1) + (uSqrt * pm)) / dd;
}

double Sphere::parameterize(const Vector3& origin, const Vector3& direction) const {
    double t1, t2;
    t1 = this->computeTiSphere(origin, direction, 1);
    t2 = this->computeTiSphere(origin, direction, -1);

    if (t1 < 0) {
        return t2;
    }
    else if (t2 < 0){
        return t1;
    }
    else{
        return fmin(t1, t2);
    }
}

Sphere::Sphere(const Material& material, const Vector3& position, double radius)
: Object(position, material), radius(radius){}


Vector3 Sphere::getNormal(const Vector3& point) const {
    return (point - this->position) / this->radius;
}
