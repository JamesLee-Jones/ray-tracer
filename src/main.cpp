#include "image.h"
#include "ppm_writer.h"
#include "camera.h"
#include "sphere.h"
#include "plane.h"
#include "intersectable_list.h"
#include "ray_tracer.h"

#include <memory>

int main() {
  Image image = Image(640, 480);
  PPMWriter iw = PPMWriter("test.ppm");

  auto camera = Camera();

  IntersectableList world = IntersectableList();
  auto mat_center = std::make_shared<Diffuse>(Vec3(0.7, 0.3, 0.3));
  auto mat_left = std::make_shared<Metal>(Vec3(0.8, 0.8, 0.3));
  auto mat_right = std::make_shared<Metal>(Vec3(0.8, 0.6, 0.2));
  auto mat_plane = std::make_shared<Diffuse>(Vec3(0.8, 0.8, 0.0));
  world.add(std::make_shared<Sphere>(Vec3(0, -100.5, -1), 100, mat_plane));
  world.add(std::make_shared<Sphere>(Vec3(0, 0, -1), 0.5, mat_center));
  world.add(std::make_shared<Sphere>(Vec3(-1, 0, -1), 0.5, mat_left));
  world.add(std::make_shared<Sphere>(Vec3(1, 0, -1), 0.5, mat_right));
  world.add(std::make_shared<Plane>(Vec3(0, -1, 0), Vec3(0, 1, 0), mat_plane));

  RayTracer ray_tracer = RayTracer(camera, world, image);
  ray_tracer.process(50, 100);

  iw.open();
  iw.write_image(image);
  iw.close();
}
