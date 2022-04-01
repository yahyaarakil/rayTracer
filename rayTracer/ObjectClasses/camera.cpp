//
//  camera.cpp
//  rayTracer
//
//  Created by Yahya Arakil on 3/28/22.
//

#include "camera.hpp"

Camera::Camera()
: Object(Vector3(0, 0, 0), Material()) {}
float Camera::parameterize(const Vector3& origin, const Vector3& direction) const {
    return INFINITY;
}
