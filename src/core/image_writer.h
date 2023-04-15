#ifndef IMAGE_WRITER_H
#define IMAGE_WRITER_H

#include <fstream>
#include <iostream>
#include <memory>
#include <string>
#include <utility>
#include <vector>

class ImageWriter {
 public:
  explicit ImageWriter(std::string filename)
      : filename{std::move(filename)}, file{std::make_unique<std::ofstream>()} {}

  virtual void write_image(Image &image) const = 0;

  inline bool open() {
    file->open(filename);
    return is_open();
  }

  [[nodiscard]] inline bool is_open() const {
    return file->is_open();
  }

  inline bool close() {
    file->close();
    return !is_open();
  }

 protected:
  std::string filename;
  std::unique_ptr<std::ofstream> file;
};

#endif //IMAGE_WRITER_H
