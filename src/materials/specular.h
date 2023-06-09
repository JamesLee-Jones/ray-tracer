#ifndef SPECULAR_H
#define SPECULAR_H

#include "core/primitive.h"
#include "core/material.h"
#include "core/vec3.h"

class Specular : public Material {
 public:
  explicit Specular(const Vec3 &colour) : albedo{colour} {}

  bool scatter(const Ray &ray_in, const Intersection &intersection, Vec3 &attenuation, Ray &scattered) const override;

 private:
  const Vec3 albedo;
};

#endif //SPECULAR_H
