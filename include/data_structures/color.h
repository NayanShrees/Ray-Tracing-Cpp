#ifndef COLOR_H_
#define COLOR_H_

#include <ostream>

class Color {
   private:
    double red_;
    double green_;
    double blue_;

   public:
    Color();
    Color(double red, double green, double blue);

    double get_red() const;
    void set_red(double red);
    double get_green() const;
    void set_green(double green);
    double get_blue() const;
    void set_blue(double blue);

    Color operator+(const Color& rhs) const;
    Color operator-(const Color& rhs) const;
    Color operator*(const double& rhs) const;
    Color operator*(const Color& rhs) const;

    bool operator==(const Color& rhs) const;

    Color& operator=(const Color& rhs);

    friend std::ostream& operator<<(std::ostream& os, const Color& color);
};

#endif  // COLOR_H_