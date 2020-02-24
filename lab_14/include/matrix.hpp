#pragma once

#include <vector>
#include <string>
#include <stdexcept>

class Matrix {
public:
    Matrix() = default;

    Matrix(size_t row, size_t col);

    void print() const noexcept;

    int get_elem(int x, int y) const noexcept(false);

    void add(Matrix &other) noexcept(false);

    void mul(Matrix &other) noexcept(false);

    void load(const std::string &file) noexcept(false);

private:
    std::vector<std::vector<int>> matrix;
    size_t row = 0;
    size_t col = 0;
};

class MatrixException : public std::exception {
public:

    explicit MatrixException(const char *message);

    const char *what() const noexcept override;

private:
    const char *message;
};
