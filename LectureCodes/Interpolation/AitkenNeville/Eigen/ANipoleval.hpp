///////////////////////////////////////////////////////////////////////////
/// Demonstration code for lecture "Numerical Methods for CSE" @ ETH Zurich
/// (C) 2016 SAM, D-MATH
/// Author(s): J. Gacon
/// Repository: https://gitlab.math.ethz.ch/NumCSE/NumCSE/
/// Do not remove this header.
//////////////////////////////////////////////////////////////////////////
# include <Eigen/Dense>

using Eigen::VectorXd;
/* SAM_LISTING_BEGIN_0 */
// Aitken-Neville algorithm for evaluation of interpolating polynomial
// IN:  t, y: interpolation data points
//      x: (single) evaluation point
// OUT: value of interpolant in x
double ANipoleval(const VectorXd& t, VectorXd y, const double x) {
  for (int i = 0; i < y.size(); ++i) {
    for (int k = i - 1; k >= 0; --k) {
      y(k) = y(k + 1) + (y(k + 1) - y(k))*(x - t(i))/(t(i) - t(k));
    }
  }
  return y(0);
}
/* SAM_LISTING_END_0 */
