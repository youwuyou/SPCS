#include <iostream>
#include <random>
#include <Eigen/Core>
#include <iomanip>

// NOTE!!! STILL IN CONSTRUCTION!!!


// f'(x) = (f(x+h) - f(x))/h
auto dF[](double x)-> double { return 0.3;};

// DF(x)
auto DF[](double x, double y)-> Eigen::Vector2d {
  Eigen::Vector2d s; // todo
  return s;
}; // todo change it





// PRE:    gamma - step size/learning rate
// POST:
Eigen::MatrixXd sgd(const double gamma, const double bi, const double rtol,
                    const double atol, int iterations){

    Eigen::MatrixXd result;
    int size;
    Eigen::Vector2d s;     // vector for newton correction


    // TODO - use a counter for storing vec into the matrix
    do{

          // TODO s = ...;

          x -= gamma * s;

          // store the current x in the result matrix

          count++;

    } while( counter < iterations && (s.norm() > rtol * x.norm()) && (s.norm() > atol));



    return result;
}







int main(){

  Eigen::MatrixXd FindMin = sgd(); // TODO - change the arguments passed


  // mmc_energies
  // formatting x y E
  mmc_energies_out(FindMin);   // store points in a file



  std::setprecision(4);
  std::cout << "The exact global minimum is ("
            << -0.558 << ", " << 1.442 << ")" << std::endl;


  // TODO - replace it
  std::cout << "The found global minimum is ("
            << -0.558 << ", " << 1.442 << ")" << std::endl;


  return 0;
}
