//
// Created by Orel on 09/05/2023.
//

#ifndef EX3FIX_CELL_H
#define EX3FIX_CELL_H

class Cell{
private:
    int PlayersOnCell;

public:
    // Constructor
    Cell();

    // Getter the number of players on the cell
    int GetPlayersOnCell() const;

    // prefix increment
    Cell& operator++();

    // postfix increment
    int operator++(int);

    // prefix decrement
    Cell& operator--();

    // postfix decrement
    int operator--(int);
};

#endif //EX3FIX_CELL_H
