#include "matrix.hpp"
#include <iostream>
#include <fstream>
#include <cassert>

Matrix::Matrix(size_t row, size_t col) : row(row), col(col) {
    matrix.resize(row);
    for (size_t i = 0; i < row; i++) {
        matrix[i].resize(col);
    }
}

void Matrix::print() const noexcept {
    for (auto &matrix_row : matrix) {
        for (const int &element : matrix_row) {
            std::cout << element << ' ';
        }
        std::cout << '\n';
    }
}

int Matrix::get_elem(int x, int y) const noexcept(false) {
    if (x < 0 || y < 0 || x >= row || y >= col)
        throw MatrixException("ACCESS: bad index.");
    return matrix[x][y];
}

void Matrix::add(Matrix &other) noexcept(false) {
    if (row != other.row || col != other.col)
        throw MatrixException("ADD: dimensions do not match.");
    for (size_t i = 0; i < row; i++) {
        for (size_t j = 0; j < col; j++) {
            matrix[i][j] += other.get_elem(i, j);
        }
    }
}

void Matrix::mul(Matrix &other) noexcept(false) {
    if (col != other.row)
        throw MatrixException("MUL: #arg1.columns != #arg2.rows.");
    Matrix buf(row, other.col);
    for (size_t i = 0; i < row; i++) {
        for (size_t j = 0; j < other.col; j++) {
            int sum = 0;

            for (size_t count = 0; count < col; count++) {
                sum += matrix[i][count] * other.matrix[count][j];
            }

            buf.matrix[i][j] = sum;
        }
    }
    matrix = buf.matrix;
    col = other.col;
}

void Matrix::load(const std::string &file) noexcept(false) {
    std::ifstream is(file);
    if (!is.is_open()) {
        throw MatrixException("LOAD: unable to open file.");
    }

    int buffer_int;

    for (int i = 0; i < 2; i++) {
        is >> buffer_int;
        if (!is.fail() && i == 0)
            row = buffer_int;
        else if(!is.fail() && i == 1)
            col = buffer_int;
        else
            throw MatrixException("LOAD: invalid file format.");
    }

    Matrix buffer(row, col);

    for (size_t i = 0; i < row; i++) {
        for (size_t j = 0; j < col; j++) {
            is >> buffer_int;
            if (!is.fail()) {
                buffer.matrix[i][j] = buffer_int;
            } else
                throw MatrixException("LOAD: invalid file format.");
        }
    }
    matrix = buffer.matrix;
    is.close();
}

MatrixException::MatrixException(const char *message) : message(message) {}

const char *MatrixException::what() const noexcept {
    return message;
}
