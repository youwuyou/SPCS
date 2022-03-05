cmake_minimum_required (VERSION 2.8.12)

# set(EXECUTABLE_OUTPUT_PATH ${CMAKE_SOURCE_DIR})

project(exercise01)

#to choose Debug build type, in build, use cmake -DCMAKE_BUILD_TYPE="Debug" ..
if(NOT CMAKE_BUILD_TYPE)
    message(STATUS "No build type selected, default to Release. ** If you want to use debug mode, use -DCMAKE_BUILD_TYPE=\"Debug\" **")
  set(CMAKE_BUILD_TYPE "Release")
endif()

set(CMAKE_CXX_FLAGS_RELEASE "-Wall -Wpedantic -Wconversion -O3 -std=c++11")
set(CMAKE_CXX_FLAGS_DEBUG "-Wall -Wpedantic -Wconversion -O3 -std=c++11 -g")

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(sources include/monte_carlo.cpp
            include/pretty.cpp
            include/walk.cpp
    )
# set(headers include/pretty.h
# 	        include/monte_carlo.h
#             include/walk.h
#     )
#
# add_library(MC_lib STATIC ${sources} ${headers})   # added monte carlo lib

add_executable(exercise01 exercise01.cpp ${sources})

# linking Eigen to the executable
find_package (Eigen3 REQUIRED NO_MODULE)
target_link_libraries(exercise01 Eigen3::Eigen)
