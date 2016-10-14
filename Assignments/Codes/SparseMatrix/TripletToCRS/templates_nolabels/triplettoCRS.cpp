//// 
//// Copyright (C) 2016 SAM (D-MATH) @ ETH Zurich
//// Author(s): lfilippo <filippo.leonardi@sam.math.ethz.ch> 
//// Contributors: tille, jgacon, dcasati
//// This file is part of the NumCSE repository.
////
#include <algorithm>
#include <iostream>
#include <vector>

#include <Eigen/Dense>

#include "timer.h"

using namespace Eigen;

/* @brief Structure holding a triplet in format (row, col, value)
 * For convenience, we provide a void constructor and a init constructor. All members are public
 * Used in the TripletMatrix class to provide a nice wrapper for a triplet
 * @tparam scalar Type of the triplet (e.g. double)
 */
template <typename scalar>
struct Triplet {
  // TODO: write Triplet if you want to use this structure for TripletMatrix
};

/* @brief Defines a matrix stored in triplet format (using the Triplet<scalar> class).
 * Triplets may be duplicated and in *any* order.
 * If there is a multiple triplet for (row,col) pair, we assume that the values are intended to be added together.
 * Dimensions are also stored to simplify the code.
 * @tparam scalar Type of the matrix and triplets (e.g. double)
 */
template <typename scalar>
struct TripletMatrix {
  // TODO: put members here

  MatrixXd densify() const;
};


/* @brief Defines a matrix stored in CRS format.
 * Dimensions are also stored to simplify the code.
 * @tparam scalar Type of the matrix and CRS vectors (e.g. double)
 */
template <typename scalar>
struct CRSMatrix {
    // TODO: put members here

  MatrixXd densify() const;
};

/* @brief Converts *this to an eigen (dense) function
 * Loops over all triplets and add value to zero matrix
 * WARNING: May fill in a lot of nonzeros if n,m large
 * @return Matrix of Dynamic size and scalar type
 */
template <class scalar>
MatrixXd TripletMatrix<scalar>::densify() const {
  MatrixXd M;
// TODO: return the "dense" version of "*this"

  return M;
}

/* @brief Converts *this to an eigen (dense) function
 * Loops over all rows and add value at col to zero matrix
 * WARNING: May fill in a lot of nonzeros if n,m large
 * @return Matrix of Dynamic size and scalar type
 */
template <typename scalar>
MatrixXd CRSMatrix<scalar>::densify() const {
  MatrixXd M;
    // TODO: convert "*this" to a dense matrix

  return M;
}

/* @brief Converts a matrix given as triplet matrix to a matrix in CRS format
 * No assumption is made on the triplets, may be unsorted and/or duplicated
 * In case of duplicated triplets, values are added toghether
 * The output CRS matrix may be empty (in that case T = C) or may be already filled with values (in which case C += T)
 * This version inserts the pairs ColVal already sorted in the list
 * Complexity: Loops over all triplets (lets say k) and look up over all columns of the row (say $n_i$), performing a
 * linear search and an insertion (complexity $O(n_i)$)
 * Assuming $n_i$ is bounded by $n$ small, complexity is $k*n$, otherwise $k^2$
 */
template <typename scalar>
void tripletToCRS(const TripletMatrix<scalar>& T, CRSMatrix<scalar>& C) {
    // TODO: conversion function
}

/* @brief Converts a matrix given as triplet matrix to a matrix in CRS format
 * No assumption is made on the triplets, may be unsorted and/or duplicated
 * In case of duplicated triplets, values are added toghether
 * The output CRS matrix may be empty (in that case T = C) or may be already filled with values (in which case C += T)
 * This version inserts all the triplets (push_back), then sorts each row and cumsum all the duplicated col values
 * Complexity: Loops over all triplets (lets say k) and do a cheap (amortized) o(1) push back (complexity k*1). Then sorts an array
 * of rows (ith quicksort complexity k * log(k))
 */
template <typename scalar>
void tripletToCRS_sortafter(const TripletMatrix<scalar>& T, CRSMatrix<scalar>& C) {
    // TODO: conversion function (alternative)
}

/* @brief overload of operator << for output of Triplet Matrix (debug).
 * WARNING: Uses densify() so there may be a lot of fill-in
 * @param o standard output stream
 * @param S matrix in Triplet matrix format
 * @return a ostream o, s.t. you can write o << A << B;
 */
std::ostream & operator<<(std::ostream& o, const TripletMatrix<double>& S) {
  return o << S.densify();
}

/* @brief overload of operator << for output of CRS Matrix (debug).
 * WARNING: Uses densify() so there may be a lot of fill-in
 * @param o standard output stream
 * @param S matrix in CRS matrix format
 * @return a ostream o, s.t. you can write o << A << B;
 */
std::ostream & operator<<(std::ostream& o, const CRSMatrix<double>& S) {
  return o << S.densify();
}

int main() {
  //// Correctness test
  std::size_t nrows = 7, ncols = 5, ntriplets = 9;

  TripletMatrix<double> T;
  CRSMatrix<double> C, D;

    // TODO: construct T here

  for(std::size_t i = 0; i < ntriplets; ++i) {
    // TODO: Use this loop to push back triplets in your matrix
    // Insert triplet with arguments: (rand() % nrows, rand() % ncols, rand() % 1000))
  }

  std::cout << "***Test conversion with random matrices***" << std::endl;
  tripletToCRS(T, C);
    // TODO: if you implemented densify(), compute Frobenius norm of $T - C$

}
