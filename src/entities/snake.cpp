#include "snake.h"

#include "raylib.h"
#include "../settings.h"

#include <iostream>
using namespace std;

Snake Snake::New(Vector2 pos){
    Snake snake;
    snake.body = {pos,pos,pos,pos,pos,pos};
    snake.input_dir = {1,0};
    return snake;
}

void Snake::update(){
    move();
}
void Snake::move(){
    motion = input_dir;
    for( int i = body.size()-1 ; i >= 1 ; i--){
        body.at(i) = body.at(i-1) ;
    }
    body.at(0) = Vector2{ body.at(0).x + motion.x*GRID_SIZE , body.at(0).y + motion.y*GRID_SIZE };
    
}

bool Snake::isCollidingWithHimself(){
    Vector2 head = body.at(0);
    for(int i = 1 ; i < (int)body.size() ; i++){
        if(CheckCollisionRecs({head.x, head.y, GRID_SIZE, GRID_SIZE}, {body.at(i).x, body.at(i).y, GRID_SIZE, GRID_SIZE} )) {
            return true;
        }

    }
    return false;
}

void Snake::input(){
    if( IsKeyDown(KEY_W) && (motion.x != 0 && motion.y != 1) ){
        input_dir = {0, -1};
    }else if ( IsKeyDown(KEY_S) && (motion.x != 0 && motion.y != -1) ){
        input_dir = {0, 1};
    }
    if( IsKeyDown(KEY_A) && (motion.x != 1 && motion.y != 0) ){
        input_dir = {-1,0};
    }else if( IsKeyDown(KEY_D) && (motion.x != -1 &&motion.y != 0) ){
        input_dir = {1,0};
    }
}

void Snake::draw(){
    for (int i =0 ; i < (int)body.size() ; i++){
        DrawRectangleV(body.at(i), {GRID_SIZE,GRID_SIZE}, MAIN_COLOR);
    }
}

bool Snake::isBodyCollidingWithApple(Apple apple){

    for(int i = 0 ;i< (int)body.size() ; i++){
        auto cur_body = body.at(i);
        if (i != 0 &&  CheckCollisionRecs({cur_body.x, cur_body.y, GRID_SIZE, GRID_SIZE}, {apple.position.x, apple.position.y, GRID_SIZE, GRID_SIZE} ) ){
            return true;
        }
    }
    
    return false;
}

bool Snake::isHeadCollidingWithApple(Apple apple){
    return CheckCollisionRecs({body.at(0).x, body.at(0).y, GRID_SIZE, GRID_SIZE}, {apple.position.x, apple.position.y, GRID_SIZE, GRID_SIZE} );
}

void Snake::grow(){
    body.push_back( body.at(body.size()-1) );
}