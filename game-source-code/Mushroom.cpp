#include "Mushroom.h"

void Mushroom::collisionResponse(){
    
    if(!isDead()){
    lives_--;
    
    switch(lives_){
        
        case 3:
        setObjectID(ObjectID::MUSHROO);
        break;
        case 2:
        setObjectID(ObjectID::MUSHRO);
        break;
        case 1:
        setObjectID(ObjectID::MUSHR);
        break;
        case 0:
         updateState(State::DEAD);
         break;
        default:
        
        break;
        }
        }
    }

void Mushroom::reset(){
    
    setObjectID(ObjectID::MUSHROOM);
    updateState(State::ALIVE);
    
    }

    

