#ifndef CAMERA_H
#define CAMERA_H

#include "ray.h"

#include <stdexcept>

class Camera {
 public:
  explicit Camera(Vec3 origin = Vec3(0, 0, 0),
         Vec3 direction = Vec3(0, 0, -1),
         double aspect_ratio = 16.0 / 9.0,
         double frame_height = 2.0,
         double focal_length = 1.0
  ) : origin{origin}, dir{direction} {
    horizontal = Vec3(frame_height * aspect_ratio, 0, 0);
    vertical = Vec3(0, frame_height, 0);
    lower_left = origin + focal_length * dir - horizontal / 2 - vertical / 2;
  }

  [[nodiscard]] Vec3 get_pos() const { return origin; }
  void set_pos(Vec3 &pos) { origin = pos; }

  [[nodiscard]] Vec3 get_dir() const { return dir; }
  void set_dir(Vec3 &direction) { dir = direction; }

  [[nodiscard]] Ray get_ray(double u, double v) const {
    Vec3 ray_dir = normalize(lower_left + u * horizontal + v * vertical - origin);
    return {origin, ray_dir};
  }

 private:
  Vec3 origin;
  Vec3 dir;
  Vec3 horizontal;
  Vec3 vertical;
  Vec3 lower_left;
};

#endif //CAMERA_H
