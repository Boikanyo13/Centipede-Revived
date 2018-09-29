#include "Spaceship.h"
#include <iostream>

Player::Player(const vector2D& size,const vector2D& position, float speed, ObjectID objectid):
GameObject{size,position,speed,objectid}
{   
    noOfLazerShots_ = 0;
    lives_ = 3;
    tempSpeed_ = speed;
    left_ = true;
    right_ = true;
    up_ = true;
    down_ = true;
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
    
 void Player::Lives(int lives){
     
     lives_ = lives;
     
     }

void Player::shoot(){
    
    for(auto i = 0; i != noOfLazerShots_; i++){
        
       lazerShotsGun_[i]->Fire();
        
        if(lazerShotsGun_[i]->getPosition().y() <= 0.0f){
                
                 lazerShotsGun_[i]->updateState(State::DEAD);
                 //lazerShotsGun_.erase(lazerShotsGun_.begin()+i);
                   //  noOfLazerShots_--;
                }
         }
}

void Player::load(){
    
    lazerShotsGun_.push_back(std::make_shared<LazerShot>(BULLET_SIZE,vector2D{0.0f,0.0f}, 1.0f, ObjectID::BULLET));
    lazerShotsGun_[noOfLazerShots_]->Load(getPosition());
    noOfLazerShots_++;
    
}

std::tuple<std::shared_ptr<LazerShot>, int> Player::firedLazerShot(int i) const
{
return std::tie(lazerShotsGun_[i], noOfLazerShots_);
}
   
void Player::explode(){
    
    setObjectID(ObjectID::EXPLOSION);
    }
        
void Player::reset(){
    
    setObjectID(ObjectID::PLAYER);
    setPosition(PLAYER_START_POSTION);

    //clear the vector 
     if(lazerShotsGun_.size()>0){
       lazerShotsGun_.erase(lazerShotsGun_.begin(), lazerShotsGun_.end());
      }
      noOfLazerShots_ = 0;
   
}

void Player::mushroomCollision(bool collision, Key key){
    
    //If there is a collision bounce back by bounce
    auto bounce = 1.0f;
    
    if(collision){
       
       switch(key){
           
           case Key::LEFT:
             
              left_ = false;
              setPosition(vector2D{getPosition().x()+bounce, getPosition().y()});
              break;
              
          case Key::RIGHT:
              
              right_ = false;
              setPosition(vector2D{getPosition().x()-bounce, getPosition().y()});
              break;
              
          case Key::UP:
              
              up_ = false;
              setPosition(vector2D{getPosition().x(), getPosition().y()+bounce});
              break;
              
          case Key::DOWN:
              
              down_ = false;
              setPosition(vector2D{getPosition().x(), getPosition().y()-bounce});
              break;
              
           default:
              break;
           }
        
        
    }
    else{
        
         left_ = true;
         right_ = true;
         up_ = true;
         down_ = true;
          
        }
    
}
      
      
void Player::moveLeft(){
    
    //Check if at boundary
        auto left =  getPosition().x() - getSpeed();
        if(left >= (getSize().x()/2.0f ) && left_){
                  setPosition(vector2D{left,getPosition().y()});
        }
    }
        
void Player::moveRight(){
    
      //Check if at boundary
        auto right = getSpeed() + getPosition().x();
        if(right <= (ORIGINAL_SCREEN_WIDTH - getSize().x()/2.0f) && right_){
                    setPosition(vector2D{right,getPosition().y()});
                }
    }
    
void Player::moveDown(){
    
     //Check if at boundary
        auto down =  getPosition().y() + getSpeed();
        if(down <= (ORIGINAL_SCREEN_HEIGHT -getSize().y()/2.0f) && down_){
                 setPosition(vector2D{getPosition().x(),down});
            }
    }
    

void Player::moveUp(){
    
     //Check if at boundary
        auto up = getPosition().y() - getSpeed();
        if(up >= 2.0f*(ORIGINAL_SCREEN_HEIGHT/3) && up_){
                setPosition(vector2D{getPosition().x(),up});
            }
    }
    
void Player::lostLife(){
    
    if(!isDead()){
       lives_--;
    
       if(lives_ == 0)
        updateState(State::DEAD);
    }
    
    
}

int Player::Lives(){
    return lives_;
    }
Player::~Player()
{
}

