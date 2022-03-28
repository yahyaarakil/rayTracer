//
//  pointLight.hpp
//  rayTracer
//
//  Created by Yahya Arakil on 3/28/22.
//

#ifndef pointLight_hpp
#define pointLight_hpp

#include "object.hpp"

class PointLight : public Object{
public:
    int index;
    Vector3 intensity;
    
    PointLight(int, Vector3, Vector3);
    void print() override;
};
#endif /* pointLight_hpp */
