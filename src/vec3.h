#ifndef RAY_TRACER__VEC3_H_
#define RAY_TRACER__VEC3_H_

#include <cmath>

class Vec3 {
 public:
  Vec3() : e{0, 0, 0} {}
  Vec3(double x, double y, double z) : e{x, y, z} {}

  double x() const { return e[0]; }
  double y() const { return e[1]; }
  double z() const { return e[2]; }

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

  double length() const {
    return sqrt(e[0] * e[0] + e[1] * e[1] + e[2] * e[2]);
  }

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

inline double dot(const Vec3 &u, const Vec3 &v) {
  return u.x() * v.x() + u.y() * v.y() + u.z() * v.z();
}

inline Vec3 cross (const Vec3 &u, const Vec3 &v) {
  return Vec3(u.y() * v.z() - u.z() * v.y(),
              u.z() * v.x() - u.x() * v.z(),
              u.x() * v.y() - u.y() * v.x());
}

inline Vec3 normalize(const Vec3 &u) {
  return u / u.length();
}

#endif //RAY_TRACER__VEC3_H_
