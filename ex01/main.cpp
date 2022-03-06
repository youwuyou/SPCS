#include "include/monte_carlo.h"
#include "include/walk.h"
#include "include/pretty.h"
// #include "coordinates.h"   -  use Eigen instead
#include <Eigen/Core>
#include <cassert>
#include <iostream>
#include <iomanip>   // std::setprecision



// Lambda expression returns the temperature in Kelvin
auto lambda = [](double celsius)-> double{ return celsius + 273.15;};




int main() {
  ///////////////////////////////////////////////// Aufgabe 1 /////////////////////////////////////////////////////////////////////////
  // test for the program simulating the 2D random walk of length n
  // grid point using Eigen::Vector2i to represent
  std::cout << "Starting the 2D random walk simulation..."<< std::endl;
  std::cout << "Please enter the number of length wanted "<< std::endl;

  int n;
  std::cin >> n; // user input for the length of the walk
  assert(n > 0 && "n must be a positive number!");


  // csv (comma separated value) -
  Eigen::MatrixXd Polymer = random_walk(n); // replace this by the real data values
  random_walk_out(Polymer);


  // b). average end-to-end distance
  //performs m times the random walk of length n
  // formatting n d r
  // n - length of the random walk
  // d - average end-to-end distance
  // r - gyration radius
  // double average = average_total_length( , );


  std::cout << "Starting the dependency check..."<< std::endl;
  std::cout << "Please enter the number of the random walks and the number of length wanted. (eg. 1000, 100)"<< std::endl;

  int i, l;
  std::cin >> i; // user input for the number of iterations and the length of the walk
  std::cin >> l;
  assert(i > 0  && l > 0
                && "i and l must both be a positive number!"
        );

  Eigen::MatrixXd Tendency = tendency(i, l);
  dependence_on_n_out(Tendency);




///////////////////////////////////////////////// Aufgabe 2 /////////////////////////////////////////////////////////////////////////

  mueller_brown_grid();

  // MEP - minimum energy path
  // arguments: n = 1000, T = 300 K, x_0 = (0.0, -0.5)

  int iterations;
  double temperature, x_, y_;
  Eigen::Vector2d x_0;

  std::cout << "Finding the MEP..."<< std::endl;
  std::cout << "Please enter the number of iterations and the temperature of the system. (eg. 10000, 300)"<< std::endl;
  std::cin >> iterations; // user input for the number of iterations and the temperature of the system
  std::cin >> temperature;

  assert(iterations > 0 && "The number of iterations must be positive!");
  assert(temperature >= 0 && "The temperature cannot be lower than the absolute zero!");

  std::cout << "Please enter the x,y coordinates of the initial point. (eg. 0.0, -0.5)" << std::endl;
  std::cin >> x_; // user input for the number of iterations and the temperature of the system
  std::cin >> y_;

  // assert(x_ >= -3  && x_ < 1.3  &&
  //        y_ > -1.3 && y_ <= 3   && "Initial point must be on the grid!");

  x_0(0) = x_;
  x_0(1) = y_;

  Eigen::MatrixXd MEP = metropolis(iterations, temperature, x_0);  // returns 3 by n matrix

  // mmc_energies
  // formatting x y E
  mmc_energies_out(MEP);   // store points in a file


  return EXIT_SUCCESS;
}
