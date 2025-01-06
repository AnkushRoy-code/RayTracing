#ifndef INCLUDE_SRC_VECTOR_H_
#define INCLUDE_SRC_VECTOR_H_

#include <cmath>
#include <iostream>

class vec3
{
public:
    double vec[3];

    vec3();
    vec3(double e0, double e1, double e2);

    [[nodiscard]] double x() const;
    [[nodiscard]] double y() const;
    [[nodiscard]] double z() const;

    vec3 operator-() const;
    double operator[](int i) const;
    double &operator[](int i);
    vec3 &operator+=(const vec3 &v);
    vec3 &operator*=(double t);
    vec3 &operator/=(double t);

    [[nodiscard]] double length() const;
    [[nodiscard]] double length_squared() const;
};

// point3 is just an alias for vec3, but useful for geometric clarity in the
// code.
using point3 = vec3;

// Vector Utility Functions

inline std::ostream &operator<<(std::ostream &out, const vec3 &v)
{
    return out << v.vec[0] << ' ' << v.vec[1] << ' ' << v.vec[2];
}

inline vec3 operator+(const vec3 &u, const vec3 &v)
{
    return {u.vec[0] + v.vec[0], u.vec[1] + v.vec[1], u.vec[2] + v.vec[2]};
}

inline vec3 operator-(const vec3 &u, const vec3 &v)
{
    return {u.vec[0] - v.vec[0], u.vec[1] - v.vec[1], u.vec[2] - v.vec[2]};
}

inline vec3 operator*(const vec3 &u, const vec3 &v)
{
    return {u.vec[0] * v.vec[0], u.vec[1] * v.vec[1], u.vec[2] * v.vec[2]};
}

inline vec3 operator*(double t, const vec3 &v)
{
    return {t * v.vec[0], t * v.vec[1], t * v.vec[2]};
}

inline vec3 operator*(const vec3 &v, double t)
{
    return t * v;
}

inline vec3 operator/(const vec3 &v, double t)
{
    return (1 / t) * v;
}

inline double dot(const vec3 &u, const vec3 &v)
{
    return u.vec[0] * v.vec[0] + u.vec[1] * v.vec[1] + u.vec[2] * v.vec[2];
}

inline vec3 cross(const vec3 &u, const vec3 &v)
{
    return {u.vec[1] * v.vec[2] - u.vec[2] * v.vec[1],
                u.vec[2] * v.vec[0] - u.vec[0] * v.vec[2],
                u.vec[0] * v.vec[1] - u.vec[1] * v.vec[0]};
}

inline vec3 unit_vector(const vec3 &v)
{
    return v / v.length();
}

#endif
