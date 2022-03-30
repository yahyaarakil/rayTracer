//
//  camera.hpp
//  rayTracer
//
//  Created by Yahya Arakil on 3/28/22.
//

#ifndef camera_hpp
#define camera_hpp

#include "object.hpp"

class Camera : public Object{
public:
    Vector3 gaze, up, m, q, v;
    float left, right, bottom, top;
    float distance;
    int width, height;
    float su, sv;
        
    void print() override;
    Vector3 computeS(int, int) const;
    
    void computeM();
    void computeU();
    void computeV();
    void computeQ();
    void computeSuSv();
};

#endif /* camera_hpp */
