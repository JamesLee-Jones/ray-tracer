#ifndef DIFFUSE_H
#define DIFFUSE_H

#include "core/primitive.h"
#include "core/material.h"
#include "core/vec3.h"

class Diffuse : public Material {
 public:
  explicit Diffuse(const Vec3 &albedo) : albedo{albedo} {}

  bool scatter(const Ray &ray_in, const Intersection &intersection, Vec3 &attenuation, Ray &scattered) const override;

 private:
  Vec3 albedo;
};

#endif //DIFFUSE_H
