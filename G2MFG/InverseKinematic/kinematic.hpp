#pragma once

#include <boost/numeric/ublas/vector.hpp>
#include <boost/numeric/ublas/matrix.hpp>
#include <boost/numeric/ublas/io.hpp>

namespace mf {

using vect_t   = boost::numeric::ublas::vector <double>;
using matr_t   = boost::numeric::ublas::matrix <double>;
using idmatr_t = boost::numeric::ublas::identity_matrix <double>;

class four_link_mechanism {
    double h1, r, h2, a;

    double phi; // for convenient calculations

    bool _verifier_is_number   () const;
    bool _verifier_is_positive () const;

    double calc_D_rel (double B) const;
    double calc_B_rel (double S) const;
    double calc_L () const;
    double calc_S (double A, double B) const;
    double calc_A (double Z) const;
    double calc_B (double Z) const;
    double calc_Z () const;

public:
    four_link_mechanism () = delete;
    four_link_mechanism (double h1, double r, double h2, double a);

    bool verifier () const;
    vect_t calc_positon (double phi);
    void dump (std::ostream& output = std::cout) const;

    double get_h1 () const;
    double get_r  () const;
    double get_h2 () const;
    double get_a  () const;
};

class planar_kinematic {
    four_link_mechanism l4_mech;
    double H, h_d;

    matr_t const_buf_Rthetta;

    bool _verifier_is_number   () const;
    bool _verifier_is_positive () const;
    bool _personal_verifier    () const;

    void calc_const_thetta ();
    
    matr_t calc_inv_W_pos (vect_t PHI, double delta_phi);

public:
    planar_kinematic () = delete;
    planar_kinematic (double h1, double r, double h2, double a,
                      double H, double h_d);

    bool verifier () const;
    vect_t calc_position (double phi0, double phi1);
    vect_t calc_angle    (double x, double z,
                          double phi0_0 = -M_PI_4, double phi1_0 = M_PI_4,
                          double eps = 1e-3);
    void dump (std::ostream& output = std::cout) const;

    double get_h1  () const;
    double get_r   () const;
    double get_h2  () const;
    double get_a   () const;
    double get_h_d () const;
    double get_H   () const;
};

class kinematic : public planar_kinematic {

public:
    kinematic () = delete;
    kinematic (double h1, double r, double h2, double a,
               double H, double h_d);

    bool verifier () const;
    vect_t calc_position (double phi0, double phi1, double phi2);
    vect_t calc_angle    (double x, double y, double z,
                          double phi0_0 = -M_PI_4, double phi1_0 = M_PI_4, double phi2_0 = 0,
                          double eps = 1e-3);
    void dump (std::ostream& output = std::cout) const;

    double get_h1  () const;
    double get_r   () const;
    double get_h2  () const;
    double get_a   () const;
    double get_h_d () const;
    double get_H   () const;
};

}