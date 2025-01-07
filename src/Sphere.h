#ifndef INCLUDE_SRC_SPHERE_H_
#define INCLUDE_SRC_SPHERE_H_

#include "Hittable.h"
#include "Vector.h"

class sphere : public hittable
{
public:
    sphere(const point3 &center, double radius);
    bool hit(const ray &r, interval rayT, hitRecord &rec) const override;

private:
    point3 center;
    double radius {};
};

#endif  // INCLUDE_SRC_SPHERE_H_
