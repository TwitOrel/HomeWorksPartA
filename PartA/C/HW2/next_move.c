#include <stdio.h>

void next_move(char* board, int n, char player) {
    int x, y;

    // Continue prompting the player for their move until a valid move is made
    while (1) {
        printf("Your turn, %c: what's your next move?: ", player);

        // Read the player's input coordinates (x, y) and check if two integers were provided
        if (scanf("%d,%d", &x, &y) != 2) {
            printf("x and y must be integers in the range (%d, %d)", n, n);

            // Clear the input buffer in case of invalid input
            fflush(stdin);

            // Return to keep prompting for a valid move
            return;
        } else {
            // Check if the selected position on the board is empty
            if (whos_there(board, n, x, y) == ' ') {
                // Place the current player's symbol on the board and exit the loop
                board[n * (y - 1) + (x - 1)] = player;
                break;
            } else {
                // Display an error message if the position is already taken
                printf("Position (%d, %d) is already taken, please choose a different coordinate\n", x, y);

                // Clear the input buffer in case of invalid input
                fflush(stdin);

                // Continue the loop to prompt for another move
            }
        }
    }
}
