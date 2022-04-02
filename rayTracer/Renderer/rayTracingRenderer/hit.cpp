//
//  hit.cpp
//  rayTracer
//
//  Created by Yahya Arakil on 3/31/22.
//

#include "hit.hpp"

Hit::Hit(double t, Object* object)
: t(t), object(object){}

double Hit::getT(){
    return t;
}
Object* Hit::getObject(){
    return object;
}
