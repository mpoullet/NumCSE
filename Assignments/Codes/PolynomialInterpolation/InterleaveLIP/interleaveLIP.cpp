#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <numeric>
#include <vector>

#include <Eigen/Dense>

using namespace Eigen;

std::vector<size_t> ordered(const VectorXd &values) {
    std::vector<size_t> indices(values.size());
    std::iota(begin(indices), end(indices), static_cast<size_t>(0));
    std::sort(begin(indices), end(indices),
		[&](size_t a, size_t b) { return values[a] < values[b]; }
    );
    return indices;
}

/* @brief 
 * @param[in] x 
 * @param[in] t 
 * @param[in] y 
 */
/* SAM_LISTING_BEGIN_1 */
class PwLinIP { 
public:
	PwLinIP(const VectorXd &x, const VectorXd &t, const VectorXd &y);
	double operator()(double arg) const;
private:
	VectorXd x_;
	VectorXd t_;
	VectorXd y_;
	VectorXd s_;
	VectorXd tentBasCoeff(const VectorXd &x, const VectorXd &t,
						  const VectorXd &y) const;
};
/* SAM_LISTING_END_1 */

/* @brief 
 * @param[in] x 
 * @param[in] t 
 * @param[in] y 
 * @param[out] s 
 */
/* SAM_LISTING_BEGIN_0 */
VectorXd PwLinIP::tentBasCoeff(const VectorXd &x, const VectorXd &t,
							   const VectorXd &y) const

{
	// Initialization
	size_t n = t.size();
	auto x_indices = ordered(x);
	auto t_indices = ordered(t);
	// You can also implement a solution which does not need
	// sorted vectors and e.g. for each knot $x_j$ looks
	// for the closest node $t_{i1}$ and the next closest node $t_{i2}$.
	// However, such solution will not become more efficient
	// if you give as input already sorted vectors: for each knot $x_j$
	// you will always have to iterate along the sorted vector $t$
	// to find the included node $t_i$.
	
	VectorXd s = VectorXd::Zero(n);
	
#if SOLUTION
	// Check condition of subproblem 5.5.c
	size_t i = 0;
	size_t k;
	for(size_t j=0; j<(n-1); ++j) {
		
		bool nodeOK = false;
		while(i < n) {
			
			bool inInterval = (x(x_indices[j]) < t(t_indices[i])) &&
							  (t(t_indices[i]) < x(x_indices[j+1]));
			
			if(inInterval) {
				nodeOK = true;
				if(i == j) { // Index of interval which contains 2 nodes
							 // $t_i$ and $t_{i+1}$. After that, we have
							 // $i > j$...
					k = j;
				}
				break;
			} else {
				++i;
			}
		}
		if(!nodeOK) {
			std::exit(EXIT_FAILURE);
		}
	}
	
	// 1. Find slope $\gamma$ and intercept $\beta$
	// in interval $k$ with 2 nodes
	// 2. Find $s_k$ and $s_{k+1}$
	double gamma = (y(t_indices[k+1]) - y(t_indices[k])) /
				   (t(t_indices[k+1]) - t(t_indices[k]));
	double beta = y(t_indices[k]) - gamma * t(t_indices[k]);
	
	s(x_indices[k])   = gamma * x(x_indices[k])   + beta;
	s(x_indices[k+1]) = gamma * x(x_indices[k+1]) + beta;
	
	
	
	for(j=k-1; j>=0; --j) {
		gamma = (s(x_indices[j+1]) - y(t_indices[j])) /
				(x(x_indices[j+1]) - t(t_indices[j]));
		beta = y(t_indices[j]) - gamma * t(t_indices[j]);
		
		s(x_indices[j]) = gamma * x(x_indices[j]) + beta;
	}
	for(j=k+2; j<n; ++j) {
		gamma = (y(t_indices[j]) - s(x_indices[j-1])) /
				(t(t_indices[j]) - x(x_indices[j-1]));
		beta = s(x_indices[j-1]) - gamma * x(x_indices[j-1]);
		
		s(x_indices[j]) = gamma * x(x_indices[j]) + beta;
	}
#else // TEMPLATE
    // TODO: 
#endif // TEMPLATE

	return s;
}
/* SAM_LISTING_END_0 */

/* SAM_LISTING_BEGIN_2 */
PwLinIP::PwLinIP(const VectorXd &x, const VectorXd &t,
				 const VectorXd &y)
{
	assert(t.size() == y.size() && t.size() == x.size() &&
		  "x, t, y must have same size!");
	
	size_t n = t.size();
	x_.resize(n);
	t_.resize(n);
	y_.resize(n);
	
	auto x_indices = ordered(x);
	for(size_t i=0; i < n; ++i) {
		x_(i) = x[x_indices[i]];
	}
	
	auto t_indices = ordered(t);
	for(size_t i=0; i < n; ++i) {
		t_(i) = t[t_indices[i]];
		y_(i) = y[t_indices[i]];
	}
	
	s_ = tentBasCoeff(x_, t_, y_);
}

double PwLinIP::operator()(double arg) const
{
	
	
	
	
	
	
	return;
}
/* SAM_LISTING_END_2 */

int main() {

}
