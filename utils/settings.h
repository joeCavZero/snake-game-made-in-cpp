#ifndef settings_h
#define settings_h

#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600


#define SNAKE_PART_SIZE 20

namespace GameStates
{
    typedef enum {
        MENU = 0,
        PLAY = 1,
        GAMEOVER =2
    }GameState;
} 


#endif