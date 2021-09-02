#include "Referee.h"

void Referee::doTurn(Player &p, int n) {
    bool success = false;
    CLEAR_WINDOW;
    awardResources(p);
    while (!success) {
        // First turn.
        if (n == 0) {
            int r, c;
            do {
                board.print();
                std::cout << "Player " << p.repr << std::endl;
                std::cout << "Enter settlement (row, col): ";
                std::cin >> r >> c;
                RESET_CIN;
                buildSettlement(p, r, c, success);
            } while (!success);
            success = false;
            do {
                board.print();
                std::cout << "Player " << p.repr << std::endl;
                std::cout << "Enter road (row, col): ";
                std::cin >> r >> c;
                RESET_CIN;
                buildRoad(p, r, c, success, n == 0);
            } while (!success);
        }
        // Subsequent turns.
        else {
            board.print();
            p.display();
            std::cout << std::endl
                << "Build road:       w+o" << std::endl
                << "Build settlement: w+b+s+h" << std::endl << std::endl;
            promptForMove(p, success);
        }
    }
}

void Referee::promptForMove(Player &p, bool &success) {
    char c;
    std::cout << "(b)uild, (t)rade, (f)orfeit? ";
    std::cin >> c;
    RESET_CIN;
    executeMove(p, c, success);
}

void Referee::executeMove(Player &p, char c, bool &success) {
    if (c == 'b')
        facilitateBuild(p, success);
    if (c == 't')
        facilitateTrade(p, success);
    if (c == 'f')
        success = true;
}

void Referee::facilitateTrade(Player &p, bool &success) {
    char a, b;
    std::cout << "Enter trade (exchange, obtain): ";
    std::cin >> a >> b;
    RESET_CIN;
    // Checks whether a is valid.
    success = p.resources.hasResourcesForTrade(a) && (p.resources.get(b) != -1);
    if (success) {
        p.resources.remove(a, 3);
        p.resources.add(b);
    }
}

void Referee::facilitateBuild(Player &p, bool &success) {
    int r, c;
    std::cout << "Enter row and column: ";
    std::cin >> r >> c;
    RESET_CIN;

    if (board.isLocationValid(r, c, 's') && p.resources.hasResourcesForSettlement())
        buildSettlement(p, r, c, success);
    else if (board.isLocationValid(r, c, 'r') && p.resources.hasResourcesForRoad())
        buildRoad(p, r, c, success, false);
}

void Referee::buildSettlement(Player &p, int r, int c, bool &success) {
    success = board.isSettlementValid(r, c);
    if (success) {
        p.resources.remove('w', 1);
        p.resources.remove('b', 1);
        p.resources.remove('s', 1);
        p.resources.remove('h', 1);
        board.setState(r, c, p.repr);
        p.addPoint();
    }
}

void Referee::buildRoad(Player &p, int r, int c, bool &success, bool first) {
    if (first)
        success = board.isRoadValid(r, c, p.repr);
    else
    {
        success = board.isRoadValid(r, c);
    }

    if (success) {
        p.resources.remove('w', 1);
        p.resources.remove('o', 1);
        board.setState(r, c);
    }
}

void Referee::awardResources(Player &p) {
    // TODO: Make this more efficient.
    for (int r = 0; r < NUM_ROWS; r++)
        for (int c = 0; c < NUM_COLS; c++)
            if (board.getState(r, c) == p.repr) {
                p.addResource(board.getState(r-1, c-1));
                p.addResource(board.getState(r-1, c+1));
                p.addResource(board.getState(r+1, c-1));
                p.addResource(board.getState(r+1, c+1));
            }
}