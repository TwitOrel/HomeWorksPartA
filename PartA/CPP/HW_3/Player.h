//
// Created by Orel on 09/05/2023.
//
#include "Vector.h"

#ifndef EX3FIX_PLAYER_H
#define EX3FIX_PLAYER_H

//  in this task we already know the limits for location so started them before instead get in the constructor
class Player{
private:
    int id = 0;
    Vector location;
    Vector speed;
    Vector personalBest;
    const static int MAX_X = 61;
    const static int MAX_Y = 30;
    const static int MIN_X = 0;
    const static int MIN_Y = 0;

public:
    // Constructor
    Player() = default;
    Player(int id,const Vector& location,const Vector& speed);

    // Destructor
    ~Player() = default;

    // Assignment operator
    Player& operator=(const Player& other);

    // Get the player's personal best location
    const Vector& GetPersonalBest();

    // Get the player's current location
    const Vector& GetLocation()const;

    // used to make the players in the limits (Max\Min X/Y)
    void limits();

    // set the new speed, new Location and new Personal Best
    void SetSpeedNLocation(const Vector& globalBest, const Vector& WinCell);

};

//  return string that present the reference player
ostream& operator<<(ostream&, const Player& player);

#endif //EX3FIX_PLAYER_H
