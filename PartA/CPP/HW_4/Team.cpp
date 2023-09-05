//
// Created by Orel on 09/05/2023.
//
#include <fstream>
#include <iostream>
#include "Team.h"
//  countSpaces isParam two util functions that we use them in this class

int countSpaces(const string& line) {
    int count = 0;
    for (char c : line) {
        if (c == ' ') {
            count++;
        }
    }
    return count;
}

bool isParam (const string& line){
    for (char c : line){
        if (c > 57 || c < 45 || c == 47){
            return false;
        }
    }
    return true;
}

bool isP(const string& type){
    if (type == "G" || type[0] == 'D' || type[0] == 'F'){
        return true;
    } else{
        return false;
    }
}


Team Team::readInit(const string &file, const Vector& WC){
    // create file Stream and check it is not null
    ifstream initFile(file);
    if (!initFile) {
        throw  invalid_argument("Failed to open the file.") ;
    }

    // read the first line and validate it is a single number for number of players
    string line;
    getline(initFile, line);
    if (countSpaces(line) != 0) {
        throw invalid_argument("ERROR: Invalid input.");
    }
    int numPlayers = stoi(line);
    if (numPlayers > 100 || numPlayers < 2){
        throw invalid_argument("ERROR: Invalid input.");
    }

    // create instance of Team
    Team team = Team(numPlayers,WC);

    int linesCounter = 0;
    while (getline(initFile, line)) {
        if ( countSpaces(line) != 4){
            throw invalid_argument("ERROR: Invalid input.");
        }

        std::string delimiter = " "; // Delimiter

        size_t pos1 = 0;
        size_t pos2 = line.find(delimiter);
        size_t pos3 = line.find(delimiter, pos2 + 1);
        size_t pos4 = line.find(delimiter, pos3 + 1);
        size_t pos5 = line.find(delimiter,pos4 + 1);


        string f1 = line.substr(pos1, pos2 - pos1);
        string f2 = line.substr(pos2 + 1, pos3 - pos2 - 1);
        string f3 = line.substr(pos3 + 1, pos4 - pos3 - 1);
        string f4 = line.substr(pos4 + 1, pos5 - pos4 - 1);
        string f5 = line.substr(pos5 +1);

        if( ((isParam(f5) + isParam(f2) + isParam(f3) + isParam(f4) != 4)) || (isP(f1) != 1) ){
            throw invalid_argument("Invalid error in InitFile ");
        }
        // f1 is the type "D" or "G" or "F"
        double  x1 = stod(f2);
        double  y1 = stod(f3);
        double  x2 = stod(f4);
        double  y2 = stod(f5);
//        std::cout << f1 << " ";
//        std::cout << x1 << " ";
//        std::cout << y1 << " ";
//        std::cout << x2 << " ";
//        std::cout << y2 << std::endl;
        Player* tmp;
        if (f1 == "D"){
            tmp = new Defensemen(linesCounter, Vector(x1,y1), Vector(x2,y2));
        }
        else if (f1 == "G"){
            tmp = new Goalie(linesCounter, Vector(x1,y1), Vector(x2,y2));
        }
        else{
            tmp = new Forwards(linesCounter, Vector(x1,y1), Vector(x2,y2));
        }
        team.list.insert(*tmp);
        linesCounter++;
    }
    team.setGlobalBest(team.list[0].GetLocation());
    team.updateGlobalBest();
    if (linesCounter != numPlayers){
        throw invalid_argument("ERROR: Invalid input.");
    }
    initFile.close();
    return team;
}

Team::Team(int numPls,const Vector& winCell):
    numPlayers(numPls),
    win(false),
    globalBest(0,0),
    WinCell(winCell){
    this->list = LinkedList<Player>();

}
//
//Team::Team(const Team &other):
//    numPlayers(other.numPlayers),
//    win(other.win),
//    globalBest(other.globalBest),
//    list(other.list),
//    WinCell(other.WinCell){
//}
//Team::Team(Team&& other) noexcept :list(other.list)
//    , numPlayers(other.numPlayers)
//    , win(other.win)
//    , globalBest(other.globalBest)
//    , WinCell(other.WinCell) {
//}
//
//Team::~Team() {}
//
//Team &Team::operator=(const Team &other) {
//    if (this == &other)return *this;
//    this->numPlayers = other.numPlayers;
//    this->win = other.win;
//    this->globalBest = other.globalBest;
//    this->WinCell = other.WinCell;
//
//    list = other.list;
//    return *this;
//}
//
//Team& Team::operator=(Team&& other) noexcept {
//    if (this == &other) {
//        return *this;
//    }
//    this->globalBest = other.globalBest;
//    this->win = other.win;
//    this->numPlayers = other.numPlayers;
//    this->WinCell = other.WinCell;
//    this->list = other.list;
//    return *this;
//}

void Team::updateGlobalBest() {
    for (int i = 0; i < this->numPlayers; ++i) {
        double globalBestDistance = globalBest.Distance(WinCell);
        double personalBestDistance = this->list[i].GetPersonalBest().Distance(WinCell);
        if (globalBestDistance > personalBestDistance){
            globalBest = this->list[i].GetPersonalBest();
        }
    }
    if ((int)globalBest.GetX() == (int)WinCell.GetX() && (int)globalBest.GetY() == (int)WinCell.GetY()){
        this->win = true;
    }
}

bool Team::isWin()const {
    return this->win;
}

void Team::updateMemberTeam(int index){
    this->list[index].SetSpeedNLocation(globalBest, WinCell);
}

void Team::setGlobalBest(const Vector &other) {
    this->globalBest = other;
}

Player& Team::operator[](int index){
    return reinterpret_cast<Player &>(this->list[index]);
}

int Team::getNumPlayers() const{
    return this->numPlayers;
}


void Team::printTeam() {
    for (int i = this->numPlayers-1; i >= 0; i--) {
        list[i].print();
        if (i != 0){
            cout << endl;
        }
    }

}









//Vector Team::GetGlobalBest() {
//    return this->globalBest;
//}
//
//Vector Team::GetWinningDest() {
//    return WinCell;
//}
