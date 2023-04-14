#include "core/vec3.h"
#include "primatives/sphere.h"
#include "core/ray.h"
#include <gtest/gtest.h>

TEST(SphereTests, TestDeclaration) {
  Vec3 center = Vec3(0, 0, 0);
  double radius = 1;
  std::shared_ptr<Material> sphere_material = std::make_shared<Diffuse>(Vec3(0, 0, 0));
  Sphere s = Sphere(center, radius, sphere_material);
  EXPECT_DOUBLE_EQ(s.getCenter().x(), center.x());
  EXPECT_DOUBLE_EQ(s.getCenter().y(), center.y());
  EXPECT_DOUBLE_EQ(s.getCenter().z(), center.z());
  EXPECT_DOUBLE_EQ(s.getRadius(), radius);
}

TEST(SphereTests, TestSetters) {
  Vec3 center = Vec3(0, 0, 0);
  double radius = 1;
  std::shared_ptr<Material> sphere_material = std::make_shared<Diffuse>(Vec3(0, 0, 0));
  Sphere s = Sphere(center, radius, sphere_material);
  Vec3 new_centre = Vec3(1,1,1);
  s.setCenter(new_centre);
  EXPECT_DOUBLE_EQ(s.getCenter().x(), new_centre.x());
  EXPECT_DOUBLE_EQ(s.getCenter().y(), new_centre.y());
  EXPECT_DOUBLE_EQ(s.getCenter().z(), new_centre.z());
  EXPECT_DOUBLE_EQ(s.getRadius(), radius);
  double new_radius = 4.4;
  s.setRadius(new_radius);
  EXPECT_DOUBLE_EQ(s.getCenter().x(), new_centre.x());
  EXPECT_DOUBLE_EQ(s.getCenter().y(), new_centre.y());
  EXPECT_DOUBLE_EQ(s.getCenter().z(), new_centre.z());
  EXPECT_DOUBLE_EQ(s.getRadius(), new_radius);
}

TEST(SphereTests, TestNormalAt) {
  Vec3 center = Vec3(0, 0, 0);
  double radius = 1;
  std::shared_ptr<Material> sphere_material = std::make_shared<Diffuse>(Vec3(0, 0, 0));
  Sphere s = Sphere(center, radius, sphere_material);
  Vec3 normal_point = Vec3(1, 0, 0);
  EXPECT_DOUBLE_EQ(s.normalAt(normal_point).x(), normal_point.x());
  EXPECT_DOUBLE_EQ(s.normalAt(normal_point).y(), normal_point.y());
  EXPECT_DOUBLE_EQ(s.normalAt(normal_point).z(), normal_point.z());
  normal_point = normalize(Vec3(1, 2, 3));
  EXPECT_DOUBLE_EQ(s.normalAt(normal_point).x(), normal_point.x());
  EXPECT_DOUBLE_EQ(s.normalAt(normal_point).y(), normal_point.y());
  EXPECT_DOUBLE_EQ(s.normalAt(normal_point).z(), normal_point.z());
}

TEST(SphereTests, TestExternalRayIntersection) {
  Vec3 center = Vec3(0, 0, 2);
  double radius = 1;
  std::shared_ptr<Material> sphere_material = std::make_shared<Diffuse>(Vec3(0, 0, 0));
  Sphere s = Sphere(center, radius, sphere_material);
  Vec3 ray_origin = Vec3(0, 0, 0);
  Vec3 ray_dir = Vec3(0, 0, 1);
  Ray ray = Ray(ray_origin, ray_dir);
  Intersection intersection = s.intersect(ray, 0 ,10);
  Vec3 expected_intersection = Vec3(0, 0, 1);
  Vec3 expected_normal = Vec3(0, 0, -1);
  EXPECT_TRUE(intersection.hit);
  EXPECT_DOUBLE_EQ(intersection.point.x(), expected_intersection.x());
  EXPECT_DOUBLE_EQ(intersection.point.y(), expected_intersection.y());
  EXPECT_DOUBLE_EQ(intersection.point.z(), expected_intersection.z());
  EXPECT_DOUBLE_EQ(intersection.normal.x(), expected_normal.x());
  EXPECT_DOUBLE_EQ(intersection.normal.y(), expected_normal.y());
  EXPECT_DOUBLE_EQ(intersection.normal.z(), expected_normal.z());
}

TEST(SphereTests, TestInternalRayIntersection) {
  Vec3 center = Vec3(0, 0, 0);
  double radius = 1;
  std::shared_ptr<Material> sphere_material = std::make_shared<Diffuse>(Vec3(0, 0, 0));
  Sphere s = Sphere(center, radius, sphere_material);
  Vec3 ray_origin = Vec3(0, 0, 0);
  Vec3 ray_dir = Vec3(0, 0, 1);
  Ray ray = Ray(ray_origin, ray_dir);
  Intersection intersection = s.intersect(ray, 0 ,10);
  Vec3 expected_intersection = Vec3(0, 0, 1);
  Vec3 expected_normal = Vec3(0, 0, -1);
  EXPECT_TRUE(intersection.hit);
  EXPECT_DOUBLE_EQ(intersection.point.x(), expected_intersection.x());
  EXPECT_DOUBLE_EQ(intersection.point.y(), expected_intersection.y());
  EXPECT_DOUBLE_EQ(intersection.point.z(), expected_intersection.z());
  EXPECT_DOUBLE_EQ(intersection.normal.x(), expected_normal.x());
  EXPECT_DOUBLE_EQ(intersection.normal.y(), expected_normal.y());
  EXPECT_DOUBLE_EQ(intersection.normal.z(), expected_normal.z());
}

TEST(SphereTests, TestRayNoIntersection) {
  Vec3 center = Vec3(0, 0, 2);
  double radius = 1;
  std::shared_ptr<Material> sphere_material = std::make_shared<Diffuse>(Vec3(0, 0, 0));
  Sphere s = Sphere(center, radius, sphere_material);
  Vec3 ray_origin = Vec3(0, 0, 0);
  Vec3 ray_dir = Vec3(1, 0, 0);
  Ray ray = Ray(ray_origin, ray_dir);
  Intersection intersection = s.intersect(ray, 0, 10);
  EXPECT_FALSE(intersection.hit);
}

TEST(SphereTest, TestZeroRadius) {
  Vec3 center = Vec3(0, 0, 0);
  double radius = 0;
  std::shared_ptr<Material> sphere_material = std::make_shared<Diffuse>(Vec3(0, 0, 0));
  EXPECT_THROW(Sphere(center, radius, sphere_material), std::invalid_argument);
}
