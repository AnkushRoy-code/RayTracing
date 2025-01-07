#include "HittableList.h"
#include "Hittable.h"
#include "Interval.h"
#include <memory>

hittableList::hittableList(const std::shared_ptr<hittable> &object)
{
    add(object);
}

void hittableList::clear()
{
    objects.clear();
}

void hittableList::add(const std::shared_ptr<hittable> &object)
{
    objects.push_back(object);
}

bool hittableList::hit(const ray &r, interval rayT, hitRecord &rec) const
{
    hitRecord tempRec;
    bool hitAnything  = false;
    auto closestSoFar = rayT.max;

    for (const auto &object: objects)
    {
        if (object->hit(r, interval(rayT.min, closestSoFar), tempRec))
        {
            hitAnything  = true;
            closestSoFar = tempRec.t;
            rec          = tempRec;
        }
    }

    return hitAnything;
}
