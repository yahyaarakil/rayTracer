//
//  mesh.hpp
//  rayTracer
//
//  Created by Yahya Arakil on 3/30/22.
//

#ifndef mesh_hpp
#define mesh_hpp

#include "object.hpp"
#include "triangle.hpp"
#include <vector>

class Mesh : public Object{
public:
    std::vector<Triangle> triangles;
    
    Mesh(Vector3, Material);
    void print() override;
};
#endif /* mesh_hpp */
