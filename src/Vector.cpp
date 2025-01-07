#include "Vector.h"
#include "Common.h"

vec3::vec3() : element {0, 0, 0} {}
vec3::vec3(double e0, double e1, double e2) : element {e0, e1, e2} {}

double vec3::x() const
{
    return element[0];
}

double vec3::y() const
{
    return element[1];
}

double vec3::z() const
{
    return element[2];
}

vec3 vec3::operator-() const
{
    return {-element[0], -element[1], -element[2]};
}

double vec3::operator[](int i) const
{
    return element[i];
}

double &vec3::operator[](int i)
{
    return element[i];
}

vec3 &vec3::operator+=(const vec3 &v)
{
    element[0] += v.element[0];
    element[1] += v.element[1];
    element[2] += v.element[2];
    return *this;
}

vec3 &vec3::operator*=(double t)
{
    element[0] *= t;
    element[1] *= t;
    element[2] *= t;
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
    return element[0] * element[0] + element[1] * element[1]
           + element[2] * element[2];
}

vec3 vec3::random()
{
    return {randomDouble(), randomDouble(), randomDouble()};
}

vec3 vec3::random(double min, double max)
{
    return {randomDouble(min, max), randomDouble(min, max),
            randomDouble(min, max)};
}
