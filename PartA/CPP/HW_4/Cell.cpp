//
// Created by Orel on 09/05/2023.
//

#include "Cell.h"

Cell::Cell():PlayersOnCell(0) {}

int Cell::GetPlayersOnCell() const {
    return this->PlayersOnCell;
}

Cell& Cell::operator++() {
    ++PlayersOnCell;
    return *this;
}

int Cell::operator++(int) {
    return PlayersOnCell++;
}

Cell& Cell::operator--() {
    --PlayersOnCell;
    return *this;
}

int Cell::operator--(int) {
    return PlayersOnCell--;
}