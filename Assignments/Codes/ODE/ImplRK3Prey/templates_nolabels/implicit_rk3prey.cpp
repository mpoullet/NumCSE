//// 
//// Copyright (C) 2016 SAM (D-MATH) @ ETH Zurich
//// Author(s): lfilippo <filippo.leonardi@sam.math.ethz.ch> 
//// Contributors: tille, jgacon, dcasati
//// This file is part of the NumCSE repository.
////
#include "implicit_rkintegrator.hpp"

//! \file implicit_rk3prey.cpp Solution for ImplRK3Prey,
//! solving prey/predator model with implicit RK method.

using namespace Eigen;

int main(void) {

    // Implementation of butcher scheme
    unsigned int s = 2;
    MatrixXd A(s,s);
    VectorXd b(s);
    // What method is this?
    A << 5./12.,      -1./12.,
         3./4.,       1./4.;
    b << 3./4.,       1./4.;

    // Coefficients and handle for prey/predator model
    double alpha1 = 3.;
    double alpha2 = 2.;
    double beta1 = 0.1;
    double beta2 = 0.1;
    // TODO: test for convergence of the method
}
