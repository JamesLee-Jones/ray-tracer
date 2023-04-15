#include "diffuse.h"

bool Diffuse::scatter(const Ray &ray_in, const Intersection &intersection, Vec3 &attenuation, Ray &scattered) const {
  auto scatter_dir = intersection.normal + Vec3::random_unit_vector();
  if (scatter_dir.near_zero()) {
    scatter_dir = intersection.normal;
  }
  attenuation = albedo;
  scattered = Ray(intersection.point, scatter_dir);
  return true;
}
