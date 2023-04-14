SET(CORE_HEADERS
        core/camera.h
        core/colour.h
        core/image.h
        core/image_writer.h
        core/primitive.h
        core/ppm_writer.h
        core/ray.h
        core/ray_tracer.h
        core/utilities.h
        core/vec3.h)

FILE(GLOB SOURCE
        src/materials/*
        src/primitives/*)

INCLUDE_DIRECTORIES(src)
INCLUDE_DIRECTORIES(src/core)

ADD_LIBRARY(ray-tracer STATIC
        ${CORE_HEADERS}
        ${SOURCE})

ADD_EXECUTABLE(ray_tracer_exe main.cpp)

SET_TARGET_PROPERTIES(ray-tracer PROPERTIES LINKER_LANGUAGE CXX)
SET_TARGET_PROPERTIES(ray_tracer_exe PROPERTIES OUTPUT_NAME ray_tracer)
TARGET_LINK_LIBRARIES(ray_tracer_exe ray-tracer)
