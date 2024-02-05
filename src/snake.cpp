#include "snake.h"
#include "raylib.h"
#include <iostream>
#include <deque>
#include "../utils/settings.h"

Snake Snake::New(Vector2 pos) {
    Snake snake;
    
    snake.body = {pos, {pos.x - SNAKE_PART_SIZE, pos.y}, {pos.x - 2*SNAKE_PART_SIZE, pos.y}};
    snake.aim = {1, 0};
    snake.next_dir = snake.aim ;
    
    return snake;
}

void Snake::reset(Vector2 pos){
    body.clear();
    body = {pos, {pos.x - SNAKE_PART_SIZE, pos.y}, {pos.x - 2*SNAKE_PART_SIZE, pos.y} };
    
    std::cout << "faleceu\n";
}
void Snake::input() {
    //-------- Input --------
    if ( IsKeyPressed(KEY_W) && (aim.x != 0 && aim.y != 1)  ){
        next_dir= {0, -1};
        
    }else if ( IsKeyPressed(KEY_S) && (aim.x != 0 && aim.y != -1)){
        next_dir= {0, 1};

    }else if ( IsKeyPressed(KEY_A) && (aim.x != 1 && aim.y != 0)){
        next_dir= {-1 , 0};

    }else if ( IsKeyPressed(KEY_D) && (aim.x != -1 && aim.y != 0)){
        next_dir= {1 , 0};
    }
}
void Snake::update() {
    
    for ( int i = body.size()-1 ; i > 0 ; i--){
        body.at(i) = body.at(i-1);
        
    }
    
    //--------  --------
    
    body.front().x += next_dir.x * SNAKE_PART_SIZE;
    body.front().y += next_dir.y * SNAKE_PART_SIZE;
    aim = next_dir;
}

void Snake::draw(){
    for (auto& vector : body){
        DrawRectangleV( vector , {SNAKE_PART_SIZE, SNAKE_PART_SIZE} , GREEN);
        
    }
}
void Snake::grow(){
    body.push_back( body.back() );
}


bool Snake::checkCollisionWithHimself(){
    for(int i = 0; i < body.size(); i++){
        //std::cout << aim.x << " ----- " << aim.y <<std::endl;
        if ( 
            i >= 2 &&
            body.at(i).x == body.front().x  &&
            body.at(i).y == body.front().y
            ){
                std::cout << "BATEU KKKKKKKK" <<std::endl;
                return true;
            }
    }
    return false;
}