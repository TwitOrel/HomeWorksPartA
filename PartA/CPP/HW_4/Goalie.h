//
// Created by Orel on 29/05/2023.
//

#ifndef EX4_GOALIE_H
#define EX4_GOALIE_H

#include "Player.h"

using namespace std;

class Goalie: public Player{
private:
    double alfa   = 0.01;
    double  betta = -0.1;
    double gamma  = -0.25;

public:
    Goalie() = default;
    Goalie(int id, const Vector& location, const Vector& speed);
 //   Goalie(const Goalie& other);
  //  ~Goalie() = default;
 //   Goalie& operator=(const Goalie& other) = default;
    Player* copy() const override;


    virtual void SetSpeedNLocation(const Vector& globalBest, const Vector& WinCell);
    //to get the others methods in the base class
    using Player :: SetSpeedNLocation;

    virtual void print() const;

};

#endif //EX4_GOALIE_H
