//
//  triangle.cpp
//  rayTracer
//
//  Created by Yahya Arakil on 3/29/22.
//

#include "triangle.hpp"

float Triangle::parameterize(const Vector3& origin, const Vector3& direction) const {
    Vector3 normal = this->getNormal();
    float t = ((this->a - origin) ^ normal) / (direction ^ normal);
    
    Vector3 point = direction * t + origin;
    Vector3 pa = this->a - point;
    Vector3 pb = this->b - point;
    Vector3 pc = this->c - point;
    
    if (abs(pa.angle(pb) + pa.angle(pc) + pc.angle(pb) - 2*M_PI) < 0.00001) {
        return t;
    }
    return INFINITY;
}

Triangle::Triangle(const Vector3& position, const Vector3& a, const Vector3& b, const Vector3& c, const Material& material)
: Object(position, material), a(a), b(b), c(c){}

Vector3 Triangle::getNormal() const {
    return (this->c - this->b) * (this->a - this->b);
}
