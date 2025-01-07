#ifndef INCLUDE_SRC_HITTABLE_H_
#define INCLUDE_SRC_HITTABLE_H_

#include "Common.h"
#include "Interval.h"

class hitRecord
{
public:
    point3 p;
    vec3 normal;
    double t {};
    bool frontFace {};
    void setFaceNormal(const ray &r, const vec3 &outwardNormal);
};

class hittable
{
public:
    virtual ~hittable() = default;

    virtual bool hit(const ray &r, interval rayT, hitRecord &rec) const = 0;
};

#endif  // INCLUDE_SRC_HITTABLE_H_
