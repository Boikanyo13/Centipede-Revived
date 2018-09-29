#include "Player.h"

void Player::Move(){
    
    if(userinput_ptr_->pressedKey()==Key::UP){
             
             spaceship_ptr_->moveUp();
             }
             
    if(userinput_ptr_->pressedKey()==Key::DOWN){
             
              spaceship_ptr_->moveDown();
            }
            
    if(userinput_ptr_->pressedKey()==Key::LEFT){
             
            spaceship_ptr_->moveLeft();
             }
             
    if(userinput_ptr_->pressedKey()==Key::RIGHT){
             
            spaceship_ptr_->moveRight();
            }
    
    
}
