
#ifndef TIMER_H
#define TIMER_H

#include "raylib.h"

class Timer {
    public:
        float life_time;
    
    static Timer New();

    void start(float life_time);
    void update();
    bool isFinished();
    



};

#endif