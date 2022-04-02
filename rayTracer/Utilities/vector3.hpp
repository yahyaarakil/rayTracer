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
    double x, y, z;
    
    Vector3();
    Vector3(double, double, double);
    
    Vector3 operator+(const Vector3&) const;
    void operator+=(const Vector3&);
    
    Vector3 operator-(const Vector3&) const;
    void operator-=(const Vector3&);
    
    Vector3 operator*(const Vector3&) const; // cross product
    
    Vector3 operator&(const Vector3&) const; // elementwise product
    void operator&=(const Vector3&); // elementwise product
    
    Vector3 operator*(double) const;
    void operator*=(double);
    
    Vector3 operator/(double) const;
    void operator/=(double);
    
    double operator^(const Vector3&) const; // dot product
    
    bool operator==(const Vector3&) const;
    
    double magnitude() const;
    double angle(const Vector3&) const;
};

#endif /* vector3_hpp */
