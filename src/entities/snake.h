#ifndef SNAKE_H
#define SNAKE_H

#include "raylib.h"
#include <deque>
#include "apple.h"

using namespace std;
class Snake {
    public:
        deque<Vector2> body;
        Vector2 input_dir;
        Vector2 motion;

        static Snake New(Vector2 pos);
        void update();
        void draw();
        void grow();
        bool isCollidingWithHimself();
        bool isBodyCollidingWithApple(Apple apple);
        bool isHeadCollidingWithApple(Apple apple);
        void input();
    private:
        void move();
        
        
        
};


#endif