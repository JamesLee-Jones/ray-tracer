#include <colour.h>
#include <vec3.h>
#include <gtest/gtest.h>

TEST(ColourTest, ScaleColour) {
  Vec3 colour = Vec3(1, 0, 0);
  ASSERT_EQ(scale_colour(colour).x(), 255);
  ASSERT_EQ(scale_colour(colour).y(), 0);
  ASSERT_EQ(scale_colour(colour).z(), 0);
  colour = Vec3(0, 1, 0);
  ASSERT_EQ(scale_colour(colour).x(), 0);
  ASSERT_EQ(scale_colour(colour).y(), 255);
  ASSERT_EQ(scale_colour(colour).z(), 0);
  colour = Vec3(0, 0, 1);
  ASSERT_EQ(scale_colour(colour).x(), 0);
  ASSERT_EQ(scale_colour(colour).y(), 0);
  ASSERT_EQ(scale_colour(colour).z(), 255);
  colour = Vec3(0, 0, 0);
  ASSERT_EQ(scale_colour(colour).x(), 0);
  ASSERT_EQ(scale_colour(colour).y(), 0);
  ASSERT_EQ(scale_colour(colour).z(), 0);
}
