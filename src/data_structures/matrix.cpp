#include "data_structures/matrix.h"

#include <math.h>

#include "data_structures/tuples.h"

Matrix::Matrix() : width(0), height(0) {
    matrix = std::vector<std::vector<double>>(
        this->height, std::vector<double>(this->width, 0));
}

Matrix::Matrix(int width, int height) : width(width), height(height) {
    matrix = std::vector<std::vector<double>>(
        this->height, std::vector<double>(this->width, 0));
}

Matrix Matrix::get_identity_matrix() {
    if (this->width != this->height) {
        throw std::length_error(
            "Identity matrix must have same width and height");
    }

    Matrix identity(this->width, this->height);
    for (int i = 0; i < identity.matrix.size(); i++) {
        for (int j = 0; j < identity.matrix[i].size(); j++) {
            if (i == j) {
                identity.matrix[i][j] = 1;
            }
        }
    }

    return identity;
}

Matrix Matrix::transpose() {
    Matrix transpose(this->height, this->width);
    for (int i = 0; i < this->matrix.size(); i++) {
        for (int j = 0; j < this->matrix[i].size(); j++) {
            transpose.matrix[j][i] = this->matrix[i][j];
        }
    }
    return transpose;
}

double Matrix::determinant() {
    if (this->width == 1 && this->height == 1) {
        return this->matrix[0][0];
    }

    if (this->width == 2 && this->height == 2) {
        return this->matrix[0][0] * this->matrix[1][1] -
               this->matrix[0][1] * this->matrix[1][0];
    }

    int sum = 0;
    for (int j = 0; j < this->matrix[0].size(); j++) {
        if (j % 2 == 0) {
            sum += this->matrix[0][j] * submatrix(0, j).determinant();
        } else {
            sum -= this->matrix[0][j] * submatrix(0, j).determinant();
        }
    }

    return sum;
}

Matrix Matrix::submatrix(int row, int col) {
    Matrix submatrix(this->width - 1, this->height - 1);

    for (int i = 0; i < this->matrix.size(); i++) {
        for (int j = 0; j < this->matrix[i].size(); j++) {
            if (i != row && j != col) {
                submatrix.matrix[i > row ? i - 1 : i][j > col ? j - 1 : j] =
                    this->matrix[i][j];
            }
        }
    }

    return submatrix;
}

double Matrix::minor(int row, int col) {
    return submatrix(row, col).determinant();
}

double Matrix::cofactor(int row, int col) {
    return minor(row, col) * ((row + col) % 2 == 0 ? 1 : -1);
}

bool Matrix::invertible() { return determinant() != 0; }

Matrix Matrix::inverse() {
    if (!invertible()) {
        throw std::invalid_argument("Matrix not invertible!");
    }

    Matrix inverse_matrix(this->width, this->height);

    double det = determinant();
    for (int i = 0; i < inverse_matrix.matrix.size(); i++) {
        for (int j = 0; j < inverse_matrix.matrix[i].size(); j++) {
            double c = cofactor(i, j);
            inverse_matrix.matrix[j][i] = c / det;
        }
    }

    return inverse_matrix;
}

bool Matrix::operator==(const Matrix& rhs) const {
    if (this->width != rhs.width || this->height != rhs.height) {
        return false;
    }

    for (int i = 0; i < this->matrix.size(); i++) {
        for (int j = 0; j < this->matrix[i].size(); j++) {
            if (abs(this->matrix[i][j] - rhs.matrix[i][j]) > Tuple::EPSILON) {
                return false;
            }
        }
    }

    return true;
}

Matrix Matrix::operator*(const Matrix& rhs) const {
    if (this->width != rhs.height) {
        throw std::length_error("Invalid Matrix column and row combination");
    }
    Matrix result(rhs.width, this->height);

    for (int i = 0; i < result.matrix.size(); i++) {
        for (int j = 0; j < result.matrix[i].size(); j++) {
            double sum = 0;
            for (int k = 0; k < this->width; k++) {
                sum += this->matrix[i][k] * rhs.matrix[k][j];
            }
            result.matrix[i][j] = sum;
        }
    }

    return result;
}

Tuple Matrix::operator*(const Tuple& rhs) const {
    Matrix tuple_matrix(1, 4);
    tuple_matrix.matrix[0][0] = rhs.get_x();
    tuple_matrix.matrix[1][0] = rhs.get_y();
    tuple_matrix.matrix[2][0] = rhs.get_z();
    tuple_matrix.matrix[3][0] = rhs.get_w();

    Matrix temp_result = *this * tuple_matrix;

    Tuple result;

    result.set_x(temp_result.matrix[0][0]);
    result.set_y(temp_result.matrix[1][0]);
    result.set_z(temp_result.matrix[2][0]);
    result.set_w(temp_result.matrix[3][0]);

    return result;
}

bool Matrix::operator!=(const Matrix& rhs) const {
    if (this->width != rhs.width || this->height != rhs.height) {
        return true;
    }
    for (int i = 0; i < this->matrix.size(); i++) {
        for (int j = 0; j < this->matrix[i].size(); j++) {
            if (abs(this->matrix[i][j] - rhs.matrix[i][j]) > Tuple::EPSILON) {
                return true;
            }
        }
    }

    return false;
}

std::ostream& operator<<(std::ostream& os, const Matrix& matrix) {
    for (auto height : matrix.matrix) {
        std::string line;
        for (auto width : height) {
            line.append(std::to_string((int)round(width)) + " ");
        }
        line.pop_back();
        os << line << std::endl;
    }
    return os;
}