#include "ray.h"

Ray::Ray(Vec3 origin, Vec3 direction) : orig{origin}, dir{direction} {
  if (dir.near_zero()) {
    throw std::invalid_argument("Ray must have non-zero direction.");
  }
}

[[nodiscard]] Vec3 Ray::at(double mu) const {
  return orig + mu * dir;
}
