#ifndef TUPLES_H_
#define TUPLES_H_

#include <ostream>

class Tuple {
   protected:
    double x_;
    double y_;
    double z_;
    double w_;

   public:
    static constexpr double EPSILON = 0.00001;
    Tuple();
    Tuple(double x, double y, double z, double w);

    double get_x() const;
    void set_x(double x);
    double get_y() const;
    void set_y(double y);
    double get_z() const;
    void set_z(double z);
    double get_w() const;
    void set_w(double w);

    bool is_point();
    bool is_vector();

    double magnitude();
    Tuple normalize();
    double dot(const Tuple& rhs);

    Tuple operator+(const Tuple& rhs) const;
    Tuple operator-(const Tuple& rhs) const;
    Tuple operator!() const;
    Tuple operator*(const double& rhs) const;
    Tuple operator/(const double& rhs) const;

    bool operator==(const Tuple& rhs) const;

    friend std::ostream& operator<<(std::ostream& os, const Tuple& tuple);
};

class Point : public Tuple {
   public:
    Point();
    Point(double x_, double y_, double z_);
};

class Vector : public Tuple {
   public:
    Vector();
    Vector(double x_, double y_, double z_);

    Vector cross(const Vector& rhs);
};

#endif  // TUPLES_H_