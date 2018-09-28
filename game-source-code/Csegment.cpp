#include "Csegment.h"


CentiSegment::CentiSegment(const vector2D& size, const vector2D& position, float speed, ObjectID objectid):
GameObject{size,position,speed,objectid}{
    forward_ = true;
    up_ = false;
    atBoundry_ = false;
}


void CentiSegment::Move(Direction direction){
    
    switch(direction){
        
        case Direction::UP:
                moveUp();
            break;
        
        case Direction::DOWN:
                moveDown();
            break;
            
        case Direction::LEFT:
                moveLeft();
            break;
            
        case Direction::RIGHT:
                moveRight();
            break;
        
        default:
        break;
        }
    
    }

void CentiSegment::head(){
    
    setObjectID(ObjectID::CHEAD);
    }
    
bool CentiSegment::isHead() const
{
    return (ID()==ObjectID::CHEAD);
    }
    
void CentiSegment::mushroomHit(){
    
       
    if(!up_)
    moveDown();
    else
        moveUp();
    
    //reverse direction   
    forward_ = !forward_;
    
}
    
    
void CentiSegment::reset(){
     
 }   

void CentiSegment::Move(){
    
    if(getPosition().y() <= getSize().y()/*/2.0f*/) { entrance(); }
    
    else{
        
            if(atBoundry_){
                
                if(!up_) Move(Direction::DOWN);
                else Move(Direction::UP);
            }

          else{
                if(forward_) Move(Direction::RIGHT);
                else Move(Direction::LEFT);}
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
    if(down <= (ORIGINAL_SCREEN_HEIGHT /*-getSize().y()/2.0f*/)){
        setPosition(vector2D{getPosition().x(), down});
         atBoundry_ = false;
       }
    else{up_ = true; }
    }
    
void CentiSegment::entrance(){
    
    auto movement = getSpeed() + getPosition().y();
    setPosition(vector2D{getPosition().x(),movement});
}
    
CentiSegment::~CentiSegment(){
    
}