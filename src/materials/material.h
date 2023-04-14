#ifndef MATERIAL_H
#define MATERIAL_H

#include "core/intersectable.h"

#include <cmath>
#include <stdexcept>

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

class Refraction : public Material {
 public:
  explicit Refraction(double refractive_index) : eta{refractive_index} {}

  bool scatter(const Ray &ray_in, const Intersection &intersection, Vec3 &attenuation, Ray &scattered) const override {
    attenuation = Vec3(1, 1, 1);
    double ri = intersection.front_face ? 1 / eta : eta;
    Vec3 ray_in_unit_dir = normalize(ray_in.direction());

    Vec3 dir;
    if (Vec3 refracted_dir = refract(ray_in_unit_dir, intersection.normal, ri);
        refracted_dir.near_zero() ||
        schlick_approximation(ray_in_unit_dir, intersection.normal, ri) > random_double()) {
      dir = reflect(ray_in_unit_dir, intersection.normal);
    } else {
      dir = refracted_dir;
    }

    scattered = Ray(intersection.point, dir);
    return true;
  }

 private:
  static Vec3 refract(const Vec3 &v, const Vec3 &n, double eta) {
    double n_dot_v = dot(n, v);
    double k = 1.0 - pow(eta, 2) * (1 - pow(n_dot_v, 2));
    if (k < 0) {
      return {0, 0, 0};
    } else {
      return eta * v - (eta * n_dot_v + sqrt(k)) * n;
    }
  }

  static double schlick_approximation(const Vec3 &l, const Vec3 &n, double eta1_over_eta2) {
    double r0 = pow((1 - eta1_over_eta2) / (1 + eta1_over_eta2), 2);
    return r0 + (1 - r0) * pow(1 - dot(n, -l), 5);
  }

  double eta;
};

#endif //MATERIAL_H
