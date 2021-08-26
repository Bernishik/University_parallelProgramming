cmake_minimum_required(VERSION 3.19)
project(lab12 CUDA)
set(CMAKE_CUDA_STANDARD 14)
add_executable(lab12 lab_12_1.cu)
add_executable(lab12_2 lab_12_2.cu)
add_executable(lab12_3 lab_12_3.cu)


set_target_properties(
        lab12
        PROPERTIES
        CUDA_SEPARABLE_COMPILATION ON)