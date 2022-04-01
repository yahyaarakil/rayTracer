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
    Vector3 a, b, c;
    Triangle(const Vector3&, const Vector3&, const Vector3&, const Vector3&, const Material&);
    float parameterize(const Vector3&, const Vector3&) const override;
    
    Vector3 getNormal() const;
};
#endif /* triangle_hpp */
