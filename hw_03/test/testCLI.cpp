//
// Created by Nikita Usoltsev on 27.04.2020.
//
#include "doctest.h"
#include "CLI.hpp"
TEST_CASE("test CLI") {
    SUBCASE("test get_mode()_COMPRESS") {
        int argc = 6;
        char* argv[] = {"./hw_03", "-f", "in_monster.txt", "-c", "-o", "out_monster.bin"};

        CLI parse(argc, argv);
        huffman_mode test = parse.get_mode();
        CHECK(test == COMPRESS);
    }
    SUBCASE("test get_mode()EXTRACT") {
        int argc = 6;
        char* argv[] = {"./hw_03", "-u", "-f", "in_monster.txt", "-o", "out_monster.bin"};
        CLI parse(argc, argv);
        huffman_mode test = parse.get_mode();
        CHECK(test == EXTRACT);
    }
    SUBCASE("test get_infile") {
        int argc = 6;
        char* argv[] = {"./hw_03", "-f", "in_monster.txt", "-u", "-o", "out_monster.bin"};
        CLI parse(argc, argv);
        std::string test = parse.get_infile();
        CHECK(test == "in_monster.txt");
    }
    SUBCASE("test get_outfile") {
        int argc = 6;
        char* argv[] = {"./hw_03", "-u", "-o", "out_monster.bin", "-f", "in_monster.txt",};
        CLI parse(argc, argv);
        std::string test = parse.get_outfile();
        CHECK(test == "out_monster.bin");
    }

}
