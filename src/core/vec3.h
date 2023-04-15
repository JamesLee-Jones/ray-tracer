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

  [[nodiscard]] inline double x() const { return e[0]; }
  [[nodiscard]] inline double y() const { return e[1]; }
  [[nodiscard]] inline double z() const { return e[2]; }

  inline Vec3 operator-() const { return {-e[0], -e[1], -e[2]}; }
  inline double operator[](int i) const { return e[i]; }
  inline double &operator[](int i) { return e[i]; }

  Vec3& operator+=(const Vec3 &v);
  Vec3& operator*=(double m);
  Vec3& operator/=(double m);

  static double dot(const Vec3 &u, const Vec3 &v);
  static Vec3 cross (const Vec3 &u, const Vec3 &v);

  static Vec3 normalize(const Vec3 &u);

  static Vec3 reflect(const Vec3 &i, const Vec3 &n);
  static Vec3 refract(const Vec3 &v, const Vec3 &n, double eta);

  static Vec3 random_vector();
  static Vec3 random_vector(double lower, double upper);
  static Vec3 random_in_unit_sphere();
  static Vec3 random_unit_vector();

  [[nodiscard]] double length() const;

  [[nodiscard]] bool near_zero(double epsilon=1e-8) const;

 private:
  double e[3];
};


Vec3 operator+(const Vec3 &u, const Vec3 &v);
Vec3 operator-(const Vec3 &u, const Vec3 &v);
Vec3 operator*(const Vec3 &u, const Vec3 &v);
Vec3 operator*(const Vec3 &u, double m);
Vec3 operator*(double m, const Vec3 &u);
Vec3 operator/(const Vec3 &u, double d);

bool operator==(const Vec3 &lhs, const Vec3 &rhs);





#endif //VEC3_H
