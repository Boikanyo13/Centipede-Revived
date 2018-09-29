#include "Spaceship.h"
#include <iostream>

Spaceship::Spaceship(const vector2D& size,const vector2D& position, float speed, ObjectID objectid):
GameObject{size,position,speed,objectid}
{   
    tempSpeed_ = speed;
    }

void Spaceship::shoot(){
    
    for(auto i = 0; i != noOfLazerShots_; i++){
        
       lazerShotsGun_[i]->Fire();
        
        if(lazerShotsGun_[i]->getPosition().y() <= 0.0f){
                
                 lazerShotsGun_[i]->updateState(State::DEAD);
                 //lazerShotsGun_.erase(lazerShotsGun_.begin()+i);
                   //  noOfLazerShots_--;
                }
         }
}

void Spaceship::load(){
    
    lazerShotsGun_.push_back(std::make_shared<LazerShot>(BULLET_SIZE,vector2D{0.0f,0.0f}, 1.0f, ObjectID::BULLET));
    lazerShotsGun_[noOfLazerShots_]->Load(getPosition());
    noOfLazerShots_++;
    
}

void Spaceship::reset(){
    
    setObjectID(ObjectID::SPACESHIP);
    setPosition(SPACESHIP_START_POSTION);

    //clear the vector 
     if(lazerShotsGun_.size()>0){
       lazerShotsGun_.erase(lazerShotsGun_.begin(), lazerShotsGun_.end());
      }
      noOfLazerShots_ = 0;
   
}

void Spaceship::mushroomCollision(bool collision, Key key){
    
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
      
      
void Spaceship::moveLeft(){
    
    //Check if at boundary
        auto left =  getPosition().x() - getSpeed();
        if(left >= (getSize().x()/2.0f ) && left_){
                  setPosition(vector2D{left,getPosition().y()});
        }
    }
        
void Spaceship::moveRight(){
    
      //Check if at boundary
        auto right = getSpeed() + getPosition().x();
        if(right <= (ORIGINAL_SCREEN_WIDTH - getSize().x()/2.0f) && right_){
                    setPosition(vector2D{right,getPosition().y()});
                }
    }
    
void Spaceship::moveDown(){
    
     //Check if at boundary
        auto down =  getPosition().y() + getSpeed();
        if(down <= (ORIGINAL_SCREEN_HEIGHT -getSize().y()/2.0f) && down_){
                 setPosition(vector2D{getPosition().x(),down});
            }
    }
    

void Spaceship::moveUp(){
    
     //Check if at boundary
        auto up = getPosition().y() - getSpeed();
        if(up >= 2.0f*(ORIGINAL_SCREEN_HEIGHT/3) && up_){
                setPosition(vector2D{getPosition().x(),up});
            }
    }
    
void Spaceship::lostLife(){
    
    if(!isDead()){
       lives_--;
    
       if(lives_ == 0)
        updateState(State::DEAD);
    }
    
    
}

