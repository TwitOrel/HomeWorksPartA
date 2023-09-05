//
// Created by Orel on 09/05/2023.
//

#include "Player.h"
using namespace std;


Player::Player(int id,const Vector& location, const Vector& speed):
        id(id),location(location),
        speed(speed),
        personalBest(location){
}

Player& Player::operator=(const Player& other){
    this->location = other.location;
    this->speed = other.speed;
    this->personalBest = other.personalBest;
    this->id = other.id;
    return *this;
}

const Vector& Player::GetPersonalBest(){
    return this->personalBest;
}


const Vector& Player::GetLocation()const {
    return this->location;
}

void Player::limits() {
    if (this->location.GetX() > MAX_X){
        this->location.SetX(MAX_X);
    }
    if (this->location.GetX() < MIN_X){
        this->location.SetX(MIN_X);
    }
    if (this->location.GetY() > MAX_Y){
        this->location.SetY(MAX_Y);
    }
    if (this->location.GetY() < MIN_Y){
        this->location.SetY(MIN_Y);
    }
}

void Player::SetSpeedNLocation(const Vector& globalBest, const Vector& WinCell) {
    srand(time(nullptr));
    Vector oldLocation = location;
    this->location += this->speed;
    limits();

    double r1 = (double)(rand()) / RAND_MAX;
    double r2 = (double)(rand()) / RAND_MAX;
    this->speed = 0.25*speed + r1 * (personalBest - oldLocation) + r2 * (globalBest - oldLocation) ;

    if (this->location.Distance(WinCell) < personalBest.Distance(WinCell)){
        this->personalBest = this->location;
    }
}


ostream& operator<<(ostream& ostream, const Player& player){

    return ostream << player.GetLocation() ;
}
//
//string Player::toString() {
//    return this->location.toString();
//}


//
//Vector Player::GetPersonalBest() {
//    return this->personalBest;
//}

//Player::Player(const Player& player) = default;


//Player& Player::operator=(const Player &player) {
//    if (&player == this)return *this;
//    this->id = player.id;
//    this->location = player.location;
//    this->personalBest = player.personalBest;
//    this->speed = player.speed;
//    return *this;
//}
