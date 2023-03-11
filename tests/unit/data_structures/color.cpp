#include "data_structures/color.h"

#include <gtest/gtest.h>

TEST(ColorUnitTests, colors_are_tuples) {
    Color a(-0.5, 0.4, 1.7);
    EXPECT_DOUBLE_EQ(-0.5, a.get_red());
    EXPECT_DOUBLE_EQ(0.4, a.get_green());
    EXPECT_DOUBLE_EQ(1.7, a.get_blue());
}

TEST(ColorUnitTests, adding_colors) {
    Color a(0.9, 0.6, 0.75);
    Color b(0.7, 0.1, 0.25);
    Color result(1.6, 0.7, 1);
    EXPECT_EQ(a + b, result);
}

TEST(ColorUnitTests, subtracting_colors) {
    Color a(0.9, 0.6, 0.75);
    Color b(0.7, 0.1, 0.25);
    Color result(0.2, 0.5, 0.5);
    EXPECT_EQ(a - b, result);
}

TEST(ColorUnitTests, multiply_color_by_scalar) {
    Color a(0.2, 0.3, 0.4);
    Color result(0.4, 0.6, 0.8);
    EXPECT_EQ(a * 2, result);
}

TEST(ColorUnitTests, multiply_colors) {
    Color a(1, 0.2, 0.4);
    Color b(0.9, 1, 0.1);
    Color result(0.9, 0.2, 0.04);
    EXPECT_EQ(a * b, result);
}