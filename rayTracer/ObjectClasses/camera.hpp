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
    double left, right, bottom, top;
    double distance;
    int width, height;
    
    Camera();
        
    double parameterize(const Vector3&, const Vector3&) const override;
};

#endif /* camera_hpp */
