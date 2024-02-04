#ifndef game_h

#define game_h

#include "raylib.h"
#include <deque> //double ended queue


class Snake{
    private:
        std::deque<Vector2> body;
        Vector2 dir;
        bool grow;
    public:
        static Snake New(Vector2 pos);
        void input();
        void update();
        void draw();
        std::deque<Vector2> getBody();
};

#endif