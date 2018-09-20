#include "GameFiles.h"

GameFiles::GameFiles()
{
    images_ = {"ship.png","lazershot.png", "centi2.png"};
    
}

 std::vector<string> GameFiles::images() const{
    
   /* switch(ID){
        
        case ObjectID::BULLET:
            return auto p = &textures_[1];
            break;
        
        case ObjectID::PLAYER:
            return &textures_[0];
            break;
        case ObjectID::CENTIPEDE:
            return &textures_[2];

       
            
        default:
        //return "";
        break;
        
        
        }*/
  return images_;
    }
    


GameFiles::~GameFiles()
{
}

