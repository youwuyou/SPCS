#include <iostream>
#include <fstream>  // for outputting data values
#include "pretty.h"
#include <Eigen/Core>


// csv (comma separated value) - The format used for the output file


  // mmc_energies
  // formatting x y E
  void mmc_energies_out(const Eigen::MatrixXd& M){


    // store all the output data under the "evaluations" folder
    std::ofstream of("../evaluations/mmc_energies");

    // formatting the first line
    of << "x y E\n";


    Eigen::Index size = M.cols();

    for(Eigen::Index i = 0; i < size; ++i){
      of << M.col(i)(0) << " "            // n
         << M.col(i)(1) << " "            // d
         << M.col(i)(2) << std::endl;     // r
    }

    of.close();  // close the file
}


  // dependence_on_n
  // formatting n d r
  void dependence_on_n_out(const Eigen::MatrixXd& M){

    std::ofstream of("../evaluations/dependence_on_n");

    // formatting the first line
    of << "n d r\n";


    // of << "n" << " " << "d" << " " << "r" << std::endl;

    Eigen::Index size = M.cols();

    for(Eigen::Index i = 0; i < size; ++i){
      of << M.col(i)(0) << " "            // n
         << M.col(i)(1) << " "            // d
         << M.col(i)(2) << std::endl;     // r
    }

    of.close();
}





  // random_walk
  // formatting example
  // x y
  // 1 2
void random_walk_out(const Eigen::MatrixXd& M){


  std::ofstream of("../evaluations/random_walk");

  // formatting the first line
  // of << "x" << " " << "y" << std::endl;
  of << "x y\n";

  Eigen::Index size = M.cols();

  for(Eigen::Index i = 0; i < size; ++i){
    of << M.col(i)(0) << " " << M.col(i)(1) << std::endl;
  }

  of.close();
}
