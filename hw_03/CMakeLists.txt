cmake_minimum_required(VERSION 3.15)
project(hw_03)

set(CMAKE_CXX_STANDARD 17)

include_directories("include/")

add_executable(hw_03
        src/main.cpp
        src/CLI.cpp
        include/CLI.hpp
        src/HuffmanArchiver.cpp
        include/HuffmanArchiver.hpp
        src/Huffman.cpp
        include/Huffman.hpp
        )

include_directories("include/")
add_executable(test_hw_03
        src/main.cpp
        src/CLI.cpp
        include/CLI.hpp
        src/HuffmanArchiver.cpp
        include/HuffmanArchiver.hpp
        src/Huffman.cpp
        include/Huffman.hpp
        test/doctest.h
        test/TestMain.cpp
        test/TestMain.hpp
        test/testCLI.cpp
        test/testHuffman.cpp
        test/testHuffmanArchiver.cpp
        )

#        test/TestBitStream.cpp
#        test/TestHuffmanArchiver.cpp
#        test/TestHuffman.cpp