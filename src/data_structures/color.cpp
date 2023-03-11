#include "data_structures/color.h"

#include <math.h>

#include "data_structures/tuples.h"

Color::Color() : red_(0), green_(0), blue_(0) {}

Color::Color(double red, double green, double blue)
    : red_(red), green_(green), blue_(blue) {}

double Color::get_red() const { return red_; }

void Color::set_red(double red) { this->red_ = red; };

double Color::get_green() const { return green_; }

void Color::set_green(double green) { this->green_ = green; }

double Color::get_blue() const { return blue_; }

void Color::set_blue(double blue) { this->blue_ = blue; }

Color Color::operator+(const Color& rhs) const {
    return Color(this->red_ + rhs.red_, this->green_ + rhs.green_,
                 this->blue_ + rhs.blue_);
}

Color Color::operator-(const Color& rhs) const {
    return Color(this->red_ - rhs.red_, this->green_ - rhs.green_,
                 this->blue_ - rhs.blue_);
}

Color Color::operator*(const double& rhs) const {
    return Color(this->red_ * rhs, this->green_ * rhs, this->blue_ * rhs);
}

Color Color::operator*(const Color& rhs) const {
    return Color(this->red_ * rhs.red_, this->green_ * rhs.green_,
                 this->blue_ * rhs.blue_);
}

bool Color::operator==(const Color& rhs) const {
    return abs(this->red_ - rhs.red_) < Tuple::EPSILON &&
           abs(this->green_ - rhs.green_) < Tuple::EPSILON &&
           abs(this->blue_ - rhs.blue_) < Tuple::EPSILON;
}

Color& Color::operator=(const Color& rhs) {
    red_ = rhs.red_;
    green_ = rhs.green_;
    blue_ = rhs.blue_;
    return *this;
}

std::ostream& operator<<(std::ostream& os, const Color& color) {
    os << "Red: " << color.red_ << ", Green: " << color.green_
       << ", Blue: " << color.blue_;
    return os;
}