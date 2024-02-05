#include "apple.h"
#include "raylib.h"
#include "../settings.h"
#include <cmath>

Apple Apple::New(Vector2 pos){
    Apple apple;
    apple.position = pos;
    return apple;
}

void Apple::draw(){
    DrawCircleV({position.x + GRID_SIZE/2 , position.y + GRID_SIZE/2}, GRID_SIZE/2, RED);
}

void Apple::randomize(){
    position.x = floor(GetRandomValue(GRID_SIZE, SCREEN_WIDTH-GRID_SIZE) / GRID_SIZE ) * GRID_SIZE ;
    position.y = floor(GetRandomValue(GRID_SIZE, SCREEN_HEIGHT-GRID_SIZE) / GRID_SIZE ) * GRID_SIZE ;
}