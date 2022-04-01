//
//  object.cpp
//  rayTracer
//
//  Created by Yahya Arakil on 3/28/22.
//

#include "object.hpp"

Object::Object(const Vector3& position, const Material& material)
: position(position), material(material) {}
