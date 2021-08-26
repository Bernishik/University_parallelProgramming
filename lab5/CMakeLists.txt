cmake_minimum_required(VERSION 3.17)
project(lab5 C)

set(CMAKE_C_STANDARD 99)
find_package(MPI REQUIRED)
include_directories(${MPI_INCLUDE_PATH})
include_directories("C:\\Program Files (x86)\\Microsoft SDKs\\MPI\\Include")

add_executable(lab5 lab5.c)

target_link_libraries(lab5 ${MPI_LIBRARIES})

if(MPI_COMPILE_FLAGS)
    set_target_properties(lab5 PROPERTIES
            COMPILE_FLAGS "${MPI_COMPILE_FLAGS}")
endif()

if(MPI_LINK_FLAGS)
    set_target_properties(lab5 PROPERTIES
            LINK_FLAGS "${MPI_LINK_FLAGS}")
endif()



