#include <iostream>
#include "raylib.h"

#include "snake.h"
#include "game.h"

#include "../utils/settings.h"
#include "../utils/fullscreen.h"
#include "../utils/timer.h"



Game Game::New(const char* title) {
    Game game;
    game.title = title;
    return game;
}


void Game::start() {
    InitWindow(SCREEN_WIDTH , SCREEN_HEIGHT , title);
    SetTargetFPS(60);

    SetExitKey( KEY_NULL );

    gameLoop();
    end();   
}

void Game::gameLoop() {
    RenderTexture2D display = LoadRenderTexture(SCREEN_WIDTH , SCREEN_HEIGHT);
    Snake snake = Snake::New( {SCREEN_WIDTH/2, SCREEN_HEIGHT/2});


    Timer timer = Timer::New();
    timer.start(3.0);

    while( !WindowShouldClose() ){
        //---- sistema de fullscreen ----
        if(IsKeyDown(KEY_F11)){
            SwitchFullscreen();
        }
        //---- ----
        snake.input();

        //---- updates ----
        timer.update();
        //std::cout<< timer.life_time << std::endl;
        if ( timer.isFinished() ){
            snake.update();

            //std::cout<< "kkkkkkkkkkkkkkk" << std::endl;
            timer.start(0.25);
        }
        

        //---- Draw no display ----
        BeginTextureMode( display );

            ClearBackground( BLACK );

            snake.draw();
            
            DrawLineEx( snake.getBody().front() ,{0,0} , 1.0 , RED);
            DrawLineEx( snake.getBody().front() ,{SCREEN_WIDTH,SCREEN_HEIGHT} , 1.0 , RED);
        
        EndTextureMode();



        //---- Draw na window ----
        BeginDrawing();
            DrawTexturePro(
                            display.texture ,
                            //qual parte do display.texture
                            {0.0 ,0.0 , static_cast<float>(display.texture.width) , static_cast<float>(display.texture.height)},
                            //em qual parte da window (janela principal)
                            {0.0 , 0.0 , static_cast<float>(GetScreenWidth()) , static_cast<float>(GetScreenHeight())},
                            // ponto de origem
                            {0.0 , 0.0} ,
                            0.0,
                            WHITE
                        );
        
        EndDrawing();
    }
}

void Game::end() {
    CloseWindow();
}

