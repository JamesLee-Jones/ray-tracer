include(FetchContent)

FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/5376968f6948923e2411081fd9372e71a59d8e77.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

add_executable(vec3_test vec3_test.cpp)
target_link_libraries(vec3_test GTest::gtest_main)

add_executable(ray_test ray_test.cpp)
target_link_libraries(ray_test GTest::gtest_main)

add_executable(sphere_test sphere_test.cpp)
target_link_libraries(sphere_test GTest::gtest_main)

add_executable(plane_test plane_test.cpp)
target_link_libraries(plane_test GTest::gtest_main)

add_executable(camera_test camera_test.cpp)
target_link_libraries(camera_test GTest::gtest_main)

add_executable(intersectable_list_test intersectable_list_test.cpp)
target_link_libraries(intersectable_list_test GTest::gtest_main)

include(GoogleTest)
include_directories(${PROJECT_SOURCE_DIR}/src)

gtest_discover_tests(vec3_test)
gtest_discover_tests(ray_test)
gtest_discover_tests(sphere_test)
gtest_discover_tests(plane_test)
gtest_discover_tests(camera_test)
gtest_discover_tests(intersectable_list_test)
