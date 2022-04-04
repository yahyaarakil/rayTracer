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
    bool ppm3 = true, output = false;
    int oArg = -1;
    // parsing arguments
    if (argc < 2) {
        std::cout << "Invalid number of arguments!\nFormat Raytracer <input_file>" << std::endl;
        return -1;
    }
    for (int i = 2; i < argc; ++i) {
        if (!strcmp(argv[i], "-ppm6")) {
            ppm3 = false;
        }
        else if (!strcmp(argv[i], "-o")) {
            output = true;
            oArg = ++i;
        }
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
    PPM3File* img;
    if (ppm3) {
        img = new PPM3File(scene.camera.width, scene.camera.height, IN_MEMORY);
    }
    else {
        img = new PPM6File(scene.camera.width, scene.camera.height, IN_MEMORY);
    }
    RayTracingRenderer renderer(scene, 0, INFINITY, *img);
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
    if (output) {
        std::cout << "Writing render to file " << argv[oArg] << std::endl;
        img->writeToFile(argv[oArg]);
    }
    else {
        int outputNo = 0;
        char filename[2000];
        
        while (true) {
            sprintf(filename, "output%d.ppm", outputNo);
            FILE *file = fopen(filename, "r");
            if (file) {
                fclose(file);
                outputNo++;
            }
            else{
                break;
            }
        }
        std::cout << "Writing render to file " << filename << std::endl;
        img->writeToFile(filename);
    }
    std::cout << "Writing finished" << std::endl;
    
    // clean up and exit
    std::cout << "Exiting..." << std::endl;
    return 0;
}
