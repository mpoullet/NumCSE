///////////////////////////////////////////////////////////////////////////
/// Demonstration code for lecture "Numerical Methods for CSE" @ ETH Zurich
/// (C) 2016 SAM, D-MATH
/// Author(s): N.N.
/// Repository: https://gitlab.math.ethz.ch/NumCSE/NumCSE/
/// Do not remove this header.
//////////////////////////////////////////////////////////////////////////
# include <Eigen/Dense>
using Eigen::RowVectorXd;
using Eigen::MatrixXd;


/* SAM_LISTING_BEGIN_0 */
// Computes the values of the Chebychev polynomials \Blue{$T_{0},\ldots,T_{d}$}, \Blue{$d\geq 2$}
// at points passed in \texttt{x} using the 3-term recursion \eqref{eq:ChebychevRecursion}.
// The values \Blue{$T_k(x_j)$}, are returned in row \Blue{$k+1$} of \texttt{V}.
void chebpolmult(const int d, const RowVectorXd& x, MatrixXd& V) {
  const unsigned n = x.size();
  V = MatrixXd::Ones(d + 1, n); // \Blue{$T_0 \equiv 1$}
  V.block(1, 0, 1, n) = x; // \Blue{$T_1(x) = x$}
  for (int k = 1; k < d; ++k) {
    const RowVectorXd p = V.block(k, 0, 1, n); // $p = T_{k}$
    const RowVectorXd q = V.block(k - 1, 0, 1, n); // $q = T_{k-1}$
    V.block(k + 1, 0, 1, n) = 2*x.cwiseProduct(p) - q; // \Magenta{3-term recursion}
  }
}
/* SAM_LISTING_END_0 */
