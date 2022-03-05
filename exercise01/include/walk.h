#ifndef WALK_H
#define WALK_H
#include <Eigen/Core>



namespace Directions{
enum Direction {LEFT  = 0,
                RIGHT = 1,
                UP    = 2,
                DOWN  = 3};  // using enum for 4 possible directions
}


// helper function for the random_walk
Eigen::Vector2d stepping(const Eigen::Vector2d&);

// PRE: length  - length of the walk
// POST: calling the random walk function
Eigen::MatrixXd random_walk(int);


// PRE: points iterated are stored as the column vectors in
//      the matrix P
Eigen::Vector2d center_of_mass(const Eigen::MatrixXd&);


// PRE: performs m times the random walk of length n
// POST: returns the average end-to-end distance
//       and the gyration radius as a std::pair object
  std::pair<double, double> properties(int, int);


// PRE:   m is the number of random walk performed
//        n is the length of the random walk for each iteration
// POST: returns a matrix storing the data values in dependent of different set-ups
//       of the random walk
  Eigen::MatrixXd tendency(int, int);

#endif
