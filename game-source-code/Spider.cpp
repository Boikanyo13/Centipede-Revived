#include "Spider.h"
#include <cstdlib>
#include <ctime>

Spider::Spider(const vector2D& size,const vector2D& position, float speed, ObjectID objectid):
GameObject{size,position,speed,objectid}
{
    setPosition(vector2D{getSize().x()/2.0f+2.0f, 440.0f});
    up_ = false;
    zigzag_ = true;
}


void Spider::Move(Direction direction){
    
    //Do nothing
}
    
void Spider::Move(){
    
    //Introduce randomness
    srand(time(0));
    auto decision = rand()%2;
    
    switch(decision){
    
        case 0:    
            if(!up_)
                moveDown();
            else if(!zigzag_)
                moveUp();
            else if(zigzag_)
                moveZig();
            else if(up_) 
                {moveZag();}
        break;
        
       case 1:
            if(up_)
                moveZig();
            else if(zigzag_)
                moveUp();
            else if(!zigzag_)
                moveZag();
            else if(!up_) 
                moveDown();
        break;
        
        case 2:
            if(zigzag_)
                moveZag();
            else if(up_)
                moveUp();
            else if(!zigzag_)
                moveDown();
            else if(!up_) 
                moveZig();
        break;
        
      default:
        break;
        }
}

void Spider::reset(){
    
    setPosition(vector2D{ORIGINAL_SCREEN_WIDTH-2.0f, 440.0f});
    updateState(State::ALIVE);
}

void Spider::moveDown(){
    
    auto down = getPosition().y() + getSpeed();
    
    if(down <= (ORIGINAL_SCREEN_HEIGHT)){
        setPosition(vector2D{getPosition().x(), down});
       
    }else{
        
        up_ = !up_;
        }
       
}

void Spider::moveUp(){
     
    auto up = getPosition().y() - getSpeed();
    if(up >= 2.0f*(ORIGINAL_SCREEN_HEIGHT/3)){
        setPosition(vector2D{getPosition().x(), up});
        
    }
    else{
          up_ = !up_;
        }
}

void Spider::moveZig(){
    
    auto zig = getPosition().x() + getSpeed();
    auto zag = getPosition().y() + getSpeed();

    
    if(zag <= (ORIGINAL_SCREEN_HEIGHT)  && zig <= (ORIGINAL_SCREEN_WIDTH - getSize().x()/2.0f))
    { 
        setPosition(vector2D{zig,zag});
        }
    else{
            
         if(zig >=  (ORIGINAL_SCREEN_WIDTH - getSize().x()/2.0f)){
             
             setPosition(vector2D{ getSize().x()/2.0f+2.0f,zag});
             }
             else{zigzag_ = !zigzag_; 
                  up_ = !up_;
                  }
         
        }
        
}
    
void Spider::moveZag(){
    
    auto zig = getPosition().x() - getSpeed();
    auto zag = getPosition().y() - getSpeed();
    
    
    if(zag >= 2.0f*(ORIGINAL_SCREEN_HEIGHT/3)  && zig >= (getSize().x()/2.0f))
    { 
        setPosition(vector2D{zig,zag});
        }
    else{
        
         if(zig <= (getSize().x()/2.0f)){
             
             setPosition(vector2D{ORIGINAL_SCREEN_WIDTH - getSize().x()/2.0f-2.0f,zag});
             }
             else{zigzag_ = !zigzag_;}
        
        }
    
}

Spider::~Spider()
{
}

