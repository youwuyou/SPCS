cmake_minimum_required(VERSION 3.16)


project(metropolis)




add_executable(converter converter.cpp  include/monte_carlo.cpp)

find_package (Eigen3 REQUIRED NO_MODULE)
target_link_libraries (converter Eigen3::Eigen)
