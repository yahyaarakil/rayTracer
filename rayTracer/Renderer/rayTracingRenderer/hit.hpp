//
//  hit.hpp
//  rayTracer
//
//  Created by Yahya Arakil on 3/31/22.
//

#ifndef hit_hpp
#define hit_hpp

#include "object.hpp"

class Hit{
private:
    double t;
    Object* object;
    
public:
    Hit() = delete;
    Hit(double, Object*);
    
    double getT();
    Object* getObject();
};

#endif /* hit_hpp */
