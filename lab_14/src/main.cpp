#include <iostream>
#include "matrix.hpp"

int main() {
    const size_t count_of_regs = 10;
    std::vector<Matrix> array_matrix(count_of_regs);
    while (true) {
        std::string s_in;
        std::cin >> s_in;
        try {
            if (s_in == "load") {
                char temp;
                size_t reg;
                std::string filename;
                std::cin >> temp >> reg >> filename;
                array_matrix[reg].load(filename);
            } else if (s_in == "print") {
                char temp;
                size_t reg;
                std::cin >> temp >> reg;
                array_matrix[reg].print();
            } else if (s_in == "add") {
                char temp;
                size_t reg1, reg2;
                std::cin >> temp >> reg1 >> temp >> reg2;
                array_matrix[reg1].add(array_matrix[reg2]);
            } else if (s_in == "mul") {
                char temp;
                size_t reg1, reg2;
                std::cin >> temp >> reg1 >> temp >> reg2;
                array_matrix[reg1].mul(array_matrix[reg2]);
            } else if (s_in == "elem") {
                char temp;
                size_t reg;
                size_t row, col;
                std::cin >> temp >> reg >> row >> col;
                std::cout << array_matrix[reg].get_elem(row, col) << '\n';
            } else if (s_in == "exit") {
                return 0;
            }
        } catch (MatrixException &e) {
            std::cout << e.what() << '\n';
        } catch (std::bad_alloc &e) {
            std::cout << "Unable to allocate memory.\n";
        }
    }
}
