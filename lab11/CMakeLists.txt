cmake_minimum_required(VERSION 3.19)
project(lab11 CUDA)

set(CMAKE_CUDA_STANDARD 14)
set(CMAKE_CUDA_COMPILER)

add_executable(lab11 lab11.cu)

set_target_properties(
        lab11
        PROPERTIES
        CUDA_SEPARABLE_COMPILATION ON)