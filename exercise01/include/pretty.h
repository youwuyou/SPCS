// header file for the pretty output functions
// functions receive a matrix and output its data into a file
#ifndef PRETTY_H
#define PRETTY_H

// csv (comma separated value) - The format used for the output file


// mmc_energies
// formatting x y E
void mmc_energies_out(const Eigen::MatrixXd&);

// dependence_on_n
// formatting n d r
void dependence_on_n_out(const Eigen::MatrixXd&);


// random_walk
// formatting x y
void random_walk_out(const Eigen::MatrixXd&);




#endif
