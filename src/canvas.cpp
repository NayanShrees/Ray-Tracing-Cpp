#include "canvas.h"

#include <math.h>

#include <algorithm>
#include <fstream>

Canvas::Canvas() : width(0), height(0) {
    pixels = std::vector<std::vector<Color>>(
        this->height, std::vector<Color>(this->width, Color(0, 0, 0)));
}

Canvas::Canvas(int width, int height) : width(width), height(height) {
    pixels = std::vector<std::vector<Color>>(
        this->height, std::vector<Color>(this->width, Color(0, 0, 0)));
}

Canvas::Canvas(int width, int height, Color color)
    : width(width), height(height) {
    pixels = std::vector<std::vector<Color>>(
        this->height, std::vector<Color>(this->width, color));
}

std::string Canvas::construct_header() {
    std::string header;
    header.append("P3\n");
    header.append(std::to_string(this->width) + " " +
                  std::to_string(this->height) + "\n");
    header.append(std::to_string(this->MAX_COLOR_VAL));
    return header;
}

std::string Canvas::construct_data() {
    std::string data;
    for (auto height : this->pixels) {
        std::string line;
        for (auto width : height) {
            line.append(std::to_string(std::clamp(
                            (int)round(width.get_red() * this->MAX_COLOR_VAL),
                            0, 255)) +
                        " ");
            line.append(std::to_string(std::clamp(
                            (int)round(width.get_green() * this->MAX_COLOR_VAL),
                            0, 255)) +
                        " ");
            line.append(std::to_string(std::clamp(
                            (int)round(width.get_blue() * this->MAX_COLOR_VAL),
                            0, 255)) +
                        " ");
        }
        // Wrap line
        size_t n = line.rfind(" ", this->PPM_WRAP_LENGTH);
        while (n != std::string::npos) {
            line.at(n) = '\n';
            n = n + this->PPM_WRAP_LENGTH > line.length()
                    ? std::string::npos
                    : line.rfind(" ", this->PPM_WRAP_LENGTH);
        }
        line.pop_back();
        data.append(line + "\n");
    }
    return data;
}

std::string Canvas::canvas_to_ppm() {
    std::string output;
    output.append(construct_header() + "\n");
    output.append(construct_data());
    return output;
}

void Canvas::save_ppm() {
    std::string output = canvas_to_ppm();
#ifdef PPM_FILE
    std::ofstream file(PPM_FILE, std::ofstream::out);
    file << output;
    file.close();
#else
#error PPM_FILE not defined
#endif
}