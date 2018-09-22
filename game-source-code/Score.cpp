#include "Score.h"

Score::Score(){
    score_ = 0;
}

void Score::centibodyDestroyed(){
    
    score_+=10;
}
void Score::centiheadDestroyed(){
    
    score_+=100;
}
void Score::mushroomDestroyed(){
    
    score_+=1;
}

int Score::score() const {
 return score_;
}

void Score::reset(){
    
    score_ = 0;
}

Score::~Score(){
}

