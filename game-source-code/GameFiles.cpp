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
       
            
        default:
        return "";
        break;
        
        
        }

    }

GameFiles::~GameFiles()
{
}
