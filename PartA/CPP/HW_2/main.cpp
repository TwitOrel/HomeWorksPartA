#include <iostream>
#include "Board.h"

using InvalidInputExcepcion = std::domain_error;

// Function to validate the user's command input.
void checkCommand(const string& command){
    if (command == "PASS" || command == "QUIT"){
        return ;
    }
    else if(command.size() == 2) {
        if (command[0] >= 'A' && command[0] <= 'H') {
            if (command[1] >= '1' && command[1] <= '8') {
                return ;
            }
        }
    }
    throw InvalidInputExcepcion("");
}

int main() {
    int countPass = 0;
    bool flagPlay = true;
    Board board = Board(8, 8);
    board.BoardPrint();

        while (countPass != 2 && board.BoardFilled() != 64) {
            try {
                string command;
                cout << (flagPlay ? "B: " : "W: ") << endl;
                getline(cin, command);
                checkCommand(command);

                if (command == "QUIT"){
                    cout << (flagPlay ? "B: " : "W: ") << "QUIT" << endl;
                    cout << (!flagPlay? "B " : "W ") << "wins the game." << endl;
                    return 0;
                }
                else if (command == "PASS"){
                    cout << (flagPlay ? "B: " : "W: ") << "PASS" << endl;
                    flagPlay = !flagPlay;
                    countPass++;
                    continue;
                }
                else{
                    board.BoardCheckLocation(command);
                    countPass = 0;
                    int j = (command[0] - 'A' );
                    int i = (command[1] - '1' );
                    board.BoardSetIndex(i, j, flagPlay ? "B" : "W");
                    flagPlay = !flagPlay;
                    board.BoardPrint();
                    if (board.BoardWhiteFilled() == 0 || board.BoardBlackFilled() == 0){
                        break;
                    }
                    continue;
                }
            }
            catch (InvalidInputExcepcion& e){
                cout << "Invalid move; the game awaits a valid move." << endl;
            }
        }

    if (board.BoardBlackFilled() == board.BoardWhiteFilled()){
        cout << "The game ends in a tie." << endl;
    } else {
        cout << (board.BoardWhiteFilled() > board.BoardBlackFilled() ? "W " : "B ") << "wins the game." << endl;
    }
    return 0;
}
