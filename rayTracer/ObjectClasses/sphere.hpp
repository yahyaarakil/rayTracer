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
    double radius;

    Sphere(const Material&, const Vector3&, double);
    double parameterize(const Vector3&, const Vector3&) const override;
    
    Vector3 getNormal(const Vector3&) const override;
private:
    double computeTiSphere(const Vector3&, const Vector3&, int) const;
};
#endif /* sphere_hpp */
