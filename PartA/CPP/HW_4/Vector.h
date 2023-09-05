//
// Created by Orel on 09/05/2023.
//

#ifndef EX3FIX_VECTOR_H
#define EX3FIX_VECTOR_H

#include <string>


class Vector{

private:
    double x;
    double y;

public:
    //Constructors
    Vector();
    Vector(double, double );
    Vector(const Vector& vector);

    // Destructor
    ~Vector();

    //  return Distance between 2 points
    double Distance(const Vector& other) const ;

    double GetX() const;
    double GetY() const;

    void SetX(double );
    void SetY(double );

    // Assignment
    Vector& operator=(const Vector& vector);

    Vector operator*(double x)const;
    Vector operator+(const Vector& vector)const;
    Vector& operator+=(const Vector& vector);
    Vector operator-(const Vector& vector)const;

};

//  used to allow double multiplication Vector
Vector operator*(double x,const Vector& vector);

//  return string that Presents the vector
ostream& operator<<(ostream&, const Vector& vector);

#endif //EX3FIX_VECTOR_H