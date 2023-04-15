#ifndef RAY_TRACER_SRC_MATERIALS_REFRACTION_H_
#define RAY_TRACER_SRC_MATERIALS_REFRACTION_H_

#include "core/primitive.h"
#include "core/material.h"
#include "core/vec3.h"

class Refraction : public Material {
 public:
  explicit Refraction(double refractive_index) : eta{refractive_index} {}

  bool scatter(const Ray &ray_in, const Intersection &intersection, Vec3 &attenuation, Ray &scattered) const override;

 private:

  static double schlick_approximation(const Vec3 &l, const Vec3 &n, double eta1_over_eta2);

  double eta;
};

#endif //RAY_TRACER_SRC_MATERIALS_REFRACTION_H_
