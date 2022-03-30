//
//  vector3.hpp
//  rayTracer
//
//  Created by Yahya Arakil on 3/28/22.
//

#ifndef vector3_hpp
#define vector3_hpp

#include <iostream>

class Vector3{
public:
    float x, y, z;
    
    Vector3();
    Vector3(float, float, float);
    
    Vector3 operator+(const Vector3&) const;
    void operator+=(const Vector3&);
    
    Vector3 operator-(const Vector3&) const;
    void operator-=(const Vector3&);
    
    Vector3 operator*(const Vector3&) const;
    
    Vector3 operator*(float) const;
    void operator*=(float);
    
    Vector3 operator/(float) const;
    void operator/=(float);
    
    float operator^(const Vector3&) const;
    
    bool operator==(const Vector3&) const;
    
    float magnitude() const;
    float angle(const Vector3&) const;
};

#endif /* vector3_hpp */
