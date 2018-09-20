#include "GameFiles.h"

GameFiles::GameFiles()
{
    images_ = {"ship.png","lazershot.png", "centi2.png", "head2.png"};
    
}

 std::vector<string> GameFiles::images() const{
    
  return images_;
    }
    


GameFiles::~GameFiles()
{
}

