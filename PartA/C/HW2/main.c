#include <stdio.h>
#include "is_legal_coordinate.c"
#include "whos_there.c"
#include "next_move.c"
#include "who_won.c"
#include "show_board.c"

int main() {
    int plays = 0;
    unsigned int size;

    // Prompt the user for the size of the board.
    printf("How many columns and rows in your board?\n");

    // Read the size from user input.
    if (scanf("%ud", &size) != 1 || size <= 0) {
        printf("Error: dimension needs to be a positive integer!");
        return 1; // Exit with an error code.
    }

    char list[size * size];
    char flag = 'x';

    // Initialize the board.
    for (int i = 0; i < size * size; ++i) {
        list[i] = ' ';
    }

    // Display the initial board.
    show_board(list, size);

    // Play the game.
    while (plays != size * size) {
        plays++;

        // Get the next move from the current player.
        next_move(list, size, flag);

        // Display the updated board.
        show_board(list, size);

        // Check if someone has won.
        if (who_won(list, size) != ' ') {
            printf("Congratulations %c, you are the winner!", flag);
            return 0; // Exit successfully.
        }

        // Switch to the other player.
        if (flag == 'x') {
            flag = 'o';
        } else {
            flag = 'x';
        }
    }

    // If all cells are filled and no winner, it's a draw.
    printf("Draw! Play again to see who is better.\n");

    return 0;
}

