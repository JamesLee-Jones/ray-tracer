#ifndef SPECULAR_H
#define SPECULAR_H

#include "core/primitive.h"
#include "core/material.h"
#include "core/vec3.h"

class Specular : public Material {
 public:
  explicit Specular(const Vec3 &colour) : albedo{colour} {}

  bool scatter(const Ray &ray_in, const Intersection &intersection, Vec3 &attenuation, Ray &scattered) const override {
    Vec3 reflected_ray = reflect(normalize(ray_in.direction()), intersection.normal);
    attenuation = albedo;
    scattered = Ray(intersection.point, reflected_ray);
    return dot(scattered.direction(), intersection.normal) > 0;
  }

 private:
  const Vec3 albedo;
};

#endif //SPECULAR_H
