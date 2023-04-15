#ifndef SCENE_H
#define SCENE_H

#include "primitive.h"

#include <memory>
#include <utility>

class Scene {
 public:
  // TODO: This constructor should also take in all the lights in the scene
  explicit Scene(std::shared_ptr<Primitive> primitives) : primitives{std::move(primitives)} {}

  [[nodiscard]] Intersection intersect(const Ray &r, double mu_min, double mu_max) const;

 private:
  std::shared_ptr<Primitive> primitives;
};

#endif //SCENE_H
