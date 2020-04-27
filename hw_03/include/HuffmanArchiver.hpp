#ifndef HW_03_HUFFMANARCHIVER_HPP
#define HW_03_HUFFMANARCHIVER_HPP

#include "Huffman.hpp"

class HuffmanArchiver {
public:
    HuffmanArchiver();

    void compress_archive(std::istream &i_stream, std::ostream &o_stream);

    void extract_archive(std::istream &i_stream, std::ostream &o_stream);

    void print_stat(std::ostream &o_stream) const noexcept;

private:

    void write_codeTable(std::ostream &o_stream, std::size_t file_size, std::map<uint8_t, int> &&frequency) noexcept;

    void write_codeFile(std::istream &i_stream, std::ostream &o_stream, HuffmanTree &tree) noexcept;

    void write_bytes(std::ostream &o_stream, std::string &code) noexcept;

    void read_codeTable(std::istream &i_stream, std::map<uint8_t, int> &frequency) noexcept;

    void
    read_decode_codeFile(std::istream &i_stream, std::ostream &o_stream, HuffmanTree &tree, std::size_t &file_size) noexcept;

    void write_decode_byte(uint8_t &byte, std::string &buffer, uint8_t &extra_zeroes,
                           std::ostream &o_stream, HuffmanTree &tree) noexcept;

    std::size_t sz_before_;
    std::size_t sz_after_;
    std::size_t sz_buffer_;
};

#endif //HW_03_HUFFMANARCHIVER_HPP
