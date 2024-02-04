#include "fullscreen.h"
#include "settings.h"

#include "raylib.h"


void SwitchFullscreen() {
    if ( IsWindowFullscreen() ){
        ToggleFullscreen();
        SetWindowSize( SCREEN_WIDTH , SCREEN_HEIGHT );
        SetWindowPosition( SCREEN_WIDTH/4 , SCREEN_HEIGHT/4);
        return;
    }else {
        auto monitor = GetCurrentMonitor();
        SetWindowSize( GetMonitorWidth(monitor) , GetMonitorHeight(monitor) );
        ToggleFullscreen();
        return;

    }
}