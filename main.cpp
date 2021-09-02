#include "Board.h"
#include "Player.h"
#include "Referee.h"
#include "constants_and_macros.h"

int main() {
    int turnNumber = 0;
    CLEAR_WINDOW;

    Referee ref;
    Player player1('X');
    Player player2('Y');

    loop:
    ref.doTurn(player1, turnNumber);
    if (player1.checkWin())
        goto victory;
    ref.doTurn(player2, turnNumber);
    if (player2.checkWin())
        goto victory;
    turnNumber++;
    goto loop;

    victory:
    std::cout << "Victory Player " << (player1.checkWin() ? "1" : "2") << "!" << std::endl;

    return 0;
}