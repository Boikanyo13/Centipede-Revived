#include "LazerShot.h"

LazerShot::LazerShot(const vector2D& size,const vector2D& position, float speed, ObjectID objectid):
GameObject{size,position,speed,objectid}
{}

void LazerShot::Move(Direction direction){
    
    //Bullet only moves UP
    if(direction==Direction::UP){
    auto newPosition = getPosition().y() - getSpeed();
    
    setPosition(vector2D(getPosition().x(), newPosition));
    
    //LazerShot out of bounds
     if(getPosition().y() < - getSize().y()){updateState(State::DEAD);}
    }
    else{
        // Do nothing
     }
}

void LazerShot::Fire(){
    
   if(!isDead()){
    Move(Direction::UP);
  }
}
    
void LazerShot::Load(const vector2D& position){
    
     setPosition(position);
    
    }
    
LazerShot::~LazerShot()
{
}
