#include "Score.h"
#include <iostream>

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

void Score::updateHighscore(){
    
    auto gameFile = std::make_shared<GameFiles>();
    auto tempscore = gameFile->scorefile();

    tempscore.push_back(score_);
    
    //sort the high scores in descending order
    std::sort(tempscore.begin(), tempscore.end() ,std::greater<int>());
    tempscore.pop_back();
    
    gameFile->scorefile(tempscore);
    
    
}

Score::~Score(){
}

