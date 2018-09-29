#include "Player.h"

void Player::move(){
    
    if(userinput_ptr_->pressedKey()==Key::UP){
             
             spaceship_ptr_->Move(Direction::UP);
             }
             
    if(userinput_ptr_->pressedKey()==Key::DOWN){
             
              spaceship_ptr_->Move(Direction::DOWN);
            }
            
    if(userinput_ptr_->pressedKey()==Key::LEFT){
             
            spaceship_ptr_->Move(Direction::LEFT);
             }
             
    if(userinput_ptr_->pressedKey()==Key::RIGHT){
             
            spaceship_ptr_->Move(Direction::RIGHT);
            }
    
    
}
