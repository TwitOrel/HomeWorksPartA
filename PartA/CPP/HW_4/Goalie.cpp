//
// Created by Orel on 29/05/2023.
//

#include <iostream>
#include "Goalie.h"

Goalie ::Goalie(int id, const Vector &location, const Vector &speed): Player(id,location,speed) {
   // cout << "ctor goalie " << endl;
}

//Goalie::Goalie(const Goalie &other): Player(other.GetId(),other.GetLocation(),other.GetSpeed()) {
// //   cout << "&ctor goalie " << endl;
//}

Player* Goalie::copy() const {
    return new Goalie(*this);
}

void Goalie::SetSpeedNLocation(const Vector &globalBest, const Vector &WinCell) {
//    cout << "override" << endl;
    Player::SetSpeedNLocation(globalBest,WinCell,alfa,betta,gamma);
}

void Goalie::print() const{
    cout << "G " << GetLocation();
}
