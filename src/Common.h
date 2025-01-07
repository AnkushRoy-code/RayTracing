#ifndef INCLUDE_SRC_COMMON_H_
#define INCLUDE_SRC_COMMON_H_

#include <cmath>
#include <iostream>
#include <limits>
#include <memory>
#include <random>

// Constants

const double infinity = std::numeric_limits<double>::infinity();
const double pi       = 3.1415926535897932385;

// Utility functions

inline double degreesToRad(double degrees)
{
    return degrees * pi / 180.0;
}

inline double randomDouble()
{
    static std::uniform_real_distribution<double> dis(0.0, 1.0);
    static std::mt19937 gen;
    return dis(gen);
}

inline double randomDouble(double min, double max)
{
    return min + (max - min) * randomDouble();
}

// Common headers

#include "Colour.h"
#include "Ray.h"
#include "Interval.h"
#include "Vector.h"

#endif  // INCLUDE_SRC_COMMON_H_
