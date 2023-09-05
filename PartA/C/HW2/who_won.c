#include <stdbool.h>

// Function to check if a player has won the game.
char who_won(const char* board, int n) {
    // Check for a horizontal or vertical win.
    for (int i = 1; i <= n; i++) {
        int testerVertical = 0, testerHorizontal = 0;
        for (int j = 1; j <= n; ++j) {
            testerVertical += whos_there(board, n, j, i);
            testerHorizontal += whos_there(board, n, i, j);
        }

        // Check if a player has won horizontally or vertically.
        if (testerHorizontal / n == 'x') {
            return 'x';
        }
        if (testerHorizontal / n == 'o') {
            return 'o';
        }
        if (testerVertical / n == 'x') {
            return 'x';
        }
        if (testerVertical / n == 'o') {
            return 'o';
        }
    }

    // Check for a diagonal win.
    int downSlant = 0, upSlant = 0;
    for (int i = 1; i <= n; ++i) {
        downSlant += whos_there(board, n, i, i);
        upSlant += whos_there(board, n, n - i + 1, i);
    }

    // Check if a player has won diagonally.
    if (upSlant / n == 'x') {
        return 'x';
    }
    if (upSlant / n == 'o') {
        return 'o';
    }
    if (downSlant / n == 'o') {
        return 'o';
    }
    if (downSlant / n == 'x') {
        return 'x';
    }

    // If no player has won yet, return a space to indicate no winner.
    return ' ';
}
