//
//  triangle.hpp
//  rayTracer
//
//  Created by Yahya Arakil on 3/29/22.
//

#ifndef triangle_hpp
#define triangle_hpp

#include "object.hpp"

class Triangle : public Object{
public:
    Vector3 a, b, c;
    Triangle(const Vector3&, const Vector3&, const Vector3&, const Vector3&, const Material&);
    void parameterize() override;
};
#endif /* triangle_hpp */
