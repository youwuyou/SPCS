cmake_minimum_required(VERSION 3.16)

project(random_walk)

set(CMAKE_CXX_FLAGS_RELEASE "-Wall -Wpedantic -Wconversion -O3 -std=c++11")
set(CMAKE_CXX_FLAGS_DEBUG "-Wall -Wpedantic -Wconversion -O3 -std=c++11 -g")



add_executable(main exercise1.cpp include/pretty.cpp include/walk.cpp)


find_package (Eigen3 REQUIRED NO_MODULE)
target_link_libraries (main Eigen3::Eigen)
