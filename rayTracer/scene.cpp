//
//  scene.cpp
//  rayTracer
//
//  Created by Yahya Arakil on 3/28/22.
//

#include "scene.hpp"

Scene::Scene(){
    this->validationCode = -1;
}

Scene::Scene(const char* filename){
    this->deserializeFromFile(filename);
}

void Scene::serializeToFile(const char* filename){
    
}
void Scene::deserializeFromFile(const char* filename){
    this->validationCode = 1; // uninitialized
    std::fstream filestream;
    filestream.open(filename, std::ios::in);
    
    if (!filestream.is_open()){
        this->validationCode = 2; // cannot open file
        return;
    }
    int required = 0;
    
    std::string line;
    // foreach entity
    while(getline(filestream, line)){
        std::vector<std::string> chunk;
        if (line[0] != '#') {
            this->validationCode = 3; // error in file format
            return;
        }
        chunk.push_back(line);
        
        // read arguments of entity
        do {
            std::string s;
            getline(filestream, s);
            chunk.push_back(s);
        } while (!chunk.back().empty());
        
        // parse entity
        switch (hashString(chunk[0])) {
            case 17063467400851883058U: // #BackgroundColor
                this->parseBackgroundColor(chunk);
                ++required;
                break;
            case 80592002779029794U: // #MaxRecursionDepth
                this->parseMaxRecursionDepth(chunk);
                ++required;
                break;
            case 16662002709960481635U: // #ShadowRayEpsilon
                this->parseShadowRayEpsilon(chunk);
                ++required;
                break;
            case 33073711400U: // #Camera
                this->parseCamera(chunk);
                ++required;
                break;
            case 32059163211370U: // #Material
                this->parseMaterial(chunk);
                break;
            case 10865027356761418017U: // #AmbientLight
                this->parseAmbientLight(chunk);
                ++required;
                break;
            case 30899820566623721U: // #PointLight
                this->parsePointLight(chunk);
                break;
            case 31050181938098405U: // #VertexList
                this->parseVertexList(chunk);
                break;
            case 33545481680U: // #Sphere
                this->parseSphere(chunk);
                break;
            case 32266520337227U: // #Triangle
                this->parseTriangle(chunk);
                break;
            case 34717872U: // #Mesh
                this->parseMesh(chunk);
                break;

            default:
                this->validationCode = 4; // unknown entity in file
                return;
                break;
        }
    }
    
    this->validationCode = (required == SCENE_REQUIRED) ? 0 : 5; // not enough required entities in scene
}

void Scene::parseBackgroundColor(const std::vector<std::string>& chunk){
    this->backgroundColor = parseVector3(chunk[1]);
}
void Scene::parseMaxRecursionDepth(const std::vector<std::string>& chunk){
    sscanf(chunk[1].c_str(), "%d\n", &(this->maxRecursionDepth));
}
void Scene::parseShadowRayEpsilon(const std::vector<std::string>& chunk){
    sscanf(chunk[1].c_str(), "%f\n", &(this->shadowRayEpsilon));
}
void Scene::parseCamera(const std::vector<std::string>& chunk){
    this->camera.position = parseVector3(chunk[1]);
    this->camera.gaze = parseVector3(chunk[2]);
    this->camera.up = parseVector3(chunk[3]);
    
    sscanf(chunk[4].c_str(), "%f %f %f %f\n",
           &(this->camera.left), &(this->camera.right), &(this->camera.bottom), &(this->camera.top));
    sscanf(chunk[5].c_str(), "%f\n", &(this->camera.distance));
    sscanf(chunk[6].c_str(), "%d %d\n", &(this->camera.width), &(this->camera.height));
}
void Scene::parseMaterial(const std::vector<std::string>& chunk){
    int index;
    float phong_exp;
    sscanf(chunk[1].c_str(), "%d\n", &index);
    sscanf(chunk[5].c_str(), "%f\n", &phong_exp);

    Material material(parseVector3(chunk[2]), parseVector3(chunk[2]),
                      parseVector3(chunk[2]), parseVector3(chunk[2]), phong_exp);

    this->materials.insert(std::pair<int, Material>(index, material));
}
void Scene::parseAmbientLight(const std::vector<std::string>& chunk){
    this->ambientLight = parseVector3(chunk[1]);
}
void Scene::parsePointLight(const std::vector<std::string>& chunk){
    int index;
    sscanf(chunk[1].c_str(), "%d\n", &index);
    PointLight pointLight(index, parseVector3(chunk[2]), parseVector3(chunk[3]));
    this->pointLights.push_back(pointLight);
}
void Scene::parseVertexList(std::vector<std::string>& chunk){
    chunk.erase(chunk.begin());
    VertexList vertexList;
    for(std::string& s : chunk){
        vertexList.vertices.push_back(parseVector3(s));
    }
    this->vertexLists.push_back(vertexList);
}
void Scene::parseSphere(const std::vector<std::string>& chunk){
}
void Scene::parseTriangle(const std::vector<std::string>& chunk){
}
void Scene::parseMesh(const std::vector<std::string>& chunk){
}
