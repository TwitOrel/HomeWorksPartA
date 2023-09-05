//
// Created by Orel on 09/05/2023.
//

#include "Vector.h"
#include <cmath>
#include <sstream>

Vector::Vector(): x(0), y(0) {}

Vector::Vector(double x1, double x2): x(x1), y(x2) {}

Vector::Vector(const Vector &vector) {
    this->x = vector.x;
    this->y = vector.y;
}

Vector::~Vector() = default;

double Vector::Distance(const Vector& other) const {
    double a = this->x - other.x;
    double b = this->y - other.y;
    return sqrt((a*a + b*b));
}


double Vector::GetX() const {
    return this->x;
}

double Vector::GetY() const {
    return this->y;
}

void Vector::SetX(double newX) {
    this->x = newX;
}

void Vector::SetY(double newY) {
    this->y = newY;
}

Vector Vector::operator*(double w)const{
    return {x * w, y * w};
}

Vector& Vector::operator=(const Vector& vector){
    if (this == &vector)return *this;
    this->x = vector.x;
    this->y = vector.y;
    return *this;
}

Vector Vector::operator+(const Vector& vector) const {
    return {this->x + vector.x, this->y + vector.y };
}

Vector& Vector::operator+=(const Vector &vector) {
    this->x += vector.x;
    this->y += vector.y;
    return *this;
}

Vector Vector::operator-(const Vector &vector) const {
    return {this->x - vector.x, this->y - vector.y};
}

Vector operator*(double x,const Vector& vector){
    return vector*x;
}

ostream& operator<<(ostream& stream, const Vector& vector){
    double y1 = (double )round(vector.GetX() * 100) / 100;
    double y2 = (double )round(vector.GetY() * 100) / 100;
    stream << y1 << " " << y2;
    return stream;
}


