# include "./signalgen.hpp"
# include <figure/figure.hpp>

// Plot signal
int main() {
  VectorXd y = signalgen();
  mgl::Figure fig;
  fig.title("Signal of signalgen()");
  fig.plot(y);
  fig.save("data");
  return 0;
}
