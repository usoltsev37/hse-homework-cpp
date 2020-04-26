//
// Created by Nikita Usoltsev on 19.04.2020.
//

#ifndef HW_03_CLI_HPP
#define HW_03_CLI_HPP


#include <string>
#include <vector>
#include <iterator>

enum huffman_mode {
    COMPRESS = 0,
    EXTRACT = 1
};

class CLI {
public:

    CLI(int argc, char *argv[]) noexcept(false);

    huffman_mode get_mode() const noexcept;

    std::string get_infile() const noexcept;

    std::string get_outfile() const noexcept;

private:
    int argc_;
    std::vector<std::string> all_argv_;
    static constexpr std::size_t arguments_count_ = 6;
    huffman_mode mode_;
    std::string input_file_;
    std::string output_file_;
};

class ParceException : public std::exception {
public:

    explicit ParceException(std::string message);

    const char *what() const noexcept override;

private:
    std::string message_;
};

#endif //HW_03_CLI_HPP
