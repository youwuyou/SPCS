#include <random>
#include <fstream>
#include "monte_carlo.h"

/*
sample the Müller-Brown potential on a coordinate grid
*/

void mueller_brown_grid() {
  std::ofstream output("../evaluations/mueller-brown");
  output << "x y E\n";

  for (double x = -3; x < 1.3; x += 0.01) {
    for (double y = 3; y > -1.3; y -= 0.01)
      output << x << " " << y << " " << E(coordinates<double>(x, y)) << std::endl;
  }

  output.close();
}

/*
calculate Müller-Brown potential energy for given coordinates
*/
double E(coordinates<double> c) {
  const std::vector<double> A_({ -200., -100., -170., 15.});
  const std::vector<double> a_({ -1., -1., -6.5, 0.7});
  const std::vector<double> b_({0., 0., 11., 0.6});
  const std::vector<double> c_({ -10., -10., -6.5, 0.7});
  const std::vector<double> x_({1., 0., -0.5, -1.});
  const std::vector<double> y_({0., 0.5, 1.5, 1.});

  // scalling by 0.1 for more realistic value
  // unit of the potential: [kJ/mol]
  // TODO: convert the k_B aka E according to the unit used
  const double E = 0.1 * (
                             A_[0] * std::exp(a_[0] * pow(c.x() - x_[0], 2)
                           + b_[0] * (c.x() - x_[0]) * (c.y() - y_[0])
                           + c_[0] * pow(c.y() - y_[0], 2))
                           + A_[1] * std::exp(a_[1] * pow(c.x() - x_[1], 2)
                           + b_[1] * (c.x() - x_[1]) * (c.y() - y_[1])
                           + c_[1] * pow(c.y() - y_[1], 2))
                           + A_[2] * std::exp(a_[2] * pow(c.x() - x_[2], 2)
                           + b_[2] * (c.x() - x_[2]) * (c.y() - y_[2])
                           + c_[2] * pow(c.y() - y_[2], 2))
                           + A_[3] * std::exp(a_[3] * pow(c.x() - x_[3], 2)
                           + b_[3] * (c.x() - x_[3]) * (c.y() - y_[3])
                           + c_[3] * pow(c.y() - y_[3], 2))
                   );
  return E;
}
