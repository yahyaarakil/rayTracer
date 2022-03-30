//
//  main.cpp
//  rayTracer
//
//  Created by Yahya Arakil on 3/28/22.
//

#include <iostream>
#include "rayTracingRenderer.hpp"
#include "ppm3.hpp"

std::ostream& operator<<(std::ostream& stream, const Vector3& vector){
    stream << "<" << vector.x << ", " << vector.y << ", " << vector.z << ">";
    return stream;
}

int main(int argc, const char * argv[]) {
//    // parsing arguments
//    if (argc != 2) {
//        std::cout << "Invalid number of arguments!\nFormat Raytracer <input_file>" << std::endl;
//        return -1;
//    }
//
//    // loading scene
//    std::cout << "Loading scene from " << argv[1] << std::endl;
//    Scene scene(argv[1]);
//    if (scene.validationCode != 0) {
//        std::cout << "Failed to open " << argv[1] << std::endl;
//        return scene.validationCode;
//    }
//    std::cout << "Scene Loaded" << std::endl;
//
//    // initializing ray tracing renderer
//    std::cout << "Initializing RayTracing Renderer" << std::endl;
//    RayTracingRenderer renderer(scene, .0f, .0f);
//    if (renderer.validationCode != 0) {
//        std::cout << "Failed to initialize renderer" << std::endl;
//        return scene.validationCode;
//    }
//    std::cout << "Renderer Initialized" << std::endl;
    
    PPM3File image(2, 2, IN_MEMORY);
    image.accessBuffer(0, 0, 0) = 255;
    image.accessBuffer(0, 0, 1) = 0;
    image.accessBuffer(0, 0, 2) = 0;

    image.accessBuffer(0, 1, 0) = 0;
    image.accessBuffer(0, 1, 1) = 255;
    image.accessBuffer(0, 1, 2) = 255;

    image.accessBuffer(1, 0, 0) = 0;
    image.accessBuffer(1, 0, 1) = 0;
    image.accessBuffer(1, 0, 2) = 255;

    image.accessBuffer(1, 1, 0) = 255;
    image.accessBuffer(1, 1, 1) = 0;
    image.accessBuffer(1, 1, 2) = 255;
    
    image.writeToFile("testImage.ppm");
    return 0;
}
