//
//  utilities.hpp
//  rayTracer
//
//  Created by Yahya Arakil on 3/28/22.
//

#ifndef utilities_hpp
#define utilities_hpp

#include <string>
#include "vector3.hpp"

unsigned long long int hashString(std::string);
Vector3 parseVector3(const std::string&);
float getDeterminant(const Vector3&, const Vector3&, const Vector3&);

#endif /* utilities_hpp */
