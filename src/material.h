#ifndef MATERIAL_H
#define MATERIAL_H

#include "intersectable.h"

class Material {
 public:
  virtual bool scatter(const Ray &ray_in, const Intersection &intersection, Vec3 &colour, Ray &scattered) const = 0;
};

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

class Metal : public Material {
 public:
  explicit Metal(const Vec3 &colour) : albedo{colour} {}

  bool scatter(const Ray &ray_in, const Intersection &intersection, Vec3 &attenuation, Ray &scattered) const override {
    Vec3 reflected_ray = reflect(normalize(ray_in.direction()), intersection.normal);
    attenuation = albedo;
    scattered = Ray(intersection.point, reflected_ray);
    return dot(scattered.direction(), intersection.normal) > 0;
  }

 private:
  const Vec3 albedo;
};

#endif //MATERIAL_H
