#ifndef RAY_TRACER_SRC_MATERIALS_REFRACTION_H_
#define RAY_TRACER_SRC_MATERIALS_REFRACTION_H_

#include "core/primitive.h"
#include "core/material.h"
#include "core/vec3.h"

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

#endif //RAY_TRACER_SRC_MATERIALS_REFRACTION_H_
