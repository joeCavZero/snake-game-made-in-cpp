#include "Timer.h"
#include "raylib.h"
#include "raymath.h"

Timer Timer::New(){
    Timer timer;
    return timer;
}

void Timer::start(float life_time) {
    this->life_time = life_time;
}

void Timer::update(){
    if (this->life_time > 0){
        this->life_time -= GetFrameTime();
    }
}


bool Timer::isFinished(){
    return (life_time <= 0) ;
}