//
//  main.cpp
//  rayTracer
//
//  Created by Yahya Arakil on 3/28/22.
//

#include <iostream>
#include "vector3.hpp"
#include "object.hpp"
#include "camera.hpp"
#include "scene.hpp"

std::ostream& operator<<(std::ostream& stream, const Vector3& vector){
    stream << "<" << vector.x << ", " << vector.y << ", " << vector.z << ">";
    return stream;
}

int main(int argc, const char * argv[]) {
    if (argc != 2) {
        std::cout << "Invalid number of arguments!\nFormat Raytracer <input_file>" << std::endl;
        return -1;
    }
    
    std::cout << "Loading scene from " << argv[1] << std::endl;
    Scene scene(argv[1]);
    
    if (scene.validationCode != 0) {
        std::cout << "Failed to open " << argv[1] << std::endl;
        return scene.validationCode;
    }
    std::cout << "Scene Loaded" << std::endl;
    
    
    return 0;
}
