#include <random>
#include <fstream>
#include "monte_carlo.h"
#include <Eigen/Core>

/*
sample the Müller-Brown potential on a coordinate grid
*/

void mueller_brown_grid() {
  std::ofstream output("../evaluations/mueller-brown");
  output << "x y E\n";

  for (double x = -3; x < 1.3; x += 0.01) {
    for (double y = 3; y > -1.3; y -= 0.01){
      output << x << " " << y << " " << E(Eigen::Vector2d(x,y)) << std::endl;
    }
  }

  output.close();
}

/*
calculate Müller-Brown potential energy for given coordinates
- self-implemented version using Eigen
- x $\in$ [-3, 1.3], y $\in$ [-1.3, 3]


*/
double E(const Eigen::Vector2d& vec) {
  Eigen::MatrixXd A_(1, 4);
            A_ << -200., -100.,
                  -170.,   15.;

  Eigen::MatrixXd a_(4, 1), b_(4, 1), c_(4, 1), x_(4, 1), y_(4, 1);

  a_ <<  -1.,   -1.,  -6.5, 0.7;
  b_ <<   0.,    0.,   11., 0.6;
  c_ << -10.,  -10.,  -6.5, 0.7;
  x_ <<   1.,    0.,  -0.5, -1.;
  y_ <<   0.,   0.5,   1.5,  1.;

  double x = vec(0), y = vec(1);

  auto scalar = A_ * (
                            ( a_.array() * (x - x_.array()).square()
                             + b_.array() * (x - x_.array()) * (y - y_.array())
                             + c_.array()         * (y - y_.array()).square()
                            ).exp()
                      ).matrix();

  // obtain the result from the Eigen::Product
  double E = scalar(0);

  return 0.1 * E; // scaling the result
}




// PRE:    n   - number of iterations
//         T   - temperature in Kelvin, effect the rule of rejection in the system
//         x_0 - initial configuration
// POST:   obtain a sample from the Boltzmann distribution,
//         or approximate
Eigen::MatrixXd metropolis(int n, double T, const Eigen::Vector2d& x_0){
    Eigen::Vector2d x, y;     // used temporarily

    double p_A;

    // using the algorithms from <random>
    // Not so sure whether to keep them here or in the loop
    std::random_device r;
    std::default_random_engine e(r());
    std::uniform_real_distribution<double> uniform(0,1);
    std::uniform_real_distribution<double> uniform_change(-0.05, 0.05);

    Eigen::MatrixXd result = Eigen::MatrixXd::Zero(2, n);  // we have for each point x, y coordinate
    result.col(0) = x_0;    // store the initial step

    for(int i = 1; i < n; ++i){

          x = result.col(i-1); // lastest position

          y(0) = x_0(0) + uniform_change(e);   // move in x direction
          y(1) = x_0(1) + uniform_change(e);   // move in y direction

          // E is the energy function following the Boltzmann distribution
          p_A = std::min(1., std::exp(-(E(y) - E(x)) / k_b * T));

          if (p_A > uniform(e)){
              result.col(i) << y;
          }
          else{
             // x_0 remains the same
              result.col(i) << x;
          }
    }

    return result;
}
