#ifndef SPHERE_H
#define SPHERE_H

#include <vec3.h>
#include <ray.h>
#include <intersectable.h>
#include <cmath>

class Sphere : public Intersectable {
 public:
  Sphere(Vec3 centre, double radius) : c{centre}, r{radius} {}

  Vec3 getCenter() { return c; }
  void setCenter(Vec3 centre) { c = centre; }

  double getRadius() { return r; }
  void setRadius(double radius) { r = radius; }

  Vec3 normalAt(Vec3 pos) const;

  Intersection intersect(const Ray &ray, double mu_min, double mu_max) const override;

 private:
  Vec3 c;
  double r;
};

Vec3 Sphere::normalAt(Vec3 pos) const {
  // TODO: Assert the point is on the sphere
  return normalize(pos - c);
}

Intersection Sphere::intersect(const Ray &ray, double mu_min, double mu_max) const {
  Vec3 delta_p = ray.origin() - c;
  double temp1 = dot(-ray.direction(), delta_p);
  double temp2 = sqrt(pow(temp1, 2) - dot(delta_p, delta_p) + pow(r, 2));
  double mu1 = temp1 + temp2;
  double mu2 = temp1 - temp2;
  bool mu1_valid = mu_max >= mu1 && mu1 >= mu_min;
  bool mu2_valid = mu_max >= mu2 && mu2 >= mu_min;

  Intersection intersection;
  double mu;
  if (mu1_valid && mu2_valid) mu = mu2;
  else if (mu1_valid) mu = mu1;
  else if (mu2_valid) mu = mu2;
  else return intersection;

  intersection.hit = true;
  intersection.point = ray.at(mu);
  intersection.normal = Sphere::normalAt(intersection.point);
  return intersection;
}

#endif //SPHERE_H
