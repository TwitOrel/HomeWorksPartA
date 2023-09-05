//
// Created by Orel on 09/05/2023.
//
#include "Player.h"
#include "Defensemen.h"
#include "Forwards.h"
#include "Goalie.h"
#include "LinkedList.h"

#ifndef EX3FIX_TEAM_H
#define EX3FIX_TEAM_H

class Team{
private:
    int numPlayers;
    bool win;
    Vector globalBest;
    Vector WinCell;
    LinkedList<Player> list;

public:
//  used default constructor for  the constructor in Game Class
//    Team(const Team& other);
    Team(int numPls,const Vector& winCell);
//    Team(Team&& other) noexcept;
//    ~Team();
//    Team& operator=(const Team& other);
//    Team& operator=(Team&& other) noexcept;
    void updateGlobalBest();
    void updateMemberTeam(int index);
    void setGlobalBest(const Vector& other);
    int getNumPlayers() const;
    bool isWin()const;
    void printTeam();

//  return Player reference from the arr
    Player& operator[](int index);

//  static function used to open and use the file
    static Team readInit(const string& file, const Vector& WC);

};


#endif //EX3FIX_TEAM_H
