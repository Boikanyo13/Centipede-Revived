#include "Scorpion.h"


void Scorpion::Move(){
    
    if(forward_)
        moveRight();
    else
        moveLeft();
    
    }

void Scorpion::moveLeft(){
    
    auto left = getPosition().x() - getSpeed();
    if(left >= -2.0f*(getSize().x())){
        setPosition(vector2D{left, getPosition().y()});
        }
    else{ updateState(State::DEAD);
        leftReset();
    }
}

void Scorpion::moveRight(){ 
    
    auto right = getSpeed() + getPosition().x();
    if(right <= (1.09*ORIGINAL_SCREEN_WIDTH)){
        setPosition(vector2D{right, getPosition().y()});
    }
    else{
    
        updateState(State::DEAD);
        rightReset();
        }
   
    }
    
 void Scorpion::reset(){
     
     updateState(State::ALIVE);
     setSize(SCORPION_SIZE);
     
     if(forward_){
        
        rightReset();
     }
     else{
        leftReset();
     }
}

void Scorpion::leftReset(){
    
         setObjectID(ObjectID::SCORPION_L);
         forward_ = true;
         setPosition(SCORPION_INIT_POSITION_L);
    
    }
    
void Scorpion::rightReset(){
     
         setObjectID(ObjectID::SCORPION_R);
         forward_ = false;
         setPosition(SCORPION_INIT_POSITION_R);
     
     }

void Scorpion::collisionResponse() {
    
    setSize(vector2D{20.0f,20.0f});
    setObjectID(ObjectID::EXPLOSION2);
    
    } 