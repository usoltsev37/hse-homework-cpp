#pragma once

#include <stdint.h>
#include <iostream>
#include <vector>

class Employee {
public:
    virtual ~Employee() = default;

    friend std::istream &operator>>(std::istream &is, Employee &empl);

    friend std::ostream &operator<<(std::ostream &os, const Employee &empl);

    friend ::std::ifstream &operator>>(std::ifstream &is, Employee &empl);

    friend ::std::ofstream &operator<<(std::ofstream &os, const Employee &empl);

    virtual int salary() const = 0;

    virtual Employee *clone() const = 0;

protected:
    virtual void scanf_istream(std::istream &is) = 0;

    virtual void print_ostream(std::ostream &os) const = 0;

    virtual void scanf_file(std::ifstream &is) = 0;

    virtual void printf_file(std::ofstream &os) const = 0;

    std::string _name;
    int32_t _base_salary;
};

class Developer : public Employee {
public:
    ~Developer() override = default;

    void scanf_istream(std::istream &is) override;

    void print_ostream(std::ostream &os) const override;

    void scanf_file(std::ifstream &is) override;

    void printf_file(std::ofstream &os) const override;

    int salary() const override;

    Employee *clone() const override;

private:
    bool _has_bonus;
};

class SalesManager : public Employee {
public:
    ~SalesManager() override = default;

    void scanf_istream(std::istream &is) override;

    void print_ostream(std::ostream &os) const override;

    void scanf_file(std::ifstream &is) override;

    void printf_file(std::ofstream &os) const override;

    int salary() const override;

    Employee *clone() const override;

private:
    int32_t _sold_nm, _price;
};


class EmployeesArray {
public:
    EmployeesArray() = default;

    ~EmployeesArray();

    EmployeesArray &operator=(const EmployeesArray &) = delete;

    EmployeesArray(const EmployeesArray &) = delete;

    void add(const Employee *e);

    int32_t total_salary() const;

    int32_t get_size() const;

    friend std::ostream &operator<<(std::ostream &os, const EmployeesArray &arr);

    friend std::ifstream &operator>>(std::ifstream &is, EmployeesArray &arr);

    friend std::ofstream &operator<<(std::ofstream &os, const EmployeesArray &arr);

private:
    std::ostream &write(std::ostream &os) const;

    std::ifstream &read(std::ifstream &is);

    std::ofstream &write(std::ofstream &os) const;

    std::vector<Employee *> _array;
};

enum Employee_num {
    NONE,
    DEVELOPER,
    SALES_MANAGER
};

void make_new_empl(Employee *&empl, int type);

