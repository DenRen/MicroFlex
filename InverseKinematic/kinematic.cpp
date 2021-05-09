#include "kinematic.hpp"

#include <cmath>
#include <iostream>
#include <stdexcept>
#include <string>

#include <boost/numeric/ublas/operation.hpp>

namespace mf {

// ===================\\
// Four link mechanism --------------------------------------------------------
// ===================//

four_link_mechanism::four_link_mechanism (double h1, double r, double h2, double a) :
    h1 (h1), r (r), h2 (h2), a (a)
{
    if (verifier () == false) {
        dump (std::cerr);
        throw std::invalid_argument ("Failed to construct four_link_mechanism");
    }
}

void four_link_mechanism::dump (std::ostream& output) const {
    output << "Dump four_link_mechanism:" << std::endl
           << "\th1: " << h1 << std::endl
           << "\tr:  " << r  << std::endl
           << "\th2: " << h2 << std::endl
           << "\ta:  " << a  << std::endl; 
}

// ==================\\
// Verifier functions --------------------------------------------------------
// ==================//

bool four_link_mechanism::_verifier_is_number () const {
    using std::isnormal;
    return isnormal (h1) && isnormal (r) && isnormal (h2) && isnormal (a);
}

bool four_link_mechanism::_verifier_is_positive () const {
    return (h1 > 0) && (r > 0) && (h2 > 0) && (a > 0);
}

bool four_link_mechanism::verifier () const {
    return _verifier_is_positive () && _verifier_is_number ();
}

// ==============\\
// Math functions --------------------------------------------------------
// ==============//

double four_link_mechanism::calc_D_rel (double B) const {
    return r*r * sin(phi) * (B - h2*h2);
}

double four_link_mechanism::calc_B_rel (double S) const {
    return S * (r * cos(phi) - h1) / sin(phi);
}

double four_link_mechanism::calc_L () const {
    const double r_sq = r*r, a_sq = a*a, h1_sq = h1*h1, h2_sq = h2*h2;

    return h1 * (r_sq * (2 + cos(2*phi)) + a_sq + h1_sq - h2_sq) + 
           r * cos(phi) * (h2_sq - 3*h1_sq - r_sq - a_sq);
}

double four_link_mechanism::calc_S (double A, double B) const {
    const double h2_sqare = h2 * h2;
    return r * sin(phi) * sqrt (2*B*h2_sqare - A - h2_sqare * h2_sqare);
}

double four_link_mechanism::calc_A (double Z) const {
    return pow(Z - a*a, 2);
}

double four_link_mechanism::calc_B (double Z) const {
    return Z + a*a;
}

double four_link_mechanism::calc_Z () const {
    return r*r - 2*r*h1*cos(phi) + h1*h1;
}

vect_t four_link_mechanism::calc_positon (double phi) {
    this->phi = phi;

    double L = calc_L ();
    double Z = calc_Z ();

    double A = calc_A (Z);
    double B = calc_B (Z);
    double S = calc_S (A, B);

    double B_rel = calc_B_rel (S);
    double D_rel = calc_D_rel (B); 

    vect_t pos (2);
    pos[0] = (D_rel - B_rel) / r;
    pos[1] = L - S;

    pos /= 2 * Z;

    return pos;
}

// ================\\
// Getter functions --------------------------------------------------------
// ================//

double four_link_mechanism::get_h1 () const {
    return h1;
}
double four_link_mechanism::get_r  () const {
    return r;
}
double four_link_mechanism::get_h2 () const {
    return h2;
}
double four_link_mechanism::get_a  () const {
    return a;
}

// ================\\
// Planar kinematic --------------------------------------------------------
// ================//

planar_kinematic::planar_kinematic (double h1, double r, double h2, double a,
                                    double H, double h_d) :
    l4_mech (h1, r, h2, a),
    H (H), h_d (h_d)
{
    if (_personal_verifier () == false) {
        dump ();
        throw std::invalid_argument ("Failed to construct planar_kinematic");
    }

    calc_const_thetta ();
}

// ==================\\
// Verifier functions --------------------------------------------------------
// ==================//

bool planar_kinematic::_verifier_is_number () const {
    using std::isnormal;
    return isnormal (h_d) && isnormal (H);
}

bool planar_kinematic::_verifier_is_positive () const {
    return (h_d > 0) && (H > 0);
}

bool planar_kinematic::_personal_verifier () const {
    return _verifier_is_positive () && _verifier_is_number ();
}

bool planar_kinematic::verifier () const {
    return l4_mech.verifier () && _personal_verifier ();
          
}

// ==============\\
// Math functions --------------------------------------------------------
// ==============//

static matr_t Get2DRotateMatrix_Sin_Cos (double sin_val, double cos_val) {
    matr_t R (2, 2);
    R (0, 0) =  cos_val;
    R (0, 1) = -sin_val;
    R (1, 0) =  sin_val;
    R (1, 1) =  cos_val;

    return R;
}

static matr_t Get2DRotateMatrix (double angle) {
    return Get2DRotateMatrix_Sin_Cos (sin (angle), cos (angle));
}

static matr_t Get2DRotateMatrix_Cos (double cos_val, int sign = 1) {
    const double sin_val =  (1 - 2 * std::signbit (sign)) * sqrt (1 - cos_val * cos_val);
    
    return Get2DRotateMatrix_Sin_Cos (sin_val, cos_val);
} 

// Calculate constant matrix that is independent of angles phi0, phi1
void planar_kinematic::calc_const_thetta () {
    const double a = l4_mech.get_a ();
    const double cos_thetta = h_d / a;

    matr_t R_thetta = Get2DRotateMatrix_Cos (cos_thetta);

    R_thetta *= H / a;
    R_thetta -= idmatr_t (2);

    const_buf_Rthetta = R_thetta;
}

vect_t planar_kinematic::calc_position (double phi0, double phi1) {
    const double phi = phi1 - phi0;
    vect_t rel_pos = l4_mech.calc_positon (phi);

    const double sin_phi0 = sin (phi0);
    const double cos_phi0 = cos (phi0);

    matr_t R_phi0 = Get2DRotateMatrix (phi0);

    using boost::numeric::ublas::prod;

    vect_t pos = prod (R_phi0, rel_pos);
    pos = prod (const_buf_Rthetta, pos);
    
    vect_t p1 (2);
    p1[0] = -sin_phi0;
    p1[1] =  cos_phi0;

    p1 *= l4_mech.get_h1 ();

    return pos += p1;
}

void planar_kinematic::dump (std::ostream& output) const {
    output << "Dump planar_kinematic:" << std::endl
           << "\th_d: " << h_d << std::endl
           << "\tH:   " << H   << std::endl;

    l4_mech.dump ();
}

}