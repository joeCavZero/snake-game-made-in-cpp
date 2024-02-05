#ifndef APPLE_H
#define APPLE_H
#include "raylib.h"

class Apple{
    public:

    Vector2 position;
    
    static Apple New(Vector2 pos);
    void draw();
    void randomize();
};

#endif