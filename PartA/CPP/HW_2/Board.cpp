#include <sstream>
#include <iostream>
#include "Board.h"
using InvalidInputExcepcion = std::domain_error;


Board ::Board() : Board(8,8) {}

Board ::Board(int row, int colum) : countBlack(2),countWhite(2),row(row),colum(colum) {
    board = new string *[row];
    for (int i = 0; i < row; i++) {
        board[i] = new string[colum];
    }
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < colum; ++j) {
            board[i][j] = "o";
        }
    }
    board[3][4] = "B";
    board[4][3] = "B";
    board[4][4] = "W";
    board[3][3] = "W";
}

Board ::~Board(){
    for (int i = 0; i < row; ++i) {
        delete[] board[i];
    }
    delete[]board;
}

void Board::BoardSetIndex (int i, int j, const string& val) {
    board[i][j] = val;
    if (!(zero(i,j,val) + one(i,j,val) + two(i,j,val) + tree(i,j,val) + four(i,j,val) + five(i,j,val) + six(i,j,val) + seven(i,j,val))){
        board[i][j] = "o";
        throw InvalidInputExcepcion("");
    }
    if (val == "B"){
        countBlack++;
    } else{
        countWhite++;
    }
}

bool Board::BoardIn(int i, int j) const {
    return (i >= 0 && i < colum && j >= 0 && j < row);
}

int Board::BoardFilled() const{
    return countWhite + countBlack;
}

int Board::BoardBlackFilled() const {
    return countBlack;
}

int Board::BoardWhiteFilled() const {
    return countWhite;
}

bool Board::BoardCheckLocation(const string& command){
    int j = (command[0] - 'A');
    int i = (command[1] - '1');
    if (board[i][j] != "o"){
        throw InvalidInputExcepcion("");
    } else{
        return true;
    }
}

void Board ::BoardPrint() const {
    stringstream print;
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < colum; ++j) {
            print << board[i][j];
            if (j == colum-1){
                if (i == row-1){
                    print <<" " << i+1 << "\n";
                } else {
                    print << " " << i + 1 << "\n\n";
                }
            } else{
                print << " ";
            }
        }
    }
    print << "A B C D E F G H";
    cout << print.str() << endl;

}

bool Board::zero(int i, int j,const string& val){
    int count =0;
    string against;
    if (val == "B"){
        against = "W";
    }
    else{
        against = "B";
    }
    int ROW = i - 1;
    int COLUM = j;
    while (this->BoardIn(ROW, COLUM)){
        if (board[ROW][COLUM] == against){
            if(ROW == 0 || ROW == 7 || COLUM == 0 || COLUM == 7){return false;}
            ROW--;
            count++;
        } else if (board[ROW][COLUM] == val){
            ROW++;
            break;
        } else{
            return false;
        }
    }
    if(count == 0){ return false;}
    while (count){
        if (val == "B"){
            countBlack++;
            countWhite--;
        } else{
            countBlack--;
            countWhite++;
        }
        count--;
        board[ROW++][COLUM] = val;
    }
    return true;
}

bool Board::one(int i, int j, const string &val) {
    int count =0;
    string against;
    if (val == "B"){
        against = "W";
    }
    else{
        against = "B";
    }
    int ROW = i - 1;
    int COLUM = j + 1;
    while (this->BoardIn(ROW, COLUM)){
        if (board[ROW][COLUM] == against){
            if(ROW == 0 || ROW == 7 || COLUM == 0 || COLUM == 7){return false;}
            ROW--;
            COLUM++;
            count++;
        } else if (board[ROW][COLUM] == val){
            ROW++;
            COLUM--;
            break;
        } else{
            return false;
        }
    }
    if(count == 0){ return false;}
    while (count){
        if (val == "B"){
            countBlack++;
            countWhite--;
        } else{
            countBlack--;
            countWhite++;
        }
        count--;
        board[ROW++][COLUM--] = val;
    }
    return true;
}

bool Board::two(int i, int j, const string& val) {
    int count =0;
    string against;
    if (val == "B"){
        against = "W";
    }
    else{
        against = "B";
    }
    int ROW = i ;
    int COLUM = j + 1;
    while (this->BoardIn(ROW, COLUM)){
        if (board[ROW][COLUM] == against){
            if(ROW == 0 || ROW == 7 || COLUM == 0 || COLUM == 7){return false;}
            COLUM++;
            count++;
        } else if (board[ROW][COLUM] == val){
            COLUM--;
            break;
        } else{
            return false;
        }
    }
    if(count == 0){ return false;}
    while (count){
        if (val == "B"){
            countBlack++;
            countWhite--;
        } else{
            countBlack--;
            countWhite++;
        }
        count--;
        board[ROW][COLUM--] = val;
    }
    return true;
}

bool Board::tree(int i, int j, const string &val) {
    int count =0;
    string against;
    if (val == "B"){
        against = "W";
    }
    else{
        against = "B";
    }
    int ROW = i + 1;
    int COLUM = j + 1;
    while (this->BoardIn(ROW, COLUM)){
        if (board[ROW][COLUM] == against){
            if(ROW == 0 || ROW == 7 || COLUM == 0 || COLUM == 7){return false;}
            ROW++;
            COLUM++;
            count++;
        } else if (board[ROW][COLUM] == val){
            ROW--;
            COLUM--;
            break;
        } else{
            return false;
        }
    }
    if(count == 0){ return false;}
    while (count){
        if (val == "B"){
            countBlack++;
            countWhite--;
        } else{
            countBlack--;
            countWhite++;
        }
        count--;
        board[ROW--][COLUM--] = val;
    }
    return true;
}

bool Board::four(int i, int j, const string &val) {
    int count =0;
    string against;
    if (val == "B"){
        against = "W";
    }
    else{
        against = "B";
    }
    int ROW = i + 1;
    int COLUM = j;
    while (this->BoardIn(ROW, COLUM)){
        if (board[ROW][COLUM] == against){
            if(ROW == 0 || ROW == 7 || COLUM == 0 || COLUM == 7){return false;}
            ROW++;
            count++;
        } else if (board[ROW][COLUM] == val){
            ROW--;
            break;
        } else{
            return false;
        }
    }
    if(count == 0){ return false;}
    while (count){
        if (val == "B"){
            countBlack++;
            countWhite--;
        } else{
            countBlack--;
            countWhite++;
        }
        count--;
        board[ROW--][COLUM] = val;
    }
    return true;
}

bool Board::five(int i, int j, const string &val) {
    int count =0;
    string against;
    if (val == "B"){
        against = "W";
    }
    else{
        against = "B";
    }
    int ROW = i + 1;
    int COLUM = j - 1;
    while (this->BoardIn(ROW, COLUM)){
        if (board[ROW][COLUM] == against){
            if(ROW == 0 || ROW == 7 || COLUM == 0 || COLUM == 7){return false;}
            ROW++;
            COLUM--;
            count++;
        } else if (board[ROW][COLUM] == val){
            ROW--;
            COLUM++;
            break;
        } else{
            return false;
        }
    }
    if(count == 0){ return false;}
    while (count){
        if (val == "B"){
            countBlack++;
            countWhite--;
        } else{
            countBlack--;
            countWhite++;
        }
        count--;
        board[ROW--][COLUM++] = val;
    }
    return true;
}

bool Board::six(int i, int j, const string& val) {
    int count =0;
    string against;
    if (val == "B"){
        against = "W";
    }
    else{
        against = "B";
    }
    int ROW = i ;
    int COLUM = j - 1;
    while (this->BoardIn(ROW, COLUM)){
        if (board[ROW][COLUM] == against){
            if(ROW == 0 || ROW == 7 || COLUM == 0 || COLUM == 7){return false;}
            COLUM--;
            count++;
        } else if (board[ROW][COLUM] == val){
            COLUM++;
            break;
        } else{
            return false;
        }
    }
    if(count == 0){ return false;}
    while (count){
        if (val == "B"){
            countBlack++;
            countWhite--;
        } else{
            countBlack--;
            countWhite++;
        }
        count--;
        board[ROW][COLUM++] = val;
    }
    return true;
}

bool Board::seven(int i, int j, const std::string &val) {
    int count = 0;
    string against;
    if (val == "B") {
        against = "W";
    } else {
        against = "B";
    }
    int ROW = i - 1;
    int COLUM = j - 1;
    while (this->BoardIn(ROW, COLUM)) {
        if (board[ROW][COLUM] == against) {
            if(ROW == 0 || ROW == 7 || COLUM == 0 || COLUM == 7){return false;}
            ROW--;
            COLUM--;
            count++;
        } else if (board[ROW][COLUM] == val) {
            ROW++;
            COLUM++;
            break;
        } else {
            return false;
        }
    }
    if (count == 0) { return false; }
    while (count) {
        if (val == "B") {
            countBlack++;
            countWhite--;
        } else {
            countBlack--;
            countWhite++;
        }
        count--;
        board[ROW++][COLUM++] = val;
    }
    return true;
}