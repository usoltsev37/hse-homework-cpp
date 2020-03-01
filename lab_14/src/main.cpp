#include <iostream>
#include <fstream>
#include "matrix.hpp"

int main() {
    const size_t count_of_regs = 10;
    std::vector<Matrix> registers(count_of_regs);
    while (true) {
        std::string command;
        std::cin >> command;
        try {
            if (command == "load") {
                char temp;
                size_t reg;
                std::string filename;
                std::cin >> temp >> reg >> filename;
                std::ifstream is(filename);
                registers[reg] >> is;
                is.close();
            } else if (command == "print") {
                char temp;
                size_t reg;
                std::cin >> temp >> reg;
                registers[reg] << std::cout;
            } else if (command == "add") {
                char temp;
                size_t reg1, reg2;
                std::cin >> temp >> reg1 >> temp >> reg2;
                registers[reg1] += registers[reg2];
            } else if (command == "mul") {
                char temp;
                size_t reg1, reg2;
                std::cin >> temp >> reg1 >> temp >> reg2;
                registers[reg1] *= registers[reg2];
            } else if (command == "elem") {
                char temp;
                size_t reg;
                size_t row, col;
                std::cin >> temp >> reg >> row >> col;
                std::cout << registers[reg].get_elem(row, col) << '\n';
            } else if (command == "exit") {
                return 0;
            }
        } catch (MatrixException &e) {
            std::cout << e.what() << '\n';
        } catch (std::bad_alloc &e) {
            std::cout << "Unable to allocate memory.\n";
        }
    }
}
