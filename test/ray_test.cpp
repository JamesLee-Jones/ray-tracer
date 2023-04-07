#include <ray.h>
#include <gtest/gtest.h>

TEST(RayTests, TestDecleration) {
  Vec3 orig = Vec3(6,7,1);
  Vec3 dir = Vec3(0,2,5);
  const Ray r = Ray(orig, dir);
  ASSERT_EQ(r.origin().x(), orig.x());
  ASSERT_EQ(r.origin().y(), orig.y());
  ASSERT_EQ(r.origin().z(), orig.z());
  ASSERT_EQ(r.direction().x(), dir.x());
  ASSERT_EQ(r.direction().y(), dir.y());
  ASSERT_EQ(r.direction().z(), dir.z());
}

TEST(RayTests, TestAt) {
  Vec3 orig = Vec3(6,7,1);
  Vec3 dir = Vec3(0.5,2.25,5.5);
  const Ray r = Ray(orig, dir);
  const Vec3 u = r.at(1);
  ASSERT_EQ(u.x(), 6.5);
  ASSERT_EQ(u.y(), 9.25);
  ASSERT_EQ(u.z(), 6.5);
  const Vec3 v = r.at(-1);
  ASSERT_EQ(v.x(), 5.5);
  ASSERT_EQ(v.y(), 4.75);
  ASSERT_EQ(v.z(), -4.5);
}
