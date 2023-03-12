#ifndef MATRIX_H_
#define MATRIX_H_

#include <ostream>
#include <vector>

#include "data_structures/tuples.h"

struct Matrix {
    int width;
    int height;
    std::vector<std::vector<double>> matrix;

    Matrix();
    Matrix(int width, int height);
    Matrix get_identity_matrix();
    Matrix transpose();
    double determinant();
    Matrix submatrix(int row, int col);
    double minor(int row, int col);
    double cofactor(int row, int col);
    bool invertible();
    Matrix inverse();

    Matrix operator*(const Matrix& rhs) const;
    Tuple operator*(const Tuple& rhs) const;

    bool operator==(const Matrix& rhs) const;
    bool operator!=(const Matrix& rhs) const;

    friend std::ostream& operator<<(std::ostream& os, const Matrix& matrix);
};

#endif  // MATRIX_H_