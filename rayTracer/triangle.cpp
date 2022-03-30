//
//  triangle.cpp
//  rayTracer
//
//  Created by Yahya Arakil on 3/29/22.
//

#include "triangle.hpp"

Triangle::Triangle()
: Object(){
    
}

void Triangle::print() {
    
}

Triangle::Triangle(Vector3 position, Vector3 a, Vector3 b, Vector3 c, Material material)
: Object(position){
    this->a = a;
    this->b = b;
    this->c = c;
    this->material = material;
}
