//
//  scene.hpp
//  rayTracer
//
//  Created by Yahya Arakil on 3/28/22.
//

#ifndef scene_hpp
#define scene_hpp

#include "vector3.hpp"
#include "object.hpp"
#include "camera.hpp"
#include "material.hpp"
#include "pointLight.hpp"
#include "sphere.hpp"
#include "triangle.hpp"
#include "mesh.hpp"
#include "utilities.hpp"
#include <vector>
#include <stdio.h>
#include <map>
#include <fstream>
#include <string>

#define SCENE_REQUIRED 5

class Scene{
public:
    Camera camera;
    int validationCode;
    Vector3 backgroundColor;
    Vector3 ambientLight;
    int maxRecursionDepth;
    float shadowRayEpsilon;
    void serializeToFile(const char*);
    void deserializeFromFile(const char*);
    
    std::vector<Material*> materials;
    std::map<int, Vector3> vertexList;
    std::vector<PointLight*> pointLights;
    std::vector<Object*> objects;
    
    Scene();
    ~Scene();
    Scene(const char*);
    
private:
    void parseBackgroundColor(const std::vector<std::string>&);
    void parseMaxRecursionDepth(const std::vector<std::string>&);
    void parseShadowRayEpsilon(const std::vector<std::string>&);
    void parseCamera(const std::vector<std::string>&);
    void parseMaterial(const std::vector<std::string>&);
    void parseAmbientLight(const std::vector<std::string>&);
    void parsePointLight(const std::vector<std::string>&);
    void parseVertexList(std::vector<std::string>&);
    void parseSphere(const std::vector<std::string>&);
    void parseTriangle(const std::vector<std::string>&);
    void parseMesh(std::vector<std::string>&);
};

#endif /* scene_hpp */
