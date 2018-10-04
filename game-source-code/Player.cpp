#include "Player.h"

void Player::Move(){
    
    if(_userinput_ptr->pressedKey()==Key::UP) moveSpaceshipUp();
             
    if(_userinput_ptr->pressedKey()==Key::DOWN) moveSpaceshipDown();
    
    if(_userinput_ptr->pressedKey()==Key::LEFT) moveSpaceshipLeft();
             
    if(_userinput_ptr->pressedKey()==Key::RIGHT) moveSpaceshipRight();
}


void Player::moveSpaceshipLeft(){
    
    //Check if at boundary
        auto left =  _spaceship_ptr->getPosition().x() - _spaceship_ptr->getSpeed();
        if(left >= (_spaceship_ptr->getSize().x()/2.0f )){
                  _spaceship_ptr->setPosition(vector2D{left,  _spaceship_ptr->getPosition().y()});
        }
    }
    
void Player::moveSpaceshipRight(){
    
      //Check if at boundary
        auto right = _spaceship_ptr->getSpeed() + _spaceship_ptr->getPosition().x();
        if(right <= (ORIGINAL_SCREEN_WIDTH - _spaceship_ptr->getSize().x()/2.0f)){
                    _spaceship_ptr->setPosition(vector2D{right,_spaceship_ptr->getPosition().y()});
                }
    }
    
    
void Player::moveSpaceshipDown(){
    
     //Check if at boundary
        auto down =   _spaceship_ptr->getPosition().y() +  _spaceship_ptr->getSpeed();
        if(down <= (ORIGINAL_SCREEN_HEIGHT - _spaceship_ptr->getSize().y()/2.0f)){
                  _spaceship_ptr->setPosition(vector2D{ _spaceship_ptr->getPosition().x(),down});
            }
    }

void Player::moveSpaceshipUp(){
    
     //Check if at boundary
        auto up =  _spaceship_ptr->getPosition().y() -  _spaceship_ptr->getSpeed();
        if(up >= 2.0f*(ORIGINAL_SCREEN_HEIGHT/3)){
                 _spaceship_ptr->setPosition(vector2D{  _spaceship_ptr->getPosition().x(),up});
            }
}


void Player::mushroomCollision(bool collision){
    
    //If there is a collision bounce back by bounce
    auto bounce = 2.0f;
    
    if(collision){
       
       switch(_userinput_ptr->pressedKey()){
           
           case Key::LEFT:
        
              _spaceship_ptr->setPosition(vector2D{ _spaceship_ptr->getPosition().x()+bounce,  _spaceship_ptr->getPosition().y()});
              break;
              
          case Key::RIGHT:
              
               _spaceship_ptr->setPosition(vector2D{ _spaceship_ptr->getPosition().x()-bounce,  _spaceship_ptr->getPosition().y()});
              break;
              
          case Key::UP:
           
               _spaceship_ptr->setPosition(vector2D{ _spaceship_ptr->getPosition().x(),  _spaceship_ptr->getPosition().y()+bounce});
              break;
              
          case Key::DOWN:
              
              _spaceship_ptr->setPosition(vector2D{ _spaceship_ptr->getPosition().x(),  _spaceship_ptr->getPosition().y()-bounce});
              break;
              
           default:
              break;
           }
        
        
    }
}
      