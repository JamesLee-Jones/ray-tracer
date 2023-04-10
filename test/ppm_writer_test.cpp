#include <vector>
#include <fstream>
#include <vec3.h>
#include <image.h>
#include <ppm_writer.h>
#include <gtest/gtest.h>

TEST(PPMWriterTest, PPMWriterDeclaration) {
  PPMWriter writer = PPMWriter("test.ppm");
  ASSERT_FALSE(writer.is_open());
}

TEST(PPMWriterTest, PPMWriterOpen) {
  PPMWriter writer = PPMWriter("test.ppm");
  writer.open();
  ASSERT_TRUE(writer.is_open());
}

TEST(PPMWriterTest, PPMWriterClose) {
  PPMWriter writer = PPMWriter("test.ppm");
  writer.open();
  writer.close();
  ASSERT_FALSE(writer.is_open());
}

TEST(PPMWriterTest, PPMWriterWriteImage) {
  std::string filename = "test.ppm";
  Image image = Image(2, 2);
  image.set_pixel(0, 1, Vec3(255, 0, 0));
  image.set_pixel(1, 1, Vec3(0, 255, 0));
  image.set_pixel(0, 0, Vec3(0, 0, 255));
  image.set_pixel(1, 0, Vec3(255, 255, 255));
  PPMWriter writer = PPMWriter(filename);
  writer.open();
  writer.write_image(image);
  writer.close();
  std::ifstream file(filename);
  ASSERT_TRUE(file.is_open());
  std::string line;
  std::getline(file, line);
  ASSERT_EQ(line, "P3");
  std::getline(file, line);
  ASSERT_EQ(line, "2 2");
  std::getline(file, line);
  ASSERT_EQ(line, "255");
  std::getline(file, line);
  ASSERT_EQ(line, "255 0 0");
  std::getline(file, line);
  ASSERT_EQ(line, "0 255 0");
  std::getline(file, line);
  ASSERT_EQ(line, "0 0 255");
  std::getline(file, line);
  ASSERT_EQ(line, "255 255 255");
}
