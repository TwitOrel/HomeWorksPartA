#ifndef EX01_COMPLEX_H
#define EX01_COMPLEX_H

#include <iostream>
#include <sstream>
#include <iomanip>


class Complex{
private:
    //fields
    double a;
    double b;
public:
    //Constructors
    Complex();
    Complex(double a, double b);
    Complex(const Complex& complex);
    ~Complex();

    //Operators
    Complex operator+(const Complex& complex)const;
    Complex operator-(const Complex &complex)const;
    Complex operator*(const Complex &complex)const;
    Complex& operator=(const Complex& complex);
    Complex& operator+=(const Complex& complex);
    Complex& operator-=(const Complex& complex);
    Complex& operator*=(const Complex& complex);
    //multi with scalar
    Complex& operator*=(double scalar);

    string toString() const;
};

#endif //EX01_COMPLEX_H
