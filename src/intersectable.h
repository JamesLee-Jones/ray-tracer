#ifndef INTERSECTABLE_H
#define INTERSECTABLE_H

#include "ray.h"

#include <memory>

class Material;

struct Intersection {
  bool hit = false;
  double mu{};
  bool front_face;
  Vec3 point;
  Vec3 normal;
  std::shared_ptr<Material> material;

  inline void set_intersection_normal(const Ray &r, const Vec3 &outward_normal) {
    front_face = dot(r.direction(), outward_normal) < 0;
    normal = front_face ? outward_normal : -outward_normal;
  }
};

class Intersectable {
 public:
  [[nodiscard]] virtual Intersection intersect(const Ray &r, double mu_min, double mu_max) const = 0;
};

#endif //INTERSECTABLE_H
