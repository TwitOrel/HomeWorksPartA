#include <stdio.h>

#include <stdio.h>

// Function to display the Tic-Tac-Toe board.
void show_board(const char* board, int n) {
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; j++) {
            if (j == n) {
                printf(" %c \n", whos_there(board, n, j, i));
            } else {
                printf(" %c |", whos_there(board, n, j, i));
            }
        }

        if (i == n) {
            continue;
        }

        // Print horizontal dividers between rows.
        for (int y = 0; y < n; ++y) {
            if (y == n - 1) {
                printf("---\n");
            } else {
                printf("---+");
            }
        }
    }
}
