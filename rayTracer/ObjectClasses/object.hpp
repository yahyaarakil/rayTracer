//
//  object.hpp
//  rayTracer
//
//  Created by Yahya Arakil on 3/28/22.
//

#ifndef object_hpp
#define object_hpp

#include "vector3.hpp"
#include "material.hpp"

class Object{
public:
    Vector3 position;
    const Material& material;
    
    Object() = delete;
    Object(const Vector3&, const Material&);
    virtual ~Object() = default;
    
    virtual void parameterize() = 0;
};

#endif /* object_hpp */
