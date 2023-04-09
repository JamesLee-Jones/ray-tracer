#ifndef COLOUR_H
#define COLOUR_H

#include <iostream>
#include <cmath>
#include <vec3.h>

Vec3 scale_colour(Vec3 colour) {
  return {trunc(255.999 * colour.x()),
          trunc(255.999 * colour.y()),
          trunc(255.999 * colour.z())};
}

void write_colour(std::ostream &s, Vec3 colour) {
  s << colour.x() << " " << colour.y() << " " << colour.z() << std::endl;
}

#endif //COLOUR_H
