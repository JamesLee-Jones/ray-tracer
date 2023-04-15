#ifndef RAY_TRACER_H
#define RAY_TRACER_H

#include "camera.h"
#include "colour.h"
#include "image.h"
#include "scene.h"
#include "material.h"
#include "utilities.h"

#include <functional>
#include <thread>

class RayTracer {
 public:
  RayTracer(const Camera &camera, const Scene &scene, Image &image) : camera{camera},
                                                                      scene{scene},
                                                                      image{image} {}

  Vec3 ray_colour(Ray &ray, int max_depth);

  void process(int max_depth, int samples, int num_threads);

 private:
  void process_thread(int max_depth, int samples, int thread_id, int num_threads);

  const Camera &camera;
  const Scene &scene;
  Image &image;
};

#endif //RAY_TRACER_H
