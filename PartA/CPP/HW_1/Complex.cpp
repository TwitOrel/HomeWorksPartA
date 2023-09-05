#include <cmath>
#include "Complex.h"

Complex::Complex():Complex(0,0) {}
Complex::Complex(double a,double b):a(a),b(b) {}

Complex::Complex(const Complex& complex):Complex(complex.a,complex.b) {}

Complex::~Complex()= default;

Complex Complex::operator+(const Complex &complex)const {
    return {this->a + complex.a, this->b + complex.b};
}
Complex Complex::operator-(const Complex &complex) const {
    return {this->a - complex.a, this->b - complex.b};
}
Complex Complex::operator*(const Complex &complex) const {
    return {(this->a * complex.a - (this->b*complex.b)), this->a*complex.b + this->b*complex.a};
    }

Complex& Complex::operator+=(const Complex &complex) {
    this->a += complex.a;
    this->b += complex.b;
    return *this;
}
Complex& Complex::operator-=(const Complex &complex) {
    this->a -= complex.a;
    this->b -= complex.b;
    return *this;
}
Complex& Complex::operator=(const Complex &complex) {
    if (this == &complex)return *this;
    this->a = complex.a;
    this->b = complex.b;
    return *this;
}
Complex& Complex::operator*=(const Complex &complex) {
    this->a = ((this->a*complex.a) - (this->b*complex.b));
    this->b = ((this->a*complex.b) + (this->b*complex.a));
    return *this;
}

Complex& Complex::operator*=(double scalar) {
    this->a *= scalar;
    this->b *= scalar;
    return *this;
}
string Complex::toString() const {
    double real = (round(this->a * 1000) / 1000);
    double image = round(this->b * 1000) / 1000;
    ostringstream res;
    res << "(" << real << "," << image << ")";
    return res.str();


}
