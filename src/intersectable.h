#ifndef INTERSECTABLE_H
#define INTERSECTABLE_H

#include <ray.h>

struct Intersection {
  bool hit = false;
  Vec3 point;
  Vec3 normal;
};

class Intersectable {
 public:
  virtual Intersection intersect(const Ray &r, double mu_min, double mu_max) const = 0;
};

#endif //INTERSECTABLE_H
