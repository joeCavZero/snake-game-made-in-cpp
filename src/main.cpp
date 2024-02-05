#include "raylib.h"

#include "settings.h"
#include "../utils/timer.h"
#include "../utils/fullscreen.h"
#include "entities/apple.h"
#include "entities/snake.h"

#include <iostream>

void DrawBorder();

int main(void)
{

    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Snake Game");
    InitAudioDevice();
    SetTargetFPS(10);
    SetExitKey(KEY_NULL);

    RenderTexture2D display = LoadRenderTexture(SCREEN_WIDTH, SCREEN_HEIGHT);

    Apple apple = Apple::New({0,0});
        apple.randomize();
    Snake snake = Snake::New({SCREEN_WIDTH/2, SCREEN_HEIGHT/2});

    Timer snake_move_timer = Timer::New();
        snake_move_timer.start(2.0);

    
    while (!WindowShouldClose())
    {   
        if(IsKeyPressed(KEY_F11)){
            SwitchFullscreen();
        }
        if(IsKeyPressed(KEY_SPACE)){
            apple.randomize();
        }
        //==== INPUT ====
        snake.input();

        //==== UPDATE ====

        snake_move_timer.update();
        
        if( snake_move_timer.isFinished()){
            snake.update();
            snake_move_timer.start(0.15);
        }
        
        if( snake.isBodyCollidingWithApple(apple) ){
            apple.randomize();
        }
        if( snake.isHeadCollidingWithApple(apple) ){
            snake.grow();
            apple.randomize();
        }
        if( snake.isCollidingWithHimself() ){
            snake = Snake::New({SCREEN_WIDTH/2, SCREEN_HEIGHT/2});
            
        }
        // se a cobrinha sair da tela, ela aparece do outro lado
        for(int i = 0 ; i < (int)snake.body.size() ; i++){
            if( snake.body.at(i).x < GRID_SIZE ){
                snake.body.at(i).x = SCREEN_WIDTH - GRID_SIZE*2;
            }else if( snake.body.at(i).x >= SCREEN_WIDTH - GRID_SIZE ){
                snake.body.at(i).x = GRID_SIZE;
            }
            if( snake.body.at(i).y < GRID_SIZE ){
                snake.body.at(i).y = SCREEN_HEIGHT - GRID_SIZE*2;
            }else if( snake.body.at(i).y >= SCREEN_HEIGHT - GRID_SIZE ){
                snake.body.at(i).y = GRID_SIZE;
            }
        }

        //==== DRAW ON RENDER TEXTURE ====
        BeginTextureMode(display);
        ClearBackground(BKG_COLOR);
        DrawBorder();
        snake.draw();
        apple.draw();
        EndTextureMode();
        //==== DRAW ON MAIN WINDOW ====
        BeginDrawing();
        ClearBackground(BKG_COLOR);
        DrawTexturePro(display.texture, {0, 0, (float)display.texture.width, (float)-display.texture.height},
                       {0, 0, (float)GetScreenWidth(), (float)GetScreenHeight()},
                       {0, 0}, 0, WHITE);
        EndDrawing();
    }

    return 0;
}

inline void DrawBorder(){
    #define THICKNESS 4
    DrawLineEx({GRID_SIZE,GRID_SIZE}, {SCREEN_WIDTH-GRID_SIZE , GRID_SIZE},THICKNESS , MAIN_COLOR);
    DrawLineEx({GRID_SIZE,GRID_SIZE}, {GRID_SIZE , SCREEN_HEIGHT-GRID_SIZE},THICKNESS , MAIN_COLOR);
    DrawLineEx({SCREEN_WIDTH-GRID_SIZE,SCREEN_HEIGHT-GRID_SIZE} ,{SCREEN_WIDTH-GRID_SIZE , GRID_SIZE},THICKNESS , MAIN_COLOR);
    DrawLineEx({SCREEN_WIDTH-GRID_SIZE,SCREEN_HEIGHT-GRID_SIZE} ,{GRID_SIZE , SCREEN_HEIGHT-GRID_SIZE},THICKNESS , MAIN_COLOR);
}