#include <cstdlib>
#include "raylib.h"
#include <cmath>
#include "settings.h"
int random(int max) {
    return rand() % (max + 1);
}
Vector2 randomGridPosition(){
    int posx = static_cast<int>( std::floor(SCREEN_WIDTH / SNAKE_PART_SIZE) - 1) ;
    int posy = static_cast<int>( std::floor(SCREEN_HEIGHT / SNAKE_PART_SIZE) - 1);
    
    return {static_cast<float>(random(posx) * SNAKE_PART_SIZE), static_cast<float>(random(posy) * SNAKE_PART_SIZE)};
}