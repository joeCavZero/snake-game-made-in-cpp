#include <iostream>
#include "game.h"
int main(void) {
    Game game = Game::New("Snake Game");
    game.start();
}