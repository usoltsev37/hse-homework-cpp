#include <iostream>
#include "bin_manip.h"

const int MAX_INT = 1000 * 1000 * 1000;

std::istream &read_bool::operator()(std::istream &is) const {
    unsigned char byte;
    is >> byte;
    if (byte == 0 || byte == 1)
        _value = byte;
    else
        is.setstate(std::ios_base::failbit);
    return is;
}

std::istream &operator>>(std::istream &is, read_bool read) {
    return read(is);
}

std::ostream &write_bool::operator()(std::ostream &os) const {
    os << static_cast<unsigned char>(_value);
    return os;
}

std::ostream &operator<<(std::ostream &os, write_bool write) {
    return write(os);
}

std::istream &read_int32::operator()(std::istream &is) const {
    unsigned char byte;
    _value = 0;
    for (int i = 0; i < static_cast<int>(sizeof(int)); i++) {
        is >> byte;
        _value |= static_cast<int32_t>(byte) << (8 * i);
    }
    if (_value < 0 || _value > MAX_INT) {
        _value = 0;
        is.setstate(std::ios_base::failbit);
    }
    return is;
}

std::istream &operator>>(std::istream &is, read_int32 read) {
    return read(is);
}

std::ostream &write_int32::operator()(std::ostream &os) const {
    os << static_cast<unsigned char>(_value) << static_cast<unsigned char>(_value >> 8);
    os << static_cast<unsigned char>(_value >> 16) << static_cast<unsigned char>(_value >> 24);
    return os;
}

std::ostream &operator<<(std::ostream &os, write_int32 write) {
    return write(os);
}

std::istream &read_string::operator()(std::istream &is) const {
    unsigned char byte;
    _value = "";
    is >> byte;
    while (byte) {
        _value.push_back(byte);
        is >> byte;
    }
    if (_value.length() == 0 || _value.length() > 100) {
        _value = "";
        is.setstate(std::ios_base::failbit);
    }
    return is;
}

std::istream &operator>>(std::istream &is, read_string read) {
    return read(is);
}

std::ostream &write_string::operator()(std::ostream &os) const {
    int32_t sz = static_cast<int>(_value.size());
    for (int i = 0; i < sz; i++) {
        os << static_cast<unsigned char>(_value[i]);
    }
    os << '\0';
    return os;
}

std::ostream &operator<<(std::ostream &os, write_string write) {
    return write(os);
}
