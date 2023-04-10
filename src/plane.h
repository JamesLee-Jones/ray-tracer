#ifndef PLANE_H
#define PLANE_H

#include "vec3.h"

#include "material.h"
#include "intersectable.h"
#include <stdexcept>
#include <memory>

class Plane : public Intersectable {
 public:
  Plane(Vec3 point, Vec3 normal, std::shared_ptr<Material> material) : p{point}, n{normal}, material{std::move(material)} {
    if (normal.near_zero()) {
      throw std::invalid_argument("Plane must have non-zero normal.");
    }
  }

  Vec3 getPoint() { return p; }
  void setPoint(Vec3 &point) { p = point; }

  Vec3 getNormal() { return n; }
  void setNormal(Vec3 &normal) { n = normal; }

  [[nodiscard]] Intersection intersect(const Ray &ray, double mu_min, double mu_max) const override;

 private:
  Vec3 p;
  Vec3 n;
  std::shared_ptr<Material> material;
};

Intersection Plane::intersect(const Ray &ray, double mu_min, double mu_max) const {
  Intersection intersection;
  double mu = -dot(ray.origin() - p, n) / dot(ray.direction(), n);
  if (mu > mu_max || mu < mu_min) return intersection; // The ray does not intersect in the valid range

  intersection.hit = true;
  intersection.mu = mu;
  intersection.point = ray.at(mu);
  intersection.set_intersection_normal(ray, n);
  intersection.material = material;
  return intersection;
}

#endif //PLANE_H
