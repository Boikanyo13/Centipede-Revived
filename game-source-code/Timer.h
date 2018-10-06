#ifndef TIMER_H
#define TIMER_H
#include <ctime>

class Timer
{
public:

    Timer()
    {}
    //start the Timer
    void start(){start_ = getTime();}
    //Stop Timing
    void end(){end_ = getTime();}
    //Get elapsed Time
    double elapsedTime(){return (end_ - start_);}
    //Reset
    void reset();
    ~Timer(){};
    
private:

    double start_ = 0.0f;
    double end_ = 0.0f;
    double getTime();
};

#endif // TIMER_H
