#include "include/walk.h"
#include "include/pretty.h"
// #include "coordinates.h"   -  use Eigen instead
#include <Eigen/Core>
#include <cassert>
#include <iostream>



int main(){

  // test for the program simulating the 2D random walk of length n
  // grid point using Eigen::Vector2d to represent
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


  // mmc_energies
  // formatting x y E
  Eigen::MatrixXd N = Eigen::MatrixXd::Random(3, 20);
  mmc_energies_out(N);

}
