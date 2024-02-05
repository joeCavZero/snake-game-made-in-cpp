#ifndef SNAKE_H

#define SNAKE_H

#include "raylib.h"
#include <deque> //double ended queue


class Snake{
    public:
        std::deque<Vector2> body;
        Vector2 next_dir;
        
        Vector2 aim;
        static Snake New(Vector2 pos);
        void input();
        void update();
        void draw();

        void grow();
        void reset(Vector2 pos);
        bool checkCollisionWithHimself();
};

#endif