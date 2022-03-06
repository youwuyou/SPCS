#ifndef MONTE_CARLO_H
#define MONTE_CARLO_H
#include <Eigen/Core>
// #include "coordinates.h"


// Boltzmann constant has exact value -  1.380649 * 10^{-23}
// Unit = [J / K]
#define k_b  1.380649e-23
#define k_b_ 8.314462618e-3 // [kJ/(mol * K)]
#define mol  6.02214076e23


void mueller_brown_grid();


double E(const Eigen::Vector2d& vec);


// PRE:    n   - number of iterations
//         T   - temperature in Kelvin, effect the rule of rejection in the system
//         x_0 - initial configuration
// POST:   obtain a sample from the Boltzmann distribution,
//         or approximate
Eigen::MatrixXd metropolis(int n, double T, const Eigen::Vector2d& x_0);

#endif
