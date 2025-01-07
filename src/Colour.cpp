#include "Colour.h"
#include "Interval.h"
#include <cmath>

inline double linearToGamma(double linearComponent)
{
    if (linearComponent > 0)
    {
        return std::sqrt(linearComponent);
    }
    return 0;
}

void writeColor(std::ostream &out, const color &pixelColour)
{
    auto r = pixelColour.x();
    auto g = pixelColour.y();
    auto b = pixelColour.z();

    r = linearToGamma(r);
    g = linearToGamma(g);
    b = linearToGamma(b);

    static const interval intensity(0.000, 0.999);
    int rbyte = int(255.999 * intensity.clamp(r));
    int gbyte = int(255.999 * intensity.clamp(g));
    int bbyte = int(255.999 * intensity.clamp(b));

    out << rbyte << " " << gbyte << " " << bbyte << "\n";
}
