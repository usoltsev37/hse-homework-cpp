//
// Created by Nikita Usoltsev on 19.04.2020.
//

#include <map>
#include <map>
#include <limits>
#include <ios> // !
#include <iterator>
#include <fstream>

#include <iostream>
#include <cassert>

#include "HuffmanArchiver.hpp"

HuffmanArchiver::HuffmanArchiver() : sz_before_(0), sz_after_(0), sz_buffer_(0) {}

void HuffmanArchiver::compress_archive(std::ifstream &i_stream, std::ofstream &o_stream) {
    std::streampos file_size = i_stream.tellg();
    i_stream.seekg( 0, i_stream.end);
    file_size = i_stream.tellg() - file_size;
    i_stream.seekg( 0, i_stream.beg);
    sz_before_ = static_cast<std::size_t>(file_size);

    std::map<uint8_t, int> frequency;

    for(auto i = std::istreambuf_iterator<char>(i_stream); i != std::istreambuf_iterator<char>(); i++)
        frequency[*i]++;

    HuffmanTree tree(frequency);

    write_codeTable(o_stream, file_size, frequency);
    write_codeFile(i_stream, o_stream, tree);

    print_stat();
}

void HuffmanArchiver::print_stat() const noexcept {
    std::cout << sz_before_ << '\n'
              << sz_after_  << '\n'
              << sz_buffer_ << std::endl;
}

void HuffmanArchiver::write_codeTable(std::ofstream &o_stream, std::size_t file_size,
                                      std::map<uint8_t, int> &frequency) {
    std::size_t size = frequency.size();
    o_stream.write(reinterpret_cast<char*>(&size), sizeof(int));
    for(auto &symbol_freq : frequency) {
        o_stream.write(reinterpret_cast<const char*>(&symbol_freq.first), sizeof(uint8_t));
        o_stream.write(reinterpret_cast<char*>(&symbol_freq.second), sizeof(int));
    }
    o_stream.write(reinterpret_cast<char*>(&file_size), sizeof(int));
    sz_buffer_ = sizeof(int);
    sz_buffer_ += sizeof(int);
    sz_buffer_ += (sizeof(int) + sizeof(uint8_t)) * size;
}

void HuffmanArchiver::write_codeFile(std::ifstream &i_stream, std::ofstream &o_stream, HuffmanTree &tree) {
    i_stream.seekg(0, i_stream.beg);
    std::string buffer = "";
    for(auto symbol = std::istreambuf_iterator<char>(i_stream);
             symbol != std::istreambuf_iterator<char>(); symbol++) {
        std::string code = buffer + tree.get_NodeBySymbol(*symbol)->get_code();
        std::size_t new_buffer_length = code.length() % CHAR_BIT;
        buffer = code.substr(code.length() - new_buffer_length, code.length());
        code = code.substr(0, code.length() - new_buffer_length);
        write_bytes(o_stream, code);
    }
    if(!buffer.empty()) {
        while(buffer.length() != CHAR_BIT) buffer += "0";
        write_bytes(o_stream, buffer);
    }
}

void HuffmanArchiver::write_bytes(std::ofstream &o_stream, std::string &code) noexcept {
    std::size_t current_bit = 0;
    std::uint8_t byte = 0;
    for(auto bit : code) {
        current_bit++;
        byte |= (static_cast<std::size_t>(bit) - 48) << (CHAR_BIT - current_bit);
        current_bit %= CHAR_BIT;
        if(current_bit == 0) {
            o_stream.write(reinterpret_cast<const char*>(&byte), sizeof(uint8_t));
            sz_after_++;
            assert(sz_after_ > 0); // AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA
            byte = 0;
        }
    }
}

void HuffmanArchiver::extract_archive(std::ifstream &i_stream, std::ofstream &o_stream) {
    std::map<uint8_t, int> frequency;

    read_codeTable(i_stream, frequency);

    HuffmanTree tree(frequency);

    read_codeFile(i_stream, o_stream, tree);

    print_stat();
}

void HuffmanArchiver::read_codeTable(std::ifstream &i_stream, std::map<uint8_t, int> &frequency) {
    int table_size;

    i_stream.read(reinterpret_cast<char*>(&table_size), sizeof(int));

    sz_buffer_ = sizeof(int);
    for(std::size_t i = 0; i < table_size; i++) {
        uint8_t symbol;
        i_stream.read(reinterpret_cast<char*>(&symbol), sizeof(uint8_t));

        int frequency_of_symbol;
        i_stream.read(reinterpret_cast<char*>(&frequency_of_symbol), sizeof(int));

        frequency[symbol] = frequency_of_symbol;
        sz_buffer_ += sizeof(int) + sizeof(uint8_t);
    }
}

void HuffmanArchiver::read_codeFile(std::ifstream &i_stream, std::ofstream &o_stream, HuffmanTree &tree) {

    tree.printCODE();

    int file_size;
    i_stream.read(reinterpret_cast<char*>(&file_size), sizeof(int));
    sz_after_ = file_size;
    sz_buffer_ += sizeof(int);
    std::string buffer = "";
    while(true) {
        uint8_t byte;
        i_stream.read(reinterpret_cast<char*>(&byte), sizeof(uint8_t));
        if(i_stream.fail()) break;

        for(size_t i = 0; i < 8; i++) {
            uint8_t bit = byte & (1 << (7 - i));
            if(bit != 0) buffer += "1";
            else buffer += "0";
            if(tree.have_code_sumbol(buffer)) {
                uint8_t symbol = tree.get_code_sumbol(buffer);
                o_stream.write(reinterpret_cast<char*>(&symbol), sizeof(uint8_t));

                std::cout << "buffer " << buffer << " symbol: " << symbol << '\n';

                buffer = "";
            }
        }

    }

}
