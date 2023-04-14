#include "core/image.h"
#include "core/ppm_writer.h"
#include "core/camera.h"
#include "primatives/sphere.h"
#include "primatives/plane.h"
#include "primatives/intersectable_list.h"
#include "core/ray_tracer.h"

#include <memory>

int main() {
  Image image = Image(640, 360);
  PPMWriter iw = PPMWriter("test.ppm");

  auto camera = Camera();

  IntersectableList world = IntersectableList();
  auto mat_center = std::make_shared<Diffuse>(Vec3(0.7, 0.3, 0.3));
  auto mat_left = std::make_shared<Refraction>(1.5);
  auto mat_right = std::make_shared<Specular>(Vec3(0.8, 0.6, 0.2));
  auto mat_plane = std::make_shared<Diffuse>(Vec3(0.8, 0.8, 0.0));
  world.add(std::make_shared<Sphere>(Vec3(-0.55, 0, -1), 0.5, mat_center));
  world.add(std::make_shared<Sphere>(Vec3(0, 0, -0.75), 0.5, mat_left));
  world.add(std::make_shared<Sphere>(Vec3(0.75, 0, -1), 0.5, mat_right));
  world.add(std::make_shared<Plane>(Vec3(0, -0.5, 0), Vec3(0, 1, 0), mat_plane));

  RayTracer ray_tracer = RayTracer(camera, world, image);
  ray_tracer.process(50, 100, 10);

  iw.open();
  iw.write_image(image);
  iw.close();
}
