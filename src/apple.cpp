#include "raylib.h"
#include "apple.h"
#include "../utils/settings.h"

Apple Apple::New(Vector2 pos){
    Apple apple;
    apple.position = pos;
    return apple;
}

Vector2 Apple::getPosition(){
    return this->position;
}
void Apple::setPosition(Vector2 pos){
    this->position = pos;
}

void Apple::draw(){
    DrawRectangleV(position , {SNAKE_PART_SIZE,SNAKE_PART_SIZE}, RED);
}

bool Apple::checkCollisionWithSnake( Snake snake){
    for ( auto& part: snake.body ){
        if ( this->position.x == part.x && this->position.y == part.y){
            return true;
        }
    }
    return false;
}