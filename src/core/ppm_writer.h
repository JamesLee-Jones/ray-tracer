#ifndef PPM_WRITER_H
#define PPM_WRITER_H

#include "colour.h"
#include "image.h"
#include "image_writer.h"

#include <fstream>
#include <iostream>
#include <string>
#include <stdexcept>
#include <utility>

class PPMWriter : public ImageWriter {
 public:
  explicit PPMWriter(std::string filename) : ImageWriter(std::move(filename)) {}

  void write_image(Image &image) const override;
};

#endif //PPM_WRITER_H
