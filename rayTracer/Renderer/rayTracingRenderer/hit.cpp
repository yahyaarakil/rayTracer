//
//  hit.cpp
//  rayTracer
//
//  Created by Yahya Arakil on 3/31/22.
//

#include "hit.hpp"

Hit::Hit(float t, Object& object)
: t(t), object(object){}

float Hit::getT(){
    return t;
}
Object& Hit::getObject(){
    return object;
}
