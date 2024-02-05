#include <iostream>
#include <cmath>
#include "raylib.h"

#include "snake.h"
#include "game.h"
#include "apple.h"

#include "../utils/settings.h"
#include "../utils/fullscreen.h"
#include "../utils/timer.h"
#include "../utils/myMath.h"




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
    //---- ASSETS ----
    Font font = LoadFont("../assets/fonts/HachicroUndertaleBattleFontRegular-L3zlg.ttf");
    
    Texture2D background = LoadTexture("./../assets/foto.jpg");
    
    //----------------
    RenderTexture2D display = LoadRenderTexture(SCREEN_WIDTH , SCREEN_HEIGHT);
    Snake snake = Snake::New( {SCREEN_WIDTH/2, SCREEN_HEIGHT/2});
    


    Timer timer = Timer::New();
    timer.start(3.0);

    
    Apple apple = Apple::New( randomGridPosition() );

    while( !WindowShouldClose() ){
        
        //---- sistema de fullscreen ----
        if(IsKeyDown(KEY_F11)){
            SwitchFullscreen();
        }
        
        timer.update();
        //---- ESTADOS DO JOGO ----
        if( state == MENU){
            if( IsKeyPressed(KEY_ENTER) ){
                state = PLAY;
                timer.start(4.0);
            }
            Vector2 text_size = MeasureTextEx(font, "MENU", 20, 1);
            
            BeginTextureMode( display );

                DrawTexture(background , 0 , 0 , WHITE);

                DrawTextEx( font , 
                            "MENU", 
                            {SCREEN_WIDTH/2 - (text_size.x/2) , SCREEN_HEIGHT/2},
                            20,
                            1,
                            WHITE);
            EndTextureMode();
        }
        
        else if( state == PLAY){
        
        //---- ----
            snake.input();

            //---- updates ----
            
            if ( timer.isFinished() ){
                snake.update();

                timer.start(0.25);
            }
            // ---- COLISÕES ----
            if (apple.checkCollisionWithSnake(snake)){
                apple.setPosition( randomGridPosition() );
                snake.grow();
            }
            
            if( snake.checkCollisionWithHimself()){
                state = GAMEOVER;
                snake.reset({SCREEN_WIDTH/2, SCREEN_HEIGHT/2});
                timer.start(4.0);
            }

            //---- Draw no display ----
            BeginTextureMode( display );

                DrawTexture(background , 0 , 0 , WHITE);

                snake.draw();
                apple.draw();
                
                DrawLineEx( snake.body.front() ,{0,0} , 1.0 , RED);
                DrawLineEx( snake.body.front() ,{SCREEN_WIDTH,SCREEN_HEIGHT} , 1.0 , RED);
            
            EndTextureMode();



            
        }
        
        else if( state == GAMEOVER){
            std::cout << "GAME OVER\n";
            
            if( timer.isFinished() ){
                state = MENU;
                
            }
            Vector2 text_size = MeasureTextEx(font, "GAME OVER", 20, 1);
            BeginTextureMode( display );
                
                DrawTexture(background , 0 , 0 , WHITE);
                DrawTextEx( font , 
                            "GAME OVER", 
                            {SCREEN_WIDTH/2 -(text_size.x /2) , SCREEN_HEIGHT/2},
                            20,
                            1,
                            WHITE);
            EndTextureMode();

            
        }
        BeginDrawing();
        ClearBackground(BLACK);
        DrawTextureEx(background , {0,0} , 0.0 , 1.0 , WHITE);
        //DrawTexture(background , 50 , 50 , WHITE);
            DrawTexturePro(
                            display.texture ,
                            //qual parte do display.texture
                            {0.0 ,0.0 , static_cast<float>(display.texture.width) , static_cast<float>(-display.texture.height)},
                            //em qual parte da window (janela principal)
                            {0.0 , 0.0 , static_cast<float>(GetScreenWidth()) , static_cast<float>(GetScreenHeight())},
                            // ponto de origem
                            {0.0 , 0.0} ,
                            0.0,
                            WHITE
                        );
        
        EndDrawing();

        
    }
    UnloadTexture(background);
}

#include <cmath>

void Game::end() {
    CloseWindow();
}



