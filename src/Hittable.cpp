#include "Hittable.h"

// nothing to do now...
void hitRecord::setFaceNormal(const ray &r, const vec3 &outwardNormal)
{
    // Sets the hit record normal vector.
    // NOTE: the parameter 'outwardNormal' is assumed to have unit length!

    frontFace = dot(r.direction(), outwardNormal) < 0;
    normal    = frontFace ? outwardNormal : -outwardNormal;
}
