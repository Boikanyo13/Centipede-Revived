#include "Spider.h"
#include <cstdlib>
#include <ctime>

void Spider::Move(){
    
    //Introduce randomness
    srand(time(0));
    auto decision = rand()%3;
    
    switch(decision){
    
        case 0:    
            if(!up_)
                moveDown();
            else if(!zigzag_)
                moveZig();
            else if(zigzag_)
                moveUp();
            else if(up_) 
                {moveZag();}
        break;
        
       case 1:
            if(up_)
                moveZig();
            else if(zigzag_)
               moveZag();
            else if(!zigzag_)
                 moveUp();
            else if(!up_) 
                moveDown();
        break;
        
        case 2:
            if(!zigzag_)
                moveZag();
            else if(up_)
                moveUp();
            else if(zigzag_)
               moveZig();
            else if(!up_) 
                moveDown();
        break;
        
      default:
        break;
        }
}

void Spider::reset(){
    
    setObjectID(ObjectID::SPIDER);
    setPosition(vector2D{1.05f*ORIGINAL_SCREEN_WIDTH, 440.0f});
    updateState(State::ALIVE);
    zigzag_ = !zigzag_;
    up_ = !up_;
}

void Spider::moveDown(){
    
    auto down = getPosition().y() + getSpeed();
    
    if(down < (ORIGINAL_SCREEN_HEIGHT)){
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
    
    
    auto zag = getPosition().y() + getSpeed();

    if(zigzag_){
        
        auto zig = getPosition().x() - getSpeed();
        
        //At bounds?
        if(zag < (ORIGINAL_SCREEN_HEIGHT)  && zig >= getSize().x())
        { 
            setPosition(vector2D{zig,zag});
        }
        else{
            
            //Rotate Position horizontally
            if(zig >=  (ORIGINAL_SCREEN_WIDTH - getSize().x()/2.0f)){
             
             setPosition(vector2D{1.05f*ORIGINAL_SCREEN_WIDTH,getPosition().y()});
             }
             else{  zigzag_ = !zigzag_; 
                    up_ = !up_;
                  }
         
        }
        
     }
    else{
        
        //At bounds?
         auto zig = getPosition().x() + getSpeed();
        
        if(zag < (ORIGINAL_SCREEN_HEIGHT)  && zig <= ORIGINAL_SCREEN_WIDTH)
         { 
            setPosition(vector2D{zig,zag});
         }
        else{
            
            //Rotate Position horizontally
            if(zig >  (ORIGINAL_SCREEN_WIDTH)){
             
                setPosition(vector2D{-2.0f*getSize().x(),getPosition().y()});
             }
             else{zigzag_ = !zigzag_; 
                   up_ = !up_;
                  }
         
            }
        }
}
    
void Spider::moveZag(){
    
    
    auto zag = getPosition().y() - getSpeed();
    
    if(zigzag_){
        
        auto zig = getPosition().x() - getSpeed();
        
        //At bounds?
        if(zag >= 2.0f*(ORIGINAL_SCREEN_HEIGHT/3)  && zig >= -(getSize().x()/2.0f))
        { 
            setPosition(vector2D{zig,zag});
        }
        else{
            
             //Rotate Position horizontally
            if(zig <= -(getSize().x()/2.0f)){
             
             setPosition(vector2D{1.01f*ORIGINAL_SCREEN_WIDTH, getPosition().y()});
             }
             else{zigzag_ = !zigzag_;
                    up_ = !up_;
                   }
            }
        }
        
    else{
           auto zig = getPosition().x() + getSpeed();
           
           //At bounds?
           if(zag >= 2.0f*(ORIGINAL_SCREEN_HEIGHT/3)  && zig <= ORIGINAL_SCREEN_WIDTH)
            { 
                setPosition(vector2D{zig,zag});
                }
            else{
                
                 //Rotate Position horizontally
                if(zig <= -(getSize().x()/2.0f)){
             
                    setPosition(vector2D{-2.0f*(getSize().x()/2.0f), getPosition().y()});
                    }
                 else{  zigzag_ = !zigzag_;
                        up_ = !up_;
                   }
        
            }
        }
}


