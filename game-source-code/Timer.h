#ifndef TIMER_H
#define TIMER_H
#include <ctime>

/**
 * @class Timer
 * @date 08/10/2018
 * @file Timer.h
 * @brief Responsible for timing GameObjects
 */

class Timer
{
public:
    /**
     * @brief Constructor
     */
    Timer()
    {}
    /**
     * @brief start the Timer
     */
    void start(){start_ = getTime();}
    /**
     * @brief Stop Timing
     */
    void end(){end_ = getTime();}
    /**
     * @brief Get elapsed Time
     * @return  time since code ran
     */
    double elapsedTime(){return (end_ - start_);}
     /**
      * @brief Reset the timer
      */
    void reset();
    ~Timer(){};
    
private:
     /**
      * @brief Compute time
      * @return time in seconds
      */
    double getTime();
    double start_ = 0.0f;
    double end_ = 0.0f;
    
};

#endif // TIMER_H
