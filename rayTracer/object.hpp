//
//  object.hpp
//  rayTracer
//
//  Created by Yahya Arakil on 3/28/22.
//

#ifndef object_hpp
#define object_hpp

#include "vector3.hpp"
class Object{
public:
    Vector3 position;
    Vector3 gaze;
    
    Object();
    Object(float, float, float);
    Object(float, float, float, float, float, float);
    Object(const Vector3& );
    Object(const Vector3& , const Vector3& );
    virtual ~Object() = default;
    
    virtual void print() = 0;
};

#endif /* object_hpp */
