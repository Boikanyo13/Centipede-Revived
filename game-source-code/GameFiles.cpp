#include "GameFiles.h"

/*GameFiles::GameFiles()
{
}*/

string GameFiles::image(ObjectID ID) const{
    
    switch(ID){
        
        case ObjectID::BULLET:
            return "lazershot.png";
            break;
        
        case ObjectID::PLAYER:
            return "ship.png";
            break;
        case ObjectID::CENTIPEDE:
            return "centi2.png";

       
            
        default:
        return "";
        break;
        
        
        }

    }

GameFiles::~GameFiles()
{
}

