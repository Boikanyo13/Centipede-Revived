#include "Csegment.h"
    
void CentiSegment::collisionResponse(){
    
    if(!up_)
    moveDown();
    else
        moveUp();
    
    //reverse direction   
    forward_ = !forward_;
    
}
    
void CentiSegment::Move(){
    
    if(getPosition().y() <= getSize().y()) { entrance(); }
    
    else{
        
            if(atBoundry_){
                
                if(!up_) moveDown();
                else moveUp();
            }

          else{
                if(forward_) moveRight();
                else moveLeft();}
    }
}

void CentiSegment::moveLeft(){
    
    auto left = getPosition().x() - getSpeed();
    if(left >= (getSize().x()/2.0f )){
        setPosition(vector2D{left, getPosition().y()});
        }
    else{forward_ = true;
        atBoundry_ = true;
    }
    }

void CentiSegment::moveRight(){ 
    
    auto right = getSpeed() + getPosition().x();
    if(right <= (ORIGINAL_SCREEN_WIDTH - getSize().x()/2.0f)){
        setPosition(vector2D{right, getPosition().y()});
    }
    else{ forward_ = false;
        atBoundry_ = true;
    }
    }

void CentiSegment::moveUp(){
    
    auto up = getPosition().y() - getSize().y();
    if(up >= 2.0f*(ORIGINAL_SCREEN_HEIGHT/3)){
        setPosition(vector2D{getPosition().x(), up});
         atBoundry_ = false;
        }
    else{ up_ = false;
                
       }
    }

void CentiSegment::moveDown(){
    
    auto down = getPosition().y() + getSize().y();
    if(down <= (ORIGINAL_SCREEN_HEIGHT)){
        setPosition(vector2D{getPosition().x(), down});
         atBoundry_ = false;
       }
    else{up_ = true; }
    }
    
void CentiSegment::entrance(){
    
    auto movement = getSpeed() + getPosition().y();
    setPosition(vector2D{getPosition().x(),movement});
}
    
