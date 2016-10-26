#include <iostream>
#include <limits>

#include <Eigen/Dense>
#include <Eigen/QR>

using namespace Eigen;

/* @brief QR decomposition from Cholesky decomposition
 * @param[in] A An $m \times n$ matrix
 * @param[out] R The upper triangular matrix from the QR decomposition of $A$
 * @param[out] Q The orthogonal matrix from the QR decomposition of $A$
 */
/* SAM_LISTING_BEGIN_0 */
void CholeskyQR(const MatrixXd & A, MatrixXd & R, MatrixXd & Q) {
	
	MatrixXd AtA = A.transpose() * A;
	LLT<MatrixXd> L = AtA.llt();
	R = L.matrixL().transpose();
	Q = R.transpose().partialPivLu().solve(A.transpose()).transpose();
	// LLT only works with symmetric p.d. matrices,
	// but $R^\top$ is at least invertible,
	// so PartialPivLU to solve the problem.
}
/* SAM_LISTING_END_0 */

/* @brief Direct QR decomposition
 * @param[in] A An $m \times n$ matrix
 * @param[out] R The upper triangular matrix from the QR decomposition of $A$
 * @param[out] Q The orthogonal matrix from the QR decomposition of $A$
 */
/* SAM_LISTING_BEGIN_1 */
void DirectQR(const MatrixXd & A, MatrixXd & R, MatrixXd & Q) {
	
	size_t m = A.rows();
	size_t n = A.cols();
	
	HouseholderQR<MatrixXd> QR = A.householderQr();
    Q = QR.householderQ();
    R = QR.matrixQR().triangularView<Upper>();
    
    // To return the same "economy-size decomposition" as Matlab
    if(m > n) {
		Q = Q.leftCols(n);
		R = R.topRows(n);
	}
}
/* SAM_LISTING_END_1 */

int main() {
	size_t m = 3;
	size_t n = 2;
    MatrixXd A(m,n);
    double epsilon = std::numeric_limits<double>::denorm_min();
    A << 1, 1, 0.5*epsilon, 0, 0, 0.5*epsilon;
    std::cout << "A =" << std::endl << A << std::endl;
    
    MatrixXd R, Q;
    CholeskyQR(A, R, Q);
	
	std::cout << "From Cholesky: R =" << std::endl << R << std::endl;
    std::cout << "From Cholesky: Q =" << std::endl << Q << std::endl;
    
    DirectQR(A, R, Q);
    
	std::cout << "Direct QR: R =" << std::endl << R << std::endl;
    std::cout << "Direct QR: Q =" << std::endl << Q << std::endl;
}
