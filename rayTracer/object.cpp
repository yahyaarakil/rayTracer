//
//  object.cpp
//  rayTracer
//
//  Created by Yahya Arakil on 3/28/22.
//

#include "object.hpp"

Object::Object(){}
Object::Object(float x_pos, float y_pos, float z_pos){
    this->position.x = x_pos;
    this->position.y = y_pos;
    this->position.z = z_pos;
}
Object::Object(const Vector3& position){
    this->position = position;
}
Object::Object(const Vector3& position, const Material material){
    this->position = position;
}
