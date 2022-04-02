//
//  mesh.cpp
//  rayTracer
//
//  Created by Yahya Arakil on 3/30/22.
//

#include "mesh.hpp"

Mesh::Mesh(const Vector3& position, const Material& material)
: Object (position, material) {}

double Mesh::parameterize(const Vector3& origin, const Vector3& direction) const {
    double min_t = INFINITY, t;
    for (Triangle* triangle : this->triangles) {
        t = triangle->parameterize(origin, direction);
        
        if (t < min_t){
            min_t = t;
        }
    }
    
    return min_t;
}
