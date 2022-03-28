//
//  vector3.cpp
//  rayTracer
//
//  Created by Yahya Arakil on 3/28/22.
//

#include "vector3.hpp"
#include <cmath>

Vector3::Vector3(){
    this->x = 0;
    this->y = 0;
    this->z = 0;
}

Vector3::Vector3(float x, float y, float z){
    this->x = x;
    this->y = y;
    this->z = z;
}

Vector3 Vector3::operator+(const Vector3& other) const {
    return Vector3(this->x + other.x, this->y + other.y, this->z + other.z);
}
void Vector3::operator+=(const Vector3& other) {
    this->x += other.x;
    this->y += other.y;
    this->z += other.z;
}

Vector3 Vector3::operator-(const Vector3& other) const {
    return Vector3(this->x - other.x, this->y - other.y, this->z - other.z);
}
void Vector3::operator-=(const Vector3& other) {
    this->x -= other.x;
    this->y -= other.y;
    this->z -= other.z;
}

Vector3 Vector3::operator*(const Vector3& other) const {
    return Vector3(
       this->y * other.z - this->z * other.y,
       -1 * (this->x * other.z - this->z * other.x),
       this->x * other.y - this->y * other.x
   );
}

Vector3 Vector3::operator*(float scalar) const {
    return Vector3(this->x * scalar, this->y * scalar, this->z * scalar);
}
void Vector3::operator*=(float scalar) {
    this->x *= scalar;
    this->y *= scalar;
    this->z *= scalar;
}

Vector3 Vector3::operator/(float scalar) const {
    return Vector3(this->x / scalar, this->y / scalar, this->z / scalar);
}
void Vector3::operator/=(float scalar) {
    this->x /= scalar;
    this->y /= scalar;
    this->z /= scalar;
}

float Vector3::operator^(const Vector3& other) const {
    return this->x * other.x + this->y * other.y + this->z * other.z;
}

bool Vector3::operator==(const Vector3& other) const {
    return (this->x == other.x) && (this->y == other.y) && (this->z * other.z);
}

float Vector3::magnitude() const {
    return sqrt(this->x * this->x +this->y * this->y +this->z * this->z);
}
float Vector3::angle(const Vector3& other) const {
    return acos(((*this)^other) / (this->magnitude() * other.magnitude()));
}
