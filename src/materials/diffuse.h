#ifndef DIFFUSE_H
#define DIFFUSE_H

#include "core/primitive.h"
#include "core/material.h"
#include "core/vec3.h"

class Diffuse : public Material {
 public:
  explicit Diffuse(const Vec3 &albedo) : albedo{albedo} {}

  bool scatter(const Ray &ray_in, const Intersection &intersection, Vec3 &attenuation, Ray &scattered) const override {
    auto scatter_dir = intersection.normal + random_unit_vector();
    if (scatter_dir.near_zero()) {
      scatter_dir = intersection.normal;
    }
    attenuation = albedo;
    scattered = Ray(intersection.point, scatter_dir);
    return true;
  }

 private:
  Vec3 albedo;
};

#endif //DIFFUSE_H
