//// 
//// Copyright (C) 2016 SAM (D-MATH) @ ETH Zurich
//// Author(s): lfilippo <filippo.leonardi@sam.math.ethz.ch> 
//// Contributors: tille, jgacon, dcasati
//// This file is part of the NumCSE repository.
////
#include <iostream>
#include <cmath>

#include <Eigen/Dense>

using namespace Eigen;


/*!
 * \brief circl_alg_fit
 * \param[in] x
 * \param[in] y
 * \return
 */
Vector3d circl_alg_fit(const VectorXd &x,
                       const VectorXd & y) {
    assert(x.size() == y.size() && "Size mismatch!");

    unsigned int n = x.size();

    // TODO: find center/radius using algebric method
}

Vector3d circl_geo_fit(const VectorXd &x, const VectorXd & y) {

}

int main(int argc, char **argv) {

}
