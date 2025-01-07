#ifndef INCLUDE_SRC_HITTABLELIST_H_
#define INCLUDE_SRC_HITTABLELIST_H_

#include "Hittable.h"

#include <memory>
#include <vector>

class hittableList : public hittable
{
public:
    hittableList() = default;
    explicit hittableList(const std::shared_ptr<hittable> &object);

    void clear();
    void add(const std::shared_ptr<hittable> &object);

    bool hit(const ray &r, interval rayT, hitRecord &rec) const override;

private:
    std::vector<std::shared_ptr<hittable>> objects;
};

#endif  // INCLUDE_SRC_HITTABLELIST_H_
