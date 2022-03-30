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
    Vector3 gaze, up;
    float left, right, bottom, top;
    float distance;
    int width, height;
        
    void print() override;
};

#endif /* camera_hpp */
