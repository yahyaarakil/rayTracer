//
//  rayTracingRenderer.cpp
//  rayTracer
//
//  Created by Yahya Arakil on 3/30/22.
//

#include "rayTracingRenderer.hpp"

RayTracingRenderer::RayTracingRenderer(Scene& scene, double t_min, double t_max, ImageGenerator& imageGenerator)
: Renderer(scene, imageGenerator), rayGenerator(scene.camera, t_min, t_max), validationCode(0) {}

Hit RayTracingRenderer::castRay(const Vector3& origin, const Vector3& direction) const {
    double min_t = INFINITY, t;
    Object* objectP = NULL;
    for (Object* object : this->scene.objects) {
        t = object->parameterize(origin, direction);
        
        if (t < min_t && t >= 0){
            objectP = object;
            min_t = t;
        }
    }
    return Hit(min_t, objectP);
}

Vector3 RayTracingRenderer::determinePixelColor(const Vector3& hitPoint, const Object& hitObject, int pass) const {
    // ambient
    Vector3 luminance = this->scene.ambientLight & hitObject.material.ambient_reflectance;
    Vector3 normal = hitObject.getNormal(hitPoint);
    Vector3 eyeVector = this->rayGenerator.position - hitPoint;
    eyeVector /= eyeVector.magnitude();

    for (PointLight* light : this->scene.pointLights) {
        Vector3 lightRay = light->position - hitPoint;
        double lightRayMag = lightRay.magnitude();
        lightRay /= lightRayMag;
        
        Hit lightRayCollision = this->castRay(hitPoint + lightRay * this->scene.shadowRayEpsilon, lightRay);
        if (lightRayCollision.getObject() != NULL) {
            if ((lightRay * lightRayCollision.getT()).magnitude() < lightRayMag) {
                continue;
            }
        }
        Vector3 intensity = light->intensity / (lightRayMag*lightRayMag);
        
        // compute diffuse
        Vector3 diffuse = (intensity & hitObject.material.diffuse_reflectance
                           * fmax(lightRay ^ normal, 0));
        luminance += diffuse;

        // compute specular
        Vector3 halfVector = lightRay + eyeVector;
        halfVector /= halfVector.magnitude();
        double alpha = fmax(normal ^ halfVector, 0);
        Vector3 specular = intensity & hitObject.material.specular_reflectance;
        specular *= pow(alpha, hitObject.material.phong_exp);

        luminance += specular;
    }
    
    if(pass > 0){
        Vector3 reflectionRay = (eyeVector *-1) + (normal * 2) * (normal ^ (eyeVector));
        reflectionRay /= reflectionRay.magnitude();

        Hit reflectionRayCollision = this->castRay(hitPoint + reflectionRay * this->scene.shadowRayEpsilon, reflectionRay);
        if (reflectionRayCollision.getObject() != NULL) {
            luminance += hitObject.material.mirror_reflectance
            & this->determinePixelColor(reflectionRay * reflectionRayCollision.getT() + hitPoint, *(reflectionRayCollision.getObject()), pass - 1);
        }
    }
    
    luminance.x = fmin(255, fmax(luminance.x, 0));
    luminance.y = fmin(255, fmax(luminance.y, 0));
    luminance.z = fmin(255, fmax(luminance.z, 0));
    return luminance;
}

int RayTracingRenderer::renderToImage() {
    Progress progress(this->scene.camera.height * this->scene.camera.width);
    for (int i = 0; i < this->scene.camera.height; ++i) {
        for (int j = 0; j < this->scene.camera.width; ++j) {
            
            Vector3 direction = this->rayGenerator.computeDirection(i, j);
            Hit hit = this->castRay(this->rayGenerator.position, direction);
            
            if (hit.getObject() != NULL) {
                Vector3 color = this->determinePixelColor(direction * hit.getT() + this->rayGenerator.position, *(hit.getObject()), this->scene.maxRecursionDepth);
                this->imageGenerator.writeNextPixel(color);
            }
            else {
                this->imageGenerator.writeNextPixel(this->scene.backgroundColor);
            }
            
            progress.update();
        }
    }
    return 0;
}
