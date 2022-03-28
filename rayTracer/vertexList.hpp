//
//  vertexList.hpp
//  rayTracer
//
//  Created by Yahya Arakil on 3/28/22.
//

#ifndef vertexList_hpp
#define vertexList_hpp


#include "object.hpp"
#include <vector>

class VertexList : public Object{
public:
    std::vector<Vector3> vertices;
    void print() override;
};
#endif /* vertexList_hpp */
