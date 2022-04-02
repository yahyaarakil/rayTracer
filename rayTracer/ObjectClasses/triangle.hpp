//
//  triangle.hpp
//  rayTracer
//
//  Created by Yahya Arakil on 3/29/22.
//

#ifndef triangle_hpp
#define triangle_hpp

#include "object.hpp"
#include "utilities.hpp"

class Triangle : public Object{
public:
    Vector3 a, b, c, normal;
    Triangle(const Vector3&, const Vector3&, const Vector3&, const Vector3&, const Material&);
    double parameterize(const Vector3&, const Vector3&) const override;
    
    Vector3 getNormal(const Vector3&) const override;
    void calculateNormal();
};
#endif /* triangle_hpp */
