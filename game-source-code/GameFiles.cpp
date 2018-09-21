#include "GameFiles.h"

GameFiles::GameFiles()
{
    objectImages_ = {"ship.png","lazershot.png", "centi2.png", "head6.png", "explosion.png"};
    screenImages_ = {"start.png", "help.png", "back.png", "exit.png", "logo.png", "sky.jpg"};
    
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

GameFiles::~GameFiles()
{
}

