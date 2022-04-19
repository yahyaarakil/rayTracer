//
//  material.cpp
//  rayTracer
//
//  Created by Yahya Arakil on 3/28/22.
//

#include "material.hpp"

Material::Material(){}
Material::Material(Vector3 ambient_reflectance, Vector3 diffuse_reflectance,
                   Vector3 specular_reflectance, Vector3 mirror_reflectance, double phong_exp)
: ambient_reflectance(ambient_reflectance), diffuse_reflectance(diffuse_reflectance),
  specular_reflectance(specular_reflectance), mirror_reflectance(mirror_reflectance), phong_exp(phong_exp) {}
