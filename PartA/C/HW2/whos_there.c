#include <stdlib.h>

// Function to check who occupies a specific coordinate (x, y) on the game board.
char whos_there(const char* board, int n, int x, int y) {
    // Check if the given coordinates (x, y) are legal for the board size n x n.
    if (is_legal_coordinate(n, x, y) == false) {
        // Print an error message and exit the program with an error code (-1).
        printf("Error");
        exit(-1);
    }

    // Calculate the index of the cell in the one-dimensional board representation.
    int index = n * (y - 1) + (x - 1);

    // Return the character (player) occupying the specified coordinate.
    return board[index];
}
