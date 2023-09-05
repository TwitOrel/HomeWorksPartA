//
// Created by Orel on 09/05/2023.
//
#include "Player.h"

#ifndef EX3FIX_TEAM_H
#define EX3FIX_TEAM_H

class Team{
private:
    int numPlayers;
    bool win;
    Vector globalBest;
    Vector WinCell;
    Player* players;

public:
//  used default constructor for  the constructor in Game Class
    Team();
    Team(const Team& other);
    Team(int numPls,const Vector& winCell);

    // Destructor
    ~Team();

    // Assignment operator
    Team& operator=(const Team& other);

    // Update the global best vector for the team
    void updateGlobalBest();

    // Update the member team based on an index
    void updateMemberTeam(int index);

    // Set the global best vector for the team
    void setGlobalBest(const Vector& other);

    // Get the number of players in the team
    int getNumPlayers() const;

    // Check if the team has won
    bool isWin()const;

    // Print the team
    void printTeam();

    // return Player reference from the arr
    Player& operator[](int index);

    // static function used to open and use the file
    static Team readInit(const string& file, const Vector& WC);
};


#endif //EX3FIX_TEAM_H
