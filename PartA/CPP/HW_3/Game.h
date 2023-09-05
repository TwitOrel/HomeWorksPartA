//
// Created by Orel on 10/05/2023.
//

#ifndef EX3FIX_BOARD_H
#define EX3FIX_BOARD_H
#include "Cell.h"
#include "Team.h"

class Game{
private:
    Cell** cells;
    Team crew;
    int time;
    const static int MAX_X = 61;
    const static int MAX_Y = 30;
    const static int MIN_X = 0;
    const static int MIN_Y = 0;

public:
    // Constructors
    Game(const Team& team,int time);
    Game(const Game& other);

    // Destructor
    ~Game();

    // Assignment operator
    Game& operator=(const Game& other);

//  static function used to open and use the file
    const static Game readFiles(const string& conf,const string& init);

//  in this function while not have winner the time running and the player try to win
    void play();

};

#endif //EX3FIX_BOARD_H
