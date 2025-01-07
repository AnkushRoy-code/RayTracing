#include "Camera.h"
#include "Colour.h"
#include "Common.h"
#include "Vector.h"

void camera::render(const hittable &world)
{
    initialise();

    std::cout << "P3\n" << imageWidth << " " << imageHeight << "\n255\n";

    for (int j = 0; j < imageHeight; j++)
    {
        std::clog << "\rScanlines remaining: " << (imageHeight - j) << " "
                  << std::flush;

        for (int i = 0; i < imageWidth; i++)
        {
            color pixelColor(0, 0, 0);
            for (int sample = 0; sample < samplesPerPixel; sample++)
            {
                ray r = getRay(i, j);
                pixelColor += rayColor(r, maxDepth, world);
            }
            writeColor(std::cout, pixelSampleScale * pixelColor);
        }
    }

    std::clog << "\rDone.               \n";
}

void camera::initialise()
{
    imageHeight = int(imageWidth / aspectRatio);
    imageHeight = (imageHeight < 1) ? 1 : imageHeight;

    pixelSampleScale = 1.0 / samplesPerPixel;

    center = point3(0, 0, 0);

    // Determine viewport dimensions.
    const auto focalLength    = 1.0;
    const auto viewportHeight = 2.0;
    const auto viewportWidth =
        viewportHeight * (double(imageWidth) / imageHeight);

    // Calculate the vectors across the horizontal and down the veirtical edges.
    const auto viewportU = vec3(viewportWidth, 0, 0);
    const auto viewportV = vec3(0, -viewportHeight, 0);

    // Calculate the horizontal and vertical delta vectors from pixel to pixel
    pixelDeltaU = viewportU / imageWidth;
    pixelDeltaV = viewportV / imageHeight;

    const auto viewportUpperLeft =
        center - vec3(0, 0, focalLength) - viewportU / 2 - viewportV / 2;

    pixel00Loc = viewportUpperLeft + 0.5 * (pixelDeltaU + pixelDeltaV);
}

vec3 camera::sample_square() const
{
    // Returns the vector to a random point in the [-.5,-.5]-[+.5,+.5] unit
    // square.
    return {randomDouble() - 0.5, randomDouble() - 0.5, 0};
}

ray camera::getRay(int i, int j) const
{
    // Construct a camera ray originating from the origina nd directed at
    // randomly sample point around the pixel location i, j

    const auto offset      = sample_square();
    const auto pixelSample = pixel00Loc + ((i + offset.x()) * pixelDeltaU)
                             + ((j + offset.y()) * pixelDeltaV);

    const auto rayOrigin = center;
    const auto rayDir    = pixelSample - rayOrigin;

    return {rayOrigin, rayDir};
}

color camera::rayColor(const ray &r, int depth, const hittable &world) const
{
    if (depth <= 0)
    {
        return {0, 0, 0};
    }

    hitRecord rec;

    if (world.hit(r, interval(0.001, infinity), rec))
    {
        vec3 direction = rec.normal + random_unit_vector();
        return 0.5 * rayColor(ray(rec.p, direction), depth - 1, world);
    }

    const vec3 unitDir = unit_vector(r.direction());
    const auto a       = 0.5 * (unitDir.y() + 1.0);
    return (1.0 - a) * color(1.0, 1.0, 1.0) + a * color(0.5, 0.7, 1.0);
}
