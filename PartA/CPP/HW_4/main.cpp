#include <iostream>
#include "Game.h"

int main(int args, char* argv[]) {
    try {
        Game game = Game::readFiles(argv[1], argv[2]);
        game.play();
    }
    catch (exception& e){
        cout << e.what() << endl;
    }
    return 0;
}
