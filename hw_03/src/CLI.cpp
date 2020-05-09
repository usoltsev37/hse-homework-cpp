#include <cstddef>
#include "CLI.hpp"
#include <iostream>

CLI::CLI(int argc, char *argv[]) : argc_(argc) {
    if (argc_ != arguments_count_ || (argc == 2 &&
        (strcmp(argv[1], "-h") == 0 || strcmp(argv[1], "--help") == 0))) {
        help();
        throw ParceException("============Invalid count of arguments============\n");
    }

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

void CLI::help() const noexcept {
    using std::cout;
    cout << "NAME\n";
    cout << "    Huffman - create archive or unpack\n\n";
    cout << "DESCRIPTION\n";
    cout << "    -c    create archive\n\n";
    cout << "    -u    unpack archive\n\n";
    cout << "    -f,   <path>\n";
    cout << "          input file name\n\n";
    cout << "    -o,   <path>\n";
    cout << "          output file name\n\n";
    cout << "    -h, --help\n";
    cout << "          display this help and exit\n\n";
}

ParceException::ParceException(std::string message) : message_(std::move(message)) {}

const char *ParceException::what() const noexcept {
    return message_.c_str();
}

