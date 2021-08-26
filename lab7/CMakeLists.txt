cmake_minimum_required(VERSION 3.17)
project(lab7 C)

set(CMAKE_C_STANDARD 99)
find_package(MPI REQUIRED)
include_directories(${MPI_INCLUDE_PATH})

SET(CMAKE_C_COMPILER mpicc)
SET(CMAKE_CXX_COMPILER mpicxx)
add_executable(lab7 lab7.c)



