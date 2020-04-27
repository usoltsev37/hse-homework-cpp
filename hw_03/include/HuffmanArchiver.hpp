//
// Created by Nikita Usoltsev on 19.04.2020.
//

#ifndef HW_03_HUFFMANARCHIVER_HPP
#define HW_03_HUFFMANARCHIVER_HPP

#include "Huffman.hpp"

class HuffmanArchiver {
public:
    HuffmanArchiver();


    void compress_archive(std::ifstream &i_stream, std::ofstream &o_stream);

    void extract_archive(std::ifstream &i_stream, std::ofstream &o_stream);

private:

    void write_codeTable(std::ofstream &o_stream, std::size_t file_size, std::map<uint8_t, int> &frequency);
    void write_codeFile(std::ifstream &i_stream, std::ofstream &o_stream, HuffmanTree &tree);
    void write_bytes(std::ofstream &o_stream, std::string &code) noexcept;

    void print_stat() const noexcept;

    void read_codeTable(std::ifstream &i_stream, std::map<uint8_t, int> &frequency);
    void read_codeFile(std::ifstream &i_stream, std::ofstream &o_stream, HuffmanTree &tree);


    std::size_t sz_before_;
    std::size_t sz_after_;
    std::size_t sz_buffer_;
};

#endif //HW_03_HUFFMANARCHIVER_HPP
