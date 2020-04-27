#include "doctest.h"
#include "Huffman.hpp"

TEST_CASE("test HuffmanTree") {
    SUBCASE("test get_NodeBySymbol()") {
        uint8_t symbol = '\x1a';
        std::map<uint8_t, int> freq{{'\x01', 2},
                                    {'\x02', 1},
                                    {'\x0a', 3},
                                    {'\x11', 1},
                                    {'\x12', 1},
                                    {symbol, 5},
        };
        HuffmanTree tree(freq);
        uint8_t test = tree.get_NodeBySymbol(symbol)->get_value();
        CHECK(test == symbol);
    }

    SUBCASE("test have_code_sumbol()_true") {
        uint8_t symbol = '\x1a';
        std::map<uint8_t, int> freq{{'\x01', 2},
                                    {'\x02', 1},
                                    {'\x0a', 3},
                                    {'\x11', 1},
                                    {'\x12', 1},
                                    {symbol, 5},
        };
        HuffmanTree tree(freq);
        std::string code = "11";
        bool test = tree.have_code_symbol(code);
        CHECK(test);
    }

    SUBCASE("test have_code_symbol()_false") {
        uint8_t symbol = '\x1a';
        std::map<uint8_t, int> freq{{'\x01', 2},
                                    {'\x02', 1},
                                    {'\x0a', 3},
                                    {'\x11', 1},
                                    {'\x12', 1},
                                    {symbol, 5},
        };
        HuffmanTree tree(freq);
        std::string code = "10000000011";
        bool test = tree.have_code_symbol(code);
        CHECK(!test);
    }

    SUBCASE("test get_code_symbol") {
        uint8_t symbol = '\x1a';
        std::map<uint8_t, int> freq{{'\x01', 2},
                                    {'\x02', 1},
                                    {'\x0a', 3},
                                    {'\x11', 1},
                                    {'\x12', 1},
                                    {symbol, 5},
        };
        HuffmanTree tree(freq);
        std::string code = "11";
        uint8_t test = tree.get_code_symbol(code);
        CHECK(test == symbol);
    }
}