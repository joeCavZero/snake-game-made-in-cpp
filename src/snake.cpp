#include "snake.h"
#include "raylib.h"
#include <iostream>
#include <deque>

Snake Snake::New(Vector2 pos) {
    Snake snake;
    snake.body = {pos , pos, pos, pos, pos};
    snake.dir = {1, 0};
    return snake;
}
void Snake::input() {
    //-------- Input --------
    if (IsKeyPressed(KEY_W)){
        dir = {0, 1};
        std::cout << "W" << std::endl;
    }else if (IsKeyPressed(KEY_S)){
        dir = {0, -1};
    }else if (IsKeyPressed(KEY_A)){
        dir = {-1 , 0};
    }else if ( IsKeyPressed(KEY_D)){
        dir = {1 , 0};
    }
}
void Snake::update() {
    
    for ( int i = body.size()-1 ; i > 0 ; i--){
        body.at(i) = body.at(i-1);
        //std::cout << "dado update" << std::endl;
    }
    //--------  --------
    
    body.front().x += dir.x * 20;
    body.front().y += dir.y * 20;
    
}

void Snake::draw(){
    for (auto& vector : body){
        DrawCircleV( vector , 10 , GREEN );
        //std::cout << dir.x <<" - "<< dir.y <<" desenhado " << vector.x << " "<< vector.y << std::endl;
    }
}

std::deque<Vector2> Snake::getBody(){
    return body;
}