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
        if (c > 57 || c < 46){
            return false;
        }
    }
    return true;
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
        if ( countSpaces(line) != 3){
            throw invalid_argument("ERROR: Invalid input.");
        }

        std::string delimiter = " "; // Delimiter

        size_t pos1 = 0;
        size_t pos2 = line.find(delimiter);
        size_t pos3 = line.find(delimiter, pos2 + 1);
        size_t pos4 = line.find(delimiter, pos3 + 1);

        string s1 = line.substr(pos1, pos2 - pos1);
        string s2 = line.substr(pos2 + 1, pos3 - pos2 - 1);
        string s3 = line.substr(pos3 + 1, pos4 - pos3 - 1);
        string s4 = line.substr(pos4 + 1);

        if (isParam(s1) + isParam(s2) + isParam(s3) + isParam(s4) != 4){
            throw invalid_argument("ERROR: Invalid input.");
        }

        double  x1 = stod(s1);
        double  y1 = stod(s2);
        double  x2 = stod(s3);
        double  y2 = stod(s4);
        team[linesCounter] = Player(linesCounter, Vector(x1, y1), Vector(x2, y2));
        linesCounter++;
    }
    team.setGlobalBest(team[0].GetLocation());
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
    this->players = new Player[numPls];

}

Team::Team(const Team &other):
    numPlayers(other.numPlayers),
    win(other.win),
    globalBest(other.globalBest),
    WinCell(other.WinCell),
    players(new Player[other.numPlayers]){
    for (int i = 0; i < numPlayers; ++i) {
        players[i] = other.players[i];
    }
}

Team::~Team() {
    delete[] this->players;
}

Team &Team::operator=(const Team &other) {
    if (this == &other)return *this;
    this->win = other.win;
    this->globalBest = other.globalBest;
    this->WinCell = other.WinCell;
    if (other.numPlayers != this->numPlayers){
        delete[] players;
        this->players = new Player[other.numPlayers];
        numPlayers = other.numPlayers;
    }
    for (int i = 0; i < other.numPlayers; ++i) {
        players[i] = other.players[i];
    }
    return *this;
}

void Team::updateGlobalBest() {
    for (int i = 0; i < this->numPlayers; ++i) {
        double globalBestDistance = globalBest.Distance(WinCell);
        double personalBestDistance = this->players[i].GetPersonalBest().Distance(WinCell);
        if (globalBestDistance > personalBestDistance){
            globalBest = this->players[i].GetPersonalBest();
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
    this->players[index].SetSpeedNLocation(globalBest, WinCell);
}

void Team::setGlobalBest(const Vector &other) {
    this->globalBest = other;
}

Player& Team::operator[](int index){
    return this->players[index];
}

int Team::getNumPlayers() const{
    return this->numPlayers;
}


void Team::printTeam() {
    for (int i = 0; i < this->numPlayers; ++i) {
        cout << players[i] ;
        if(i!=numPlayers-1){
            cout<<endl;
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
