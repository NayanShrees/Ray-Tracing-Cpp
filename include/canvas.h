#ifndef CANVAS_H_
#define CANVAS_H_

#include <vector>

#include "data_structures/color.h"

struct Canvas {
    int width;
    int height;
    std::vector<std::vector<Color>> pixels;
    const int MAX_COLOR_VAL = 255;
    const int PPM_WRAP_LENGTH = 70;

    Canvas();
    Canvas(int width, int height);
    Canvas(int width, int height, Color color);

    std::string construct_header();
    std::string construct_data();
    std::string canvas_to_ppm();
    void save_ppm();
};

#endif  // CANVAS_H_