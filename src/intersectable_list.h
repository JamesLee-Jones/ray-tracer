#ifndef INTERSECTABLE_LIST_H
#define INTERSECTABLE_LIST_H

#include "intersectable.h"
#include "ray.h"

#include <memory>
#include <vector>

using std::shared_ptr;

class IntersectableList : public Intersectable {
 public:
  IntersectableList() = default;
  explicit IntersectableList(shared_ptr<Intersectable> &obj) { add(obj); }

  void add(const shared_ptr<Intersectable>& obj) { objects.push_back(obj); }
  void clear() { objects.clear(); }

  Intersection intersect(const Ray &r, double mu_min, double mu_max) const override;

 private:
  std::vector<shared_ptr<Intersectable>> objects;
};

Intersection IntersectableList::intersect(const Ray &r, double mu_min, double mu_max) const {
  Intersection closest = Intersection();
  for (const auto& obj : objects) {
    Intersection curr_intersection = obj->intersect(r, mu_min, mu_max);
    if (curr_intersection.hit && (!closest.hit || curr_intersection.mu < closest.mu)) {
      closest = curr_intersection;
    }
  }
  return closest;
}

#endif //INTERSECTABLE_LIST_H
