#ifndef MATERIAL_H
#define MATERIAL_H

#include "primitive.h"

#include <cmath>
#include <stdexcept>

class Material {
 public:
  virtual bool scatter(const Ray &ray_in, const Intersection &intersection, Vec3 &colour, Ray &scattered) const = 0;
};

#endif //MATERIAL_H
