#include "GameFiles.h"

GameFiles::GameFiles()
{
    objectImages_ = {"ship.png","lazershot.png", "centi2.png", "head6.png", "explosion.png","mushroom1.png",
                     "mushroom2.png", "mushroom3.png","mushroom4.png","spider.png"};
    screenImages_ = {"start.png", "help.png", "back.png", "exit.png", "logo.png", "sky.jpg", "background1.jpg", "life.png"};
   
}

 std::vector<string> GameFiles::objectImages() const{
    
  return objectImages_;
    }
    
std::vector<string> GameFiles::screenImages() const{
    
    return screenImages_;
    }
    
std::string GameFiles::font() const{
    auto font = "rocket.ttf";
    return font;
}

std::vector<int> GameFiles::scorefile(){
    
    std::ifstream inHighScore_("highscore.txt");
    
     if(!inHighScore_.is_open()) throw FileNotFound{};
        
        auto tempHighscore = 0;
        std::vector<int> highscores ;
        
        while(inHighScore_ >> tempHighscore)
        {
            highscores.push_back(tempHighscore);
        }
    
        inHighScore_.close();
    
    return highscores;
}

void GameFiles::scorefile(std::vector<int> score){
    
    std::ofstream outHighScore_("highscore.txt");
    
    if(!outHighScore_.is_open()) throw FileNotFound{};
    
    outHighScore_.clear();
    
   for(auto i = 0u; i < score.size() ; i++){
       
       
        outHighScore_ <<  score[i] << "\n";
    }
   
        outHighScore_.close();
    
}

GameFiles::~GameFiles()
{
    
}

