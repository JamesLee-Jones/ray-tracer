cmake_minimum_required(VERSION 3.25)
project(ray_tracer)

set(CMAKE_CXX_STANDARD 23)

enable_testing()

include_directories(src)
add_subdirectory(src)
add_subdirectory(test)
