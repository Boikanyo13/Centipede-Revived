#ifndef SCORE_H
#define SCORE_H
#include "GameFiles.h"
#include <memory>

/**
 * @class Score
 * @author bvrad
 * @date 08/10/2018
 * @file Score.h
 * @brief This class is responsible keeping score
 */

class Score
{
public:
    /**
     * @brief Default constructor
     */
    Score();
    /**
     * @brief incremenet score by 10 
     */
    void centibodyDestroyed();
    /**
     * @brief incremenet score by 100 
     */
    void centiheadDestroyed();
    /**
     * @brief incremenet score by 1
     */
    void mushroomDestroyed();
    /**
     * @brief increment score by 300
     */
    void spiderDestroyed();
    /**
     * @brief increment score by 1000
     */
    void scorpionDestroyed();
    /**
     * @brief get score
     * @return current score
     */
    int score() const;
    /**
     * @brief reset score 
     */
    void reset();
    /**
     * @brief update high score
     */
    void updateHighscore();
    /**
      Destroy Score object
     */
    ~Score();
private:
        //score keeper
        int score_;

};

#endif // SCORE_H
