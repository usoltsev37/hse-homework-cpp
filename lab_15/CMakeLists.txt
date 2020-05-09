cmake_minimum_required(VERSION 3.15)
project(lab_15)

include_directories("./include/")

set(CMAKE_CXX_STANDARD 17)

add_executable(lab_15 ./include/linq.hpp
        ./src/minimal_smoke_test.cpp)