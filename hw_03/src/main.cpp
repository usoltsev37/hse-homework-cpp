#include <iostream>
#include <fstream>
#include <sstream>
#include "HuffmanArchiver.hpp"
#include "Huffman.hpp"
#include "CLI.hpp"

int main(int argc, char *argv[]) {
    try {
        CLI parcer(argc, argv);

        HuffmanArchiver archiver;

        if(parcer.get_mode() == COMPRESS) {
            std::ifstream i_stream(parcer.get_infile(), std::ifstream::binary);
            std::ofstream o_stream(parcer.get_outfile(), std::ofstream::binary);
            archiver.compress_archive(i_stream, o_stream);
        } else if(parcer.get_mode() == EXTRACT) {
            std::ifstream i_stream;
            std::ofstream o_stream;
        }



    } catch(ParceException &e) {
        std::cout << e.what() << '\n';
    } catch (std::exception &e) {
        std::cout << e.what() << '\n';
    }

    //std::ifstream input;


    return 0;
}

//