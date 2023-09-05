#ifndef EX2_BOARD_H
#define EX2_BOARD_H

#include <string>

using namespace std;

class Board{

private:
    int countBlack;
    int countWhite;
    int row;
    int colum;
    string** board;


//// HOPE U ENJOY, IN BOARD.H LINE 17-26 I MADE FUNCTIONS FOR INVERSION RULE I KNOW I CAN REPLACE IT WITH 2 SMART FUNCTION THAT ONE CHECK THE AROUND OF THE POINT AND IF IT NECESSARY
//// THE SECOND FUNCTION GET THE REFERENCE POINT AND VECTOR DELTA
//// THAT CAN REPLACE THE ZERO - SEVEN FUNCTION I WROTE
    //after choosing place
    //check if the move is legal, if yes it makes all those inversion rule
    bool zero(int,int,const string&);
    bool one(int,int,const string&);
    bool two(int,int,const string&);
    bool tree(int,int,const string&);
    bool four(int,int,const string&);
    bool five(int,int,const string&);
    bool six(int,int,const string&);
    bool seven(int,int,const string&);

public:
    //Constructors
    Board();
    Board(int, int);
    ~Board();

    //set index in the board
    void BoardSetIndex(int, int, const string& val);

    //check if index in the board
    bool BoardIn(int, int) const;

    //return how many acts made
    int BoardFilled() const;

    //return how many black made
    int BoardBlackFilled() const;

    //return how many white made
    int BoardWhiteFilled() const;

    //check if this location not filled
    bool BoardCheckLocation(const string& command);

    //printing the board
    void BoardPrint() const;
};
#endif //EX2_BOARD_H
