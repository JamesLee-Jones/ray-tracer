#ifndef SPHERE_H
#define SPHERE_H

#include "core/vec3.h"
#include "core/ray.h"
#include "core/material.h"
#include "core/primitive.h"

#include <cmath>
#include <memory>
#include <utility>

class Sphere : public Primitive {
 public:
  Sphere(Vec3 centre, double radius, std::shared_ptr<Material> material) : c{centre},
                                                                           r{radius},
                                                                           material{std::move(material)} {
    if (fabs(r) < 1e-8) {
      throw std::invalid_argument("Sphere must have non-zero radius.");
    }
  }

  [[nodiscard]] Vec3 getCenter() const { return c; }
  void setCenter(Vec3 center) { c = center; }

  [[nodiscard]] double getRadius() const { return r; }
  void setRadius(double radius) { r = radius; }

  [[nodiscard]] Vec3 normalAt(Vec3 pos) const;

  [[nodiscard]] Intersection intersect(const Ray &ray, double mu_min, double mu_max) const override;

 private:
  Vec3 c;
  double r;
  std::shared_ptr<Material> material;
};

Vec3 Sphere::normalAt(Vec3 pos) const {
  // TODO: Assert the point is on the sphere
  return normalize(pos - c);
}

Intersection Sphere::intersect(const Ray &ray, double mu_min, double mu_max) const {
  Intersection intersection;
  Vec3 delta_p = ray.origin() - c;
  double temp1 = dot(-ray.direction(), delta_p);
  double determinant = pow(temp1, 2) - dot(delta_p, delta_p) + pow(r, 2);

  if (determinant < 0.0) return intersection;

  double temp2 = sqrt(determinant);
  double mu1 = temp1 - temp2;
  double mu2 = temp1 + temp2;
  bool mu1_valid = mu_max >= mu1 && mu1 >= mu_min;
  bool mu2_valid = mu_max >= mu2 && mu2 >= mu_min;

  double mu;
  if ((mu1_valid && mu2_valid) || mu1_valid) mu = mu1;
  else if (mu2_valid) mu = mu2;
  else return intersection;

  intersection.hit = true;
  intersection.mu = mu;
  intersection.point = ray.at(mu);
  intersection.set_intersection_normal(ray, Sphere::normalAt(intersection.point));
  intersection.material = material;
  return intersection;
}

#endif //SPHERE_H
