#include "core/vec3.h"
#include <gtest/gtest.h>

TEST(VectorTests, TestDefaultDeclaration) {
  const Vec3 v = Vec3();
  EXPECT_EQ(v.x(), 0);
  EXPECT_EQ(v.y(), 0);
  EXPECT_EQ(v.z(), 0);
}

TEST(VectorTests, TestDeclaration) {
  const Vec3 v1 = Vec3(1, 2, 3);
  EXPECT_EQ(v1.x(), 1);
  EXPECT_EQ(v1.y(), 2);
  EXPECT_EQ(v1.z(), 3);
  const Vec3 v2 = Vec3(0.1, 0.2, 0.3);
  EXPECT_EQ(v2.x(), 0.1);
  EXPECT_EQ(v2.y(), 0.2);
  EXPECT_EQ(v2.z(), 0.3);
}

TEST(VectorTests, TestUnaryMinux) {
  const Vec3 v = -Vec3(1, 2, 3);
  EXPECT_EQ(v.x(), -1);
  EXPECT_EQ(v.y(), -2);
  EXPECT_EQ(v.z(), -3);
}

TEST(VectorTests, TestIndexing) {
  const Vec3 v = Vec3(1, 2, 3);
  EXPECT_EQ(v[0], 1);
  EXPECT_EQ(v[1], 2);
  EXPECT_EQ(v[2], 3);
}

TEST(VectorTests, TestIndexAssignment) {
  Vec3 v = Vec3(1, 2, 3);
  v[0] = 4;
  EXPECT_EQ(v[0], 4);
  v[1] = 5;
  EXPECT_EQ(v[1], 5);
  v[2] = 6;
  EXPECT_EQ(v[2], 6);
}

TEST(VectorTests, TestPlusEquals) {
  Vec3 v1 = Vec3(1, 2, 3);
  const Vec3 v2 = Vec3(4, 5, 6);
  v1 += v2;
  EXPECT_EQ(v1.x(), 5);
  EXPECT_EQ(v1.y(), 7);
  EXPECT_EQ(v1.z(), 9);
}

TEST(VectorTests, TestTimesEquals) {
  Vec3 v = Vec3(1, 2, 3);
  v *= 2;
  EXPECT_EQ(v.x(), 2);
  EXPECT_EQ(v.y(), 4);
  EXPECT_EQ(v.z(), 6);

  v *= 0.25;
  EXPECT_EQ(v.x(), 0.5);
  EXPECT_EQ(v.y(), 1);
  EXPECT_EQ(v.z(), 1.5);
}

TEST(VectorTests, TestDivEquals) {
  Vec3 v = Vec3(3, 6, 9);
  v /= 3;
  EXPECT_EQ(v.x(), 1);
  EXPECT_EQ(v.y(), 2);
  EXPECT_EQ(v.z(), 3);

  v = Vec3(3, 6, 9);
  v /= 2;
  EXPECT_EQ(v.x(), 1.5);
  EXPECT_EQ(v.y(), 3);
  EXPECT_EQ(v.z(), 4.5);
}

TEST(VectorTests, TestLength) {
  Vec3 v = Vec3(1, 2, 3);
  double length = 3.7416573867739413;
  EXPECT_DOUBLE_EQ(v.length(), length);
}

TEST(VectorTests, TestPlus) {
  Vec3 v1 = Vec3(3, 6, 9);
  Vec3 v2 = Vec3(0.5, 2, 1.5);
  Vec3 v3 = v1 + v2;
  EXPECT_EQ(v3.x(), 3.5);
  EXPECT_EQ(v3.y(), 8);
  EXPECT_EQ(v3.z(), 10.5);
}

TEST(VectorTests, TestMinus) {
  Vec3 v1 = Vec3(3, 6, 9);
  Vec3 v2 = Vec3(0.5, 2, 1.5);
  Vec3 v3 = v1 - v2;
  EXPECT_EQ(v3.x(), 2.5);
  EXPECT_EQ(v3.y(), 4);
  EXPECT_EQ(v3.z(), 7.5);
}

TEST(VectorTests, TestMult) {
  Vec3 v1 = Vec3(3, 6, 9);
  Vec3 v2 = Vec3(0.5, 2, 1.5);
  Vec3 v3 = v1 * v2;
  EXPECT_EQ(v3.x(), 1.5);
  EXPECT_EQ(v3.y(), 12);
  EXPECT_EQ(v3.z(), 13.5);
  Vec3 v4 = v1 * 0.5;
  EXPECT_EQ(v4.x(), 1.5);
  EXPECT_EQ(v4.y(), 3);
  EXPECT_EQ(v4.z(), 4.5);
  v4 = 0.5 * v1;
  EXPECT_EQ(v4.x(), 1.5);
  EXPECT_EQ(v4.y(), 3);
  EXPECT_EQ(v4.z(), 4.5);
}

TEST(VectorTests, TestDiv) {
  Vec3 v1 = Vec3(3, 6, 9);
  Vec3 v2 = v1 / 2;
  EXPECT_EQ(v2.x(), 1.5);
  EXPECT_EQ(v2.y(), 3);
  EXPECT_EQ(v2.z(), 4.5);
}

TEST(VectorTests, TestDot) {
  Vec3 v1 = Vec3(3, 6, 9);
  Vec3 v2 = Vec3(0.5, 2, 1.5);
  double d = dot(v1, v2);
  EXPECT_EQ(d, 27);
}

TEST(VectorTests, TestCross) {
  Vec3 v1 = Vec3(3, 6, 9);
  Vec3 v2 = Vec3(0.5, 2, 1.5);
  Vec3 c = cross(v1, v2);
  EXPECT_EQ(c.x(), -9);
  EXPECT_EQ(c.y(), 0);
  EXPECT_EQ(c.z(), 3);
}

TEST(VectorTests, TestNormalize) {
  Vec3 v1 = Vec3(3, 6, 9);
  EXPECT_DOUBLE_EQ(normalize(v1).length(), 1);
}
