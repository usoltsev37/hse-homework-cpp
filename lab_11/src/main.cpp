#include <iostream>
#include <string>
#include <fstream>
#include <assert.h>
#include "employees.h"
#include "bin_manip.h"

void add_employee(EmployeesArray &arr) {
    int type;
    std::cin >> type;
    Employee *empl = nullptr;
    make_new_empl(empl, type);
    std::cin >> *empl;
    arr.add(empl);
}

void load_file(std::string &file, EmployeesArray &arr) {
    std::ifstream ifs(file, std::ios::binary);
    ifs >> arr;
    ifs.close();
}

void save_file(std::string &file, EmployeesArray &arr) {
    std::ofstream ofs;
    ofs.open(file);
    ofs << arr;
    ofs.close();
}

int main() {
    EmployeesArray arr;
    std::string command;
    while (std::cin >> command) {
        if (command == "add") {
            add_employee(arr);
        } else if (command == "load") {
            std::string file;
            std::cin >> file;
            load_file(file, arr);
        } else if (command == "save") {
            std::string file;
            std::cin >> file;
            save_file(file, arr);
        } else if (command == "list") {
            std::cout << arr;
        } else if (command == "exit") {
            return 0;
        } else {
            assert(!"Unknown command\n");
        }
    }
}
