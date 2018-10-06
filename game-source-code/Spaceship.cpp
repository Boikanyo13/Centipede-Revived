#include "Spaceship.h"
#include <iostream>

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
      
      if(isDead()){
            
            lives_ = 3;
            setObjectID(ObjectID::SPACESHIP);
            updateState(State::ALIVE);
          
          }
   
}
      
void Spaceship::lostLife(){
    
    if(!isDead()){
       
         lives_--;
    
        if(lives_ == 0)
        updateState(State::DEAD);
    }
}

