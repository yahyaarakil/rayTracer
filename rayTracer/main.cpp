//
//  main.cpp
//  rayTracer
//
//  Created by Yahya Arakil on 3/28/22.
//

#include <iostream>
#include "vector3.hpp"

std::ostream& operator<<(std::ostream& stream, const Vector3& vector){
    stream << "<" << vector.x << ", " << vector.y << ", " << vector.z << ">";
    return stream;
}

int main(int argc, const char * argv[]) {
    Vector3 a(1,3,4);
    Vector3 b(2,7,-5);
    
    Vector3 ab = a * b;
    std::cout << ab;
    
    a += b;
    std::cout<<std::endl<<a;
    return 0;
}
