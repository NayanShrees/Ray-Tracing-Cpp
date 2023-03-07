#include "data_structures/tuples.h"

#include <gtest/gtest.h>
#include <math.h>

TEST(TupleUnitTests, tuple_is_a_point) {
    Tuple a(4.3, -4.2, 3.1, 1.0);
    EXPECT_DOUBLE_EQ(a.get_x(), 4.3);
    EXPECT_DOUBLE_EQ(a.get_y(), -4.2);
    EXPECT_DOUBLE_EQ(a.get_z(), 3.1);
    EXPECT_DOUBLE_EQ(a.get_w(), 1);
    EXPECT_TRUE(a.is_point());
    EXPECT_TRUE(!a.is_vector());
}

TEST(TupleUnitTests, tuple_is_a_vector) {
    Tuple a(4.3, -4.2, 3.1, 0.0);
    EXPECT_DOUBLE_EQ(a.get_x(), 4.3);
    EXPECT_DOUBLE_EQ(a.get_y(), -4.2);
    EXPECT_DOUBLE_EQ(a.get_z(), 3.1);
    EXPECT_DOUBLE_EQ(a.get_w(), 0);
    EXPECT_TRUE(!a.is_point());
    EXPECT_TRUE(a.is_vector());
}

TEST(TupleUnitTests, point_creates_tuple) {
    Point p(4, -4, 3);
    EXPECT_DOUBLE_EQ(4, p.get_x());
    EXPECT_DOUBLE_EQ(-4, p.get_y());
    EXPECT_DOUBLE_EQ(3, p.get_z());
    EXPECT_DOUBLE_EQ(1, p.get_w());
}

TEST(TupleUnitTests, vector_creates_tuple) {
    Vector v(4, -4, 3);
    EXPECT_DOUBLE_EQ(4, v.get_x());
    EXPECT_DOUBLE_EQ(-4, v.get_y());
    EXPECT_DOUBLE_EQ(3, v.get_z());
    EXPECT_DOUBLE_EQ(0, v.get_w());
}

TEST(TupleUnitTests, adding_two_tuple) {
    Tuple a(3, -2, 5, 1);
    Tuple b(-2, 3, 1, 0);
    Tuple result(1, 1, 6, 1);
    EXPECT_EQ(a + b, result);
}

TEST(TupleUnitTests, subtracting_two_points) {
    Point a(3, 2, 1);
    Point b(5, 6, 7);
    Vector result(-2, -4, -6);
    EXPECT_EQ(a - b, result);
}

TEST(TupleUnitTests, subtracting_vector_from_point) {
    Point a(3, 2, 1);
    Vector b(5, 6, 7);
    Point result(-2, -4, -6);
    EXPECT_EQ(a - b, result);
}

TEST(TupleUnitTests, subtracting_two_vectors) {
    Vector a(3, 2, 1);
    Vector b(5, 6, 7);
    Vector result(-2, -4, -6);
    EXPECT_EQ(a - b, result);
}

TEST(TupleUnitTests, subtracting_vector_from_zero) {
    // Testing negation
    Vector a(0, 0, 0);
    Vector b(1, -2, 3);
    Vector result(-1, 2, -3);
    EXPECT_EQ(a - b, result);
}

TEST(TupleUnitTests, negating_tuple) {
    Tuple a(1, -2, 3, -4);
    Tuple result(-1, 2, -3, 4);
    EXPECT_EQ(!a, result);
}

TEST(TupleUnitTests, multiply_tuple_by_scalar) {
    Tuple a(1, -2, 3, -4);
    Tuple result(3.5, -7, 10.5, -14);
    EXPECT_EQ(a * 3.5, result);
}

TEST(TupleUnitTests, multiply_tuple_by_fraction) {
    Tuple a(1, -2, 3, -4);
    Tuple result(0.5, -1, 1.5, -2);
    EXPECT_EQ(a * 0.5, result);
}

TEST(TupleUnitTests, divide_tuple_by_scalar) {
    Tuple a(1, -2, 3, -4);
    Tuple result(0.5, -1, 1.5, -2);
    EXPECT_EQ(a / 2, result);
}

TEST(TupleUnitTests, magnitude_vector_1_0_0) {
    Vector a(1, 0, 0);
    EXPECT_EQ(a.magnitude(), 1);
}

TEST(TupleUnitTests, magnitude_vector_0_1_0) {
    Vector a(0, 1, 0);
    EXPECT_EQ(a.magnitude(), 1);
}

TEST(TupleUnitTests, magnitude_vector_0_0_1) {
    Vector a(0, 0, 1);
    EXPECT_EQ(a.magnitude(), 1);
}

TEST(TupleUnitTests, magnitude_vector_1_2_3) {
    Vector a(1, 2, 3);
    EXPECT_EQ(a.magnitude(), sqrt(14));
}

TEST(TupleUnitTests, magnitude_vector_neg1_neg2_neg3) {
    Vector a(-1, -2, -3);
    EXPECT_EQ(a.magnitude(), sqrt(14));
}

TEST(TupleUnitTests, norm_vec_4_0_0) {
    Vector a(4, 0, 0);
    EXPECT_EQ(a.normalize(), Vector(1, 0, 0));
}

TEST(TupleUnitTests, norm_vec_1_2_3) {
    Vector a(1, 2, 3);
    EXPECT_EQ(a.normalize(), Vector(0.26726, 0.53452, 0.80178));
}

TEST(TupleUnitTests, dot_product_two_tuples) {
    Vector a(1, 2, 3);
    Vector b(2, 3, 4);
    EXPECT_EQ(a.dot(b), 20);
}

TEST(TupleUnitTests, cross_product_two_tuples) {
    Vector a(1, 2, 3);
    Vector b(2, 3, 4);
    EXPECT_EQ(a.cross(b), Vector(-1, 2, -1));
    EXPECT_EQ(b.cross(a), Vector(1, -2, 1));
}
