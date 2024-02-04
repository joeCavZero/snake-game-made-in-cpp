#ifndef GAME_H

#define GAME_H

#include <iostream>

class Game{

    private:
        const char* title;
    public:
        //---- Metodos ----
        static Game New(const char* title);
        void start();
        void gameLoop();
        void end();
};

#endif