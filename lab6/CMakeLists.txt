cmake_minimum_required(VERSION 3.17)
project(lab6 C)

set(CMAKE_C_STANDARD 11)
include_directories("C:\\Program Files (x86)\\Microsoft SDKs\\MPI\\Include")
include_directories(.)

add_executable(lab6
        lab6.c)
target_link_libraries(lab6 ${MPI_LIBRARIES})

if(MPI_COMPILE_FLAGS)
    set_target_properties(lab5 PROPERTIES
            COMPILE_FLAGS "${MPI_COMPILE_FLAGS}")
endif()

if(MPI_LINK_FLAGS)
    set_target_properties(lab5 PROPERTIES
            LINK_FLAGS "${MPI_LINK_FLAGS}")
endif()


