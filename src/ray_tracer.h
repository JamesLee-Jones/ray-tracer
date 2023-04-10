#ifndef RAY_TRACER_SRC_RAY_TRACER_H_
#define RAY_TRACER_SRC_RAY_TRACER_H_

#include "camera.h"
#include "colour.h"
#include "intersectable_list.h"
#include "image.h"
#include "material.h"

#include <functional>
#include <thread>

class RayTracer {
 public:
  RayTracer(const Camera &camera, const IntersectableList &world, Image &image) : camera{camera},
                                                                                  world{world},
                                                                                  image{image} {}

  Vec3 ray_colour(Ray &ray, int max_depth) {
    if (max_depth <= 0) return {0, 0, 0};

    if (Intersection intersection = world.intersect(ray, 0.001, std::numeric_limits<double>::infinity());
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
    Vec3 dir = normalize(ray.direction());
    auto t = 0.5 * (dir.y() + 1.0); // Interpolate
    return (1 - t) * Vec3(1, 1, 1) + t * Vec3(0.5, 0.7, 1);
  }

  void process(int max_depth, int samples, int num_threads=1) {
    std::vector<std::thread> threads = {};
    for (int t_id = 0; t_id < num_threads; t_id++) {
      std::thread t {&RayTracer::process_thread, this, max_depth, samples, t_id, num_threads};
      threads.push_back(std::move(t));
    }

    for (int t_id = 0; t_id < num_threads; t_id++) {
      threads[t_id].join();
    }
  }

 private:
  void process_thread(int max_depth, int samples, int thread_id, int num_threads) {
    std::uniform_real_distribution<double> unif(0, 1);
    std::random_device dev;
    std::mt19937 re(dev());
    for (int j = image.get_height()-1-thread_id; j >= 0; j-=num_threads) {
      for (int i = 0; i < image.get_width(); i++) {
        Vec3 pixel_col = Vec3(0, 0, 0);
        for (int k = 0; k < samples; k++) {
          auto u = (double(i) + unif(re)) / (image.get_width()-1);
          auto v = (double(j) + unif(re)) / (image.get_height()-1);
          Ray ray = camera.get_ray(u, v);
          pixel_col += ray_colour(ray, max_depth);
        }
        image.set_pixel(i, j, convert_colour(pixel_col, samples));
      }
    }
  }

  const Camera &camera;
  const IntersectableList &world;
  Image &image;
};

#endif //RAY_TRACER_SRC_RAY_TRACER_H_
