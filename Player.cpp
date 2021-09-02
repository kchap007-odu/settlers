#include "Player.h"

Player::Player(char c) {
    repr = c;
    // Need to start with enough resources for a road and settlment.
    resources.add('w');
    resources.add('o');
    resources.add('w');
    resources.add('b');
    resources.add('s');
    resources.add('h');
    // Need to ensure score is set to 0 once first settlment is built.
    score = -1;
}

void Player::display(void) {
    std::cout << std::endl;
    std::cout << "Player " << repr << std::endl;
    std::cout << "Score: " << score << std::endl;
    std::cout << "Resources: " << std::endl;
    resources.display();
}