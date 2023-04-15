#ifndef IMAGE_H
#define IMAGE_H

#include "vec3.h"

#include <memory>
#include <vector>

using image_t = std::vector<std::vector<Vec3>>;

class Image {
 public:
  Image(int width, int height) : image(new std::vector<std::vector<Vec3>>(height,
                                                                          std::vector<Vec3>(width, Vec3(0, 0, 0)))) {}

  inline Vec3 get_pixel(int x, int y) {
    return image->at(image->size() - 1 - y).at(x);
  }
  inline void set_pixel(int x, int y, Vec3 col) {
    image->at(image->size() - 1 - y).at(x) = col;
  }

  inline int get_width() { return (int)image->at(0).size(); }
  inline int get_height() { return (int)image->size(); }

 private:
  std::unique_ptr<image_t> image;
};

#endif //IMAGE_H
