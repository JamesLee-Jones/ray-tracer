#ifndef IMAGE_WRITER_H
#define IMAGE_WRITER_H

#include <string>
#include <fstream>
#include <iostream>
#include <utility>
#include <vector>
#include <memory>

class ImageWriter {
 public:
  explicit ImageWriter(std::string filename)
      : filename{std::move(filename)}, file{std::make_unique<std::ofstream>()} {}

  virtual void write_image(Image &image) const = 0;

  virtual bool open() {
    file->open(filename);
    return is_open();
  }

  [[nodiscard]] bool is_open() const {
    return file->is_open();
  }

  bool close() {
    file->close();
    return !is_open();
  }

 protected:
  std::string filename;
  std::unique_ptr<std::ofstream> file;
};

#endif //IMAGE_WRITER_H
