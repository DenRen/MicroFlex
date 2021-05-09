#include <iostream>
#include "kinematic.hpp"

#define _USE_MATH_DEFINES
#include <cmath>

static inline double deg2rad (double deg) {
    return deg * M_PI / 180;
}

int main () {
    mf::planar_kinematic mech (178, 65, 180, 81.6, 230, 76);
    std::cout << mech.calc_position (deg2rad (0), deg2rad (90)) << std::endl;
}