set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(Threads REQUIRED)

add_executable(ray_tracer main.cpp vec3.h ray.h sphere.h intersectable.h plane.h camera.h intersectable_list.h image_writer.h ppm_writer.h image.h colour.h material.h ray_tracer.h)

target_link_libraries(ray_tracer PRIVATE Threads::Threads)
