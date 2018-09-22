#ifndef SCORE_H
#define SCORE_H

class Score
{
public:
    Score();
    //incremenet score by 10 
    void centibodyDestroyed();
    //incremenet score by 100 
    void centiheadDestroyed();
    //incremenet score by 1
    void mushroomDestroyed();
    //get score
    int score() const;
    //reset score 
    void reset();
    ~Score();
private:
        int score_;

};

#endif // SCORE_H
