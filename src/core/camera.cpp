#include "camera.h"

Camera::Camera(Vec3
               origin,
               Vec3
               direction,
               double aspect_ratio,
               double frame_height,
               double focal_length
) : origin{
    origin}, dir{
    direction} {
  horizontal = Vec3(frame_height * aspect_ratio, 0, 0);
  vertical = Vec3(0, frame_height, 0);
  lower_left = origin + focal_length * dir - horizontal / 2 - vertical / 2;
}

[[nodiscard]] Ray Camera::get_ray(double u, double v) const {
  Vec3 ray_dir = Vec3::normalize(lower_left + u * horizontal + v * vertical - origin);
  return {origin, ray_dir};
}
