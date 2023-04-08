#ifndef PLANE_H
#define PLANE_H

#include <vec3.h>
#include <ray.h>
#include <intersectable.h>

class Plane : public Intersectable {
 public:
  // TODO: Throw an error if the normal is (0,0,0)
  Plane(Vec3 &point, Vec3 &normal) : p{point}, n{normal} {}

  Vec3 getPoint() { return p; }
  void setPoint(Vec3 &point) { p = point; }

  Vec3 getNormal() { return n; }
  void setNormal(Vec3 &normal) { n = normal; }

  Intersection intersect(const Ray &ray, double mu_min, double mu_max) const override;

 private:
  Vec3 p;
  Vec3 n;
};

Intersection Plane::intersect(const Ray &ray, double mu_min, double mu_max) const {
  Intersection intersection;
  double mu = -dot(ray.origin() - p, n) / dot(ray.direction(), n);
  if (mu > mu_max || mu < mu_min) return intersection; // The ray does not intersect in the valid range

  intersection.hit = true;
  intersection.point = ray.at(mu);
  intersection.normal = n;
  return intersection;
}

#endif //PLANE_H
