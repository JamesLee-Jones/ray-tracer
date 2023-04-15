#include "refraction.h"

bool Refraction::scatter(const Ray &ray_in, const Intersection &intersection, Vec3 &attenuation, Ray &scattered) const {
  attenuation = Vec3(1, 1, 1);
  double ri = intersection.front_face ? 1 / eta : eta;
  Vec3 ray_in_unit_dir = Vec3::normalize(ray_in.direction());

  Vec3 dir;
  if (Vec3 refracted_dir = Vec3::refract(ray_in_unit_dir, intersection.normal, ri);
      refracted_dir.near_zero() ||
      schlick_approximation(ray_in_unit_dir, intersection.normal, ri) > random_double()) {
    dir = Vec3::reflect(ray_in_unit_dir, intersection.normal);
  } else {
    dir = refracted_dir;
  }

  scattered = Ray(intersection.point, dir);
  return true;
}

double Refraction::schlick_approximation(const Vec3 &l, const Vec3 &n, double eta1_over_eta2) {
  double r0 = pow((1 - eta1_over_eta2) / (1 + eta1_over_eta2), 2);
  return r0 + (1 - r0) * pow(1 - Vec3::dot(n, -l), 5);
}
