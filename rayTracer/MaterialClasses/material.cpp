//
//  material.cpp
//  rayTracer
//
//  Created by Yahya Arakil on 3/28/22.
//

#include "material.hpp"

Material::Material(){}
Material::Material(Vector3 ambient_reflectance, Vector3 diffuse_reflectance,
                   Vector3 specular_reflectance, Vector3 mirror_reflectance, float phong_exp){
    this->ambient_reflectance = ambient_reflectance;
    this->diffuse_reflectance = diffuse_reflectance;
    this->specular_reflectance = specular_reflectance;
    this->mirror_reflectance = mirror_reflectance;
    this->phong_exp = phong_exp;
}
