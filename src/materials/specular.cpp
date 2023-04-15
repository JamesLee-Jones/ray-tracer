#include "specular.h"

bool Specular::scatter(const Ray &ray_in, const Intersection &intersection, Vec3 &attenuation, Ray &scattered) const {
  Vec3 reflected_ray = Vec3::reflect(Vec3::normalize(ray_in.direction()), intersection.normal);
  attenuation = albedo;
  scattered = Ray(intersection.point, reflected_ray);
  return Vec3::dot(scattered.direction(), intersection.normal) > 0;
}
