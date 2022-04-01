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
    std::vector<Triangle*> triangles;
    
    Mesh(const Vector3&, const Material&);
    float parameterize(const Vector3&, const Vector3&) const override;
};
#endif /* mesh_hpp */
