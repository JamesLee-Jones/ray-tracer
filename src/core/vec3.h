#ifndef VEC3_H
#define VEC3_H

#include "utilities.h"

#include <cmath>
#include <random>
#include <stdexcept>

class Vec3 {
 public:
  Vec3() : e{0, 0, 0} {}
  Vec3(double x, double y, double z) : e{x, y, z} {}

  [[nodiscard]] double x() const { return e[0]; }
  [[nodiscard]] double y() const { return e[1]; }
  [[nodiscard]] double z() const { return e[2]; }

  Vec3 operator-() const { return {-e[0], -e[1], -e[2]}; }
  double operator[](int i) const { return e[i]; }
  double &operator[](int i) { return e[i]; }

  Vec3& operator+=(const Vec3 &v) {
    e[0] += v[0];
    e[1] += v[1];
    e[2] += v[2];
    return *this;
  }

  Vec3& operator*=(const double m) {
    e[0] *= m;
    e[1] *= m;
    e[2] *= m;
    return *this;
  }

  Vec3& operator/=(const double m) {
    e[0] /= m;
    e[1] /= m;
    e[2] /= m;
    return *this;
  }

  [[nodiscard]] double length() const {
    return sqrt(e[0] * e[0] + e[1] * e[1] + e[2] * e[2]);
  }

  [[nodiscard]] bool near_zero(double epsilon=1e-8) const {
    return (fabs(x()) < epsilon) && (fabs(y()) < epsilon) && (fabs(z()) < epsilon);
  }

 private:
  double e[3];
};

inline Vec3 operator+(const Vec3 &u, const Vec3 &v) {
  return {u.x() + v.x(), u.y() + v.y(), u.z() + v.z()};
}

inline Vec3 operator-(const Vec3 &u, const Vec3 &v) {
  return {u.x() - v.x(), u.y() - v.y(), u.z() - v.z()};
}

inline Vec3 operator*(const Vec3 &u, const Vec3 &v) {
  return {u.x() * v.x(), u.y() * v.y(), u.z() * v.z()};
}

inline Vec3 operator*(const Vec3 &u, const double m) {
  return {u.x() * m, u.y() * m, u.z() * m};
}

inline Vec3 operator*(const double m, const Vec3 &u) {
  return {u.x() * m, u.y() * m, u.z() * m};
}

inline Vec3 operator/(const Vec3 &u, const double d) {
  return (1/d) * u;
}

inline bool operator==(const Vec3 &lhs, const Vec3 &rhs) {
  double epsilon = 1e-8;
  return (fabs(lhs.x() - rhs.x()) < epsilon) &&
         (fabs(lhs.y() - rhs.y()) < epsilon) &&
         (fabs(lhs.z() - rhs.z()) < epsilon);
}

inline double dot(const Vec3 &u, const Vec3 &v) {
  return u.x() * v.x() + u.y() * v.y() + u.z() * v.z();
}

inline Vec3 cross (const Vec3 &u, const Vec3 &v) {
  return {u.y() * v.z() - u.z() * v.y(),
              u.z() * v.x() - u.x() * v.z(),
              u.x() * v.y() - u.y() * v.x()};
}

inline Vec3 normalize(const Vec3 &u) {
  return u / u.length();
}

inline Vec3 reflect(const Vec3 &i, const Vec3 &n) {
  if (fabs(n.length() - 1) > 1e-8) {
    throw std::invalid_argument("n must be normalised.");
  }
  return i - 2.0 * dot(n, i) * n;
}

inline static Vec3 random_vector(double lower, double upper) {
  return {random_double(lower, upper),
          random_double(lower, upper),
          random_double(lower, upper)};
}

inline static Vec3 random_vector() {
  return random_vector(0.0, 1.0);
}

inline static Vec3 random_in_unit_sphere() {
  while (true) {
    Vec3 v = random_vector(-1, 1);
    if (v.length() > 1) continue;
    return v;
  }
}

inline static Vec3 random_unit_vector() {
  return normalize(random_vector());
}

#endif //VEC3_H
