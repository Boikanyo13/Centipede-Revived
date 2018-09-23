#include "Mushroom.h"

Mushroom::Mushroom(const vector2D& size, const vector2D& position, float speed, ObjectID objectid):
GameObject{size,position,speed,objectid}
{
    lives_ = 4;
}

int Mushroom::lives() const{
    
return lives_;    
}

void Mushroom::shot(){
    
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
void Mushroom::Move(Direction direction){
    
    throw NonMovableObject{};
    
    }
    
    
Mushroom::~Mushroom()
{
}

