//
//  rayGenerator.hpp
//  rayTracer
//
//  Created by Yahya Arakil on 3/30/22.
//

#ifndef rayGenerator_hpp
#define rayGenerator_hpp

#include "camera.hpp"
#include "sphere.hpp"
#include <cmath>

class RayGenerator : public Camera {
public:
    RayGenerator();
    RayGenerator(Camera, float, float);

    Vector3 w, u, v, m, q;
    float su, sv, t_min, t_max;

    Vector3 computeS(int, int) const;
    Vector3 computeDirection(const Vector3&) const;
    Vector3 computeR(float t, const Vector3&) const;
//    float computeTSphere(const Vector3&, const Sphere&) const;
    
    void computeVectors();

private:
    void computeW();
    void computeU();
    void computeV();
    void computeM();
    void computeQ();
    void computeSuSv();
//    float computeTiSphere(const Vector3&, const Sphere&, int) const;
};

#endif /* rayGenerator_hpp */
