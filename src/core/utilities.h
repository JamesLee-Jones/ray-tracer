#ifndef UTILITIES_H
#define UTILITIES_H

#include <random>

static double random_double(const double lower, const double upper) {
  std::uniform_real_distribution<double> unif(lower, upper);
  std::random_device dev;
  std::mt19937 re(dev());
  return unif(re);
}

static double random_double() {
  return random_double(0, 1);
}

#endif //UTILITIES_H
