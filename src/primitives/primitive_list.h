#ifndef PRIMITIVE_LIST_H
#define PRIMITIVE_LIST_H

#include "core/primitive.h"
#include "core/ray.h"

#include <memory>
#include <vector>

using std::shared_ptr;

class PrimitiveList : public Primitive {
 public:
  PrimitiveList() = default;
  explicit PrimitiveList(shared_ptr<Primitive> &obj) { add(obj); }

  void add(const shared_ptr<Primitive>& obj) { objects.push_back(obj); }
  void clear() { objects.clear(); }

  [[nodiscard]] Intersection intersect(const Ray &r, double mu_min, double mu_max) const override;

 private:
  std::vector<shared_ptr<Primitive>> objects;
};

Intersection PrimitiveList::intersect(const Ray &r, double mu_min, double mu_max) const {
  Intersection closest = Intersection();
  for (const auto& obj : objects) {
    Intersection curr_intersection = obj->intersect(r, mu_min, mu_max);
    if (curr_intersection.hit && (!closest.hit || curr_intersection.mu < closest.mu)) {
      closest = curr_intersection;
    }
  }
  return closest;
}

#endif //PRIMITIVE_LIST_H
