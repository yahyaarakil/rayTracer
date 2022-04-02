//
//  rayTracingRenderer.cpp
//  rayTracer
//
//  Created by Yahya Arakil on 3/30/22.
//

#include "rayTracingRenderer.hpp"

RayTracingRenderer::RayTracingRenderer(Scene& scene, double t_min, double t_max, ImageGenerator& imageGenerator)
: Renderer(scene, imageGenerator), rayGenerator(scene.camera, t_min, t_max), validationCode(0) {}

Hit RayTracingRenderer::castRay(const Vector3& origin, const Vector3& direction){
    double min_t = INFINITY, t;
    Object* objectP = NULL;
    for (Object* object : this->scene.objects) {
        t = object->parameterize(this->rayGenerator.position, direction);
        
        if (t < min_t){
            objectP = object;
            min_t = t;
        }
    }
    return Hit(min_t, objectP);
}

Vector3 RayTracingRenderer::determinePixelColor(const Vector3& hitPoint, const Object& hitObject) const {
    // ambient
    Vector3 luminance = this->scene.ambientLight & hitObject.material.ambient_reflectance;
    Vector3 normal = hitObject.getNormal(hitPoint);

    for (PointLight light : this->scene.pointLights) {
        Vector3 lightRay = light.position - hitPoint;
        double lightRayMag = lightRay.magnitude();
        lightRay /= lightRayMag;
        
        // diffuse
        Vector3 diffuseLuminance = (hitObject.material.diffuse_reflectance
        * fmax(0, lightRay ^ normal))
        & (light.intensity / (lightRayMag * lightRayMag));

        luminance += diffuseLuminance;

        // specular
        Vector3 e = (this->rayGenerator.position - hitPoint);
        e /= e.magnitude();
        Vector3 h = lightRay + e;
        h /= h.magnitude();
        Vector3 specular = hitObject.material.specular_reflectance * pow(normal ^ h, hitObject.material.phong_exp);

        luminance += specular;
    }
    return luminance;
}

int RayTracingRenderer::renderToImage() {
    Progress progress(this->scene.camera.height * this->scene.camera.width);
    for (int i = 0; i < this->scene.camera.height; ++i) {
        for (int j = 0; j < this->scene.camera.width; ++j) {
            Vector3 direction = this->rayGenerator.computeDirection(this->rayGenerator.computeS(i, j));
            Hit hit = castRay(this->rayGenerator.position, direction);
            if (hit.getT() > this->rayGenerator.t_min && hit.getT() < this->rayGenerator.t_max) {
                Vector3 color = this->determinePixelColor(direction * hit.getT(), *(hit.getObject()));
                this->imageGenerator.writeNextPixel(color);
//                this->imageGenerator.writeNextPixel(Vector3(255, 255, 255));
            }
            else {
                this->imageGenerator.writeNextPixel(this->scene.backgroundColor);
            }
            
            progress.update();
        }
    }
    return 0;
}
