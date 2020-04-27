#include "doctest.h"
#include "HuffmanArchiver.hpp"
#include <sstream>


TEST_CASE("test HuffmanArchiver") {
    SUBCASE("test end2end") {
        std::string s = "I'm only a man with a chamber who's got me,\n";
        std::stringstream input(s);
        std::stringstream output;

        HuffmanArchiver archiver;
        archiver.compress_archive(input, output);

        std::stringstream output_decode;
        archiver.extract_archive(output, output_decode);

        bool test = (s == input.str());
        CHECK(test);
    }

    SUBCASE("test end2end") {
        std::string s = "Мне скулы от досады сводит:\n"
                        "Мне кажется который год,\n"
                        "Что там, где я,- там жизнь проходит,\n"
                        "А там, где нет меня,- идет!\n"
                        "А дальше - больше, каждый день я\n"
                        "Стал слышать злые голоса:\n"
                        "Где ты - там только наважденье,\n"
                        "Где нет тебя - все чудеса.\n"
                        "...\n"
                        "1979\n"
                        "Владимир Высоцкий\n";
        std::stringstream input(s);
        std::stringstream output;

        HuffmanArchiver archiver;
        archiver.compress_archive(input, output);

        std::stringstream output_decode;
        archiver.extract_archive(output, output_decode);

        bool test = (s == input.str());
                CHECK(test);
    }

    SUBCASE("test printStat_compress") {
        std::string s = "I'm only a man with a chamber who's got me,\n";
        std::stringstream input(s);
        std::stringstream output;

        HuffmanArchiver archiver;
        archiver.compress_archive(input, output);
        std::stringstream stat_compress;
        archiver.print_stat(stat_compress);


        std::string test = "44\n23\n118\n";
        CHECK(test == stat_compress.str());
    }

    SUBCASE("test printStat_extract") {
        std::string s = "I'm only a man with a chamber who's got me,\n";
        std::stringstream input(s);
        std::stringstream output;

        HuffmanArchiver archiver;
        archiver.compress_archive(input, output);
        std::stringstream output_decode;
        archiver.extract_archive(output, output_decode);

        std::stringstream stat_compress;
        archiver.print_stat(stat_compress);


        std::string test = "23\n44\n118\n";
        CHECK(test == stat_compress.str());
    }

}