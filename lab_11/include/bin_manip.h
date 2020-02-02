#pragma once

#include <fstream>
#include <string>

class read_bool { //failbit
public:
    explicit read_bool(bool &value) : _value(value) {}

    std::istream &operator()(std::istream &is) const;

private:
    bool &_value;
};

std::istream &operator>>(std::istream &is, read_bool read);

class write_bool {
public:
    explicit write_bool(const bool value) : _value(value) {}

    std::ostream &operator()(std::ostream &) const;

private:
    bool _value;
};

std::ostream &operator<<(std::ostream &os, write_bool write);


class read_int32 {
public:
    explicit read_int32(int32_t &value) : _value(value) {}

    std::istream &operator()(std::istream &is) const;

private:
    int32_t &_value;
};

std::istream &operator>>(std::istream &is, read_int32 read);

class write_int32 {
public:
    explicit write_int32(const int32_t value) : _value(value) {}

    std::ostream &operator()(std::ostream &os) const;

private:
    int32_t _value;
};

std::ostream &operator<<(std::ostream &os, write_int32 write);


class read_string {
public:
    explicit read_string(std::string &value) : _value(value) {}

    std::istream &operator()(std::istream &is) const;

private:
    std::string &_value;
};

std::istream &operator>>(std::istream &is, read_string read);


class write_string {
public:
    explicit write_string(const std::string &value) : _value(value) {}

    std::ostream &operator()(std::ostream &is) const;

private:
    std::string _value;
};

std::ostream &operator<<(std::ostream &os, write_string write);

