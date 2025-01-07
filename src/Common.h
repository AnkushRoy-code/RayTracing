#ifndef INCLUDE_SRC_COMMON_H_
#define INCLUDE_SRC_COMMON_H_

#include <cmath>
#include <iostream>
#include <limits>
#include <memory>

// Constants

const double infinity = std::numeric_limits<double>::infinity();
const double pi       = 3.1415926535897932385;

// Utility functions

inline double degreesToRad(double degrees)
{
    return degrees * pi / 180.0;
}

// Common headers

#include "Colour.h"
#include "Ray.h"
#include "Interval.h"
#include "Vector.h"

#endif  // INCLUDE_SRC_COMMON_H_
