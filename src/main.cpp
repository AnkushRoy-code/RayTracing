#include "Camera.h"
#include "HittableList.h"
#include "Sphere.h"

int main()
{
    hittableList world;

    world.add(std::make_shared<sphere>(point3(0, 0, -1), 0.5));
    world.add(std::make_shared<sphere>(point3(0, -100.5, -1), 100));

    camera cam;

    cam.aspectRatio     = 16.0 / 9.0;
    cam.imageWidth      = 400;
    cam.samplesPerPixel = 10;
    cam.maxDepth        = 5;

    cam.render(world);
}
