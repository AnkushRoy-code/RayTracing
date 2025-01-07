#include "Sphere.h"
#include "Hittable.h"
#include "Vector.h"
#include <cmath>

sphere::sphere(const point3 &center, double radius) :
    center(center), radius(std::fmax(0, radius))
{
}

bool sphere::hit(const ray &r, interval rayT, hitRecord &rec) const
{
    const vec3 oc = center - r.origin();
    const auto a  = r.direction().length_squared();
    const auto h  = dot(r.direction(), oc);
    const auto c  = oc.length_squared() - radius * radius;

    const auto discrimenant = h * h - a * c;

    if (discrimenant < 0)
    {
        return false;
    }

    const auto sqrtd = std::sqrt(discrimenant);

    auto root = (h - sqrtd) / a;

    if (!rayT.surrounds(root))
    {
        root = (h + sqrtd) / a;
        if (!rayT.surrounds(root))
        {
            return false;
        }
    }

    rec.t                    = root;
    rec.p                    = r.at(rec.t);
    const vec3 outwardNormal = (rec.p - center) / radius;
    rec.setFaceNormal(r, outwardNormal);

    return true;
}
