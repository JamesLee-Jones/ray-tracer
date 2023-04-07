#ifndef RAY_H
#define RAY_H

#include <vec3.h>

class Ray {
 public:
  Ray(Vec3 origin, Vec3 direction) : orig{origin}, dir{direction} {}

  Vec3 at(double mu) const {
    return orig + mu * dir;
  }

  Vec3 origin() const { return orig; }
  Vec3 direction() const { return dir; }

 private:
  Vec3 orig;
  Vec3 dir;
};

#endif //RAY_H
