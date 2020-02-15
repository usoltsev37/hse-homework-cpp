cmake_minimum_required(VERSION 3.15)
project(hw_02)

set(CMAKE_CXX_STANDARD 14)

include_directories("include/")

add_executable(test_hw_02 test/test1.cpp test/Test.cpp include/Test.hpp test/BoardTest.cpp include/BoardTest.hpp src/Board.cpp include/Board.hpp)
add_executable(hw_02 src/main.cpp src/Board.cpp src/StdioBoardView.cpp include/Board.hpp include/StdioBoardView.hpp)