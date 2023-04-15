#ifndef CAMERA_H
#define CAMERA_H

#include "ray.h"
#include "vec3.h"

#include <stdexcept>

class Camera {
 public:
  explicit Camera(Vec3 origin = Vec3(0, 0, 0),
                  Vec3 direction = Vec3(0, 0, -1),
                  double aspect_ratio = 16.0 / 9.0,
                  double frame_height = 2.0,
                  double focal_length = 1.0
  );

  [[nodiscard]] inline Vec3 get_pos() const { return origin; }
  inline void set_pos(Vec3 &pos) { origin = pos; }

  [[nodiscard]] inline Vec3 get_dir() const { return dir; }
  inline void set_dir(Vec3 &direction) { dir = direction; }

  [[nodiscard]] Ray get_ray(double u, double v) const;

 private:
  Vec3 origin;
  Vec3 dir;
  Vec3 horizontal;
  Vec3 vertical;
  Vec3 lower_left;
};

#endif //CAMERA_H
