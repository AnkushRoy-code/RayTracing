#ifndef INCLUDE_SRC_RAY_H_
#define INCLUDE_SRC_RAY_H_

#include "Vector.h"

class ray
{
public:
    ray() = default;
    ray(const point3 &origin, const vec3 &direction);

    [[nodiscard]] const point3 &origin() const;
    [[nodiscard]] const vec3 &direction() const;
    [[nodiscard]] point3 at(double t) const;

private:
    point3 orig;
    vec3 dir;
};

#endif
