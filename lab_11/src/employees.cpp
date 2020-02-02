#include <string.h>
#include <string>

#include "employees.h"
#include "bin_manip.h"

std::istream &operator>>(std::istream &is, Employee &empl) {
    empl.scanf_istream(is);
    return is;
}

std::ostream &operator<<(std::ostream &os, const Employee &empl) {
    empl.print_ostream(os);
    return os;
}

std::ifstream &operator>>(std::ifstream &is, Employee &empl) {
    empl.scanf_file(is);
    return is;
}

std::ofstream &operator<<(std::ofstream &os, const Employee &empl) {
    empl.printf_file(os);
    return os;
}

void Developer::scanf_istream(std::istream &is) {
    is >> _name >> _base_salary >> _has_bonus;
}

void Developer::print_ostream(std::ostream &os) const {
    os << "Developer" << "\n"
       << "Name: " << _name << "\n"
       << "Base Salary: " << _base_salary << "\n"
       << "Has bonus: " << (_has_bonus ? "+" : "-") << "\n";
}

void Developer::scanf_file(std::ifstream &is) {
    is >> read_string(_name) >> read_int32(_base_salary) >> read_bool(_has_bonus);
}

void Developer::printf_file(std::ofstream &os) const {
    os << write_int32(1) << write_string(_name);
    os << write_int32(_base_salary) << write_bool(_has_bonus);
}

int Developer::salary() const {
    int salary = _base_salary;
    if (_has_bonus) { salary += 1000; }
    return salary;
}

Employee *Developer::clone() const {
    Developer *copy = new Developer;
    *copy = *this;
    return copy;
}

void SalesManager::scanf_istream(std::istream &is) {
    is >> _name >> _base_salary >> _sold_nm >> _price;
}

void SalesManager::print_ostream(std::ostream &os) const {
    os << "Sales Manager" << "\n"
       << "Name: " << _name << "\n"
       << "Base Salary: " << _base_salary << "\n"
       << "Sold items: " << _sold_nm << "\n"
       << "Item price: " << _price << "\n";
}

void SalesManager::scanf_file(std::ifstream &is) {
    is >> read_string(_name) >> read_int32(_base_salary) >> read_int32(_sold_nm) >> read_int32(_price);
}

void SalesManager::printf_file(std::ofstream &os) const {
    os << write_int32(2) << write_string(_name);
    os << write_int32(_base_salary) << write_int32(_sold_nm) << write_int32(_price);
}

int SalesManager::salary() const {
    return _base_salary + _sold_nm * _price * 0.01;
}

Employee *SalesManager::clone() const {
    SalesManager *copy = new SalesManager;
    *copy = *this;
    return copy;
}

EmployeesArray::~EmployeesArray() {
    int32_t sz = get_size();
    for (int i = 0; i < sz; i++) {
        delete _array[i];
    }
}

void EmployeesArray::add(const Employee *empl) {
    _array.push_back(empl->clone());
}

int32_t EmployeesArray::total_salary() const {
    int32_t sum = 0;
    int32_t size = get_size();
    for (int i = 0; i < size; i++) {
        sum += _array[i]->salary();
    }
    return sum;
}

int32_t EmployeesArray::get_size() const {
    return _array.size();
}

std::ostream &EmployeesArray::write(std::ostream &os) const {
    int32_t sz = get_size();
    for (int i = 1; i <= sz; i++) {
        os << i << ". ";
        os << *_array[i - 1];
    }
    os << "== Total salary: " << total_salary() << "\n";
    return os;
}

std::ostream &operator<<(std::ostream &os, const EmployeesArray &arr) {
    return arr.write(os);
}

std::ifstream &EmployeesArray::read(std::ifstream &is) {
    int32_t sz;
    is >> read_int32(sz);
    for (int i = 0; i < sz; i++) {
        int32_t type;
        is >> read_int32(type);
        Employee *empl = nullptr;
        make_new_empl(empl, type);
        is >> (*empl);
        add(empl);
    }
    return is;
}

std::ifstream &operator>>(std::ifstream &is, EmployeesArray &arr) {
    arr.read(is);
    return is;
}

std::ofstream &EmployeesArray::write(std::ofstream &os) const {
    size_t sz = static_cast<size_t>(get_size());
    os << write_int32(static_cast<int32_t>(sz));
    for (size_t i = 0; i < sz; i++) {
        os << (*_array[i]);
    }
    return os;
}

std::ofstream &operator<<(std::ofstream &os, const EmployeesArray &arr) {
    arr.write(os);
    return os;
}

void make_new_empl(Employee *&empl, int type) {
    if (type == DEVELOPER) {
        empl = new Developer;
    } else if (type == SALES_MANAGER) {
        empl = new SalesManager;
    } else {
        assert(!"Unknown command\n");
    }
}
