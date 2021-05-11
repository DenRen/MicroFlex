#include <iostream>
#include "kinematic.hpp"

#define _USE_MATH_DEFINES
#include <cmath>

static inline double deg2rad (double deg) {
    return deg * M_PI / 180;
}

int main () {
    mf::planar_kinematic mech (178, 65, 180, 81.6, 230, 76);

    const double phi0 = deg2rad (40), phi1 = deg2rad (90);
    std::cout << "phi0: " << phi0 << ", phi1: " << phi1 << std::endl;

    mf::vect_t pos = mech.calc_position (phi0, phi1);
    std::cout << "pos: " << pos << std::endl;

    mf::vect_t phi = mech.calc_angle (pos[0], pos[1]);
    std::cout << "phi calc: " << phi << std::endl;

    std::cout << "pos calc: " << mech.calc_position (phi[0], phi[1]) << std::endl;
}