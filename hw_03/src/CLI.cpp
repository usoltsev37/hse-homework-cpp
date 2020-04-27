//
// Created by Nikita Usoltsev on 19.04.2020.
//

#include <cstddef>
#include <utility>
#include <algorithm>
#include "CLI.hpp"

#include <iostream>

CLI::CLI(int argc, char *argv[]) : argc_(argc) {
    if (argc_ != arguments_count_)
        throw ParceException("============Invalid count of arguments============\n");

    all_argv_.assign(argv + 1, argv + argc);

    for (auto key = all_argv_.begin(); key != all_argv_.end(); key++) {
        if (*key == "-c")
            mode_ = huffman_mode::COMPRESS;
        else if (*key == "-u")
            mode_ = huffman_mode::EXTRACT;
        else if (*key == "-f")
            input_file_ = *(++key);
        else if (*key == "-o")
            output_file_ = *(++key);
        else
            throw ParceException("==== Unknown format, example is \"./hw_03 -c -f myfile.txt -o result.bin\" ====\n");
    }

}

huffman_mode CLI::get_mode() const noexcept {
    return mode_;
}

std::string CLI::get_infile() const noexcept {
    return input_file_;
}

std::string CLI::get_outfile() const noexcept {
    return output_file_;
}

ParceException::ParceException(std::string message) : message_(std::move(message)) {}

const char *ParceException::what() const noexcept {
    return message_.c_str();
}

