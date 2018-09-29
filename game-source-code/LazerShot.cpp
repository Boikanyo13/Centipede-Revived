#include "LazerShot.h"

void LazerShot::Move(){
    
    //Bullet only moves UP
  
    auto newPosition = getPosition().y() - getSpeed();
    
    setPosition(vector2D(getPosition().x(), newPosition));
    
    //LazerShot out of bounds
     if(getPosition().y() < 0){updateState(State::DEAD);}

}

void LazerShot::Fire(){
    
   if(!isDead()){
    Move();
  }
}
    

