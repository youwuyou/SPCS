cmake_minimum_required(VERSION 3.16)



project(stochastic_gradient_descent)




add_executable(sgd main.cpp)



find_package (Eigen3 REQUIRED NO_MODULE)
target_link_libraries (sgd Eigen3::Eigen)
