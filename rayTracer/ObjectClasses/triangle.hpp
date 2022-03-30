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
    
    Triangle();
    Triangle(Vector3, Vector3, Vector3, Vector3, Material);
    void parameterize() override;
};
#endif /* triangle_hpp */
