#ifndef PPM_WRITER_H
#define PPM_WRITER_H

#include <image_writer.h>
#include <image.h>
#include <string>
#include <stdexcept>
#include <fstream>
#include <iostream>
#include <utility>

class PPMWriter : public ImageWriter {
 public:
  explicit PPMWriter(std::string filename) : ImageWriter(std::move(filename)) {}

  void write_image(Image &image) const override;

};

void PPMWriter::write_image(Image &image) const {
  if (!ImageWriter::is_open()) {
    throw std::logic_error("The file must be open.");
  }
  *file << "P3" << std::endl;
  *file << image.get_width() << " " << image.get_height() << std::endl;
  *file << 255 << std::endl;
  for (int j = image.get_height()-1; j >= 0; j--) {
    for (int i = 0; i < image.get_width(); i++) {
      write_colour(*file, scale_colour(image.get_pixel(i, j)));
    }
  }
}

#endif //PPM_WRITER_H
