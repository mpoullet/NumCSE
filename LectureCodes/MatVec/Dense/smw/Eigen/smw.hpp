///////////////////////////////////////////////////////////////////////////
/// Demonstration code for lecture "Numerical Methods for CSE" @ ETH Zurich
/// (C) 2016 SAM, D-MATH
/// Author(s): Thomas Etterlin <thomaset@student.ethz.ch>
///            R. Hiptmair <hiptmair@sam.math.ethz.ch>
/// Repository: https://gitlab.math.ethz.ch/NumCSE/NumCSE/
/// Do not remove this header.
//////////////////////////////////////////////////////////////////////////

#pragma once

#include <iostream>
#include <cassert>
#include <limits>

#include <Eigen/Dense>

using namespace Eigen;

/* SAM_LISTING_BEGIN_0 */
// Solving rank-1 updated LSE based on \eqref{eq:smwx}
template <class LUDec>
VectorXd smw(const LUDec &lu, const MatrixXd &u, const VectorXd &v, const VectorXd &b){
  VectorXd z = lu.solve(b); //\label{smw:1}
  VectorXd w = lu.solve(u); //\label{smw:2}
  double alpha = 1.0 + v.dot(w);
  if (std::abs(alpha) < std::numeric_limits<double>::epsilon())
    throw std::runtime_error("A nearly singular");
  else return (z - w * v.dot(z) / alpha);
}
/* SAM_LISTING_END_0 */

// Old version
/* SAM_LISTING_BEGIN_1 */
VectorXd smw_old(const MatrixXd &L, const MatrixXd &U, const MatrixXd &u, const VectorXd &v, const VectorXd &b){
	VectorXd z = U.triangularView<Upper>().solve( L.triangularView<Lower>().solve(b) );//\label{smw:1}
	VectorXd w = U.triangularView<Upper>().solve( L.triangularView<Lower>().solve(u) );//\label{smw:2}
	double alpha = 1.0 + v.dot(w);
	assert(std::abs(alpha) > std::numeric_limits<double>::epsilon()*U.lpNorm<1>() && "A nearly singular");
	return z - w * v.dot(z) / alpha;
}
/* SAM_LISTING_END_1 */
