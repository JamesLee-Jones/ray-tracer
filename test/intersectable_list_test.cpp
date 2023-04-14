#include "primatives/intersectable_list.h"
#include "core/ray.h"
#include "primatives/plane.h"
#include <memory>
#include <gtest/gtest.h>

TEST(IntersectableListTest, IntersectableListClosestIntersection) {
  Vec3 ray_orig = Vec3(0, 0, 0);
  Vec3 ray_dir = Vec3(0, 0, 1);
  Ray ray = Ray(ray_orig, ray_dir);
  Vec3 plane_normal = Vec3(0, 0, -1);
  std::shared_ptr<Material> plane_material = std::make_shared<Diffuse>(Vec3(0, 0, 0));
  auto plane1 = std::make_shared<Plane>(Vec3(0, 0, 1), plane_normal, plane_material);
  auto plane2 = std::make_shared<Plane>(Vec3(0, 0, 2), plane_normal, plane_material);
  auto plane3 = std::make_shared<Plane>(Vec3(0, 0, 3), plane_normal, plane_material);
  IntersectableList list = IntersectableList();
  list.add(plane1);
  list.add(plane2);
  list.add(plane3);
  Intersection intersection = list.intersect(ray, 0, 5);
  ASSERT_TRUE(intersection.hit);
  ASSERT_DOUBLE_EQ(intersection.point.x(), 0);
  ASSERT_DOUBLE_EQ(intersection.point.y(), 0);
  ASSERT_DOUBLE_EQ(intersection.point.z(), 1);
  ASSERT_DOUBLE_EQ(intersection.normal.x(), plane_normal.x());
  ASSERT_DOUBLE_EQ(intersection.normal.y(), plane_normal.y());
  ASSERT_DOUBLE_EQ(intersection.normal.z(), plane_normal.z());
}
