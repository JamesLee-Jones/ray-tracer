#include <vec3.h>
#include <ray.h>
#include <plane.h>
#include <material.h>
#include <gtest/gtest.h>
#include <memory>

TEST(PlaneTests, PlaneDeclaration) {
  Vec3 plane_origin = Vec3(0, 0, 0);
  Vec3 plane_norm = Vec3(0, 1, 0);
  std::shared_ptr<Material> plane_material = std::make_shared<Diffuse>(Vec3(0, 0, 0));
  Plane plane = Plane(plane_origin, plane_norm, plane_material);
  ASSERT_DOUBLE_EQ(plane.getNormal().x(), plane_norm.x());
  ASSERT_DOUBLE_EQ(plane.getNormal().y(), plane_norm.y());
  ASSERT_DOUBLE_EQ(plane.getNormal().z(), plane_norm.z());
  ASSERT_DOUBLE_EQ(plane.getPoint().x(), plane_origin.x());
  ASSERT_DOUBLE_EQ(plane.getPoint().y(), plane_origin.y());
  ASSERT_DOUBLE_EQ(plane.getPoint().z(), plane_origin.z());
}

TEST(PlaneTests, TestSetters) {
  Vec3 plane_origin = Vec3(0, 0, 0);
  Vec3 plane_norm = Vec3(0, 1, 0);
  std::shared_ptr<Material> plane_material = std::make_shared<Diffuse>(Vec3(0, 0, 0));
  Plane plane = Plane(plane_origin, plane_norm, plane_material);
  Vec3 new_origin = Vec3(1,1,1);
  plane.setPoint(new_origin);
  EXPECT_DOUBLE_EQ(plane.getPoint().x(), new_origin.x());
  EXPECT_DOUBLE_EQ(plane.getPoint().y(), new_origin.y());
  EXPECT_DOUBLE_EQ(plane.getPoint().z(), new_origin.z());
  EXPECT_DOUBLE_EQ(plane.getNormal().x(), plane_norm.x());
  EXPECT_DOUBLE_EQ(plane.getNormal().y(), plane_norm.y());
  EXPECT_DOUBLE_EQ(plane.getNormal().z(), plane_norm.z());
  Vec3 new_normal = Vec3(1, 0, 0);
  plane.setNormal(new_normal);
  EXPECT_DOUBLE_EQ(plane.getPoint().x(), new_origin.x());
  EXPECT_DOUBLE_EQ(plane.getPoint().y(), new_origin.y());
  EXPECT_DOUBLE_EQ(plane.getPoint().z(), new_origin.z());
  EXPECT_DOUBLE_EQ(plane.getNormal().x(), new_normal.x());
  EXPECT_DOUBLE_EQ(plane.getNormal().y(), new_normal.y());
  EXPECT_DOUBLE_EQ(plane.getNormal().z(), new_normal.z());
}

TEST(PlaneTests, TestRayIntersection) {
  Vec3 plane_origin = Vec3(0, 0, 0);
  Vec3 plane_norm = Vec3(0, 1, 0);
  std::shared_ptr<Material> plane_material = std::make_shared<Diffuse>(Vec3(0, 0, 0));
  Plane plane = Plane(plane_origin, plane_norm, plane_material);
  Vec3 ray_origin = Vec3(0, 1, 0);
  Vec3 ray_dir = normalize(Vec3(1, -1, 0));
  Ray ray = Ray(ray_origin, ray_dir);
  Intersection intersection = plane.intersect(ray, 0 ,10);
  Vec3 expected_intersection = Vec3(1, 0, 0);
  Vec3 expected_normal = Vec3(0, 1, 0);
  EXPECT_TRUE(intersection.hit);
  EXPECT_DOUBLE_EQ(intersection.point.x(), expected_intersection.x());
  EXPECT_DOUBLE_EQ(intersection.point.y(), expected_intersection.y());
  EXPECT_DOUBLE_EQ(intersection.point.z(), expected_intersection.z());
  EXPECT_DOUBLE_EQ(intersection.normal.x(), expected_normal.x());
  EXPECT_DOUBLE_EQ(intersection.normal.y(), expected_normal.y());
  EXPECT_DOUBLE_EQ(intersection.normal.z(), expected_normal.z());

  ray_dir = Vec3(1, 0, 0);
  ray = Ray(ray_origin, ray_dir);
  intersection = plane.intersect(ray, 0, 10);
  EXPECT_FALSE(intersection.hit);
}
