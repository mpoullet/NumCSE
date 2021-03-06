///////////////////////////////////////////////////////////////////////////
/// Demonstration code for lecture "Numerical Methods for CSE" @ ETH Zurich
/// (C) 2016 SAM, D-MATH
/// Author(s): Thomas Etterlin <thomaset@student.ethz.ch>
/// Repository: https://gitlab.math.ethz.ch/NumCSE/NumCSE/
/// Do not remove this header.
//////////////////////////////////////////////////////////////////////////

#pragma once

#include <cassert>

#include <Eigen/Dense>

using namespace Eigen;

/* SAM_LISTING_BEGIN_0 */
//! Algorithm of Crout: LU-factorization of \Blue{$\VA\in\bbK^{n,n}$}
void lufak(const MatrixXd& A, MatrixXd& L, MatrixXd& U){
  int n = A.rows();  assert( n == A.cols());
  L = MatrixXd::Identity(n,n);
  U = MatrixXd::Zero(n,n);
  for(int k = 0; k < n; ++k){
  	// Compute row of \Blue{$\VU$}
  	for(int j = k; j < n; ++j)
  	  U(k,j) = A(k,j) - (L.block(k,0,1,k) * U.block(0,j,k,1))(0,0);
  	// Compute column of \Blue{$\VL$}  
  	for(int i = k+1; i < n; ++i)
  	  L(i,k) = (A(i,k) - (L.block(i,0,1,k) * U.block(0,k,k,1))(0,0))/U(k,k);
  }
}
/* SAM_LISTING_END_0 */
