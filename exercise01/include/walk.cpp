#include "walk.h"
#include <random>
#include <utility>
#include <cmath>

// helper function for the random_walk
  Eigen::Vector2d stepping(const Eigen::Vector2d& current_point){

      Eigen::Vector2d result;  // initializing using the current point

      int x = int(current_point(0));
      int y = int(current_point(1));

      // using the algorithms from <random>
      std::random_device r;
      std::default_random_engine e(r());
      std::uniform_int_distribution<int> uniform(0,3);

      int direction = uniform(e); // describing directions using {0, 1, 2, 3}

      switch(direction){
          case Directions::LEFT :{
              x--;
              break;
          }

          case Directions::RIGHT :{
              x++;
              break;
          }

          case Directions::UP :{
              y++;
              break;
          }

          case Directions::DOWN :{
              y--;
              break;
          }

      }

      result(0) = x;
      result(1) = y;

      return result;
  }


  // calling the random walk function
  // PRE: length  - length of the walk
  Eigen::MatrixXd random_walk(int length){
      Eigen::MatrixXd result = Eigen::MatrixXd::Zero(2, length);
      Eigen::Vector2d step = Eigen::Vector2d::Zero();  // for iterating

      // using loop to iterate up to the length
      result.col(0)(0) = 0; // starting at the point (0, 0)
      result.col(0)(1) = 0;

      for(int i = 1; i < length; ++i){
          step = stepping(step); // stepping function returns the location of the next point
          result.col(i) << step; // storing the values into the
      }

      return result;
  }


// PRE: points iterated are stored as the column vectors in
//      the matrix P
Eigen::Vector2d center_of_mass(const Eigen::MatrixXd& P){

    Eigen::Vector2d result;

    result = P.rowwise().sum();   // summing up all coordinates
    result /= double(P.cols());                // divide by the number of points

    return result;
}



// PRE: performs m times the random walk of length n
// POST: returns the average end-to-end distance
//       and the gyration radius as a std::pair object
  std::pair<double, double> properties(int m, int n){

    double temp_distance = 0.0;
    double temp_radius = 0.0;

    Eigen::MatrixXd P = Eigen::MatrixXd::Identity(2, n);

    for(int i = 0; i < m; ++i){
        P = random_walk(n);  // dimension 2 x n
        temp_distance += P.col(n-1).norm();                    // using the norm() from Eigen

        Eigen::Vector2d s_vec = center_of_mass(P);
        for(int j = 0; j < n; ++j){
            temp_radius += std::pow((P.col(j) - s_vec).norm(), 2);
        }
    }
        temp_distance /= m; // divide by the number of the random walk performed
        temp_radius = std::sqrt(temp_radius / n);


    return std::make_pair(temp_distance, temp_radius);
  }

  // n - length of the random walk
  // d - average end-to-end distance
  // r - gyration radius

// PRE:   m is the number of random walk performed
//        n is the length of the random walk for each iteration
// POST: returns a matrix storing the data values in dependent of different set-ups
//       of the random walk
  Eigen::MatrixXd tendency(int m, int n){
      Eigen::MatrixXd result = Eigen::MatrixXd(3, n);
      std::pair<double, double> property_pair;

      for(int i = 1; i < n; ++i){
          property_pair = properties(m, i); // arguments: m , n

          result.col(i)(0) = i;               // n - length
          result.col(i)(1) = property_pair.first;  // d - distance
          result.col(i)(2) = property_pair.second; // r - gyration radius

      }
      return result;
  }
