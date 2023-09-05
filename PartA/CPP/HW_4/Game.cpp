//
// Created by Orel on 10/05/2023.
//
#include <iostream>
#include <fstream>
#include "Team.h"
#include "Game.h"

using namespace std;

int countSpace(const string& line) {
    int count = 0;
    for (char c : line) {
        if (c == ' ') {
            count++;
        }
    }
    return count;
}

bool isNumeric (const string& line){
    for (char c : line){
        if (c > 57 || c < 46){
            return false;
        }
    }
    return true;
}

Game Game::readFiles(const string &conf, const string &init) {
    // create file Stream and check it is not null
    ifstream configFile(conf);
    if (!configFile) {
        throw  invalid_argument("Failed to open the file.") ;
    }

    // read the first line and validate it is a single number for number of players
    string line;
    getline(configFile, line);
    if (countSpace(line) < 1 || countSpace(line) > 2) {

        throw invalid_argument("ERROR: Invalid input.");
    }
    std::string delimiter = " "; // Delimiter

    size_t pos1 = 0;
    size_t pos2 = line.find(delimiter);
    size_t pos3 = line.find(delimiter, pos2 + 1);

    string s1 = line.substr(pos1, pos2 - pos1);
    string s2 = line.substr(pos2 + 1, pos3 - pos2 - 1);
    if (isNumeric(s1) + isNumeric(s2)  != 2){
        throw invalid_argument("ERROR: Invalid input.");
    }

    Vector winPlace = Vector(stod(s1), stod(s2));


    getline(configFile, line);
    if (countSpace(line) != 0) {
        throw invalid_argument("ERROR: Invalid input.");
    }

    pos1 = 0;
    pos2 = line.find(delimiter);
    s1 = line.substr(pos1, pos2 - pos1);

    if (isNumeric(s1)  != 1){
        throw invalid_argument("ERROR: Invalid input.");
    }
    int time = stoi(s1);
    if (time > 1000000 || time < 0){
        throw invalid_argument("ERROR: Invalid time");
    }
    getline(configFile,line);
    configFile.close(); // close the file when done reading
    return {Team::readInit(init,winPlace), time};
}

Game::Game(const Team &team, int time):crew(team), time(time) {
    this->cells = new Cell*[MAX_X];
    for (int i = MIN_X; i < MAX_X; ++i) {
        cells[i] = new Cell[MAX_Y];
    }
    for (int i = 0; i < team.getNumPlayers(); ++i) {
           cells[(int)crew[i].GetLocation().GetX()][(int)crew[i].GetLocation().GetY()]++;
    }
}

Game::Game(const Game &other):crew(other.crew),time(other.time) {
    this->cells = new Cell*[MAX_X];
    for (int i = MIN_X; i < MAX_X; ++i) {
        cells[i] = new Cell[MAX_Y];
        for (int j = 0; j < MAX_Y; ++j) {
            this->cells[i][j] = other.cells[i][j];
        }
    }
}

//Game::Game(Game&& other) noexcept
//        : cells(other.cells), crew(other.crew), time(other.time)
//{
//    other.cells = nullptr;
//}


Game::~Game() {
    for (int i = 0; i < 61; ++i) {
        delete[] cells[i];
    }
    delete[] cells;
}

Game& Game::operator=(const Game& other) {
    if (this == &other)return *this;

    this->crew = other.crew;
    this->time = other.time;
    for (int i = 0; i < 61; ++i) {
        delete[] cells[i];
    }
    delete[] cells;
    this->cells = new Cell*[MAX_X];
    for (int i = MIN_X; i < MAX_X; ++i) {
        cells[i] = new Cell[MAX_Y];
        for (int j = 0; j < MAX_Y; ++j) {
            this->cells[i][j] = other.cells[i][j];
        }
    }
    return *this;
}

//Game& Game::operator=(Game&& other) noexcept {
//    if (this == &other){
//        return *this;
//    }
//    for (int i = 0; i < 61; ++i) {
//        delete[] cells[i];
//    }
//    delete[] cells;
//
//    cells = other.cells;
//    other.cells = nullptr;
//    time = other.time;
//    crew = other.crew;
//    return *this;
//}

void Game::play() {
    int clock = 0;
    while (clock < time ) {
        clock++;
        crew.updateGlobalBest();
        if (crew.isWin())break;
        for (int i = 0; i < this->crew.getNumPlayers(); ++i) {
            int x = (int) crew[i].GetLocation().GetX();
            int y = (int) crew[i].GetLocation().GetY();
            cells[(x == MAX_X)? MAX_X-1 : x][(y == MAX_Y)? MAX_Y-1:y]--;
            crew.updateMemberTeam(i);
            cells[(x == MAX_X)? MAX_X-1 : x][(y == MAX_Y)? MAX_Y-1:y]++;
        }
    }
    cout << clock << endl;
    this->crew.printTeam();
}



