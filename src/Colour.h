#ifndef INCLUDE_SRC_COLOUR_H_
#define INCLUDE_SRC_COLOUR_H_

#include "Vector.h"

#include <iostream>

using color = vec3;

void writeColor(std::ostream &out, const color &pixelColor);

#endif  // INCLUDE_SRC_COLOUR_H_
