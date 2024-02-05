#include <iostream>
#include "game.h"
#include "../utils/settings.h"
int main(void) {
    Game game = Game::New("Snake Game");
    game.state = GameStates::MENU;
    game.start();
}