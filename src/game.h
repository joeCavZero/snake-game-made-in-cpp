#ifndef GAME_H
#define GAME_H

#include <iostream>
#include "../utils/settings.h"

using namespace GameStates;

class Game{

    private:
        const char* title;
    public:
        GameState state = MENU;
        bool pause = false;
        //---- Metodos ----
        static Game New(const char* title);
        void start();
        void gameLoop();
        void end();
};

#endif