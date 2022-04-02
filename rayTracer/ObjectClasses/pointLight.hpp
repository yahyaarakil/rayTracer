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
    Vector3 intensity;
    
    PointLight(const Vector3&, const Vector3&);
    double parameterize(const Vector3&, const Vector3&) const override;
};
#endif /* pointLight_hpp */
