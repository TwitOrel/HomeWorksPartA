//
// Created by Orel on 29/05/2023.
//

#ifndef EX4_DEFENSEMEN_H
#define EX4_DEFENSEMEN_H

#include "Player.h"


class Defensemen: public Player{
private:
    double alfa   = 0.05;
    double  betta = 0.1;
    double gamma  = 0;

public:
    // Constructors
    Defensemen() = default;
    Defensemen(int id, const Vector& location, const Vector& speed);
    ////    Defensemen(const Defensemen& other);

    // Override the copy method to create a copy of a Defensemen player
    Player* copy() const override;


    ////    ~Defensemen() = default;
    ////    Defensemen& operator=(const Defensemen& other) = default;

    // Override the SetSpeedNLocation method for Defensemen players
    virtual void SetSpeedNLocation(const Vector& globalBest, const Vector& WinCell);
    
    //to get the others methods in the base class
    using Player :: SetSpeedNLocation;

    virtual void print() const;

};

#endif //EX4_DEFENSEMEN_H
