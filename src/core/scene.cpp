#include "scene.h"

Intersection Scene::intersect(const Ray &r, double mu_min, double mu_max) const {
  return primitives->intersect(r, mu_min, mu_max);
}
