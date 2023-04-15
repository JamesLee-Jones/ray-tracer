SET(CORE_HEADERS
        core/camera.h
        core/colour.h
        core/image.h
        core/image_writer.h
        core/material.h
        core/ppm_writer.h
        core/primitive.h
        core/ray.h
        core/ray_tracer.h
        core/scene.h
        core/utilities.h
        core/vec3.h)

SET(CORE_SOURCE
        core/camera.cpp
        core/ppm_writer.cpp
        core/ray.cpp
        core/ray_tracer.cpp
        core/scene.cpp
        core/vec3.cpp)

FILE(GLOB SOURCE
        materials/*.h
        materials/*.cpp
        primitives/*.h
        primitives/*.cpp)

INCLUDE_DIRECTORIES(src)
INCLUDE_DIRECTORIES(src/core)

ADD_LIBRARY(ray-tracer STATIC
        ${CORE_SOURCE}
        ${CORE_HEADERS}
        ${SOURCE})

ADD_EXECUTABLE(ray_tracer_exe main.cpp)

SET_TARGET_PROPERTIES(ray-tracer PROPERTIES LINKER_LANGUAGE CXX)
SET_TARGET_PROPERTIES(ray_tracer_exe PROPERTIES OUTPUT_NAME ray_tracer)
TARGET_LINK_LIBRARIES(ray_tracer_exe ray-tracer)
