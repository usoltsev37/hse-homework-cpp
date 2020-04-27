#include "doctest.h"
#include "Huffman.hpp"

#include <iostream>

TEST_CASE("test HuffmanTree") {

    /*
    SUBCASE("test HuffmanNode::get_code()") {
        uint8_t symbol = '\x1a';
        std::map<uint8_t, int> freq{{'\x01', 2},
                                    {'\x02', 1},
                                    {'\x0a', 3},
                                    {'\x11', 1},
                                    {'\x12', 1},
                                    {symbol, 5},
        };
        HuffmanTree tree(freq);
        HuffmanTree::HuffmanNode* node = tree.get_NodeBySymbol(symbol);
        //using std::cout;
        //cout << node->get_code() << '\n';
        std::string test = node->get_code();
        CHECK(test == "101");
    } */

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
}