cmake_minimum_required(VERSION 3.15)
project(lab_14)

set(CMAKE_CXX_STANDARD 14)

include_directories("include/")

add_executable(lab_14 include/matrix.hpp src/main.cpp src/matrix.cpp)