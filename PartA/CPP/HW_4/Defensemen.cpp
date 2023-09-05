//
// Created by Orel on 29/05/2023.
//


#include "iostream"
#include "Defensemen.h"


Defensemen ::Defensemen(int id, const Vector &location, const Vector &speed): Player(id,location,speed) {
  //  cout << "ctor Defensemen " << endl;

}

//Defensemen::Defensemen(const Defensemen& other): Player(other.GetId(),other.GetLocation(),other.GetSpeed()) {
//    cout << "&ctor Defensemen " << endl;
//}

Player* Defensemen::copy() const {
    return new Defensemen(*this);
}

void Defensemen::SetSpeedNLocation(const Vector &globalBest, const Vector &WinCell) {
//    cout << "override" << endl;
    Player::SetSpeedNLocation(globalBest,WinCell,alfa,betta,gamma);
}

void Defensemen::print() const{
    cout << "D " << GetLocation();
}