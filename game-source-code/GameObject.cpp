#include "GameObject.h"


GameObject::GameObject(const vector2D& size,const vector2D& position, float speed, ObjectID objectid):
size_{size},
speed_{speed},
objectID_{objectid}
{
    
    if(objectid == ObjectID::SPACESHIP || objectid == ObjectID::MUSHROOM){
        
        if(position.x() < 0 || position.y() < 0 ||position.x() > ORIGINAL_SCREEN_WIDTH || position.y() > ORIGINAL_SCREEN_HEIGHT){
        throw ObjectOutOfBounds{};
          }
        else{  position_=position;
            }
        
        }
       else if(objectid == ObjectID::SPIDER || objectid == ObjectID::SCORPION_L || objectid == ObjectID::SCORPION_R||objectid==ObjectID::EXPLOSION2){
           
            if(position.y() < 0 ||position.y() > ORIGINAL_SCREEN_HEIGHT){
                throw ObjectOutOfBounds{};
                }
                else{  position_=position;
                }
           
        }
       else{
              
            if(position.x() < 0 ||position.x() > ORIGINAL_SCREEN_WIDTH || position.y() > ORIGINAL_SCREEN_HEIGHT){
                    throw ObjectOutOfBounds{};
                }
             else{
             position_=position;}
           
           }

       isDead_ = false;
  }
    
void GameObject::setPosition(const vector2D& position){
     
    //Ensure that objects are within the screen bounds 
    
    //Check, for LazerShots and Centipede vertical position is allowed to be < 0 
   
    if(objectID_ == ObjectID::SPACESHIP || objectID_ == ObjectID::MUSHROOM){
        
        if(position.x() < 0 || position.y() < 0 ||position.x() > ORIGINAL_SCREEN_WIDTH || position.y() > ORIGINAL_SCREEN_HEIGHT){
        throw ObjectOutOfBounds{};
          }
        else{  position_=position;
            }
        
        }
       else if(objectID_== ObjectID::SPIDER || objectID_ == ObjectID::SCORPION_L || objectID_ == ObjectID::SCORPION_R||objectID_==ObjectID::EXPLOSION2){
           
            if(position.y() < 0 ||position.y() > ORIGINAL_SCREEN_HEIGHT){
                throw ObjectOutOfBounds{};
                }
                else{  position_=position;
                }
           
        }
       else{
              
            if(position.x() < 0 ||position.x() > ORIGINAL_SCREEN_WIDTH || position.y() > ORIGINAL_SCREEN_HEIGHT){
                    throw ObjectOutOfBounds{};
                }
                else{
                position_=position;}
           }


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


