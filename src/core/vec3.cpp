#include "vec3.h"

Vec3& Vec3::operator+=(const Vec3 &v) {
  e[0] += v[0];
  e[1] += v[1];
  e[2] += v[2];
  return *this;
}

Vec3& Vec3::operator*=(const double m) {
  e[0] *= m;
  e[1] *= m;
  e[2] *= m;
  return *this;
}

Vec3& Vec3::operator/=(const double m) {
  e[0] /= m;
  e[1] /= m;
  e[2] /= m;
  return *this;
}

[[nodiscard]] double Vec3::length() const {
  return sqrt(e[0] * e[0] + e[1] * e[1] + e[2] * e[2]);
}

[[nodiscard]] bool Vec3::near_zero(double epsilon) const {
  return (fabs(x()) < epsilon) && (fabs(y()) < epsilon) && (fabs(z()) < epsilon);
}

Vec3 operator+(const Vec3 &u, const Vec3 &v) {
  return {u.x() + v.x(), u.y() + v.y(), u.z() + v.z()};
}

Vec3 operator-(const Vec3 &u, const Vec3 &v) {
  return {u.x() - v.x(), u.y() - v.y(), u.z() - v.z()};
}

Vec3 operator*(const Vec3 &u, const Vec3 &v) {
  return {u.x() * v.x(), u.y() * v.y(), u.z() * v.z()};
}

Vec3 operator*(const Vec3 &u, const double m) {
  return {u.x() * m, u.y() * m, u.z() * m};
}

Vec3 operator*(const double m, const Vec3 &u) {
  return {u.x() * m, u.y() * m, u.z() * m};
}

Vec3 operator/(const Vec3 &u, const double d) {
  return (1/d) * u;
}

bool operator==(const Vec3 &lhs, const Vec3 &rhs) {
  double epsilon = 1e-8;
  return (fabs(lhs.x() - rhs.x()) < epsilon) &&
      (fabs(lhs.y() - rhs.y()) < epsilon) &&
      (fabs(lhs.z() - rhs.z()) < epsilon);
}

double Vec3::dot(const Vec3 &u, const Vec3 &v) {
  return u.x() * v.x() + u.y() * v.y() + u.z() * v.z();
}


Vec3 Vec3::cross(const Vec3 &u, const Vec3 &v) {
  return {u.y() * v.z() - u.z() * v.y(),
          u.z() * v.x() - u.x() * v.z(),
          u.x() * v.y() - u.y() * v.x()};
}

Vec3 Vec3::normalize(const Vec3 &u) {
  return u / u.length();
}

Vec3 Vec3::reflect(const Vec3 &i, const Vec3 &n) {
  if (fabs(n.length() - 1) > 1e-8) {
    throw std::invalid_argument("n must be normalised.");
  }
  return i - 2.0 * dot(n, i) * n;
}

Vec3 Vec3::refract(const Vec3 &v, const Vec3 &n, double eta) {
  double n_dot_v = dot(n, v);
  double k = 1.0 - pow(eta, 2) * (1 - pow(n_dot_v, 2));
  if (k < 0) {
    return {0, 0, 0};
  } else {
    return eta * v - (eta * n_dot_v + sqrt(k)) * n;
  }
}

Vec3 Vec3::random_vector(double lower, double upper) {
  return {random_double(lower, upper),
          random_double(lower, upper),
          random_double(lower, upper)};
}

Vec3 Vec3::random_vector() {
  return random_vector(0.0, 1.0);
}

Vec3 Vec3::random_in_unit_sphere() {
  while (true) {
    Vec3 v = random_vector(-1, 1);
    if (v.length() > 1) continue;
    return v;
  }
}

Vec3 Vec3::random_unit_vector() {
  return normalize(random_vector());
}




