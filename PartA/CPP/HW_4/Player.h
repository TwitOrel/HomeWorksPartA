//
// Created by Orel on 09/05/2023.
//
#include "Vector.h"

#ifndef EX3FIX_PLAYER_H
#define EX3FIX_PLAYER_H

#include "Vector.h"

//  in this task we already know the limits for location so started them before instead get in the constructor
class Player{
private:
    int id = 0;

    // Current location of the player as a 2D vector
    Vector location;

    // Current speed of the player as a 2D vector
    Vector speed;

    // Personal best location of the player as a 2D vector
    Vector personalBest;
    const static int MAX_X = 61;
    const static int MAX_Y = 30;
    const static int MIN_X = 0;
    const static int MIN_Y = 0;

public:
    //Constructors
    Player() = default;
    Player(int id,const Vector& location,const Vector& speed);
    ////    Player(const Player& other);

    // Destructor
    virtual ~Player() = default;

    ////    Player& operator=(const Player& other);

    // Getter method to retrieve the personal best location
    const Vector& GetPersonalBest();

    // Getter method to retrieve the current location
    const Vector& GetLocation()const;

    // Getter method to retrieve the current speed
    const Vector& GetSpeed()const;

    int GetId()const;

    //  used to make the players in the limits (Max\Min X/Y)
    void limits();

    //  set the new speed, new Location and new Personal Best
    void SetSpeedNLocation(const Vector& globalBest, const Vector& WinCell, double alfa, double betta, double gama);

    // Virtual function to set the player's new speed and location based on global best and win cell
    virtual void SetSpeedNLocation(const Vector& globalBest, const Vector& WinCell);

    bool operator>(const Player& other)const;
    bool operator==(const Player& other)const;
    bool operator<(const Player&)const;
    bool operator>=(const Player&)const;

    virtual Player* copy() const;


    virtual void print() const;

};

//  return string that present the reference player
ostream& operator<<(ostream&, const Player& player);

#endif //EX3FIX_PLAYER_H
