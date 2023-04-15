#include "ppm_writer.h"

void PPMWriter::write_image(Image &image) const {
  if (!ImageWriter::is_open()) {
    throw std::logic_error("The file must be open.");
  }
  *file << "P3" << std::endl;
  *file << image.get_width() << " " << image.get_height() << std::endl;
  *file << 255 << std::endl;
  for (int j = image.get_height()-1; j >= 0; j--) {
    for (int i = 0; i < image.get_width(); i++) {
      write_colour(*file, image.get_pixel(i, j));
    }
  }
}
