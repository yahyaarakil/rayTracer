//
//  main.cpp
//  rayTracer
//
//  Created by Yahya Arakil on 3/28/22.
//

#include <iostream>
#include "vector3.hpp"
#include "object.hpp"

std::ostream& operator<<(std::ostream& stream, const Vector3& vector){
    stream << "<" << vector.x << ", " << vector.y << ", " << vector.z << ">";
    return stream;
}

class Object2 : public Object{
public:
    void print() override {
        
    }
};

int main(int argc, const char * argv[]) {
    Vector3 a(1, 2, 3);
    
    Vector3 b;
    
    std::cout<< b << std::endl;
    return 0;
}
