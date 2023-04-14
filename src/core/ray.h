#ifndef RAY_H
#define RAY_H

#include "core/vec3.h"

#include <stdexcept>
#include <limits>

class Ray {
 public:
  Ray() = default;
  Ray(Vec3 origin, Vec3 direction) : orig{origin}, dir{direction} {
    if (dir.near_zero()) {
      throw std::invalid_argument("Ray must have non-zero direction.");
    }
  }

  [[nodiscard]] Vec3 at(double mu) const {
    return orig + mu * dir;
  }

  [[nodiscard]] Vec3 origin() const { return orig; }
  [[nodiscard]] Vec3 direction() const { return dir; }

 private:
  Vec3 orig;
  Vec3 dir;
};



#endif //RAY_H
