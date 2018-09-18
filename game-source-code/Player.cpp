#include "Player.h"

Player::Player(const vector2D& size,const vector2D& position, float speed, ObjectID objectid):
GameObject{size,position,speed,objectid}
{   
    
    }
    
void Player::Move(Direction direction){  

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
    
   

        
      
void Player::moveLeft(){
    
    //Check if at boundary
        auto left =  getPosition().x() - getSpeed();
        if(left >= (getSize().x()/2.0f )){
                  setPosition(vector2D{left,getPosition().y()});
        }
    }
        
void Player::moveRight(){
    
      //Check if at boundary
        auto right = getSpeed() + getPosition().x();
        if(right <= (ORIGINAL_SCREEN_WIDTH - getSize().x()/2.0f)){
                    setPosition(vector2D{right,getPosition().y()});
                }
    }
    
void Player::moveDown(){
    
     //Check if at boundary
        auto down =  getPosition().y() + getSpeed();
        if(down <= (ORIGINAL_SCREEN_HEIGHT -getSize().y()/2.0f)){
                 setPosition(vector2D{getPosition().x(),down});
            }
    }
    
   // down >= 2.0f*(ORIGINAL_SCREEN_HEIGHT/3
    
void Player::moveUp(){
    
     //Check if at boundary
        auto up = getPosition().y() - getSpeed();
        if(up >= 2.0f*(ORIGINAL_SCREEN_HEIGHT/3)){
                setPosition(vector2D{getPosition().x(),up});
            }
    }

Player::~Player()
{
}

