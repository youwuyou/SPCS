#ifndef MONTE_CARLO_H
#define MONTE_CARLO_H
#include <Eigen/Core>
// #include "coordinates.h"





void mueller_brown_grid();


double E(const Eigen::Vector2d& vec);


// PRE:    n   - number of iterations
//         T   - temperature in Kelvin, effect the rule of rejection in the system
//         x_0 - initial configuration
// POST:   obtain a sample from the Boltzmann distribution,
//         or approximate
Eigen::MatrixXd metropolis(int n, double T, const Eigen::Vector2d& x_0);

#endif
