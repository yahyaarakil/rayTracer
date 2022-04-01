//
//  utilities.cpp
//  rayTracer
//
//  Created by Yahya Arakil on 3/28/22.
//

#include "utilities.hpp"

unsigned long long int hashString(std::string s){
    unsigned long long int hash = 0;
    for (int i = 0; i < s.length(); ++i) {
        hash = (hash << 5) - hash;
        hash += s[i];
    }
    return hash;
}

Vector3 parseVector3(const std::string& s){
    Vector3 v;
    sscanf(s.c_str(), "%f %f %f\n", &(v.x), &(v.y), &(v.z));
    return v;
}

float getDeterminant(const Vector3& v1, const Vector3& v2, const Vector3& v3){
    return v1.x * (v2.y * v3.z - v3.y * v2.z)
    + v1.y * (v3.x * v2.z - v2.x * v3.z)
    + v1.z * (v2.x * v3.y - v2.y * v3.x);
}
