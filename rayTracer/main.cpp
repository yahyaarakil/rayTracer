//
//  main.cpp
//  rayTracer
//
//  Created by Yahya Arakil on 3/28/22.
//

#include <iostream>
#include "rayTracingRenderer.hpp"
#include "ppm3.hpp"
#include "ppm6.hpp"

std::ostream& operator<<(std::ostream& stream, const Vector3& vector){
    stream << "<" << vector.x << ", " << vector.y << ", " << vector.z << ">";
    return stream;
}

int main(int argc, const char * argv[]) {
    // parsing arguments
    if (argc != 2) {
        std::cout << "Invalid number of arguments!\nFormat Raytracer <input_file>" << std::endl;
        return -1;
    }

    // loading scene
    std::cout << "Loading scene from " << argv[1] << std::endl;
    Scene scene(argv[1]);
    if (scene.validationCode != 0) {
        std::cout << "Failed to open " << argv[1] << std::endl;
        return scene.validationCode;
    }
    std::cout << "Scene Loaded" << std::endl;

    // initializing ray tracing renderer
    std::cout << "Initializing RayTracing Renderer" << std::endl;
    PPM6File img(scene.camera.width, scene.camera.height, IN_MEMORY);
    RayTracingRenderer renderer(scene, .0f, .0f, img);
    if (renderer.validationCode != 0) {
        std::cout << "Failed to initialize renderer" << std::endl;
        return scene.validationCode;
    }
    std::cout << "Renderer Initialized" << std::endl;
    
    // render
    std::cout << "Rendering started" << std::endl;
    renderer.renderToImage();
    std::cout << "Rendering finished" << std::endl;
    
    // write file
    std::cout << "Writing render to file" << std::endl;
    img.writeToFile("output1.ppm");
    std::cout << "Writing finished" << std::endl;
    
    // clean up and exit
    std::cout << "Exiting..." << std::endl;
    return 0;
}
