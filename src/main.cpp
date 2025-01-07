#include "Common.h"
#include "Hittable.h"
#include "HittableList.h"
#include "Interval.h"
#include "Sphere.h"
#include "Vector.h"
#include <memory>

// const by default are better. Fight me.

color rayColor(const ray &r, const hittable &world)
{
    hitRecord rec;
    if (world.hit(r, interval(0, infinity), rec))
    {
        return 0.5 * (rec.normal + color(1, 1, 1));
    }

    const vec3 unitDirection = unit_vector(r.direction());
    const auto a             = 0.5 * (unitDirection.y() + 1.0);
    return (1.0 - a) * color(1.0, 1.0, 1.0) + a * color(0.5, 0.7, 1.0);
}

int main()
{
    const auto aspectRatio = 16.0 / 9.0;
    const int imageWidth   = 400;

    // Calculate the image height and ensure that its atleast 1.
    const int imageHeightP = int(imageWidth / aspectRatio);  // P for pseudo
    const int imageHeight  = (imageHeightP < 1) ? 1 : imageHeightP;

    // World
    hittableList world;

    //                                  coordinates     radius
    world.add(std::make_shared<sphere>(point3(0, 0, -1), 0.5));
    world.add(std::make_shared<sphere>(point3(0, -100.5, -1), 100));

    // Camera

    const auto focalLength    = 1.0;
    const auto viewportHeight = 2.0;
    const auto viewPortWidth =
        viewportHeight * (double(imageWidth) / imageHeight);
    const auto cameraCenter = point3(0, 0, 0);

    // Calculate the vectors across the horizontal and down the vertical
    // viewport edges.

    const auto viewportU = vec3(viewPortWidth, 0, 0);
    const auto viewportV = vec3(0, -viewportHeight, 0);

    const auto pixelDeltaU = viewportU / imageWidth;
    const auto pixelDeltaV = viewportV / imageHeight;

    const auto viewportUpperLeft =
        cameraCenter - vec3(0, 0, focalLength) - viewportU / 2 - viewportV / 2;

    const auto pixel00Loc =
        viewportUpperLeft + 0.5 * (pixelDeltaU + pixelDeltaV);

    std::cout << "P3\n" << imageWidth << " " << imageHeight << "\n255\n";

    for (int j = 0; j < imageHeight; j++)
    {
        std::clog << "\rScanlines remaning: " << (imageHeight - j) << " "
                  << std::flush;

        for (int i = 0; i < imageWidth; i++)
        {
            const auto pixelCenter =
                pixel00Loc + (i * pixelDeltaU) + (j * pixelDeltaV);

            const auto rayDirection = pixelCenter - cameraCenter;
            const ray r(cameraCenter, rayDirection);

            const color pixelColor = rayColor(r, world);
            writeColor(std::cout, pixelColor);
        }
    }

    std::clog << "\rDone.                   \n";
}
