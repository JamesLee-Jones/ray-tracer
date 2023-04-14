#include "core/camera.h"
#include "core/ray.h"
#include "core/vec3.h"

#include <gtest/gtest.h>

TEST(CameraTest, CameraDeclaration) {
  Camera camera = Camera();
  ASSERT_DOUBLE_EQ(camera.get_pos().x(), 0);
  ASSERT_DOUBLE_EQ(camera.get_pos().y(), 0);
  ASSERT_DOUBLE_EQ(camera.get_pos().z(), 0);
  ASSERT_DOUBLE_EQ(camera.get_dir().x(), 0);
  ASSERT_DOUBLE_EQ(camera.get_dir().y(), 0);
  ASSERT_DOUBLE_EQ(camera.get_dir().z(), -1);

  Vec3 camera_orig = Vec3(1, 1, 1);
  Vec3 camera_direction = Vec3(-1, 4, 5);
  camera = Camera(camera_orig, camera_direction);
  ASSERT_DOUBLE_EQ(camera.get_pos().x(), camera_orig.x());
  ASSERT_DOUBLE_EQ(camera.get_pos().y(), camera_orig.y());
  ASSERT_DOUBLE_EQ(camera.get_pos().z(), camera_orig.z());
  ASSERT_DOUBLE_EQ(camera.get_dir().x(), camera_direction.x());
  ASSERT_DOUBLE_EQ(camera.get_dir().y(), camera_direction.y());
  ASSERT_DOUBLE_EQ(camera.get_dir().z(), camera_direction.z());
}

TEST(CameraTest, CameraSetters) {
  Vec3 camera_orig = Vec3(1, 1, 1);
  Camera camera = Camera();
  camera.set_pos(camera_orig);
  ASSERT_DOUBLE_EQ(camera.get_pos().x(), camera_orig.x());
  ASSERT_DOUBLE_EQ(camera.get_pos().y(), camera_orig.y());
  ASSERT_DOUBLE_EQ(camera.get_pos().z(), camera_orig.z());
  ASSERT_DOUBLE_EQ(camera.get_dir().x(), 0);
  ASSERT_DOUBLE_EQ(camera.get_dir().y(), 0);
  ASSERT_DOUBLE_EQ(camera.get_dir().z(), -1);

  Vec3 camera_direction = Vec3(-1, 4, 5);
  camera.set_dir(camera_direction);
  ASSERT_DOUBLE_EQ(camera.get_pos().x(), camera_orig.x());
  ASSERT_DOUBLE_EQ(camera.get_pos().y(), camera_orig.y());
  ASSERT_DOUBLE_EQ(camera.get_pos().z(), camera_orig.z());
  ASSERT_DOUBLE_EQ(camera.get_dir().x(), camera_direction.x());
  ASSERT_DOUBLE_EQ(camera.get_dir().y(), camera_direction.y());
  ASSERT_DOUBLE_EQ(camera.get_dir().z(), camera_direction.z());
}

TEST(CameraTest, CameraGetRay) {
  Vec3 camera_orig = Vec3(0, 0, 0);
  Vec3 camera_direction = Vec3(0, 0, 1);
  Camera camera = Camera(camera_orig, camera_direction, 16.0/9.0, 2.0, 1.0);
  Ray ray = camera.get_ray(0.5, 0.5);
  ASSERT_EQ(ray.origin().x(), camera_orig.x());
  ASSERT_EQ(ray.origin().y(), camera_orig.y());
  ASSERT_EQ(ray.origin().z(), camera_orig.z());
  ASSERT_EQ(ray.direction().x(), camera_direction.x());
  ASSERT_EQ(ray.direction().y(), camera_direction.y());
  ASSERT_EQ(ray.direction().z(), camera_direction.z());
}
