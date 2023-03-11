#include "canvas.h"

#include <gtest/gtest.h>

TEST(CanvasUnitTests, creating_canvas) {
    Color color(0, 0, 0);
    Canvas canvas(10, 20);
    for (auto height : canvas.pixels) {
        for (auto width : height) {
            EXPECT_EQ(width, color);
        }
    }
}

TEST(CanvasUnitTests, writing_pixel_canvas) {
    Color color(1, 0, 0);
    Canvas canvas(10, 20);
    canvas.pixels[3][2] = color;
    EXPECT_EQ(canvas.pixels[3][2], color);
}

TEST(CanvasUnitTests, construct_PPM_header) {
    Canvas canvas(5, 3);
    std::string header = canvas.construct_header();
    std::string result("P3\n5 3\n255");
    EXPECT_EQ(header, result);
}

TEST(CanvasUnitTests, construct_PPM_data) {
    Canvas canvas(5, 3);
    Color c1(1.5, 0, 0);
    Color c2(0, 0.5, 0);
    Color c3(-0.5, 0, 1);
    canvas.pixels[0][0] = c1;
    canvas.pixels[1][2] = c2;
    canvas.pixels[2][4] = c3;
    std::string data = canvas.construct_data();
    data.pop_back();
    std::string result(
        "255 0 0 0 0 0 0 0 0 0 0 0 0 0 0\n0 0 0 0 0 0 0 128 0 0 0 0 0 0 0\n0 0 "
        "0 0 0 0 0 0 0 0 0 0 0 0 255");
    EXPECT_EQ(data, result);
}

TEST(CanvasUnitTests, splitting_lines_PPM) {
    Color color(1, 0.8, 0.6);
    Canvas canvas(10, 2, color);
    std::string data = canvas.construct_data();
    data.pop_back();
    std::string result(
        "255 204 153 255 204 153 255 204 153 255 204 153 255 204 153 255 "
        "204\n153 255 204 153 255 204 153 255 204 153 255 204 153\n255 204 153 "
        "255 204 153 255 204 153 255 204 153 255 204 153 255 204\n153 255 204 "
        "153 255 204 153 255 204 153 255 204 153");
    EXPECT_EQ(data, result);
}

TEST(CanvasUnitTests, PPM_newline_terminated) {
    Canvas canvas(5, 3);
    std::string data = canvas.construct_data();
    EXPECT_EQ(std::string{data.back()}, std::string("\n"));
}