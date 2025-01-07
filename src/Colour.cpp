#include "Colour.h"

void writeColor(std::ostream &out, const color &pixelColour)
{
    auto r = pixelColour.x();
    auto g = pixelColour.y();
    auto b = pixelColour.z();

    int rbyte = int(255.999 * r);
    int gbyte = int(255.999 * g);
    int bbyte = int(255.999 * b);

    out << rbyte << " " << gbyte << " " << bbyte << "\n";
}
