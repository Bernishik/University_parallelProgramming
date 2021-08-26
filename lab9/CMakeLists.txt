cmake_minimum_required(VERSION 3.19)
project(lab9 C)

set(CMAKE_C_STANDARD 99)
find_package(MPI REQUIRED)
include_directories(${MPI_INCLUDE_PATH})

SET(CMAKE_C_COMPILER mpicc)
SET(CMAKE_CXX_COMPILER mpicxx)
add_executable(lab9
        lab9.c)
