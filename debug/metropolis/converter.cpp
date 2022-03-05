#include <cmath>
#include <iostream>
#include <iomanip>   // std::setprecision
#include <Eigen/Core>
#include "include/monte_carlo.h"

// Boltzmann constant has exact value -  1.380649 * 10^{-23}
// Unit = [J / K]
#define k_b 1.380649e-23


// Lambda expression returns the temperature in Kelvin
auto lambda = [](double celsius)-> double{ return celsius + 273.15;};





int main(){

  // std::cout << std::setprecision(7);
  // std::cout << k_b << std::endl;



  // MEP - minimum energy path
  // arguments: n = 1000, T = 300 K, x_0 = (0.0, -0.5)
  Eigen::Vector2d x_0 = {0.0, -0.5};
  Eigen::MatrixXd MEP = metropolis(1000, 300, x_0);


  // mmc_energies
  // formatting x y E
  mmc_energies_out(MEP);   // store points in a file


  return 0;
}
