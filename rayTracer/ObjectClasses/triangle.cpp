//
//  triangle.cpp
//  rayTracer
//
//  Created by Yahya Arakil on 3/29/22.
//

#include "triangle.hpp"

//double Triangle::parameterize(const Vector3& origin, const Vector3& direction) const {
//    Vector3 normal = this->getNormal();
//    double t = ((this->a - origin) ^ normal) / (direction ^ normal);
//
//    if(t < 0)
//        return INFINITY;
//
//    Vector3 point = direction * t + origin;
//    Vector3 pa = this->a - point;
//    Vector3 pb = this->b - point;
//    Vector3 pc = this->c - point;
//
//    if (abs(pa.angle(pb) + pa.angle(pc) + pc.angle(pb) - 2*M_PI) < 0.1f) {
//        return t;
//    }
//    return INFINITY;
//}

double Triangle::parameterize(const Vector3& origin, const Vector3& direction) const {
    Vector3 amb = this->a - this->b;
    Vector3 amc = this->a - this->c;
    Vector3 amo = this->a - origin;
    double A = getDeterminant(amb, amc, direction);
    double t = getDeterminant(amb, amc, amo) / A;
    double beta = getDeterminant(amo, amc, direction) / A;
    double gamma = getDeterminant(amb, amo, direction) / A;
    
    if (beta + gamma < 1 && beta > 0 && gamma > 0 && t > 0) {
        return t;
    }
    return INFINITY;
}

Triangle::Triangle(const Vector3& position, const Vector3& a, const Vector3& b, const Vector3& c, const Material& material)
: Object(position, material), a(a), b(b), c(c){
    this->calculateNormal();
}

Vector3 Triangle::getNormal(const Vector3& point) const {
    return this->normal;
}

void Triangle::calculateNormal() {
    this->normal = (this->c - this->b) * (this->a - this->b);
    this->normal /= this->normal.magnitude();
}
