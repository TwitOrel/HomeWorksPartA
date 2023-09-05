//
// Created by Orel on 29/05/2023.
//

#ifndef EX4_FORWARDS_H
#define EX4_FORWARDS_H

#include "Player.h"

class Forwards: public Player{
private:
    // Coefficients used in calculations
    double alfa   = 0.25;
    double  betta = 1;
    double gamma  = 1;

public:
    // Constructors
    Forwards() = default;
    Forwards(int id, const Vector& location, const Vector& speed);
    ////    Forwards(const Forwards& other);

    // Override the copy function to create a copy of a Forwards player
    Player* copy() const override;

    ////    ~Forwards() = default;
    ////   Forwards& operator=(const Forwards& other) = default;

    // Calculate and set speed and location based on globalBest and WinCell
    void SetSpeedNLocation(const Vector& globalBest, const Vector& WinCell) override;

    //to get the others methods in the base class
    using Player :: SetSpeedNLocation;

    virtual void print() const;

};

#endif //EX4_FORWARDS_H
