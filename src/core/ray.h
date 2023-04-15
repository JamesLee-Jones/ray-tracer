#ifndef RAY_H
#define RAY_H

#include "vec3.h"

#include <limits>
#include <stdexcept>

class Ray {
 public:
  Ray() = default;
  Ray(Vec3 origin, Vec3 direction);

  [[nodiscard]] Vec3 at(double mu) const;

  [[nodiscard]] inline Vec3 origin() const { return orig; }
  [[nodiscard]] inline Vec3 direction() const { return dir; }

 private:
  Vec3 orig;
  Vec3 dir;
};



#endif //RAY_H
