#include "data_structures/matrix.h"

#include <gtest/gtest.h>

#include "data_structures/tuples.h"

TEST(MatrixUnitTests, construct_inspect_4_x_4_matrix) {
    Matrix matrix(4, 4);
    matrix.matrix[0][0] = 1;
    matrix.matrix[0][1] = 2;
    matrix.matrix[0][2] = 3;
    matrix.matrix[0][3] = 4;

    matrix.matrix[1][0] = 5.5;
    matrix.matrix[1][1] = 6.5;
    matrix.matrix[1][2] = 7.5;
    matrix.matrix[1][3] = 8.5;

    matrix.matrix[2][0] = 9;
    matrix.matrix[2][1] = 10;
    matrix.matrix[2][2] = 11;
    matrix.matrix[2][3] = 12;

    matrix.matrix[3][0] = 13.5;
    matrix.matrix[3][1] = 14.5;
    matrix.matrix[3][2] = 15.5;
    matrix.matrix[3][3] = 16.5;

    EXPECT_EQ(matrix.matrix[0][0], 1);
    EXPECT_EQ(matrix.matrix[0][3], 4);
    EXPECT_EQ(matrix.matrix[1][0], 5.5);
    EXPECT_EQ(matrix.matrix[1][2], 7.5);
    EXPECT_EQ(matrix.matrix[2][2], 11);
    EXPECT_EQ(matrix.matrix[3][0], 13.5);
    EXPECT_EQ(matrix.matrix[3][2], 15.5);
}

TEST(MatrixUnitTests, construct_inspect_2_x_2_matrix) {
    Matrix matrix(2, 2);
    matrix.matrix[0][0] = -3;
    matrix.matrix[0][1] = 5;

    matrix.matrix[1][0] = 1;
    matrix.matrix[1][1] = -2;

    EXPECT_EQ(matrix.matrix[0][0], -3);
    EXPECT_EQ(matrix.matrix[0][1], 5);
    EXPECT_EQ(matrix.matrix[1][0], 1);
    EXPECT_EQ(matrix.matrix[1][1], -2);
}

TEST(MatrixUnitTests, construct_inspect_3_x_3_matrix) {
    Matrix matrix(4, 4);
    matrix.matrix[0][0] = -3;
    matrix.matrix[0][1] = 5;
    matrix.matrix[0][2] = 0;

    matrix.matrix[1][0] = 1;
    matrix.matrix[1][1] = -2;
    matrix.matrix[1][2] = -7;

    matrix.matrix[2][0] = 0;
    matrix.matrix[2][1] = 1;
    matrix.matrix[2][2] = 1;

    EXPECT_EQ(matrix.matrix[0][0], -3);
    EXPECT_EQ(matrix.matrix[1][1], -2);
    EXPECT_EQ(matrix.matrix[2][2], 1);
}

TEST(MatrixUnitTests, equate_2_4_x_4_matrix) {
    Matrix a(4, 4);
    a.matrix[0][0] = 1;
    a.matrix[0][1] = 2;
    a.matrix[0][2] = 3;
    a.matrix[0][3] = 4;

    a.matrix[1][0] = 5;
    a.matrix[1][1] = 6;
    a.matrix[1][2] = 7;
    a.matrix[1][3] = 8;

    a.matrix[2][0] = 9;
    a.matrix[2][1] = 10;
    a.matrix[2][2] = 11;
    a.matrix[2][3] = 12;

    a.matrix[3][0] = 13;
    a.matrix[3][1] = 14;
    a.matrix[3][2] = 15;
    a.matrix[3][3] = 16;

    Matrix b(4, 4);
    b.matrix[0][0] = 1;
    b.matrix[0][1] = 2;
    b.matrix[0][2] = 3;
    b.matrix[0][3] = 4;

    b.matrix[1][0] = 5;
    b.matrix[1][1] = 6;
    b.matrix[1][2] = 7;
    b.matrix[1][3] = 8;

    b.matrix[2][0] = 9;
    b.matrix[2][1] = 10;
    b.matrix[2][2] = 11;
    b.matrix[2][3] = 12;

    b.matrix[3][0] = 13;
    b.matrix[3][1] = 14;
    b.matrix[3][2] = 15;
    b.matrix[3][3] = 16;

    EXPECT_TRUE(a == b);
    EXPECT_FALSE(a != b);
}

TEST(MatrixUnitTests, not_equate_2_4_x_4_matrix) {
    Matrix a(4, 4);
    a.matrix[0][0] = 1;
    a.matrix[0][1] = 2;
    a.matrix[0][2] = 3;
    a.matrix[0][3] = 4;

    a.matrix[1][0] = 5;
    a.matrix[1][1] = 6;
    a.matrix[1][2] = 7;
    a.matrix[1][3] = 8;

    a.matrix[2][0] = 9;
    a.matrix[2][1] = 10;
    a.matrix[2][2] = 11;
    a.matrix[2][3] = 12;

    a.matrix[3][0] = 13;
    a.matrix[3][1] = 14;
    a.matrix[3][2] = 15;
    a.matrix[3][3] = 16;

    Matrix b(4, 4);
    b.matrix[0][0] = 2;
    b.matrix[0][1] = 3;
    b.matrix[0][2] = 4;
    b.matrix[0][3] = 5;

    b.matrix[1][0] = 6;
    b.matrix[1][1] = 7;
    b.matrix[1][2] = 8;
    b.matrix[1][3] = 9;

    b.matrix[2][0] = 8;
    b.matrix[2][1] = 7;
    b.matrix[2][2] = 6;
    b.matrix[2][3] = 5;

    b.matrix[3][0] = 4;
    b.matrix[3][1] = 3;
    b.matrix[3][2] = 2;
    b.matrix[3][3] = 1;

    EXPECT_TRUE(a != b);
    EXPECT_FALSE(a == b);
}

TEST(MatrixUnitTests, multiply_2_matrices) {
    Matrix a(4, 4);
    a.matrix[0][0] = 1;
    a.matrix[0][1] = 2;
    a.matrix[0][2] = 3;
    a.matrix[0][3] = 4;

    a.matrix[1][0] = 5;
    a.matrix[1][1] = 6;
    a.matrix[1][2] = 7;
    a.matrix[1][3] = 8;

    a.matrix[2][0] = 9;
    a.matrix[2][1] = 8;
    a.matrix[2][2] = 7;
    a.matrix[2][3] = 6;

    a.matrix[3][0] = 5;
    a.matrix[3][1] = 4;
    a.matrix[3][2] = 3;
    a.matrix[3][3] = 2;

    Matrix b(4, 4);
    b.matrix[0][0] = -2;
    b.matrix[0][1] = 1;
    b.matrix[0][2] = 2;
    b.matrix[0][3] = 3;

    b.matrix[1][0] = 3;
    b.matrix[1][1] = 2;
    b.matrix[1][2] = 1;
    b.matrix[1][3] = -1;

    b.matrix[2][0] = 4;
    b.matrix[2][1] = 3;
    b.matrix[2][2] = 6;
    b.matrix[2][3] = 5;

    b.matrix[3][0] = 1;
    b.matrix[3][1] = 2;
    b.matrix[3][2] = 7;
    b.matrix[3][3] = 8;

    Matrix result(4, 4);
    result.matrix[0][0] = 20;
    result.matrix[0][1] = 22;
    result.matrix[0][2] = 50;
    result.matrix[0][3] = 48;

    result.matrix[1][0] = 44;
    result.matrix[1][1] = 54;
    result.matrix[1][2] = 114;
    result.matrix[1][3] = 108;

    result.matrix[2][0] = 40;
    result.matrix[2][1] = 58;
    result.matrix[2][2] = 110;
    result.matrix[2][3] = 102;

    result.matrix[3][0] = 16;
    result.matrix[3][1] = 26;
    result.matrix[3][2] = 46;
    result.matrix[3][3] = 42;

    EXPECT_EQ(a * b, result);
}

TEST(MatrixUnitTests, multiply_matrix_by_tuple) {
    Matrix a(4, 4);
    a.matrix[0][0] = 1;
    a.matrix[0][1] = 2;
    a.matrix[0][2] = 3;
    a.matrix[0][3] = 4;

    a.matrix[1][0] = 2;
    a.matrix[1][1] = 4;
    a.matrix[1][2] = 4;
    a.matrix[1][3] = 2;

    a.matrix[2][0] = 8;
    a.matrix[2][1] = 6;
    a.matrix[2][2] = 4;
    a.matrix[2][3] = 1;

    a.matrix[3][0] = 0;
    a.matrix[3][1] = 0;
    a.matrix[3][2] = 0;
    a.matrix[3][3] = 1;

    Tuple b(1, 2, 3, 1);

    Tuple result(18, 24, 33, 1);

    EXPECT_EQ(a * b, result);
}

TEST(MatrixUnitTests, multiply_matrix_by_identity) {
    Matrix a(4, 4);
    a.matrix[0][0] = 0;
    a.matrix[0][1] = 1;
    a.matrix[0][2] = 2;
    a.matrix[0][3] = 4;

    a.matrix[1][0] = 1;
    a.matrix[1][1] = 2;
    a.matrix[1][2] = 4;
    a.matrix[1][3] = 8;

    a.matrix[2][0] = 2;
    a.matrix[2][1] = 4;
    a.matrix[2][2] = 8;
    a.matrix[2][3] = 16;

    a.matrix[3][0] = 4;
    a.matrix[3][1] = 8;
    a.matrix[3][2] = 16;
    a.matrix[3][3] = 32;

    EXPECT_EQ(a * a.get_identity_matrix(), a);
}

TEST(MatrixUnitTests, transpose_matrix) {
    Matrix a(4, 4);
    a.matrix[0][0] = 0;
    a.matrix[0][1] = 9;
    a.matrix[0][2] = 3;
    a.matrix[0][3] = 0;

    a.matrix[1][0] = 9;
    a.matrix[1][1] = 8;
    a.matrix[1][2] = 0;
    a.matrix[1][3] = 8;

    a.matrix[2][0] = 1;
    a.matrix[2][1] = 8;
    a.matrix[2][2] = 5;
    a.matrix[2][3] = 3;

    a.matrix[3][0] = 0;
    a.matrix[3][1] = 0;
    a.matrix[3][2] = 5;
    a.matrix[3][3] = 8;

    Matrix result(4, 4);
    result.matrix[0][0] = 0;
    result.matrix[0][1] = 9;
    result.matrix[0][2] = 1;
    result.matrix[0][3] = 0;

    result.matrix[1][0] = 9;
    result.matrix[1][1] = 8;
    result.matrix[1][2] = 8;
    result.matrix[1][3] = 0;

    result.matrix[2][0] = 3;
    result.matrix[2][1] = 0;
    result.matrix[2][2] = 5;
    result.matrix[2][3] = 5;

    result.matrix[3][0] = 0;
    result.matrix[3][1] = 8;
    result.matrix[3][2] = 3;
    result.matrix[3][3] = 8;

    EXPECT_EQ(a.transpose(), result);
}

TEST(MatrixUnitTests, transpose_matrix_identity) {
    Matrix a(5, 5);
    EXPECT_EQ(a.get_identity_matrix().transpose(), a.get_identity_matrix());
}

TEST(MatrixUnitTests, determinant_2_x_2_matrix) {
    Matrix a(2, 2);
    a.matrix[0][0] = 1;
    a.matrix[0][1] = 5;
    a.matrix[1][0] = -3;
    a.matrix[1][1] = 2;
    EXPECT_EQ(a.determinant(), 17);
}

TEST(MatrixUnitTests, submatrix_of_3_x_3_matrix) {
    Matrix a(3, 3);
    a.matrix[0][0] = 1;
    a.matrix[0][1] = 5;
    a.matrix[0][2] = 0;

    a.matrix[1][0] = -3;
    a.matrix[1][1] = 2;
    a.matrix[1][2] = 7;

    a.matrix[2][0] = 0;
    a.matrix[2][1] = 6;
    a.matrix[2][2] = -3;

    Matrix result(2, 2);
    result.matrix[0][0] = -3;
    result.matrix[0][1] = 2;
    result.matrix[1][0] = 0;
    result.matrix[1][1] = 6;

    EXPECT_EQ(a.submatrix(0, 2), result);
}

TEST(MatrixUnitTests, submatrix_of_4_x_4_matrix) {
    Matrix a(4, 4);
    a.matrix[0][0] = -6;
    a.matrix[0][1] = 1;
    a.matrix[0][2] = 1;
    a.matrix[0][3] = 6;

    a.matrix[1][0] = -8;
    a.matrix[1][1] = 5;
    a.matrix[1][2] = 8;
    a.matrix[1][3] = 6;

    a.matrix[2][0] = -1;
    a.matrix[2][1] = 0;
    a.matrix[2][2] = 8;
    a.matrix[2][3] = 2;

    a.matrix[3][0] = -7;
    a.matrix[3][1] = 1;
    a.matrix[3][2] = -1;
    a.matrix[3][3] = 1;

    Matrix result(3, 3);
    result.matrix[0][0] = -6;
    result.matrix[0][1] = 1;
    result.matrix[0][2] = 6;

    result.matrix[1][0] = -8;
    result.matrix[1][1] = 8;
    result.matrix[1][2] = 6;

    result.matrix[2][0] = -7;
    result.matrix[2][1] = -1;
    result.matrix[2][2] = 1;

    EXPECT_EQ(a.submatrix(2, 1), result);
}

TEST(MatrixUnitTests, minor_of_3_x_3_matrix) {
    Matrix a(3, 3);
    a.matrix[0][0] = 3;
    a.matrix[0][1] = 5;
    a.matrix[0][2] = 0;

    a.matrix[1][0] = 2;
    a.matrix[1][1] = -1;
    a.matrix[1][2] = -7;

    a.matrix[2][0] = 6;
    a.matrix[2][1] = -1;
    a.matrix[2][2] = 5;

    EXPECT_EQ(a.minor(1, 0), 25);
}

TEST(MatrixUnitTests, cofactor_of_3_x_3_matrix) {
    Matrix a(3, 3);
    a.matrix[0][0] = 3;
    a.matrix[0][1] = 5;
    a.matrix[0][2] = 0;

    a.matrix[1][0] = 2;
    a.matrix[1][1] = -1;
    a.matrix[1][2] = -7;

    a.matrix[2][0] = 6;
    a.matrix[2][1] = -1;
    a.matrix[2][2] = 5;

    EXPECT_EQ(a.cofactor(0, 0), -12);
    EXPECT_EQ(a.cofactor(1, 0), -25);
}

TEST(MatrixUnitTests, determinant_of_3_x_3_matrix) {
    Matrix a(3, 3);
    a.matrix[0][0] = 1;
    a.matrix[0][1] = 2;
    a.matrix[0][2] = 6;

    a.matrix[1][0] = -5;
    a.matrix[1][1] = 8;
    a.matrix[1][2] = -4;

    a.matrix[2][0] = 2;
    a.matrix[2][1] = 6;
    a.matrix[2][2] = 4;

    EXPECT_EQ(a.cofactor(0, 0), 56);
    EXPECT_EQ(a.cofactor(0, 1), 12);
    EXPECT_EQ(a.cofactor(0, 2), -46);
    EXPECT_EQ(a.determinant(), -196);
}

TEST(MatrixUnitTests, determinant_of_4_x_4_matrix) {
    Matrix a(4, 4);
    a.matrix[0][0] = -2;
    a.matrix[0][1] = -8;
    a.matrix[0][2] = 3;
    a.matrix[0][3] = 5;

    a.matrix[1][0] = -3;
    a.matrix[1][1] = 1;
    a.matrix[1][2] = 7;
    a.matrix[1][3] = 3;

    a.matrix[2][0] = 1;
    a.matrix[2][1] = 2;
    a.matrix[2][2] = -9;
    a.matrix[2][3] = 6;

    a.matrix[3][0] = -6;
    a.matrix[3][1] = 7;
    a.matrix[3][2] = 7;
    a.matrix[3][3] = -9;

    EXPECT_EQ(a.cofactor(0, 0), 690);
    EXPECT_EQ(a.cofactor(0, 1), 447);
    EXPECT_EQ(a.cofactor(0, 2), 210);
    EXPECT_EQ(a.cofactor(0, 3), 51);
    EXPECT_EQ(a.determinant(), -4071);
}

TEST(MatrixUnitTests, testing_invertible_matrix) {
    Matrix a(4, 4);
    a.matrix[0][0] = 6;
    a.matrix[0][1] = 4;
    a.matrix[0][2] = 4;
    a.matrix[0][3] = 4;

    a.matrix[1][0] = 5;
    a.matrix[1][1] = 5;
    a.matrix[1][2] = 7;
    a.matrix[1][3] = 6;

    a.matrix[2][0] = 4;
    a.matrix[2][1] = -9;
    a.matrix[2][2] = 3;
    a.matrix[2][3] = -7;

    a.matrix[3][0] = 9;
    a.matrix[3][1] = 1;
    a.matrix[3][2] = 7;
    a.matrix[3][3] = -6;

    EXPECT_TRUE(a.invertible());
}

TEST(MatrixUnitTests, testing_non_invertible_matrix) {
    Matrix a(4, 4);
    a.matrix[0][0] = -4;
    a.matrix[0][1] = 2;
    a.matrix[0][2] = -2;
    a.matrix[0][3] = -3;

    a.matrix[1][0] = 9;
    a.matrix[1][1] = 6;
    a.matrix[1][2] = 2;
    a.matrix[1][3] = 6;

    a.matrix[2][0] = 0;
    a.matrix[2][1] = -5;
    a.matrix[2][2] = 1;
    a.matrix[2][3] = -5;

    a.matrix[3][0] = 0;
    a.matrix[3][1] = 0;
    a.matrix[3][2] = 0;
    a.matrix[3][3] = 0;

    EXPECT_FALSE(a.invertible());
}

TEST(MatrixUnitTests, inverse_4_x_4_matrix) {
    Matrix a(4, 4);
    a.matrix[0][0] = -5;
    a.matrix[0][1] = 2;
    a.matrix[0][2] = 6;
    a.matrix[0][3] = -8;

    a.matrix[1][0] = 1;
    a.matrix[1][1] = -5;
    a.matrix[1][2] = 1;
    a.matrix[1][3] = 8;

    a.matrix[2][0] = 7;
    a.matrix[2][1] = 7;
    a.matrix[2][2] = -6;
    a.matrix[2][3] = -7;

    a.matrix[3][0] = 1;
    a.matrix[3][1] = -3;
    a.matrix[3][2] = 7;
    a.matrix[3][3] = 4;

    Matrix result(4, 4);
    result.matrix[0][0] = 0.21805;
    result.matrix[0][1] = 0.45113;
    result.matrix[0][2] = 0.24060;
    result.matrix[0][3] = -0.04511;

    result.matrix[1][0] = -0.80827;
    result.matrix[1][1] = -1.45677;
    result.matrix[1][2] = -0.44361;
    result.matrix[1][3] = 0.52068;

    result.matrix[2][0] = -0.07895;
    result.matrix[2][1] = -0.22368;
    result.matrix[2][2] = -0.05263;
    result.matrix[2][3] = 0.19737;

    result.matrix[3][0] = -0.52256;
    result.matrix[3][1] = -0.81391;
    result.matrix[3][2] = -0.30075;
    result.matrix[3][3] = 0.30639;

    EXPECT_EQ(a.determinant(), 532);
    EXPECT_EQ(a.cofactor(2, 3), -160);
    EXPECT_EQ(result.matrix[3][2], -0.30075);
    EXPECT_EQ(a.cofactor(3, 2), 105);
    EXPECT_EQ(result.matrix[2][3], 0.19737);
    EXPECT_EQ(a.inverse(), result);
}

TEST(MatrixUnitTests, inverse_4_x_4_matrix_2) {
    Matrix a(4, 4);
    a.matrix[0][0] = 8;
    a.matrix[0][1] = -5;
    a.matrix[0][2] = 9;
    a.matrix[0][3] = 2;

    a.matrix[1][0] = 7;
    a.matrix[1][1] = 5;
    a.matrix[1][2] = 6;
    a.matrix[1][3] = 1;

    a.matrix[2][0] = -6;
    a.matrix[2][1] = 0;
    a.matrix[2][2] = 9;
    a.matrix[2][3] = 6;

    a.matrix[3][0] = -3;
    a.matrix[3][1] = 0;
    a.matrix[3][2] = -9;
    a.matrix[3][3] = -4;

    Matrix result(4, 4);
    result.matrix[0][0] = -0.15385;
    result.matrix[0][1] = -0.15385;
    result.matrix[0][2] = -0.28205;
    result.matrix[0][3] = -0.53846;

    result.matrix[1][0] = -0.07692;
    result.matrix[1][1] = 0.12308;
    result.matrix[1][2] = 0.02564;
    result.matrix[1][3] = 0.03077;

    result.matrix[2][0] = 0.35897;
    result.matrix[2][1] = 0.35897;
    result.matrix[2][2] = 0.43590;
    result.matrix[2][3] = 0.92308;

    result.matrix[3][0] = -0.69231;
    result.matrix[3][1] = -0.69231;
    result.matrix[3][2] = -0.76923;
    result.matrix[3][3] = -1.92308;

    EXPECT_EQ(a.inverse(), result);
}

TEST(MatrixUnitTests, inverse_4_x_4_matrix_3) {
    Matrix a(4, 4);
    a.matrix[0][0] = 9;
    a.matrix[0][1] = 3;
    a.matrix[0][2] = 0;
    a.matrix[0][3] = 9;

    a.matrix[1][0] = -5;
    a.matrix[1][1] = -2;
    a.matrix[1][2] = -6;
    a.matrix[1][3] = -3;

    a.matrix[2][0] = -4;
    a.matrix[2][1] = 9;
    a.matrix[2][2] = 6;
    a.matrix[2][3] = 4;

    a.matrix[3][0] = -7;
    a.matrix[3][1] = 6;
    a.matrix[3][2] = 6;
    a.matrix[3][3] = 2;

    Matrix result(4, 4);
    result.matrix[0][0] = -0.04074;
    result.matrix[0][1] = -0.07778;
    result.matrix[0][2] = 0.14444;
    result.matrix[0][3] = -0.22222;

    result.matrix[1][0] = -0.07778;
    result.matrix[1][1] = 0.03333;
    result.matrix[1][2] = 0.36667;
    result.matrix[1][3] = -0.33333;

    result.matrix[2][0] = -0.02901;
    result.matrix[2][1] = -0.14630;
    result.matrix[2][2] = -0.10926;
    result.matrix[2][3] = 0.12963;

    result.matrix[3][0] = 0.17778;
    result.matrix[3][1] = 0.06667;
    result.matrix[3][2] = -0.26667;
    result.matrix[3][3] = 0.33333;

    EXPECT_EQ(a.inverse(), result);
}

TEST(MatrixUnitTests, multiply_product_by_inverse) {
    Matrix a(4, 4);
    a.matrix[0][0] = 3;
    a.matrix[0][1] = -9;
    a.matrix[0][2] = 7;
    a.matrix[0][3] = 3;

    a.matrix[1][0] = 3;
    a.matrix[1][1] = -8;
    a.matrix[1][2] = 2;
    a.matrix[1][3] = -9;

    a.matrix[2][0] = -4;
    a.matrix[2][1] = 4;
    a.matrix[2][2] = 4;
    a.matrix[2][3] = 1;

    a.matrix[3][0] = -6;
    a.matrix[3][1] = 5;
    a.matrix[3][2] = -1;
    a.matrix[3][3] = 1;

    Matrix b(4, 4);
    b.matrix[0][0] = 8;
    b.matrix[0][1] = 2;
    b.matrix[0][2] = 2;
    b.matrix[0][3] = 2;

    b.matrix[1][0] = 3;
    b.matrix[1][1] = -1;
    b.matrix[1][2] = 7;
    b.matrix[1][3] = 0;

    b.matrix[2][0] = 7;
    b.matrix[2][1] = 0;
    b.matrix[2][2] = 5;
    b.matrix[2][3] = 4;

    b.matrix[3][0] = 6;
    b.matrix[3][1] = -2;
    b.matrix[3][2] = 0;
    b.matrix[3][3] = 5;

    EXPECT_EQ((a * b) * b.inverse(), a);
}
