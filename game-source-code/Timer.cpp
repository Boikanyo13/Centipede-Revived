#include "Timer.h"


double Timer::getTime(){
    
    auto time = clock();
    return static_cast<double>(time)/CLOCKS_PER_SEC;
}

void Timer::reset(){
    
    end_ = 0.0f;
    start_ = 0.0f;
    }
