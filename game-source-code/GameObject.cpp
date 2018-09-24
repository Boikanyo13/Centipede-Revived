#include "GameObject.h"


GameObject::GameObject(const vector2D& size,const vector2D& position, float speed, ObjectID objectid):
size_{size},
speed_{speed},
objectID_{objectid}
{
 
   if((objectid != ObjectID::CENTIPEDE) && (objectID_ != ObjectID::BULLET)){
      if(position.x() < 0 || position.y() < 0 ||position.x() > ORIGINAL_SCREEN_WIDTH || position.y() > ORIGINAL_SCREEN_HEIGHT){
        throw ObjectOutOfBounds{};
        }
       else{position_=position;}
      }
  else if(position.x() < 0 || position.x() > ORIGINAL_SCREEN_WIDTH || position.y() > ORIGINAL_SCREEN_HEIGHT){
           throw ObjectOutOfBounds{};
     }
   else{
          position_=position;
       }

       isDead_ = false;
  }
    
void GameObject::setPosition(const vector2D& position){
     
    //Ensure that objects are within the screen bounds 
    
    //Check, for LazerShots and Centipede vertical position is allowed to be < 0 
    if(objectID_ != ObjectID::SPIDER && objectID_ != ObjectID::BULLET){
    
    if((objectID_ != ObjectID::CENTIPEDE) && (objectID_ != ObjectID::BULLET)){
      if(position.x() < 0 || position.y() < 0 ||position.x() > ORIGINAL_SCREEN_WIDTH || position.y() > ORIGINAL_SCREEN_HEIGHT){
            throw ObjectOutOfBounds{};
        }
        else{position_ = position;}
      }
   else if(position.x() < 0 || position.x() > ORIGINAL_SCREEN_WIDTH || position.y() > ORIGINAL_SCREEN_HEIGHT){
           throw ObjectOutOfBounds{};
          
     }
   else{
          position_=position;
    }}
    else{position_=position;}

    }
 
void GameObject::setSize(const vector2D& size){
    
    size_ = size;
    }
    
void GameObject::setSpeed(float speed){
    
    speed_ = speed;
    
    }
    
void GameObject::setObjectID(ObjectID oID){
    
    objectID_ = oID;
    
    }
    
void GameObject::updateState(State state){
    
    switch(state){
        
        case State::DEAD:
            isDead_ = true;
            break;
        case State::ALIVE:
            isDead_ = false;
            break;
        default:
             break; 
        }
    
    
    }
    
bool GameObject::isDead() const{
    
    return isDead_;
    };

float GameObject::getSpeed() const{
    
    return speed_;
    }

vector2D GameObject::getPosition() const{
    
    return position_;
    }

vector2D GameObject::getSize() const{
    
    return size_;
    }
    
ObjectID GameObject::ID() const{
    
    return objectID_;
    }

GameObject::~GameObject(){}

