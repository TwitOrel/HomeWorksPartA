//
// Created by Orel on 29/05/2023.
//
#include "iostream"
#include "Forwards.h"

Forwards ::Forwards(int id, const Vector &location, const Vector &speed): Player(id,location,speed) {
  //  cout << "ctor Forwards " << endl;

}

//Forwards::Forwards(const Forwards& other): Player(other.GetId(),other.GetLocation(),other.GetSpeed()) {
//    cout << "&ctor Forwards " << endl;
//}

Player* Forwards::copy() const {
    return new Forwards(*this);
}

void Forwards::SetSpeedNLocation(const Vector &globalBest, const Vector &WinCell) {
 //   cout << "override" << endl;
    Player::SetSpeedNLocation(globalBest,WinCell,alfa,betta,gamma);
}

void Forwards::print() const{
    cout << "F " << GetLocation();
}