#include <image.h>
#include <vec3.h>
#include <gtest/gtest.h>

TEST(ImageTest, ImageDeclaration) {
  int image_w = 640;
  int image_h = 480;
  Image image = Image(image_w, image_h);
  ASSERT_EQ(image.get_width(), image_w);
  ASSERT_EQ(image.get_height(), image_h);
}

TEST(ImageTest, ImageGetPixel) {
  int image_w = 640;
  int image_h = 480;
  Image image = Image(image_w, image_h);
  Vec3 col = Vec3(0, 0, 0);
  ASSERT_EQ(image.get_pixel(0, 0).x(), col.x());
  ASSERT_EQ(image.get_pixel(0, 0).y(), col.y());
  ASSERT_EQ(image.get_pixel(0, 0).z(), col.z());
  ASSERT_EQ(image.get_pixel(639, 0).x(), col.x());
  ASSERT_EQ(image.get_pixel(639, 0).y(), col.y());
  ASSERT_EQ(image.get_pixel(639, 0).z(), col.z());
  ASSERT_EQ(image.get_pixel(0, 479).x(), col.x());
  ASSERT_EQ(image.get_pixel(0, 479).y(), col.y());
  ASSERT_EQ(image.get_pixel(0, 479).z(), col.z());
  ASSERT_EQ(image.get_pixel(639, 479).x(), col.x());
  ASSERT_EQ(image.get_pixel(639, 479).y(), col.y());
  ASSERT_EQ(image.get_pixel(639, 479).z(), col.z());
  ASSERT_EQ(image.get_pixel(324, 235).x(), col.x());
  ASSERT_EQ(image.get_pixel(324, 235).y(), col.y());
  ASSERT_EQ(image.get_pixel(324, 235).z(), col.z());
}

TEST(ImageTest, ImageSetPixel) {
  int image_w = 640;
  int image_h = 480;
  Image image = Image(image_w, image_h);
  Vec3 col = Vec3(1, 0, 0);
  image.set_pixel(0, 0, col);
  ASSERT_EQ(image.get_pixel(0, 0).x(), 1);
  ASSERT_EQ(image.get_pixel(0, 0).y(), 0);
  ASSERT_EQ(image.get_pixel(0, 0).z(), 0);
  col = Vec3(0, 1, 0);
  image.set_pixel(324, 235, col);
  ASSERT_EQ(image.get_pixel(324, 235).x(), 0);
  ASSERT_EQ(image.get_pixel(324, 235).y(), 1);
  ASSERT_EQ(image.get_pixel(324, 235).z(), 0);
}
