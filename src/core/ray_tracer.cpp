#include "ray_tracer.h"

Vec3 RayTracer::ray_colour(Ray &ray, int max_depth) {
  if (max_depth <= 0) return {0, 0, 0};

  if (Intersection intersection = scene.intersect(ray, 0.001, std::numeric_limits<double>::infinity());
      intersection.hit) {
    Ray scattered;
    Vec3 attenuation;
    if (intersection.material->scatter(ray, intersection, attenuation, scattered)) {
      if(auto col = ray_colour(scattered, max_depth-1); col.near_zero()) {
        return attenuation;
      }else {
        return attenuation * col;
      }
    }
    return {0, 0, 0};
  }

  // This is the skybox and should be configurable in the future.
  Vec3 dir = Vec3::normalize(ray.direction());
  auto t = 0.5 * (dir.y() + 1.0); // Interpolate
  return (1 - t) * Vec3(1, 1, 1) + t * Vec3(0.5, 0.7, 1);
}

void RayTracer::process(int max_depth, int samples, int num_threads=1) {
  std::vector<std::thread> threads = {};
  for (int t_id = 0; t_id < num_threads; t_id++) {
    std::thread t {&RayTracer::process_thread, this, max_depth, samples, t_id, num_threads};
    threads.push_back(std::move(t));
  }

  for (int t_id = 0; t_id < num_threads; t_id++) {
    threads[t_id].join();
  }
}

void RayTracer::process_thread(int max_depth, int samples, int thread_id, int num_threads) {
  for (int j = image.get_height()-1-thread_id; j >= 0; j-=num_threads) {
    for (int i = 0; i < image.get_width(); i++) {
      Vec3 pixel_col = Vec3(0, 0, 0);
      for (int k = 0; k < samples; k++) {
        auto u = (double(i) + random_double()) / (image.get_width()-1);
        auto v = (double(j) + random_double()) / (image.get_height()-1);
        Ray ray = camera.get_ray(u, v);
        pixel_col += ray_colour(ray, max_depth);
      }
      image.set_pixel(i, j, convert_colour(pixel_col, samples));
    }
  }
}
