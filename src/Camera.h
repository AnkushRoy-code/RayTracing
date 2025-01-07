#ifndef INCLUDE_SRC_CAMERA_H_
#define INCLUDE_SRC_CAMERA_H_

#include "Hittable.h"
#include "Vector.h"

class camera
{
public:
    double aspectRatio  = 1.0;
    int imageWidth      = 100;
    int samplesPerPixel = 10;  // Count of random samples for each pixel
    int maxDepth        = 10;  // Maximum no of ray bounces into scene

    void render(const hittable &world);

private:
    void initialise();
    [[nodiscard]] color
        rayColor(const ray &r, int depth, const hittable &world) const;
    [[nodiscard]] ray getRay(int i, int j) const;
    [[nodiscard]] vec3 sample_square() const;

    int imageHeight {};
    point3 center {};
    point3 pixel00Loc {};
    vec3 pixelDeltaU {};
    vec3 pixelDeltaV {};
    double pixelSampleScale {};
};

#endif  // INCLUDE_SRC_CAMERA_H_
