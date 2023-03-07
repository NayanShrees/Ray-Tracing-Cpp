#include "data_structures/tuples.h"

#include <math.h>

#include <cstdlib>

Tuple::Tuple() : x_(0), y_(0), z_(0), w_(0) {}

Tuple::Tuple(double x, double y, double z, double w)
    : x_(x), y_(y), z_(z), w_(w) {}

double Tuple::get_x() const { return x_; }

void Tuple::set_x(double x) { this->x_ = x; }

double Tuple::get_y() const { return y_; }

void Tuple::set_y(double y) { this->y_ = y; }

double Tuple::get_z() const { return z_; }

void Tuple::set_z(double z) { this->z_ = z; }

double Tuple::get_w() const { return w_; }

void Tuple::set_w(double w) { this->w_ = w; }

bool Tuple::is_point() { return w_ == 1; }

bool Tuple::is_vector() { return w_ == 0; }

double Tuple::magnitude() {
    return sqrt(pow(this->x_, 2) + pow(this->y_, 2) + pow(this->z_, 2) +
                pow(this->w_, 2));
}

Tuple Tuple::normalize() {
    double tuple_magnitude = this->magnitude();
    return Tuple(this->x_ / tuple_magnitude, this->y_ / tuple_magnitude,
                 this->z_ / tuple_magnitude, this->w_ / tuple_magnitude);
}

double Tuple::dot(const Tuple& rhs) {
    return (this->x_ * rhs.x_) + (this->y_ * rhs.y_) + (this->z_ * rhs.z_) +
           (this->w_ * rhs.w_);
}

Tuple Tuple::operator+(const Tuple& rhs) const {
    double w = this->w_ + rhs.w_;

    if (w > 1) {
        w = 1;
    }

    Tuple tuple;
    tuple.x_ = this->x_ + rhs.x_;
    tuple.y_ = this->y_ + rhs.y_;
    tuple.z_ = this->z_ + rhs.z_;
    tuple.w_ = w;
    return tuple;
}

Tuple Tuple::operator-(const Tuple& rhs) const {
    double w = this->w_ - rhs.w_;

    if (w < 0) {
        w = 0;
    }

    Tuple tuple;
    tuple.x_ = this->x_ - rhs.x_;
    tuple.y_ = this->y_ - rhs.y_;
    tuple.z_ = this->z_ - rhs.z_;
    tuple.w_ = w;
    return tuple;
}

Tuple Tuple::operator!() const {
    return Tuple(-this->x_, -this->y_, -this->z_, -this->w_);
}

Tuple Tuple::operator*(const double& rhs) const {
    Tuple tuple;
    tuple.x_ = this->x_ * rhs;
    tuple.y_ = this->y_ * rhs;
    tuple.z_ = this->z_ * rhs;
    tuple.w_ = this->w_ * rhs;
    return tuple;
}

Tuple Tuple::operator/(const double& rhs) const {
    Tuple tuple;
    tuple.x_ = this->x_ / rhs;
    tuple.y_ = this->y_ / rhs;
    tuple.z_ = this->z_ / rhs;
    tuple.w_ = this->w_ / rhs;
    return tuple;
}

bool Tuple::operator==(const Tuple& rhs) const {
    return abs(this->x_ - rhs.x_) < Tuple::EPSILON &&
           abs(this->y_ - rhs.y_) < Tuple::EPSILON &&
           abs(this->z_ - rhs.z_) < Tuple::EPSILON &&
           abs(this->w_ - rhs.w_) < Tuple::EPSILON;
}

std::ostream& operator<<(std::ostream& os, const Tuple& tuple) {
    os << "x: " << tuple.x_ << ", y: " << tuple.y_ << ", z: " << tuple.z_
       << ", w: " << tuple.w_;
    return os;
}

Point::Point() : Tuple(0, 0, 0, 1) {}

Point::Point(double x_, double y_, double z_) : Tuple(x_, y_, z_, 1) {}

Vector::Vector() : Tuple(0, 0, 0, 0) {}

Vector::Vector(double x_, double y_, double z_) : Tuple(x_, y_, z_, 0) {}

Vector Vector::cross(const Vector& rhs) {
    return Vector(this->y_ * rhs.z_ - this->z_ * rhs.y_,
                  this->z_ * rhs.x_ - this->x_ * rhs.z_,
                  this->x_ * rhs.y_ - this->y_ * rhs.x_);
}
