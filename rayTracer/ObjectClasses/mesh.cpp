//
//  mesh.cpp
//  rayTracer
//
//  Created by Yahya Arakil on 3/30/22.
//

#include "mesh.hpp"

Mesh::Mesh(const Vector3& position, const Material& material)
: Object (position, material) {}

float Mesh::parameterize(const Vector3& origin, const Vector3& direction) const {
    return INFINITY;
}
