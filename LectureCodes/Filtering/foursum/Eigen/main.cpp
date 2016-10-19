# include <Eigen/Dense>
# include <iostream>
# include "foursum.hpp"

int main() {
  auto s = [](double x){ return std::sin(x)*std::cos(5*x); };
  VectorXcd c;
  c = foursum(s, 2, 3);
  std::cout << "c:\n" << c << "\n";
  return 0;
}
