#include <iostream>
#include "Player.h"

using namespace std;


Player::Player(int id,const Vector& location, const Vector& speed):
        id(id),location(location),
        speed(speed),
        personalBest(location){
  //  cout << "ctor player" << endl;
}

//Player::Player(const Player &other):id(other.id),location(other.location),speed(other.speed),personalBest(other.personalBest) {
//    cout << "&ctor player " << endl;
//}

//Player& Player::operator=(const Player& other){
//    this->location = other.location,
//    this->speed = other.speed,
//    this->personalBest = other.personalBest,
//    this->id = other.id;
//    return *this;
//}

const Vector& Player::GetPersonalBest(){
    return this->personalBest;
}


const Vector& Player::GetLocation()const {
    return this->location;
}

const Vector& Player::GetSpeed()const {
    return this->speed;
}

int Player::GetId() const {
    return id;
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

void Player::SetSpeedNLocation(const Vector& globalBest, const Vector& WinCell, double alfa, double betta, double gama) {
    srand(time(nullptr));
    Vector oldLocation = location;
    this->location += this->speed;
    limits();

    double r1 = (double) (rand()) / RAND_MAX;
    double r2 = (double) (rand()) / RAND_MAX;
    this->speed = (alfa * speed) + (betta * r1 * (personalBest - oldLocation)) + (gama * r2 * (globalBest - oldLocation));
    if (this->location.Distance(WinCell) < personalBest.Distance(WinCell)) {
        this->personalBest = this->location;
    }
}
Player* Player::copy() const {
    return new Player(*this);
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

bool Player::operator>(const Player& other) const {
    double x = this->location.GetX();
    double y = this->location.GetY();
    double otherX = other.location.GetX();
    double otherY = other.location.GetY();
    if (x > otherX){
        return true;
    }
    else if(otherX > x){
        return false;
    } else{
        if (y > otherY){
            return true;
        }
        else if (otherY >= y){
            return false;
        }
    }
    return false;
}

bool Player::operator==(const Player &other) const {
    double x = this->location.GetX();
    double y = this->location.GetY();
    double otherX = other.location.GetX();
    double otherY = other.location.GetY();


    return ( (x == otherX ) && ( y == otherY ) && (this->id == other.id) );
}

bool Player::operator<(const Player& other) const {
    double x = this->location.GetX();
    double y = this->location.GetY();
    double otherX = other.location.GetX();
    double otherY = other.location.GetY();

    if (x < otherX){
        return true;
    }
    else if (x > otherX){
        return false;
    }
    else{
        if (y < otherY){
            return true;
        }
    }
    return false;
}

bool Player::operator>=(const Player& other) const {
    double x = this->location.GetX();
    double y = this->location.GetY();
    double otherX = other.location.GetX();
    double otherY = other.location.GetY();

    if (x > otherX){
        return true;
    } else if (x < otherX){
        return false;
    } else{
        if (y > otherY){
            return true;
        } else if (y < otherY){
            return false;
        }
    }
    return true;
}

void Player::print() const {
    cout << this->GetLocation(); ;
}


ostream& operator<<(ostream& ostream, const Player& player){

    return ostream << player.GetLocation() ;
}