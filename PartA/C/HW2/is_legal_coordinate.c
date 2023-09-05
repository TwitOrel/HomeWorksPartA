
// Function to check if the given coordinates (x, y) are legal within the game board of size n x n.
bool is_legal_coordinate(unsigned int n, int x, int y) {
    // Calculate the index of the cell in the one-dimensional board representation.
    int index = n * (y - 1) + (x - 1);

    // Check if the calculated index is within the valid range [0, n*n].
    if (index >= 0 && index <= n * n) {
        // The coordinates are legal, so return true.
        return true;
    }

    // The coordinates are not legal, so return false.
    return false;
}
