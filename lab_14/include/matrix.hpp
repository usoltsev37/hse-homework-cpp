#pragma once

#include <vector>
#include <string>
#include <stdexcept>
#include <iostream>

class Matrix {
public:
    Matrix() = default;

    Matrix(size_t row, size_t col);

    void print(std::ostream &os) const noexcept;

    int get_elem(int x, int y) const noexcept(false);

    Matrix &operator+=(const Matrix &other) noexcept(false);

    Matrix &operator*=(const Matrix &other) noexcept(false);

    std::ifstream &operator>>(std::ifstream &is) noexcept(false);

    std::ostream &operator<<(std::ostream &os) const noexcept;

private:
    std::vector<std::vector<int>> matrix;
    size_t row = 0;
    size_t col = 0;
};

class MatrixException : public std::exception {
public:

    explicit MatrixException(std::string message_);

    const char *what() const noexcept override;

private:
    std::string message;
};
