#ifndef APPLE_H
#define APPLE_H

#include "raylib.h"
#include "snake.h"

class Apple {
    private:
        Vector2 position;

    public:
        static Apple New(Vector2 pos);
        void update();
        void draw();
        Vector2 getPosition();
        void setPosition(Vector2 pos);
        bool checkCollisionWithSnake(Snake snake);
        

};

#endif