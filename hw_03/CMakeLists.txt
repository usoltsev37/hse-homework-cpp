cmake_minimum_required(VERSION 3.15)
project(hw_03)

set(CMAKE_CXX_STANDARD 17)

include_directories("include/")

add_executable(hw_03
        src/main.cpp
        test/TestMain.cpp
        test/TestMain.hpp
        src/CLI.cpp
        include/CLI.hpp
        src/HuffmanArchiver.cpp
        include/HuffmanArchiver.hpp
        src/Huffman.cpp
        include/Huffman.hpp
        )

