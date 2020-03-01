#include "matrix.hpp"
#include <iostream>
#include <fstream>
#include <utility>

Matrix::Matrix(size_t row, size_t col) : row(row), col(col),
                                         matrix(std::vector<std::vector<int>>(row, std::vector<int>(col, 0))) {}

void Matrix::print(std::ostream &os) const noexcept {
    for (auto &matrix_row : matrix) {
        for (const int &element : matrix_row) {
            os << element << ' ';
        }
        os << '\n';
    }
}

int Matrix::get_elem(int x, int y) const noexcept(false) {
    if (x < 0 || y < 0 || x >= row || y >= col)
        throw MatrixException("ACCESS: bad index.");
    return matrix[x][y];
}

Matrix &Matrix::operator+=(const Matrix &other) noexcept(false) {
    if (row != other.row || col != other.col)
        throw MatrixException("ADD: dimensions do not match.");
    for (size_t i = 0; i < row; i++) {
        for (size_t j = 0; j < col; j++) {
            matrix[i][j] += other.matrix[i][j];
        }
    }
    return *this;
}

Matrix &Matrix::operator*=(const Matrix &other) noexcept(false) {
    if (col != other.row)
        throw MatrixException("MUL: #arg1.columns != #arg2.rows.");
    Matrix product(*this);
    for (size_t i = 0; i < row; i++) {
        for (size_t j = 0; j < other.col; j++) {
            int sum = 0;

            for (size_t count = 0; count < col; count++) {
                sum += matrix[i][count] * other.matrix[count][j];
            }

            product.matrix[i][j] = sum;
        }
    }
    *this = product;
    return *this;
}

std::ifstream &Matrix::operator>>(std::ifstream &is) noexcept(false) {
    if (!is.is_open()) {
        throw MatrixException("LOAD: unable to open file.");
    }
    is.exceptions(std::ifstream::failbit);
    try {
        int buffer_int;

        is >> buffer_int;
        row = buffer_int;

        is >> buffer_int;
        col = buffer_int;

        Matrix buffer(row, col);

        for (size_t i = 0; i < row; i++) {
            for (size_t j = 0; j < col; j++) {
                is >> buffer_int;
                buffer.matrix[i][j] = buffer_int;
            }
        }
        matrix = buffer.matrix;
    } catch (std::ifstream::failure &e) {
        throw MatrixException("LOAD: invalid file format.");
    }
    return is;

}

std::ostream &Matrix::operator<<(std::ostream &os) const noexcept {
    print(os);
    return os;
}

MatrixException::MatrixException(std::string message_) : message(std::move(message_)) {}

const char *MatrixException::what() const noexcept {
    return message.c_str();
}
