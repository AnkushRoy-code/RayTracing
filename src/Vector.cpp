#include "Vector.h"

vec3::vec3() : vec {0, 0, 0} {}
vec3::vec3(double e0, double e1, double e2) : vec {e0, e1, e2} {}

double vec3::x() const
{
    return vec[0];
}

double vec3::y() const
{
    return vec[1];
}

double vec3::z() const
{
    return vec[2];
}

vec3 vec3::operator-() const
{
    return {-vec[0], -vec[1], -vec[2]};
}

double vec3::operator[](int i) const
{
    return vec[i];
}

double &vec3::operator[](int i)
{
    return vec[i];
}

vec3 &vec3::operator+=(const vec3 &v)
{
    vec[0] += v.vec[0];
    vec[1] += v.vec[1];
    vec[2] += v.vec[2];
    return *this;
}

vec3 &vec3::operator*=(double t)
{
    vec[0] *= t;
    vec[1] *= t;
    vec[2] *= t;
    return *this;
}

vec3 &vec3::operator/=(double t)
{
    return *this *= 1 / t;
}

double vec3::length() const
{
    return std::sqrt(length_squared());
}

double vec3::length_squared() const
{
    return vec[0] * vec[0] + vec[1] * vec[1] + vec[2] * vec[2];
}
