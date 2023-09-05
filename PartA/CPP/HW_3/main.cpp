#include <iostream>
#include "Team.h"
#include "Player.h"
#include "Game.h"

// the files used for the game so I choose to send there the files and deal with them

using namespace std;

int main(int arg, char* argv[]) {
    try {
        // Read game configuration and initialization files from command line arguments
        Game game = Game::readFiles(argv[1], argv[2]);

        // Start the game
        game.play();
    }
    catch (exception& e){
        // Handle exceptions and display error messages
        cout << e.what() << endl;
    }
    return 0;
}
