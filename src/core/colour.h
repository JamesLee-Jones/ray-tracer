#ifndef COLOUR_H
#define COLOUR_H

#include "vec3.h"

#include <algorithm>
#include <cmath>
#include <iostream>

Vec3 convert_colour(Vec3 colour, int samples=1) {
  auto r = colour.x();
  auto g = colour.y();
  auto b = colour.z();

  auto scale = 1.0 / samples;
  r = std::clamp(sqrt(scale * r), 0.0, 0.999);
  g = std::clamp(sqrt(scale * g), 0.0, 0.999);
  b = std::clamp(sqrt(scale * b), 0.0, 0.999);

  return {trunc(256 * r),
          trunc(256 * g),
          trunc(256 * b)};
}

void write_colour(std::ostream &s, Vec3 colour) {
  s << colour.x() << " " << colour.y() << " " << colour.z() << std::endl;
}

#endif //COLOUR_H
