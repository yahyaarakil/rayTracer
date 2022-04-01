//
//  triangle.cpp
//  rayTracer
//
//  Created by Yahya Arakil on 3/29/22.
//

#include "triangle.hpp"

void Triangle::parameterize() {
    
}

Triangle::Triangle(const Vector3& position, const Vector3& a, const Vector3& b, const Vector3& c, const Material& material)
: Object(position, material), a(a), b(b), c(c){}
