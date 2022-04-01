//
//  sphere.hpp
//  rayTracer
//
//  Created by Yahya Arakil on 3/29/22.
//

#ifndef sphere_hpp
#define sphere_hpp

#include "object.hpp"

class Sphere : public Object{
public:
    float radius;

    Sphere(const Material&, const Vector3&, float);
    float parameterize(const Vector3&, const Vector3&) const override;
    
private:
    float computeTiSphere(const Vector3&, const Vector3&, int) const;
};
#endif /* sphere_hpp */
