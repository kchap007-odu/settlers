#include "Board.h"

Board::Board(void) {
    setInitConfig();
    print();
}

bool Board::isLocationValid(int r, int c, char a) {
    return ((a == 's') && ((r % 2 == 0) && (c % 2 == 0)) || ((a == 'r') && ((r % 2) != (c % 2))));
}

void Board::setInitConfig(void) {
    int idx = 0;
    for (int i = 0; i < NUM_ROWS; i++)
        for (int j = 0; j < NUM_COLS; j++)
            state[i][j] = (((i % 2) == 1) & ((j % 2) == 1)) ? getNextResource(idx) : ' ';
}

char Board::getNextResource(int& n) {
    char c = INIT_RESOURCES[n];
    n++;
    return c;
}

bool Board::isSettlementValid(int r, int c) {
    return (isLocationValid(r, c, 's') && (!isOccupied(r-2, c) && !isOccupied(r+2, c) && !isOccupied(r, c-2) && !isOccupied(r, c+2)));
}

bool Board::isRoadValid(int r, int c, char a) {
    // Overloaded for first turn.
    if (!isLocationValid(r, c, 'r'))
        return false;
    if (r % 2 == 0)
        return ((getState(r, c-1) == a) || (getState(r, c+1) == a));
    else if (c % 2 == 0)
        return ((getState(r-1, c) == a) || (getState(r+1, c) == a));
    else
        return false;
}

bool Board::isRoadValid(int r, int c) {
    bool surrounding, adjacent;
    // A road must have another road two columns to the left, two columns to the right, or one column and one row offset.
    surrounding = (isOccupied(r-1, c-1) || isOccupied(r+1, c-1) || isOccupied(r+1, c+1) || isOccupied(r-1, c+1));
    // If the row is even, columns need to be checked, otherwise, rows need to be checked.
    adjacent = (r % 2 == 0) ? (isOccupied(r, c-2) || isOccupied(r, c+2)) : (isOccupied(r-2, c) || isOccupied(r+2, c));
    return (surrounding || adjacent);
}

void Board::print(void) {
    CLEAR_WINDOW;
    // Print header
    std::cout << std::setw(SPACING) << ' ';
    for (int i = 0; i < NUM_ROWS; i++)
        // Prints the column number.
        std::cout << std::setw(SPACING) << i;
    std::cout << std::endl;

    for (int i = 0; i < NUM_ROWS; i++) {
        std::cout << std::endl;
        // Prints the row number
        std::cout << std::setw(SPACING) << i;
        for (int j = 0; j < NUM_COLS; j++)
            std::cout << std::setw(SPACING) << state[i][j];
        std::cout << std::endl;
    }
}